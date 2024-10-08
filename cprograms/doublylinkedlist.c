/*create a doubly inked list having info of employee perform insertion at
front and deletion at the end*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//creating a struct for doubly ll
struct node{
    char name[50];
    int emp_id;
    struct node *forward;
    struct node *backward;
};
//function to create a node
struct node* create_node(int emp_id,char*name){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->emp_id=emp_id;
    strcpy(new_node->name,name);
    new_node->forward=NULL;
    new_node->backward=NULL;
    return new_node;
}
void insertion_ele(struct node**head,int emp_id,char*name){
    //creating a new node using function
    struct node* newnode=create_node(emp_id,name);
    if (*head==NULL){
        *head=newnode;
    }
    else{
        newnode->forward=*head;
        (*head)->backward=newnode;
        *head=newnode;
    }
}
void delete_ele(struct node**head){
    if (*head==NULL){
        printf("list is empty ");
        return;
    }
    //temp
    struct node*temp=*head;
    while (temp->forward!=NULL){
        temp=temp->forward;
    }
    if (temp->backward!=NULL){
        temp->backward->forward=NULL;
    }
    else{
        *head=NULL;
    }
    free(temp);
}
void display(struct node**head){
    struct node*temp1=*head;
    while(temp1!=NULL){
        printf("ID:%d,name:%s\n",temp1->emp_id,temp1->name);
        temp1=temp1->forward;
    }
}
int main(){
    struct node*head=NULL;
    insertion_ele(&head,1,"alice");
    insertion_ele(&head,2,"divyansh");
    insertion_ele(&head,3,"riya");
    printf("original list");
    display(&head);
    delete_ele(&head);
    display(&head);

    
}