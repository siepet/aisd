#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ALOT 100000
#define MLD 1000000000.0 // 10 ** 9

//#define C 5
int C;
int A[ALOT];
int B[ALOT];
int length;

int Partition(int *A, int p, int r);
void QuickSort(int *A, int p, int r){

	if(p < r){
		int q = Partition(A, p, r);
		QuickSort(A, p, q);
		QuickSort(A, q+1, r);
	
	
	}

}
void Bubble(int *A, int p, int r);
void QuickSort_Bubble(int *A, int p, int r){
	
	if(p < r){
		if(r - p + 1 < C){
			Bubble(A, p, r);
		} else {
			int q = Partition(A, p, r);
			QuickSort_Bubble(A, p, q);
			QuickSort_Bubble(A, q + 1, r);
		}
	}
}

void Bubble(int *A, int p, int r){
	int i, tmp, j;
	for(i = p; i <= r; i++){
		for(j = p; j <= r; j++){
			if(A[j] > A[j+1]){
				tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
		}
	}

}
int Partition(int *A, int p, int r){
	int x = A[r];
	int i = p - 1;
	int j; // iterator
	for(j = p; j <= r; j++){
		if(A[j] <= x){
			i++;
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	if(i < r){
		return i;
	} else {
		return i - 1;
	}
}

void wczytaj(){
	FILE *input_k = fopen("input_k.txt", "r");
	FILE *input_nk = fopen("input_nk.txt", "r");
	int i = 0, n;
	do {
		n = fscanf(input_nk, "%d", &A[i]);
		n = fscanf(input_nk, "%d", &B[i]);
		i++;

	} while(n != EOF);
	length = i - 1;

	fclose(input_k);
	fclose(input_nk);
	puts("Wczytano prawidlowo!");
}

void zapisz(){
	FILE *output_k  = fopen("output_k.txt", "w");
	FILE *output_nk = fopen("output_nk.txt", "w");
	int i; 
	for(i = 0; i < length; i++){
		fprintf(output_k, "%d ", A[i]);
		fprintf(output_nk, "%d ", B[i]);
	}
	fprintf(output_k, "\n");
	fprintf(output_nk, "\n");
	fclose(output_k);
	fclose(output_nk);
	puts("Zapisano prawidlowo!");

}

void wyswietl(){
	int i;
	for(i = 0; i < length; i++){
		printf("A[%d] == %d \t B[%d] == %d ",i, i, A[i], B[i]);
	}
	putchar(10);

}




int main(void){
	
	struct timespec tp0, tp1;
	struct timespec tp2, tp3;
	double czas1, czas2; // , funkcja, x;
	double f_1, f_2;
	int i;
	
	wczytaj();
	int G[] = {99, 1, 5, 7, 2, 8, 9, 3, 4, 5, 1, 2, 6, 5};
	puts("Przed sortowaniem: ");
//	wyswietl();

//	for();
//
	
	for(i = 1000; i <= 10000; i += 100){
	C = log(i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
		QuickSort_Bubble(A, 0, i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
		czas1 = (tp1.tv_sec + tp1.tv_nsec/MLD) - (tp0.tv_sec + tp0.tv_nsec/MLD);
		
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp2);
		QuickSort(B, 0, i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp3);
		czas2 = (tp3.tv_sec + tp3.tv_nsec/MLD) - (tp2.tv_sec + tp2.tv_nsec/MLD);
		

		
		f_1 = i * i; 
		f_2 = i * i;
	printf("n = %d\tczas_k = %lf\tczas_nk = %lf \n\t      wsp_k =  %lf\twsp_nk = %lf\n", i, czas1, czas2,f_1/czas1, f_2/czas2);
	}
	
	putchar(10);
	puts("Po sortowaniu: ");
//	wyswietl();

	
	zapisz();



	return 0;
}





