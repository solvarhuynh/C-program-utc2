#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct list{
    node *head;
    node *tail;
}list;
void duyet(list L){
    while(L.head!=NULL){
        printf("%d ",L.head->data);
        L.head = L.head->next;
    }
}
void themdau(list* L, int n){
    node* nwnode = (node*)malloc(sizeof(node));
    nwnode->data = n;
    nwnode->next = NULL;
    if(L->head == NULL){
        L->tail = nwnode;
    }
    nwnode->next = L->head;
    L->head = nwnode;

}
int main(){
    list l;
    l.head = NULL, l.tail= NULL;
    for(int i = 0; i < 10; i++){
        themdau(&l,i);
    }
    duyet(l);

}
