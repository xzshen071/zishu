#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	//�ݺ����յĴ�
	//���� 
	const int maxn=20;
	int r,c;
	char s[maxn][maxn]; 
	int count1=0;
	int num[maxn][maxn],k;//����
	while(scanf("%d%d",&r,&c)==2 && r!=0 ){
		//��ʼ�� 
		k=0;
		memset(num,0,sizeof(num));//��ų�ʼ�� 
		
		//��������
		if(count1) printf("\n");
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
		/*
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) 
				cout << num[i][j] << " ";
			cout << endl;			
		}
		*/
		//������򵥴�:�ж�������1������'*',������β�� 
		printf("puzzle #%d:\nAcross\n",++count1);
		int flag=1;
		for(int i=0;i<r;i++){
			if(flag == 0) {
				flag = 1;
				printf("\n");
			}
			for(int j=0;j<c;j++){
				//���ÿһ�� 
				if(s[i][j]!='*'){
					if(flag){
						printf(" %2d.",num[i][j]);
						flag=0;
					}
					printf("%c",s[i][j]);
					
				}else if(flag == 0){
					flag = 1;
					printf("\n");
				}	
			}
		}	
		if(flag == 0) printf("\n");
		//������򵥴�
		printf("Down\n");
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
							printf(" %2d.",num[i][j]);
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
		if(sign){
			printf("\n");
		}
		
	}	
	
	return 0;
}
