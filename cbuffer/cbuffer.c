#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

struct mutex buf_log;

#define __LOG_BUF_LEN	4096

char __mlx5e_log_buf[__LOG_BUF_LEN] __aligned(4);
char *mlx5e_log_buf = __mlx5e_log_buf;
u32 mlx5e_log_buf_len = __LOG_BUF_LEN;

u32 log_next_idx = 0;

static int cbuffer_init(void)
{
	char a[10] = "test";
	int len = strlen(a);

	mutex_init(&buf_log);

	mutex_lock(&buf_log);

	memcpy(mlx5e_log_buf, a, len);
	mlx5e_log_buf += len;
	log_next_idx += len;

	memset(mlx5e_log_buf, 0, 1);
	mlx5e_log_buf += 1;
	log_next_idx += 1;

	mutex_unlock(&buf_log);

	pr_info("cbuffer enter\n");
	return 0;
}

static void cbuffer_exit(void)
{
	mutex_destroy(&buf_log);

	pr_info("cbuffer exit\n");
}

module_init(cbuffer_init);
module_exit(cbuffer_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
