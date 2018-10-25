#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;

const int maxn = 120000 + 5;
map<string,vector<string> > m;	//���ܴ���һ��ǰ׺��Ӧ�������	
string words[maxn];		//��ÿ������ĵ��� 
set<string> comp_word; //�渴�ϴʣ���ֹ�ظ��� 
int num1;				//����ĵ��ʵĸ���
void save_words(string s); 
bool is_find( string s);
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	num1 = 1;
	m.clear();
	while(cin >> words[num1]){
		//cout << words[num1] << endl; 
		save_words(words[num1]); 
		num1++;		
		
	}
	//cout << num1 << endl;
	
	//������ϴ�
	for(int i = 1; i < num1; i++){
		int lens = m[words[i]].size();
		if(lens == 0 ) continue;
		else{
			//cout << words[i] << endl;
			//cout << m[words[i]] << endl;
			for( int j = 0; j < lens; j++){
				string tmp = words[i] + m[words[i]][j];
				//if( !is_find( m[words[i]][j]) || is_repeat( tmp)) continue;
				if( !is_find( m[words[i]][j])) continue;
				else{ comp_word.insert(tmp); }
				
			}
		}
		
		
	}
	set<string> :: iterator it;
	for(it = comp_word.begin(); it != comp_word.end(); it++) cout << *it << endl;
	
	/*
	//����compare����
	string a("abcde"); string b("abcde"); string c("aabcde"); string d("aeeebcd"); string e("bcde");
	if(a.compare(b) == 0) cout << "1" << endl;			//�ɹ� 
	//if(a.compare(c,1,5) == 0) cout << "2" << endl;	//���� 
	if(a.compare(1,3,d,4,3) == 0) cout << "3" << endl; 	//�ɹ� 
	if(e.compare(0,4,a,1,4) == 0) cout << "4" << endl;  //�ɹ� 
	if(a.compare(1,4,e) == 0) cout << "5" << endl;		//�ɹ� 
	//compare��ʽ��s1.compare(pos1,lens1,s2,pos2,lens2);
	*/
	
	/* 
	//����substr���� 
	string f("01234567"); string g("0123456789");
	f = f.substr(0, f.length());	//substr(pos,lens);
	//f = f.substr(0,7);			//�����0 ~ 6 
	g = g.substr(f.length());		//substr(pos)����ʾֱ���ַ���β�� 
	cout << f << " " << g << endl;
	*/ 
	
	return 0;
} 
void save_words(string s){
	
	//cout << s << endl;
	for(int i = num1 - 1; i > 0; i--){
		int lens = words[i].length();
		//cout << lens << endl;
		//cout << s.substr(0, lens) << " ";
		if(s.compare(0, lens, words[i]) == 0){
			//cout << words[i] << " ";
			m[words[i]].push_back( s.substr(lens));
			//int pos = m[words[i]].size() -1; 
			//cout << m[words[i]][pos] << endl;
			
			
		}
		
	}
	//cout << endl;
	
	return;
	
}
bool is_find( string s){

	for(int i = 1; i < num1; i++){
		if( s == words[i])
			return true;
		
	}
	
	return false;
}
