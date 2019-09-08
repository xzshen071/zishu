#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

const int maxn = 10000 +5;
int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn];		//�����򡢺��������������Լ���Ӧ����������������� 
int n;

//������ 
bool read_list(int* a) {
	string line;
	if(!getline(cin, line)) return false;
	stringstream ss(line);
	n = 0;
	int x;
	while(ss >> x) a[n++] = x;
	//while(ss >> a[n++]);	//n����1 
	return n > 0;
}
//��in_order[L1..R1]��post_order[L2..R2]����һ�Ŷ����������ظ� 
int bulid(int L1, int R1, int L2, int R2) {
	if(L1 > R1) return 0;					//�ݹ�Ľ������� 
	int root = post_order[R2];
	int pos = L1;
	while(in_order[pos] != root) pos++;
	int cnt = pos - L1;
	lch[root] = bulid(L1, pos-1, L2, L2+cnt-1); 
	rch[root] = bulid(pos+1, R1, L2+cnt, R2-1); 
	return root;	
}
//���������õ�Ҷ�������·����Ӧ��Ҷ���Ȩֵ
int best, best_sum;							//�������õݹ鷽����ʱ�򣬲����ں������涨��ֵ 
void dfs(int u, int sum) {
	sum += u;
	if(!lch[u] && !rch[u]) {				//Ҷ��� 
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
		bulid(0, n-1, 0, n-1);			//���� 
		best_sum = 100000000; 
		dfs(post_order[n-1], 0);		//�������ý�� 
		cout << best << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
