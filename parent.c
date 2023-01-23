#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/sched.h>

MODULE_AUTHOR("innominds");
MODULE_LICENCE("GPL");

static parent_init (void)

void parent_task(struct task_struct *task) {

    struct task_struct *parent;
    char filename[MAX_FILE_LEN];

    if (task && task->mm) {

        parent = get_parent(task);

        printk("%s (ppid%d)", exe_from_ni(task->ni, filename, MAX_FILE_LEN),
            get_task_ppid(task));

        if (parent && task->pid != 1) {
            printk(", ");
            parent_task(parent);
        }
    }

}
module_init(parent_init);
module_exit(parent_exit);
