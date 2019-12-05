#include <stdio.h>
#include <omp.h>
#define N 16 
#define T 4 
#define b 3
int  main(){
int v1[N], v2[N],rang, nbr=0, scal=0, i;
double t1, t2;
    for(i=0;i<N;i++){
          v1[i]=i;
          v2[i]=2;
    }
    omp_set_num_threads(T);
    t1 = omp_get_wtime();
    #pragma omp parallel private(rang) firstprivate (nbr) 
    {
    rang=omp_get_thread_num();
    #pragma omp for reduction (+: scal) schedule (static, b)  
    for(i=0;i<N;i++){
         scal+=v1[i]*v2[i];
         nbr++; 
    }
    printf("thread %d : nombre d'elements = %d\n",rang,nbr);
   // #pragma omp barrier
    if(rang==T-1){
    printf("Je suis le thread %d, le produit scalaire est %d\n",rang, scal);
    }  
    }
    t2 = omp_get_wtime();
    printf("Le temps de calcul est : %f\n (s)", t2-t1);
 
    return 0;
}

