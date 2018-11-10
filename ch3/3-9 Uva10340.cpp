#include<stdio.h>
#include<math.h>
#include<string.h>

char s[1000000],t[1000000];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%s%s",s,t)==2){
		//printf("%s %d %s %d\n",s,strlen(s),t,strlen(t));
        int p=0,k=0;
        int min_l = strlen(s) < strlen(t) ? strlen(s) : strlen(t);
        int max_l = strlen(s) + strlen(t) - min_l;
        for(int i=0;i<min_l;i++){
            for(int j=k;j<max_l;j++){
            	if(min_l == strlen(t)) {
            		if(t[i]==s[j]){//找t中各个字符在s的位置 
                    	p++;
                    	//printf("%d\n",j);
                    	k=j+1;
                    	break;  
                	}
				}else {
					if(s[i]==t[j]){//找t中各个字符在s的位置 
                    	p++;
                    	//printf("%d\n",j);
                    	k=j+1;
                    	break;  
                	}
				}
            }
        }
        //printf("%d\n",p);
        //判定是子序列的条件：个数p等于s的长度 
        if(p==min_l)
            printf("Yes\n");
        else
            printf("No\n");			
	}
	
	return 0;
}
