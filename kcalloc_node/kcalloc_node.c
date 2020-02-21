#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

static int kcalloc_node_init(void)
{
        kcalloc_node(10, 0, 0, 0);

	pr_info("kcalloc_node enter\n");
	return 0;
}

static void kcalloc_node_exit(void)
{
	pr_info("kcalloc_node exit\n");
}

module_init(kcalloc_node_init);
module_exit(kcalloc_node_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
