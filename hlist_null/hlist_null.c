#include <linux/init.h>
#include <linux/module.h>
#include <linux/list_nulls.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hlist_null_init(void)
{
	struct hlist_nulls_head head;
	struct hlist_nulls_node node;

	INIT_HLIST_NULLS_HEAD(&head, 0);
	hlist_nulls_add_head(&node, &head);
	pr_info("hlist_null head: %px\n", &head.first);
	pr_info("hlist_null add: %px, %px\n", node.next, node.pprev);
	hlist_nulls_del(&node);
	pr_info("hlist_null delete: %px, %px\n", node.next, node.pprev);
	return 0;
}

static void hlist_null_exit(void)
{
	pr_info("hlist_null exit\n");
}

module_init(hlist_null_init);
module_exit(hlist_null_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
