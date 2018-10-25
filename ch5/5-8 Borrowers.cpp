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

int num_b;		//��¼������ı��� 

int find_book(const string s);
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	string line;
	num_b = 1; 
	//���� 
	while( getline(cin,line)){
		if( line[0] == 'E') break;
		
		//��line����Ԥ����������������
		int pos1;		//��¼�������һ��˫���ŵ�λ�� 
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
	int pos2;		//��¼��һ��˫���ŵ�λ��	
	//�������� 
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
				if( b[i].ret == 1 && i == 1){ b[i].ret = 0; printf("Put %s first\n",b[i].title.c_str()); }	//�����������ǵ�һ�� 
				else if( b[i].ret == 1){																	//���������鲻�ǵ�һ�� 
					b[i].ret = 0;
					int flag = 1;
					for( int j = i-1; j > 0; j--){ 															//���뵽û�н��ȥ����ĺ��� 
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
