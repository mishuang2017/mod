#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int test_printk_init(void)
{
	pr_debug("test_printk debug enter\n");
	printk(KERN_DEBUG "%s: debug\n", __func__);
	pr_info("test_printk info enter\n");
	return 0;
}

static void test_printk_exit(void)
{
	pr_info("test_printk exit\n");
}

module_init(test_printk_init);
module_exit(test_printk_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
