#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int fib[SIZE] = {0};
void *runner(void *param);

int main(int argc, char *argv[])
{
	fib[1] = 1;
	pthread_t tid; 
	pthread_attr_t attr;	

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

	int to = atoi(argv[1]);

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);
	pthread_join(tid, NULL);

	for (int i = 0; i < to; ++i)
		printf("%d ", fib[i]);
	printf("\n");
	
	return 0;
}

void *runner(void *param)
{
	int i = atoi((char*)param);
	if (i != 0 && i != 1) 
		for (int j = 2; j < i; ++j) 
			fib[j] = fib[j-1] + fib[j-2];
	pthread_exit(0);
}