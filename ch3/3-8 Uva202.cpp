#include<stdio.h>
#include<math.h>
#include<string.h>


int main(){
	//ѭ��С��
	int a,b,rem,i;
	scanf("%d%d",&a,&b);
	int tmp=a/b;//��������
	printf("%d.",tmp);
	//�ѵ�һ����������� 
	a%=b;
	rem=a;
	a*=10;
	printf("%d",a/b);
	a%=b;
	for(i=1;a!=rem;i++){//����ģ�� 
		a*=10;
		printf("%d",a/b);
		a%=b;
			
	}
	printf("\n%d\n",i);
	
	return 0;
}


