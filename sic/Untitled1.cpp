#include <iostream>
#include <fstream> 
#include <string> 

using namespace std; 
string Binary(string);//convert from hexadecimal to binary
string bin2hex(string);//convert from bin to hex
int calTA(string);
int bin2dec(string); //convert from binary to decimal
string int2bin(int);
string start,last,opcode,binn;
int start1,last1,pc;
    string line;
	string* mem;
	string mm[100];
	int l;
	string c="";//string about convert int to bin
	string hexx="";//string about convert bin to hex 
	string inst="";
	string A="000000"; // A register
	string L="000000";//L register
	string S="000000";//S register
	string SW="000000";//SW register
	string T="000000";//T register
	string B="000000";// base register
	string X="000000";//index register
	 string r1="0";
    string r2="0";
     int n=0;

    string PC;
	string binary, bin="";
	int TA;
	string indirect="";
	string temp="";
		int sum;
	string TA1;
	string str1,str2;
	int instnode;
	string nameio;//read the name of the device
	
int main ()
{
	
	

	mem = new string[10000];
	
	ifstream myfile("mem.txt");
	if(myfile.is_open())
	{
		int i = 0 ; 
		while(! myfile.eof())
		{
			

			getline(myfile,line);
			//cout << line<< endl; 
			//mem[0] = line;
			//cout << "memory location" << mem[0]<<endl; 

			if (line.substr(0,5) == "!_!_!")
			{
				if (line.substr(5,2) ==" S")
				{
				int pos = line.find("START = "); 
				start = line.substr(pos+8,5);
				l=start.length();
				
				Binary(start);
				binary=bin;
				bin="";
		
				bin2dec(binary);
			start1=sum;
			instnode=start1;
			
			sum=0;
				

				}
				if(line.substr(5,3) ==" LA")
				{
					int pos = line.find("LAST = ");
						last = line.substr(pos+7,5);
						l=last.length();
				
				Binary(last);
				binary=bin;
				bin="";
				bin2dec(binary);
			last1=sum;
			pc= start1;
			//cout<<start1<<endl;
			
			sum=0;
				}
								
			} 
			else
			{
                
				if (line.substr(0,5)!="!_!_!")
				{
			
				if((line.substr(2,1)=="_")&&(line.substr(5,1)=="_")&&(line.substr(8,1)=="_"))
				{
					line.replace(2,1,"");
					line.replace(4,1,"");
					line.replace(6,1,"");
				}
				if((line.substr(2,1)=="_")&&(line.substr(5,1)=="_"))
				{
                    line.replace(2,1,"");
					line.replace(4,1,"");
				}

				if(line.substr(2,1)=="_")
					 line.replace(2,1,"");
				
		 
				
				l= line.length();
				if (l==2)  //format 1
				{
					mem[instnode]=line.substr(0,2);
					instnode++;
				}
				if (l==4)  //format 2
				{
					mem[instnode]=line.substr(0,2);
                    instnode++;
					mem[instnode]=line.substr(2,2);
					instnode++;
				}
					if (l==6)  // format 3
					{
						
						
						mem[instnode]=line.substr(0,2);
						instnode++;
						mem[instnode]=line.substr(2,2);
						instnode++;
						mem[instnode]=line.substr(4,2);
						instnode++;
				
					}
					if (l==8)   // format 4
					{
						mem[instnode]=line.substr(0,2);
						instnode++;
						mem[instnode]=line.substr(2,2);
						instnode++;
						mem[instnode]=line.substr(4,2);
						instnode++;
						mem[instnode]=line.substr(6,2);
						instnode++;
					}
				
		
			}
				
				}


		}

		myfile.close(); 


	} 
	else 
	{
		cout <<  "error";
	} 
	pc=start1;
	while((pc<=last1)&&(pc>=start1))
	{
	opcode=mem[pc];	
	l=opcode.length();
	Binary (opcode);//convert from hexidecimal to binary
	opcode=bin; 


	bin="";
	 opcode.replace(6,2,"00");
	
		if (opcode=="10011000")    //MULR r1,r2
	{
		
		
		  inst=mem[pc]+mem[pc+1];
		  str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;
			 

		
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }

	  //----
	    if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }

	  //-----
	  int r;
		l=v1.length();
		 Binary (v1);
		 v1=bin;
		 bin="";

		  bin2dec(v1);
			r11=sum;
				sum=0;


         l=v2.length();
		 Binary (v2);
		 v2=bin;
		 bin="";

		 bin2dec(v2);
			r=sum;
				sum=0;
				
    r=r*r11;

   if (r==0)
		{ v2="000000";
   
   }

	 else
	{
		int2bin (r);
		 v2=c;
		 c="";
		
		 bin2hex(v2);
		 v2=hexx;
		 hexx="";
   }
	 
	 //------
	        if(r22==0)
	  {
		  A=v2;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r22==1)
	  {
		  X=v2;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r22==2)
	  {
		  L=v2;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r22==3)
	  {
		   B=v2;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r22==4)
	  {
           S=v2;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r22==5)
	  {
	  T=v2;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r22==8)
	  {
		  //pc=v2;
		//   cout<<pc<<endl;
	  }
	  else if(r22=9)
	  {
		    SW=v2;
		// cout<<"SW="<<SW<<endl;
	  }
	

		 
	}// end MULR


	  
 else if(opcode=="10101100")// RMO
	 {  
		
		  inst=mem[pc]+mem[pc+1];
		  str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }

	  //------
	    if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }

	  //-----


	  v2=v1;

	 
	 //------
	        if(r22==0)
	  {
		  A=v2;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r22==1)
	  {
		  X=v2;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r22==2)
	  {
		  L=v2;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r22==3)
	  {
		   B=v2;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r22==4)
	  {
           S=v2;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r22==5)
	  {
	  T=v2;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r22==8)
	  {
		  //pc=v2;
		//   cout<<pc<<endl;
	  }
	  else if(r22=9)
	  {
		    SW=v2;
		// cout<<"SW="<<SW<<endl;
	  }
	
	  }  //end rmo



 else if(opcode=="10010100")// subr r1,r2
	 {  
		
		 
		  inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

	

		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }

	  //------
	    if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }

	  //-----
	  int r;
		l=v1.length();
		 Binary (v1);
		 v1=bin;
		 bin="";

		  bin2dec(v1);
			r11=sum;
				sum=0;


         l=v2.length();
		 Binary (v2);
		 v2=bin;
		 bin="";

		 bin2dec(v2);
			r=sum;
				sum=0;
				
    r=r-r11;

   if (r==0)
		{ 
			v2="000000";
        }

   else if(r<0)
   {
	   //****** THE TWO'S COMPLEMENT ******
	   r=r*-1;
	
	int2bin (r);
		 r2=c;
		 c="";
		  l=r2.length();
		  	
	l=l-1;
	string ar=r2;

	
	  while(l>=0)
	  {
	   if (ar.at(l)=='1')
		  ar.replace(l,1,"0");

	   else //(ar.at(l)=='0')
	   ar.replace(l,1,"1");


	l=l-1;
	  }

	  r2=ar;

	  bin2dec(r2);
	r11=sum;
	sum=0;

	r11=r11+1;

	int2bin (r11);
		 v2=c;
		 c="";
		 bin2hex(v2);
		 v2=hexx;
		 hexx="";


   }// end twos

	 else if(r>0)
	{

		int2bin (r);
		 v2=c;
		 c="";
		
		 bin2hex(v2);
		 v2=hexx;
		 hexx="";
   }
	 //---------
   
	 //------
	        if(r22==0)
	  {
		  A=v2;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r22==1)
	  {
		  X=v2;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r22==2)
	  {
		  L=v2;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r22==3)
	  {
		   B=v2;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r22==4)
	  {
           S=v2;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r22==5)
	  {
	  T=v2;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r22==8)
	  {
		  //pc=v2;
		//   cout<<pc<<endl;
	  }
	  else if(r22=9)
	  {
		    SW=v2;
		// cout<<"SW="<<SW<<endl;
	  }
	
	  }//end sub



 else if(opcode=="10010000")// addr r1,r2
	 {  

		  inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

       
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }

	  //----
	    if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }

	  //-----
	  int r;
		l=v1.length();
		 Binary (v1);
		 v1=bin;
		 bin="";

		  bin2dec(v1);
			r11=sum;
				sum=0;


         l=v2.length();
		 Binary (v2);
		 v2=bin;
		 bin="";

		 bin2dec(v2);
			r=sum;
				sum=0;
				
    r=r+r11;

   if (r==0)
		{ v2="000000";
   
   }

	 else
	{
		int2bin (r);
		 v2=c;
		 c="";
		
		 bin2hex(v2);
		 v2=hexx;
		 hexx="";
   }
	 //------
	       
	 //------
	        if(r22==0)
	  {
		  A=v2;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r22==1)
	  {
		  X=v2;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r22==2)
	  {
		  L=v2;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r22==3)
	  {
		   B=v2;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r22==4)
	  {
           S=v2;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r22==5)
	  {
	  T=v2;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r22==8)
	  {
		  //pc=v2;
		//   cout<<pc<<endl;
	  }
	  else if(r22=9)
	  {
		    SW=v2;
		// cout<<"SW="<<SW<<endl;
	  }
	  
	
	
 }//end add 

 else if(opcode=="10110100")// clear r1
	 {  
	 inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;



		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  
		 str1=str1.substr(0,4);
		

         int r11;
			 string v1;

		 bin2dec(str1);
			r11=sum;
				sum=0;
	
		 v1="000000";
   
		 
	
	 //------
	        if(r11==0)
	  {
		  A=v1;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r11==1)
	  {
		  X=v1;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r11==2)
	  {
		  L=v1;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r11==3)
	  {
		   B=v1;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r11==4)
	  {
           S=v1;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r11==5)
	  {
	  T=v1;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r11==8)
	  {
		  //pc=v1;
		//   cout<<pc<<endl;
	  }
	  else if(r11=9)
	  {
		    SW=v1;
		// cout<<"SW="<<SW<<endl;
	  }
   


	  }//end clear

 else if(opcode=="10100000")// compr r1,r2
	 {  
	
		  inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }

	  //----
	    if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }


    if (v1>v2 )
	SW="000001";
	 if (v1==v2)
	SW="000000";
	if (v1<v2)
	SW="000002";
	

	  }//end compare

 else if(opcode=="10011100")// div
	 {  
		 
		   inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }

	  //----
	    if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }

	  //-----
	  int r;
		l=v1.length();
		 Binary (v1);
		 v1=bin;
		 bin="";

		  bin2dec(v1);
			r11=sum;
				sum=0;


         l=v2.length();
		 Binary (v2);
		 v2=bin;
		 bin="";

		 bin2dec(v2);
			r=sum;
				sum=0;

				if(r11==0)
				{ cout<<"error cant divide on zero"<<endl;}
				
				else
				{
    r=r/r11;

   if (r==0)
		{ v2="000000";
   
   }

	 else
	{
		int2bin (r);
		 v2=c;
		 c="";
		
		 bin2hex(v2);
		 v2=hexx;
		 hexx="";
   }
	 
	 //------
	        if(r22==0)
	  {
		  A=v2;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r22==1)
	  {
		  X=v2;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r22==2)
	  {
		  L=v2;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r22==3)
	  {
		   B=v2;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r22==4)
	  {
           S=v2;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r22==5)
	  {
	  T=v2;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r22==8)
	  {
		  //pc=v2;
		//   cout<<pc<<endl;
	  }
	  else if(r22=9)
	  {
		    SW=v2;
		// cout<<"SW="<<SW<<endl;
	  }
				}
 } //end div

 else if(opcode=="10101000")// shiftR
	 { 
		 
		   inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }
	  //

	   if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }

	  //-----
 l=v2.length();
		 Binary (v2);
		 v2=bin;
		 bin="";
		 
		 bin2dec(v2);
			r22=sum;
				sum=0;
	  n=r22+1;
	  

  //
	string ya;

 l=v1.length();
 Binary (v1);
	v1=bin;
 bin="";

    ya=v1;
	l=ya.length();
		
		
	l=l-1;

	string arr=ya;  //arr={v1 as binary string}
    char *p;
      p=&arr[0];


    int i=0;  //start doing the shiftR n times
   while (i<n)
	
   {
	   while (l>0)
	   {
	
     arr[l]=arr[l-1];

			   l=l-1;
	   }
	 
	   if(l==0)
		   arr[0]=arr[0];

	   i++;
	   l=ya.length();
	  l=l-1;
   } 

    l=ya.length();

  /* for(int i=0;i<=(l-1);i++)
	   {cout<<arr[i];
   }
   cout<<endl;
   */

      v1=arr;
 

	 bin2hex(v1);
		 v1=hexx;
		 hexx="";
				
	  
	  
	 //------
	        if(r11==0)
	  {
		  A=v1;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r11==1)
	  {
		  X=v1;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r11==2)
	  {
		  L=v1;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r11==3)
	  {
		   B=v1;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r11==4)
	  {
           S=v1;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r11==5)
	  {
	  T=v1;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r11==8)
	  {
		  //pc=v1;
		//   cout<<pc<<endl;
	  }
	  else if(r11=9)
	  {
		    SW=v1;
		// cout<<"SW="<<SW<<endl;
	  }



 }//end shift

 else if(opcode=="10100100")// shiftL
	 { 
		 
		   inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		  str2=str1;
		 str1=str1.substr(0,4);
		 str2=str2.substr(4,4);

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;

		 bin2dec(str2);
			r22=sum;
				sum=0;

				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }
 //
	   if(r22==0)
	  {
		  v2=A;
	  }
	  else if(r22==1)
	  {
		  v2=X;
	  }
	  else if(r22==2)
	  {
		  v2=L;
	  }
	  else if(r22==3)
	  {
		  v2=B;
	  }
	  else if(r22==4)
	  {
		  v2=S;
	  }
	  else if(r22==5)
	  {
		  v2=T;
	  }
	  else if(r22==8)
	  {
		  v2=pc;
	  }
	  else if(r22=9)
	  {
		  v2=SW;
	  }

	  //-----
	  l=v2.length();
		 Binary (v2);
		 v2=bin;
		 bin="";
		 
		 bin2dec(v2);
			r22=sum;
				sum=0;
	  n=r22+1;
	  
	
	  
	  
	string ya;
	
 l=v1.length();
 Binary (v1);
	v1=bin;
 bin="";

    ya=v1;
	l=ya.length();
		
	l=l-1;

	string arr=ya;  //arr={r1 as binary string}
    char *p;
      p=&arr[0];

  int first;
  first=arr[0];
  int count=l;
  l=0;

    int i=0;  //start doing the shiftL n times
   while (i<n)
	
   {
	   while (l<count)
	   {
	
     arr[l]=arr[l+1];
			   l=l+1;
	   }
	 
	   if(l==count)
		   arr[l]=first;

	   first=arr[0];
	   i++;

	   l=ya.length();
	  l=l-1;
	  count=l;
	  l=0;

   } 

    l=ya.length();

  /* for(int i=0;i<=(l-1);i++)
	   {cout<<arr[i];
   }
   cout<<endl;
   */

      v1=arr;
 

	 bin2hex(v1);
		 v1=hexx;
		 hexx="";
		 
		
	 //------
	        if(r11==0)
	  {
		  A=v1;
		 //cout<<"A="<<A<<endl;
	  }
	  else if(r11==1)
	  {
		  X=v1;
		   //cout<<"X="<<X<<endl;
	  }
	  else if(r11==2)
	  {
		  L=v1;
		   //cout<<"L="<<L<<endl;
	  }
	  else if(r11==3)
	  {
		   B=v1;
		    //cout<<"B="<<B<<endl;
	  }
	  else if(r11==4)
	  {
           S=v1;
		   //cout<<"S="<<S<<endl;
	  }
	  else if(r11==5)
	  {
	  T=v1;
	  //cout<<"T="<<T<<endl;
	  }
	  else if(r11==8)
	  {
		  //pc=v1;
		//   cout<<pc<<endl;
	  }
	  else if(r11=9)
	  {
		    SW=v1;
		// cout<<"SW="<<SW<<endl;
	  }

 }//end shiftL


 else if(opcode=="10111000")// tixr 
	 {
		  inst=mem[pc]+mem[pc+1];
		    str1=mem[pc+1];
			 l=inst.length();
			  pc=pc+inst.length()/2;

		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";

		
		 str1=str1.substr(0,4);
	

         int r11,r22;
			 string v1,v2;

		 bin2dec(str1);
			r11=sum;
				sum=0;
				
	  if(r11==0)
	  {
		  v1=A;
	  }
	  else if(r11==1)
	  {
		  v1=X;
	  }
	  else if(r11==2)
	  {
		  v1=L;
	  }
	  else if(r11==3)
	  {
		  v1=B;
	  }
	  else if(r11==4)
	  {
		  v1=S;
	  }
	  else if(r11==5)
	  {
		  v1=T;
	  }
	  else if(r11==8)
	  {
		  v1=pc;
	  }
	  else if(r11=9)
	  {
		  v1=SW;
	  }

	  //----
	       
	     l=X.length();
		 Binary (X);
		 X=bin;
		 bin="";

          bin2dec(X);
			r22=sum;
			sum=0;

	r22=r22+1;

	int2bin (r22);
		 v2=c;
		 c="";
		
		 bin2hex(v2);
		 v2=hexx;
		 hexx="";
	      
		 X=v2;

	 if (X>v1 )
	SW="000001";
	 if (X==v1)
	SW="000000";
	if (X<v1) 
	SW="000002";
	 

					
 }  //end tixr

	 if(opcode=="01000100")//the instruction is OR m
	 {
		
		 int var,a;
		 l=A.length();

		 Binary(A);
		 A=bin;
		 bin="";
		 bin2dec(A);
		 a=sum;
		 sum=0;
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }

			 
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1))
							{
								calTA(binary);
								var=TA;
								a=a&var;
							}
			 else
			 {
                                calTA (binary);
							    temp=mem[TA]+mem[TA+1]+mem[TA+2];
								l=temp.length();
							    Binary(temp);
							    bin2dec(bin);
							    var=sum;
							    sum=0;
								a=a|var;

			 }
		 
		int2bin (a);
		 A=c;
		 c="";
		 bin2hex(A);
		 A=hexx;
		 hexx="";
			 

	 }
	 
	 if (opcode=="00001100")// the instruction is STA m
	{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
		 

			 
			 Binary (inst);
			 binary=bin;
			 bin="";

			
						
		 calTA(binary);
		 mem[TA]=A.substr(0,2);
		 mem[TA+1]=A.substr(2,2);
		 mem[TA+2]=A.substr(4,2);

		mm[0]=mem[TA];
		mm[1]=mem[TA+1];
		mm[2]=mem[TA+2];

		 
		 
		

	}
	 
	 if (opcode=="01111000")// the instruction is STB m
		{
			str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
             calTA(binary);
			 mem[TA]=B.substr(0,2);
			 mem[TA+1]=B.substr(2,2);
			 mem[TA+2]=B.substr(4,2);
			 mm[3]=mem[TA];
			 mm[4]=mem[TA+1];
			 mm[5]=mem[TA+2];
			 
		 

		
		
	 }


		if (opcode=="00010100")//the instruction is STL m
		{
			str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 
			 calTA(binary);
			 mem[TA]=L.substr(0,2);
			 mem[TA+1]=L.substr(2,2);
			 mem[TA+2]=L.substr(4,2);
			  mm[6]=mem[TA];
			 mm[7]=mem[TA+1];
			 mm[8]=mem[TA+2];
			 
		
		
						
		}
