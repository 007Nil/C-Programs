#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

    node *root = NULL;

    void Append ();
    void Add_in_begin ();
    void Add_in_middle();
    int length();
    void display();
    void delete_node(int);

    int main(){
        int choice;
        int key;
        while(1){
            printf("\n\n Double Linked List Operations \n\n");
            printf("1. Append \n");
            printf("2. Add Node at begin of list \n");
            printf("3. Add Node at middle of list \n");
            printf("4. Length of List");
            printf("5. Dislay all elements of list \n");
            printf("6. Delete Node of List \n");
            printf("7. Exit \n");

            printf("Enter your choice :");
            scanf("%d",&choice);

            switch(choice){
                case 1:
                    Append();
                    break;
                case 2:
                    Add_in_begin();
                    break;
                case 3:
                    Add_in_middle();
                    break;
                case 4:
                    printf("The length of List is %d \n",length());
                    break;
                case 5:
                    display();
                    break;
                case 6:
                     if (root == NULL){
                            printf("Currently node is empty so no nodes avalable for delete \n\n");
                        }
                        else{
                            printf("Enter the data you want to delete :");
                            scanf("%d",&key);
                            delete_node(key);
                        }
                        break;

                case 7:
                    exit(1);
                    break;
                default:
                    printf("Inavlide Choice \n\n");
            }

        }
        return 0;
    }

    void Append(){
        node *temp;
        temp = (node*)malloc(sizeof(node));
        printf("Enter the Node Data :");
        scanf("%d",&temp->data);
        temp->left = NULL;
        temp->right = NULL;

        if( root == NULL){
            root = temp;
        }
        else{
            node *p;
            p =root;
            while(p->right != NULL){
                p = p->right;
            }
            p->right = temp;
            temp->left =temp;
        }
    }
    void Add_in_begin(){
        node *temp;
        temp = (node *)malloc(sizeof(node));
        printf("Enter the node value :");
        scanf("%d",&temp->data);
        temp->left = NULL;
        temp->right = NULL;

        if( root == NULL){
            root = temp;
        }
        else{
            temp->right = root;
            root->left = temp;
            root = temp;
         }
    }

    int length(){
        int count_node;
        node *temp = root;
        while(temp != NULL){
            temp = temp->right;
            count_node++;
        }
        return count_node;
    }

    void Add_in_middle(){
        if ( root == NULL){
            printf("Currentlty node is emply enter atlast two nodes to perform this opertaion \n");
        }
        else{
             int location, i =1;
             node *temp;
             printf("Enter the location :");
             scanf("%d", &location);
             if( location > length()){
                 printf("Enter a valid location \n");
                 printf("Currently List have  %d nodes",length());
             }
             else{
                 node *p;
                 temp = (node*)malloc(sizeof(node));
                 printf("Enter the node data :");
                 scanf("%d", &temp->data);
                 temp->left = temp->right = NULL;

                 while ( i < location){
                    p = p->right;
                    i++;
                 }
                 temp->right = p->right;
                 p->right->left = temp;
                 p->right = temp;
                 temp->left = p;
             }
        }
    }

    void display(){
        node *temp = root;
        while (temp != NULL){
            printf("%d >>",temp->data);
            temp = temp->right;
        }
    }

    void delete_node(int node_data){
        node *temp = root;

            while(temp->right != NULL && temp->right->data != node_data){
            temp = temp->right;
            }
            if (temp->right == NULL){
                printf("Element %d is not found in list",node_data);
                }
            else{
                if(temp->right->right != NULL){
                     node *p = temp->right;
                     temp->right = p->right;
                     (p->right)->left = temp;

                      free(p);
                }
                if( temp->right->right == NULL){  // for deteing the last node from list
                    node *p = temp->right;
                    temp->right = NULL;
                    free(p);
                }

            }
    }
