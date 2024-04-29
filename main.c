#include "list.h"
#include <stdio.h>
#include <string.h>

typedef struct oggetto{
    int a;
    int b;
    char c[50];
}item_t;

void stampa_item(item_t * i){
    i=(item_t*)i;
    printf("Item: %s   a: %d   b: %d\n", i->c, i->a, i->b);
}

int itemgreaterA(item_t* a, item_t* b){
    return a->a>b->a;
}

int itemgreaterB(item_t* a, item_t* b){
    return a->b>b->b;
}

int itemgreaterName(item_t* a, item_t* b){
    int r= strcmp(a->c, b->c);
    if(r==1)
        return 1;
    return 0;
}

int main(){
    list_t lista= list_init();
    item_t ogg1, ogg2, ogg3, ogg4, ogg5;
    
    ogg1.a=1;
    ogg1.b=1;
    strcpy(ogg1.c, "ogg1");

    ogg2.a=1;
    ogg2.b=2;
    strcpy(ogg2.c, "ogg2");

    ogg3.a=2;
    ogg3.b=4;
    strcpy(ogg3.c, "ogg3");

    ogg4.a=5;
    ogg4.b=3;
    strcpy(ogg4.c, "ogg4");

    ogg5.a=9;
    ogg5.b=2;
    strcpy(ogg5.c, "ogg5");

    list_ins_head(lista, &ogg1);
    list_ins_head(lista, &ogg2);
    list_ins_head(lista, &ogg3);
    list_ins_head(lista, &ogg4);
    list_ins_head(lista, &ogg5);

    list_print(lista, stampa_item);
    printf("\n");

    list_insertion_sort(lista, itemgreaterA);
    list_print(lista, stampa_item);
    printf("\n");

    list_insertion_sort(lista, itemgreaterB);
    list_print(lista, stampa_item);
    printf("\n");

    list_insertion_sort(lista, itemgreaterName);
    list_print(lista, stampa_item);
    printf("\n");
    
    return 0;
}
