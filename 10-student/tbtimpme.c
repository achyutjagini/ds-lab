#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
   tree->root=NULL;

}

void insertleft(threadbst *cur,threadbst *temp)//temp is new node inserted
{
temp->llink=cur->llink;

cur->llink=temp;//temp becomes right child of cur

cur->lthread=0;  //making 0 as node gets a rightchild so right pointer not thread

}

void insertright(threadbst *cur,threadbst *temp)
{
//cur points to node which has right link as thread
temp->rlink=cur->rlink;

cur->rlink=temp;//temp becomes right child of cur

cur->rthread=0;  //making 0 as node gets a rightchild so right pointer not thread
}
void tree_insert(Tree *tree, int data)
{   
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->left=temp->right=NULL;
    temp->leftThread=1;
    temp->rightThread=1;

    Node *prev,*cur;
   
     cur=tree->root;

    if(tree->root==NULL)
     { tree->root=temp;
     return;}
     
     while(cur!=NULL)
{
 prev=cur;
 if(ele<cur->data)
  {
    if(cur->lthread==1)
      break;//exit while and else
   cur=cur->llink;
  }
  else   //ele>cur->data
 {
      if(cur->rthread==1)
        break;//exit while and else

        cur=cur->rlink;
 } 

}//end while

if(cur->lthread==1)
   insertleft(prev,temp);

else
    insertright(cur,temp);

}
     
     }




Node *inorder_predecessor(Node *ptr)
{
   //TODO
}

Node *inorder_successor(Node *ptr)
{
   //TODO
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }

    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    //TODO
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
