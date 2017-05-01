#include<stdio.h>
#include<pthread.h>
#include<sched.h>

pthread_barrier_t barrier;
pthread_t tid[2];

void* showRun(void* arg)
{
	cpu_set_t mask;
	CPU_ZERO(&mask);
        CPU_SET(0, &mask);
        sched_setaffinity(0, sizeof(mask), &mask);
	pthread_t id=pthread_self();
	double a=0;
	int s=0;
	struct sched_param param;
	param.sched_priority=sched_get_priority_max(SCHED_FIFO);
	s=sched_setscheduler(0, SCHED_FIFO, &param); 	
	pthread_barrier_wait(&barrier);
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
	pthread_barrier_init(&barrier, NULL, 2);
	int err;
	for(int i=0;i<2;i++)
	{
		/**	
		pthread_attr_t *attr=new pthread_attr_t;
		struct sched_param *param=new struct sched_param;
		param->sched_priority=sched_get_priority_max(SCHED_FIFO)-i;
		pthread_attr_setinheritsched(attr, PTHREAD_EXPLICIT_SCHED);
		pthread_attr_setschedpolicy(attr, SCHED_FIFO);
		pthread_attr_setschedparam(attr, param);
		**/
		err=pthread_create(&(tid[i]), NULL, &showRun, NULL);
		if(err!=0) 
			printf("can't create thread!\n");
		else
			printf("\nThread %i successfully create!\n", i+1);
	}
	for(int i=0;i<2;i++)
	{
		pthread_join(tid[i], NULL);
	}
	return 0;
}




