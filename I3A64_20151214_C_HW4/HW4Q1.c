#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct node node;
typedef struct node *point;
struct node{
	int data;
	point next;
};
void insert (point *head,int item){
	point temp=*head;
	point newone=malloc(sizeof(struct node));
	if(*head){
		while(temp->next!=NULL){
			temp=temp->next;
		}
		newone->data=item;
		newone->next=NULL;
		temp->next=newone;
	}
	else{
		newone->data=item;
		newone->next=NULL;
		*head=newone;
	}
	
}


void BubbleSort(int* array, int length){
	int i;
    for (i = length - 1; i > 0; --i){
    	int j;
		for (j = 0; j < i; ++j)
            if (array[j] > array[j + 1]){
            	int temp;
            	temp=array[j];
            	array[j]=array[j+1];
            	array[j+1]=temp;
			}
               
	}
        
}
void print(point head){
	point temp=head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	int a[7]={0,0,0,0,0,0,0};
	int i;
	for(i=0;i<7;i++){
		while(1){
			int num,flag=1;
			int temp=i;
			srand(time(NULL));
			num=rand()%49+1;
			while(temp>=0){
				if(num==a[temp]){
					flag=0;
					break;
				}
				temp--;
			}
			if (flag==1){
				a[i]=num;
				break;
			}
		}
		
	}
	printf("開獎球如下:\n");
	point head=NULL;
	for(i=0;i<7;i++){
		insert(&head,a[i]);
	}
	print(head);
	
	return 0;
}
