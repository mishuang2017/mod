#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

static int slab_init(void)
{
	pr_info("slab enter, %lx\n", KMALLOC_MAX_SIZE);
	pr_info("slab enter, %lx\n", KMALLOC_MAX_CACHE_SIZE);
	return 0;
}

static void slab_exit(void)
{
	pr_info("slab exit\n");
}

module_init(slab_init);
module_exit(slab_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
