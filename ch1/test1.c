#include<stdio.h>
#include<math.h>
int main(){
	/* 
	//ƽ����
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	printf("%.3f",(a+b+c)/3);
	*/
	
	/* 
	//�¶�
	float f,c;
	scanf("%f",&f);
	c=5*(f-32)/9;
	printf("%.3f",c);
	*/
	
	/*
	//������
	int n,sum;
	sum=0;
	scanf("%d",&n);
	for(;n>=1;n--){
		sum=sum+n;
		
	}
	printf("%d",sum);
	//for(i=1;i<=n;i++)
	//	sum=sum+i;
	*/
	
	/*
	//���Һ�����
	const float pi=acos(-1.0);
	int n;
	scanf("%d",&n);
	printf("%f %f",sin((n*pi)/180),cos((n*pi)/180));
	*/
	
	/*
	//����
	int n,money;
	scanf("%d",&n);
	money=n*95;
	if(money<300)
		printf("%.2f",(float)money);
	else
		printf("%.2f",money*0.85);
	*/

	/*
	//������
	int a,b,c,tmp;
	scanf("%d%d%d",&a,&b,&c);
	//������,������a<=b<=c
	if(a>b){//��֤a<=b
		tmp=a;
		a=b;
		b=tmp;	
	}
	if(a>c){//��֤a<=c,�ұ�֤a<=b
		tmp=a;
		a=c;
		c=tmp;			
	}
	if(b>c){
		tmp=b;
		b=c;
		c=tmp;		
	}
	//���������ε�����
	tmp=a*a+b*b;
	if(a+b<=c || c-b>=a)
		printf("not a triangle");		
	else if(tmp==c*c)
		printf("yes");
	else
		printf("no");
	*/

	/*
	//��ݣ��ж�����
	int year;
	scanf("%d",&year);
	if((year%4==0 && year%100!=0) || year%400==0)
		printf("yes");
	else
		printf("no");
	*/	
	
	return 0;
	
}
