/*kernel hello world program*/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched.h>
#include<asm/current.h>

MODULE_AUTHOR("Innominds..\n");
MODULE_LICENSE("GPLV2");
MODULE_DESCRIPTION("Hello world program..\n");

static int hello_init(void)
{
	printk("pid:%d  " ,current->pid,current->comm);

	printk(KERN_INFO "%S: %S: %d\n",__FILE__,__func__,__LINE__);
	return 0;
}

static void hello_exit(void)
{
	printk("%s: %s : %d\n",__FILE__,__func__,__LINE__);
}

module_init(hello_init);
module_exit(hello_exit);



