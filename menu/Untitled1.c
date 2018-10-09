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
//			c =getch(); // getch在遇到方向鍵時會返回0再使用getch便會返回掃描碼
//		if( c == 72 ) 
//			printf("UP\n"); //我幫你把上下左右數據調出來你用的時候define成UP來使用這個值就可以了
//		if ( c == 80) 
//			printf("DOWN\n"); 
//		if ( c == 75) 
//			printf("LEFT\n"); 
//		if ( c == 77) 
//			printf("RIGHT\n"); 
//		if(c == 113) //按q退出
//			break; 
//	}		 
//	return 0; 
//}


    #include<stdio.h>
    #include <windows.h>
    /*
    *功能：
        輸出彩色字符串
    *輸入參數：
        color:顏色選擇，1 red, 2 green, 3 yellow, default white
        str: 彩色字符串
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
