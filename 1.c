#include <stdio.h>
#include<omp.h>
#include<stdlib.h>

#define N 6


int main(int argc,char*argv[]) {
   
   
   int rows=N, i, j, space;
   

   double time = omp_get_wtime();
   #pragma omp  for 
  for (i = rows; i >= 1; --i) {
      for (space = 0; space < rows - i; ++space)
         printf("  ");
      for (j = i; j <= 2 * i - 1; ++j)
         printf("* ");
      for (j = 0; j < i - 1; ++j)
         printf("* ");
      printf("\n");
   }

printf("\nExecuted Done in %f seconds\n",  omp_get_wtime()-time);
   return 0;
}
