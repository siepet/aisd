#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 2013
int kolizje = 0;
int numbers = 0;
int A[m] = { 0 };

struct osoba{
    char nazwisko[25];
    int ilosc;
};

int hashFunc1(int k){
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
    fclose(f);
 return length;

}

int hashFuncA(int k, int i){
    return (hashFunc1(k) + i * i) % m;
}

void print(int k, int j){
    printf("--> h(%d) = %d\n", k, j);
}

int insert(struct osoba *T[], int k, struct osoba* Ludz){
    numbers++;
    int i = 0;
    int j;

    do{
        j = hashFuncA(k, i);
        if(T[j] == (void*)0 || T[j] == (void*)-1){
            //T[j] = k;
            T[j] = Ludz;
//            print(k, j);
            return 1;
        } else {
            A[j]++;
            kolizje++;
            i++;
        }
    }while(i < m);
    return 0;

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

void load(struct osoba T[], const char *filename){
    int i;
    int size = getSize(filename) - 1;
    FILE *f = fopen(filename, "r");
    printf("File size: %i entries.\n", size);
    char tmp[30];
    for(i = 0; i < size; i++){
            fscanf(f, "%i", &T[i].ilosc);
            fscanf(f, "%s", tmp);
            strcpy(T[i].nazwisko, tmp);
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
    printf("Wielkosc tablicy: \t\t%d\n", m);
    printf("Ilosc zer w tablicy T: \t\t%d \n", zera);
    printf("Maksymalna ilosc kolizji: \t%d \n", max);
    printf("Srednia ilosc kolizji:  \t%lf \n", (double)niezera/(double)iloscNiezer);
}
int main(void){
    int i;
    struct osoba *J[m] = { 0 };   // tablica hashy
    int k = getSize("nazwiskaASCII.txt");
    struct osoba T[k];
    load(T, "nazwiskaASCII.txt");
    for(i = 0; i < 0.9*m; i++){
        int liczba = to_int(T[i].nazwisko);
        insert(J, liczba, &T[i]);
    }

   // show_K(A);
    zlicz();
 
    return 0;

}
