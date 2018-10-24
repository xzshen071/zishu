#include<stdio.h>
#include<math.h>
int main(){
	/* 计算圆柱表面积 
	const float pi=acos(-1.0);//const表示它是一个不可变的常数,尽量用它声明常数 
	float r,h;
	scanf("%f%f",&r,&h);
	
	printf("Area=%.3f\n",2*pi*r*r+2*pi*r*h);
	*/

	/*提取三位数的个、十、百位 
	int num,ge,shi,bai,result;
	scanf("%d",&num);
	ge=num%10;
	shi=num/10%10;
	bai=num/100;
	result=ge*100+shi*10+bai;
	
	printf("%03d",result);
	/*
	%3d--可以指定宽度，不足的左边补空格
	%-3d--左对齐
	%03d---一种左边补0 的等宽格式,比如数字12,%03d出来就是: 012 
	*/
	
	/*竞赛中只是为了解决问题，而不是展示自己的代码写的多高级 
	//a,b变量互换 
	int a,b;
	//int t;
	scanf("%d%d",&a,&b);
	//b=t;
	
	printf("%d %d\n",b,a);
	*/
	
	/*鸡兔同笼 
	int ji,tu,n,m;
	scanf("%d%d",&n,&m);
	//flag1=(m-2*n)%2;
	//flag2=(4*n-m)%2;//要保证是整数，m是偶数就行 
	tu=(m-2*n)/2;
	ji=n-tu;
	if(m%2!=0||tu<0||ji<0){
		printf("No answer");
		
	}else{
		printf("%d %d",ji,tu);
		
	}
	*/ 
	
	/*考虑一下if嵌套，if嵌套是你已经满足这个条件了，里面再加if
	//用if的时候注意谁和谁是一个层面的
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
	
	//从小到大输出接收到的三个数 
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
	if(a>b){//执行完毕之后a<=b 
		t=a;
		a=b;
		b=t;
	}
	if(a>c){//执行完毕之后a<=c,且a<=b仍然成立 
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
	
	/*int是精确值，float是估计值，所以1/0会报错而1.0/0.0不会 
	int a;
	a=1/0;
	printf("%d",1/0);
	 */
	
	/*由于%d是输出的格式字符，所以无法直接输出
	//对此C语言规定转义字符%%，值为原始的%符号。
	int a,b;
	//scanf("%d%d",&a,&b);
	printf("%%d"); 
	 */
	 
	/* 
	//int型整数的最大值为2147483647，最小值为-2147483647
	//即可以表示4个字节的数，32位，但首位是符号位，范围：-(2^31-1)~(2^31-1) 
	int c; 
	c=-2147483647; 
	*/
	
	/* 
	//double精确到多少位小数跟整型的位数有关，精确的总位数应该为16位（十进制）。double为64位（8个字节） 
    //负数从 -1.79769313486232E308 到 -4.94065645841247E-324，而正数的时候是从 4.94065645841247E-324 到 1.79769313486232E308。
	printf("%f",-1.7976E+308); 
	*/
	
	/* 
	//&&、||、!优先级
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
	//结论!>&&>|| 
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
	//else紧跟最近得if 
	//表达方式
	 	if(a){ 
			if(b)
				x++;
			else
				y++;
	 	} 
	*/ 
	
	return 0; 
}
