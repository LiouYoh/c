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
    // 生成16個子密鑰  
    	generateKeys();     
    // 密文寫入 a.txt  
    	bitset<64> cipher = encrypt(plain);  
    	fstream file1;  
    	file1.open( "D://a.txt" , ios::binary | ios::out);  
    	file1.write(( char *)&cipher, sizeof (cipher));  
    	file1.close();  
  
    // 讀文件 a.txt  
    	bitset<64> temp;  
    	file1.open( "D://a.txt" , ios::binary | ios::in);  
    	file1.read(( char *)&temp,  sizeof (temp));  
    	file1.close();  
  
    // 解密，並寫入文件 b.txt  
    	bitset<64> temp_plain = decrypt(temp);  
    	file1.open( "D://b.txt" , ios::binary | ios::out);  
    	file1.write(( char *)&temp_plain, sizeof (temp_plain));  
    	file1.close();  
   	    s.erase(0, pos + delimiter.length());
	}
	
	bitset<64> plain = charToBitset(s.c_str());  
    key = charToBitset(k.c_str());  
    // 生成16個子密鑰  
    generateKeys();     
    // 密文寫入 a.txt  
    bitset<64> cipher = encrypt(plain);  
    fstream file1;  
    file1.open( "D://a.txt" , ios::binary | ios::out);  
    file1.write(( char *)&cipher, sizeof (cipher));  
    file1.close();  
  
    // 讀文件 a.txt  
    bitset<64> temp;  
    file1.open( "D://a.txt" , ios::binary | ios::in);  
    file1.read(( char *)&temp,  sizeof (temp));  
    file1.close();  
  
    // 解密，並寫入文件 b.txt  
    bitset<64> temp_plain = decrypt(temp);  
    file1.open( "D://b.txt" , ios::binary | ios::out);  
    file1.write(( char *)&temp_plain, sizeof (temp_plain));  
    file1.close();  
	
    return 0; 
}
