#include<stdio.h>
#include<string.h>
#define maxn 20
char s[maxn],s1[maxn],s2[maxn];
int p[5];//���Ѿ�ѡ���˵Ķ����� 
int Is_sucess(int a);
int main(){
	//������
	while(scanf("%s",s)==1){
		for(int i=6;i<=11;i++){
			s1[i-6]=s[i];
		}
		//printf("%s\n",s1);
		//��Ԫ��s[0]��λ�ÿ�ʼ�� 
		memset(p,0,sizeof(p));
		if(Is_sucess(0) && Is_sucess(1) && Is_sucess(2))
			printf("TURE\n\n");
		else
			printf("FALSE\n\n");
			
	} 
	
	return 0;
} 
int Is_sucess(int a){
	//��s1���ҵ���λ�ã����������������ͬ����Ϊ1 
	int flag=0,num=0;
	for(int i=0;i<6;i++){
		if(s1[i]==s[a] && p[0]!=i &&p[1]!=i && p[2]!=i){
			if(s1[5-i]==s[5-a]){
				p[num++]=i;
				flag=1;
			}
		}
	}
	
	return flag;
	
}
