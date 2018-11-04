#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 

 
#define NUM_THREADS 8
#define M 4 

pthread_t threads[NUM_THREADS]; 
int m1[M][M] = { {8,6,4,2}, {8,6,4,2}, {8,6,4,2}, {8,6,4,2} },
    m2[M][M] = { {3,6,9,8}, {3,6,9,8}, {3,6,9,8}, {3,6,9,8} }, 
    sum[M][M]; 

void* Add(void* arg) 
{ 
	int i, j; 
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++) 
			sum[i][j] = m1[i][j] + m2[i][j]; 
} 


int main() 
{ 
    int i, j, it = 0; 

    for(i = 0; i < NUM_THREADS; i++)
      pthread_create(&threads[i], NULL, &Add, (void*)it++);
      
  
    for(i = 0; i < NUM_THREADS ; i++) 
      pthread_join(threads[i], NULL); 
    

    printf("\nSum:\n"); 
    for (i = 0; i < M; i++)
    { 
      for (j = 0; j < M; j++)
        printf("%d ", sum[i][j]); 
      
      printf("\n"); 
    } 

    return 0; 
} 
