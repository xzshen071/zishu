//��������Ϸ
#include<stdio.h>
#include<string.h>

//��д�Ĵ��� 
#define maxn 100
int Judgecheck(int *a,int n){
	int flag=1;
	for(int i=0;i<n;i++)
		if(a[i]!=1){
			flag=0;
			break;
		}
	return flag;
	
}
void guess(char *a,char *b,int n1,int n2){
	int check[n1]={0};//���a�е���ĸ�Ƿ���ȫ�¶� 
	int chance=0;//�²����ֻ��Ϊ6��
	//����6�λ�û���ж�Ϊ��û����6��Ҳû���ж��Ƿ����� 
	for(int i=0;i<n2;i++){
		//����b�е��ַ��Ƿ���a�� 
		if(strchr(a,b[i])==NULL){
			chance++;//��¼�´����
		} 
		else{
			//����b[i]��a�е�λ�� 
			for(int j=0;j<n1;j++)
				if(a[j]==b[i]){
					check[j]=1; 
					a[j]=' ';//�ٴβ¶Դ���ĸ�д� 
				} 
			//���¶�һ���ǣ��ж��Ƿ�Ӯ�� 
			if(Judgecheck(check,n1)){
				printf("You win.\n");
				return;	
			}
					
		}		
		
	}
	
	//���chanceС��6�������ˣ����ʧ����
	if(chance<6){
		printf("You chickened out.\n");
		
	}else 
		printf("You lose.\n");
	
}
char s1[maxn],s2[maxn];//������ö����ȫ�ֱ�������ֹջ��� 
int main(){
	int Num;
	while(scanf("%d",&Num)==1 && Num!=-1){ 
		//���� 
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		//���뵥��
		scanf("%s",s1); 
		int len1=strlen(s1);//��¼���뵥�ʵĳ��� 
		//������ҵĲ²�
		scanf("%s",s2); 
		int len2=strlen(s2);//�����Ҳ²ⳤ�� 
		//�ж���ҵĲ²⣬�������� 
		printf("Round %d\n",Num);
		guess(s1,s2,len1,len2); 
		
	}
	
	
	return 0;
} 

/*
ϸ��˵��
1����������ѡȡ��count��min��max�ȶ�����STL�Ѿ�ʹ�õ����֣�д������ñܿ�����
2��������ʹ�ã�Ҫע���������ƣ������ó������������Һõ��ԣ�����ָ�롣 
*/ 
/* 
//��
#define maxn 100
int left,chance;//����Ҫ��Left��λ�ã���chance��֮��ͻ���
char s[maxn],s2[maxn];//�����ַ���s����Ҳµ���ĸ������s2
int win,lose;//win=1��ʾ�Ѿ�Ӯ�ˣ�lose=1��ʾ����
//��д�ĺ��������ʸ� 
void guess(char ch){
	int bad=1;
	for(int i=0;i<strlen(s);i++)
		if(s[i]==ch){
			left--;
			s[i]=' ';
			bad=0;
		}
	if(bad)
		--chance;
	if(!chance)
		lose=1;
	if(!left)
		win=1;
		
} 

int main(){
	int rnd;
	while(scanf("%d%s%s",&rnd,s,s2)==3 && rnd!=-1){
		printf("Round %d\n",rnd);
		win=lose=0;//���һ��������֮ǰҪ��ʼ��
		left=strlen(s);
		chance=7;
		for(int i=0;i<strlen(s2);i++){
			guess(s2[i]);
			if(win || lose)
				break;
		} 
		//���ݽ�����
		if(win)
			printf("You win.\n");
		else if(lose)
			printf("You lose.\n");
		else
			printf("You chickened out.\n"); 
		
	}
	
	return 0;
	
	
}
*/ 

