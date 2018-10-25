#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 1005
void PrintMax(int a,int c,int g,int t){
		int Num[]={a,c,g,t},max=-999999,symbol;
		//遍历，找打最大值且记录下表 
		for(int i=0;i<4;i++){
			if(Num[i]>max){
				max=Num[i];
				symbol=i;
				
			}
		}
		//根据下标打印
		switch(symbol){
			case 0:
				printf("A");
				break;
			case 1:
				printf("C");
				break;
			case 2:
				printf("G");
				break;
			case 3:
				printf("T");
				break;
				
			
		} 
				
}
int main(){
	//DNA序列
	int m,n;
	char s[maxn];
	//接收m和n
	scanf("%d%d",&m,&n);//m是个数，n是长度 
	//开4个数组（A、C、T、G）,存每一个位置出现的次数
	int A[maxn],C[maxn],T[maxn],G[maxn];
	//数组次数初始化
	memset(A,0,sizeof(A));
	memset(C,0,sizeof(C));
	memset(T,0,sizeof(T));
	memset(G,0,sizeof(G)); 
	//每次读一个数组
	for(int i=0;i<m;i++){

		scanf("%s",s); 
		//记录A、C、G、T数组 
		for(int j=0;j<n;j++){
			switch(s[j]){
				case 'A':
					A[j]=++A[j];
					break;
				case 'C':
					C[j]=++C[j];
					break;
				case 'T':
					T[j]=++T[j];
					break;
				case 'G':
					G[j]=++G[j];
					break;
			
			}
		}
		
	}
	printf("\n");
	
	//比较每一位哪个字母出现的次数多
	for(int i=0;i<n;i++){
		
		//打印次数最多的字母
		PrintMax(A[i],C[i],G[i],T[i]); 
		//printf("%d %d %d %d\n",A[i],C[i],G[i],T[i]);
		
		
	} 
	printf("\n");	
	

	
	
	
	return 0;
}
