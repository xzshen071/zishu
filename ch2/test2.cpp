#include<stdio.h> 
#include<math.h>
int main(){
/*	
	//ˮ�ɻ��� 
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
	//���ŵ��
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
	//��������
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
	//�����еĺ�
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
			k=1.0/n;//��һ���ǹؼ������ֱ�ӱ�ʾ��s+=1.0/(n*n)�������ȷ����Ϊn*n���ܻᳬ����Χ 
			s+=k/n;//or 1.0/n/n 
		}
		printf("Case %d: %.5f\n",++count,s);
			
	}
*/

/* 
	//������С��
	//��д�Ĵ������ 
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
	//���ⲻ�ܿ��������������Ҫģ����ѧ�ϵĳ���
	int count=0;
	while(1){
		int a,b,c,tmp;
		scanf("%d%d%d",&a,&b,&c);
		if(a==0 && b==0 && c==0)
			break;
		tmp=a/b;//ȡ��������
		printf("Case %d: %d.",++count,tmp);
		//�ؼ��Ĳ��� 
		a%=b;//ȡ������Ϊ�˿�ʼ����С�����֣�����8/3=2.6666...7��8%3=2��2/3=0.6666...7 
		for(int i=c;i>1;i--){//����һλһλ����Ϊc<=100���ᳬ��int��long long������ 
			a*=10;
			printf("%d",a/b);
			a%=b; //����ȡ�� 
			
		}
		a*=10;
		printf("%d\n",(a/b>5)?(a/b+1):(a/b));//����жϸ�ʽ����ѧѧ��		
	
	}
*/

/* 
	//����
	//��д�Ĵ������ 
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
	for(int abc=123;abc<329;abc++){//������Ŀ�������ķ�Χ��������Ҫ��
	
		bool judge[10]={false};//c++Ҳ�в������� 
		judge[abc/100]=judge[abc/10%10]=judge[abc%10]=true;//c++����������ֵ 
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
	
	//˼����
	/* 
	//��Ŀ1 
	//�޸ĵ�7�У����޸ĵ�6��
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		printf("%d\n",i*2);
	//�޸ĵ�6�У����޸ĵ�7��
	int n;
	scanf("%d",&n);
	for(int i=2;i<=2*n;i+=2)
		printf("%d\n",i);
*/ 
/*
	//��Ŀ2
	double i;
	for(i=0;i!=10;i+=0.1)//˫����ʵ�ʹ������ 
		printf("%.1f\n",i);
	//���� 
	//for(i=9;i!=10;i+=0.1)
		//printf("%2.150f\n",i);
	
*/	
		
	return 0;
}
