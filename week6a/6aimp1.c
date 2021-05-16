#include "6a.h"
#include<ctype.h>

static Node* create_Node(int data, Node* link)
{
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
	ptr_List->head=NULL;
	ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data) 
{
	Node* temp=NULL;
	temp=create_Node(data,temp);
	temp->link=ptr_List->head;
	ptr_List->head=temp;
	ptr_List->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr) 
{
	return(Node_ptr->data);
}

void List_delete_front(List* ptr_List)
{
	Node* temp;
	temp=ptr_List->head;
	if(temp==NULL)
	{
		return;
	}
	else
	{
		ptr_List->head=temp->link;
		ptr_List->number_of_Nodes--;
		free(temp);
	}
}

void List_destroy(List* ptr_List) 
{
	Node* p;
	p=ptr_List->head;
	Node* q=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->link;
		free(q);
	}
	free(ptr_List);
}

void stack_initialize(Stack *ptr_stack) 
{
	ptr_stack->ptr_List=(List*)malloc(sizeof(List));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack) 
{
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	if(ptr_stack->ptr_List->head==NULL)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

const int stack_peek(Stack *ptr_stack)
{
	return(Node_get_data(ptr_stack->ptr_List->head));
}

void stack_destroy(Stack *ptr_stack) 
{
	List_destroy(ptr_stack->ptr_List);
	free(ptr_stack);
}

int postfix_eval(const char* expression) 
{
	Stack* stk;
	stk=(Stack*)malloc(sizeof(Stack));
	stack_initialize(stk);

	for(int i=0; expression[i]; i++)
	{
		if(isdigit(expression[i]))
		{
			stack_push(stk, expression[i] - '0');
		}
		else
		{
			int x=stack_peek(stk);
			stack_pop(stk);
			int y=stack_peek(stk);
			stack_pop(stk);
			switch(expression[i])
			{
				case '+':
					stack_push(stk, y+x);
					break;
				case '-':
					stack_push(stk, y-x);
					break;
				case '*':
					stack_push(stk, y*x);
					break;
				case '/':
					stack_push(stk, y/x);
					break;
			}
		}
	}
	int result=stack_peek(stk);
	stack_pop(stk);
	stack_destroy(stk);
	return(result);
}