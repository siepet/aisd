#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *p;
    int rank;
};

struct Node *MakeSet(int k){
    struct Node *x = malloc(sizeof(struct Node));
    x->key = k;
    x->p = x;
    x->rank = 0;
    return x;
}
struct Node *FindSet(struct Node *x){
    if (x != x->p){
        return FindSet(x->p);
    } else {
        return x;
    }
}

int Union(struct Node *x, struct Node *y){
    if(x->rank > y->rank){
        y->p = x;
    } else {
        x->p = y;
        if(x->rank == y->rank){
            y->rank++;
        }
    }
    return 0;
}
int S-C(struct Node *x, struct Node *y){
    if(FindSet(x) == FindSet(y)){
        return 1;
    } else {
        return 0;
    }
}
int main(){
    struct Node *tab[10];
    tab[0] = MakeSet(5);
    tab[1] = MakeSet(1);
    printf("%i ", tab[0]->rank);
    Union(FindSet(tab[0]), FindSet(tab[1]));
    printf("%i ", tab[0]->rank);
    printf("%i ", tab[1]->rank);

    return 0;
}
