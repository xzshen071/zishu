#include<cstdio>
#include<iostream>
using namespace std;

//�ж���ƽ�Ƿ�ƽ�⣬ƽ����������ߺ��ұ߶�ƽ�⣨�ݹ�ʵ�֣���WΪ�޸�Ϊ����ƽ�������� 
bool solve(int &W) {
	int W1, D1, W2, D2;
	cin >> W1 >> D1 >> W2 >> D2;
	bool b1 = true, b2 = true;					//b1��������ƽ�Ƿ�ƽ�⣬b2��������ƽ�Ƿ�ƽ�⡣�����ƽ��ģ����û�ж�Ӧ������ƽΪҶ��㣩
	if(!W1) b1 = solve(W1);						//����ƽ��������ƽ
	if(!W2) b2 = solve(W2);						//����ƽ��������ƽ
	W = W1 + W2;								//����ƽ��Ӧ��������
	return b1 && b2 && (W1 * D1 == W2 * D2); 	//�жϴ�����ƽ����Ҷ��㣩�Ƿ�ƽ�� 
} 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T, W;
	cin >> T;
	while(T--) {
		if(solve(W)) cout << "YES\n"; else cout <<"NO\n";	//solve���������ж���ƽ�Ƿ�ƽ�� 
		if(T) cout <<"\n";									//���һ��case���治��Ҫ����� 
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
