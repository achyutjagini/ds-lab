#include "cll.h"

void position_insert(List *cll, int data, int pos)
{
	Node *new_node = create_node(data);
	if (pos > cll->length)
	{
		return;
	}
	else if (pos == 0)
	{
		if (cll->length == 0)
		{
			cll->head = new_node;
			cll->tail = cll->head;
		}
		else
		{
			new_node->next = cll->head;
			cll->head = new_node;
			cll->tail->next = cll->head;
		}

		cll->length++;
	}
	else if (pos == cll->length && pos != 0)
	{
		Node *temp = cll->tail;
		temp->next = new_node;
		cll->tail = new_node;
		new_node->next = cll->head;
		cll->length++;
	}
	else
	{
		int i = 0;
		Node *temp;
		temp = cll->head;
		for (; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
		cll->length++;
	}
}

void position_delete(List *cll, int pos)
{

	struct Node *newnode, *temp;
	newnode = cll->head;
	if (pos == 0)
	{
		cll->head = newnode->next;
		cll->tail->next = cll->head;
		free(newnode);
		cll->length -= 1;
	}
	else if (pos == cll->length)
	{
		int i;
		for (i = pos - 1; i >= 0; i--)
		{
			temp = newnode;
			newnode = newnode->next;
		}
		temp->next = cll->head;
		cll->length -= 1;
	}
	else if (pos < cll->length)
	{
		int i;
		for (i = pos - 1; i >= 0; i--)
		{
			temp = newnode;
			newnode = newnode->next;
		}
		temp->next = newnode->next;
		cll->length -= 1;
	}
}

int josephus(List *cll, int k)
{
	int i;
	Node *newnode = cll->head;
	Node *temp = NULL;
	for (i = 0; i < k; i++)
	{
		newnode = newnode->next;
	}
	if (k == -1)
	{
		newnode = cll->tail;
	}
	while (cll->length > 1)
	{
		temp = newnode->next;
		newnode->next = temp->next;
		free(temp);
		cll->length--;
		newnode = newnode->next;
	}
	cll->head = newnode;
	cll->tail = newnode;
	return newnode->data;
}
