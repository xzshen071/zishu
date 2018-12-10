#include<cstdio>			//在这个头文件中可以用isalpha函数 
#include<stack>
#include<iostream>
#include<string>
using namespace std;

//有时候用用结构体也很方便 
struct Matrix {
	int a, b;
	//可以以后用用这个用法 
	Matrix(int a = 0, int b = 0) : a(a), b(b) {}		//这个函数可以方便直接定义Matrix类型的变量，例如Matrix(1, 2);	
}m[26];			//对应26个大写字母，例如矩阵名为A，则在数组中的位置为'A' - 'A'，即0 

stack<Matrix> s;
 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	//矩阵信息的读入 
	for(int i = 0; i < n; i++) {
		string name;;
		cin >> name;
		int k = name[0] - 'A';				//位置 
		cin >> m[k].a >> m[k].b; 
	}
	//表达式的读入与处理 
	string expr;
	while(cin >> expr) {
		int len = expr.length();
		bool error = false;					//判断是否表达式错误 
		int ans = 0;
		for(int i = 0; i < len; i++) {
			if(isalpha(expr[i])) s.push(m[expr[i] - 'A']);
			else if(expr[i] == ')') {
				Matrix m2 = s.top(); s.pop();
				Matrix m1 = s.top(); s.pop();
				if(m1.b != m2.a) { error = true; break; }	//注意我以后写的格式 
				ans += m1.a * m1.b * m2.b;
				s.push(Matrix(m1.a, m2.b));	//结构体函数的作用在此体现 
				//Matrix();					//这样写则结构体Matrix中的a和b都为默认参数 
			} 
		}
		//打印，最好写成一个单独的模块，用一个标志来确定打印结果
		if(error) cout << "error\n"; else cout << ans << endl; 
	}
	return 0;
}
