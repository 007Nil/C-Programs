#include <stdio.h>
#define MAXSIZE 5



struct stack            /* Structure definition for stack */
{
    int stk[MAXSIZE];
    int num;
    int top;
} s;

void push ();
void pop();
void display ();
void search();
void options_for_user ();


int main()
{

int choice;

s.top = -1;

while (1)  //Loop End at line 52
    {
        options_for_user();

        printf ("Enter your choice\n");
        scanf   ("%d", &choice);

        switch (choice)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: search();
                break;
            case 5:
            return 0;
            default :
               printf("Not a Valid option\n");
        } /*End of switch case*/


} /*End of while loop */

} //End of main function

void options_for_user()
{
        printf ("------------------------------------------\n");
        printf ("1. PUSH/INPUT\n");
        printf ("2. POP/DELETE\n");
        printf ("3. DISPLAY ELEMETS IN STACK\n");
        printf ("4. SEARCH\n");
        printf ("5. EXIT\n");
        printf ("------------------------------------------\n");
}

/*Function to add an element to the stack*/
void push() {

    if (s.top == (MAXSIZE - 1))
    {
        printf ("Error: Overflow\n");
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &s.num);
        s.top = s.top + 1;
        s.stk[s.top] = s.num;  //accessing Golbar Struc
    } //End of 'IF ELSE' STATEMENT
}


/*Function to delete an element from the stack*/
void pop ()
{

    if (s.top == - 1)
    {
        printf ("Error: Stack Empty\n");
    }
    else
    {
        s.num = s.stk[s.top];
        printf ("poped element is = %d\n", s.num);
        s.top = s.top - 1;
    }
}



/*Function to display the status of the stack*/
void display()
{
    int i;
    if (s.top == -1)
    {
        printf ("Error: Stack Empty\n");
    }
    else
    {
        printf ("\nItems in Stack\n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}


void search(){

    int i;
    //int num;
    int counter=0;
    if (s.top == -1)
    {
        printf ("Error: Stack Empty\n");
    }
    else
    {
        printf ("Enter the element to be searched\n");
        scanf ("%d", &s.num);

        for (i = s.top; i >= 0; i--)
        {
            if(s.num==s.stk[i]) {
            counter++;
            break;
            }
        }

        if(counter>0){
            printf ("Element %d found in stack\n", s.num);
        }
        else {
            printf ("Element %d not found in stack\n", s.num);
        }
    }
    printf ("\n");

}
