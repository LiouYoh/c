#include <stdio.h>


int main()
{
       
		int before=16,num[10];
		int i;
		
		for(i=0;i<10;i++){
	        	
        	num[i]=before%2;
        	before=before/2;
		}
		
		for(i=9;i>=0;i--){
			printf("%d",num[i]);
		}
		

        return 0;
}

