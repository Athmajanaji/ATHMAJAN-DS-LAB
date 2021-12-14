#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct stack{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
int main(){
    int choice=0;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
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
    struct stack *ptr=(struct stack *)malloc(sizeof(struct stack));
    if(ptr==NULL){
        printf("Stack OverFlow");
    }
    else{
        printf("Enter The Value To Be Pushed");
        scanf("%d",&val);
        ptr->data=val;
        if(top==NULL){
            ptr->next=NULL;
            top=ptr;
        }
        else{
            ptr->next=top;
            top=ptr;
        }
    }
    printf("Item Pushed");
}

void display(){
    struct stack *ptr;
    ptr=top;
    if(ptr==NULL){
        printf("Stack Is Empty");
    }
    else{
        printf("Stack Elements\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void pop(){
    struct stack*ptr;
    int item;
    ptr=top;
    if(ptr==NULL){
        printf("Stack Underflow");
    }
    else{
        item=top->data;
        top=top->next;
        free(ptr);
        printf("%d Popped",item);
    }
}