/*�d���ɦW�Gfile_inp.cpp*/

#include <fstream>

#include <stdlib.h>

#include <iomanip>

int main()                      //�D�{���}�l

{

        fstream file;

        char str[8];

        int id;

        file.open("Reader.txt", ios::in);        //�N�ɮ׶}�Ҭ���J���A

        if(!file)     //�ˬd�ɮ׬O�_���\�}��

        {

                cerr << "Can't open file!\n";

                exit(1);     //�b�����`���ΤU�A���_�{��������

        }

        cout << setw(4) << setiosflags(ios::right) << "ID"

                        << setw(8) << setiosflags(ios::right) << "Name" << endl;

        cout << "-------------------\n";

        while(file >> id >> str)     //Ū���O���A�YŪ�����ɮ׵����h�Ǧ^0

                        cout << setw(4) << setiosflags(ios::right) << id

                                        << setw(8) << setiosflags(ios::right) << str << endl;

                //�q�ɮ�Ū�����
	return 0;
}      //�D�{������
