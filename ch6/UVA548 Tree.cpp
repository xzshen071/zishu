#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

const int maxn = 10000 +5;
int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn];		//存中序、后续遍历的数据以及对应左子树和右子树编号 
int n;

//读数据 
bool read_list(int* a) {
	string line;
	if(!getline(cin, line)) return false;
	stringstream ss(line);
	n = 0;
	int x;
	while(ss >> x) a[n++] = x;
	//while(ss >> a[n++]);	//n会多加1 
	return n > 0;
}
//把in_order[L1..R1]和post_order[L2..R2]建成一颗二叉树，返回根 
int bulid(int L1, int R1, int L2, int R2) {
	if(L1 > R1) return 0;					//递归的结束条件 
	int root = post_order[R2];
	int pos = L1;
	while(in_order[pos] != root) pos++;
	int cnt = pos - L1;
	lch[root] = bulid(L1, pos-1, L2, L2+cnt-1); 
	rch[root] = bulid(pos+1, R1, L2+cnt, R2-1); 
	return root;	
}
//遍历树，得到叶结点的最短路径对应的叶结点权值
int best, best_sum;							//当你是用递归方法的时候，不能在函数里面定义值 
void dfs(int u, int sum) {
	sum += u;
	if(!lch[u] && !rch[u]) {				//叶结点 
		if(sum < best_sum || (sum == best_sum && u < best)) {
			best_sum = sum;
			best = u;
		}
		return;
	}	
	if(lch[u]) dfs(lch[u], sum);
	if(rch[u]) dfs(rch[u], sum);	
} 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(read_list(in_order)) {
		read_list(post_order);
		memset(lch, 0, maxn*sizeof(int));
		memset(rch, 0, maxn*sizeof(int));
		bulid(0, n-1, 0, n-1);			//建树 
		best_sum = 100000000; 
		dfs(post_order[n-1], 0);		//遍历树得结果 
		cout << best << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
