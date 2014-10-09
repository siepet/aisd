//DFS przeszukiwanie grafu w glab
#include <stdio.h>
#include <stdlib.h>

#define bialy 0
#define szary 1
#define czarny 2
#define MAX 6

typedef struct lista{
        int key;
        struct lista* next;
        }lista;

typedef struct wierzcholek{
        int kolor;
        int odleglosc;
        int poprzednik;
        int czas;
        lista* head;
        }wierzcholek;

void DodajDoListy(lista **head, int element){
     lista * nowy;
     lista * tmp;
     nowy=(lista *)malloc(sizeof(lista));
     nowy->next=NULL;
     nowy->key=element;

     if((*head)==NULL)
     *head=nowy;
     else{
          tmp=*head;
          while(tmp->next!=NULL){ tmp=tmp->next;}
          tmp->next=nowy;
          }
     }

void Graf(wierzcholek* tab, int x, int y){
     DodajDoListy(&tab[x].head,y);
     }

void wypisz(lista **head)
{
     lista* tmp=*head;
     while(tmp!=NULL){
        printf("-> %d ", tmp->key);
        tmp=tmp->next;
        }
     printf("\n");
}

int time=0;

void DFSVisit(wierzcholek* tab, int numer){
     tab[numer].kolor=szary;
     tab[numer].odleglosc=++time;
     lista* tmp=tab[numer].head;
     while(tmp){
           if(tab[tmp->key].kolor==bialy){
              tab[tmp->key].poprzednik=numer;
              DFSVisit(tab,tmp->key);
              }
           tmp=tmp->next;
           }
     tab[numer].kolor==czarny;
     tab[numer].czas=++time;
     }

void DFS(wierzcholek* tab){
     int i;
     for(i=0;i<MAX;i++){
         tab[i].kolor=bialy;
         tab[i].poprzednik=0;
         }
     for(i=0;i<MAX;i++){
         if(tab[i].kolor==bialy){
            DFSVisit(tab,i);
            }
         }
     }

int main(){
    wierzcholek tab[MAX];
    int i;
    for(i=0;i<MAX;i++)
    {
         tab[i].head=NULL;
    }

    //przykladowy graf
    Graf(tab,0,1);
    Graf(tab,0,3);
    Graf(tab,1,4);
    Graf(tab,2,4);
    Graf(tab,2,5);
    Graf(tab,3,1);
    Graf(tab,4,3);
    Graf(tab,5,5);

    printf("Lista sasiedztwa:\n");
    for(i=0;i<MAX;i++){
        printf("%d ", i);
        wypisz(&tab[i].head);
    }
    DFS(tab);

    for(i=0;i<MAX;i++){
    printf("\nWierzcholek: %d  ", i);
    printf(" %d /", tab[i].odleglosc);
    printf(" %d  ", tab[i].czas);
} printf("\n");
  system("PAUSE");
  return 0;
}
