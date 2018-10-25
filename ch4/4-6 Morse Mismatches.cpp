#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//码表 
//对应A~Z,0-9 
char m_table[50][10]; 
//上下文单词 
struct section{
	char word[15];//单词
	char ma[100];//编码 
	
}t[105]; 
char yma[100]; 
char readchar();
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//读表
	char c;
	while(1){
		c=readchar();
		if(c=='*')
			break;
		char a[10];
		scanf("%s",a);
		//存入码表
		if(isalpha(c)){//英文字母
			memcpy(m_table[c-'A'],a,sizeof(a));
			//printf("%d %s\n",c-'A',m_table[c-'A']);
			
		}else{
			memcpy(m_table[c-'0'+25],a,sizeof(a));
			//printf("%d %s\n",c-'0'+25,m_table[c-'0'+25]);
		}
	
	}
	//存上下文
	memset(t,0,sizeof(t));
	int num=0;//记录s 
	for(int i=0;;i++){
		//存单词 
		scanf("%s",t[i].word);
		if(t[i].word[0]=='*')
			break;
		num++;//有效上下文个数 
		//存编码
		int len=strlen(t[i].word);
		for(int j=0;j<len;j++){
			if(isalpha(t[i].word[j])){
				if(j==0)
					memcpy(t[i].ma,m_table[t[i].word[j]-'A'],sizeof(m_table[t[i].word[j]-'A']));
				else//字符串合并 
					strcat(t[i].ma,m_table[t[i].word[j]-'A']);
			}else{
				if(j==0)
					memcpy(t[i].ma,m_table[t[i].word[j]-'0'+25],sizeof(m_table[t[i].word[j]-'0'+25]));
				else//字符串合并 
					strcat(t[i].ma,m_table[t[i].word[j]-'0'+25]);
			}
				
		}
		//printf("%s\n",t[i].ma);
		
	}
	//输入原码还原单词
	while(1){
		scanf("%s",yma);
		if(yma[0]=='*')
			break;
		//在上下文中寻找原码
		int flag1=0;//找到标志，且存找到的次数 
		for(int i=0;i<num;i++){
			if(strcmp(yma,t[i].ma)==0){
				if(flag1==0) 
					printf("%s",t[i].word);
				flag1++;
			}
			
		}
		//找到多次
		if(flag1>1)
			printf("!\n");
		else if(flag1==1)
			printf("\n");
		else{//未能准确匹配，比较相似程度，字符串长度短的那一方和另一方全部匹配，但是不能相差太大
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
