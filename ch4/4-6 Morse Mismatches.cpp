#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
using namespace std;
//码表 
//对应A~Z,0-9 
char m_table[50][20]; 
//上下文单词 
struct section{
	char word[15];//单词
	char ma[300];//编码 
	
}t[105]; 
char yma[300]; 
char readchar();
set<string> s;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//读表
	char c;
	while(1){
		c=readchar();
		//printf("%c\n",c);
		if(c=='*')
			break;
		char a[10];
		scanf("%s",a);
		//存入码表
		if(isalpha(c)){//英文字母
			memcpy(m_table[c-'A'],a,sizeof(a));
			//printf("%d %s\n",c-'A',m_table[c-'A']);
			
		}else{
			memcpy(m_table[c-'0'+26],a,sizeof(a));		//字母是0~25，那数字应该是26~35 
			//printf("%d %s\n",c-'0'+26,m_table[c-'0'+26]);
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
		string tmp1 = t[i].word;
		s.insert(tmp1);
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
					memcpy(t[i].ma,m_table[t[i].word[j]-'0'+26],sizeof(m_table[t[i].word[j]-'0'+26]));
				else//字符串合并 
					strcat(t[i].ma,m_table[t[i].word[j]-'0'+26]);
			}
				
		}
		//printf("%s %s\n",t[num-1].word,t[num-1].ma);
		
	}
	//for(set<string>::iterator it = s.begin(); it != s.end(); it++) cout << *it << " ";
	//cout << endl;
	//输入原码还原单词
	while(1){
		scanf("%s",yma);
		//printf("%s\n",yma);
		if(yma[0]=='*')
			break;
		//在上下文中寻找原码
		int flag1=0;//找到标志，且存找到的次数 
		string tmp2;
		set<string> s2;
		for(int i=0;i<num;i++){
			if(strcmp(yma,t[i].ma)==0){		//存在完全匹配，打印字典序最小的 
				tmp2 = t[i].word; 			//char转string 
				s2.insert(tmp2);
				flag1++;
			}
		}
		//set<string>::iterator it = s1.begin();
		//for(it = s1.begin(); it != s1.end(); it++) cout << *it << " ";
		set<string>::iterator it = s2.begin();
		//找到多次
		if(flag1>1)
			cout << *it << "!" << endl;
		else if(flag1==1)
			cout << *it << endl;
		else{//未能准确匹配，比较相似程度，字符串长度短的那一方和另一方全部匹配，但是不能相差太大
			map<int,set<string> > len_s;
			int dlen_now=10000,flag3=0;
		 	for(int i=0;i<num;i++){
		 		int flag2=1,dlen;
				int minl=strlen(yma)<strlen(t[i].ma)?strlen(yma):strlen(t[i].ma);
				//cout << minl << endl;
				if(minl == strlen(t[i].ma)) dlen = strlen(yma)-strlen(t[i].ma);
				else dlen = strlen(t[i].ma)-strlen(yma);
				//cout << dlen << endl;
				for(int j=0;j<minl;j++){			
					if(yma[j]!=t[i].ma[j]){
						flag2=0;
						break;
					}
				}
				//通过增加或删减达到匹配（增加或删除的字符应尽量少）。相同则显示字典序最小的 
				if(flag2){
					if(dlen<=dlen_now) {
						//cout << dlen << endl;
						tmp2 = t[i].word;
						len_s[dlen].insert(tmp2);
						dlen_now=dlen;
						flag3=1;
					}
				}		
			}
			
			if(flag3){
				//cout << dlen_now << endl;
				it = len_s[dlen_now].begin();
				cout << *it << "?" << endl;
			}else{
				it = s.begin();
				cout << *it << "?" << endl;
			}			
		} 
				
	}
	//for(set<string>::iterator it = s.begin(); it != s.end(); it++) cout << *it << " ";
	//cout << endl;			 
	return 0;	
} 
	
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\r' && ch!='\n')
			return ch;
	}
}
