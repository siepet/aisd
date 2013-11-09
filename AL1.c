// kompilowac z opcjami -lrt -lm: gcc AL1.c -lrt -lm
#include <time.h>
#include <stdio.h>
#include <math.h>
#define MAX 60000l
#define MLD 1000000000.0 //10**9
double procedura1(int n){
 float x=0;
 int i,j,k;

 for(i=n-1;i>1;i--) {
  if((i % 2) == 1) {
    for(j=1;j<i+1;j++) ; 
    for(k=i+1;k<n+1;k++) x=x+1;
    }
 } 
 return x;
}
double procedura2(int A[], int n){
	float x = 0.0;
	float suma;
	int g, d, i;
	
	for(d = 1; d <= n; d++){
		for(g = d; g <= n; g++){
			suma = 0.0;
			for(i = d; i <= g; i++){
				suma = suma + A[i];
			}
			//x = max(x,suma);
			x = x > suma ? x : suma;
		}
	}
	return x;

}
void procedura3(int n){
		int i, j;
		for(i = 1; i < sqrt(n); i++){
			j = 1; 
			while(j < sqrt(n)){
				j = j+j;
			
			}
		}
}
main(){
  struct timespec tp0, tp1;
  double Tn,Fn,x;
  int n;
  int A[100];
  for(n=0;n<100;n++){
  	A[n] = n*n;
  }

for(n=2;n<200000000;n*=2){

clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
//x = procedura1(n);
//x = procedura2(A, n);
procedura3(n);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);

  Tn=(tp1.tv_sec+tp1.tv_nsec/MLD)-(tp0.tv_sec+tp0.tv_nsec/MLD);
	
//  	Fn = n*n;
//	Fn = n*n*n ; // np. funkcja liniowa
	Fn = log(sqrt(n)) * sqrt(n);
//      Fn = 20000*n ; // np. funkcja liniowa
//      Fn = n*n*n; 
//      Fn = n*log(n); 
//      Fn = n*n*sqrt(n);
//      Fn = n*n; 
//      Fn = n*n/1000; 
    
  printf("n: %5d \tczas: %3.5lf \twspolczynnik: %3.5lf\n",n,Tn, Fn/Tn);

}
// testy sprawwdzające działanie procedury2
// procedura sumuje wartosci tablicy A[n] do n-tego elementu
/*
for(n=0;n<100;n++){
	printf("\n A[%d] == %d, procedura2(A, %d) == %lf ", n, A[n], n, procedura2(A,n));
}
*/

printf("\n");


	return 0;
}
