#include <fstream.h>

#include <stdlib.h>  //�ϥ�exit�����Jstdlib���Y��

int main()                      //�D�{���}�l

{

	fstream file;

	char *str[4] = { "Mary","John","Judy","Joe" };  //�ŧi�r����а}�C

	int id[4] = { 100,200,300,400 };

	file.open("Reader.txt", ios::out);      //�}���ɮ�

	if (!file)     //�ˬd�ɮ׬O�_���\�}��

	{

		cerr << "Can't open file!\n";

		exit(1);     //�b�����`���ΤU�A���_�{��������

	}

	for (int i = 0; i < 4; i++) {

		file << id[i] << " " << str[i] << "\n";

	}      //�N��ƿ�X���ɮ�
	return 0;
}      //�D�{������
