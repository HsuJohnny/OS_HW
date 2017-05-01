#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage int sys_show(void)
{
	printk("b02901113, Cheng Han Hsu \n");
	return 0;
}
