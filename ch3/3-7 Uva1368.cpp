#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 1005
void PrintMax(int a,int c,int g,int t){
		int Num[]={a,c,g,t},max=-999999,symbol;
		//�������Ҵ����ֵ�Ҽ�¼�±� 
		for(int i=0;i<4;i++){
			if(Num[i]>max){
				max=Num[i];
				symbol=i;
				
			}
		}
		//�����±��ӡ
		switch(symbol){
			case 0:
				printf("A");
				break;
			case 1:
				printf("C");
				break;
			case 2:
				printf("G");
				break;
			case 3:
				printf("T");
				break;
				
			
		} 
				
}
int main(){
	//DNA����
	int m,n;
	char s[maxn];
	//����m��n
	scanf("%d%d",&m,&n);//m�Ǹ�����n�ǳ��� 
	//��4�����飨A��C��T��G��,��ÿһ��λ�ó��ֵĴ���
	int A[maxn],C[maxn],T[maxn],G[maxn];
	//���������ʼ��
	memset(A,0,sizeof(A));
	memset(C,0,sizeof(C));
	memset(T,0,sizeof(T));
	memset(G,0,sizeof(G)); 
	//ÿ�ζ�һ������
	for(int i=0;i<m;i++){

		scanf("%s",s); 
		//��¼A��C��G��T���� 
		for(int j=0;j<n;j++){
			switch(s[j]){
				case 'A':
					A[j]=++A[j];
					break;
				case 'C':
					C[j]=++C[j];
					break;
				case 'T':
					T[j]=++T[j];
					break;
				case 'G':
					G[j]=++G[j];
					break;
			
			}
		}
		
	}
	printf("\n");
	
	//�Ƚ�ÿһλ�ĸ���ĸ���ֵĴ�����
	for(int i=0;i<n;i++){
		
		//��ӡ����������ĸ
		PrintMax(A[i],C[i],G[i],T[i]); 
		//printf("%d %d %d %d\n",A[i],C[i],G[i],T[i]);
		
		
	} 
	printf("\n");	
	

	
	
	
	return 0;
}
