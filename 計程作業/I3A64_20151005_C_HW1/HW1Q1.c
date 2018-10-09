#include <stdio.h>

void printfstar(int a){
	printf("%c%c%c",'*','*','*');
	int k;
	for(k=1;k<=a;k++){
		printf("%c",' ');
	}
	printf("%c%c%c\n",'*','*','*');
}

void printfx(int k){
	int i,j;
	int a=k;
	int temp=a/2;
	
	int s;
	for(i=1;i<a-1;i++){
		printf("%c%c%c",' ',' ',' ');
		for(j=1;j<a;j++){	
			if(j<=temp&&i<=temp){
				if(i==j){
					printf("%c",'*');	
				}
				else{
					printf("%c",' ');
				}
			}
			if(j<temp&&i>temp)
				if(i+j==a-1){
					printf("%c",'*');
				}
				else{
					printf("%c",' ');
				}
			if(j>=temp&&i<=temp){
				if(j+i==a){
					printf("%c",'*');	
				}
				else{
					printf("%c",' ');
				}
			}
			if(j>temp-2&&i>temp){
				if(i+1==j){
					printf("%c",'*');
				}
				else{
					printf("%c",' ');
				}
			}
				
			
		}
		printf("\n");
	}		
}


int main(){
	
	int a;
	do{
		printf("input the number");
		scanf("%d",&a);
		if(a%2==1){
			printfstar(a);
			printfx(a);
			printfstar(a);
			break;
		}
	}while(1);
	
	
	
	
		
	system("pause");
	return 0;
	
}
