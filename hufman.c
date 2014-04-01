#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int d;
    int f;
    char c;
    char code;
};
int ile(struct Node *heap[]){
    int i, p = 0;
    for(i = 0; i < 100; i++){
        if(heap[i]->f > 0){
            p++;
        }
    }
    return p;
}
void add(struct Node *heap[], struct Node *e, int boolean){
    int i;
    if(boolean == 0){
        for(i = 0; i <= 26; i++){
            if(heap[i]->f == -1){
                heap[i] = e;
                return;
            } else if(heap[i]->c == e->c) {
                heap[i]->f++;
                return;
            }
        }
    } else {
        for(i = 27; i < 100; i++){
            if(heap[i]->f == -1){
                heap[i] = e;
                return;
            }
        }
    }
}
void init(struct Node *heap[]){
    FILE *f = fopen("plika.txt", "r");
    char tmp;
    int i;
    for(i = 0; i < 100; i++){
        heap[i] = malloc(sizeof(struct Node));
        heap[i]->c = '1';
        heap[i]->f = -1;

    }
    do {
        tmp = fgetc(f);
        if(tmp != 10 && tmp != 32 && tmp != -1){
            struct Node *e = malloc(sizeof(struct Node));
            e->c = tmp;
            e->f = 1;
            e->d = 0;
            e->left = e->right = e->parent = NULL;
            add(heap, e, 0);
        }
    }while(tmp != EOF);

}
struct Node *min(struct Node *heap[]){
    int i;
    int p;
    int min = INT_MAX;
    for(i = 0; i < 100; i++){
        if(heap[i]->d == 0){
            if(heap[i]->f != -1){
                 if(heap[i]->f < min){
                    min = heap[i]->f;
                    p = i;
                }
            }
        }
    }
    if(min == INT_MAX){
        return heap[0];
    } else {
        heap[p]->d = 1;
        return heap[p];
    }
}
void print_(struct Node *heap[]);
struct Node *huffman(struct Node *heap[]){
    int i;
    struct Node *x;
    struct Node *y;
    int ko = ile(heap);
    for(i = 27; i < 27 + ko - 1; i++){
        x = min(heap);
        printf("x->f == %d\t\t\t", x->f);
        y = min(heap);
        printf("y->f == %d \n", y->f);
        struct Node *z = malloc(sizeof(struct Node));
        x->code = '0';
        y->code = '1';
        z->left = x;
        x->parent = z;
        z->right = y;
        y->parent = z;
        z->f = x->f + y->f;
        z->c = 'z';
        printf("\t\tz->f == %d \n", z->f);
        add(heap, z, 1);
    }
    return min(heap);
}
void print_(struct Node *heap[]){
    int i;
    for(i = 0; i < 100; i++){
        if(heap[i]->f > 0){
            printf("%d. %c: %d\n", i, heap[i]->c, heap[i]->f);
        }
    }
}
void print_tree(struct Node *n, char c[], int lenc)
{
  if(!(n->left)){
    printf("%c: ", n->c);
    int i;
    for(i = 0; i < lenc; i++){
        printf("%c", c[i]);
    }
    printf("\n");
  } else {
    c[lenc] = '0';
    print_tree(n->left, c, lenc + 1);
    c[lenc] = '1';
    print_tree(n->right, c, lenc + 1);
  }
}
int main(){
    struct Node *heap[100], *tmp;
    char arr[100];
    init(heap);
    print_(heap);
    tmp = huffman(heap);
    print_(heap);
    print_tree(tmp, arr, 0);
    return 0;

}
