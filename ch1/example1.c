#include<stdio.h>
#include<math.h>
int main(){
	/* ����Բ������� 
	const float pi=acos(-1.0);//const��ʾ����һ�����ɱ�ĳ���,���������������� 
	float r,h;
	scanf("%f%f",&r,&h);
	
	printf("Area=%.3f\n",2*pi*r*r+2*pi*r*h);
	*/

	/*��ȡ��λ���ĸ���ʮ����λ 
	int num,ge,shi,bai,result;
	scanf("%d",&num);
	ge=num%10;
	shi=num/10%10;
	bai=num/100;
	result=ge*100+shi*10+bai;
	
	printf("%03d",result);
	/*
	%3d--����ָ����ȣ��������߲��ո�
	%-3d--�����
	%03d---һ����߲�0 �ĵȿ��ʽ,��������12,%03d��������: 012 
	*/
	
	/*������ֻ��Ϊ�˽�����⣬������չʾ�Լ��Ĵ���д�Ķ�߼� 
	//a,b�������� 
	int a,b;
	//int t;
	scanf("%d%d",&a,&b);
	//b=t;
	
	printf("%d %d\n",b,a);
	*/
	
	/*����ͬ�� 
	int ji,tu,n,m;
	scanf("%d%d",&n,&m);
	//flag1=(m-2*n)%2;
	//flag2=(4*n-m)%2;//Ҫ��֤��������m��ż������ 
	tu=(m-2*n)/2;
	ji=n-tu;
	if(m%2!=0||tu<0||ji<0){
		printf("No answer");
		
	}else{
		printf("%d %d",ji,tu);
		
	}
	*/ 
	
	/*����һ��ifǶ�ף�ifǶ�������Ѿ�������������ˣ������ټ�if
	//��if��ʱ��ע��˭��˭��һ�������
	/*eg:
	if(){
		...
	}else if(){
		...		
	}else if(){
		if(){
			...
		}else{
			...
		}
	}else if(){
		...
	}else{
		...
	}
	
	//��С����������յ��������� 
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<=b && b<=c)
		printf("%d %d %d",a,b,c);
	else if(a<=c && c<=b)
		printf("%d %d %d",a,c,b);
	else if(b<=a && a<=c)
		printf("%d %d %d",b,a,c);
	else if(b<=c && c<=a)
		printf("%d %d %d",b,c,a);
	else if(c<=a && a<=b)
		printf("%d %d %d",c,a,b);
	else if(c<=b && b<=a)
		printf("%d %d %d",c,b,a);
	return 0;
	
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b){//ִ�����֮��a<=b 
		t=a;
		a=b;
		b=t;
	}
	if(a>c){//ִ�����֮��a<=c,��a<=b��Ȼ���� 
		t=a;
		a=c;
		c=t;	
	}
	if(b>c){
		t=b;
		b=c;
		c=t;
	}
	
	printf("%d %d %d",a,b,c);
	*/ 
	
	/*int�Ǿ�ȷֵ��float�ǹ���ֵ������1/0�ᱨ���1.0/0.0���� 
	int a;
	a=1/0;
	printf("%d",1/0);
	 */
	
	/*����%d������ĸ�ʽ�ַ��������޷�ֱ�����
	//�Դ�C���Թ涨ת���ַ�%%��ֵΪԭʼ��%���š�
	int a,b;
	//scanf("%d%d",&a,&b);
	printf("%%d"); 
	 */
	 
	/* 
	//int�����������ֵΪ2147483647����СֵΪ-2147483647
	//�����Ա�ʾ4���ֽڵ�����32λ������λ�Ƿ���λ����Χ��-(2^31-1)~(2^31-1) 
	int c; 
	c=-2147483647; 
	*/
	
	/* 
	//double��ȷ������λС�������͵�λ���йأ���ȷ����λ��Ӧ��Ϊ16λ��ʮ���ƣ���doubleΪ64λ��8���ֽڣ� 
    //������ -1.79769313486232E308 �� -4.94065645841247E-324����������ʱ���Ǵ� 4.94065645841247E-324 �� 1.79769313486232E308��
	printf("%f",-1.7976E+308); 
	*/
	
	/* 
	//&&��||��!���ȼ�
	int a,b,c;
	a=1;
	b=1;
	c=0;
	if( a || b && c)
		printf("&&>||\n");
	else
		printf("||>&&\n");

	a=0;
	b=1;
	c=0;	 
	if( ! a && b && c)
		printf("&&>!\n");
	else
		printf("!>&&\n"); 
	//����!>&&>|| 
	 */ 
	
	/* 
	//if(){}else{} 
	int a,b,x,y;
	a=0;b=0;x=0;y=0;
	if(a)
		if(b)
			x++;
		else
			y++;
	printf("%d %d\n",x,y);
	a=1;
	if(a)
		if(b)
			x++;
		else
			y++;
	printf("%d %d\n",x,y);		 
	//else���������if 
	//��﷽ʽ
	 	if(a){ 
			if(b)
				x++;
			else
				y++;
	 	} 
	*/ 
	
	return 0; 
}
