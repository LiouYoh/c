#include <stdio.h>
#include <string.h>
 
struct grade{
	int co_num;  //某學生的課程數目
	int g[10];  //為一個陣列儲存各課程的成績
	double average;  //該學生的平均成績
};

struct student{
	char name[10];  //學生姓名
	struct grade gd;
};
int main(){
	struct student first;
	printf("請輸入學生姓名:");
	gets(first.name);
	fflush(stdin);
	printf("請輸入課程數目:");
	scanf("%d",&first.gd.co_num);
	fflush(stdin);
	int i,sum=0;
	for(i=0;i<first.gd.co_num;i++){
		printf("請輸入第%d個成績:",i+1);
		scanf("%d",&first.gd.g[i]);
		fflush(stdin);
		sum+=first.gd.g[i];
	}
	first.gd.average=(double)sum/first.gd.co_num;
	printf("%s的平均成績為:%.1f",first.name,first.gd.average);
	return 0;
}                                                       
