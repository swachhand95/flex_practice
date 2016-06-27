#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int value = 0;
void *runner(void *param);

int main(int argc, char *argv[])
{
	int pid;
	pthread_t tid; // Thread id
	pthread_attr_t attr;	// thread attributes

	pid = fork();

	if (pid == 0)	// child process
	{
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, runner, NULL);
		pthread_join(tid, NULL);
		printf("CHILD: value = %d\n", value);
	}
	else if (pid > 0) // parent process
	{
		wait(NULL);	// wait for the child process to complete
		printf("PARENT: value = %d\n", value);
	}

	return 0;
}

void *runner(void *param)
{
	value = 5;
	pthread_exit(0);
}