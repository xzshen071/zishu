#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//周期串
	//枚举法，它的周期最大是它本身
	char s[1000];
	scanf("%s",s);
	int len=strlen(s);
	for(int i=1;i<=len;i++){//枚举 
		int flag=1; 
		if(len%i==0){//如果i为最小周期，那么字符串长度必定是i的整数倍
			for(int j=i;j<len;j++){//判断i是否为其周期 
				if(s[j-i]!=s[j]){
					flag=0;
					break;
				}
			}
			if(flag){
				printf("%d\n",i); 
				break;//只打印最小周期 
			}
			
			
		}
		
		
	}	
	
	
	
	
	
	
	return 0;
}
