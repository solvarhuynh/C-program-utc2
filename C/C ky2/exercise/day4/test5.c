#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct list{
    node* head;
    node* tail;
}list;
void duyet(list l){
    while(l.head!=NULL){
        printf("%d ", l.head->data);
        l.head = l.head->next;
    }
}
void themcuoi(list* l, int n){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    if(l->head == NULL){
        l->head = newnode;
        printf("%p\n",l->tail);
        l->tail = newnode;
        printf("%p\n%p\n",l->tail, newnode);
    }else{
        printf("\n%p\n%p",l->tail, newnode);
        printf("\n%p\n",l->tail->next);
        l->tail->next = newnode;
        printf("\n%p\n",l->tail->next);
        l->tail = newnode;
        printf("%p\n%p\n",l->tail,l->tail->next);
    }
}
int main(){
    list l;
    l.head = NULL, l.tail = NULL;
    for(int i = 0; i<2; i++){
        themcuoi(&l, i);
    }
    duyet(l);
}