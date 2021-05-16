#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	Node *temp;
	Node *newnode;
	newnode= (Node *)malloc(sizeof(Node));
	newnode->data=data;
	newnode->link=NULL;
	if(list->head==NULL)
	{
		list->head=newnode;
		list->number_of_nodes=1;
		return;
	}
	temp=list->head;
    while(temp->link!=NULL)
	     temp=temp->link;
    temp->link=newnode;
	list->number_of_nodes=list->number_of_nodes+1;

}

void list_delete_front(List* list) {
	Node *temp;
	temp=list->head;
	list->head=list->head->link;
	free(temp);
}

void list_insert_at (List *list, int data, int position)
{
    Node *newnode;
	newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
	newnode->link=NULL;
    if(position==0)
	{
	  newnode->link=list->head;
	  list->head=newnode;
	  list->number_of_nodes=list->number_of_nodes+1;
	  return;
	}
	else if(position>0 && position<=list->number_of_nodes)
     {
      Node *prev,*cur=NULL;//cur-second,prev-first
	  int count=0;
      for(cur=list->head;;prev=cur,cur=cur->link,count=count+1)
     {
       if(count==position)
          {
			prev->link=newnode;
			newnode->link=cur;
			list->number_of_nodes=list->number_of_nodes+1;
			break; 
		  }

	 }
	 }


   else if(position==list->number_of_nodes)
      { Node *temp;
		  temp=list->head;
    while(temp->link!=NULL)
	     temp=temp->link;
    temp->link=newnode;
	list->number_of_nodes=list->number_of_nodes+1;
    return;
	  }
}


void list_reverse(List* list)
{
 	Node* prev = NULL;
    Node* cur=list->head;
	Node* next = NULL;
	while (cur != NULL) {
        // Store next
        next = cur->link;//next is 2nd node

        // Reverse current node's pointer
        cur->link = prev; 
        
		// Move pointers one position ahead.
        prev = cur;
        cur = next;
    }
    list->head=prev;
}