if (opcode=="01111100")//the instruction is STS m
		{
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			
			 calTA(binary);
			 mem[TA]=S.substr(0,2);
			 mem[TA+1]=S.substr(2,2);
             mem[TA+2]=S.substr(4,2);
			  mm[9]=mem[TA];
			 mm[10]=mem[TA+1];
			 mm[11]=mem[TA+2];
			 
		
			
			
		}
if (opcode=="11101000")//the instruction is STSW m
		{
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
            
		     calTA(binary);
			 mem[TA]=SW.substr(0,2);
			 mem[TA+1]=SW.substr(2,2);
			 mem[TA+2]=SW.substr(4,2);
			  mm[12]=mem[TA];
			 mm[13]=mem[TA+1];
			 mm[14]=mem[TA+2];
			 
		 
			 

			
		}
		if (opcode=="10000100")//the instruction is STT m
		{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
             
			//cout<<"STT m"<<endl;
			calTA(binary);
			mem[TA]=T.substr(0,2);
			mem[TA+1]=T.substr(2,2);
			mem[TA+2]=T.substr(4,2);
			 mm[15]=mem[TA];
			 mm[16]=mem[TA+1];
			 mm[17]=mem[TA+2];
			
		 
			
				
		}

if (opcode=="00010000")// the instruction is STX 
		{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
             calTA(binary);
			 mem[TA]=X.substr(0,2);
			 mem[TA+1]=X.substr(2,2);
			 mem[TA+2]=X.substr(4,2);
			  mm[18]=mem[TA];
			 mm[19]=mem[TA+1];
			 mm[20]=mem[TA+2];
			 
		

		}
