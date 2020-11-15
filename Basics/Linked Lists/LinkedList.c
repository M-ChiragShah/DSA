#include<stdio.h>
#include<stdlib.h>

/* Defining the structure */
typedef struct node{
    int value;
    struct node* next; // Self Referntial Structure
}NODE;

/* Declaring global pointer so that it can be accessed by all functions */
NODE* first;


/* 
- This funciton creates a node
- It checks if list is empty if it is then it links first to new node
- Else it just updates first
*/
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

/* 
- This function inserts an element at given position 
*/
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

/*
- This functiuon deletes an element at a given position
*/
/*void delete(int position){
    NODE* temp = first;
    while(position-- != 0){
        if(first->next == NULL && position != 0){
            printf("\nOUT OF BOUNDS\n");    
        }
    }
}*/

/*
- This function displays the entire linked list
*/
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

//Main
int main(){
    /*
    Initialize first to NULL to avoid dangling pointer
    and to know that the list is empty
    */
    first = NULL;

    //initialize variables
    int size_node,element,choice,position;
    choice = 0;

    //Print instructions
    printf("\nLinked Lists\n\n");
    while(choice != -1){
    l :  
    printf("Choose an opition : \n1. Create a linked list\n2. Add a number to linked list\n3. Insert at position\n4. -1 to quit\n");
    scanf("%d",&choice);
        switch(choice){
            case 1 :
                    printf("\nHow many nodes does your list have ?\n");
                    scanf("%d",&size_node);  
                    printf("\nEnter a number to add to the list\n\n");
                    for(int i = 0; i < size_node; i++){
                        scanf("%d",&element);
                        createnode(element);
                        display();
                    }
                    break;
            case 2 :
                    if(first == NULL){
                        printf("\nPlease create a linked list first\n");
                        goto l;
                    }
                    printf("\nEnter the elment you want to add\n");
                    scanf("%d",&element);
                    createnode(element);
                    display();
                    break;
            case 3 :
                    printf("\nEnter the position (Index) and the element (Value)\n");
                    scanf("%d%d",&position,&element);
                    insert(position,element);
                    display();
                    break;
            default:
            break;

        }
    }
  
    printf("\n");
    return 0;
}