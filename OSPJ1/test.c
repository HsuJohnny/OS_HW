#include<sys/syscall.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int n1, n2, ans1, ans2;
	printf("Please input two numbers :");
	scanf("%d %d", &n1, &n2);
	ans1 = syscall(338, n1, n2);
	ans2 = syscall(339, n1, n2);
	syscall(337);
	printf("Multiply answer is %d \n", ans1);
	printf("Min answer is %d \n", ans2);
	return 0;
}
