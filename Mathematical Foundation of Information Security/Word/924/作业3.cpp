//��ҵ3������ŷ����ó�������ʮ������ת���ɶ�����
#include<iostream>

int main(){
	int a,b=2,r;
	std::cout<<"����a=bq+r��ʮ����ת���ɶ���������\n";
	std::cout<<"Please input a number:\n";
	std::cin>>a;
	r=a;
	std::string bin="";
	std::cout<<"�������ŷ����ó����������У�\n";
	while(a){
		std::cout<<a<<" = "<<b<<" * "<<a/b<<" + "<<a%b<<std::endl;
		bin+=a%b+'0';
		a/=b;
	}
	std::cout<<std::endl<<"��ˣ�"<<r<<"=<";
	for(int i=bin.length();i>0;i--)
	std::cout<<bin[i-1];
	std::cout<<">\n";
} 
