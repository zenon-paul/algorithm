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
#endif
