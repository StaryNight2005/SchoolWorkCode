//创建日期：2024年10月28日
//创建人：StaryNight2005
//程序说明：创建循环队列，并实现队列的数据入队列和出队列。测试案例进行3次入队列和一次出队列 
//输入示例：无 
//输出示例：1 2 3  1 2 
//满队列判断，length是否与队列最大值相等 

#include <stdio.h>
#include <stdlib.h>

#define LineMax 10

typedef struct line{
	int data;
	struct line* next;
}line,*Line; 

typedef struct queue{
	Line rear;
	int length;
}queue;

Line CreatLine(int n){
	Line l = (Line)malloc(sizeof(line));
	
	l->data = n;
	l->next = NULL;
	
	return l;
}

Line InitLine(){
	Line rear = CreatLine(0);
	Line temp = rear;
	Line head = rear;
	int i;
	
	for(i=1;i<LineMax;i++){
		rear = CreatLine(0);
		temp->next = rear;
		temp = rear;
	}
	rear->next = head;
	
	//初始队列为空 
	rear = head;
	return rear;
}

void PushLine(Line* tail,int data){
	(*tail)->data = data;
	*tail = (*tail)->next;
	
}

void PopLine(Line* tail){
	Line temp = *tail;
	while((*tail)->next != temp){
		*tail = (*tail)->next;
	}
}

void DestroyLine(Line* tail){
	Line temp = (*tail)->next;
	Line tem = temp->next;
	
	while(tem != *tail){
		free(temp);
		temp = tem;
		tem = temp->next;
	}
	free(*tail);
}


queue InitQueue(){
	queue que;
	que.rear = InitLine();
	que.length = 0;
	return que;
}

void PushQueue(queue *que,int data){
	PushLine(&(que->rear),data);
	que->length++;
}

void PopQueue(queue* que){
	que->length--;
	PopLine(&(que->rear));
}

void ShowQue(queue* que){
	int i = 0;
	Line temp = que->rear;
	
	for(;i<LineMax-que->length;i++){
		temp = temp->next;
	}
	
	while(temp != que->rear){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

void DestroyQue(queue* que){
	DestroyLine(&(que->rear));
	que->length = 0;
}


int main(){
	queue que = InitQueue(); 
	ShowQue(&que);
	printf("\n");
	
	PushQueue(&que,1);
	PushQueue(&que,2);
	PushQueue(&que,3);
	ShowQue(&que);
	printf("\n");
	
	PopQueue(&que);
	ShowQue(&que);
	
	DestroyQue(&que);
	return 0;
}
