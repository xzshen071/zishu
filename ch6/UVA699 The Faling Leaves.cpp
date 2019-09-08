#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 80 + 10;
int sum[maxn];

//边输入边统计
void build(int pos) {
	int v;
	cin >> v;
	if(v == -1) return;			//无子树（递归的退出条件） 
	sum[pos] += v;				//统计每个位置的值（针对每个结点要做的动作） 
	build(pos-1);				//左子树 
	build(pos+1); 				//右子树 
} 

//从根结点开始（递归也必须有一个初始化） 
bool init() {
	int v;
	cin >> v;
	if(v == -1) return false;
	memset(sum, 0, maxn*sizeof(int)); 
	int pos = maxn/2;			//根结点的位置在中间 
	sum[pos] = v;					 
	build(pos-1);				//根结点对应的左子树 
	build(pos+1); 				//根结点对应的右子树 
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int kase = 0;
	while(init()) {
		printf("Case %d:\n", ++kase);
		int pos = 0, flag = 0;
		while(sum[pos] == 0) pos++;
		while(sum[pos]) {
			if(flag) cout << " "; else flag = 1;
			cout << sum[pos++]; 
		}
		cout << endl << endl;
	}
	//fclose(stdin);
    //fclose(stdout);
	return 0;
	
} 
