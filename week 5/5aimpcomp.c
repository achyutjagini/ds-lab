#include "5a.h"
static Node *create_Node(int data, Node *link)
{
	Node *newnode;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->link = link;
	return newnode;
}
void list_initialize(List *ptr_list)
{
	ptr_list->head = NULL;
	ptr_list->number_of_Nodes = 0;
}

void list_insert_front(List *ptr_list, int data)
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

void list_delete_front(List *ptr_list)
{
	if (ptr_list->head == NULL)
		return;
	Node *temp;
	temp = ptr_list->head;
	if (ptr_list->head->link == NULL)//only one node
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

void list_destroy(List *ptr_list)
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

void display(List *ptr_list)
{
	Node *temp;
	temp = ptr_list->head;
	if (ptr_list->head == NULL)
		printf("EMPTY\n");
	else
	{
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
	}
}

void Stack_initialize(Stack *ptr_Stack)
{
	ptr_Stack->ptr_list = (List*)malloc(sizeof(List));
	list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key)
{
	list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack)
{
	list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack)
{
	if (ptr_Stack->ptr_list->head == NULL)
		return 1;
	else
		return 0;
}

const int Stack_peek(Stack *ptr_Stack)
{
	return Node_get_data(ptr_Stack->ptr_list->head);
}

void Stack_destroy(Stack *ptr_Stack)
{
	list_destroy(ptr_Stack->ptr_list);
}

int match_parenthesis(const char *string)
{
	Stack *ptr;
	ptr = (Stack*)malloc(sizeof(Stack));
	Stack_initialize(ptr);
	int i = 0;
	while (string[i])
	{
		if (string[i] == '(' || string[i] == '[' || string[i] == '{')
		{
			Stack_push(ptr, string[i]);
		}
		if (string[i] == ')' || string[i] == ']' || string[i] == '}')
		{
			if (Stack_is_empty(ptr))
			{
				return 0;
			}
			else if (!((Stack_peek(ptr) == '(' && string[i] == ')') || (Stack_peek(ptr) == '[' && string[i] == ']') || (Stack_peek(ptr) == '{' && string[i] == '}')))
			{
				return 0;
			}
			Stack_pop(ptr);
		}
		i++;
	}
	
	if (Stack_is_empty(ptr))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
