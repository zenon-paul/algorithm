#include <stdio.h>
#include <stdlib.h>
struct d_node{
	int num1;
	int num2;
	int num3;
	char* s;
	struct d_node* right;
	struct d_node* left;
};
struct d_node* root = NULL;
struct d_node* search(int num){
	if(root == NULL)
	{
		return NULL;
	}
	struct d_node* current = root;
	while(current)
	{
		if(current->num1 == num)
		{
			return current;
		}
		else if(num < current->num1)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return NULL;
}
int add(int n1,int n2,int n3,char* st){
	if(root == NULL)
	{
		root = (struct d_node*)malloc(sizeof(struct d_node));
		root->num1 = n1;
		root->num2 = n2;
		root->num3 = n3;
		root->s = st;
		root->left = NULL;
		root->right = NULL;
		return 1;
	}
	struct d_node* current = root;
	while(current != NULL)
	{
		if(current->num1 == n1)
		{
			return 0;
		}
		else if(n1 < current->num1)
		{
			if(current->left)
			{
				current = current->left;
			}
			else
			{
				current->left = (struct d_node*)malloc(sizeof(struct d_node));
				(current->left)->num1 = n1;
				(current->left)->num2 = n2;
				(current->left)->num3 = n3;
				(current->left)->s = st;
				(current->left)->left = NULL;
				(current->left)->right = NULL;
				return 1;
			}
		}
		else
		{
			if(current->right)
			{
				current = current->right;
			}
			else
			{
				current->right = (struct d_node*)malloc(sizeof(struct d_node));
				(current->right)->num1 = n1;
				(current->right)->num2 = n2;
				(current->right)->num3 = n3;
				(current->right)->s = st;
				(current->right)->left = NULL;
				(current->right)->right = NULL;
				return 1;
			}
		}
	}
	return 0;
}
void deletnochild(struct d_node* current,struct d_node* parent){
	if(parent != NULL)
	{
		if(parent->left == current)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
		free(current);
	}
	else
	{
		free(current);
		root = NULL;
	}
}
void deleteonechild(struct d_node* current,struct d_node* child){
	current->num1 = child->num1;
	current->num2 = child->num2;
	current->num3 = child->num3;
	current->s = child->s;
	free(child);
}
void delettwochild(struct d_node* current,struct d_node* child){
	struct d_node* max;
	struct d_node* maxparent;
	max = current->left;
	maxparent = current;
	while(current->right != NULL)
	{
		maxparent = max;
		max = max->right;
	}
	current->num1 = max->num1;
	current->num2 = max->num2;
	current->num3 = max->num3;
	current->s = max->s;
	if(max->left == NULL)
	{
		deletnochild(max,maxparent);
	}
	else
	{
		deleteonechild(max,maxparent);
	}
}
int delete(int num){
	if(root == NULL)
	{
		return 0;
	}
	struct d_node* current = root;
	struct d_node* parent = NULL;
	while(current)
	{
		if(current->num1 == num)
		{
			break;
		}
		parent = root;
		if(num < current->num1)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	if(current == NULL)
	{
		return 0;
	}
	else
	{
		
	}
	return 0;
}
void disp(struct d_node* seed,int depth){//右は帰りがけ左は行きがけ
	if(seed != NULL)
	{
		if(seed->right != NULL)
		{
			disp(seed->right,depth+1);
		}
		for(int i = 0;i < depth;i++)
		{
			printf(" ");
		}
		printf("-[%d\n",seed->num1);
		if(seed->left != NULL)
		{
			disp(seed->left,depth+1);
		}
	}
	depth++;
}
int main(){
	struct d_node* x;
	add(50,0,0,"a");
	add(100,0,0,"a");
	add(100,0,0,"b");
	add(20,0,0,"a");
	add(30,0,0,"a");
	add(10,0,0,"a");
	add(0,0,0,"a");
	//disp(root,0);
	delete(20);
	disp(root,0);
	x = search(100);
	//printf("%d\n",x->num1);
}
