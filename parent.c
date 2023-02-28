/*********** MODULE FOR PRINT THE PID PPID AND THE PROCESS TREE **************/


#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TO PRINT TREE");
MODULE_AUTHOR("KERNEL MASTER");
 
 
static int __init hello_init(void)
{
	struct task_struct *task, *parent_task;
	task = current;
	parent_task = task->parent;

	printk(KERN_INFO "Hello world\n");
	printk(KERN_INFO "current process: name=%s, pid=%d\n", task->comm, task->pid);
	printk(KERN_INFO "parent process: name=%s, pid=%d\n", parent_task->comm, parent_task->pid);
	while (task->pid !=0)
	{
		task =task->parent;
		printk(KERN_INFO "process in tree: name=%s, pid=%d\n", task->comm,task->pid);
	}
		return 0;
}
	static void __exit hello_exit(void)
	{
		printk(KERN_INFO "Hello world completed\n");


	}


module_init(hello_init);   
module_exit(hello_exit);

 

