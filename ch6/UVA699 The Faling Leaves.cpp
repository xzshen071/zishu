#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 80 + 10;
int sum[maxn];

//�������ͳ��
void build(int pos) {
	int v;
	cin >> v;
	if(v == -1) return;			//���������ݹ���˳������� 
	sum[pos] += v;				//ͳ��ÿ��λ�õ�ֵ�����ÿ�����Ҫ���Ķ����� 
	build(pos-1);				//������ 
	build(pos+1); 				//������ 
} 

//�Ӹ���㿪ʼ���ݹ�Ҳ������һ����ʼ���� 
bool init() {
	int v;
	cin >> v;
	if(v == -1) return false;
	memset(sum, 0, maxn*sizeof(int)); 
	int pos = maxn/2;			//������λ�����м� 
	sum[pos] = v;					 
	build(pos-1);				//������Ӧ�������� 
	build(pos+1); 				//������Ӧ�������� 
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
