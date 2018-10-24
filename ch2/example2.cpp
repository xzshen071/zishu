//保存为.cpp文件，想象成是c与c++共同的部分 
#include<stdio.h>
#include<math.h>
//#include<time.h>//定时器 
//#define INF 99999999 
//#define LOCAL//删除它即可防止没有删除程序中的文件重定向
//也可以在编译选项中定义LOCAL，格式gcc example.cpp -DLOCAL,会生成example.exe文件，你必须先运行，才能看到结果 
int main(){
/* 
	//打印1~n 
	int n;
	scanf("%d",&n);
	for(int i =1;i<=n;i++)
		printf("%d\n",i);
	//printf("%d",i); //会报错，因为i只定义再循环体内
	//这样做会尽量缩小变量定义得范围，程序写多了之后，优点会展现出来 
*/

/*
	//完全平方数
	//浮点运算可能存在误差。在进行浮点数比较时，应考虑到浮点误差  
	for(int a=1;a<=9;a++)
		for(int b=0;b<=9;b++){
			int n=a*1100+b*11;//这里才开始使用n,因此在这里定义n 
			int m=floor(sqrt(n)+0.5);//sqrt(n)为浮点数，为了减小浮点数的误差，改为四舍五入，即floor(x+0.5)
			//误差可以这么理解：假设经过大量运算后，由于误差的影响，整数1变成了0.9999999，floor的结果将会是0而不是1，floor(x)函数是取不超过x的整数 
			if((m*m)==n)
				printf("%d\n",n);
				
		}
		
	//第二种方法，可以避免浮点数的误差	
	for(int x=1;;x++){
		int n=x*x;
		if(n<1000)
			continue;
		if(n>9999)
			break;
		int aa=n/100;
		int bb=n%100;
		if(aa/10 == aa%10 && bb/10 == bb%10)
			printf("%d\n",n);		
	}	
*/

/* 
	//不要忘记测试，一个看上去正确的程序可能隐含错误，可用输出中间结果差错 
	//int n;//得用long long类型，因为n得使<=10^9成立 
	int n2;
	int count=0;
	scanf("%d",&n2);//为了避开输入输出不确定是%lld或者%l64d的问题,因为输入的值并没有溢出 
	long long n=n2;//用long long型的n代替n2做运算 
	while(n>1){
		if(n%2==1)
			n=3*n+1;
		else
			n=n/2;
		//printf("%d\n",n);//查错，输入987654321时，可判定是int类型溢出（3*n+1） ,int在比赛中一般为32位，C99没有规定确切的大小，所以得加大范围 
		count++;
		
	}
	//printf("%lld",count);//%d得改，但是在Linux下是%lld，在windows有时候是%l64d,为了保险起见，可以用后面介绍得C++流，或者编写自定义输入输出函数 
	printf("%d",count);
*/

/*
	//近似计算
	double sum=0;
	int flag=1;
	for(int i=1;;i+=2){
		if(flag){
			sum+=1.0/i;
			flag=0;
		}
		else{
			sum-=1.0/i;
			flag=1;
		}
		if((1.0/i) < 1e-6)
			break;
	}	 
	printf("%.6f\n",sum);
	//第二种方法 
	double sum=0;
	for(int i=0;;i++){
		double term=1.0/(i*2+1);
		if(i%2==0)
			sum+=term;
		else
			sum-=term;
		if(term < 1e-6)
			break;
	}	 
	printf("%.6f\n",sum);
	//第三种方法，改用do{}while();
	double sum=0;
	double term;
	int flag=1;
	int i=1;
	do{
		term=1.0/i;
		if(flag){
			sum+=term;
			flag=0;
		}
		else{
			sum-=term;
			flag=1;
		}
		i+=2;
	}while(term>=1e-6);//do{}while(条件判断);是先做计算再判断 
	printf("%.6f\n",sum);
*/

/*
	//阶乘之和（之取末6位） 
	//当n>=25之后末6位都是940313，因为25！的值末尾有6个0：25/5+5/5=6个， 所以25！末6位的值和n=24时相同的。 
	const int mod=1000000;//不变的常量最好用const定义 
	int n,S=0;
	scanf("%d",&n);
	//if(n>24)
		//n=24; 
	//long long S=0;//只是取末6位。可以不用long long类型。 
	//原理：要计算只包含加法、减法、乘法和除法的整数表达式除以正整数n取余，可以在每次计算之后对n取余，结果不变 
	for(int i=1;i<=n;i++){
		//long long sum=1;
		int sum=1;//每循环一次重新声明sum 
		for(int j=i;j>0;j--){
			sum=(sum*j)%mod;
		}//运行速度将会很慢 
		//printf("%lld\n",sum);
		S=(S+sum)%mod;
	}
	printf("%d\n",S);
	//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);//除CLOCKS_PER_SEC得到以秒为单位的值 
	//用计时器计算程序运行时间时，存在键盘输入时，可能会算入键盘输入的时间，所以可在windows命令行下执行echo 20|abc，其中20为输入的值，abc为程序名		
	//很多程序与n存在近似简单关系，可以通过计时器验证这一关系 
*/

/* 
	#ifdef LOCAL
	//输入输出重定向，使得scanf从input.txt中读入，printf写入文件output.txt。不过有些竞赛可能不允许，又或者不允许此方式，要仔细阅读注意事项 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif//若定义了LOCAL，才编译其中的代码 
	int x,n=0,min=INF,max=-INF,s=0;//变量在为赋值之前的值是不确定的。特别的它不一定等于0 
	//printf("%d %d\n",&min,&max); 
	while(scanf("%d",&x)==1){//scanf函数有返回值，返回值是成功输入的变量个数，当输入结束时，scanf函数无法再次读取x，将返回0 
	//输入存在一个问题：因为enter、tab、space都不能表示输入结束，所以输入完按enter不会有输出。
	//在windows下，输入完毕后先按enter，再按ctrl+z，最后再按enter即可结束输入 
		s+=x;
		if(x<min)
			min=x;
		if(x>max)
			max=x;
		n++;
		
	}
 
	printf("%d %d %.3f",min,max,(double)s/n);//代码完成后需注释，中途可以拿来测试 
*/ 

/* 
	//禁止重定向方式，如何处理 
	FILE *fin,*fout;
	fin=fopen("input.txt","rb");
	fout=fopen("data.txt","wb");
	//用此方式可以轻松改写成标准的输入输出，即 
	//fin=stdin;//stdin指的是标准的输入 
	//fout=stdout;
	int x,n=0,min=INF,max=-INF,s=0;
	while(fscanf(fin,"%d",&x)==1){//注意用此方式的时候要用fsacnf与fprintf，注意格式 
 
		s+=x;
		if(x<min)
			min=x;
		if(x>max)
			max=x;
		n++;
		
	}
 
	fprintf(fout,"%d %d %.3f",min,max,(double)s/n);
	//必须有下面这两个语句 
	fclose(fin);
	fclose(fout);
*/

/* 
 	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int count=0;
	while(1){
		int min=INF,max=-INF,x,n,s=0;
		scanf("%d",&n);
		if(n==0)
			break;
		//count++;
		for(int i=n;i>0;i--){
			scanf("%d",&x);
			s+=x;
			if(x<min)
				min=x;
			if(x>max)
				max=x;
		}
		if(count)
			printf("\n"); 
		printf("Case %d: %d %d %.3f\n",++count,min,max,(double)s/n);
		//printf("\n");//错误，因为最后一组数据的输出以回车符结束，之后不会有空行 
	}

	//编译时加-Wall,会给出很多警告信息（不是所有），以方便差错。有些‘错误’程序时合法的，只是这些动作不是所期望的 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,count=0,x,s=0;
	while(scanf("%d",&n)==1 && n){
		int min=INF,max=-INF,s=0;//变量定义在循环内，防止特殊情况下，值不发生改变 。即每次循环值重置 
		//两个模块有同名变量时，内层变量会屏蔽外层变量，有时候会引起很隐蔽的错误 
		for(int i=n;i>0;i--){
			scanf("%d",&x);
			s+=x;
			if(x<min)
				min=x;
			if(x>max)
				max=x;
		}
		if(count)
			printf("\n");
		printf("Case %d: %d %d %.3f\n",++count,min,max,(double)s/n);
	}
*/		 
	return 0;
}
