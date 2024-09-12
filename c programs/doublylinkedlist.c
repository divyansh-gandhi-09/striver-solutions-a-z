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
    
}
