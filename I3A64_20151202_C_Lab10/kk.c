#include <stdio.h>
struct date_t{          //日期
   int day, 
       month, 
       year; 
}; 
 
struct meats_t{            //肉類額外資訊
   char    meat_type;       //以字元表示肉的種類，'R'=紅肉，'P'=家禽肉，'F'=魚肉
   struct date_t  packaging_date;  //包裝日期
   struct date_t  expiration_date; //有效日期
}; 
 
struct produce_t{            //農產品額外資訊
   char    produce_type;    //字元 'F'=水果，'V'=蔬菜
   struct date_t  received_date;   //採收日期
};  
 
struct dairy_t{             //奶製品額外資訊
   struct date_t expiration_date;   //有效日期
}; 
 
struct canned_t{             //罐頭額外資訊
   struct date_t  expiration_date;  //有效日期(只有年、月)
   int     aisle_number;     //走道編號(整數)
   char    aisle_side;       //走道方向(字元'A'或 'B')
};  
 
struct non_foods_t{             //非食品類額外資訊
   char  category;           //字元表示種類 ('C'=清潔用品，'P'=藥用類，'O'=其它)
   int   aisle_number;       //走道編號(整數)
   char  aisle_side;         //走道方向(字元'A'或 'B')
}; 
 
struct category_t{              //貨品種類
   struct meats_t      meats;        //肉類
   struct produce_t    produce;      //農產品
   struct dairy_t      dairy;        //奶製品
   struct canned_t     canned_goods; //罐頭
   struct non_foods_t  non_foods;    //非食品類
}; 

struct item_t{                          	  //貨品資料
   char        item_name[20];   			//貨品名稱
   int         unit_cost;                   //貨品單價
   char        product_category;            //貨品種類
   struct category_t category;                    //不同貨品種類之額外資訊
}; 
 
