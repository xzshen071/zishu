#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//������
	//������д渡��������M x 2^E��M��β����E�ǽ��룬��󸡵����е�M��9������ʮ������16λ�����Ը��������ֻ�ܱ���16λС�� 
	//ö�ٴ��(����)��һ���������ʾ�ķ�Χ���Ϳ����ô˷��� 
	const int maxn=35;
	double a[maxn][maxn];
	for(int m=0;m<=9;m++){
		for(int e=1;e<=30;e++){
			//b=1-2^(-1-i)��c=2^j-1��a*2^c=A*10^B����߲��ᳬ�����ұ߿��ܻᳬ������ 
			//����lg����lg(b)+c*lg(2)=lg(A)+B�����ݿ�ѧ��������0<=A<10����0<lg(A)<1��С����,B�������� 
			double b=1-pow(2,-1-m);
			double c=pow(2,e)-1;
			a[m][e]=log10(b)+c*log10(2);
			
		}
	} 
	//����AeB��ȡ��A��B��Ȼ����
	char s[maxn];
	double A;
	int B;
	while(1){
		scanf("%s",s);//��������� 
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='e')
				s[i]=' ';//�����A��B����Ϊscanf��������' '����'\n'ʱ��ͣ���� 
			
		}
		sscanf(s,"%lf %d",&A,&B);//��A��B�����ÿɺ�sprintf���
		if(A==0 && B==0)
			break;
		double tmp=log10(A)+B;
		int m,e;
		for(m=0;m<=9;m++){
			for(e=0;e<=30;e++){
				if(a[m][e]==tmp)
					break;
				
			}
			if(a[m][e]==tmp)
				break;
		}
		printf("%d %d\n",m,e);
		
	}
	
	
	
	
	
	
	
	return 0;
}
