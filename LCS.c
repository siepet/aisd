#include <stdio.h>
//#include <conio.h>
#include <string.h>

int i, j, m, n, a, c[20][20];
char x[15], y[15], b[20][20];
void PRINT(int i,int j){
    if(i==0 || j==0){
        return;
    }
    if(b[i][j] == 'c'){         // \    cross
        PRINT(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u'){      // |    up
        PRINT(i-1,j);
    } else {                    // -    left
        PRINT(i,j-1);
    }
}
void lcs_length(void){
    m = strlen(x);
    n = strlen(y);
    for(i = 0; i <= m; i++){
        c[i][0]=0;
    }
    for(i = 0; i<= n; i++){
        c[0][i] = 0;
    }
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(x[i-1] == y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'c';
            } else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'l';
            }
        }
    }
    PRINT(m,n);
 }
int main(void){
    printf("1 ciag:\n");
    gets(x);
    printf("2 ciag:\n");
    gets(y);
    printf("Najdluzszy wspolny podciag: \n");
    lcs_length();
    printf("\n");

    return 0;
}
