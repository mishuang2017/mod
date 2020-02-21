#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
static void mlx5_flow_stats_work(struct work_struct *private_);
static DECLARE_DELAYED_WORK(mlx5_flow_work, mlx5_flow_stats_work);

static void mlx5_flow_stats_work(struct work_struct *private_)
{
	pr_info("%s: %lx\n", __func__, jiffies);
	schedule_delayed_work(&mlx5_flow_work, HZ);
}

static int delayed_work_init(void)
{
	pr_info("delayed_work enter\n");
	schedule_delayed_work(&mlx5_flow_work, HZ);
	return 0;
}

static void delayed_work_exit(void)
{
        flush_delayed_work(&mlx5_flow_work);
        cancel_delayed_work(&mlx5_flow_work);
	pr_info("delayed_work exit\n");
}

module_init(delayed_work_init);
module_exit(delayed_work_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