if(opcode=="00011100")// SUB m
		{
			
		 int var,a;
		 l=A.length();
		 Binary(A);
		 A=bin;
		 bin="";
		 bin2dec(A);
		 a=sum;
		 sum=0;
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1))
							{
								calTA(binary);
								var=TA;
								a=a-var;
							}
			 else
			 {
                                calTA (binary);
							    temp=mem[TA]+mem[TA+1]+mem[TA+2];
								l=temp.length();
							    Binary(temp);
							    bin2dec(bin);
							    var=sum;
							    sum=0;
								a=a-var;

			 }
		 
		int2bin (a);
		 A=c;
		 c="";
		 bin2hex(A);
		 A=hexx;
		 hexx="";
		 cout<<"A ="<<A<<endl;
	
		}
 if (opcode=="01001100")// the instruction is RSUB 
	{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";

			 int str2;
			 string str;
			 Binary(L);
			 str=bin;
			 bin="";
			 bin2dec(str);
			 str2=sum;
			 sum=0;
			 pc=str2;
			
			 
		 }	

if (opcode=="00101100")// the instruction is TIX m
{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
		 int x;
			string xx;
			l=X.length();
            Binary(X);
			xx=bin;
			bin="";
			l=xx.length();
			bin2dec(xx);
			x=sum;
			sum=0;
			x=x+1;
			int2bin(x);
		 X=c;
		 c="";
		 bin2hex(X);
		 
		 

		 hexx="";
 l=inst.length();
			 Binary (inst);
			 binary=bin;
			 bin="";
		if((binary.at(6)==0)&&(binary.at(7)==1))   // immediate addressing
			 {
				 calTA(binary);
				 int2bin (TA);
		         temp=c;
		         c="";
		         bin2hex(temp);
		         temp=hexx;
		         hexx="";
				 if(X>temp)
					 SW="000001";
				 if(X<temp)
					 SW="000002";
				 if(X==temp)
					 SW="000000";
		}
		else
		{
			calTA(binary);
			temp=mem[TA]+mem[TA+1]+mem[TA+2];
				 if(X>temp)
					 SW="000001";
				 if(X<temp)
					 SW="000002";
				 if(X==temp)
					 SW="000000";
		}
}


 if (opcode=="01010100")// the instruction is STCH m
		{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
             calTA(binary);
			 mem[TA]=A.substr(4,2);
			  mm[21]=mem[TA];
			
			 
		
		
		}
 
