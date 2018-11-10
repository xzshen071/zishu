#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=10+5;
map<string,int> IDcache;//将集合映射为ID 
map<long long,int> Rcache;//将二元组映射为行 
vector<int> v[maxn];
int num;//存编号 
int ID(string s);
long long combine(int x,int y);

int main(){
	//行数，列数
	int cols,rows,flag;
	while(cin >> rows >> cols){
		num=0;flag=1;
		IDcache.clear();//将IDcache清空 
		//一行一行输入，将其映射为编号
		for(int i=0;i<rows;i++){
			string line;
			if(flag){//把第一次输入的空格读掉 
				char c=getchar();
				flag=0;
			}
			getline(cin,line);
			//cout << line.size() << "\n";
			
			//将' '将变成'.'，将','变成‘ ’
			for(int j=0;j<line.size();j++){
				if(line[j]==' ')
					line[j]='-';
				else if(line[j]==',')
					line[j]=' ';				
				
			} 
			//cout << line << "\n";
			
			//分列存字符串 
			stringstream ss(line);
			string s;
			for(int j=0;j<cols;j++){
				ss >> s;
				//cout << s << "\n";
				
				//将集合编号 
				if(IDcache.count(s)==0){
					IDcache[s]=num;
					num++;					
				} 
				//存各字符串
				v[j].push_back(IDcache[s]);
				
			}
				 
		}
		
		for(int i=0;i<cols;i++){
			for(int j=0;j<rows;j++){
				cout << v[i][j] << " ";
				
			}
			cout << "\n";
		} 
		
		int flag1=1,flag2=1;
		Rcache.clear();//将Rcache清空 
		//列扫描，从上至下
		for(int i=0;i<cols;i++){
			for(int j=i+1;j<cols;j++){
				for(int k=0;k<rows;k++){
					//变成二元组ab的形式
					long long ab=combine(v[i][k],v[j][k]);
					cout << ab << "\n";
					if(Rcache.count(ab)==0) 
						Rcache[ab]=k;
					else{
						if(flag1){ printf("NO\n"); flag1=0;}
						printf("%d %d\n%d %d\n",Rcache[ab]+1,k+1,i+1,j+1);
						flag2=0;
					}
					
					
				}
				
			}
			
		}
		if(flag2) cout << "YES" << "\n"; 
	
	
	}	
	

	
	return 0;
} 
//生成二元组 
long long combine(int x,int y){
	int len,y1=y;
	while(y1){
		y1/=10;
		len++;
	}
	long long z=x*pow(10,len)+y;
	return z;
	
}


