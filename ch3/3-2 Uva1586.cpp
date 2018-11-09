#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<cctype>
#include<sstream>
using namespace std;

const int maxn = 80 + 5;

char atom[maxn];				//原子名称 
int num[maxn];					//对应的原子数量 
map<char, double> atom_w;		//原子映射原子质量 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//原子映射原子量
	atom_w['C'] = 12.01;
	atom_w['H'] = 1.008;
	atom_w['O'] = 16.00;
	atom_w['N'] = 14.01;
	
	//读入原子名称和个数（分开存）
	int n;
	while(cin >> n) {
		while(n--) {	
			memset(atom, 0, sizeof(atom));				//初始化原子名称 
			for(int i = 0; i < maxn; i++) num[i] = 1;	//初始化原子数量 
			string tmp;
			cin >> tmp;
			//cout << tmp << endl;	
		 
			int pos = 0;							//用来表示存储的原子名称的位置 
			for(int i = 0; i < tmp.size(); i++) {
				if(isalpha(tmp[i])) {				//是字母 
					atom[pos] = tmp[i];
					pos++; 
					tmp[i] = ' '; 					//让这个位置变为空格，方便数字的读取 
				}else {
					if(pos > 0) num[pos - 1] = 0;	//做标记，说明这个位置对应的原子名称有超过数目1的数量 
				} 
			}
			//cout << tmp << endl;
			
			//cout << pos << endl;
			//存大于数目1的原子个数，其他默认为1 
			stringstream ss(tmp);
			for(int i = 0; i < pos; i++) {
				if(num[i] == 0) {
					ss >> num[i];
				}
			}
			//for(int i = 0; i < pos; i++) cout << num[i] << " ";
			//cout << endl; 
			
			//计算分子量
			double sum = 0.0; 
			for(int i = 0; i < pos; i++) {
				sum += (atom_w[atom[i]] * num[i]);
				//cout << (atom_w[atom[i]] * num[i]) << " ";
			}
			//cout << endl;
			printf("%.3f\n", sum); 	
		}		
	} 
	
	return 0;
} 
