#include<stdio.h>
#include "trie.h"

void display(struct trienode *curr)
  {
     int i,j;
   for(i=0;i<26;i++)
   {
     if(curr->child[i]!=NULL)
     {
       word[length++]=i+97;
       if(curr->child[i]->endofword==1)//if word found
       {   printnewline();
          
          for(j=0;j<length;j++)
             printf("%c",word[j]);
        }
       display(curr->child[i]);
     }
    }
    length--;
    return; 
 }

 struct trienode *getnode()
 {
   int i;
   struct trienode *temp;
   temp=(struct trienode*)malloc(sizeof(struct trienode));
   for(i=0;i<26;i++)
    temp->child[i]=NULL;
  temp->endofword=0;
   return temp;
 }


 void insert(struct trienode * root, char *key)
 {
   int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        curr->child[index]=getnode();
      curr=curr->child[index];
    }
    curr->endofword=1;
  }


 int search(struct trienode * root,char *key)
  {

  int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];
    }
    if(curr->endofword==1)
       return 1;
   return 0;
  }

 void delete_trie(struct trienode *root,char *key)
  {
    int i,j,index,flag;
    struct trienode* curr;
    curr=root;
    flag=1;

    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
      {
         return;
      }
      curr=curr->child[index];
    }
      curr->endofword=0;
      return;
  }













 


 
 



















