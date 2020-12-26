#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct parameters
{
  int s, p;
} args;

int matrix1[MAX_SIZE][MAX_SIZE];
int matrix2[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE][MAX_SIZE];

int maxThread;

void *multiply(void *arg)
{
  args *parm = arg;

  for (int b = 0; b < MAX_SIZE; b++)
  {
    result[parm->s][parm->p] += matrix1[parm->s][b] * matrix2[b][parm->p];
  }
}

void initializeMatrix()
{
  for (int l = 0; l < MAX_SIZE; l++)
  {
    for (int m = 0; m < MAX_SIZE; m++)
    {
      matrix1[l][m] = rand() % 10;
      matrix2[l][m] = rand() % 10;
      result[l][m] = 0;
    }
  }
}

void startThread()
{

  int s = 0, p = 0;

  while (s < MAX_SIZE)
  {
    p = 0;
    while (p < MAX_SIZE)
    {
      pthread_t threads[maxThread];
      args parm[maxThread];

      for (int l = 0; l < maxThread; l++)
      {

        if (p >= MAX_SIZE)
        {
          break;
        }

        parm[l].s = s;
        parm[l].p = p;
        pthread_create(&threads[l], NULL, multiply, (void *)&parm[l]);

        pthread_join(threads[l], NULL);

        p++;
      }
    }
    s++;
  }
}

int main()
{
  initializeMatrix();
  printf("Enter no. of threads:");
  scanf("%d", &maxThread);
  clock_t begin = clock();

  startThread();

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time :%lf \n", time_spent);
}
