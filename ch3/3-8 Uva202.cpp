#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

vector<int> rem;				//������ 
vector<int> result;				//��С����ÿһλ����Ľ�� 
int find_rem(int tmp);			//���Ƿ������ͬ������������������λ�ã�û�ҵ�����-1���ҵ��򷵻�λ�ã� 
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int a, b;
	while(scanf("%d%d", &a, &b) == 2) {
		rem.clear();
		result.clear();
		 
		int l;						//aΪ������bΪ��������lΪѭ������ 
		int tmp = a / b;//��������
		printf("%d/%d = %d.", a, b, tmp);
		//cout << endl;
		//�ѵ�һ����������� 
		a %= b;
		rem.push_back(a);
		a*=10;
		result.push_back(a/b);
		a %= b;
		int flag = 0;						//�����ж�����*10�Ƿ������ˣ�����ѭ��С���� 
		while(find_rem(a) == -1) {			//����ģ�⣬�ҵ���ͬ��λ�òŽ��� 
			if(a == 0) {					//����Ϊ0 
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
		//�����һ�� 
		if(flag) {							//��Ϊ����Ϊ0����ѭ�� 
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
		//����ڶ���
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

