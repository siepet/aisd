#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

void usage(){
    printf("Usage: ./wzorce.out wzorzec.txt tekst.txt \n");
    printf("If your text or pattern has new lines \'\\n\', use: bash deleteEnters.sh fileName \n");
}
int budujTablice(char *pattern, int *tab){
    int i = 1, j = 0, w = strlen(pattern);
    tab[0] = 0;

    while(i < w){
        if(pattern[i] == pattern[j]){
            j++;
            tab[i] = j + 1;
            i++;
        } else {
            if(j != 0){
                j = tab[j - 1];
                i++;
            } else {
                tab[i] = 0;
                i++;
            }
        }
    }

    return 0;
}
// Knuth Morris Pratt
int KMP(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int tab[patternLength];
    budujTablice(pattern, tab);
    int j = 0, i = 0;
    while(i < textLength){
        if(pattern[j] == text[i]){
            j++;
            i++;
        }
        if(j == patternLength){
            printf("KMPIndex: %d ", i - j);
            j = tab[j - 1];
        } else if(pattern[j] != text[i]){
            if(j != 0){
                j = tab[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return 0;
}

// Knuth Morris Pratt modified (assuming '?' as any character)
int KMPM(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int tab[patternLength];
    budujTablice(pattern, tab);
    int j = 0; int i = 0;
    while(i < textLength){
        if(pattern[j] == text[i] || pattern[j] == '?'){
            j++;
            i++;
        }
        if(j == patternLength){
            printf("KMPMIndex: %d ", i - j);
            j = tab[j - 1];
        } else if(pattern[j] != text[i]){
            if(j != 0){
                j = tab[j - 1];
            } else {
                i++;
            }
        }
    }

    return 0;
}

// oczywisty algorytm
int OA(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int i, j;
    for(i = 0; i < textLength - patternLength; i++){
        for(j = 0; j < patternLength; j++){
            if(text[i + j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            printf("OA: Index: %d ", i);
        }
    }
    return 0;
}
// Rabin-Karp
int RK(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int q = 101;
    int d = 256;

    for(i = 0; i < patternLength - 1; i++){
        h = (h * d) % q;
    }

    for(i = 0; i < patternLength; i++){
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for(i = 0; i <= textLength - patternLength; i++){
        if(p == t){
            for(j = 0; j < patternLength; j++){
                if(text[i + j] != pattern[j]){
                    break;
                }
            }
            if(j == patternLength){
                printf("RKIndex: %d ", i);
            }
        }
        if(i < textLength - patternLength){
            t = (d * (t - text[i] * h) + text[i + patternLength]) % q;
            if(t < 0){
                t = t + q;
            }
        }


    }    
    
    return 0;
}
// funkcja budujaca tablice przejsc automatu skonczonego
int tablicaPrzejsc(char *pattern, int tab[][128]){
    int i, k = 0, x, patternLength = strlen(pattern);
    for(x = 0; x < 128; x++){
        tab[0][x] = 0;
    }
    tab[0][(int)pattern[0]] = 1;

    for(i = 1; i <= patternLength; i++){
        for(x = 0; x < 128; x++){
            tab[i][x] = tab[k][x];
        }
        tab[i][(int)pattern[i]] = i + 1;
        if(i < patternLength){
            k = tab[k][(int)pattern[i]];
        }
    }
    return 0;
}
// Automat skonczony
int AS(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int tab[patternLength + 1][128];
    tablicaPrzejsc(pattern, tab);
    int i, j = 0;
    for(i = 0; i < textLength; i++){
        j = tab[j][(int)text[i]];
        if(j == patternLength){
            printf("FAIndex: %d ", i - patternLength + 1);
        }
    }

    return 0;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        usage();
        exit(1);
    }
    int patternF = 0;
    patternF = open(argv[1], O_RDONLY);
    if(patternF < 0){
        fputs("Error occured with pattern file! \n", stderr);
        exit(1);
    }
    
    int textF = 0;
    textF = open(argv[2], O_RDONLY);
    if(textF < 0){
        fputs("Error occured with text file! \n", stderr);
        exit(1);
    }

    struct stat patternStat, textStat;
    fstat(patternF, &patternStat);
    fstat(textF, &textStat);
    char *pattern = (char*)malloc(patternStat.st_size);
    char *text = (char*)malloc(textStat.st_size);
    int patternSize = read(patternF, pattern, patternStat.st_size);
    printf("Read %d bytes from pattern file. \n", patternSize);
    int textSize = read(textF, text, textStat.st_size);
    printf("Read %d bytes from text file. \n", textSize);
    close(patternF);
    close(textF);
    struct timespec t0, t1;
    double time_nano, time_sec;
    
    clock_gettime(CLOCK_REALTIME, &t0);
    KMP(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("\nKMP: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
        
    clock_gettime(CLOCK_REALTIME, &t0);
    KMPM(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("\nKMPM: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
    
    clock_gettime(CLOCK_REALTIME, &t0);
    OA(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("\nOA: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
    
    clock_gettime(CLOCK_REALTIME, &t0);
    RK(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("\nRK: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
    
    clock_gettime(CLOCK_REALTIME, &t0);
    AS(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("\nAS: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
        
    return 0;
}
