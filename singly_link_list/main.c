#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}node;
    node *root = NULL;

    void Append();
    void Add_at_begin();
    int length();
    void Add_in_middle();
    void display ();
    void delete_node(int);

    int main (){
        int choice;
         int node_key = 0;

        while(1){
            printf("\n\n Singly Link List Operations \n\n");
            printf("1. Append \n");
            printf("2. Add Node at Begin \n");
            printf("3. Add Node in Middle \n");
            printf("4. Length of Link List \n");
            printf("5. Display Elements of Link List \n");
            printf("6. Delete Node from Link List \n");
            printf("7. Exit \n");
            printf("\n\n Enter your Choice :");
            scanf("%d",&choice);

            switch(choice){
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
                    printf("The Length is : %d",length());
                    break;
                case 5:
                    display();
                    break;
                case 6:
                    printf("Enter the node data you want to delete :");
                    scanf("%d", &node_key);
                    delete_node(node_key);
                    break;
                case 7:
                    exit(1);
                    break;
                default:
                    printf("Invalid Chioce \n\n");
            }
        }

        return 0;
    }

    void Append(){
        node *temp;
        temp = (node*)malloc(sizeof(node));
        printf("Enter Node Data :");
        scanf("%d", &temp->data);
        temp->link = NULL;

        if( root == NULL){
            root = temp;
        }
        else{
            node *p;
            p = root;
            while ( p->link !=NULL){
                p = p->link;
            }
            p->link = temp;
        }
    }

    void Add_at_begin(){
        node *temp;
        temp = (node*)malloc(sizeof(node));
        printf("Enter Node data :");
        scanf("%d",&temp->data);
        temp->link = NULL;

        if ( root == NULL){
            root = temp;
        }
        else{
            temp->link = root;
            root = temp;
        }
    }

    int length(){
        node *p;
        int count;
        p = root;
        while( p != NULL){
            p = p->link;
            count ++;
       }
       return count;
    }

    void Add_in_middle(){
        node *temp,*p;
        int location = 0, i =1;
        printf("Enter the location you want to enter the node :");
        scanf("%d",&location);

        if( location > length()){
            printf("Invalide Location \n");
            printf("Currently Link List have %d node is in it",length());
        }

        else{
            p = root;
            while( i > location){
                i++;
                p = p->link;
            }
            temp = (node*)malloc(sizeof(node));
            printf("Enter the Node Data :");
            scanf("%d", &temp->data);
            temp->link = NULL;
            temp->link = p->link;
            p->link = temp;
        }
    }

    void display(){
        node *p;
        p = root;
        while(p != NULL){
            printf("%d >>",p->data);
            p = p->link;
        }
    }

    void delete_node(int node_data){
        node *temp = root;
        while(temp->link != NULL && temp->link->data != node_data ){
            temp = temp->link;
        }
        if( temp->link == NULL){
            printf("Element %d is not present in list \n",node_data);
        }
        else{
            node *p;
            p = temp->link;
            temp->link = p->link;
            p->link = NULL;
            free(p);
        }

    }
