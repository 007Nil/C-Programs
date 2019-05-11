#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *link;
}node;

node *root = NULL;

void Append();
void Add_at_begin ();
void Add_in_middle ();
int length();
void display ();
void delete_node ();

int main (){
    int choise;
    while(1){

        printf("Single Linked List Operations \n\n");
        printf("1. APPEND\n");
        printf("2. Add At begin \n");
        printf("3. Add In Middle \n");
        printf("4. Length of Linked List \n");
        printf("5. Display all the elements in Linked List \n");
        printf("6. Delete Node in Linked List \n");
        printf("7. Exit \n");
        printf("Enter your option :");
        scanf("%d",&choise);

        switch(choise){
        case 1:
            Append();
            break;
        case 2:
            Add_at_begin();
            break;
        case 3:
            Add_in_middle();
            break;
        case 4:
            printf("The Length is %d \n\n",length());
            break;
        case 5:
            display();
            break;
        case 6:
            delete_node();
            break;
        case 7:
            exit(1);
        default :
            printf("Invalid Input to the program");

        }

    }
    return 0;

}

void Append(){
    node *temp = NULL;
    temp = (node*)malloc(sizeof(node));
    printf("Enter the node value :");
    scanf("%d",&temp->data);
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        node *p = root;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
}

void Add_at_begin(){
    node *temp = NULL;
    temp =(node*)malloc(sizeof(node));
    printf("Enter the node data :");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        temp->link = root;
        root = temp;
    }
}

int length()
{
    int count = 0;
    node* temp;
    temp = root;

    while (temp != NULL) {

        count ++;
        temp = temp->link;
    }
    return count;

}
void Add_in_middle(){
    node *temp, *p;
    int location, len;
    int i = 1;
    printf("Enter the location of node :");
    scanf("%d",&location);
    len = length();

    if(location > len){
        printf("Invalid location \n");
        printf("Currently the linked list have %d nodes",len);
    }
    else{
        p = root;
        while(location > i){
                    p = p->link;
                    i++;
            }
            temp = (node*)malloc(sizeof(node));
            printf("Enter the node data");
            scanf("%d",&temp->data);
            temp->link = p->link;
            p->link = temp;
    }
}

void display(){
    node *temp = NULL;
    temp = root;

    if(root == NULL){
        printf("The Link list is Emply \n\n");
    }
    else{
         while (temp != NULL){
                printf("%d >>",temp->data);
                temp = temp->link;
        }
    }

}

void delete_node(){
    node *temp = NULL;
    int location = 0 ;
    printf("Enter the location of the node to be deleted :");
    scanf("%d",&location);

    if(location> length()){
        printf("Invalid location \n");
        printf("Currently the linked list have %d nodes",length());
    }
    else if (location == 1){
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else{
        node *p,*q;
        int i = 1;
        p = root;
        while(i < location){
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link =NULL;
        free(q);
    }
}
