#include "6a.h"
static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}
void List_initialize(List* ptr_List) 
{
	ptr_list->head = NULL;
	ptr_list->number_of_Nodes = 0;
}
void List_insert_front(List* ptr_List, int data) 
{
	Node *newnode = create_Node(data, ptr_list->head);
	ptr_list->head = newnode;
	ptr_list->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr) 
{
	if (Node_ptr == NULL)
		return -1;
	return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
	if (ptr_list->head == NULL)
		return;
	Node *temp;
	temp = ptr_list->head;
	if (ptr_list->head->link == NULL)
	{
		free(temp);
		ptr_list->head = NULL;
		ptr_list->number_of_Nodes--;
		return;
	}
	ptr_list->head = temp->link;
	free(temp);
	ptr_list->number_of_Nodes--;
	return;	
}

void List_destroy(List* ptr_List) 
{
	if (ptr_list->head == NULL)
		return;
	Node *temp, *tempone;
	temp = ptr_list->head;
	while (temp != NULL)
	{
		tempone = temp;
		temp = temp->link;
		free(tempone);
	}
	ptr_list->head = NULL;
}


void stack_initialize(Stack *ptr_stack) 
{
	ptr_Stack->ptr_list = (List*)malloc(sizeof(List));
	list_initialize(ptr_Stack->ptr_list);	
}

void stack_push(Stack *ptr_stack, int key)
{
list_insert_front(ptr_Stack->ptr_list, key);
}

void stack_pop(Stack *ptr_stack) 
{
list_delete_front(ptr_Stack->ptr_list);
}

int stack_is_empty(Stack *ptr_stack) 
{
	if (ptr_Stack->ptr_list->head == NULL)
		return 1;
	else
		return 0;
}

const int stack_peek(Stack *ptr_stack)
{
	return Node_get_data(ptr_Stack->ptr_list->head);
}

void stack_destroy(Stack *ptr_stack) 
{
list_destroy(ptr_Stack->ptr_list);
}

int postfix_eval(const char* expression) 
{
    








	
}
