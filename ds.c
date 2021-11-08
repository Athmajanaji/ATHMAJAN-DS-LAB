#include<stdio.h>
void insert(int val,int index,int *,int l);
void search(int val,int *,int l);
int main()
{
 int i,l,pos,value,element;
 int a[10];
 int choice;
 int *p;
 printf("Enter The Limit less than 10 \n");
 scanf("%d",&l);
 for(i=0;i<l;i++)
 {
   printf("Enter Number %d  ",i+1);
   scanf("%d",&a[i]);
 }
 p=a;

 for(i=0;i<l;i++)
 {
   printf(" %d ",*p);
   p++;
 }
 printf("\n");
 printf("Select Your Choice \n");
 printf(" 1. Insert \n");
 printf(" 2. Search \n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
         printf("Enter Preferred Position");
         scanf("%d",&pos);
         printf("Enter The Value to insert");
         scanf("%d",&value);
         insert(value,pos,a,l);
         break;
  case 2:
         printf("Enter The Element To Search ");
         scanf("%d",&element);
         search(element,a,l);
         break; 
  case 3:
         printf("Enter The Element To Search ");
         scanf("%d",&element);
         search(element,a,l);
         break; 

  default:printf("Enter A Valid Option");
  
 }
 
}


void insert(int val,int pos,int *a,int l)
{
 int i;

 for(i=l;i>=pos;i--)
  {
   a[i]=a[i-1];
   
  }
a[pos-1]=val;

 for(i=0;i<l+1;i++)
 {
  printf(" %d ",*a);
  a++;
 }
}

void search(int val,int *p,int l)
{
  int i;
 for(i=0;i<l;i++)
   {
     if(val==*p){
       printf("Element found at %d",i+1);
       }
   p++;
  }
}


