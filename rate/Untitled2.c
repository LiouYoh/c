#include<stdio.h>
#include<math.h>
int main(){
	float formate=100;
	float rate;
	int times;
	printf("input rate:");
	scanf("%f",&rate); 
	printf("input times:");
	scanf("%d",&times); 
	int i=0;
	
	printf("years\t%3.f%%\t%3.f%%\t%3.f%%\t%3.f%%\t%3.f%%\n",rate,rate+1,rate+2,rate+3,rate+4);
	for(i=1;i<=times;i++){
		printf("%d\t%.2f\t%.2f\n",i,100*pow(1+(rate/100),i),100*pow(1+((rate+1)/100),i));
	}
	
	 
	return 0;
}
