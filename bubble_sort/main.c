#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[50],temp,i,j,n;
    printf("Enter length of the array :");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter the %d array values :",i);
        scanf("%d",&array[i]);
    }
    printf("The entered array is : \n");
    for( i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");


    for(i=0; i<n; i++){
        for(j=0; j< n-1-i; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

            }
        }
    }
    for (i =0; i<n; i++)
    printf("%d ",array[i]);
    return 0;
}
