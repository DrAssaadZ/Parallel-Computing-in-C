#include <stdio.h>
#include <omp.h>
#define T 4
#define N 4 
#define M 4 	
int  main(){
int a[N][M], nbocc_t[T], nbocc=0, i, j, rang, x ;
    // initialisation d'un tableau d'entiers
    scanf("%d", &x);
for(i=0;i<N;i++)
       for (j=0; j< M; j++)
               a[i][j]=5;

   // initilisation du tableau des min locaux aux threads
    for(i=0;i<T;i++) nbocc_t[i]=0;
   // définition du nombre de threads de la région parallèle
    omp_set_num_threads(T);
   // ouverture de la région parallèle
    #pragma omp parallel private(rang)
    {
    // récupération du rang du thread en cours
    rang=omp_get_thread_num();
    // déclaration de la boucle parallèle
    #pragma omp for private(i), schedule (static, 2) 
      for(j=0;j<M;j++)
         for(i=0;i<N;i++) nbocc_t[rang]=(a[i][j]==x ? nbocc_t[rang]+1 : nbocc_t[rang]);
    // affichage du rang et du min local du thread en cours
    printf("thread %d : nbocc_t=%d\n",rang, nbocc_t[rang]);
   }
    
   // boucle calculant le minimum des min locaux aux thread
    for(i=0; i<T; i++)
       nbocc+=nbocc_t[i]; 
    printf(" Le nombre d'occurences de %d  est  %d\n", x, nbocc);
    return 0;
}

