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
	int weim=-1;//������Ip��ַ�����λ 
	while(n--){
		//�ֳ�4���ֶ�
		memset(ip,0,sizeof(ip));
		scanf("%d.%d.%d.%d",&ip[3],&ip[2],&ip[1],&ip[0]); 
		//printf("%d.%d.%d.%d\n",ip[3],ip[2],ip[1],ip[0]);
		//��ip[3]��ʼ���ӵ�һ��������1����һ��������0����¼λ�� 
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
	//��������ַ
	int flag1=0,flag2=0;
	for(int i=3;i>=0;i--){
		if(flag1)
			printf(".");
		flag1=1;
		if(weim>i*8){
			weim-=i*8;
			//������weim��������weim 
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
	//�����������
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
	//������ߵ�һ��1 
	do{
		er=a%2;
		num++;
		a/=2;	
	}while(er!=1);
	//����ߵ�һ��1��ĵ�һ��0 
	while(a%2!=0){
		num++;
		a/=2;
		
	}
	//printf("%d\n",num);
	
}
