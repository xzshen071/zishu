#include<stdio.h>
#include<string.h> 
#define maxn 110
char s1[maxn],s2[maxn];
int p1[maxn],p2[maxn];
void Sort_Char(char s[],int n);
void Sort_Int(int a[],int n);
int main(){
	//������
	while(scanf("%s%s",s1,s2)==2){
		//�����������,����ͬ����ĸ���� 
		int len=strlen(s1);
		Sort_Char(s1,len);
		Sort_Char(s2,len);
		//printf("%s\n",s1);
		//printf("%s\n",s2);
		//ͳ���ַ��и�����ĸ���ֵĴ���
		int kase1=1,Num1=0,kase2=1,Num2=0;
		for(int i=0;i<len;i++){
			if(s1[i+1]==s1[i]){
				kase1++;
			}
			else{
				p1[Num1]=kase1;
				Num1++;
				kase1=1;	
			}
			
			if(s2[i+1]==s2[i]){
				kase2++;
			}
			else{
				p2[Num2]=kase2;
				Num2++;
				kase2=1;	
			}		
			
				
		}
		/*
		for(int i=0;i<Num1;i++){
			printf("%d ",p1[i]);
		}
		printf("\n");
				
		for(int i=0;i<Num2;i++){
			printf("%d ",p2[i]);
		}
		printf("\n");
		*/
		//�ж�p1��p2���鳤��Ԫ���Ƿ���ͬ
		if(Num1!=Num2){
			printf("No\n");
		}else{
			//��p1��p2���� 
			Sort_Int(p1,Num1);
			Sort_Int(p2,Num1);
			//�ж������Ƿ���ͬ
			int flag=1;
			for(int i=0;i<Num1;i++){
				if(p1[i]!=p2[i]){
					printf("No\n");
					flag=0;
					break;
				}
			}
			if(flag)
				printf("Yes\n");
				
		}
		
		
	} 
	
	return 0;
} 
void Sort_Char(char s[],int n){
    int i,j;
    for(i=1;i<n;i++)
    {
        char temp=s[i];
        for(j=i;j>0&&s[j-1]>temp;--j)
            s[j]=s[j-1];
        s[j]=temp;
    }
    
}

void Sort_Int(int a[],int n){
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp=a[i];
        for(j=i;j>0&&a[j-1]>temp;--j)
            a[j]=a[j-1];
        a[j]=temp;
    }
    
}
