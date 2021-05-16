#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

Node *newNode(int);
void setLeft(Node*,int);
void setRight(Node*,int);

void tree_initialize(Tree *tree)
{
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *ptrnode=tree->root, *par=NULL;
    while(ptrnode!=NULL){
        par=ptrnode;
        if(data<ptrnode->data){
            if(!ptrnode->leftThread)ptrnode=ptrnode->left;
            else break;
        }
        else{
            if(!ptrnode->rightThread)ptrnode=ptrnode->right;
            else break;
        }
    }
    if(par==NULL){
        tree->root=newNode(data);
        return ;
    }
    if(data<par->data)setLeft(par,data);
    else setRight(par,data);
}

Node *inorder_predecessor(Node *ptr)
{
    if(ptr->leftThread)return ptr->left;
    ptr=ptr->left;
    while(!ptr->rightThread)ptr=ptr->right;
    return ptr;
}

Node *inorder_successor(Node *ptr)
{
    if(ptr->rightThread)return ptr->right;
    ptr=ptr->right;
    while(!ptr->leftThread)ptr=ptr->left;
    return ptr;
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *ptrnode=tree->root;
    while(!ptrnode->leftThread)ptrnode=ptrnode->left;
    while(ptrnode!=NULL){
        printfun(ptrnode->data);
        ptrnode=inorder_successor(ptrnode);
    }
    nextline();
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *ptrnode=tree->root;
    while(!ptrnode->rightThread)ptrnode=ptrnode->right;
    while(ptrnode!=NULL){
        printfun(ptrnode->data);
        ptrnode=inorder_predecessor(ptrnode);
    }
    nextline();
}

void destroy(Node *r)
{
    //TODO
    Node *temp;
    while(r->left!=NULL)r=r->left;
    while(r!=NULL){
        temp=r;
        r=r->right;
        free(temp);
    }
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}

Node *newNode(int data){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    newnode->leftThread=newnode->rightThread=1;
    return newnode;
}

void setLeft(Node *ptrnode, int data){
    Node *newnode=newNode(data);
    newnode->left=ptrnode->left;
    ptrnode->left=newnode;
    newnode->right=ptrnode;
    ptrnode->leftThread=0;
}

void setRight(Node *ptrnode, int data){
    Node *newnode=newNode(data);
    newnode->right=ptrnode->right;
    ptrnode->right=newnode;
    newnode->left=ptrnode;
    ptrnode->rightThread=0;
}

