#include<stdio.h>
#include<string.h>
#define maxn 15 
int n;
int h[maxn][maxn],v[maxn][maxn];
int Num[maxn];//存边长为x的正方形个数 
char readchar(); 
void JudgeSquares(int k,int z);
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	
	int symbol=0,f=1;
	//读小黑点的阶数
	while(scanf("%d",&n)==1){
		if(f) f=0;
		else printf("\n");
		//初始化 
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(Num,0,sizeof(Num));
		//读边数
		int m;
		scanf("%d",&m);
		while(m--){
			char c;
			//从不是换行符开始读 
			c=readchar();
			//printf("%c\n",c); 
			int i,j;
			if(c=='H'){//行 
				scanf("%d%d",&i,&j);
				//printf("%d %d\n",i,j);
				h[i][j]=1; 
			}else{//列 
				scanf("%d%d",&j,&i);
				//printf("%d %d\n",i,j);
				v[i][j]=1;	
			} 
		} 
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d ",h[i][j]);
			printf("\n");
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d ",v[i][j]);
			printf("\n");
		}
		*/
		//判断是否形成正方形
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//判断此点是否有右边和下边 
				if(h[i][j]==1 && v[i][j]==1){
					//判断由此点构成的正方形 
					JudgeSquares(i,j);
				}
			}
		} 
		//打印
		if(symbol)
			printf("**********************************\n\n");
		int flag=1;
		printf("Problem #%d\n\n",++symbol);
		for(int i=1;i<=n;i++){
			if(Num[i]!=0){
				printf("%d square (s) of size %d\n",Num[i],i);
				flag=0;
			}
		}
		if(flag)
			printf("No completed squares can be found.\n");
	} 
	return 0;
} 
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\n' && ch!='\r')
			return ch;			
	}
} 
void JudgeSquares(int hang,int lie){
	//printf("%d %d\n",hang,lie);
	//找到向右和向下没有边的最大处
	int maxh,maxv;
	maxh=maxv=0;
	//从此点列方向出发，最多有几条边，必须是连续的 
	for(int i=hang;i<n;i++){
		if(v[i][lie]==1){
			maxv++;
		}else break; 
	}
	//从此点行方向出发，最多有几条边，必须是连续的 
	for(int j=lie;j<n;j++){
		if(h[hang][j]==1){
			maxh++;
		}else break;
	}
	//printf("%d %d\n",maxh,maxv);
	
	//获得边长的可能性
	int maxb;//最大正方形边长  
	if(maxh<maxv)
		maxb=maxh;
	else 
		maxb=maxv;
	//从最大可能的边长开始 
	for(int i=maxb;i>0;i--){
		int flag1=1;
		//从最大边长点出发向列延伸 
		for(int j=lie;j<lie+i;j++){
			//printf("%d %d\n",hang+i,j);
			if(h[hang+i][j]==0){
				flag1=0;
				break;
			}
		}
		if(flag1){				//若此边长成立 
			//列是lie+i 
			//printf("%d\n",i);
			int flag2=1;
			//从最大边长点出发向行延伸 
			for(int k=hang;k<hang+i;k++){
			//	printf("%d %d\n",k,lie+i);
				if(v[k][lie+i]==0){
					flag2=0;
					break;
				}
				
			}
			if(flag2)
				Num[i]++;		//存此边长的正方形个数 
		}
	} 
	/*
	for(int i=1;i<=n;i++)
		printf("%d ",Num[i]);
	printf("\n");    
	*/
	
}
