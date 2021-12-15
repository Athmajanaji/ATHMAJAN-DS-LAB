#include<stdlib.h>
#include <stdio.h>
     
void create();
void display();
struct node *insertatend(struct node *head, int data);
struct node *insertatbeg(struct node*head,int data);
struct node *insertatindex(struct node*head,int data,int pos);
struct node *deleteatbeg(struct node *head);
struct node *deleteatend(struct node *head);
struct node *deleteAtIndex(struct node * head, int index);

 
struct node
{
 int data;
 struct node *next;
};
struct node *start=NULL;
int main()     
{
 int choice,a,pos;
 while(1){
  printf("\n                MENU                             \n");
  printf("\n 1.Create     \n");
  printf("\n 2.Insert At The Begining     \n");
  printf("\n 3.Insert At End     \n");
  printf("\n 4.Insert in between     \n");
  printf("\n 5.Display    \n");
  printf("\n 6.Delete at begining    \n");
  printf("\n 7.Delete at end    \n");
  printf("\n 8.Delete at Pos       \n");
  printf("\n 9.Exit       \n");
  printf("Enter your choice:\t");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
         create();
         break;
  case 5:
         display();
         break;                        
  case 2:
         printf("Enter Element ");
         scanf("%d",&a);
         start=insertatbeg(start,a);
         break;
  case 4:
         printf("Enter Element ");
         scanf("%d",&a);
         printf("Enter Postion After Which you want to insert element");
         scanf("%d",&pos);
         start=insertatindex(start,a,pos);
         break;
  case 3:
         printf("Enter Element ");
         scanf("%d",&a);
         start=insertatend(start,a);
         break;
  case 6:
         start=deleteatbeg(start);
         break;
  case 7:
         start=deleteatend(start);
         break;
  case 8:printf("Enter The POsition");
         scanf("%d",&pos);
         start=deleteAtIndex(start,pos);
         break;
  case 9:
         exit(0);
         break;
                             
  default:
          printf("n Wrong Choice:n");
          break;
  }
 }

return 0;
}

void create()
{
 struct node *temp,*ptr;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
  printf("\nOut of Memory Space:\n");
  exit(0);
 }
 printf("\nEnter the data value for the node:\t");
 scanf("%d",&temp->data);
 temp->next=NULL;
 if(start==NULL)
 {
  start=temp;
 }
 else
 {
  ptr=start;
  while(ptr->next!=NULL)
  {
   ptr=ptr->next;
  }
   ptr->next=temp;
  }
}
void display()
{
 struct node *ptr;
 if(start==NULL)
 {
 printf("\nList is empty:\n");
 return;
 }
 else
 {
  ptr=start;
  printf("\nThe List elements are:\n");
  while(ptr!=NULL)
  {
   printf("%d---->",ptr->data );
   ptr=ptr->next ;
  }
 }
}


struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;
    ptr->next = NULL;
    while(p->next!=NULL){
     p=p->next;
    }
    p->next=ptr;
    return head;
}

struct node *insertatbeg(struct node*head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = start;
    return ptr;
}

struct node *insertatindex(struct node*head,int data,int pos){
    int i=0;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data = data;
    while(i!=pos-1){
    p=p->next;
    i++;
    }
    ptr->next = p->next;
    p->next=ptr;
    return head;
}

struct node *deleteatbeg(struct node *head){
struct node *temp= head;
struct node *p;
head=head->next;
free(temp);
return head;
}
struct node *deleteatend(struct node *head){
struct node *temp= head;
struct node *p;
while(temp->next!=NULL){
p=temp;
temp=temp->next;
}
p->next=NULL;
free(temp);
return head;
}

struct node *deleteAtIndex(struct node * head, int index){
    if(head->next==NULL){
     printf("Nothing to delete");
     }
    else
    {
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
    }
}

