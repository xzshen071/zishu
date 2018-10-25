#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxn 30
int ip[6];
int num;
int yanma[9]={255,254,252,248,240,224,192,128,0};
void chang_er(int a); 
int main(){
	int n;
	scanf("%d",&n);
	int weim=-1;//存所有Ip地址的最大位 
	while(n--){
		//分成4部分读
		memset(ip,0,sizeof(ip));
		scanf("%d.%d.%d.%d",&ip[3],&ip[2],&ip[1],&ip[0]); 
		//printf("%d.%d.%d.%d\n",ip[3],ip[2],ip[1],ip[0]);
		//从ip[3]开始，从第一个二进制1到下一个二进制0，记录位数 
		num=0;
		for(int i=0;i<5;i++){
			chang_er(ip[i]);
			if(num<8*(i+1)){
				break;
			}
		}
		if(num>weim)
			weim=num; 
			
		//printf("%d\n",weim);
		
	}
	//输出网络地址
	int flag1=0,flag2=0;
	for(int i=3;i>=0;i--){
		if(flag1)
			printf(".");
		flag1=1;
		if(weim>i*8){
			weim-=i*8;
			//先左移weim，再右移weim 
			ip[i]=ip[i]>>weim;
			ip[i]=ip[i]<<weim;
			printf("%d",ip[i]);
			flag2=i; 
			break;
			
		}else
			printf("%d",ip[i]);
			
	}
	while(flag2--){
		printf(".%d",0);
	}
	printf("\n");
	//输出子网掩码
	flag1=0,flag2=0;
	for(int i=3;i>=0;i--){
		if(flag1)
			printf(".");
		flag1=1;
		if(weim>i*8){
			weim-=i*8;
			printf("%d",yanma[weim]);
			flag2=i;
			break;
			
		}else
			printf("%d",yanma[0]);
	} 
	while(flag2--){
		printf(".%d",0);
	}
	printf("\n");	 
	
	return 0;
} 
void chang_er(int a){
	int er;
	//到最左边第一个1 
	do{
		er=a%2;
		num++;
		a/=2;	
	}while(er!=1);
	//最左边第一个1后的第一个0 
	while(a%2!=0){
		num++;
		a/=2;
		
	}
	//printf("%d\n",num);
	
}
