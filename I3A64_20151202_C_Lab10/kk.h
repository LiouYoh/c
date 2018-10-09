#include <stdio.h>
struct date_t{          //���
   int day, 
       month, 
       year; 
}; 
 
struct meats_t{            //�����B�~��T
   char    meat_type;       //�H�r����ܦת������A'R'=���סA'P'=�a�V�סA'F'=����
   struct date_t  packaging_date;  //�]�ˤ��
   struct date_t  expiration_date; //���Ĥ��
}; 
 
struct produce_t{            //�A���~�B�~��T
   char    produce_type;    //�r�� 'F'=���G�A'V'=����
   struct date_t  received_date;   //�Ħ����
};  
 
struct dairy_t{             //���s�~�B�~��T
   struct date_t expiration_date;   //���Ĥ��
}; 
 
struct canned_t{             //���Y�B�~��T
   struct date_t  expiration_date;  //���Ĥ��(�u���~�B��)
   int     aisle_number;     //���D�s��(���)
   char    aisle_side;       //���D��V(�r��'A'�� 'B')
};  
 
struct non_foods_t{             //�D���~���B�~��T
   char  category;           //�r����ܺ��� ('C'=�M��Ϋ~�A'P'=�ĥ����A'O'=�䥦)
   int   aisle_number;       //���D�s��(���)
   char  aisle_side;         //���D��V(�r��'A'�� 'B')
}; 
 
struct category_t{              //�f�~����
   struct meats_t      meats;        //����
   struct produce_t    produce;      //�A���~
   struct dairy_t      dairy;        //���s�~
   struct canned_t     canned_goods; //���Y
   struct non_foods_t  non_foods;    //�D���~��
}; 

struct item_t{                          	  //�f�~���
   char        item_name[20];   			//�f�~�W��
   int         unit_cost;                   //�f�~���
   char        product_category;            //�f�~����
   struct category_t category;                    //���P�f�~�������B�~��T
}; 
 
