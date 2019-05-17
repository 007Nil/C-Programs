#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

int queue[CAPACITY];
int front = 0;
int rare = 0;

void push();
void pop();
void display();

int main(){
    int choice;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
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
            default:
                printf("Invalid Option");
        }
    }
    return 0;
}

void push(){
    if (rare == CAPACITY ){
        printf("Overflow");
    }
    else{
        int data;
        printf("Enter the data :");
        scanf("%d",&data);
        queue[rare] = data;
        rare++;
    }
}

void pop(){
    if (front == rare){
        printf("The Queue is Emply\n\n");
    }
    else{
        printf("%d will be deleted from Queue\n\n",queue[front]);

        for(int i =1; i<rare; i++ ){
            queue[i-1] = queue[i];
        }
    }
}

void display(){
     if (front == rare){
        printf("The Queue is Emply\n\n");
    }
    else{
        for (int i=front;i<rare;i++){
            printf("%d \n",queue[i]);
        }
    }
}
