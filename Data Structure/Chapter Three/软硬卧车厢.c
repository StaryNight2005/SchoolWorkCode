//上传日期：2024年10月28日
//创建人：StaryNight2005
//程序说明： 模拟火车进出站将软卧车厢放在硬卧车厢前，首先让软卧先全部入站，再让硬卧入站 
//输入示例：5 SHSHS
//输出示例：H H S S S



#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
	char type;
	struct Stack* next;
}Stack,*STA;

void PushStack(STA* sta,char data){
	STA newsta = (STA)malloc(sizeof(Stack));
	newsta->type = data;
	newsta->next = NULL;
	
	if(!*sta){
		*sta = newsta;
	}
	else{
		newsta->next = *sta;
		*sta = newsta;
	}
}

void PopStack(STA* sta){
	if(*sta == NULL){
		return;
	}
	
	STA temp = *sta;
	*sta = temp->next;
	free(temp);
}

void ShowStack(STA sta){
	while(sta != NULL){
		printf("%c ",sta->type);
		sta = sta->next;
	}
	
}

void DestroyStack(STA* sta){
	while(*sta != NULL){
		PopStack(sta);
	}
}


int main(){
	int n;
	char type;
	STA sta,temp;
	
	sta = temp = NULL; 
	
	printf("请输入车厢节数\n");
	scanf("%d",&n);
	
	printf("请输入车厢初始情况\n");
	{int i;
	for(i = 0; i < n; i++){
		scanf(" %c",&type);
		
		if(type == 'S')
			PushStack(&sta,type);
		else
			PushStack(&temp,type);
	}
	}
	
	while(temp != NULL){
		type = temp->type;
		PopStack(&temp);
		PushStack(&sta,type);
	}
	
	ShowStack(sta);
	
	DestroyStack(&sta);
	
	return 0;
}
