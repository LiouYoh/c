#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
   
 	string s =  "I WILL PASS NETWORK SECURITY" ;
 	string k =  "1234567" ; 
	string delimiter = " ";

	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
    	token = s.substr(0, pos);
    	token = token+" ";
   		bitset<64> plain = charToBitset(token.c_str());  
    	key = charToBitset(k.c_str());  
    // �ͦ�16�Ӥl�K�_  
    	generateKeys();     
    // �K��g�J a.txt  
    	bitset<64> cipher = encrypt(plain);  
    	fstream file1;  
    	file1.open( "D://a.txt" , ios::binary | ios::out);  
    	file1.write(( char *)&cipher, sizeof (cipher));  
    	file1.close();  
  
    // Ū��� a.txt  
    	bitset<64> temp;  
    	file1.open( "D://a.txt" , ios::binary | ios::in);  
    	file1.read(( char *)&temp,  sizeof (temp));  
    	file1.close();  
  
    // �ѱK�A�üg�J��� b.txt  
    	bitset<64> temp_plain = decrypt(temp);  
    	file1.open( "D://b.txt" , ios::binary | ios::out);  
    	file1.write(( char *)&temp_plain, sizeof (temp_plain));  
    	file1.close();  
   	    s.erase(0, pos + delimiter.length());
	}
	
	bitset<64> plain = charToBitset(s.c_str());  
    key = charToBitset(k.c_str());  
    // �ͦ�16�Ӥl�K�_  
    generateKeys();     
    // �K��g�J a.txt  
    bitset<64> cipher = encrypt(plain);  
    fstream file1;  
    file1.open( "D://a.txt" , ios::binary | ios::out);  
    file1.write(( char *)&cipher, sizeof (cipher));  
    file1.close();  
  
    // Ū��� a.txt  
    bitset<64> temp;  
    file1.open( "D://a.txt" , ios::binary | ios::in);  
    file1.read(( char *)&temp,  sizeof (temp));  
    file1.close();  
  
    // �ѱK�A�üg�J��� b.txt  
    bitset<64> temp_plain = decrypt(temp);  
    file1.open( "D://b.txt" , ios::binary | ios::out);  
    file1.write(( char *)&temp_plain, sizeof (temp_plain));  
    file1.close();  
	
    return 0; 
}
