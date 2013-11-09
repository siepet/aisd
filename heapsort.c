// heap sort

// Marcin Siepetowski



#include <stdio.h>

#include <stdlib.h>

#define MAX 100

int A[MAX];

int heapSize;

int length;



void heapify(int A[], int i){

    int l = 2 * i;

    int r = 2 * i + 1;

    int largest;

    if(l <= heapSize && A[l] > A[i]){

        largest = l;

    } else {

        largest = i;

    }



    if(r <= heapSize && A[r] > A[largest]){

        largest = r;

    }



    if(largest != i){

        int tmp;

        tmp = A[i];

        A[i] = A[largest];

        A[largest] = tmp;

        heapify(A, largest);

    }



}

void build_heap(int A[]){

    heapSize = length;

    int i;

    for(i = length/2; i > 0; i--){

            heapify(A, i);

    }



}

void heapsort(int A[]){

    int i;

    build_heap(A);

    for(i=length; i>=2; i--){

        int tmp;

        tmp = A[1];

        A[1] = A[i];

        A[i] = tmp;

        heapSize--;

        heapify(A, 1);

    }

}

int main(void){



    FILE* input = fopen("input.txt", "r");
    if(input == NULL){
	printf("No input.txt file found!");
    }
    //reading numbers to an array from a file

    int lines = 1 /* because we start from index 1, not 0 */, n;

    int i;

    // to make sure it is viable

 	A[0] = 0;

    do{

        n = fscanf(input, "%d", &A[lines]);

        lines++;

    } while(n != EOF);

    fclose(input);

    length = lines - 2;

    heapsort(A);

    // writing to output file the sorted heap

    FILE* output = fopen("output.txt", "w");

    for(i=1;i<=length;i++){

        fprintf(output, "%d ", A[i]);

    }

    fclose(output);

    return 0;

}


