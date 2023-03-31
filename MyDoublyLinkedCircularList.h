#ifndef INCLUDE_LIST
#define INCLUDE_LIST
#include<stdio.h>
#include<stdlib.h>
struct list_node {
    int num1;
    int num2;
    int num3;
    char* sent;
    struct list_node* next;
    struct list_node* prev;
};
typedef struct list_data {
    int elm;
    struct list_node* head;
}d_list;
void il(d_list* x);
struct list_node* get_elm_addres(d_list* x, int index);
int add_substitute(d_list* x, int index, int n1, int n2, int n3, char* s);
int dlt(d_list* x, int index);
int disp(d_list* x);
#endif
