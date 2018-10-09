#include <stdio.h>
#include <stdlib.h>
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
int sumList(point head){
	int sum=0;
	point temp = head;
	while(temp!=NULL){
		sum=sum+temp->data;
		temp=temp->next;
		
	}
	return sum;
}
void print(point head){
	point temp=head;
	while(temp!=NULL){
		printf("\t%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
double averageList(point head){
	int total=sumList(head);
	int times=0;
	point tem=head;
	while(tem!=NULL){
		times++;
		tem=tem->next;
	}
	double answer=(double) total/times;
	return answer;
}
void BubbleSort(int* array, int length)
{
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
void dele(point *head,int item){
	point temp=*head;
	point deleNode=temp->next;
	if(temp->next==NULL){
		if(temp->data==item){
			*head=NULL;	
		}
	}
	else{
		if(temp->data==item){
			*head=temp->next;
		}
		else{
			while(deleNode->data!=item){
				temp=temp->next;
				deleNode=temp->next;
			}
			if(deleNode->next==NULL){
				temp->next=NULL;
			}
			else{
				temp->next=deleNode->next;
			}
		}
		
		
	}
	
}
int main(){
	point head=NULL;
	int number[80];
	int input,i;
	printf("how many number would you input : ");
	scanf("%d",&input);
	for(i=0;i<input ;i++){
		printf("please input the %d number :",i+1);
		scanf("%d",&number[i]);
	}
	BubbleSort(number,input);
	for(i=0;i<input ;i++){
		insert(&head,number[i]);
		
	}
	printf("print all element :");
	print(head);
	printf("total is :%d\n",sumList(head));
	printf("average is :%g\n",averageList(head));
	
	int a;
	printf("which number do you want to delete:");
	scanf("%d",&a);
	dele(&head,a);
	print(head);
	return 0;
}
