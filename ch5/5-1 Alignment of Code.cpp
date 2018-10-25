#include<iostream>
#include<sstream>
#include<vector>
#include<string> 
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1000 + 5;
const int maxl = 180 + 5;
vector<string> code[maxn];	//�������
int lens[maxl];	//��ÿ������ַ����� 

void print(const string& s,int len,char extra);
int main(){
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	memset(lens,0,sizeof(lens));	//lens�������� 
	string line;
	int rows=1,cols=1;
	while( getline(cin, line)){
		stringstream ss(line);
		string s;
		
		int k=1;
		while(ss >> s){
			int l = s.length();
			//cout << l << endl;
			lens[k] = max(lens[k], l); 
			k++;
			code[rows].push_back(s);
			
		}
		rows++;
		cols = max(k,cols);		//��ȡ������� 
		//cout << cols << endl;

	}
	/* 
	for(int i = 1; i < cols ; i++){
		cout << lens[i] << " ";
	} 
	cout << endl;
	*/ 
	
	
	for(int i = 1; i < rows; i++){
		for(int j = 1; j <= code[i].size(); j++){
			if( j == code[i].size()) cout << code[i][j-1];	//ÿ�����һ�У����ĩβ�����пո� 
			else print(code[i][j-1], lens[j]+1, ' ');		//lens[j]+1��֤�ַ���֮��������һ��' '�� 
			
		}
		cout << endl;
		
	}
	
	
	return 0;
}
void print(const string& s,int len,char extra){
	cout << s;
	for(int i=0;i<len-s.length();i++){
		cout << extra;
		
	}
	

}
