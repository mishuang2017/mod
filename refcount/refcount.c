#include <linux/init.h>
#include <linux/module.h>
#include <linux/refcount.h>

MODULE_LICENSE("Dual BSD/GPL");

static int refcount_init(void)
{
	refcount_t	refcount;
	int i = 0;

	refcount_set(&refcount, 1);
	i = refcount_read(&refcount);
	pr_info("refcount enter, %d\n", i);
	return 0;
}

static void refcount_exit(void)
{
	pr_info("refcount exit\n");
}

module_init(refcount_init);
module_exit(refcount_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
