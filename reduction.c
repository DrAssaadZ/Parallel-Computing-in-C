#include <stdio.h>
#include<omp.h>


int main(){
  int a[4][4],s=0, i,j;
 for(i=0;i<4;i++)
 for(j=0;j<4;j++)
 a[i][j]=i*4+j;
 #pragma omp parallel
 {
 #pragma omp for   reduction(+:s) private(j)
 for(i=0;i<4;i++){
   for(j=0;j<4;j++) s=s+a[i][j];
    
    printf("PAR*********=%d : i=%d s=%d\n",
      omp_get_thread_num(),i,s);

   }
  printf("PAR*********=%d :  s=%d\n",
      omp_get_thread_num(),s);
 
   }
   
   printf("SEQ s=%d\n",s);
}
