#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	 int size;
	printf("\nEnter size of Matrix\n");
	scanf("%d", &size);
	int N[size][size], M[size][size], P[size][size];
	int s, p, d;
	//printf("\nEnter Firt Matrix\n");
	for(s=0; s<size; s++) {
	 for(p=0; p<size; p++) {
	  N[s][p]=rand() % 50;
	  }
	}
	
	for(s=0; s<size; s++) {
	 for(p=0; p<size; p++) {
	  M[s][p]=rand() % 50;
	 }
	}
	
 clock_t begin = clock();
	
	for(s=0; s<size; s++) {
	 for(p=0; p<size; p++) {
	  P[s][p]=0;
	  for(d=0; d<size; d++) {
		P[s][p]=P[s][p] + N[s][d] * M[d][p];
	   }
	  }
	}
	printf("\nThe results is…\n");
	for(s=0; s<size; s++) {
	 for(p=0; p<size; p++) {
	  }
	}
	clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time elapsed was :%lfs\n", time_spent);
  return 0;
}
	

