#include<iostream>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;

map<string, string> old_d;
map<string, string> new_d;
set<string> k;
vector<string> add; vector<string> del; vector<string> cha;	//��¼����ɾ�������޸ĵ�keyֵ 
int n;

int deal_line( string &s);				//����ð�ŵĸ�����ȷ�������� 
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	string line1, line2;
	int flag1 = 1;
	while( n--){
		old_d.clear(); new_d.clear(); k.clear(); add.clear(); del.clear(); cha.clear(); //��� 
		if(flag1){ char c = getchar(); flag1 = 0;}
		
		//���¾��ֵ䣬������ 
		getline(cin, line1);
		getline(cin, line2);
		int t1 = deal_line( line1);
		int t2 = deal_line( line2);
		/* 
		cout << t << endl;
		cout << line1 << endl;
		cout << line2 << endl;
		*/
		stringstream ss1(line1);
		stringstream ss2(line2);
		string key, value;
		while( t1--) {
			ss1 >> key >> value;
			//cout << key << " " << value << endl;
			old_d[key] = value;
			k.insert(key);
			
		}
		while( t2--){
			ss2 >> key >> value;
			//cout << key << " " << value << endl;
			new_d[key] = value;
			k.insert(key);	
			
		}
		
		//�Ƚ��¾ɴʵ�
		int flag2 = 1; 
		set<string>::iterator it;
		for( it = k.begin(); it != k.end(); it++){
			int len1 = old_d[ *it].size(); int len2 = new_d[ *it].size();
			if( len1 == 0){ add.push_back( *it); flag2 = 0;}
			if( len2 == 0){ del.push_back( *it); flag2 = 0;}
			if( len1 && len2 && old_d[ *it] != new_d[ *it]){ cha.push_back( *it); flag2 = 0;}
			
		}
		
		//��˳����� 
		for( int i = 0; i < add.size(); i++){ if( i == 0) cout << "+";else cout << ","; cout << add[i]; if( i == add.size() - 1) cout << endl;} //��� 
		for( int i = 0; i < del.size(); i++){ if( i == 0) cout << "-";else cout << ","; cout << del[i]; if( i == del.size() - 1) cout << endl;} //ɾ�� 
		for( int i = 0; i < cha.size(); i++){ if( i == 0) cout << "*";else cout << ","; cout << cha[i]; if( i == cha.size() - 1) cout << endl;} //�޸� 
		if(flag2) cout << "No changes" << endl;
		cout << endl;
	}

	
	
	
	return 0;
}
//ֻ����ĸ������ 
int deal_line( string &s){
	int num_m = 0;
	for( int i =0; i < s.size(); i++){
		if( s[i] == ':') num_m++;
		
		if( !isalpha( s[i]) && !isdigit( s[i])) s[i] = ' ';
		
	}
	
	return num_m;
	
}
