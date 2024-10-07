//作业3：运用欧几里得除法，将十进制数转化成二进制
#include<iostream>

int main(){
	int a,b=2,r;
	std::cout<<"根据a=bq+r将十进制转化成二进制数：\n";
	std::cout<<"Please input a number:\n";
	std::cin>>a;
	r=a;
	std::string bin="";
	std::cout<<"逐次运用欧几里得除法，我们有：\n";
	while(a){
		std::cout<<a<<" = "<<b<<" * "<<a/b<<" + "<<a%b<<std::endl;
		bin+=a%b+'0';
		a/=b;
	}
	std::cout<<std::endl<<"因此，"<<r<<"=<";
	for(int i=bin.length();i>0;i--)
	std::cout<<bin[i-1];
	std::cout<<">\n";
} 
