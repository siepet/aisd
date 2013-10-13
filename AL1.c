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
double procedura2(int *n){
	float x = 0.0;
	float suma;
	size_t size = sizeof(n)/sizeof(int);
	int g, d, i;
	
	for(d = 1; d <= size; d++){
		for(g = d; g <= size; g++){
			suma = 0.0;
			for(i = d; i <= g; i++){
				suma = suma + n[i];
			}
			x = suma > x ? suma : x;
	
		}
	}
	return x;

}
int procedura3(int n){
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
for(n=2;n<66000;n=2*n){

clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);

// przykladowe obliczenia
    x=procedura1(n);

// zgadywana funkcja
      //  Fn=5*n ; // np. funkcja liniowa
//      Fn=20000*n ; // np. funkcja liniowa
//      Fn=n*n*n; 
//      Fn=n*log(n); 
//      Fn=n*n*sqrt(n);
//      Fn=n*n; 
//      Fn=n*n/1000; 
    
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);

  Tn=(tp1.tv_sec+tp1.tv_nsec/MLD)-(tp0.tv_sec+tp0.tv_nsec/MLD);
  Fn = n*10;
  printf("n: %5d \tczas: %3.5lf \twspolczynnik: %3.5lf\n",n,Tn, Fn/Tn);
}
}
