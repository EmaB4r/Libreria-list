#include "list.h"
#include <stdio.h>

typedef struct Item
{
    int a, b, c
}Item_t;



void print_item(Item_t * i){
    printf("a: %d   b: %d   c: %d\n", i->a, i->b, i->c);
}

int item_a_gt(Item_t * i1, Item_t * i2){
    return i1->a>i2->a;
}

int item_b_gt(Item_t * i1, Item_t * i2){
    return i1->b>i2->b;
}

int item_c_gt(Item_t * i1, Item_t * i2){
    return i1->c>i2->c;
}

void fill_item(Item_t* i, int a, int b, int c){
    i->a=a;
    i->b=b;
    i->c=c;
}

int main(int argc, char const *argv[]){
    Item_t obj1, obj2, obj3, obj4, obj5, obj6, obj7;
    fill_item(&obj1, 1,3,7);
    fill_item(&obj2, 2,2,6);
    fill_item(&obj3, 3,5,5);
    fill_item(&obj4, 4,7,4);
    fill_item(&obj5, 5,1,3);
    fill_item(&obj6, 6,4,2);
    fill_item(&obj7, 7,6,1);

    list_t lista=list_init();
    list_ins_head(lista, &obj1);
    list_ins_head(lista, &obj2);
    list_ins_head(lista, &obj3);
    list_ins_head(lista, &obj4);
    list_ins_head(lista, &obj5);
    list_ins_head(lista, &obj6);
    list_ins_head(lista, &obj7);

    list_print(lista, print_item);
    printf("\n");

    list_insertion_sort(lista, item_a_gt);
    list_print(lista, print_item);
    printf("\n");

    list_insertion_sort(lista, item_b_gt);
    list_print(lista, print_item);
    printf("\n");

    list_insertion_sort(lista, item_c_gt);
    list_print(lista, print_item);
    printf("\n");

    
    return 0;
}
