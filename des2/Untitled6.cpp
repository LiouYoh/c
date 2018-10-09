/*範例檔名：file_inp.cpp*/

#include <fstream>

#include <stdlib.h>

#include <iomanip>

int main()                      //主程式開始

{

        fstream file;

        char str[8];

        int id;

        file.open("Reader.txt", ios::in);        //將檔案開啟為輸入狀態

        if(!file)     //檢查檔案是否成功開啟

        {

                cerr << "Can't open file!\n";

                exit(1);     //在不正常情形下，中斷程式的執行

        }

        cout << setw(4) << setiosflags(ios::right) << "ID"

                        << setw(8) << setiosflags(ios::right) << "Name" << endl;

        cout << "-------------------\n";

        while(file >> id >> str)     //讀取記錄，若讀取至檔案結尾則傳回0

                        cout << setw(4) << setiosflags(ios::right) << id

                                        << setw(8) << setiosflags(ios::right) << str << endl;

                //從檔案讀取資料
	return 0;
}      //主程式結束
