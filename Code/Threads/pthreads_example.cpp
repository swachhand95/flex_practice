#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void *runner(void *param);

int main(int argc, char *argv[])
{
	pthread_t tid; // Thread id
	pthread_attr_t attr;	// thread attributes

	if (argc != 2) 
	{
		fprintf(stderr, "Please enter a positive integer\n");
		return -1;
	}
	if (atoi(argv[1]) < 0) 
	{
		fprintf(stderr, "Please enter a positive integer\n");
		return -1;
	}

	pthread_attr_init(&attr);	// get the default attributes
	pthread_create(&tid, &attr, runner, argv[1]);	// create the thread
	pthread_join(tid, NULL);	// wait for the thread to exit

	printf("Sum = %d\n", sum);

	return 0;
}

void *runner(void *param)
{
	int upper = atoi((char* )param);
	int i = 1;
	for (; i <= upper; ++i)
		sum += i;

	pthread_exit(0);
}