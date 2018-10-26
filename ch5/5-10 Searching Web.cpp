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

vector<string> art[maxn];							//存每篇文章对应的每一行的内容 
map<string, map<int, vector<int> > > pos;			//用于映射单词在某篇文章，某一行的位置 
int n;												//文章数 
int t;												//命令数
int flag3;											//判断是不是打印命令结果的第一行 
int symbol;											//判断是否找到	

void deal_row( string &s);							//用引用的方式改变内容
void save_pos( string s, int i, int &j); 			//对每行的每个单词进行映射
void print(const string& s,int len,char extra);
void print_line( string A, string B = "1", int k = -1);
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	//读文章 
	cin >> n;
	int flag1 = 1;
	for(int i = 0; i < n; i++){			//文章次序从0开始 
		//可能需要读一下空行符
		if( flag1){ flag1 = 0; char c = getchar();}
		
		//读文章每一行并处理 
		string line1; 
		int hang = 0;
		while( getline(cin, line1)){
			if( line1[0] == '*') break;		//这一篇文章结束
			
			art[i].push_back(line1);		//存第i篇文章的某行
			 
			deal_row(line1);				//处理文章每一行
			//cout << line1 << endl;
			
			save_pos(line1, i, hang);		//对每行的每个单词进行映射 
			
			
		}
		//cout << hang << endl;		
		
	} 
	
	//读命令 
	cin >> t;
	int flag2 = 1;
	string line2;
	while( t--){
		if( flag2){ flag2 = 0; char c = getchar();}
		getline(cin, line2);
		
		//判断指令  
		int num_k = 1;						//记录此命令有几个空格，+1则是有几个字符串				 
		for(int i = 0; i < line2.size(); i++)  if( line2[i] == ' ') num_k++;
		stringstream ss(line2); 
		string s;
		flag3 = 1;
		symbol = 0;	
		
		if( num_k == 1){					//找到有A字符串的文章			
			ss >> s;
			print_line(s);					//打印有s的行 
			
		}else if( num_k == 3){				//找到有A和B字符串的文章或者找到有A或者B字符串的文章 
			vector<string> tmp_s;
			while( num_k--){ ss >> s; tmp_s.push_back(s);}
			
			if( tmp_s[1] == "AND"){
				//判断某一篇文章里是不是既有A又有B
				for(int i = 0; i < n; i++){
					if( pos[tmp_s[0]][i].size() != 0 && pos[tmp_s[2]][i].size() != 0 ) print_line( tmp_s[0], tmp_s[2], i);
					
				}
			
			}
			else{ print_line( tmp_s[0], tmp_s[2]);}
				
			
		}else{								//找到没有A字符串的文章 
			while( num_k--)  ss >> s;
			for(int i = 0; i < n; i++){		
				if( pos[s][i].size() == 0){	//第i篇文章没有字符串A  
					//输出整篇文章
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
//将','和'.'字符变成' '，大写变小写 
void deal_row(string &s){
	//将','和'.'字符变成' '
	for( int i = 0; i < s.size(); i++){
		if( !isalpha(s[i])) 
			s[i] = ' ';
			
	}
	//大写变小写 
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	
} 

//对每行的每个单词进行映射
void save_pos( string s, int i, int &j){
	stringstream ss(s);
	
	string tmp;
	while( ss >> tmp && tmp[0] != ' '){
		vector<int>::iterator it = find(pos[tmp][i].begin(), pos[tmp][i].end(), j);;
 
		if (it == pos[tmp][i].end()){
			pos[tmp][i].push_back( j);
		}
			
	}
		
	j++;	//下一行 

}
void print(const string& s,int len,char extra){
	cout << s;
	for(int i=0;i<len-s.length();i++){
		cout << extra;
		
	}
	

}
//打印还有A和B字符串的行 
void print_line( string A, string B, int k){		//k指代第K篇文章 
	int tmp; 
	
	if( k != -1){											//打印第k篇文章的行 
		if( flag3) flag3 = 0; else{ print("", 10, '-'); cout << endl;}
		/*
		//打印A 
		for( int i = 0; i < pos[A][k].size(); i++){
				tmp = pos[A][k][i];
				cout << art[k][tmp] << endl;
				symbol = 1;
			
		}
		//打印B，B可能等于"1" 
		for( int i = 0; B != "1" && i < pos[B][k].size(); i++){
				tmp = pos[B][k][i];
				cout << art[k][tmp] << endl;
				symbol = 1;
		}
		*/
		//A和B需要一起打印
		set<int> order;										//存打印次序
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
			
		
		
		
	}else{													//打印所有文章的行 
		for( int i = 0; i < n; i++){
			if(pos[A][i].size() != 0 || pos[B][i].size() != 0) print_line(A,B,i);
			
				
		
		} 
		
		
		
		
	}
	
	
	
	
} 


