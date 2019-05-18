#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;
    node *fornt = NULL;
    node *rare = NULL;

    void push();
    void pop();
    void display();

    int main(){
        int choice;

        while(1){
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Display\n");
            printf("4. Exit\n");

            printf("Enter your choice :");
            scanf("%d",&choice);

            switch(choice){
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
                    break;
                default :
                    printf("Invalide Option \n\n");
            }
        }
        return 0;
    }

    void push(){
        node *temp;
        temp = (node*)malloc(sizeof(node));
        printf("Enter the node data :");
        scanf("%d",&temp->data);
        temp->link = NULL;
        if (fornt == NULL){
            fornt = temp;
        }
        else{
            rare->link = temp;
        }
        rare = temp;
    }

    void pop(){
        if(fornt == NULL){
            printf("Underflow \n");
        }
        else{
            printf("%d will be deleted from Queue \n\n",fornt->data);
            node *p = fornt;
            fornt = fornt->link;
            p->link = NULL;
            free(p);

        }
    }

    void display(){
        node *temp = fornt;

        if( temp == NULL){
            printf("Queue is Emply \n\n");
        }

        while( temp != NULL ){
            printf("%d \n",temp->data);
            temp = temp->link;
        }
    }


