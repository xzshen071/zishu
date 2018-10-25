#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	//ÊýÊý×Ö
	char s[10006];
	scanf("%s",s);
	int len=strlen(s),num[10];
	memset(num,0,sizeof(num));
	for(int i=0;i<len;i++){
		for(int j=0;j<10;j++)
			if(s[i]-'0'==j)
				num[j]++;
	}	
	for(int i=0;i<10;i++){
         printf("%d:%d\n",i,num[i]);
	} 
	
	
	
	
	return 0;
}
