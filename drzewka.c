#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int amount;
};

int exist(struct Node *tree, int key){
    struct Node *tmp = tree;
    while(tmp != NULL && tmp->value != key){
        if(key < tmp->value){
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }

    }
    if(tmp == NULL){
        return 0;
    } else {
        return 1;
    }
}

struct Node* SZUKAJ(struct Node *tree, int key){
    struct Node *tmp = tree;
    while(tmp != NULL && tmp->value != key){
        if(key < tmp->value){
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }

    }
    return tmp;
}

int WSTAW(struct Node *tree, int key){

    struct Node *insertion = malloc(sizeof(struct Node));
    struct Node *tmp = tree;
    struct Node *parent;

    insertion->value = key;
    insertion->left = NULL;
    insertion->right = NULL;
    insertion->parent = NULL;
    insertion->amount = 1;


    if(exist(tree, key) == 1){
        struct Node *s = SZUKAJ(tree, key);
        s->amount++;
        return 1;
    } else {

        while(tmp != NULL){
            parent = tmp;
            if(key < tmp->value){
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
        insertion->parent = parent;

        if(parent == NULL){
            tree = insertion;
        } else {
            if(insertion->value < parent->value){
                parent->left = insertion;
            } else {
                parent->right = insertion;
            }
        }

        return 1;
    }
}



struct Node* MINIMUM(struct Node *tree){
    struct Node* tmp = tree;
    while(tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp;
}

int USUN(struct Node *tree, int key){

    struct Node* zet = SZUKAJ(tree, key);
    struct Node* why = malloc(sizeof(struct Node));
    struct Node* iks = malloc(sizeof(struct Node));

    if(zet->amount > 1){
        zet->amount--;
        return 1;
    } else {

        if(zet->left == NULL || zet->right == NULL){
            why = zet;
        } else {
            why = MINIMUM(zet->right);
        }
        if(why->left != NULL){
            iks = why->left;
        } else {
            iks = why->right;
        }
        if(iks != NULL){
            iks->parent = why->parent;
        }
        if(why->parent == NULL){
            tree = iks;
        } else {
            if(why == why->parent->left ){
                why->parent->left = iks;
            } else {
                why->parent->right = iks;
            }
        }
        if(why != zet){
            zet->value = why->value;
        }

        return 1;
    }
}

void DRUKUJ(struct Node *tree){
    struct Node *tmp = tree;
    if(tmp != NULL){
        DRUKUJ(tmp->left);
        printf("int: %d amount: %d \n", tmp->value, tmp->amount);
        DRUKUJ(tmp->right);
    }

}

int main(void){
    struct Node *root = malloc(sizeof(struct Node));
    root->parent = NULL;
    root->left   = NULL;
    root->right  = NULL;
    root->amount = 1;

    root->value = 10;



    WSTAW(root, 5);
    WSTAW(root, 1);
    WSTAW(root, 2);
    WSTAW(root, 3);
    WSTAW(root, 3);
    WSTAW(root, 10);
    DRUKUJ(root);
    USUN(root, 10);
    DRUKUJ(root);

    return 0;
}
