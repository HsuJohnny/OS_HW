#include<stdio.h>
#include<pthread.h>
#include<sched.h>

pthread_t tid[2];

void* showRun(void* arg)
{
	pthread_t id=pthread_self();
	double a=0;	
	if(pthread_equal(id, tid[0]))
	{
		for(int i=0;i<3;i++)
		{
			printf("\nThread 1 is running\n");
			for(int i =0;i<10000000;i++) a+=0.1;
		}
	}
	else
	{	
		for(int i=0;i<3;i++)
		{
			printf("\nThread 2 is running\n");
			for(int i =0;i<10000000;i++) a+=0.1;
		}
	}
}

int main()
{
	int err;
	for(int i=0;i<2;i++)
	{
		err=pthread_create(&(tid[i]), NULL, &showRun, NULL);
		if(err!=0) 
			printf("can't create thread!");
		else
			printf("\nThread %i successfully create!", i+1);
	}
	for(int i=0;i<2;i++)
	{
		pthread_join(tid[i], NULL);
	}
}




