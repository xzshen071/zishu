#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//��� 
//��ӦA~Z,0-9 
char m_table[50][10]; 
//�����ĵ��� 
struct section{
	char word[15];//����
	char ma[100];//���� 
	
}t[105]; 
char yma[100]; 
char readchar();
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//����
	char c;
	while(1){
		c=readchar();
		if(c=='*')
			break;
		char a[10];
		scanf("%s",a);
		//�������
		if(isalpha(c)){//Ӣ����ĸ
			memcpy(m_table[c-'A'],a,sizeof(a));
			//printf("%d %s\n",c-'A',m_table[c-'A']);
			
		}else{
			memcpy(m_table[c-'0'+25],a,sizeof(a));
			//printf("%d %s\n",c-'0'+25,m_table[c-'0'+25]);
		}
	
	}
	//��������
	memset(t,0,sizeof(t));
	int num=0;//��¼s 
	for(int i=0;;i++){
		//�浥�� 
		scanf("%s",t[i].word);
		if(t[i].word[0]=='*')
			break;
		num++;//��Ч�����ĸ��� 
		//�����
		int len=strlen(t[i].word);
		for(int j=0;j<len;j++){
			if(isalpha(t[i].word[j])){
				if(j==0)
					memcpy(t[i].ma,m_table[t[i].word[j]-'A'],sizeof(m_table[t[i].word[j]-'A']));
				else//�ַ����ϲ� 
					strcat(t[i].ma,m_table[t[i].word[j]-'A']);
			}else{
				if(j==0)
					memcpy(t[i].ma,m_table[t[i].word[j]-'0'+25],sizeof(m_table[t[i].word[j]-'0'+25]));
				else//�ַ����ϲ� 
					strcat(t[i].ma,m_table[t[i].word[j]-'0'+25]);
			}
				
		}
		//printf("%s\n",t[i].ma);
		
	}
	//����ԭ�뻹ԭ����
	while(1){
		scanf("%s",yma);
		if(yma[0]=='*')
			break;
		//����������Ѱ��ԭ��
		int flag1=0;//�ҵ���־���Ҵ��ҵ��Ĵ��� 
		for(int i=0;i<num;i++){
			if(strcmp(yma,t[i].ma)==0){
				if(flag1==0) 
					printf("%s",t[i].word);
				flag1++;
			}
			
		}
		//�ҵ����
		if(flag1>1)
			printf("!\n");
		else if(flag1==1)
			printf("\n");
		else{//δ��׼ȷƥ�䣬�Ƚ����Ƴ̶ȣ��ַ������ȶ̵���һ������һ��ȫ��ƥ�䣬���ǲ������̫��
			int dlen_now=10000,pos;
		 	for(int i=0;i<num;i++){
		 		int flag2=1;
				int minl=strlen(yma)<strlen(t[i].ma)?strlen(yma):strlen(t[i].ma);
				int dlen=abs(strlen(yma)-strlen(t[i].ma));
				for(int j=0;j<minl;j++){
					if(yma[j]!=t[i].ma[j]){
						flag2=0;
						break;
					}
						
				}
				if(flag2){
					if(dlen<dlen_now)
						dlen_now=dlen;
						pos=i;
				}
					
			}
				printf("%s?\n",t[pos].word);	
		 		
		} 
			
			
	}
		
			 
		return 0;	
} 
	
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\r' && ch!='\n')
			return ch;
		
	}
}
