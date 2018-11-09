#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
using namespace std;

const int maxn = 10 + 5;	

int num[maxn];				//存0~9依次出现的次数 
string to_s(int a);
int main() {
	//string tmp = to_s(985432);
	//cout << tmp << " " << tmp.size() << endl;
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	while(cin >> n) {
		while(n--) {
			memset(num, 0 ,sizeof(num));
			int t;
			cin >> t;
			//对从1~n的整数按string类型处理 
			for(int i = 1; i <= t; i++) {
				string tmp = to_s(i);
				//cout << tmp << " " << tmp.size() << endl;
				for(int j = 0; j < tmp.size(); j++) {
					if(tmp[j] == '0') num[0]++;
					else if(tmp[j] == '1') num[1]++;
					else if(tmp[j] == '2') num[2]++;
					else if(tmp[j] == '3') num[3]++;
					else if(tmp[j] == '4') num[4]++;
					else if(tmp[j] == '5') num[5]++;
					else if(tmp[j] == '6') num[6]++;
					else if(tmp[j] == '7') num[7]++;
					else if(tmp[j] == '8') num[8]++;
					else if(tmp[j] == '9') num[9]++;
				} 
			}
			int flag = 1;
			for(int i = 0; i < 10; i++) {
				if(flag) flag = 0;
				else cout << " ";
				cout << num[i];
			}
			cout << endl; 
		}	
	}
	
	return 0;
}
string to_s(int a) {
	stringstream ss;
	ss << a;
	string s = ss.str();
	
	return s;
}
