#include<stdio.h>
#include<stdlib.h>
#include <time.h>
struct Page
{
	int page_no;
}frames[7];
int faults=0,q,p,n,page_no,flag=0;			
int page_found(int page_no)
{
	for(q=0;q<n;q++)
	{
		if(frames[q].page_no == page_no)
			return q;	  
	}
	return 'a';
}

int main()
{
	int len;					 
	srand ( time(NULL));
	printf("Enter number of pages (b/w 0 to 9) :");
	scanf("%d",&len);
	if(len<0 || len>9)
	{
		printf("\nInput out of bounds.\n");
		exit(0);
	}
	int *arr = (int *)malloc(len*sizeof(int));
	for (int q=0;q<len;q++)
	{
		arr[q] = ( rand()%9 )+1 ;
	}
	printf("\nEnter no of frames (b/w 1 to 7) :");
	scanf("%d",&n);
	if(n<1 || n>7)
	{
		printf("\nInput out of bounds.\n");
		exit(0);
	}
	printf("Length:%d",len);
	for (q=0;q<n;q++)
	{
		frames[q].page_no = -1;		   
	}
	printf("\n Page no     page frames     page faults     fault count");
	printf("\n-----------------------------------------------------------");
	for(p=0;p<len;p++)
	{
		page_no = arr[p];
		flag=0;  
		if(page_found(page_no) == 'a')			
		{
			frames[faults%n].page_no = page_no;
			faults++;
			flag=1;
		}
		printf("\n%5d\t",page_no);
		printf("\t");
		for(q=0;q<n;q++)
		{
			printf("%d ",frames[q].page_no);
		}
		if(flag==1)
		{
			printf("\t\t MISS");
		}	
		else
		{
			printf("\t\t HIT");
		}
		printf("\t\t%d",faults);
	}
	printf("\n------------------------------------------------------------");
	printf("\nTotal page faults:%d", faults);
	free(arr);
	return 0;
}
