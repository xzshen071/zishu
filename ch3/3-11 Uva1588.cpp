#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 300

char s1[maxn],s2[maxn];
int  a1[maxn],a2[maxn];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//清零 
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	while(scanf("%s%s",s1,s2) == 2) {
		//printf("%s\n%s\n",s1,s2);
        int len1=strlen(s1);
        int len2=strlen(s2);
        //把字符转换成数字
        for(int i=0;i<len1;i++)
            a1[i]=s1[i]-'0';
        for(int i=0;i<len2;i++)
            a2[i]=s2[i]-'0';
		for(int i = len1; i < maxn; i++) a1[i] = 0;
		for(int i = len2; i < maxn; i++) a2[i] = 0;
        //s1不动，移动s2 
        int i;
        for(i=0;i<len1;i++){
            int flag=1;
            for(int j=0;j<len2;j++){
                if(a1[i+j]+a2[j]>3){
                    flag=0;
                    break;
                    
                }
            }
            if(flag)
                break;
        } 
        int L1=(len2+i)>len1?len2+i:len1;//记录长度，要与len1比较 
        //s2不动，移动s1
        for(i=0;i<len2;i++){
            int flag=1;
            for(int j=0;j<len1;j++){
                if(a2[i+j]+a1[j] > 3){
                    flag=0;
                    break;
                    
                }
            }
            if(flag)
                break;
        } 
        int L2=(len1+i)>len2?len1+i:len2;//记录长度 
        //两者比较 
        if(L1 >L2)
            printf("%d\n",L2);
        else
            printf("%d\n",L1);			
	}
	
	return 0;
}