if (opcode=="00000000")  //LDA m instruction 
		{
		str1=mem[pc+1];
		 l=str1.length();
		  Binary (str1);
		   str1=bin;
		  bin="";
			  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			                Binary (inst);
			                binary=bin;
			                bin="";

			                
							if((binary.at(6)==0)&&(binary.at(7)==1))
							{ 
								calTA(binary);
								int2bin(TA);
								A=c;
							    c="";
		                        bin2hex(A);
		                        A=hexx;
		                        hexx="";
		                        cout<<"A = "<<A<<endl;
							}

							else
							{
		               calTA(binary);
						
						A=mem[TA]+mem[TA+1]+mem[TA+2];
						
							}
							

						}

	if(opcode=="01101000")  //LDB m
	{
						
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
		if((binary.at(6)==0)&&(binary.at(7)==1))
							{ 
								calTA(binary);
								int2bin(TA);
								B=c;
							    c="";
		                        bin2hex(B);
		                        B=hexx;
		                        hexx="";
		                        cout<<"B ="<<B<<endl;
							}

							else
							{
             calTA(binary);
			 B=mem[TA]+mem[TA+1]+mem[TA+2];
			 
		}
		 
			 
						
	}
if(opcode=="00001000")//LDL m
{
			str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
         
			if((binary.at(6)==0)&&(binary.at(7)==1))
							{ 
								calTA(binary);
								int2bin(TA);
								L=c;
							    c="";
		                        bin2hex(L);
		                        L=hexx;
		                        hexx="";
		                       
							}

					else
							{
			 calTA(binary);
			 L=mem[TA]+mem[TA+1]+mem[TA+2];
			 cout<<"L ="<<L<<endl;
			//cout<<mem[TA]<<endl;
			}
						
}

