#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char name[50];
    int emp_id;
    struct node*start,*forward;
}node;
node*create_node(char*name,int emp_id){
    node *newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->name, name);
    newnode->emp_id = emp_id;
    newnode->forward=NULL;
    newnode->start=NULL;
    return newnode;
}
void insertion(node**head,char*name,int emp_id,int pos){
    node*newnode=create_node(name,emp_id);
    if (pos ==1){
        newnode->start=NULL;
        newnode->forward=*head;
        *head=newnode;
        return;
    }
    node *temp=*head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->forward;
    }
    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        free(newnode);
        return;
    }
    newnode->start=temp;
    newnode->forward=temp->forward;
    temp->forward=newnode;
}
void delete_node(node**head){
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = *head;
    for (int i = 1; temp != NULL; i++) {
        temp = temp->forward;
    }
    if (temp == NULL || temp->forward == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }
}
