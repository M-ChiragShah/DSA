#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int val;
    struct node* next;
};
struct node* HEAD;

int isEmpty(){
    if(HEAD == NULL){
        return 1;
    }
    return 0;
}

void addNode_Front(int value){
    struct node* Temp = (struct node*)malloc(sizeof(struct  node));
    if(isEmpty()){
        Temp->prev = NULL;
        Temp->next = NULL;
        Temp->val = value;
        HEAD = Temp;
    }
    else{
        Temp->val = value;
        HEAD->prev = Temp;
        Temp->next = HEAD;
        Temp->prev = NULL;
        HEAD = Temp;
    }
}

void display_ftr(){
    if(!(isEmpty())){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp = HEAD;
        printf("\nFront to Rear\n");
        while(1){
            if(temp->next != NULL){
            printf("%d->",temp->val);
            temp = temp->next;
            }
            else{
                 printf("%d->",temp->val);
                 break;
            }
            
        }
        printf("\nRead to Front\n");
        while(temp != NULL){
            printf("<-%d",temp->val);
            temp = temp->prev;
        }
    }
}

int main(){
    HEAD = NULL;
    addNode_Front(1);
    addNode_Front(2);
    addNode_Front(3);
    display_ftr();
    return 0;
}