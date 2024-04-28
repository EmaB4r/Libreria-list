//
// Created by EmanueleBar on 05/12/2023.
//


#ifndef LIST_H
#define LIST_H
typedef struct list *list_t;
typedef struct node *node_t;

//creates a dynamic struct list, having headpointer, tailpointer and number of elements
list_t list_init();

//frees a list
void list_free(list_t list);

//inserts a given item pointer in head's place
void list_ins_head(list_t list, void* Item);

//inserts a given item pointer in tail's place
void list_ins_tail(list_t list, void* Item);

//returns list's number of nodes
int list_get_num_elem(list_t list);

//creates a dynamic struc node
node_t node_init();

//returns list's head's pointer
node_t list_get_head(list_t list);

//returns
node_t node_get_next(node_t node);

//returns
node_t node_get_prev(node_t node);

//returns a node's value
void * node_get_val(node_t node);

//prints to screen the whole list's contents by using a user defined printing function
//
// if the item type saved in list is "int a"
// print_fun should be defined as:
// void a_print_fun(int* val){printf("%d", *val);}
//
// and then in main be called as:
// list_print(list_t l, a_print_fun);
//
void list_print(list_t l, void (print_fun)(void *));

//sorts list by using a user defined cmp function if(a > b)
//
// if the item type saved in list is "int a"
// cmp should be defined as:
// int a_gt_b(int* a, int*b){return *a>*b;}
//
// and then in main be called as:
// list_insertion_sort(list_t l, a_gt_b);
//
void list_insertion_sort(list_t l, int(*item_gt)(void*, void*));

#endif //LIST_H
