#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

int mod_init(void)
{
	struct task_struct *task;
	struct thread_info *ti;

	ti = current_thread_info();

	task = ti->task;

	pr_info("\nProgram Name %s", task->comm);
	pr_info("\nthread_info at %p", ti);
	pr_info("\nprocess descriptor at %p", task);
	pr_info("\nStack starts at %p\n", task->stack);
		
	return 0;
}

void mod_exit(void)
{

}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("support@techveda.org");
MODULE_DESCRIPTION("LKD_CW: Print proc info");
