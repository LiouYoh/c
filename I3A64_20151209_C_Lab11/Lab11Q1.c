//i3a64«É§Ê
#include <stdio.h>
#include <string.h>
struct person{
    char name[10], sex, hair[8], eye[8], religion[15];
    int height, weight;
}a[10];	
struct person setPerson(){
	struct person temp;
	printf("inpout the name:");
	gets(temp.name);
	fflush(stdin);
	printf("inpout the height:");
	scanf("%d",&temp.height);
	fflush(stdin);
	printf("input the weight:");
	scanf("%d",&temp.weight);
	fflush(stdin);
	printf("input the sex:");
	scanf("%c",&temp.sex);
	fflush(stdin);
	printf("input the hair:");
	gets(temp.hair);
	fflush(stdin);
	printf("input the eye:");
	gets(temp.eye);
	fflush(stdin);
	printf("input the religion:");
	gets(temp.religion);
	fflush(stdin);
	return temp;
	
}
void BubbleSort(struct person *arr,int arr_index){
 	int k,times,i;
 	struct person temp;
 
 	k=arr_index-1;
 	while(k!=0){ 
  		times=0;
  		for(i=0;i<=k-1;i++){
  			//strcmp(str_1,str_2,2);
  			if(strcmp(arr[i].name,arr[i+1].name)==1){
   			//if(arr[i].name>arr[i+1].name){
   				temp=arr[i]; 
				arr[i]=arr[i+1]; 
				arr[i+1]=temp;  /* arr[i]»Parr[i+1]¤¬´« */
     			times=i;
   			}
  		}
  		k=times;
 	}
}
int main(){
	int i;
	int many=4;
	for(i=0;i<many;i++){
		printf("set the %d one\n",i+1);
		a[i]=setPerson();
		printf("\n");
	}
	
	
	printf("\n");
	printf("\n");
	printf("Name\theight\tweight\tsex\thair\teye\treligion\n");
	printf("-----------------------------------------------------------\n");
	
	for(i=0;i<many;i++){
		printf("%s\t%d\t%d\t%c\t%s\t%s\t%s\n",a[i].name,a[i].height,a[i].weight,a[i].sex,a[i].hair,a[i].eye,a[i].religion);
	}
	BubbleSort(a,many);
	
	printf("\n");
	printf("\n");
	printf("Name\theight\tweight\tsex\thair\teye\treligion\n");
	printf("-----------------------------------------------------------\n");
	
	for(i=0;i<many;i++){
		printf("%s\t%d\t%d\t%c\t%s\t%s\t%s\n",a[i].name,a[i].height,a[i].weight,a[i].sex,a[i].hair,a[i].eye,a[i].religion);
	}
	return 0;
}
