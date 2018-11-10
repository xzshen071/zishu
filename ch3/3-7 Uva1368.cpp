#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 1005

int m,n;
//打印次数最多的字母，且返回这一列的Hamming距离 
int PrintMax(int a,int c,int g,int t){
		int Num[]={a,c,g,t},max=-999999,symbol;
		//遍历，找打最大值且记录下表 
		for(int i=0;i<4;i++){
			if(Num[i]>max){
				max=Num[i];					//表示最多相同字母的个数 
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
		
		return (m - max); 			
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	while(scanf("%d", &t) == 1) {
		while(t--) {
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
            
            //比较每一位哪个字母出现的次数多
            int h_dist=0;				//记录总的hamming距离 
            for(int i=0;i<n;i++){
                
                //打印次数最多的字母，且返回这一列的Hamming距离 
                h_dist+=PrintMax(A[i],C[i],G[i],T[i]); 
                //printf("%d %d %d %d\n",A[i],C[i],G[i],T[i]); 
            } 
            printf("\n%d\n",h_dist);	
		}
	}
	
	return 0;
}
