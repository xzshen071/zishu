#include<cstdio>
#include<cmath>
#include<sstream>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ตรทึ
	int t;
	while(cin >> t) {
		getchar();
		string line;
		while(t--) {
			int sorce=0,kase=0;
			getline(cin, line);
			for(int i =0; i < line.size(); i++) {
				if(line[i] == 'O'){
					kase++;
					sorce+=kase;
			
				}else
					kase=0;
				
			}
			printf("%d\n",sorce);	
		}
	}
	return 0; 
}



