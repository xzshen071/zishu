#include<cstdio>
#include<iostream>
using namespace std;

//判断天平是否平衡，平衡条件是左边和右边都平衡（递归实现），W为修改为子天平的总重量 
bool solve(int &W) {
	int W1, D1, W2, D2;
	cin >> W1 >> D1 >> W2 >> D2;
	bool b1 = true, b2 = true;					//b1代表左天平是否平衡，b2代表右天平是否平衡。最后是平衡的（最后没有对应的子天平为叶结点）
	if(!W1) b1 = solve(W1);						//左天平还有子天平
	if(!W2) b2 = solve(W2);						//右天平还有子天平
	W = W1 + W2;								//子天平对应的总重量
	return b1 && b2 && (W1 * D1 == W2 * D2); 	//判断此子天平（非叶结点）是否平衡 
} 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T, W;
	cin >> T;
	while(T--) {
		if(solve(W)) cout << "YES\n"; else cout <<"NO\n";	//solve函数用来判断天平是否平衡 
		if(T) cout <<"\n";									//最后一个case后面不需要打空行 
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
