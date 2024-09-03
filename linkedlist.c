#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//creating a node
struct node{
    char name[20];
    int rollno;
    struct node* next;
};
//function to create a new node 
struct node* create_node(char *name,int rollno){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name,name);
    newnode->rollno=rollno;
    newnode->next=NULL;
    return newnode;
}
// Function to insert a node at a specified position
void insertion_ele(struct node** head,char*name,int rollno,int pos){
    struct node*newnode=create_node(name,rollno);
    if (pos==1){
        newnode->next = *head;
        *head=newnode;
        return;
    }
    struct node*temp=*head;
    for (int i=1;i<(pos-1&&temp!=NULL);i++){
        temp= temp->next;
    }
    if (temp==NULL){
        printf("postion is out of bounds.\n");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void display(struct node*head){
    struct node*temp=head;
    while (temp!=NULL){
        printf("Name:%s,roll no:%d\n",temp->name,temp->rollno);
        temp=temp->next;
    }
}
int main(){
    struct node*head=NULL;
    insertion_ele(&head,"divyansh",1,1);
    insertion_ele(&head,"divyansh",3,2);
    display(head);
    return 0;
}
