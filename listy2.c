#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element{
	int key;
	struct Element *next;
//	struct Element *prev;
} ll;

// adds given element to the linked list
void add(ll list, int x){
	ll tmp = (ll)malloc(sizeof(struct Element));
	ll tmp2 = list;
	tmp->key = x;
	tmp->next = list;
	list = tmp2;
	list->next = tmp;


}
// removes given element from the linked list
void removel(ll list, int x){
	ll tmp = list->next;
	while(tmp != NULL){
		if(tmp->key == x){
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}

}
// searches the linked list for given element
ll search();
//deletes whole list
ll delete();
// prints whole list on screen
void llprint(ll list){
	ll tmp = list;
	while(tmp != NULL){
		printf("%i ", tmp->key);
		tmp = tmp->next;
	}
}

int main(void){
	ll *lista = NULL;
	add(lista, 5);	


	return 0;
}
