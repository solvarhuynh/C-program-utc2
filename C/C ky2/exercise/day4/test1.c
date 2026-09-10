#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

void duyet(node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}
node* themdau(node *head, int n){
    node* nwnode = (node*)malloc(sizeof(node));
    nwnode->data = n;
    nwnode->next = head;
    head = nwnode;
    return head;
}
int main(){
    node *head = NULL;
    for(int i = 0; i < 10; i++){
        head = themdau(head,i);
    }
    duyet(head);
}