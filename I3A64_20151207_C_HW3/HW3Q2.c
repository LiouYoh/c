#include <stdio.h>
#include <string.h>
 
struct grade{
	int co_num;  //�Y�ǥͪ��ҵ{�ƥ�
	int g[10];  //���@�Ӱ}�C�x�s�U�ҵ{�����Z
	double average;  //�Ӿǥͪ��������Z
};

struct student{
	char name[10];  //�ǥͩm�W
	struct grade gd;
};
int main(){
	struct student first;
	printf("�п�J�ǥͩm�W:");
	gets(first.name);
	fflush(stdin);
	printf("�п�J�ҵ{�ƥ�:");
	scanf("%d",&first.gd.co_num);
	fflush(stdin);
	int i,sum=0;
	for(i=0;i<first.gd.co_num;i++){
		printf("�п�J��%d�Ӧ��Z:",i+1);
		scanf("%d",&first.gd.g[i]);
		fflush(stdin);
		sum+=first.gd.g[i];
	}
	first.gd.average=(double)sum/first.gd.co_num;
	printf("%s���������Z��:%.1f",first.name,first.gd.average);
	return 0;
}                                                       
