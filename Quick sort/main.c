#include <stdio.h>

void quick_sort(int[],int,int);
int partition(int[],int,int);

int main()
{
	int a[50],n,i;
	printf("How many elements?");
	scanf("%d",&n);
	printf("\nEnter array elements:");

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	quick_sort(a,0,n-1);
	printf("\nArray after sorting:");

	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	return 0;
}

void quick_sort(int a[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,h);
	}
}

int partition(int a[],int l,int h)
{
	int pivote,i,j,temp;
	pivote=a[l];
	i=l;
	j=h+1;

	do
	{
		do
			i++;

		while(a[i]<pivote&&i<=h);

		do
			j--;
		while(pivote<a[j]);

		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);

	a[l]=a[j];
	a[j]=pivote;

	return(j);
}
