#include"et.h"
#include<ctype.h>

void push(Node **s,int *t, Node *temp)
{
    ++(*t);
    s[*t]=temp;
}

int isoper(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/': 
        return 1;
        default : return 0;
    }
}

Node* pop(Node **stack,int *top)
{
    Node *temp;
    temp=stack[*top];
    (*top)--;
    
    return temp;
}

Node * createExpressionTree(char* a,int len)
{
    char ch;
    Node *stack[100];


    int top=-1;
    int i=0;
    
    Node *temp;
    
    while(a[i]!='\0')
    {
      
      ch=a[i];
     if(isalpha(ch))
     {
      temp=(Node *)(malloc(sizeof(Node)));      
      temp->left=temp->right=NULL;
      temp->data = ch;
      push(stack,&top,temp); 
     }
      if(isoper(ch))
      {
        temp=(Node *)(malloc(sizeof(Node))); 
        temp->data = ch;
        temp->right=pop(stack,&top);
        temp->left=pop(stack,&top);
        
        push(stack,&top,temp);
      }    


    i++;     
    }

    return(pop(stack,&top));
 
}





void inorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL)
 {
    inorder(root->left);
    printf("%c",root->data); 
    inorder(root->right);
 }

}


void preorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL)
 {
   printf("%c",root->data);
   preorder(root->left);
   preorder(root->right);
 }
     
}

void postorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL)
 {
   postorder(root->left);
   postorder(root->right);
   printf("%c",root->data);
 }
   
}

void freeTree(Node *root)
{
  if(root==NULL) 
  { return;}  
  freeTree(root->left);
  
  freeTree(root->right); 
  
  free(root);
}
