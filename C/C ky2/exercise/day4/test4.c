#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}
node* themcuoi(node *head, int n){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        return head;
    }
    node *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newnode;
    return head;
}
int main(){
    node*head = NULL;
    for(int i = 0; i<10; i++){
        head = themcuoi(head,i);
    }
    duyet(head);
}