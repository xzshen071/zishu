#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//�ݺ����յĴ�
	//���� 
	const int maxn=20;
	int r,c;
	char s[maxn][maxn]; 
	int count1=0;
	int num[maxn][maxn],k=0;//����
	memset(num,0,sizeof(num));//��ų�ʼ�� 
	while(scanf("%d%d",&r,&c)==2 && r!=0 ){
		//��������
		for(int i=0;i<r;i++){
			scanf("%s",s[i]);
			//��ţ�һ��һ���� 
			for(int j=0;j<c;j++){//��������߻������Ǳ߽���ߺڸ� 
				if(s[i][j]!='*'){
					if(j-1<0 || i-1<0 || s[i][j-1]=='*' || s[i-1][j]=='*')
				 		num[i][j]=++k;	
				}
			}
			
		}
		//������򵥴�:�ж�������1������'*',������β�� 
		printf("puzzle #%d:\nAcross\n",++count1);
		for(int i=0;i<r;i++){
			if(i)
				printf("\n");
			int flag=1;
			for(int j=0;j<c;j++){
				//���ÿһ�� 
				if(s[i][j]!='*'){
					if(flag){
						printf("%d.",num[i][j]);
						flag=0;
					}
					printf("%c",s[i][j]);
					
				}else{
					flag=1;
					if(j!=0 && j!=c-1) 
						printf("\n");
				}
				
			}
		}	
		//������򵥴�
		printf("\nDown\n");
		int sign=0;//�ж��Ƿ����е����򵥴������� 
		for(int count2=0;count2<r;count2++){//����ÿһ�� 
			for(int j=0;j<c;j++){
				int flag=1;
				for(int i=count2;i<r;i++){
					//���ÿһ�� 
					if(s[i][j]!='*'){
						if(num[i][j]==-1)//��������򲻴�ӡ������ѭ�� 
							continue;
						else if(flag){//��ӡ���� 
							if(sign){
								printf("\n");
							}
							sign=1;//��һ�в���ӡ 
							printf("%d.",num[i][j]);
							flag=0;
						}
						printf("%c",s[i][j]);
						num[i][j]=-1;//�����������ĸλ��-1 
					
					}else{
					
						break;
					}
					
				}
	
				
			}	
		} 
	
	
	
	}	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
