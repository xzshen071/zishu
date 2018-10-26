#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<sstream>
#include<set>
using namespace std;
const int maxn = 100 + 5;
const int maxl = 80 +5;

vector<string> art[maxn];							//��ÿƪ���¶�Ӧ��ÿһ�е����� 
map<string, map<int, vector<int> > > pos;			//����ӳ�䵥����ĳƪ���£�ĳһ�е�λ�� 
int n;												//������ 
int t;												//������
int flag3;											//�ж��ǲ��Ǵ�ӡ�������ĵ�һ�� 
int symbol;											//�ж��Ƿ��ҵ�	

void deal_row( string &s);							//�����õķ�ʽ�ı�����
void save_pos( string s, int i, int &j); 			//��ÿ�е�ÿ�����ʽ���ӳ��
void print(const string& s,int len,char extra);
void print_line( string A, string B = "1", int k = -1);
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	//������ 
	cin >> n;
	int flag1 = 1;
	for(int i = 0; i < n; i++){			//���´����0��ʼ 
		//������Ҫ��һ�¿��з�
		if( flag1){ flag1 = 0; char c = getchar();}
		
		//������ÿһ�в����� 
		string line1; 
		int hang = 0;
		while( getline(cin, line1)){
			if( line1[0] == '*') break;		//��һƪ���½���
			
			art[i].push_back(line1);		//���iƪ���µ�ĳ��
			 
			deal_row(line1);				//��������ÿһ��
			//cout << line1 << endl;
			
			save_pos(line1, i, hang);		//��ÿ�е�ÿ�����ʽ���ӳ�� 
			
			
		}
		//cout << hang << endl;		
		
	} 
	
	//������ 
	cin >> t;
	int flag2 = 1;
	string line2;
	while( t--){
		if( flag2){ flag2 = 0; char c = getchar();}
		getline(cin, line2);
		
		//�ж�ָ��  
		int num_k = 1;						//��¼�������м����ո�+1�����м����ַ���				 
		for(int i = 0; i < line2.size(); i++)  if( line2[i] == ' ') num_k++;
		stringstream ss(line2); 
		string s;
		flag3 = 1;
		symbol = 0;	
		
		if( num_k == 1){					//�ҵ���A�ַ���������			
			ss >> s;
			print_line(s);					//��ӡ��s���� 
			
		}else if( num_k == 3){				//�ҵ���A��B�ַ��������»����ҵ���A����B�ַ��������� 
			vector<string> tmp_s;
			while( num_k--){ ss >> s; tmp_s.push_back(s);}
			
			if( tmp_s[1] == "AND"){
				//�ж�ĳһƪ�������ǲ��Ǽ���A����B
				for(int i = 0; i < n; i++){
					if( pos[tmp_s[0]][i].size() != 0 && pos[tmp_s[2]][i].size() != 0 ) print_line( tmp_s[0], tmp_s[2], i);
					
				}
			
			}
			else{ print_line( tmp_s[0], tmp_s[2]);}
				
			
		}else{								//�ҵ�û��A�ַ��������� 
			while( num_k--)  ss >> s;
			for(int i = 0; i < n; i++){		
				if( pos[s][i].size() == 0){	//��iƪ����û���ַ���A  
					//�����ƪ����
					if( flag3) flag3 = 0; else{ print("", 10, '-'); cout << endl;}
					for( int j = 0; j < art[i].size(); j++){ cout << art[i][j] << endl; symbol = 1;}
					
				}
				
				 
			}
			
		}
		if(symbol == 0) printf("Sorry, I found nothing.\n"); 
		
		print("", 10, '=');
		cout << endl;
		
		
			
	} 
	
	
	return 0;
} 
//��','��'.'�ַ����' '����д��Сд 
void deal_row(string &s){
	//��','��'.'�ַ����' '
	for( int i = 0; i < s.size(); i++){
		if( !isalpha(s[i])) 
			s[i] = ' ';
			
	}
	//��д��Сд 
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	
} 

//��ÿ�е�ÿ�����ʽ���ӳ��
void save_pos( string s, int i, int &j){
	stringstream ss(s);
	
	string tmp;
	while( ss >> tmp && tmp[0] != ' '){
		vector<int>::iterator it = find(pos[tmp][i].begin(), pos[tmp][i].end(), j);;
 
		if (it == pos[tmp][i].end()){
			pos[tmp][i].push_back( j);
		}
			
	}
		
	j++;	//��һ�� 

}
void print(const string& s,int len,char extra){
	cout << s;
	for(int i=0;i<len-s.length();i++){
		cout << extra;
		
	}
	

}
//��ӡ����A��B�ַ������� 
void print_line( string A, string B, int k){		//kָ����Kƪ���� 
	int tmp; 
	
	if( k != -1){											//��ӡ��kƪ���µ��� 
		if( flag3) flag3 = 0; else{ print("", 10, '-'); cout << endl;}
		/*
		//��ӡA 
		for( int i = 0; i < pos[A][k].size(); i++){
				tmp = pos[A][k][i];
				cout << art[k][tmp] << endl;
				symbol = 1;
			
		}
		//��ӡB��B���ܵ���"1" 
		for( int i = 0; B != "1" && i < pos[B][k].size(); i++){
				tmp = pos[B][k][i];
				cout << art[k][tmp] << endl;
				symbol = 1;
		}
		*/
		//A��B��Ҫһ���ӡ
		set<int> order;										//���ӡ����
		int lens = max(pos[A][k].size(), pos[B][k].size());
		for( int i = 0; i < lens; i++){
			if( i < pos[A][k].size()) order.insert( pos[A][k][i]);
			if( i < pos[B][k].size()) order.insert( pos[B][k][i]);
			
		}
		set<int>::iterator it;
		for( it = order.begin(); it != order.end(); it++){
			cout << art[k][*it] << endl;
			symbol = 1;
			
		}			
			
		
		
		
	}else{													//��ӡ�������µ��� 
		for( int i = 0; i < n; i++){
			if(pos[A][i].size() != 0 || pos[B][i].size() != 0) print_line(A,B,i);
			
				
		
		} 
		
		
		
		
	}
	
	
	
	
} 


