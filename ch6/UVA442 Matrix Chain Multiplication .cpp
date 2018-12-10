#include<cstdio>			//�����ͷ�ļ��п�����isalpha���� 
#include<stack>
#include<iostream>
#include<string>
using namespace std;

//��ʱ�����ýṹ��Ҳ�ܷ��� 
struct Matrix {
	int a, b;
	//�����Ժ���������÷� 
	Matrix(int a = 0, int b = 0) : a(a), b(b) {}		//����������Է���ֱ�Ӷ���Matrix���͵ı���������Matrix(1, 2);	
}m[26];			//��Ӧ26����д��ĸ�����������ΪA�����������е�λ��Ϊ'A' - 'A'����0 

stack<Matrix> s;
 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	//������Ϣ�Ķ��� 
	for(int i = 0; i < n; i++) {
		string name;;
		cin >> name;
		int k = name[0] - 'A';				//λ�� 
		cin >> m[k].a >> m[k].b; 
	}
	//���ʽ�Ķ����봦�� 
	string expr;
	while(cin >> expr) {
		int len = expr.length();
		bool error = false;					//�ж��Ƿ���ʽ���� 
		int ans = 0;
		for(int i = 0; i < len; i++) {
			if(isalpha(expr[i])) s.push(m[expr[i] - 'A']);
			else if(expr[i] == ')') {
				Matrix m2 = s.top(); s.pop();
				Matrix m1 = s.top(); s.pop();
				if(m1.b != m2.a) { error = true; break; }	//ע�����Ժ�д�ĸ�ʽ 
				ans += m1.a * m1.b * m2.b;
				s.push(Matrix(m1.a, m2.b));	//�ṹ�庯���������ڴ����� 
				//Matrix();					//����д��ṹ��Matrix�е�a��b��ΪĬ�ϲ��� 
			} 
		}
		//��ӡ�����д��һ��������ģ�飬��һ����־��ȷ����ӡ���
		if(error) cout << "error\n"; else cout << ans << endl; 
	}
	return 0;
}
