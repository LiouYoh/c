//#include <stdio.h>
//#include "myConio.h"
//#import "myConio.c";
//int main(){
//	
//	printf("hello");
//	return 0;
//} 

//#include <conio.h>
//int main(){ 
//	int c ; 
//	while(1){ 
//		c = getch(); 
//		if(c==0) 
//			c =getch(); // getch�b�J���V��ɷ|��^0�A�ϥ�getch�K�|��^���y�X
//		if( c == 72 ) 
//			printf("UP\n"); //�����A��W�U���k�ƾڽեX�ӧA�Ϊ��ɭ�define��UP�Өϥγo�ӭȴN�i�H�F
//		if ( c == 80) 
//			printf("DOWN\n"); 
//		if ( c == 75) 
//			printf("LEFT\n"); 
//		if ( c == 77) 
//			printf("RIGHT\n"); 
//		if(c == 113) //��q�h�X
//			break; 
//	}		 
//	return 0; 
//}


    #include<stdio.h>
    #include <windows.h>
    /*
    *�\��G
        ��X�m��r�Ŧ�
    *��J�ѼơG
        color:�C���ܡA1 red, 2 green, 3 yellow, default white
        str: �m��r�Ŧ�
    */
    void printColorStr(int color, char *str)
    {
        HANDLE hd;

        hd = GetStdHandle(STD_OUTPUT_HANDLE);
        switch(color)
        {
            case 1: //red
                SetConsoleTextAttribute(hd,
                                        FOREGROUND_RED |
                                        FOREGROUND_INTENSITY);
                break;
            case 2: //green
                 SetConsoleTextAttribute(hd,
                                    FOREGROUND_GREEN |
                                    FOREGROUND_INTENSITY);
                break;
            case 3: //yellow
                SetConsoleTextAttribute(hd,
                                    FOREGROUND_RED | 
                                    FOREGROUND_GREEN |
                                    FOREGROUND_INTENSITY);
                break;
            default: //white
                SetConsoleTextAttribute(hd,
                                    FOREGROUND_RED | 
                                    FOREGROUND_GREEN | 
                                    FOREGROUND_BLUE);
        }

        printf("%s",str);
    }


    int main()
    {

        printColorStr(1, "hi");
        printf("\n");
        printColorStr(0,"ha");
        return 0;
    }
