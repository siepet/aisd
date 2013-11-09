#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
//	int n = (int)argv[1][0] - 47;
	int i; // iterator
	FILE *input = fopen("input_k.txt", "w+");
	int x;
int	n = 100000;
	srand(time(NULL));
	for(i = 0; i < n; i++){
		x = rand() % 2;
		fprintf(input, "%d ", x);
	}
	fprintf(input, "\n");
//	fclose(input);
	
	return 0;

}
