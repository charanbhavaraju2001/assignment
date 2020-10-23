//C program to Efficiently Sort an Array with many duplicate values (MergeSort)

#include<stdio.h>
#include<stdlib.h>
int *b;
void mergesort(int,int,int a[]);
void merge(int,int,int,int a[]);


int main()
{
	int *a, n, low = 0 , high,i,size;
	printf("Enter the number of array elements\n");
	scanf("%d",&size);
	a=(int *)malloc(size*sizeof(int));
	b=(int *)malloc(size*sizeof(int));
	n=size;
	high=n-1;
	printf("Enter the array elements\n");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("Array elements before sorting are\n");
	for(i=0;i<n;i++){
		printf("%d ", a[i]);
	}
	mergesort(low,high,a);
	printf("\nArray elements after sorting are\n");
	for(i=0;i<n;i++){
		printf("%d ", a[i]);
	}

	return 0;
}

void mergesort(int low,int high,int a[]){
	if(low<high){
	    int mid;
		mid = (low + high)/2;
		mergesort(low,mid,a);
		mergesort(mid+1,high,a);
		merge(low,mid,high,a);
	}

}

void merge(int  low,int mid , int high , int a[]){
	int i = low , j = mid + 1 , k = low;
	while (i <= mid && j<= high){
		if(a[i] <= a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i > mid){
		while(j<=high){
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			b[k]=a[i];
			k++;
			i++;
		}
	}
	for(k=0;k<=high;k++){
		a[k]=b[k];
	}
}
