#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int kernel_version_init(void)
{
	pr_info("kernel_version enter: %x\n", LINUX_VERSION_CODE);
	return 0;
}

static void kernel_version_exit(void)
{
	pr_info("kernel_version exit\n");
}

module_init(kernel_version_init);
module_exit(kernel_version_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
