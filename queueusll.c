#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct queue{
    int data;
    struct queue *next;
};
struct queue *front=NULL;
struct queue *rear;
int main(){
    int choice=0;     
    printf("\n*********Queue operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:   
                push();  
                break;   
            case 2:  
                pop();  
                break; 
            case 3:  
                display();  
                break;  
            case 4:   
                printf("Exiting....");
                exit(0);  
                break;   
            default:  
                printf("Please Enter valid choice ");   
        }  
    }  
    return 0;
}

void push(){
    int val;
    struct queue *ptr=(struct queue *)malloc(sizeof(struct queue));
    if(ptr==NULL){
        printf("queue OverFlow");
    }
    else{
        printf("Enter The Value To Insert");
        scanf("%d",&val);
        ptr->data=val;
        if(front==NULL){
            front=ptr;
            rear=ptr;
            front->next=NULL;
            rear->next=NULL;
        }
        else{
            rear->next=ptr;
            rear=ptr;
            rear->next=NULL;
        }
    }
    printf("Item Inserted");
}

void display(){
    struct queue *ptr;
    ptr=front;
    if(ptr==NULL){
        printf("queue Is Empty");
    }
    else{
        printf("queue Elements\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void pop(){
    struct queue*ptr;
    int item;
    if(front==NULL){
        printf("queue Underflow");
    }
    else{
        ptr=front;
        item=front->data;
        front=front->next;
        free(ptr);
        printf("%d Delted",item);
    }
}