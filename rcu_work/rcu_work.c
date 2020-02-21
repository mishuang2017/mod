#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

struct foo {
	int a;
	char b;
	long c;
	struct rcu_work rwork;
};
DEFINE_SPINLOCK(foo_mutex);

struct foo __rcu *gbl_foo;

int foo_get_a(void)
{
	int retval;

	rcu_read_lock();
	retval = rcu_dereference(gbl_foo)->a;
	rcu_read_unlock();
	return retval;
}

void foo_reclaim(struct work_struct *work)
{
	struct foo *fp = container_of(to_rcu_work(work), struct foo, rwork);

	printk(KERN_INFO "%s is called\n", __func__);
	kfree(fp);
}

void my_queue_work(struct rcu_work *work, work_func_t func)
{
	INIT_RCU_WORK(work, func);
	queue_rcu_work(system_wq, work);
}

void foo_update_a(int new_a)
{
	struct foo *new_fp;
	struct foo *old_fp;

	new_fp = kmalloc(sizeof(*new_fp), GFP_KERNEL);
	spin_lock(&foo_mutex);
	old_fp = rcu_dereference_protected(gbl_foo, lockdep_is_held(&foo_mutex));
	*new_fp = *old_fp;
	new_fp->a = new_a;
	rcu_assign_pointer(gbl_foo, new_fp);
	spin_unlock(&foo_mutex);
	my_queue_work(&old_fp->rwork, foo_reclaim);
}

MODULE_LICENSE("Dual BSD/GPL");

static int rcu_work_init(void)
{
	int a = 0;

	gbl_foo = kmalloc(sizeof(struct foo), GFP_KERNEL);
	foo_update_a(1);
	a = foo_get_a();
	printk(KERN_ALERT "rcu_work enter, %d\n", a);
	return 0;
}

static void rcu_work_exit(void)
{
	printk(KERN_ALERT "rcu_work exit\n");
}

module_init(rcu_work_init);
module_exit(rcu_work_exit);

MODULE_AUTHOR("mishuang");
MODULE_DESCRIPTION("A Sample Hello World Module");
MODULE_ALIAS("A Sample module");
