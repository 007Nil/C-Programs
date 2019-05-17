#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;
    node *top = NULL;

    void push();
    void pop();
    void display();

    int main(){
        int choise;
        while(1){
            printf("1. Push \n");
            printf("2. Pop \n");
            printf("3. Display \n");
            printf("4. Exit \n\n");
            printf("Enter your choise :");
            scanf("%d",&choise);

            switch(choise){
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(1);
                default:
                    printf("Invalide Entry \n\n");
            }
        }
        return 0;
    }

    void push(){
        node *temp;
        temp =(node*)malloc(sizeof(node));
        printf("Enter the node data :");
        scanf("%d",&temp->data);
        temp->link = top;
        top = temp;
    }

    void pop(){
        node *temp;
        if ( top == NULL){
            printf("Underflow \n\n");
        }
        else{
            temp = top;
            printf("%d will be deleted \n\n",temp->data);
            top = top->link;
            temp->link = NULL;
            free(temp);
        }
    }
    void display(){
        node * temp;
        temp = top;
        if (top == NULL){
            printf("Stack is emply \n\n");
        }
        else{
             while(temp != NULL){
                printf("%d\n",temp->data);
                temp = temp->link;
            }
        }

    }
