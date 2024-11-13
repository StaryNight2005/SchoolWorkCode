//创建日期：2024年11月13日
//创建人：StaryNight2005
//程序说明： 通过递归统计树的叶子节点数 
//输入示例： 5
//输出示例： 16



#include<stdio.h>
#include<stdlib.h>

typedef struct BinTree {
	int num;
	struct BinTree* Parent;
	struct BinTree* Left;
	struct BinTree* Right;
}bin, * Bin;

//创建新节点 
Bin CreateCode(Bin Par, int num) {
	Bin newcode = (Bin)malloc(sizeof(bin));

	newcode->Parent = Par;
	newcode->num = num;
	newcode->Left = NULL;
	newcode->Right = NULL;

	return newcode;
}

//递归建立n层完全满二叉树 
void CreateTree(Bin* Tree, int n) {
	if (n == 0) {
		return;
	}

	if (*Tree == NULL) {
	
		*Tree = CreateCode(NULL, 0);
		n--;
	}

	//递归建立左子树 
	if ((*Tree)->Left == NULL) {
		
		(*Tree)->Left = CreateCode(*Tree, 0);
		
		CreateTree(&((*Tree)->Left), n - 1);//左子树为根建立新树 
	}

	//递归建立右子树 
	if ((*Tree)->Right == NULL) {

		(*Tree)->Right = CreateCode(*Tree, 0);
		
		CreateTree(&((*Tree)->Right), n - 1);//右子树为根建立新树 
	}
}

//统计叶子节点数 
int CountLeaf(Bin Tree){
	int res = 0;
	
	//如果为叶子节点，统计 
	if(Tree->Left == NULL && Tree->Right == NULL){
		return 1;
	}
	
	//不是叶子，统计左子树（如果存在的话） 
	if(Tree->Left)
		res += CountLeaf(Tree->Left);
	
	//不是叶子，统计右子树（如果存在的话） 
	if(Tree->Right)
		res += CountLeaf(Tree->Right);
		
	return res;
} 

//释放树 
void DestroyTree(Bin* Tree){
	
	//释放左子树 
	if((*Tree)->Left){
		DestroyTree(&((*Tree)->Left));
		
		(*Tree)->Left = NULL;
	}
	
	//释放右子树 
	if((*Tree)->Right){
		DestroyTree(&(*Tree)->Right);
		
		(*Tree)->Right = NULL;
	}
	
	//释放自己 
	if((*Tree)->Left == NULL && (*Tree)->Right == NULL){
		free(*Tree);
	}
} 

int main() {

	Bin tree = NULL;
	int high;
	
	printf("请输入创建的树的高度:");
	scanf("%d", &high);

	CreateTree(&tree, high);
	
	printf("该树的叶子节点数为：%d\n",CountLeaf(tree));
	
	DestroyTree(&tree); 
	
	return 0;
}
