//
// Created by EmanueleBar on 05/12/2023.
//
/*
 * TIPI
 *   struct lista {head, tail, n_elem}
 *   struct nodo {*precedente, *successivo, chiave_sort, Item}
 * FUNZIONI
 *   list_crea
 *   list_distruggi
 *   list_ins_head
 *   list_ins_tail
 *   list_get_nodo
 *   list_pop_nodo
 *   list_get_n_elem
 *   nodo_crea
 *   nodo_distruggi
 *   nodo_next
 *   nodo_prev
 *   nodo_get_val
 */

#ifndef LIST_H
#define LIST_H
typedef struct list *list_t;
typedef struct node *node_t;

//crea dinamicamente un contenitore lista con head, tail e n_elem
list_t list_crea();

//distrugge una lista
void list_distruggi(list_t list);

//inserisce un valore passato tramite puntatore in testa alla lista
void list_ins_head(list_t list, void* Item);

//inserisce un valore passato tramite puntatore in coda alla lista
void list_ins_tail(list_t list, void* Item);

//restituisce il numero di elementi salvati in una lista
int list_get_num_elem(list_t list);

//crea un nodo
node_t node_crea();

//restituisce il puntatore alla testa di una lista
node_t list_get_head(list_t list);

//passato puntatore a un nodo restituisce quello che lo segue
node_t node_get_next(node_t node);

//passato puntatore a un nodo restituisce quello che lo precede
node_t node_get_prev(node_t node);

//restituisce il valore puntato da un nodo, è necessario cast del puntatore
void * node_get_val(node_t node);

void list_pop_node(node_t nodo);



#endif //LIST_H
