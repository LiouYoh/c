#include <stdio.h>
//i3a64	�B�ɧ�

struct student{												//make the student informantion with id,answer,right answer and level
	int id;
	char answer[11];
	int goodAnswer;
	char level;
};

int correct(char right[],char answer[]){					//to check how many right answer does each student have
	int l=0;
	int sum=0;
	for(l=0;l<10;l++){
		if(right[l]==answer[l]){
			sum++;
		}
	}
	return sum;
}



int main(){
	
	int howManyStudent=2;								//can choose how many student you want
	char right[11];										//make the right answer 
	struct student st[howManyStudent];					//make the student array
	int loopi,loopj,loopk,loopl;
	int topGrade=0;										//check the student which get the most correct answer
	
	
	printf("��J���T�ѵ�:");							//input the correct answer
	scanf("%s",&right);
	
	printf("\n");
	
	printf("��J�C�Ӿǥ;Ǹ��P�񵪵��סG\n");			
 
	for(loopj=0;loopj<howManyStudent;loopj++){						//input the student informantion and check who gets the most correct answer
		scanf("%d %s",&st[loopj].id,st[loopj].answer);
		st[loopj].goodAnswer=correct(right,st[loopj].answer);
		if(st[loopj].goodAnswer>topGrade){
			topGrade=st[loopj].goodAnswer;
		}
	}

	for(loopk=0;loopk<howManyStudent;loopk++){												//to check the level 
		if(st[loopk].goodAnswer==topGrade||st[loopk].goodAnswer==topGrade-1){
			st[loopk].level='A';
		}
		else if(st[loopk].goodAnswer==topGrade-2||st[loopk].goodAnswer==topGrade-3){
			st[loopk].level='C';
		}
		else{
			st[loopk].level='F';
		}
	}
																								//here is output
	printf("���T���׬�:%s\n",right);
	printf("�Ǹ�\t����\t�����D��\t����\n");
	printf("------------------------\n");
	
	for(loopl=0;loopl<howManyStudent;loopl++){
		printf("%d\t%s\t%d\t%c\n",st[loopl].id,st[loopl].answer,st[loopl].goodAnswer,st[loopl].level);
	}

	
	
	return 0;
} 
