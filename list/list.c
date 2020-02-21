#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

struct node {
	struct list_head list;
	int v;
};

struct list_head head;

/*
static void test_list(void)
{
	struct node a;
	struct node b;
	struct node c;
	struct node d;
	struct node *n;

	INIT_LIST_HEAD(&head);

	a.v = 1;
	list_add_tail(&a.list, &head);
	b.v = 2;
	list_add_tail(&b.list, &head);
	c.v = 3;
	list_add_tail(&c.list, &head);
	d.v = 4;
	list_add(&d.list, &c.list);

	list_for_each_entry(n, &head, list) {
		pr_info("%d\n", n->v);
	}
}
*/

static void test_list2(void)
{
	struct node *a, *tmp;
	int i;

	INIT_LIST_HEAD(&head);

	for (i = 0; i < 1; i++) {
		a = kzalloc(sizeof(*a), GFP_KERNEL);
		a->v = i;
		pr_info("add: %d\n", a->v);
		list_add(&a->list, &head);
	}

	i = 0;
/* 	list_for_each_entry_safe(a, tmp, &head, list) { */
	list_for_each_entry(a, &head, list) {
		pr_info("free: %d\n", a->v);
		kfree(a);
		if (i++ == 5)
			break;
	}
}

static int list_init(void)
{
	pr_info("list enter\n");
/* 	test_list(); */
	test_list2();
	return 0;
}

static void list_exit(void)
{
	pr_info("list exit\n");
}

module_init(list_init);
module_exit(list_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
