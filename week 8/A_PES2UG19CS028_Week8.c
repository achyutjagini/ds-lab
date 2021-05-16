#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    tree->root=NULL;
    //tree->tree->root=(Node *)malloc(sizeof(Node));
    //tree->tree->root->data=
}

void tree_insert(Tree *tree, int data)
{
Node *cur,*prev;
Node *temp=(Node *)malloc(sizeof(Node));
temp->data=data;
temp->left=temp->right=NULL;
cur=tree->root;
if(tree->root==NULL)
{
  tree->root=temp;
  cur=tree->root;
}
 else 
 {
   while(cur!=NULL)
        {
          prev=cur;
         if(data < cur->data)
            cur=cur->left;
         else
           cur=cur->right;
        }
    if(data< prev->data)    
      prev->left=temp;
       else
        prev->right=temp;
    }
 }
 Node *search(int key,Node **prev,Tree *t)
{
    Node *cur;
    //(*prev)=NULL;
    cur=t->root;
    if(key==cur->data)
           return cur;
    while(cur!=NULL)
    {
       if(key==cur->data)
          return cur;
        else
        {
            (*prev)=cur;
           if(key<cur->data)
              cur=cur->left;
           else
           {
                cur=cur->right;
           }
              
               
        }
           
    }
    //return cur;
}

void tree_delete(Tree *tree, int element)
{
Node *cur,*prev,*insucc,*inprev;
cur=search(element,&prev,tree);
//deleted Node has both left and right subtree-working
if(cur->left!=NULL && cur->right!=NULL)
{
    inprev=cur;
    insucc=cur->right;
    while(insucc->left!=NULL)
    {
        inprev=insucc;
        insucc=insucc->left;
    }
    cur->data=insucc->data;
    if(inprev==cur)
    {
        inprev->right=insucc->right;
    }
    else
        inprev->left=insucc->right;
free(insucc);        
return;    
}
//deleted Node has only 1 subtree
if(cur->left!=NULL||cur->right!=NULL)
{
if(cur==tree->root)
{
    if(cur->left!=NULL)
    {tree->root=cur->left;//i just changed
    }
    else 
    tree->root=cur->right;
}
else if(prev->left==cur)
     prev->left=cur->left;
else
{
    prev->right=cur->right;
}
cur=NULL;
free(cur);
return;
}

//deleted Node is leaf Node-working
if(cur->left==NULL && cur->right==NULL)
{
if(cur==tree->root)
   tree->root=NULL;

else if(prev->left==cur)
     prev->left=NULL;
else
{
    prev->right=NULL;
}
   return;     
}
} 
void tree_inorder(Node *r)
{
 	  if(r==NULL)
       { 
         return;}
 //else if (Node!=NULL)
   // {
        tree_inorder( r->left ); 
        printf( "%d ", r->data );
        tree_inorder( r->right );
   // }
}

void tree_preorder(Node *r)
{
    if(r==NULL)
       {  
         return;}
 //else if (Node!=NULL)
   // {
        printf( "%d ", r->data );
        tree_preorder( r->left ); 
        tree_preorder( r->right );
   // }

}

void tree_postorder(Node *r)
{
    if(r==NULL)
       { 
         return;}
 //else if (Node!=NULL)
   // {
        tree_postorder( r->left ); 
        tree_postorder( r->right );
        printf( "%d ", r->data );
   // }
}

void postorder(Tree *t)
{
   tree_postorder(t->root);
   printf("\n");
}

void preorder(Tree *t)
{
     tree_preorder(t->root);
     printf("\n");
}

void inorder(Tree *t)
{
    tree_inorder(t->root);
    printf("\n");
}

void destroy(Node *r)
{
  if(r==NULL) 
  { return;}  
  destroy(root->left);
  
  destroy(root->right); 
  
  free(root);
  
}

void tree_destroy(Tree *t)
{ 
    destroy(t->root);
}
