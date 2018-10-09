#include <stdio.h>
#include <math.h>
struct vector{
	int x;
	int y;
};
struct vector v_add(struct vector a, struct vector b){
	struct vector temp;
	temp.x=a.x+b.x;
	temp.y=a.y+b.y;
	return temp;
}
double v_length(struct vector a){
	return sqrt(pow(a.x,2)+pow(a.y,2));
	
}
struct vector v_scalar(struct vector temp, int a){
	temp.x=temp.x*a;
	temp.y=temp.y*a;
	return temp;
}
int main(){
	struct vector u,v;
	printf("input u<x,y>\n");
	printf("x=");
	scanf("%d",&u.x);
	printf("y=");
	scanf("%d",&u.y);
	printf("input v<x,y>\n");
	printf("x=");
	scanf("%d",&v.x);
	printf("y=");
	scanf("%d",&v.y);
	printf("u+v = <%d,%d>\n",v_add(u,v).x,v_add(u,v).y);
	printf("length of u= %.2f \n",v_length(u));
	printf("3*v = < %d ,%d >\n",v_scalar(v,3).x,v_scalar(v,3).y);

	return 0;
}
