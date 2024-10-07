#include<iostream>
#include<string>
#include<map>
using namespace std;

void hex_to_bin(string* hex,string* bin){
	map<char,string> dic;
	dic['0']="0000";
	dic['1']="0001";
	dic['2']="0010";
	dic['3']="0011";
	dic['4']="0100";
	dic['5']="0101";
	dic['6']="0110";
	dic['7']="0111";
	dic['8']="1000";
	dic['9']="1001";
	dic['A']="1010";
	dic['B']="1011";
	dic['C']="1100";
	dic['D']="1101";
	dic['E']="1110";
	dic['F']="1111";//创建字典 
	*bin="";
	for(int i=0;i<hex->length();i++){
		*bin+=dic[(*hex)[i]];
	} 
}


int main(){
	string hex[3]={"ABCDEFA","DEFACEDA","9A0AB"};
	string bin[3];
	for(int i=0;i<3;i++){
	hex_to_bin(&hex[i],&bin[i]);
	cout<<hex[i]<<"转成二进制为"<<bin[i]<<endl;
	}
	
	return 0;
} 
