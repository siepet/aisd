#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	const char *filename = "plik";
	FILE *f = fopen(filename, "w");
	char x;
	
	if(argc < 2){
		printf("Not enough parameters! 2 needed \n");
		printf("Usage: ./slowoGen WordNumber wordLength\n");
		exit(-1);
	}
	int length = atoi(argv[1]);	// strings length
	int h = atoi(argv[2]);		// how many words to generate
	int i, j;			// iterators
	srand(time(NULL));
	for(i = 0; i < h; i++){
		for(j = 0; j < length; j++){
			x = rand() % (122 - 97 + 1) + 97;
			fprintf(f, "%c", x);
		}
		fprintf(f, "\n");
	}
	fclose(f);
printf("%i words of length %i saved to file %s \n", h, length, filename);
printf("Word list from file %s: \n", filename);
	char cmd[50];

	i = sprintf(cmd, "cat %s", filename);
	system(cmd);
	return 0;
}
