#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//������
	char s[100],t[100];
	int p=0,k=0;
	scanf("%s",s);
	scanf("%s",t);
	for(int i=0;i<strlen(t);i++){
		for(int j=k;j<strlen(s);j++){
			if(t[i]==s[j]){//��t�и����ַ���s��λ�� 
				p++;
				k=j+1;
				break;
				
			}
		}
	}
	//�ж��������е�����������p����s�ĳ��� 
	if(p==strlen(t))
		printf("Yes");
	else
		printf("No");	
	
	
	
	
	return 0;
}
