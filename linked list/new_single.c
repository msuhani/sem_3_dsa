#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
// Function to create a new node
struct Node* createNode(int data){
    struct node* newNode=(struct node* )malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("failed to give memory ");
        exit(1);
    }
    
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
    
}
// Function to add a new node at the end of the list
void append(struct Node** head, int data){
    struct node* newnode=createNode(data);
    if(*head==NULL){
        *head=newnode;
    }else {
        struct node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
// Function to traverse and print the elements of the list
void traverse(struct Node* head){
    if(head==NULL)
        printf("list is empty");
    else{
        struct node* temp=head;
        printf("elements of the list are : ");
        while(temp!=NULL){
                    printf("%d", temp->data);
                    temp=temp->next;
        }
    }
}
int main(){
    struct node* head=NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    
    traverse(head);
}