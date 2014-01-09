#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 1500
int kolizje = 0;
int numbers = 0;
int A[m] = { 0 };

int hash(int k){
    return k % m;
}
int getSize(const char *filename){
    int length = 0;
    int k;
    char tmp[25];
    FILE *f = fopen(filename, "r");
    do{
        k = fscanf(f, "%s", tmp);
        length++;
    }while(k == 1);
    return length;

}
void insert_chained(int T[], int k){
    if(T[hash(k)] > 0){
        A[hash(k)]++;
    } else {
        T[hash(k)] = k;
        A[hash(k)]++;
    }
}

void show(int T[]){
    int i;
    printf("\n====================================\n");
    printf("========   T A B L E   =============\n");
    for(i = 0; i < m; i++){
        printf("T[%i] \t==\t %i \n", i, T[i]);
    }
    printf("====================================\n");
}
void show_K(int T[]){
    int i;
    printf("\n====================================\n");
    printf("========   T A B L E   =============\n");
    for(i = 0; i < m; i++){
        if(T[i] > 0)
            printf("T[%i] \t==\t %i \n", i, T[i]);
    }
    printf("====================================\n");
}
int to_int(const char * word);
void load(int T[], const char *filename){
    int i;
    int size = getSize(filename) - 1;
    FILE *f = fopen(filename, "r");
    printf("%i", size);
    char tmp[20];
    for(i = 0; i < size; i++){
            fscanf(f, "%s", tmp);
            T[i] = to_int(tmp);
    }
    puts("Loaded succesfully! \n");
}
int to_int(const char * word){
    long int number = 0;
    int length = strlen(word);
    int i;
    for(i = 0; i < length; i+=2){
        number += ((int)word[i] * 11) ^ (int)word[i+1];
    }
    return number;

}
void zlicz(){
    int i = 0;
    int zera = 0;
    int niezera = 0;
    int iloscNiezer = 0;
    int max = 0;
    for(i = 0; i < m; i++){
        if(A[i] == 0){
            zera++;
        }
        if(A[i] > 0){
            niezera += A[i];
            iloscNiezer++;
        }
        max = ((A[i] > max) ? (A[i]) : (max));
    }

    printf("\n");
    printf("(bez kolizyjnych kluczy) Ilosc zer w tablicy A: %d \n", zera);
    printf("(najwieksza ilosc kolizji) Najwieksza ilosc kolizji w tablicy A: %d \n", max);
    printf("(srednia wartosc pozycji niezerowych w tablicy A: %lf \n", (float)niezera/(float)iloscNiezer);
}
int main(void){
    int J[m] = { 0 };
    int i;
    int k = getSize("plik1.txt");
    int T[k];
    load(T, "plik1.txt");
    for(i = 0; i < 2*m; i++){
        insert_chained(J, T[i]);
    }
    show_K(A);
    zlicz();
    return 0;


}
