#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//子序列
	char s[100],t[100];
	int p=0,k=0;
	scanf("%s",s);
	scanf("%s",t);
	for(int i=0;i<strlen(t);i++){
		for(int j=k;j<strlen(s);j++){
			if(t[i]==s[j]){//找t中各个字符在s的位置 
				p++;
				k=j+1;
				break;
				
			}
		}
	}
	//判定是子序列的条件：个数p等于s的长度 
	if(p==strlen(t))
		printf("Yes");
	else
		printf("No");	
	
	
	
	
	return 0;
}
