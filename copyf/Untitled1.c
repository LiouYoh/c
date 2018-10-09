#include <stdlib.h>
#include <stdio.h>
#include <string.h>
	
struct student{
  	char   stu_id[12];
  	int    ScoreComputer;
  	int    ScoreMath;
  	int    ScoreEng;
  	float  ScoreAvg;
};
 
FILE *fp;
 
void main(){
 	int score[3][3]={{89,84,75},{77,69,87},{65,68,77}};
	struct student IM[3];
 	int i,Total,num;
 
 	strcpy(IM[0].stu_id,"S9103501");
 	strcpy(IM[1].stu_id,"S9103502");
 	strcpy(IM[2].stu_id,"S9103503");
 	for(i=0;i<3;i++){
     	Total=0;
     	IM[i].ScoreComputer=score[i][0];
     	IM[i].ScoreMath=score[i][1];
     	IM[i].ScoreEng=score[i][2];
     	Total=score[i][0]+score[i][1]+score[i][2];
     	IM[i].ScoreAvg=((float)Total)/3;
 	}
 	if((fp = fopen("data4.exe", "w+b")) == NULL){
   		printf("檔案錯誤\n");
   		exit(1);
 	}
 	
	num = fwrite(IM,sizeof(struct student),3,fp);
 
 	printf("二進位檔寫入完成\n");
 	fclose(fp);
 	return 0;
}

