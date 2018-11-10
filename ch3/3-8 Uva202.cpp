#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

vector<int> rem;				//存余数 
vector<int> result;				//存小数后每一位相除的结果 
int find_rem(int tmp);			//找是否存在相同的余数，返回余数的位置（没找到返回-1，找到则返回位置） 
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int a, b;
	while(scanf("%d%d", &a, &b) == 2) {
		rem.clear();
		result.clear();
		 
		int l;						//a为除数，b为被除数，l为循环长度 
		int tmp = a / b;//整数部分
		printf("%d/%d = %d.", a, b, tmp);
		//cout << endl;
		//把第一个余数算出来 
		a %= b;
		rem.push_back(a);
		a*=10;
		result.push_back(a/b);
		a %= b;
		int flag = 0;						//用来判断余数*10是否被整除了（不是循环小数） 
		while(find_rem(a) == -1) {			//除法模拟，找到相同的位置才结束 
			if(a == 0) {					//余数为0 
				flag = 1;
				break; 
			}
			rem.push_back(a);
			a *= 10; 
			result.push_back(a/b);
			a %= b;
			
		}
		//for(int i = 0; i < rem.size() && i < 50; i++) cout << rem[i] << " ";
		//cout << endl;
		//for(int i = 0; i < result.size() && i < 50; i++) cout << result[i] << " ";
		//cout << endl;
		//输出第一行 
		if(flag) {							//因为余数为0跳出循环 
			for(int i = 0; i < result.size() && i < 50; i++) cout << result[i];
			cout << "(0)" << endl;
			l = 1; 
		}else {
			int pos = find_rem(a);
			for(int i = 0; i < result.size() && i < 50; i++) {
				if(i < pos || i > pos) cout << result[i];
				else if(i == pos) cout << "(" << result[i];
			}
			if(result.size() > 50) cout << "...)" << endl;
			else cout << ")" << endl;
			l = result.size() - pos;
		}
		//输出第二行
		printf("   %d = number of digits in repeating cycle\n\n", l);
	}
	
	return 0;
}
int find_rem(int tmp) {
	for(int i = 0; i < rem.size(); i++) {
		if(tmp == rem[i])
			return i;
	}
	
	return -1;
} 

