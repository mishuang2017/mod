#include <linux/init.h>
#include <linux/module.h>
#include <linux/rhashtable.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

struct mlx5e_tc_flow {
	struct rhash_head	node;
	u64			cookie;
};

static const struct rhashtable_params tc_ht_params = {
	.head_offset = offsetof(struct mlx5e_tc_flow, node),
	.key_offset = offsetof(struct mlx5e_tc_flow, cookie),
	.key_len = sizeof(((struct mlx5e_tc_flow *)0)->cookie),
	.automatic_shrinking = true,
};

static int hash_init(void)
{
	struct rhashtable tc_ht;
/* 	struct mlx5e_tc_flow flow1; */
	struct mlx5e_tc_flow *flow2;
	struct mlx5e_tc_flow *flow;
	struct mlx5e_tc_flow *flow_p;
	int sz = sizeof (struct mlx5e_tc_flow);
	int err;

	pr_info("hash enter\n");
	rhashtable_init(&tc_ht, &tc_ht_params);

#if 0
	flow1.cookie = 1;
	err = rhashtable_insert_fast(&tc_ht, &flow1.node, tc_ht_params);
	if (err)
		pr_info("err: %d\n", err);
	else
		pr_info("%px\n", &flow1);
#endif

	flow2 = kzalloc(sz, GFP_KERNEL);
	flow2->cookie = 1;
	err = rhashtable_insert_fast(&tc_ht, &flow2->node, tc_ht_params);
	pr_info("insert\n");
	if (err)
		pr_info("err: %d\n", err);
	else
		pr_info("%px\n", &flow2);

	err = rhashtable_remove_fast(&tc_ht, &flow2->node, tc_ht_params);
	pr_info("remove\n");
	if (err)
		pr_info("err: %d\n", err);

	flow_p = kzalloc(sz, GFP_KERNEL);
	flow_p->cookie = 1;
	flow = rhashtable_lookup_fast(&tc_ht, &flow_p->cookie, tc_ht_params);
	pr_info("lookup, %px\n", flow);

	kfree(flow2);
	kfree(flow_p);

	return 0;
}

static void hash_exit(void)
{
	pr_info("hash exit\n");
}

module_init(hash_init);
module_exit(hash_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