if(opcode=="01101100")  //LDS m
{
	    str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			
			 			if((binary.at(6)==0)&&(binary.at(7)==1))
							{ 
								calTA(binary);
								int2bin(TA);
								S=c;
							    c="";
		                        bin2hex(S);
		                        S=hexx;
		                        hexx="";
		                       
							}

					else
							{
			 calTA(binary);
			 S=mem[TA]+mem[TA+1]+mem[TA+2];
			 cout<<" s="<<S<<endl;
						}
			
}

if(opcode=="01110100")  //LDT m
{
			str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
	 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
             
			//cout<<"STT m"<<endl;
			 			if((binary.at(6)==0)&&(binary.at(7)==1))
							{ 
								calTA(binary);
								int2bin(TA);
								T=c;
							    c="";
		                        bin2hex(T);
		                        T=hexx;
		                        hexx="";
		                       
							}

					else
							{
			calTA(binary);
			T =mem[TA]+mem[TA+1]+mem[TA+2];
			cout<<"t ="<<T<<endl;
			//cout<<mem[TA]<<endl;
						}
				

}

if(opcode=="00000100") ///LDX m
{
			str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 			if((binary.at(6)==0)&&(binary.at(7)==1))
							{ 
								calTA(binary);
								int2bin(TA);
								X=c;
							    c="";
		                        bin2hex(X);
		                        X=hexx;
		                        hexx="";
		                       
							}

					else
							{
             calTA(binary);
			 X=mem[TA]+mem[TA+1]+mem[TA+2];
			 
						}

	
}

if(opcode=="01010000") ///LDCH m    
{
			str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 			if((binary.at(6)==0)&&(binary.at(7)==1))
							{ string e;
								calTA(binary);
								int2bin(TA);
								e=c;
							    c="";
		                        bin2hex(e);
		                        A.replace(4,2,hexx);
		                        hexx="";
		                       
							}

					else
							{
								
             calTA(binary);
			 A=A.substr(0,4)+mem[TA];
			 

						}	

}

if(opcode=="00011000")// ADD m
		{
			
		 int var,a;
		 l=A.length();

		 Binary(A);
		 A=bin;
		 bin="";
		 bin2dec(A);
		 a=sum;
		 sum=0;
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1))
							{
								calTA(binary);
								var=TA;
								a=a+var;
							}
			 else
			 {
                                calTA (binary);
							    temp=mem[TA]+mem[TA+1]+mem[TA+2];
								l=temp.length();
							    Binary(temp);
							    bin2dec(bin);
							    var=sum;
							    sum=0;
								a=a+var;

			 }
		 
		int2bin (a);
		 A=c;
		 c="";
		 bin2hex(A);
		 A=hexx;
		 hexx="";
		 


		}

		
if(opcode=="00100000")// MUL m
		{
			
		 int var,a;
		 l=A.length();

		 Binary(A);
		 A=bin;
		 bin="";
		 bin2dec(A);
		 a=sum;
		 sum=0;
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1))
							{
								calTA(binary);
								var=TA;
								a=a*var;
							}
			 else
			 {
                                calTA (binary);
							    temp=mem[TA]+mem[TA+1]+mem[TA+2];
								l=temp.length();
							    Binary(temp);
							    bin2dec(bin);
							    var=sum;
							    sum=0;
								a=a*var;

			 }
		
		int2bin (a);
		 A=c;
		 c="";
		 bin2hex(A);
		 A=hexx;
		 hexx="";
		 cout<<A<<endl;



		}

 if(opcode=="00100100")// DIV m
		{
			
		 int var,a;
		 l=A.length();

		 Binary(A);
		 A=bin;
		 bin="";
		 bin2dec(A);
		 a=sum;
		 sum=0;
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1))
							{
								calTA(binary);
								var=TA;
								a=a/var;
							}
			 else
			 {
                                calTA (binary);
							    temp=mem[TA]+mem[TA+1]+mem[TA+2];
								l=temp.length();
							    Binary(temp);
							    bin2dec(bin);
							    var=sum;
							    sum=0;
								a=a/var;

			 }
		 
		int2bin (a);
		 A=c;
		 c="";
		 bin2hex(A);
		 A=hexx;
		 hexx="";
		 cout<<A<<endl;



 }

