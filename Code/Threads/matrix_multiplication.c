#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define K 2
#define N 3

int A[M][K] = {{1, 4},
			   {2, 5},
			   {3, 6}};

int B[K][N] = {{8, 7, 6},
			   {5, 4, 3}};

int C[M][N] = {{0}};

struct v
{
	int row;
	int col;
};

void *runner(void *param);

int main(int argc, char *argv[])
{
	pthread_t workers[M][N];
	pthread_attr_t worker_attrs[M][N];

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			struct v *data = (struct v*) malloc(sizeof(struct v));
			data->row = i;
			data->col = j;

			pthread_attr_init(&worker_attrs[i][j]);
			pthread_create(&workers[i][j], &worker_attrs[i][j], runner, data);
		}
	}

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			pthread_join(workers[i][j], NULL);

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("%d ", C[i][j]);
		printf("\n");
	}

	return 0;
}

void *runner(void *param) 
{
	struct v* data = (struct v*) param;
	int row = data->row;
	int col = data->col;
	C[row][col] = 0;
	for (int i = 0; i < K; ++i)
		C[row][col] += A[row][i] * B[i][col];
	pthread_exit(0);
}