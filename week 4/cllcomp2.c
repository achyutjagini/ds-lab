#include "cll.h"

void position_insert(List* cll, int data, int pos)
{
	Node *ptr = create_node(data);				// Creating a node
	if(pos == 0)								// Insert at beginning
	{
		if(cll -> length == 0)					// If list is Empty
		{
			cll -> head = ptr;
			cll -> tail = ptr;
			cll -> length ++;
		}
		else									// If list Exists
		{
			ptr -> next = cll -> head;
			cll -> head = ptr;
			cll -> tail -> next = ptr;
			cll -> length ++;
		}
	}
	else if(pos == cll -> length)					// Insert at end
	{
		cll -> tail -> next = ptr;
		cll -> tail = ptr;
		ptr -> next = cll -> head;
		cll -> length ++;
	}
	else if(pos > 0 && pos < cll -> length)			//Insert at any position
	{
		Node *temp;
		temp = cll -> head;
		int i;
		
		for(i=0;i<pos-1;i++)
		{
			temp = temp -> next; 
		}
		
		ptr -> next = temp -> next;
		temp -> next = ptr;
		cll -> length ++;
	}
}

void position_delete(List* cll, int pos)
{
	
	struct Node *newnode,*temp;
    	newnode=cll->head;
    	if(pos==0)							//position is zero
    	{
        	cll->head=newnode->next;
        	cll->tail->next=cll->head;
        	free(newnode);
        	cll->length-=1;
    	}
    	else if(pos==cll->length)					
    	{
        	int i;
        	for(i=pos-1;i>=0;i--)
        	{
            		temp=newnode;
     	      		newnode=newnode->next;
        	}
        	temp->next=cll->head;
        	cll->length-=1;
    	}
   	 else if(pos<cll->length)
   	 {
        	int i;
        	for(i=pos-1;i>=0;i--)
        	{
            		temp=newnode;	
			newnode=newnode->next;
        	}
       		temp->next=newnode->next;
        	cll->length-=1;
    	}
}


int josephus(List* cll, int k)
{	
 	int i;
    	Node *newnode=cll->head;
    	Node *temp=NULL;
    	for(i=0;i<k;i++)
    	{
        	newnode=newnode->next;
    	}
    	if(k==-1)
    	{
        	newnode=cll->tail;
    	}
    	while(cll->length>1)
    	{
        	temp=newnode->next;
        	newnode->next=temp->next;
        	free(temp);
        	cll->length--;
        	newnode=newnode->next;
    	}
    	cll->head=newnode;
    	cll->tail=newnode;
    	return newnode->data;
}


