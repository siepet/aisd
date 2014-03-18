#include <stdio.h>
struct Node{
	char c;	// character
	int f;	// number of occurrences
	struct Node *next;
};
struct KK{
	struct Node *s;
	int size;
};
// does all the huffmaning
int Min(struct KK *q){
	int min = 65536123;
	int i;
	struct Node *tmp;
	
	for(i; i < q->size; i++){
		tmp = q->s;
		min = (min > tmp->f) ? tmp->f : min;
	}

	return min;
}

int Huffy(char *slowo){
	int i;
	//for(i = 2;  

	return 0; // Min(Q);
}

int czytaj(){
	FILE *f = 	

}
int main(void){
		

	return 0;
	
}
