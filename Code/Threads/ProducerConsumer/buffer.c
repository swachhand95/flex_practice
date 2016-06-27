#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

buffer_item buffer[BUFFER_SIZE];
int head = 0;
int tail = 0;

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

enum {FALSE, TRUE};

int insert_item(buffer_item item)
{
	if (head - tail + 1 == BUFFER_SIZE)
	{
		fprintf(stderr, "Buffer is full, can't add more items\n");
		return -1;
	}
	buffer[head] = item;
	++head;
	head = head % BUFFER_SIZE;
	return 0;
}

int remove_item(buffer_item *item)
{
	if (head == tail)
	{
		fprintf(stderr, "%s\n", "Buffer is empty, can't remove more items");
		return -1;
	}
	*item = buffer[tail];
	++tail;
	tail = tail % BUFFER_SIZE;
	return 0;
}

void buffer_init(void)
{
	pthread_mutex_init(&mutex, NULL);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, BUFFER_SIZE);
}

void *consumer(void *param)
{
	buffer_item item;

	do
	{	
		// sleep
		sleep(2);

		sem_wait(&full);
		pthread_mutex_lock(&mutex);

		remove_item(&item);
		printf("Removed: %d\n", item);

		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
	while (TRUE);
}

void *producer(void *param)
{
	buffer_item item = 0;
	do 
	{
		item = rand();

		// sleep
		sleep(2);

		sem_wait(&empty);
		pthread_mutex_lock(&mutex);

		insert_item(item);
		printf("Inserted: %d\n", item);

		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
	while (TRUE);
}

int main(int argc, char const *argv[])
{
	pthread_t producer_thread;
	pthread_attr_t producer_attr;
	pthread_t consumer_thread;
	pthread_attr_t consumer_attr;

	buffer_init();

	pthread_attr_init(&producer_attr);
	pthread_attr_init(&consumer_attr);

	pthread_create(&producer_thread, &producer_attr, producer, NULL);
	pthread_create(&consumer_thread, &consumer_attr, consumer, NULL);

	pthread_join(producer_thread, NULL);
	pthread_join(consumer_thread, NULL);

	return 0;
}