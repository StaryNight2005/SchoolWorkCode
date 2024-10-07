//��ҵ4������ŷ����ó��������ʵ�ֽ���ת��
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int hex_to_dec(char* hex){
	int len_hex=strlen(hex);
	int i=0,dec=0,hex_num=0;
	while(i<len_hex){
		if(hex[i]>='0'&&hex[i]<='9')
			hex_num=hex[i]-'0';
		else if(hex[i]>='a'&&hex[i]<='f')
			hex_num=hex[i]-'a'+10;
		else if(hex[i]>='A'&&hex[i]<='F')
			hex_num=hex[i]-'A'+10;
		dec+=hex_num*pow(16,len_hex-i-1);
		i++;
	}
	return dec;
}

char* hex_to_bin(char* hex){
	char* _hex[16]={
	"0000","0001","0010","0011",
	"0100","0101","0110","0111",
	"1000","1001","1010","1011",
	"1100","1101","1110","1111"};
	int len_hex=strlen(hex);
	char* bin=(char*)malloc(4*len_hex+1);
	memset(bin,0,sizeof(bin));
	int i=0;
	while(i<len_hex){
		if(hex[i]>='0'&&hex[i]<='9')
		strcat(bin,_hex[hex[i]-'0']);
		else if(hex[i]>='A'&&hex[i]<='F')
		strcat(bin,_hex[hex[i]-'A'+10]);
		else if(hex[i]>='a'&&hex[i]<='f')
		strcat(bin,_hex[hex[i]-'a'+10]);
		i++;
	}
	return bin;
}

char* bin_to_hex(char* bin){
	char* _hex[16]={
	"0000","0001","0010","0011",
	"0100","0101","0110","0111",
	"1000","1001","1010","1011",
	"1100","1101","1110","1111"};
	char _table[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int bin_len=strlen(bin);
	
	bin_len+=4-bin_len%4;
	
	char*pbin=(char*)malloc(bin_len+1);
	char* hex=(char*)malloc(bin_len/4+1);
	memset(pbin,0,sizeof(pbin));
	memset(hex,0,sizeof(hex));
	for(int i=0;i<bin_len-strlen(bin);i++)
	strcat(pbin,"0");
	strcat(pbin,bin);
	cout<<"����Ķ�������Ϊ��"<<pbin<<endl;
	int i=0;
	while(i<bin_len){
		char temp[5]="";
		strncpy(temp,pbin+i,4);
	
		int flag;
		for(int j=0;j<16;j++){
			if(strcmp(temp,_hex[j])==0){
				flag=j;
				break;
				
			}
		}
		
		hex[i/4]=_table[flag];
		i+=4;
	}
	hex[bin_len/4+1]='/0';
	return hex;
}

int main(){
	char hex[33]={};
	int flag=0;
	while(!flag){
	cout<<"������Ϸ���ʮ������������󳤶�32��\n";
	cin>>hex;
	if(strlen(hex)>=33)
	continue;
	flag=1;
	for(int i=0;i<strlen(hex);i++){
		if(!(hex[i]>='0'&&hex[i]<='9'||hex[i]>='a'&&hex[i]<='f'||hex[i]>='A'&&hex[i]<='F')){
			flag=0;
			break;
		}
	}
	}
	
	cout<<"ʮ��������<"<<hex<<">ת��Ϊʮ������Ϊ��"<<hex_to_dec(hex)<<endl;
	cout<<"ʮ��������<"<<hex<<">ת��Ϊ��������Ϊ��"<<hex_to_bin(hex)<<endl;
	
	char bin[129]={};
	flag=0;
	while(!flag){
	cout<<"������Ϸ��Ķ�����������󳤶�128��\n";
	cin>>bin;
	if(strlen(bin)>=129)
	continue;
	flag=1;	
	for(int i=0;i<strlen(bin);i++){
		if(!(bin[i]=='0'||bin[i]=='1')){
			flag=0;
			break;
		}
	}
	}
	
	cout<<"��������<"<<bin<<">ת��Ϊʮ��������Ϊ��"<<bin_to_hex(bin)<<endl;
	return 0;
}
