#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct A{
	int number;
	char *string;
};

struct A table[5]; 
int main(void){
	memset(table, 0, sizeof(struct A) * 5);	
	printf("%d %s \n", table[0].number, table[0].string);
	
	printf("%d %s \n", table[1].number, table[1].string);
	

	return 0;
}
