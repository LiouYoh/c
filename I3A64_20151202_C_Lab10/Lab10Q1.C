#include <stdio.h>
#include <string.h>
//#include <kk.h>
#import "kk.c";

//struct date_t{          //日期
//   int day, 
//       month, 
//       year; 
//}; 
// 
//struct meats_t{            //肉類額外資訊
//   char    meat_type;       //以字元表示肉的種類，'R'=紅肉，'P'=家禽肉，'F'=魚肉
//   struct date_t  packaging_date;  //包裝日期
//   struct date_t  expiration_date; //有效日期
//}; 
// 
//struct produce_t{            //農產品額外資訊
//   char    produce_type;    //字元 'F'=水果，'V'=蔬菜
//   struct date_t  received_date;   //採收日期
//};  
// 
//struct dairy_t{             //奶製品額外資訊
//   struct date_t expiration_date;   //有效日期
//}; 
// 
//struct canned_t{             //罐頭額外資訊
//   struct date_t  expiration_date;  //有效日期(只有年、月)
//   int     aisle_number;     //走道編號(整數)
//   char    aisle_side;       //走道方向(字元'A'或 'B')
//};  
// 
//struct non_foods_t{             //非食品類額外資訊
//   char  category;           //字元表示種類 ('C'=清潔用品，'P'=藥用類，'O'=其它)
//   int   aisle_number;       //走道編號(整數)
//   char  aisle_side;         //走道方向(字元'A'或 'B')
//}; 
// 
//struct category_t{              //貨品種類
//   struct meats_t      meats;        //肉類
//   struct produce_t    produce;      //農產品
//   struct dairy_t      dairy;        //奶製品
//   struct canned_t     canned_goods; //罐頭
//   struct non_foods_t  non_foods;    //非食品類
//}; 
//
//struct item_t{                          	  //貨品資料
//   char        item_name[20];   			//貨品名稱
//   int         unit_cost;                   //貨品單價
//   char        product_category;            //貨品種類
//   struct category_t category;                    //不同貨品種類之額外資訊
//}; 
// 
struct item_t set(){
	fflush(stdin);
	