if(opcode=="01000000")// AND m
		{
			
		 int var,a;
		 l=A.length();

		 Binary(A);
		 A=bin;
		 bin="";
		 bin2dec(A);
		 a=sum;
		 sum=0;
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1))
							{
								calTA(binary);
								var=TA;
								a=a&var;
							}
			 else
			 {
                                calTA (binary);
							    temp=mem[TA]+mem[TA+1]+mem[TA+2];
								
								l=temp.length();
							    Binary(temp);
							    bin2dec(bin);
							    var=sum;
							    sum=0;
								a=a&var;

			 }
		 
		int2bin (a);
		 A=c;
		 c="";
		 bin2hex(A);
		 A=hexx;
		 hexx="";
		 



}

if(opcode=="00111100")    //J m
{
			str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1)) // immediate addressing
			 {
				 calTA(binary);
				 pc=TA;
			 }
			 else
			 {
				 int d1;
				 string s1;
				 calTA(binary);
				 temp=mem[TA];
				 l=temp.length();
				 Binary(temp);
				 s1=bin;
				 bin="";
				 bin2dec(s1);
				 d1=sum;
				 sum=0;
				 pc=d1;


			 }
		 
}

if(opcode=="01001000")  // JSUB m  ;;L=pc ; pc=m
{
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
			 if((binary.at(6)==0)&&(binary.at(7)==1))   // immediate addressing
			 {
				 calTA(binary);
				 //l=pc
				 int2bin (pc);
		         L=c;
		         c="";
		         bin2hex(L);
		         L=hexx;
		         hexx="";
				 //pc=m
				 pc=TA;
		 
			 }
			 else
			 {
				 calTA(binary);
				 //L=pc				 
				 int2bin (pc);
		         L=c;
		         c="";
		         bin2hex(L);
		         L=hexx;
		         hexx="";
				 //pc=m
				 int d1;
				 string s1;
				 temp=mem[TA];
				 l=temp.length();
				 Binary(temp);
				 s1=bin;
				 bin="";
				 bin2dec(s1);
				 d1=sum;
				 sum=0;
				 pc=d1;

			 }
}

if(opcode=="00101000")  //comp m 
{
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
		if((binary.at(6)==0)&&(binary.at(7)==1))   // immediate addressing
			 {
				 calTA(binary);
				 int2bin (TA);
		         temp=c;
		         c="";
		         bin2hex(temp);
		         temp=hexx;
		         hexx="";
				 if(A>temp)
					 SW="000001";
				 if(A<temp)
					 SW="000002";
				 if(A==temp)
					 SW="000000";
		}
		else
		{
			calTA(binary);
			temp=mem[TA]+mem[TA+1]+mem[TA+2];
				 if(A>temp)
					 SW="000001";
				 if(A<temp)
					 SW="000002";
				 if(A==temp)
					 SW="000000";
		}
}

if(opcode=="00110000")
{
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
		if((binary.at(6)==0)&&(binary.at(7)==1))   // immediate addressing
			 {
				 calTA(binary);
				 if(SW=="000000")
				 {
					 pc=TA;
				 }
		}

		else
		{
			calTA(binary);
			if(SW=="000000")
			{
			     int d1;
				 string s1;
				 temp=mem[TA];
				 l=temp.length();
				 Binary(temp);
				 s1=bin;
				 bin="";
				 bin2dec(s1);
				 d1=sum;
				 sum=0;
				 pc=d1;

			}
		}

}

if(opcode=="00110100")//JGT m
{
		 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
		if((binary.at(6)==0)&&(binary.at(7)==1))   // immediate addressing
			 {
				 calTA(binary);
				 if(SW=="000001")
				 {
					 pc=TA;
				 }
		}

		else
		{
			calTA(binary);
			if(SW=="000001")
			{
			     int d1;
				 string s1;
				 temp=mem[TA];
				 l=temp.length();
				 Binary(temp);
				 s1=bin;
				 bin="";
				 bin2dec(s1);
				 d1=sum;
				 sum=0;
				 pc=d1;

			}
		}

}

if(opcode=="00111000")//JLT m
{
			 str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 Binary (inst);
			 binary=bin;
			 bin="";
		if((binary.at(6)==0)&&(binary.at(7)==1))   // immediate addressing
			 {
				 calTA(binary);
				 if(SW=="000002")
				 {
					 pc=TA;
				 }
		}

		else
		{
			calTA(binary);
			if(SW=="000002")
			{
			     int d1;
				 string s1;
				 temp=mem[TA];
				 l=temp.length();
				 Binary(temp);
				 s1=bin;
				 bin="";
				 bin2dec(s1);
				 d1=sum;
				 sum=0;
				 pc=d1;

			}
		}

}
if (opcode=="11011000")// the instruction is RD m
	{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		  if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 string ll;
			 ifstream myfile ("simulator IO input.txt");
			 if(myfile.is_open())
	{
		
	 
		while(! myfile.eof())
		{
			string io;

			getline(myfile,ll);
			nameio =ll;

			int pos = ll.find("I/O '"); 
				io = ll.substr(pos+5,2);
				A.replace(4,2,io);
				

			 
		 }	
		myfile.close();

			 }
			 else
				 cout<<"unable to open file";
		 }
