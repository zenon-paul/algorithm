#include"list.h"
void il(d_list* x) {
	x->head = NULL;
	x->elm = 0;//elmは個数
}
struct list_node* get_elm_addres(d_list* x, int index) {
	if (x->head == NULL)
	{
		return NULL;
	}
	index = index % x->elm;
	struct list_node* rest = x->head;
	for (int i = 0; i < index; i++)
	{
		rest = rest->next;
	}
	return rest;
}
void substitute(d_list* x, int index, int n1, int n2, int n3, char* s) {
	if (x->head == NULL)
	{
		return;
	}
	index = index % x->elm;
	struct list_node* rest = get_elm_addres(x, index);
	rest->num1 = n1;
	rest->num2 = n2;
	rest->num3 = n3;
	rest->sent = s;
}
int disp(d_list* x);
int add_substitute(d_list* x, int index, int n1, int n2, int n3, char* s) {
	struct list_node* added;
	added = (struct list_node*)malloc(sizeof(struct list_node));
	if (x->head == NULL)
	{
		x->head = added;
		added->next = added;
		added->prev = added;
		x->elm++;
		substitute(x, 0, n1, n2, n3, s);
		return 1;
	}
	else if (index == 0)
	{
		struct list_node* restn = x->head;
		struct list_node* restp = restn->prev;
		added->next = restn;
		restn->prev = added;
		restp->next = added;
		added->prev = restp;
		x->head = added;
		x->elm++;//!
		substitute(x, 0, n1, n2, n3, s);
		return 1;
	}
	else if (index % x->elm == 0) {
		int access = index % x->elm;
		struct list_node* restn = get_elm_addres(x, access);
		printf("@@%d\n", restn->num1);
		struct list_node* restp = restn->prev;
		printf("@@%d\n", restp->num1);
		added->next = restn;
		restn->prev = added;
		restp->next = added;
		added->prev = restp;
		x->elm++;//!
		substitute(x, index, n1, n2, n3, s);
		return 1;
	}
	else
	{
		index = index % x->elm;
		struct list_node* restn = get_elm_addres(x, index);
		struct list_node* restp = restn->prev;
		added->next = restn;
		restn->prev = added;
		restp->next = added;
		added->prev = restp;
		x->elm++;//!
		substitute(x, index, n1, n2, n3, s);
		return 1;
	}
}
int dlt(d_list* x, int index) {
	if (x->head == NULL)
	{
		return 0;
	}
	else if ((index % x->elm) == 0)
	{
		struct list_node* rest = get_elm_addres(x, index);
		struct list_node* restn = rest->next;
		struct list_node* restp = rest->prev;
		if (rest == restn)
		{
			x->head = NULL;
			free(rest);
			x->elm--;
			return 1;
		}
		x->head = restn;
		restn->prev = restp;
		restp->next = restn;
		free(rest);
		x->elm--;
		return 1;
	}
	else
	{
		index = index % x->elm;
		struct list_node* rest = get_elm_addres(x, index);
		struct list_node* restn = rest->next;
		struct list_node* restp = rest->prev;
		restn->prev = restp;
		restp->next = restn;
		free(rest);
		x->elm--;
		return 1;
	}
}
int disp(d_list* x) {
	if (x->head == NULL)
	{
		return 0;
	}
	else
	{
		struct list_node* rest = x->head;
		do
		{
			printf("%d ", rest->num1);
			rest = rest->next;
		} while (rest != x->head);
		printf("\n");
		return 1;
	}

}
