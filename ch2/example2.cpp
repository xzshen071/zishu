//����Ϊ.cpp�ļ����������c��c++��ͬ�Ĳ��� 
#include<stdio.h>
#include<math.h>
//#include<time.h>//��ʱ�� 
//#define INF 99999999 
//#define LOCAL//ɾ�������ɷ�ֹû��ɾ�������е��ļ��ض���
//Ҳ�����ڱ���ѡ���ж���LOCAL����ʽgcc example.cpp -DLOCAL,������example.exe�ļ�������������У����ܿ������ 
int main(){
/* 
	//��ӡ1~n 
	int n;
	scanf("%d",&n);
	for(int i =1;i<=n;i++)
		printf("%d\n",i);
	//printf("%d",i); //�ᱨ����Ϊiֻ������ѭ������
	//�������ᾡ����С��������÷�Χ������д����֮���ŵ��չ�ֳ��� 
*/

/*
	//��ȫƽ����
	//����������ܴ������ڽ��и������Ƚ�ʱ��Ӧ���ǵ��������  
	for(int a=1;a<=9;a++)
		for(int b=0;b<=9;b++){
			int n=a*1100+b*11;//����ſ�ʼʹ��n,��������ﶨ��n 
			int m=floor(sqrt(n)+0.5);//sqrt(n)Ϊ��������Ϊ�˼�С������������Ϊ�������룬��floor(x+0.5)
			//��������ô��⣺���辭�������������������Ӱ�죬����1�����0.9999999��floor�Ľ��������0������1��floor(x)������ȡ������x������ 
			if((m*m)==n)
				printf("%d\n",n);
				
		}
		
	//�ڶ��ַ��������Ա��⸡���������	
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
	//��Ҫ���ǲ��ԣ�һ������ȥ��ȷ�ĳ�������������󣬿�������м������ 
	//int n;//����long long���ͣ���Ϊn��ʹ<=10^9���� 
	int n2;
	int count=0;
	scanf("%d",&n2);//Ϊ�˱ܿ����������ȷ����%lld����%l64d������,��Ϊ�����ֵ��û����� 
	long long n=n2;//��long long�͵�n����n2������ 
	while(n>1){
		if(n%2==1)
			n=3*n+1;
		else
			n=n/2;
		//printf("%d\n",n);//�������987654321ʱ�����ж���int���������3*n+1�� ,int�ڱ�����һ��Ϊ32λ��C99û�й涨ȷ�еĴ�С�����ԵüӴ�Χ 
		count++;
		
	}
	//printf("%lld",count);//%d�øģ�������Linux����%lld����windows��ʱ����%l64d,Ϊ�˱�������������ú�����ܵ�C++�������߱�д�Զ�������������� 
	printf("%d",count);
*/

/*
	//���Ƽ���
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
	//�ڶ��ַ��� 
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
	//�����ַ���������do{}while();
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
	}while(term>=1e-6);//do{}while(�����ж�);�������������ж� 
	printf("%.6f\n",sum);
*/

/*
	//�׳�֮�ͣ�֮ȡĩ6λ�� 
	//��n>=25֮��ĩ6λ����940313����Ϊ25����ֵĩβ��6��0��25/5+5/5=6���� ����25��ĩ6λ��ֵ��n=24ʱ��ͬ�ġ� 
	const int mod=1000000;//����ĳ��������const���� 
	int n,S=0;
	scanf("%d",&n);
	//if(n>24)
		//n=24; 
	//long long S=0;//ֻ��ȡĩ6λ�����Բ���long long���͡� 
	//ԭ��Ҫ����ֻ�����ӷ����������˷��ͳ������������ʽ����������nȡ�࣬������ÿ�μ���֮���nȡ�࣬������� 
	for(int i=1;i<=n;i++){
		//long long sum=1;
		int sum=1;//ÿѭ��һ����������sum 
		for(int j=i;j>0;j--){
			sum=(sum*j)%mod;
		}//�����ٶȽ������ 
		//printf("%lld\n",sum);
		S=(S+sum)%mod;
	}
	printf("%d\n",S);
	//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);//��CLOCKS_PER_SEC�õ�����Ϊ��λ��ֵ 
	//�ü�ʱ�������������ʱ��ʱ�����ڼ�������ʱ�����ܻ�������������ʱ�䣬���Կ���windows��������ִ��echo 20|abc������20Ϊ�����ֵ��abcΪ������		
	//�ܶ������n���ڽ��Ƽ򵥹�ϵ������ͨ����ʱ����֤��һ��ϵ 
*/

/* 
	#ifdef LOCAL
	//��������ض���ʹ��scanf��input.txt�ж��룬printfд���ļ�output.txt��������Щ�������ܲ������ֻ��߲�����˷�ʽ��Ҫ��ϸ�Ķ�ע������ 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif//��������LOCAL���ű������еĴ��� 
	int x,n=0,min=INF,max=-INF,s=0;//������Ϊ��ֵ֮ǰ��ֵ�ǲ�ȷ���ġ��ر������һ������0 
	//printf("%d %d\n",&min,&max); 
	while(scanf("%d",&x)==1){//scanf�����з���ֵ������ֵ�ǳɹ�����ı������������������ʱ��scanf�����޷��ٴζ�ȡx��������0 
	//�������һ�����⣺��Ϊenter��tab��space�����ܱ�ʾ������������������갴enter�����������
	//��windows�£�������Ϻ��Ȱ�enter���ٰ�ctrl+z������ٰ�enter���ɽ������� 
		s+=x;
		if(x<min)
			min=x;
		if(x>max)
			max=x;
		n++;
		
	}
 
	printf("%d %d %.3f",min,max,(double)s/n);//������ɺ���ע�ͣ���;������������ 
*/ 

/* 
	//��ֹ�ض���ʽ����δ��� 
	FILE *fin,*fout;
	fin=fopen("input.txt","rb");
	fout=fopen("data.txt","wb");
	//�ô˷�ʽ�������ɸ�д�ɱ�׼������������� 
	//fin=stdin;//stdinָ���Ǳ�׼������ 
	//fout=stdout;
	int x,n=0,min=INF,max=-INF,s=0;
	while(fscanf(fin,"%d",&x)==1){//ע���ô˷�ʽ��ʱ��Ҫ��fsacnf��fprintf��ע���ʽ 
 
		s+=x;
		if(x<min)
			min=x;
		if(x>max)
			max=x;
		n++;
		
	}
 
	fprintf(fout,"%d %d %.3f",min,max,(double)s/n);
	//������������������� 
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
		//printf("\n");//������Ϊ���һ�����ݵ�����Իس���������֮�󲻻��п��� 
	}

	//����ʱ��-Wall,������ܶྯ����Ϣ���������У����Է�������Щ�����󡯳���ʱ�Ϸ��ģ�ֻ����Щ���������������� 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,count=0,x,s=0;
	while(scanf("%d",&n)==1 && n){
		int min=INF,max=-INF,s=0;//����������ѭ���ڣ���ֹ��������£�ֵ�������ı� ����ÿ��ѭ��ֵ���� 
		//����ģ����ͬ������ʱ���ڲ��������������������ʱ�����������εĴ��� 
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
