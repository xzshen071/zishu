#include<stdio.h>
#define maxn 900
int ge[maxn];
void Sort_Int(int a[],int n); 
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	int n,m,kase=0;
	//输入网格规模 
	while(scanf("%d%d",&n,&m)==2 && n!=0){
		//存每个网格的海拔高度
		for(int i=0;i<n*m;i++)
			scanf("%d",&ge[i]);		
		//存网格内雨水的总体积
		int V;
		scanf("%d",&V);
		//对网格进行从小到大排序
		Sort_Int(ge,n*m);
		/*
		for(int i=0;i<n*m;i++){
			printf("%d ",ge[i]);
		}
		printf("\n");
		*/
		//计算输出水位的海拔高度及有多少百分比的区域有水
		double percent,h;
		int num=0;//被淹住宅的个数 
		for(int i=0;i<n*m;i++){
			num++;
			//总体积
			V+=ge[i]*100;
			//平均海拔高度
			h=(double)V/(100*(i+1)); 
			if(h<=ge[i+1])
				break;
			
		} 
		printf("Region %d\n",++kase);
		printf("Water level is %.2f meters.\n",h);
		printf("%.2f percent of the region is under water.\n\n",(double)num/(n*m)*100);
		
	}
	
	
	return 0;
} 
void Sort_Int(int a[],int n){
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp=a[i];
        for(j=i;j>0&&a[j-1]>temp;--j)
            a[j]=a[j-1];
        a[j]=temp;
    }
    
}
