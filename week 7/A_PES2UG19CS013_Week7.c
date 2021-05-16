#include "queue.h"
static node *create_node(int id, int time, node *link)
{
node *ptr;
ptr=(struct node *)malloc(sizeof(node)); 
ptr->id=id;
ptr->time=time;
ptr->link=link;
return ptr;
}
void list_initialize(List *ptr_list)
{
ptr_list->head=NULL;
ptr_list->tail=NULL;
ptr_list->number_of_nodes=0;
}
const int node_get_id(node *node_ptr)
{
return(node_ptr->id);
}

const int node_get_time(node *node_ptr)
{
return(node_ptr->time);
}

void list_insert_rear(List *ptr_list, int id, int time)
{   node *temp=NULL;
	temp=create_node(id,time,NULL);
	if(ptr_list->head==NULL)
	{
		ptr_list->head=temp;
		ptr_list->tail=temp;
		ptr_list->number_of_nodes=ptr_list->number_of_nodes+1;
		return;
	}
    else
	{
	    ptr_list->tail->link=temp;
		ptr_list->tail=temp;
	    ptr_list->number_of_nodes=ptr_list->number_of_nodes+1;
}
}

void list_delete_front(List *ptr_list)
{
if(ptr_list->number_of_nodes==0)
{
printf("Empty Queue");
return;	
}
node *temp;
temp=ptr_list->head;
ptr_list->head=ptr_list->head->link;
free(temp);
ptr_list->number_of_nodes=ptr_list->number_of_nodes-1;
return;
}

void list_destroy(List *ptr_list)
{
node *temp,*prev;
temp=ptr_list->head;
while(temp!=NULL)
{
prev=temp;
temp=temp->link;
free(prev);
}
free(temp);
}

void queue_initialize(Queue *queue_list)
{
queue_list->ptr_list=(List *)malloc(sizeof(List));
}

void queue_enqueue(Queue *ptr, int id, int time)
{
list_insert_rear(ptr->ptr_list, id, time);
}

void queue_dequeue(Queue *ptr)
{
list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{



}

void queue_peek(Queue *ptr)
{
		if(ptr->ptr_list->number_of_nodes==0)
		{
			printf("Empty List");
			return;
		}
else
{
printf("%d %d\n",ptr->ptr_list->head->id,ptr->ptr_list->head->time);
}

}

void queue_destroy(Queue *ptr)
{


}

const int queue_find_person(Queue *ptr_queue, int t)
{


	
}

