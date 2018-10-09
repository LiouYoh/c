#include <stdio.h>
int main(){
	int n, p, d;	
	scanf("%d",&n);
	scanf("%d",&p);
	scanf("%d",&d);
	int ans = 1;
	int i;
	for(i=1; i<=p; i++)
	{
		ans = ans*n;
		ans %= d;
	}
	printf("%d",ans);
	return 0;
}
