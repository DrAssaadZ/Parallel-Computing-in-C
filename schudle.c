#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
 void main(){
 int a[MAX],i, imin, imax;
 #pragma omp parallel private(imin,imax)
 {
 imax=0;
 imin=MAX;
 #pragma omp for schudle (static, 2)
 for(i=0;i<MAX;i++){
 imin=i<imin?i:imin;
 imax=i>imax?i:imax;
 a[i]=1;
 //sleep(1); /* pour augmenter la charge */
printf("%d:%d\n",omp_get_thread_num(),i);
 }
 printf("thread %d imin=%d imax=%d\n", omp_get_thread_num(),
imin, imax);
}
}
