#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv) {
	
	srand(time(NULL));
	int num=rand()%100+1;
	int up=100,down;
	int guess;
	
	do{
		printf("input a number:");
		scanf("%d",&guess);
		if(guess==0){
			break;
		}
		else if(guess>num){
			printf("too high\n");
			up=guess;
			printf("range is %d ~ %d\n",down,up);
		}
		else if(guess<num){
			printf("too low\n");
			down=guess;
			printf("range is %d ~ %d\n",down,up);
		}	
		else{
			printf("good");
			break;
		}
			
	}while(true);
	
	return 0;
}
