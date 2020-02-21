#include <linux/init.h>
#include <linux/module.h>
/* #include <net/netevent.h> */

MODULE_LICENSE("Dual BSD/GPL");

struct testa
{
	int a;
};

struct testa *a = NULL;

static int hello_init(void)
{
	int num = 1;
	num = ALIGN(1, 4);

	printk(KERN_ALERT "hello: %d: %px\n", num, a);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Hello World exit\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
