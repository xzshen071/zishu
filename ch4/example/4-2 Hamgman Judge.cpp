//刽子手游戏
#include<stdio.h>
#include<string.h>

//我写的代码 
#define maxn 100
int Judgecheck(int *a,int n){
	int flag=1;
	for(int i=0;i<n;i++)
		if(a[i]!=1){
			flag=0;
			break;
		}
	return flag;
	
}
void guess(char *a,char *b,int n1,int n2){
	int check[n1]={0};//检查a中的字母是否被完全猜对 
	int chance=0;//猜测次数只能为6次
	//猜完6次还没对判断为错，没猜完6次也没对判断是放弃了 
	for(int i=0;i<n2;i++){
		//查找b中的字符是否在a中 
		if(strchr(a,b[i])==NULL){
			chance++;//记录猜错次数
		} 
		else{
			//查找b[i]在a中的位置 
			for(int j=0;j<n1;j++)
				if(a[j]==b[i]){
					check[j]=1; 
					a[j]=' ';//再次猜对次字母判错 
				} 
			//当猜对一次是，判断是否赢了 
			if(Judgecheck(check,n1)){
				printf("You win.\n");
				return;	
			}
					
		}		
		
	}
	
	//如果chance小于6，放弃了，最后失败了
	if(chance<6){
		printf("You chickened out.\n");
		
	}else 
		printf("You lose.\n");
	
}
char s1[maxn],s2[maxn];//数组最好定义成全局变量，防止栈溢出 
int main(){
	int Num;
	while(scanf("%d",&Num)==1 && Num!=-1){ 
		//清零 
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		//输入单词
		scanf("%s",s1); 
		int len1=strlen(s1);//记录输入单词的长度 
		//输入玩家的猜测
		scanf("%s",s2); 
		int len2=strlen(s2);//获得玩家猜测长度 
		//判断玩家的猜测，并输出结果 
		printf("Round %d\n",Num);
		guess(s1,s2,len1,len2); 
		
	}
	
	
	return 0;
} 

/*
细节说明
1、变量名的选取：count、min、max等都是在STL已经使用的名字，写程序最好避开它们
2、变量的使用：要注意变量的设计，可以让程序优美，而且好调试，少用指针。 
*/ 
/* 
//答案
#define maxn 100
int left,chance;//还需要猜Left个位置，错chance次之后就会输
char s[maxn],s2[maxn];//答案是字符串s，玩家猜的字母序列是s2
int win,lose;//win=1表示已经赢了；lose=1表示输了
//它写的函数利用率高 
void guess(char ch){
	int bad=1;
	for(int i=0;i<strlen(s);i++)
		if(s[i]==ch){
			left--;
			s[i]=' ';
			bad=0;
		}
	if(bad)
		--chance;
	if(!chance)
		lose=1;
	if(!left)
		win=1;
		
} 

int main(){
	int rnd;
	while(scanf("%d%s%s",&rnd,s,s2)==3 && rnd!=-1){
		printf("Round %d\n",rnd);
		win=lose=0;//求解一组新数据之前要初始化
		left=strlen(s);
		chance=7;
		for(int i=0;i<strlen(s2);i++){
			guess(s2[i]);
			if(win || lose)
				break;
		} 
		//根据结果输出
		if(win)
			printf("You win.\n");
		else if(lose)
			printf("You lose.\n");
		else
			printf("You chickened out.\n"); 
		
	}
	
	return 0;
	
	
}
*/ 

