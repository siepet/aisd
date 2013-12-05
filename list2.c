#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
};

void add(struct Node **head, int number){
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp->value = number;
    if(*head != NULL){
        (*head)->prev = tmp;
    }
    tmp->prev = NULL;
    tmp->next = *head;

    *head = tmp;

}
int exist(struct Node *head, int number){
    struct Node *tmp = head;
    while(tmp != NULL){
        if(tmp->value == number){
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;

}
struct Node* getTail(struct Node **head){
    struct Node *tmp = *head;
    struct Node *tmp2;
    while(tmp != NULL){
        tmp2 = tmp;
        tmp = tmp->next;
    }

    return tmp2;
}
void delete_n(struct Node **head, int number){
    struct Node *tmp;
    struct Node *tmp_p;
    tmp = *head;

    if(exist(tmp, number)){
        while(tmp != NULL && tmp->value != number){
            tmp_p = tmp;
            tmp = tmp->next;
        }
        if(tmp == *head){
            *head = (*head)->next;
            (*head)->prev = NULL;
        } else {
            tmp_p->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        if(tmp != NULL){
            free(tmp);
        }
    } else {
        printf("Element %i was not found on the list. \n", number);
    }

}
void delete_l(struct Node **head);
void merge(struct Node **one, struct Node **two){
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp = *one;
    if(*one == NULL || *two == NULL){
        printf("Empty list found. \n");
    } else {
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        (*two)->prev = tmp;
        tmp->next = *two;
    }
	*two = NULL;
}

void search(struct Node **head, int number){
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp = *head;
    int count = 0;
    if(tmp == NULL){
        printf("Cannot search the empty list! \n");
    } else {
        while(tmp != NULL){
            if(tmp->value == number){
                count++;
            }
            tmp = tmp->next;
        }
        if(count == 0){
            printf("Element %i was not found on the list %p.", number, &head);
        } else {
            printf("\nElement->value: %i found %i time(s).\n", number, count);
        }
    }
}
void showH(struct Node **head){
    struct Node *tmp;
    tmp = *head;
    if(tmp == NULL){
        printf("List is empty!\n");
    } else {
        printf("List elements are: \n");
        while(tmp != NULL){
            printf("%i \n",tmp->value);
            tmp = tmp->next;
        }
    }


}
void showT(struct Node **head){
    struct Node *tmp;

        tmp = getTail(head);
        if(tmp == NULL || *head == NULL){
            printf("List is empty!\n");
        } else {
            printf("List elements are: \n");
            while(tmp != NULL){
                printf("%i \n", tmp->value);
                tmp = tmp->prev;
            }
        }

}
void delete_l(struct Node **head){
    struct Node *tmp;
    tmp = *head;
    struct Node *t;
    while(tmp != NULL){
        t = tmp->next;
        free(tmp);
        tmp = t;
    }
    *head = NULL;
    printf("Whole linked list deleted and memory free'd. \n");
}

int main(void){
    struct Node *head = NULL;           // initialize linked list
    struct Node *tail = NULL;
    showH(&head);
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);

    add(&tail, 4);
    add(&tail, 5);
    merge(&head, &tail);
    showH(&head);
    showH(&tail);
    search(&head, 4);
    delete_n(&head, 7);
    showH(&head);
    delete_l(&head);
    showH(&head);
    showT(&head);
    search(&head, 0);
    printf("\nListBackwards: \n");
    showT(&head);
    printf("\n\n");

    return 0;
}

