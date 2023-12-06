//
// Created by EmanueleBar on 05/12/2023.
//

#include "list.h"
#include <stdlib.h>

typedef struct list {
    node_t head;
    node_t tail;
    int num_elem;
}*list_t;

typedef struct node {
    node_t prev;
    node_t next;
    int * sorting_key_int;
    char **sorting_key_string;
    void* Item;
}*node_t;

list_t list_crea(){
    list_t l=(list_t)malloc(sizeof (struct list));
    l->tail=l->head=NULL;
    l->num_elem=0;
    return l;
}

void list_recursive_free(node_t nodo){
    if(nodo->next!=NULL){
        list_recursive_free(nodo->next);
        free(nodo->Item);
        free(nodo);
    }
}

void list_distruggi(list_t list){
    list_recursive_free(list->head);
    free(list);
}

void list_ins_head(list_t list, void* Item){
    if(list->head==NULL && list->tail==NULL){
        list->head=list->tail=node_crea();
    }
    else{
        list->head->prev=node_crea();
        list->head->prev->next=list->head;
        list->head=list->head->prev;
    }
    list->head->Item=Item;
    list->num_elem+=1;

}

void list_ins_tail(list_t list, void* Item){
    if(list->head==NULL && list->tail==NULL){
        list->head=list->tail=node_crea();
    }
    else{
        list->tail->next=node_crea();
        list->tail->next->prev=list->tail;
        list->tail=list->tail->next;
    }
    list->tail->Item=Item;
    list->num_elem+=1;
}


int list_get_num_elem(list_t list){
    return list->num_elem;
}

node_t node_crea(){
    node_t nodo=(node_t) malloc(sizeof (struct node));
    nodo->next=NULL;
    nodo->prev=NULL;
    nodo->Item=NULL;
    nodo->sorting_key_int=NULL;
    nodo->sorting_key_string=NULL;
    return nodo;
}

node_t list_get_head(list_t list){
    return list->head;
}

node_t node_get_next(node_t node){
    return node->next;
}

node_t node_get_prev(node_t node){
    return node->prev;
}

void * node_get_val(node_t node){
    return node->Item;
}

void list_pop_node(node_t nodo);