	struct item_t temp;
	char product;
	printf("Enter product category <M,P,D,C,N> >");
	scanf("%c",&product);
	fflush(stdin);
	if(product=='M'){
		temp.product_category='M';
		printf("Enter item name >");
		gets(temp.item_name);
		printf("Enter cost of item <in cents> >");
		scanf("%d",&temp.unit_cost);
		fflush(stdin);
		char m;
		printf("Enter meat type<R,P,F> >");
		scanf("%c",&m);
		fflush(stdin);
		if(m=='R'){
			temp.category.meats.meat_type='R';
		}
		if(m=='P'){
			temp.category.meats.meat_type='P';
		}
		if(m=='F'){
			temp.category.meats.meat_type='F';
		}
		
		printf("Enter date of packaging <day month year> >");
		scanf("%d",&temp.category.meats.packaging_date.day);
		//fflush(stdin);
		scanf("%d",&temp.category.meats.packaging_date.month);
		//fflush(stdin);
		scanf("%d",&temp.category.meats.packaging_date.year);
		//fflush(stdin);
		
		
		printf("Enter date of expiration <day month year> >");
		scanf("%d",&temp.category.meats.expiration_date.day);
		//fflush(stdin);
		scanf("%d",&temp.category.meats.expiration_date.month);
		//fflush(stdin);
		scanf("%d",&temp.category.meats.expiration_date.year);
		//fflush(stdin);
		
	}
	if(product=='P'){
		temp.product_category='P';
		printf("Enter item name >");
		gets(temp.item_name);
		printf("Enter cost of iitem <in cents> >");
		scanf("%d",&temp.unit_cost);
		fflush(stdin);
		char p;
		printf("Enter product type <F,V> >");
		scanf("%c",&p);
		fflush(stdin);
		if(p=='F'){
			temp.category.produce.produce_type='F';
		}
		if(p=='V'){
			temp.category.produce.produce_type='V';
		}
		printf("Enter date received <day month year> >");
		scanf("%d",&temp.category.produce.received_date.day);
		//fflush(stdin);
		scanf("%d",&temp.category.produce.received_date.month);
		//fflush(stdin);
		scanf("%d",&temp.category.produce.received_date.year);
		//fflush(stdin);	
	}
	if(product=='D'){
		temp.product_category='D';
		printf("Enter item name >");
		gets(temp.item_name);
		printf("Enter cost of item <in cents> >");
		scanf("%d",&temp.unit_cost);
		fflush(stdin);
		printf("Enter expiration date <day month year> >");
		scanf("%d",&temp.category.dairy.expiration_date.day);
	//	fflush(stdin);
		scanf("%d",&temp.category.dairy.expiration_date.month);
	//	fflush(stdin);
		scanf("%d",&temp.category.dairy.expiration_date.year);
	//	fflush(stdin);
	}
	if(product=='C'){
		temp.product_category='C';
		printf("Enter item name >");
		gets(temp.item_name);
		printf("Enter cost of item <in cents> >");
		scanf("%d",&temp.unit_cost);
		fflush(stdin);
		printf("Enter expiration date <month year> >");
		scanf("%d",&temp.category.canned_goods.expiration_date.month);
	//	fflush(stdin);
		scanf("%d",&temp.category.canned_goods.expiration_date.year);
	//	fflush(stdin);
		printf("Enter aisle number >");
		scanf("%d",&temp.category.canned_goods.aisle_number);
		fflush(stdin);
		
		char s;
		printf("Enter aisle side <A,B> >");
		scanf("%c",&s);
		if(s=='A'){
			temp.category.canned_goods.aisle_side='A';
		}
		if(s=='B'){
			temp.category.canned_goods.aisle_side='B';
		}
		
	}
	if(product=='N'){
		temp.product_category='N';
		printf("Enter item name >");
		gets(temp.item_name);
		printf("Enter cost of item <in cents> >");
		scanf("%d",&temp.unit_cost);
		fflush(stdin);
		
		char t;
		printf("Enter non food type<C,P,O> >");
		scanf("%c",&t);
		if(t=='C'){
			temp.category.non_foods.category='C';
		}
		if(t=='P'){
			temp.category.non_foods.category='P';
		}
		if(t=='O'){
			temp.category.non_foods.category='O';
		}
		
		printf("Enter aisle number >");
		scanf("%d",&temp.category.non_foods.aisle_number);
		fflush(stdin);
		printf("Enter aisle side <A,B> >");
		
		char s;
		scanf("%c",&s);
		if(s=='A'){
			temp.category.non_foods.aisle_side='A';
		}
		if(s=='B'){
			temp.category.non_foods.aisle_side='B';
		}
	} 
	
	return temp;
	
	
}
void get(struct item_t tem){
	printf("%s\t",tem.item_name);
	printf("%dC\t",tem.unit_cost);
	if(tem.product_category=='M'){
	printf("%c\t",tem.category.meats.meat_type);
	printf("%d\t%d\t%d\t",tem.category.meats.packaging_date.day,tem.category.meats.packaging_date.month,tem.category.meats.packaging_date.year);
	printf("%d\t%d\t%d\t",tem.category.meats.expiration_date.day,tem.category.meats.expiration_date.month,tem.category.meats.expiration_date.year);
	}
	if(tem.product_category=='P'){
		printf("%c\t",tem.category.produce.produce_type);
		printf("%d\t%d\t%d",tem.category.produce.received_date.day,tem.category.produce.received_date.month,tem.category.produce.received_date.year);
	}
	if(tem.product_category=='D'){
		printf("%d\t%d\t%d",tem.category.dairy.expiration_date.day,tem.category.dairy.expiration_date.month,tem.category.dairy.expiration_date.year);
	}
	if(tem.product_category=='C'){
		printf("%d\t%d\t",tem.category.canned_goods.expiration_date.month,tem.category.canned_goods.expiration_date.year);
		printf("%d%c",tem.category.canned_goods.aisle_number,tem.category.canned_goods.aisle_side);
	}
	if(tem.product_category=='N'){
		printf("%c\t",tem.category.non_foods.category);
		printf("%d",tem.category.non_foods.aisle_number);
		printf("%c",tem.category.non_foods.aisle_side);
	}
	printf("\n");
}
int main(){
	int i;
	int k=1;
	struct item_t item[5];
	for(i=0;i<k;i++){
		item[i]=set();
	}
	printf("\n\n");
	for(i=0;i<k;i++){
		get(item[i]);
	}
	return 0;
}
