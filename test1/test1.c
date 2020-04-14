#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int test1_init(void)
{
	struct attribute attr;
	static struct lock_class_key __key;
	bool b;
	u32 u;

	attr.key = &__key;
	pr_info("test1 enter, %d, %d\n", sizeof(b), sizeof(u));
	return 0;
}

static void test1_exit(void)
{
	pr_info("test1 exit\n");
}

module_init(test1_init);
module_exit(test1_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
