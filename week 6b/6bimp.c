#include "6b.h"
#include<stdlib.h>
#include<ctype.h>
stack* stack_initialize(int size)
{
	stack * Stack = (stack *)malloc(sizeof(stack));
	Stack->top=-1;
	Stack->arr=(int *)malloc(size*sizeof(int));
	return Stack;
}

void stack_push(stack *ptr_stack, int key) 
{
	ptr_stack->arr[++ptr_stack->top]=key;
}

int stack_is_empty(stack *ptr_stack)
{
	return ptr_stack->top==-1;
}

void stack_pop(stack *ptr_stack)
{
	if(stack_is_empty(ptr_stack)==0){
		ptr_stack->arr[ptr_stack->top=ptr_stack->top-1];
	}
}


int stack_peek(stack *ptr_stack) 
{
	if(stack_is_empty(ptr_stack)==0){
		return ptr_stack->arr[ptr_stack->top];
	}
}

void stack_destroy(stack *ptr_stack) 
{
	free(ptr_stack->arr);
}
int check_prec(char symb){
			if(symb=='+' || symb=='-'){
				return 2;
			}
			else if(symb=='*' || symb=='/'){
				return 4;
			}
			else if(isalpha(symb)){
				return 8;
			}
			else if(symb=='('||symb=='['||symb=='{'){
				return 0;
			}
}
int input_prec(char symb){
			if(symb=='+' || symb=='-'){
				return 1;
			}
			else if(symb=='*' || symb=='/'){
				return 3;
			}
			else if(isalpha(symb)){
				return 7;
			}
			else if(symb==')'||symb==']'||symb=='}'){
				return 0;
			}
			else if(symb=='('||symb=='['||symb=='{'){
				return 9;
			}
		}

		
void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
	//#include<ctype.h>
	stack * Stack = stack_initialize(strlen(source_infix));
	int i=0,j=0;
	while(source_infix[i]!='\0'){
		
		while(check_prec(stack_peek(Stack))>input_prec(source_infix[i])){
			target_postfix[j]=stack_peek(Stack);
			stack_pop(Stack);
			j++;
		}
		if(input_prec(source_infix[i])!=check_prec(stack_peek(Stack))){
			stack_push(Stack,source_infix[i]);
		}
		else{
			stack_pop(Stack);
		}
		i++;
	}
	if(stack_is_empty(Stack)==0){
		while(stack_is_empty(Stack)==0){
			target_postfix[j]=stack_peek(Stack);
			stack_pop(Stack);
			j++;
		}
	}
	target_postfix[j]='\0';
	stack_destroy(Stack);
}
