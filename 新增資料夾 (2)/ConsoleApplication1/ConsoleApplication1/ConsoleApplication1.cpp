#include <fstream.h>

#include <stdlib.h>  //使用exit須載入stdlib標頭檔

int main()                      //主程式開始

{

	fstream file;

	char *str[4] = { "Mary","John","Judy","Joe" };  //宣告字串指標陣列

	int id[4] = { 100,200,300,400 };

	file.open("Reader.txt", ios::out);      //開啟檔案

	if (!file)     //檢查檔案是否成功開啟

	{

		cerr << "Can't open file!\n";

		exit(1);     //在不正常情形下，中斷程式的執行

	}

	for (int i = 0; i < 4; i++) {

		file << id[i] << " " << str[i] << "\n";

	}      //將資料輸出至檔案
	return 0;
}      //主程式結束
