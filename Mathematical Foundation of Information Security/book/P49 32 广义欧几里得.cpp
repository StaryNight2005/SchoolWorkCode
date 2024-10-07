#include<iostream>
using namespace std;

void Extended_Euclidean(int a,int b){
	cout<<"\ta="<<a<<",\tb="<<b<<endl;
	int r_2=a,r_1=b,s_2=1,s_1=0,t_2=0,t_1=1,q;
	cout<<"j"<<"\ts_j"<<"\tt_j"<<"\tq_j+1"<<"\tr_j+1"<<endl;
	cout<<"-3"<<"\t\t\t\t"<<r_2<<endl;
	cout<<"-2"<<"\t"<<s_2<<"\t"<<t_2<<"\t\t"<<r_1<<endl;
	int j=-1;
	while(r_1){
	q=r_2/r_1;
	int temp=r_2;
	r_2=r_1;
	r_1=temp-q*r_1;
	temp=s_2;
	s_2=s_1;
	s_1=temp-q*s_1;
	temp=t_2;
	t_2=t_1;
	t_1=temp-q*t_1;
	cout<<j++<<"\t"<<s_2<<"\t"<<t_2<<"\t"<<q<<"\t"<<r_1<<endl;
	}
	int s=s_2,t=t_2;
	cout<<"ËùÒÔ£¬";
	if(t>0)
	cout<<s<<"*"<<a<<"+"<<t<<"*"<<b<<"="<<r_2<<endl;
	else
	cout<<s<<"*"<<a<<t<<"*"<<b<<"="<<r_2<<endl;
}
int main(){
	int a[4]={1613,2947,20041,1107};
	int b[4]={3589,3772,37516,822916};
	cout<<"½â£º\n";
	for(int i=0;i<4;i++){
		Extended_Euclidean(a[i],b[i]);
		cout<<endl;
	}
	return 0;
}
