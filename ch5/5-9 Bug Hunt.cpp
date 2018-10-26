#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<sstream> 
#include<stack>
#include<cstdlib>
using namespace std;

struct arr{
	int span;					//�����±귶Χ 
	map<int,int> index;			//�±��Ӧ��ֵ 
	
};

map<string, arr> a;				//��������ӳ������ṹ 
int is_bug( stack<string> s); 
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	string line;
	while( getline(cin,line)){
		if(line[0] == '.') break; 
		
		int row_bug = 1;
		int flag1 = 1;		//�ж��Ƿ��ǵ�һ�ζ������ 
		int flag2 = 1;		//�ж��Ƿ��Ѿ�����bug����ʹ������bug���ǵðѺ���ô�������� 
		a.clear();
		do{
			//cout << line <<endl;
			
			if(flag1) flag1 = 0;
			else if(line[0] == '.') break;		
			//�ж��Ǹ�ֵ��仹�Ƕ���
			int symbol = 1, num_l = 1;		//��ñ��ʽ���Ԫ�ظ���������ѹջ 
			for( int i = 0; i < line.size(); i++){
				if( line[i] == '['){ line[i] = ' '; num_l++;}
				else if( line[i] == ']'){ line[i] = ' ';}
				else if( line[i] == '='){ symbol = 0; num_l++;}
			
			} 
			//cout << line << endl;
			
			stringstream ss(line);
			
			if( symbol){	//�������� 
				string s;
				int lens;
				ss >> s >> lens;
				a[s].span = lens;
				
				//cout << a[s].span << endl;
				
			}else{			//��ֵ 
				//cout << num_l << endl;
				
				string s;
				stack<string> zhan;
				
				for( int i = 0; i < num_l; i++){ 
					ss >> s; 
					if(s[0] == '='){	//��Ϊ�Ⱥź��ұߵ��ַ�����һ����Ҫ�ֿ� 
						zhan.push("=");
						zhan.push(s.substr(1));
					}else 
						zhan.push(s); 
				}		
				/* 
				for( int i = 0; !zhan.empty(); i++){ cout << zhan.top() << " "; zhan.pop();}				
				cout << endl;
				*/ 
				
				//is_bug(zhan);
				if( flag2 && is_bug(zhan) ) { cout << row_bug << endl; flag2 = 0;}	//δ��ʼ���������±�Խ�� 
				
				
			} 
			row_bug++;

			
		}while( getline(cin,line));
		if(flag2) cout << "0" << endl;												//û��bug�����0 
		
	}
	
	return 0;
} 
int is_bug( stack<string> s){
	int value;
	int pos = atoi(s.top().c_str());
	//cout << pos << endl;
	
	s.pop();
	
	while(s.size() != 1){
		if( s.top() == "="){
			value = pos; 					//��¼�Ⱥ��ұߵ�ֵ 
			s.pop(); 						//�����Ⱥ� 
			
			pos = atoi(s.top().c_str());	
			//cout << pos << endl;
			s.pop();
			
			if(s.size() == 1) break;
		}
	
		string name = s.top();
		//cout << name << " " << a[name].span << " " << a[name].index.count(pos) << endl;
		
		if( pos >= a[name].span || a[name].index.count(pos) == 0) { 	//δ��ʼ���������±�Խ�� 
			//cout << "done1" << endl; 
			return 1;
		}	
		
		pos = a[name].index[pos]; 												
		s.pop();

	}
	//��¼ջ���һ��Ԫ�� 
	string name = s.top();
	s.pop(); 
	//cout << pos << endl;
	
	if( pos >= a[name].span) { 
		//cout << "done2" << endl; 
		return 1;
	}
	
	a[name].index[pos] = value;
	//cout << value << endl;
	
	return 0;
	
}
