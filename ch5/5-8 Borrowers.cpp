#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;
const int maxn = 1000000 + 1;

struct book{
	string title;
	string author;
	int bro;
	int ret;
	
}b[maxn];
int comp(const book &a,const book &b)
{
    if(a.author != b.author) return a.author < b.author;
    else return a.title < b.title;
}

int num_b;		//记录存入书的本数 

int find_book(const string s);
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	string line;
	num_b = 1; 
	//存书 
	while( getline(cin,line)){
		if( line[0] == 'E') break;
		
		//对line进行预处理，分离标题和作者
		int pos1;		//记录标题最后一个双引号的位置 
		for(int i = 0; i < line.size(); i++){
			if(i != 0 && line[i] == '"'){ pos1 = i; break;} 
				
		} 
		//cout << pos << endl;
		b[num_b].title = line.substr(0, pos1+1); b[num_b].author = line.substr(pos1+1);
		b[num_b].bro = b[num_b].ret = 0;
		num_b++;
		
	}
	
	/*
	for(int i = 1; i < num_b; i++){
		cout << b[i].title << " " << b[i].author << endl;
		
	}
	cout << endl;
	*/
	sort(b,b+num_b,comp);
	/*
	for(int i = 1; i < num_b; i++){
		cout << b[i].title << " " << b[i].author << endl;
		
	}
	cout << endl;
	*/
	
	string com;
	int pos2;		//记录第一个双引号的位置	
	//接收命令 
	while(getline(cin, com)){
		if( com[0] == 'E') break;
		else if( com[0] == 'B' || com[0] == 'R'){
			for(int i = 0; i < com.size(); i++){ if(com[i] == '"'){ pos2 = i; break;} }
			int pos = find_book( com.substr(pos2));
			//cout << com.substr(pos2) << " " << pos << endl;
			
			if( com[0] == 'B') b[pos].bro = 1; 
			else{ b[pos].ret = 1; b[pos].bro = 0;}
			
		}else{
			for( int i = 1; i < num_b; i++){
				if( b[i].ret == 1 && i == 1){ b[i].ret = 0; printf("Put %s first\n",b[i].title.c_str()); }	//还回来的书是第一本 
				else if( b[i].ret == 1){																	//还回来的书不是第一本 
					b[i].ret = 0;
					int flag = 1;
					for( int j = i-1; j > 0; j--){ 															//插入到没有借出去的书的后面 
						if( b[j].bro == 0){ printf("Put %s after %s\n",b[i].title.c_str(), b[j].title.c_str()); flag = 0; break;}
				
					}
					if(flag) printf("Put %s first\n",b[i].title.c_str());
					
				}
				
			}
			cout << "END" << endl;
			
		}
		

	} 
	
	
	
	
	
	return 0;
} 
int find_book(const string s){
	for(int i = 1; i < num_b; i++){
		if(b[i].title == s)
			return i;
	
		
	}
	
	
	
}
