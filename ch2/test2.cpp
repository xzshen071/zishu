#include<stdio.h> 
#include<math.h>
int main(){
/*	
	//水仙花数 
	for(int num=100;num<1000;num++){
		int ge,shi,bai;
		ge=num%10;
		shi=num/10%10;
		bai=num/100;
		if((bai*bai*bai+shi*shi*shi+ge*ge*ge)==num)
			printf("%d\n",num);
		
	}
*/

/*
	//韩信点兵
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	unsigned int a,b,c,count=0,n;
	while(scanf("%d %d %d",&a,&b,&c)==3){
		for(n=10;n<=100;n++){
			if(n%3==a && n%5==b && n%7==c){
				printf("Case %d: %d\n",++count,n);
				break;
			}
			
		}
		if(n==101)
			printf("Case %d: No answer\n",++count);

	}	
*/

/*
	//倒三角形
	int n,count=0;
	scanf("%d",&n);
	for(;n>0;n--){
		for(int j=count;j>0;j--)
			printf(" ");
		for(int i=2*n-1;i>0;i--)
			printf("#");
		printf("\n");
		count++;
	}	
*/
 
/*
	//子序列的和
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int count=0;
	while(1){
		int m,n;
		double k,s=0;
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
			break;
		for(;n<=m;n++){
			k=1.0/n;//这一步是关键，如果直接表示成s+=1.0/(n*n)结果不正确，因为n*n可能会超出范围 
			s+=k/n;//or 1.0/n/n 
		}
		printf("Case %d: %.5f\n",++count,s);
			
	}
*/

/* 
	//分数化小数
	//我写的错误程序 
	while(1){
		int a,b,c,j=1,k;
		double s;
		scanf("%d%d%d",&a,&b,&c);
		if(a==0 && b==0 && c==0)
			break;
		for(int i=c;i>0;i--)
			j*=10;
		s=(double)a/b;
		printf("%f\n",s);
		k=floor((s*j)+0.5);
		printf("%d\n",k);
		printf("0.%d\n",k);
	}
*/
/* 
	//此题不能靠计算机做除法，要模拟数学上的除法
	int count=0;
	while(1){
		int a,b,c,tmp;
		scanf("%d%d%d",&a,&b,&c);
		if(a==0 && b==0 && c==0)
			break;
		tmp=a/b;//取整数部分
		printf("Case %d: %d.",++count,tmp);
		//关键的步数 
		a%=b;//取余数，为了开始计算小数部分，例如8/3=2.6666...7，8%3=2，2/3=0.6666...7 
		for(int i=c;i>1;i--){//必须一位一位，因为c<=100，会超出int，long long等类型 
			a*=10;
			printf("%d",a/b);
			a%=b; //继续取余 
			
		}
		a*=10;
		printf("%d\n",(a/b>5)?(a/b+1):(a/b));//这个判断格式可以学学用		
	
	}
*/

/* 
	//排列
	//我写的错误程序 
	for(int i=123;i<=329;i++){
		int ge,ge1,ge2;
		int shi,shi1,shi2;
		int bai,bai1,bai2;
		ge=i%10;
		shi=i/10%10;
		bai=i/100;
		ge1=ge*2%10;
		shi1=shi*2%10+ge*2/10;
		bai1=bai*2+shi*2/10;
		ge2=ge*3%10;
		shi2=shi*3%10+ge*3/10;
		bai2=bai*3+shi*3/10;
		if(ge!=ge1!=ge2!=shi!=shi1!=shi2!=bai!=bai1!=bai2 )
			printf("%d%d%d %d%d%d %d%d%d\n",ge,shi,bai,ge1,shi1,bai1,ge2,shi2,bai2);
		
	} 
*/
/* 
	for(int abc=123;abc<329;abc++){//根据题目限制数的范围（这点很重要）
	
		bool judge[10]={false};//c++也有布尔类型 
		judge[abc/100]=judge[abc/10%10]=judge[abc%10]=true;//c++可以连续赋值 
		int def=abc*2;
		judge[def/100]=judge[def/10%10]=judge[def%10]=true;
		int ghi=abc*3;
		judge[ghi/100]=judge[ghi/10%10]=judge[ghi%10]=true;
		
		bool flag=true;
		for(int i=1;i<10;i++){//1-9 
			if(judge[i]!=true){
				flag=false;
				break;
			}
				
		}
		if(flag)
			printf("%d %d %d\n",abc,def,ghi);		
	
	}	
	
	//思考题
	/* 
	//题目1 
	//修改第7行，不修改第6行
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		printf("%d\n",i*2);
	//修改第6行，不修改第7行
	int n;
	scanf("%d",&n);
	for(int i=2;i<=2*n;i+=2)
		printf("%d\n",i);
*/ 
/*
	//题目2
	double i;
	for(i=0;i!=10;i+=0.1)//双精度实型存在误差 
		printf("%.1f\n",i);
	//测试 
	//for(i=9;i!=10;i+=0.1)
		//printf("%2.150f\n",i);
	
*/	
		
	return 0;
}
