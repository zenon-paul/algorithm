#include<stdlib.h>
void idp(d_deque* x){
	x->body = (d_list*)malloc(sizeof(d_list*));
	il(x->body);
}
int d_put_tail(d_deque* x,int y){
	add_substitute(x->body,(x->body)->elm - 1,y,0,0,0);
	return 1;
}
int d_get_tail(d_deque* x,int* y){
	struct list_node* rest = get_elm_addres(x->body,(x->body)->elm-1);
	if(rest !=NULL){
	*y = rest->num1;
	dlt(x->body,0);
	return 1;
	}
	else
	{
		return 0;
	}
}
int d_put_head(d_deque* x,int y){
	add_substitute(x->body,0,y,0,0,0);
	return 1;
}
int d_get_head(d_deque* x,int* y){
	struct list_node* rest = get_elm_addres(x->body,0);
	if(rest != NULL){
	*y = rest->num1;
	dlt(x->body,0);
	return 1;
	}
	else
	{
		return 0;
	}
}
