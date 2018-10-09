#include <stdio.h>
//i3a64
int main(){
	
	char item[100];
	char *loca;

	char des[10];
	printf("請輸入產品碼:");
	scanf("%s",item);
	
	int k=0,sum=0;
	
	if(item[0]=='D'){
		
		loca="DShui";
		printf("產品所在倉庫: %s\n",loca);
		int i=5;
		char idtemp[100];
		while(item[i]>=48&&item[i]<=57){
			idtemp[i-5]=item[i];
			i++;
		}
		idtemp[i-5]='\0';
		printf("產品序號: %s\n",idtemp);
		char des[10];
		int z=0;
		while(item[i]!='\0'){
			des[z]=item[i];
			z++;
			i++;
		}
		des[z]='\0';
		printf("產品樣式: ");
		puts(des);
		
		
		
	}
	if(item[0]=='Z'){
		char loca[10]="ZXinsheng";
		printf("產品所在倉庫: %s\n",loca);
		int i=9;
		char idtemp[100];
		while(item[i]>=48&&item[i]<=57){
			
			idtemp[i-9]=item[i];
			i++;
		}
		idtemp[i-9]='\0';
		printf("產品序號: %s\n",idtemp);
		char des[10];
		int z=0;
		while(item[i]!='\0'){
			des[z]=item[i];
			z++;
			i++;
		}
		des[z]='\0';
		printf("產品樣式: ");
		puts(des);
	}
	if(item[0]=='T'){
		char loca[10]="TMS";
		printf("產品所在倉庫: %s\n",loca);
		int i=3;
		char idtemp[100];
		while(item[i]>=48&&item[i]<=57){
			
			idtemp[i-3]=item[i];
			i++;
		}
		idtemp[i-3]='\0';
		printf("產品序號: %s\n",idtemp);
		char des[10];
		int z=0;
		while(item[i]!='\0'){
			des[z]=item[i];
			z++;
			i++;
		}
		des[z]='\0';
		printf("產品樣式: ");
		puts(des);
	}
	
	
	if(item[0]=='X'){
		char loca[10]="XDian";
		printf("產品所在倉庫: %s\n",loca);
		int i=5;
		char idtemp[100];
		while(item[i]>=48&&item[i]<=57){
			
			idtemp[i-5]=item[i];
			i++;
		}
		idtemp[i-5]='\0';	
		printf("產品序號: %s\n",idtemp);
		char des[10];
		int z=0;
		while(item[i]!='\0'){
			des[z]=item[i];
			z++;
			i++;
		}
		des[z]='\0';
		printf("產品樣式: ");
		puts(des);
	}
	
	return 0;
}
