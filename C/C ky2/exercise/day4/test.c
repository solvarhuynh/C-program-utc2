#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next; 
}node;
void duyet(node* head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}
void themdau(node **head, int n){
    node* nwnode = (node*)malloc(sizeof(node));
    printf("\ndc **head: %p\ndc *head: %p\ndc nwnode: %p\n", head, *head, nwnode);
    nwnode->data = n;
    nwnode->next = *head;
    *head = nwnode;
    printf("\ndc **head: %p\ndc *head: %p\ndc nwnode->next: %p\n", head, *head, nwnode->next);
}
int main(){
    node* head = NULL;
    printf("dc cua head: %p\n",head);
    for(int i = 0; i<2; i++){
        themdau(&head, i);
    }
    printf("gt cua head: %p\ndc cua head: %p\n",*head, head);
    duyet(head);
}