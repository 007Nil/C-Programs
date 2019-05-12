#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
    node *root = NULL;

    void Append();
    void Add_at_begin();
    void Add_in_middle();
    void display();
    int length ();
    void delete_node ();



    int main(){
        int choise;
    while(1){

        printf("\n Doubly Linked List Operations \n\n");
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
        printf("Enter the node data :");
        scanf("%d", &temp->data);
        temp->left = temp->right = NULL;

        if(root == NULL){
            root = temp;
        }
        else{
            node * p;
            p = root;
            while (p->right != NULL){
                p = p->right;
            }
            p->right = temp;
            temp->left =p;
        }

    }

    void Add_at_begin(){
        node *temp = NULL;
        temp = (node*)malloc(sizeof(node));
        printf("Enter node data :");
        scanf("%d",&temp->data);
        temp->right = temp->left =NULL;

        if (root == NULL)
            root = temp;
        else{
            temp->right = root;
            root->left = temp;
            root = temp;
        }
    }

    int length(){
        node *temp;
        int count = 0;
        temp = root;

        while(temp != NULL){
            count ++;
            temp = temp->right;
        }
        return count;
    }

    void Add_in_middle(){
        node *temp,*p;
        int location,i=1;
        printf("Enter the location of the node :");
        scanf("%d",&location);

        if(location > length()){
            printf("Invalid Option\n");
            printf("Currently Link List have %d nodes",length());
        }
        else{
            p = root;
            while(i < location){
                p = p->right;
                i++;
            }
            temp = (node*)malloc(sizeof(node));
            printf("Enter node data :");
            scanf("%d",&temp->data);
            temp->right = temp->left = NULL;

            temp->right = p->right;
            temp->right->left = temp;

            p->right = temp;
            temp->left = p;
        }
    }

    void display(){
        node * temp;
        temp = root;
        if (temp == NULL){
            printf("The Linked List is empty");
        }
        else{
            while(temp != NULL){
                printf("%d ->",temp->data);
                temp =temp->right;
            }
        }
    }

    void delete_node(){
        node *temp = NULL;
        int location,i=1;
        printf("Enter the Location you want to delete :");
        scanf("%d",&location);

        if(location > length()){
            printf("Invalid Location \n");
            printf("Currently Link List have %d locations",length());
        }
        else if(location == 1){
            temp = root;
            root= temp->right;
            root->left = NULL;
            free(temp);
        }
        else{
            node *p,*q;
            p = root;
            while(i > location){
                 p = p->right;
                 i++;
            }
            q = p->right;
            p->right = q->right;
            q->right->left = p;
            q->right = q->left = NULL;
            free(q);
        }
    }

