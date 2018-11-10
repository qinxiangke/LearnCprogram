/*key points: Loadable Kernel Module*/
/*1. complilable but non-runnable independtly
After being loaded in the kernel then running in kernel space */

#include <linux/module.h>   /*mandatory*/
#include <linux/kernel.h>   /*kernel function*/
#include <linux/init.h>     /*including _init and _exit*/

static int __init lkp_init( void )  /*to initialize module*/
{
	printk("<1>Hello,World! from the kernel space...\n");
	return 0;
}

static void __exit lkp_cleanup( void )  /*to exit and clean**/
{
	printk("<1>Goodbye,World! leaving kernel space...\n");
}
module_init(lkp_init);  /*entry of the driver program*/
module_exit(lkp_cleanup);
MODULE_LICENSE("GPL");