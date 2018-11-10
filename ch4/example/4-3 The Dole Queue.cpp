//救济金发放
#include<stdio.h>
#include<string.h>
#define maxn 25
int s[maxn],n,k,m;
//p是当前位置，步长是d（顺时针为-1，逆时针为1），t为数数次数，返回新位置 
int leave(int p,int d,int t);
int main(){
	//输入
	int k,m;
	scanf("%d%d%d",&n,&k,&m); 
	//初始化编号 
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++){
		s[i]=i;
	} 
	//发放救济金
	//结束条件
	int left=n;//剩余人数 
	//初始值
	int p1=n;
	int p2=1; 
	while(left){
		//挑选离开的人
		//逆时针 
		p1=leave(p1,1,k);//第一次从后一位开始数 
		//顺时针
		p2=leave(p2,-1,m); 
		printf("%3d",p1);
		left--;
		s[p1]=s[p2]=0;
		if(p2!=p1){
			printf("%3d",p2);
			left--;
		}
		if(left)
			printf(",");		
		
		
	} 
	
	return 0;
}
int leave(int p,int d,int t){
	//查找次数 
	while(t--){
		do{
			//加n是为了防止变成负数，(p+d+n-1)%n表示的范围：0~n-1，所以在改变位置之前要-1，即在位置n的时候-1变成n-1,然后映射为n 
			p=(p+d+n-1)%n +1;
			printf("%d\n",p); 
		}while(s[p]==0);//走到下一个非0数字 
		
	}
	//离开的人让其位置的数字为0
	//s[p]=0;//不能放这里，因为会影响下一次调用的结果，即不存在顺逆相同的情况 
	return p;
	
	
}
