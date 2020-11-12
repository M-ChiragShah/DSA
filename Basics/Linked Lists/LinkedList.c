#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}NODE;

NODE* first;

void createnode(int val){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if( temp != NULL){
        temp->value = val;
        temp->next = NULL;
        if(first != NULL){
            temp->next = first;
            first = temp;
        }
        else{
            first = temp;
        }
    }
    else{
        printf("\nOut of memory\n");
    }
}

void insert(int position, int val){
    NODE* temp = first;
    NODE* temp_2 = (NODE*)malloc(sizeof(NODE));
    int count = 1;
    if(first != NULL){
        while(count != position){
            temp = temp->next;
            count++;
        }
        temp_2->value = temp->value;
        temp_2->next = temp->next;
        temp->value = val;
        temp->next = temp_2;

    }
}

void display(){
    NODE* temp = first;
    if(first != NULL){
        printf("\nLINKED LIST : ");
        while(temp != NULL){
            if(temp->next != NULL){
                printf("%d -> ",temp->value);
            }
            else{
                printf("%d",temp->value);
            }
            temp = temp->next;
        }
        printf("\n\n");
    }
}
int main(){
    first = NULL;
    int size_node,element;
    printf("\nLinked Lists\n\n");
    printf("How many nodes do you want to add : ");
    scanf("%d",&size_node);
    printf("\nEnter a number to add to the list\n\n");
    for(int i = 0; i < size_node; i++){
        scanf("%d",&element);
        createnode(element);
        display();
    }
    printf("\n");
    return 0;
}