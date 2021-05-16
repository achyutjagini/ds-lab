#include "queue.h"

void list_initialize(List *ptr_list) {
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
	ptr_list->number_of_nodes = 0;
}

const int node_get_id(node *node_ptr) {
	return node_ptr->id;	
}

const int node_get_time(node *node_ptr) {
	return node_ptr->time;	
}

void list_insert_rear(List *ptr_list, int id, int time) {
	if (!ptr_list->number_of_nodes) {
		node* axax = malloc(sizeof(node));
		axax->id = id;
		axax->time = time;
		axax->link = NULL;
		ptr_list->head = axax;
		ptr_list->tail = axax;
	}
	else {
		node* xaxa = malloc(sizeof(node));
		xaxa->id = id;
		xaxa->time = time;
		xaxa->link = NULL;
		ptr_list->tail->link = xaxa;
		ptr_list->tail = xaxa;
	}
	ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list) {
	if (ptr_list->number_of_nodes != 0){
        node* temp = ptr_list->head;
        ptr_list->head = temp->link;
        free(temp);
        ptr_list->number_of_nodes--;
    }
}

void list_destroy(List *ptr_list) {
    while(ptr_list->number_of_nodes > 0){
		node* temp = ptr_list->head;
		ptr_list->head = temp->link;
		free(temp);
		ptr_list->number_of_nodes--;
    }
    free(ptr_list);
}

void queue_initialize(Queue *queue_list) {
	List* listthing = malloc(sizeof(List));
	list_initialize(listthing);
	queue_list->ptr_list = listthing;
}

void queue_enqueue(Queue *ptr, int id, int time) {
	list_insert_rear(ptr->ptr_list, id, time);
}

void queue_dequeue(Queue *ptr) {
	list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr) {
	if (ptr->ptr_list->number_of_nodes != 0) {
		return 0;
	}	
	else {
		return 1;	
	}
}

void queue_peek(Queue *ptr) {
	if (queue_is_empty(ptr) == 0) {
		printf("%d %d\n", ptr->ptr_list->head->id, ptr->ptr_list->head->time);	
	}
	else {
		printf("Empty Queue\n");
	}
}

void queue_destroy(Queue *ptr) {
	list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t) {
	int X = 0;
	int obfuscatedthing;
	while (X < t) {
		if (queue_is_empty(ptr_queue)) {
			printf("Empty Queue\n");
			return -69;
		}
		X += node_get_time(ptr_queue->ptr_list->head);
		if (X > t) { 
			break;
		}
		if (ptr_queue->ptr_list->number_of_nodes != 0){
			node* temp = ptr_queue->ptr_list->head;
			ptr_queue->ptr_list->head = temp->link;
			free(temp);
			ptr_queue->ptr_list->number_of_nodes--;
		}
	}
	if (queue_is_empty(ptr_queue)) {
		printf("Empty Queue\n");
		return -69;
	}
	obfuscatedthing = ptr_queue->ptr_list->head->id;
	printf("%d\n", obfuscatedthing);
}