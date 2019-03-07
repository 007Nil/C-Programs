/*Stack Implementation using static array*/
#include <stdio.h>

#define CAPACITY 5 //Pre-process macro
int stack[CAPACITY];
int top = -1;


int userDisplay ();
int choiceOptions (int);
int push (int);
int isFull();
int pop ();
int isEmpty();
int peek ();
int display();


int main()
{
    int choice;
    while (1)
    {
        userDisplay();
        printf("Enter Your Choice :");
        scanf ("%d", &choice);
        choiceOptions(choice);
    }

}

int userDisplay()
{
    printf("1.Push \n");
    printf("2.Pop \n");
    printf("3.Peek \n");
    printf("4.Display all items in stack \n");
    printf("5.Quit\n");

    return 0;
}

int choiceOptions(int choice)
{
    int item;
    switch (choice)
    {
        case 1:
                printf("Enter element :");
                scanf ("%d",&item);
                push  (item);
                break;
        case 2:
                 item = pop();
                 if (item == 0)
                    {
                        printf("Stack is underflow\n");
                        printf("\n \n");
                    }
                else
                    {
                        printf("Deleted item is %d",item);
                    }
                break;
        case 3 : peek ();
                 break;
        case 4 : display ();
                break;
        case 5 : exit(0);
                break;
        default :
                    printf("Invalide Input \n\n");
                    printf("\n \n");
    }
    return 0;
}

int push(int element)
{
    if (isFull())
    {
        printf("Stack is overflow \n");
        printf("\n \n");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("%d inserted into stack\n",element);
        printf("\n \n");
    }
    return 0;
}

int isFull()
{
    if( top == CAPACITY-1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

int isEmpty()
{
    if (top == -1 )
        {
            return 1;
        }
    else
        {
            return 0;
        }
    return 0;
}

int peek()
{
    if(isEmpty())
        {
            printf("Stack is Empty");
            printf("\n \n");
        }
    else
        {
            printf("peek element : %d \n", stack[top]);
            printf("\n \n");
        }
    return 0;
}

int display()
{
    if(isEmpty())
        {
            printf("stack is empty\n\n");
        }
    else
        {
            int i;
            printf("stack elementys are \n");
            for (i=0 ; i<= top ; i++)
                {
                    printf("%d \n" , stack[i]);
                }
            printf("\n\n");
        }
    return 0;
}