if (opcode=="11011100")// the instruction is WD m
	{
		str1=mem[pc+1];
		 l=str1.length();
		 Binary (str1);
		 str1=bin;
		 bin="";
		 if (str1.at(3)=='0')//format3
		 {
			 inst=mem[pc]+mem[pc+1]+mem[pc+2];
			 l=inst.length();
			  pc=pc+inst.length()/2;
		 }
		 else  //e=1 then format 4 4 bytes from memory
			 {inst=mem[pc]+mem[pc+1]+mem[pc+2]+mem[pc+3];
		 l=inst.length();
 pc=pc+inst.length()/2;
		 }
			 string ll;
			 ofstream myfile ("simulator IO output.txt");
			 if(myfile.is_open())
	{
	
		ll=A.substr(4,2);	
		myfile<<nameio<<endl;
		myfile.close();

						}
			 else
				 cout<<"unable to open file";
		 }




			

	 //cout<<line<<endl;
	
	}
	int2bin (pc);
		 PC=c;
		 c="";
		 bin2hex(PC);
		 PC=hexx;
		 hexx="";
		
		 
		 


	{
ofstream myfile ("simulator output.txt");
			 if(myfile.is_open())
	{
	
		myfile <<"!_!_! Registers\n";
		myfile<<"A = "<<A<<endl;
        myfile<<"X = "<<X<<endl;
		myfile<<"L = "<<L<<endl;
        myfile<<"PC = "<<PC<<endl;
		myfile<<"SW = "<<SW<<endl;
        myfile<<"B = "<<B<<endl;
		myfile<<"S = "<<S<<endl;
        myfile<<"T = "<<T<<endl;
		myfile<<mm[0]<<endl;
		myfile<<mm[1]<<endl;
		myfile<<mm[2]<<endl;
			myfile<<mm[3]<<endl;
		myfile<<mm[4]<<endl;
		myfile<<mm[5]<<endl;
		myfile<<mm[6]<<endl;
		myfile<<mm[7]<<endl;
		myfile<<mm[8]<<endl;
			myfile<<mm[9]<<endl;
		myfile<<mm[10]<<endl;
		myfile<<mm[11]<<endl;
		myfile<<mm[12]<<endl;
		myfile<<mm[13]<<endl;
		myfile<<mm[14]<<endl;
			myfile<<mm[15]<<endl;
		myfile<<mm[16]<<endl;
		myfile<<mm[17]<<endl;
		myfile<<mm[18]<<endl;
		myfile<<mm[19]<<endl;
		myfile<<mm[20]<<endl;
			myfile<<mm[21]<<endl;
		
	  
		
		myfile.close();

						}
			 else
				 cout<<"unable to open file";
		 }


	return 0;
}
string int2bin(int n)
{
	
	int i,p;
	i=n;
	while (i!=0)
	{
		i= n/2;
		p=n - (i*2);
		n=i;
		if (p==0)
			c='0'+c;
		else if (p==1)
			c='1'+c;
	}
string str,str1;
	l=c.length();
	if(l%4==1)
	{
		str="000";
		c=str+c;
	}
	else if (l%4==2)
	{
		str="00";
		c=str+c;
	}
	else if (l%4==3)
	{
		str="0";
		c=str+c;
	}
	return c;
}
string bin2hex(string w)
{
	string str,str1;
	l=w.length();
	if(l%4==1)
	{
		str="000";
		w=str+w;
	}
	else if (l%4==2)
	{
		str="00";
		w=str+w;
	}
	else if (l%4==3)
	{
		str="0";
		w=str+w;
	}
	l=w.length();
	
	int i=l-4;
	while (i>=0)
	{
	if(w.substr(i,4)=="1111")
		str1="F";
	else if(w.substr(i,4)=="1110")
		str1="E";
   else if(w.substr(i,4)=="1101")
		str1="D";
	else if(w.substr(i,4)=="1100")
		str1="C";
   else if(w.substr(i,4)=="1011")
		str1="B";
   else if(w.substr(i,4)=="1010")
		str1="A";
	else if(w.substr(i,4)=="1001")
		str1="9";
    else if(w.substr(i,4)=="1000")
		str1="8";
	else if(w.substr(i,4)=="0111")
		str1="7";
   else if(w.substr(i,4)=="0110")
		str1="6";
   else if(w.substr(i,4)=="0101")
		str1="5";
	else if(w.substr(i,4)=="0100")
		str1="4";
	  else if(w.substr(i,4)=="0011")
		str1="3";
	else if(w.substr(i,4)=="0010")
		str1="2";
   else if(w.substr(i,4)=="0001")
		str1="1";
   else if(w.substr(i,4)=="0000")
		str1="0";
   hexx=str1+hexx;
   i=i-4;
	}
	l=hexx.length();
	if(l==1)
		 hexx="00000"+hexx;
		 if(l==2)
		  hexx="0000"+hexx;
        if(l==3)
		 hexx="000"+hexx;
		 if(l==4)
		  hexx="00"+hexx;
		  if(l==5)
		  hexx="0"+hexx;
	return hexx;
}


