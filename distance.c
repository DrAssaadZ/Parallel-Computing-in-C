#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#define N  5
#define M  2

double Mat[N][M];

double distance (int i, int j){
    int k; 
    double dist=0;
    for(k=0; k<M; k++)
       dist+=(Mat[i][k]-Mat[j][k])*(Mat[i][k]-Mat[j][k]);
   return sqrt(dist);
}

int main () {
double  Mdist [N][N];
int  i, j;

srand(time(0));
for (i=0; i<N; i++) {
    for(j=0; j<M; j++){
        Mat[i][j]=  rand()%5;
        printf(" %f ",  Mat[i][j]);
    }
    printf(" \n ");
}

for (i=0; i< N-1; i++)
  for(j=i+1; j<N; j++) {
     Mdist[j][i]=distance(i, j);
}

printf(" \n ");

for (i=0; i<N-1; i++)
    for(j=i+1; j<N; j++){
       printf(" %f ",  Mdist[j][i]);
    }

printf(" \n ");

return 0;
}
