#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxh = 200 + 5;
string tab[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
int H, W;
int sum[6];
int circle;
void DFS0(int x, int y, string *g) {
	if(x < 0 || x > (H+1) || y < 0 || y > (4*W+1)) return;
	if(g[x][y] != '0') return;
	g[x][y] = 'z';
	DFS0(x+1, y, g);
	DFS0(x-1, y, g);
	DFS0(x, y+1, g);
	DFS0(x, y-1, g);
}
void DFS1(int x, int y, string *g) {
	if(x < 0 || x > (H+1) || y < 0 || y > (4*W+1) || g[x][y] == 'z') return;
	if(g[x][y] == '0') {
		circle++;
		DFS0(x, y, g);
	}
	g[x][y] = 'z';
	DFS1(x+1, y, g);
	DFS1(x-1, y, g);
	DFS1(x, y+1, g);
	DFS1(x, y-1, g);	
}	

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int kase = 0;
	while(cin >> H >> W) {
		string g[maxh];
		if(H == 0 || W == 0) break;
		//外围加'0'
		for(int i = 0; i <= (4*W+1); i++) {
			g[0] += '0';
			g[H+1] += '0'; 
		}
		for(int i = 1; i <= H; i++) {
			g[i] += '0'; 
			for(int j = 1; j <= W; j++) {
				char c;
				cin >> c;
				if(c >= '0' && c <= '9') g[i] += tab[c - '0'];
				else if(c >= 'a' && c <= 'f') g[i] += tab[c - 87];
			}
			g[i] += '0';
		} 
		/* 
		for(int i = 0; i <= (H+1); i++) 
			cout << g[i] << endl;
		*/
		DFS0(0, 0, g);								//DFS符号外围的'0' 
		/* 
		for(int i = 0; i <= (H+1); i++) 
			cout << g[i] << endl;
		*/
		memset(sum, 0, sizeof(sum));
		//通过判断符号里有几个圈来获得结果 
		for(int i = 1; i <= H; i++)
			for(int j = 1; j <= 4*W; j++) {
				if(g[i][j] == '1') {
					circle = 0;
					DFS1(i, j, g);	
					sum[circle]++;
				}
			}
		//打印结果 
		printf("Case %d: ", ++kase);
		if(sum[1] != 0) 
			for(int i = 0; i < sum[1]; i++)
				cout << "A";
		if(sum[5] != 0) 
			for(int i = 0; i < sum[5]; i++)
				cout << "D";
		if(sum[3] != 0) 
			for(int i = 0; i < sum[3]; i++)
				cout << "J";
		if(sum[2] != 0) 
			for(int i = 0; i < sum[2]; i++)
				cout << "K";
		if(sum[4] != 0) 
			for(int i = 0; i < sum[4]; i++)
				cout << "S";
		if(sum[0] != 0) 
			for(int i = 0; i < sum[0]; i++)
				cout << "W";	
		cout << endl;		
	}	
	return 0;
}

