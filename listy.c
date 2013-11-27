#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element{
	int key;
	struct Element *next;
//	struct Element *prev;
}* lis;

// adds given element to the linked list
void add(lis list, int x){
//	lis tmp = (lis)malloc(sizeof(struct Element));
//	lis tmp2 = list;
//	tmp->key = x;
//	tmp->next = list;
//	list = tmp2;
//	list->next = tmp;

}
// removes given element from the linked list
void removel(lis list, int x){
	lis tmp = list->next;
	while(tmp != NULL){
		if(tmp->key == x){
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}

}
// searches the linked list for given element
lis search();
//deletes whole list
lis delete();
// prints whole list on screen
void llprint(lis list){
	lis tmp = list;
	while(tmp != NULL){
		printf("%i ", tmp->key);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(void){
	lis lista = NULL;
	add(lista, 5);	
	add(lista, 11);
	llprint(lista);
	
	return 0;
}
