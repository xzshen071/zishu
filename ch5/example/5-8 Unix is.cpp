#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=100+5;
const int maxcol=60;
string filenames[maxn]; 

void print(const string &s,int len,char extra);
int main(){
	int n;
	while(cin >> n){
		//存字符串，找最大长度 
		int M=0;
		for(int i=0;i<n;i++){
			cin >> filenames[i];
			M=max(M,(int)filenames[i].length());
			
		}
		//确定行数列数
		int cols =(maxcol-M)/(M+2)+1,rows=(n-1)/cols+1;
		print("",60,'-');
		cout << "\n";
		sort(filenames,filenames+n);
		//一行一行输出
		for(int r=0;r<rows;r++){
			for(int c=0;c<cols;c++){
				int idx= c*rows +r;
				if(idx < n) print(filenames[idx],c==cols-1?M:M+2,' ');//如果是倒数第二列，则占用M个字符，不是则占用M+2个字符 
				
				
			}
			cout << "\n";
		}
		
		
		
		
	} 
	
	return 0;   
	
	
}
void print(const string &s,int len,char extra){
	cout << s;
	for(int i=0;i<len-s.length();i++){
		cout << extra;
		
	}
	
	
	
	
}
