#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
Node *newnode;
newnode=create_node(data);
if(pos==0)
{
if(cll->head==NULL)
{
   newnode->next=newnode;
   cll->head=newnode;
   cll->tail=newnode;
   cll->length=cll->length+1;
   return;
}
else
{
newnode->next=cll->head;
cll->length=cll->length+1;
cll->head=newnode;
return;
}
}
if(pos==cll->length)
{
cll->tail->next=newnode;
cll->tail=newnode;
cll->length=cll->length+1;
return;
}
else if(pos>0 && pos<cll->length)
{
Node *prev,*cur;
int count=0;
for(cur=cll->head;cur!=NULL;prev=cur,cur=cur->next,count=count+1)
{
if(count==pos)
{
prev->next=newnode;
newnode->next=cur;
cll->length=cll->length+1;
break;
}
}
}

}

void position_delete(List* cll, int pos)
{
Node *temp;
Node *prev,*cur;
if(pos==0)
{
temp=cll->head;
cll->head=cll->head->next;
free(temp);
cll->length=cll->length-1;
return;
}
if(pos==cll->length-1)
{

for(cur=cll->head;cur!=cll->tail;prev=cur,cur=cur->next);
prev->next=NULL;
cll->tail=prev;
free(cur);
cll->length=cll->length-1;
return;
}
else if(pos>0 && pos<(cll->length-1))
{int count=0;
for(cur=cll->head;cur!=cll->tail;prev=cur,cur=cur->next,count=count+1)
{
if(count==pos)
{
prev->next=cur->next;
free(cur);
cll->length=cll->length-1;
break;
}

}
}


}

int josephus(List* cll, int k)
{
Node *ptr1 = cll->head, *ptr2 = cll->head; 
    while (ptr1->next != ptr1) 
    {  
        int count = 0; 
        while (count != (k+1)) 
        { 
            ptr2 = ptr1; 
            ptr1 = ptr1->next; 
            count=count+1; 
        } 
        /* Remove the m-th node */
        ptr2->next = ptr1->next; 
          free(ptr1);
      cll->length=cll->length-1;
        ptr1 = ptr2->next;
         return(ptr1->data);
    } 

}


