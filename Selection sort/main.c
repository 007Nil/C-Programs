#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[50];
    int i,j,n,temp,min;
    printf("Enter the array size : ");
    scanf("%d",&n);

    for(i=0; i<n ; i++){
        printf("Enter the %d array elements :",i);
        scanf("%d",&array[i]);
    }
    printf("The array elements are :");
    for(i=0; i<n; i++){
        printf(" %d",array[i]);
    }
    printf("\n\n");
    for(i=0; i<n; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
    }
    printf("The sorted array is :");
    for(i=0; i<n; i++){
        printf(" %d",array[i]);
    }
    return 0;
}