string Binary (string p)
	{
		
		
		string b;
		int u;
		for ( u=0;u<l;u++)
		{
		if (p.substr(u,1)=="0")
		b="0000";
		if (p.substr(u,1)=="1")
			b="0001";
		if (p.substr(u,1)=="2")
			b="0010";
		if (p.substr(u,1)=="3")
			b="0011";
		if (p.substr(u,1)=="4")
			b="0100";
		if (p.substr(u,1)=="5")
			b="0101";
		if (p.substr(u,1)=="6")
			b="0110";
		if (p.substr(u,1)=="7")
			b="0111";
		if (p.substr(u,1)=="8")
			b="1000";
		if (p.substr(u,1)=="9")
			b="1001";
		if (p.substr(u,1)=="A")
			b="1010";
		if (p.substr(u,1)=="B")
			b="1011";
		if (p.substr(u,1)=="C")
			b="1100";
		if (p.substr(u,1)=="D")
			b="1101";
		if (p.substr(u,1)=="E")
			b="1110";
		if (p.substr(u,1)=="F")
			b="1111";
		bin =bin+b;
		

		
		
		}
		
	return bin;
	}
		int calTA (string binTA)
		{
			int b,x;
			string bb,xx;
			l=B.length();
			Binary(B);
			bb=bin;
			bin="";
			l=bb.length();
			bin2dec(bb);
			b=sum;
			sum=0;
			l=X.length();
            Binary(X);
			xx=bin;
			bin="";
			l=xx.length();
			bin2dec(xx);
			x=sum;
			sum=0;
			
			if(((binTA.at(6)=='1')&&(binTA.at(7)=='1'))||((binTA.at(6)=='0')&&(binTA.at(7)=='0')))//Simple addressing mode 
			{
				if (binTA.at(11)=='0')//simple addressing format 3
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
				{
						TA1=binTA.substr(12,12);
						bin2dec(TA1);
						TA=sum;
						sum =0;
				}

				
				if (binTA.at(11)=='1')//simple addressing format 4
					if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
					{
						TA1=binTA.substr(12,20);
					bin2dec(TA1);
						TA=sum;
						sum =0;
				}
				if (binTA.at(11)=='0')//simple addressing format 3
					if((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='1'))
					{
						TA1=binTA.substr(12,12);
					bin2dec(TA1);
						TA=sum;
						sum =0;
						TA=TA+pc;		
			}
              if (binTA.at(11)=='0')//simple addressing format 3
				  if((binTA.at(8)=='0')&&(binTA.at(9)=='1')&&(binTA.at(10)=='0'))
				  {
	                  TA1=binTA.substr(12,12);
					  bin2dec(TA1);
					  TA=sum;
						sum =0;
						TA=TA+b;
				  }
				  if (binTA.at(11)=='0')//simple addressing format 3
				  if((binTA.at(8)=='1')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
				  {
	                  TA1=binTA.substr(12,12);
					  bin2dec(TA1);
					  TA=sum;
						sum =0;
						TA=TA+x;
				  }
				  if (binTA.at(11)=='1')//simple addressing format 4
				  if((binTA.at(8)=='1')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
				  {
	                  TA1=binTA.substr(12,20);
					  bin2dec(TA1);
					  TA=sum;
						sum =0;
						TA=TA+x;
				  }
				   if (binTA.at(11)=='0')//simple addressing format 3
				  if((binTA.at(8)=='1')&&(binTA.at(9)=='0')&&(binTA.at(10)=='1'))
				  {
	                  TA1=binTA.substr(12,12);
					  bin2dec(TA1);
					  TA=sum;
						sum =0;
						TA=TA+x+pc;
				  }
				   if (binTA.at(11)=='0')//simple addressing format 3
				  if((binTA.at(8)=='1')&&(binTA.at(9)=='1')&&(binTA.at(10)=='0'))
				  {
	                  TA1=binTA.substr(12,12);
					  bin2dec(TA1);
					  TA=sum;
						sum =0;
						TA=TA+x+b;
				  }
			}
			if((binTA.at(6)=='1')&&(binTA.at(7))=='0')// Indirect addressing mode
			{
				if (binTA.at(11)=='0')//indirect addressing format 3
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
				{
						TA1=binTA.substr(12,12);
						bin2dec(TA1);
						indirect=mem[sum];
						Binary(indirect);
						bin2dec(bin);

						TA=sum;
						sum =0;
				}
				if (binTA.at(11)=='1')//indirect addressing format 4
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
				{
						TA1=binTA.substr(12,20);
						bin2dec(TA1);
						indirect=mem[sum];
						Binary(indirect);
						bin2dec(bin);

						TA=sum;
						sum =0;
				}
				if (binTA.at(11)=='0')//indirect addressing format 3
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='1'))
				{
						TA1=binTA.substr(12,12);
						bin2dec(TA1);
						TA=sum;
						sum =0;
						TA=TA+pc;
						indirect=mem[TA];
						Binary(indirect);
						bin2dec(bin);
						TA=sum;
						sum=0;

				}
				if (binTA.at(11)=='0')//indirect addressing format 3
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='1')&&(binTA.at(10)=='0'))
				{
						TA1=binTA.substr(12,12);
						bin2dec(TA1);
						TA=sum;
						sum =0;
						TA=TA+b;
						indirect=mem[TA];
						Binary(indirect);
						bin2dec(bin);
						TA=sum;
						sum=0;

				}
			}
              if((binTA.at(6)=='0')&&(binTA.at(7))=='1')//Immediate addressing mode
				  if (binTA.at(11)=='0')//immediate addressing format 3
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
				{
						TA1=binTA.substr(12,12);
						bin2dec(TA1);
						TA=sum;
						sum =0;
				}
				  if (binTA.at(11)=='1')//immediate addressing format 4
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='0'))
				{
						TA1=binTA.substr(12,20);
						bin2dec(TA1);
						TA=sum;
						sum =0;
				}
				  if (binTA.at(11)=='0')//immediate addressing format 3
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='0')&&(binTA.at(10)=='1'))
				{
						TA1=binTA.substr(12,12);
						bin2dec(TA1);
						TA=sum;
						sum =0;
						TA=TA+pc;
				}
				  if (binTA.at(11)=='0')//immediate addressing format 3
				if ((binTA.at(8)=='0')&&(binTA.at(9)=='1')&&(binTA.at(10)=='0'))
				{
						TA1=binTA.substr(12,12);
						bin2dec(TA1);
						TA=sum;
						sum =0;
						TA=TA+b;
				}
				

			
			
			return (TA);
			}
			
			
		
		// convert a binary string to a decimal number, returns decimal value
int bin2dec(string binn)
{
        int  b, k, m, n;
        int  len;
		
		
		

		len =(binn.length()) - 1;
        for(k = 0; k <= len; k++)
        {
			
                n = (binn[k] - '0'); // char to numeric value
                if ((n > 1) || (n < 0))
                {
                        puts("\n\n ERROR! BINARY has only 1 and 0!\n");
                        return (0);
                }
                for(b = 1, m = len; m > k; m--)
                {
                        
                        b *= 2;
                }
                // sum it up

			
                sum = sum + n * b;
				
		}
		
		
        return(sum);
}
			


		
