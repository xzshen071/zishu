#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//纵横字谜的答案
	//读入 
	const int maxn=20;
	int r,c;
	char s[maxn][maxn]; 
	int count1=0;
	int num[maxn][maxn],k=0;//存编号
	memset(num,0,sizeof(num));//编号初始化 
	while(scanf("%d%d",&r,&c)==2 && r!=0 ){
		//读入网格
		for(int i=0;i<r;i++){
			scanf("%s",s[i]);
			//编号，一行一行来 
			for(int j=0;j<c;j++){//条件：左边或上面是边界或者黑格 
				if(s[i][j]!='*'){
					if(j-1<0 || i-1<0 || s[i][j-1]=='*' || s[i-1][j]=='*')
				 		num[i][j]=++k;	
				}
			}
			
		}
		//输出横向单词:判断条件：1、碰见'*',到达表格尾部 
		printf("puzzle #%d:\nAcross\n",++count1);
		for(int i=0;i<r;i++){
			if(i)
				printf("\n");
			int flag=1;
			for(int j=0;j<c;j++){
				//输出每一行 
				if(s[i][j]!='*'){
					if(flag){
						printf("%d.",num[i][j]);
						flag=0;
					}
					printf("%c",s[i][j]);
					
				}else{
					flag=1;
					if(j!=0 && j!=c-1) 
						printf("\n");
				}
				
			}
		}	
		//输出纵向单词
		printf("\nDown\n");
		int sign=0;//判断是否所有的纵向单词输出完毕 
		for(int count2=0;count2<r;count2++){//处理每一行 
			for(int j=0;j<c;j++){
				int flag=1;
				for(int i=count2;i<r;i++){
					//输出每一列 
					if(s[i][j]!='*'){
						if(num[i][j]==-1)//输出过了则不打印，继续循环 
							continue;
						else if(flag){//打印次数 
							if(sign){
								printf("\n");
							}
							sign=1;//第一行不打印 
							printf("%d.",num[i][j]);
							flag=0;
						}
						printf("%c",s[i][j]);
						num[i][j]=-1;//让输出过的字母位置-1 
					
					}else{
					
						break;
					}
					
				}
	
				
			}	
		} 
	
	
	
	}	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
