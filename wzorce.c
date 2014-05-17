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

// Knuth Morris Pratt
int KMP(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(pattern);

    
    return 0;
}

// Knuth Morris Pratt modified (assuming '?' as any character)
int KMPM(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(pattern);

    return 0;
}

// oczywisty algorytm
int OA(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int i, s = 0, j;
    for(i = 0; i < textLength - patternLength; i++){
        for(j = 0; j < patternLength; j++){
            if(text[i + j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            printf("Index: %d \n", i);
        }
    }
    return 0;
}
// Rabin-Karp
int RK(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);

    return 0;
}

// Automat skonczony
int AS(char *pattern, char *text){
    int patternLength = strlen(pattern);
    int textLength = strlen(text);

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
    int textSize = read(textF, text, textStat.st_size);
    
    struct timespec t0, t1;
    double time_nano, time_sec;
    
    clock_gettime(CLOCK_REALTIME, &t0);
    KMP(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("KMP: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
        
    clock_gettime(CLOCK_REALTIME, &t0);
    KMPM(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("KMPM: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
    
    clock_gettime(CLOCK_REALTIME, &t0);
    OA(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("OA: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
    
    clock_gettime(CLOCK_REALTIME, &t0);
    RK(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("RK: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
    
    clock_gettime(CLOCK_REALTIME, &t0);
    AS(pattern, text);
    clock_gettime(CLOCK_REALTIME, &t1);
    time_sec = t1.tv_sec - t0.tv_sec;
    time_nano = t1.tv_nsec - t0.tv_nsec;
    printf("AS: Time: %lf nanoseconds, %lf seconds \n", time_nano, time_sec);
        
    return 0;
}
