//�����һ��Ӧ���������0 ~ 100000��Fibonacci��ֵ���ڶ������ֵ���ֻ�洢ǰ40�����֣������Ҽ��ɡ� 
#include<iostream>
#include<cstring>
#include<cstdlib>				//malloc���������� 
#include<algorithm>
#include<new>
using namespace std;
const int maxp = 100000;

int num = 0;
//void print_sq(string s);		//��ӡ����˿�ͷ��Fibonacci���� 
//string Fibonacci(int n);		//��n�����µ�Fibonacci��ֵ 
string add(string a, string b);	//string���ͼӷ� 

struct node{					//�ֵ����н�����Ϣ
	int id;						//�Ӹ���㵽�˽��������ִ�ǰ׺�Ĵ���
	node *next[10];				//����Ӵ˽������ı��Ϊ0 ~ 9���ӽ��
	node() {					//��ʼ�������Ϣ 
		id = -1;
		for(int i = 0; i < 10; i++) next[i] = NULL;
	} 	
};
void insert(node *root, string s, int id) {
	node *tmp = root;
	for(int i = 0; i < s.size(); i++) {
		int pos = s[i] - '0';
		if(tmp -> next[pos] == NULL) {
			tmp -> next[pos] = new node;
			tmp -> next[pos] -> id = id;
			tmp = tmp -> next[pos];
		}else {
			tmp = tmp -> next[pos];
		}
	}
}
int research(node *root, string s) {
	node *tmp = root;
	for(int i = 0; i < s.size(); i++) {
		int pos = s[i] - '0';
		if(tmp -> next[pos] == NULL) return -1;
		else tmp = tmp -> next[pos];
	}
	return tmp -> id;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	//�õ�0 ~ 100000��Fibonacci��ֵ�����Ҳ����ֵ�����
	//�ֵ�����ʼ�� 
	//node *root = (node*)malloc(sizeof(node)); 		//malloc������ö���Ĺ��캯������new�ᣬ������node() {}��newҲ����Ҫָ�������ڴ� 
	node *root = new node;								//new��malloc�����Կ��ٿռ䣬new�Ǵ����ɴ��������䣬��malloc�ǴӶ��Ϸ��䣻new��delete��Ӧ��malloc��free��Ӧ 
	insert(root, "0", 0); 
	insert(root, "1", 1);
	
	string a, b, sum;
	a = "0"; b = "1";
	for(int i = 2; i <= maxp; i++) {					//�����ű��������Ҫ-1����Ϊ��ʼֵ��0��1 
		//string sum = add(a, b);
		sum = add(a, b);
		a = b;
		b = sum;
		if(sum.size() > 40) sum = sum.substr(0,40);		//ֻȡǰ40�����֣���Ϊ���벻����40�� 
		insert(root, sum, i); 
	}
	//cout << sum << endl;
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		printf("Case #%d: ", i);
		
		int pos = research(root, s);					//�ҵ�����˿�ͷ��Fibonacci���� 
		if(pos == -1) cout << "-1" << endl;
		else cout << (pos - 1) << endl;
	}
	
	return 0;
}
/*
//(1)string���ͼӷ�
string add(string a, string b) {
	string result;
	
	int len1 = a.length();
	int len2 = b.length();
	//ǰ�油��Ū����ͬ����
	if(len1 < len2) {
		for(int i = 1; i <= len2 - len1; i++)
			a = "0" + a;
	}else {
		for(int i = 1; i <= len1 - len2; i++)
			b = "0" + b;		
	}
	int len = a.length();								//���߳��� 
	int cf = 0;											//��λ
	int tmp;											//����λ�������
	for(int i = len -1; i >=0; i--) {
		tmp = a[i] - '0' + b[i] -'0' + cf;
		cf = tmp / 10;									//��λ 
		tmp %= 10;										//����
		result = char(tmp + '0') + result; 
	} 
	if(cf != 0) result = char(cf + '0') + result;		//���һλ��λ����0 
	return result; 
} 
*/
//(2)string���ͼӷ���(2)��(1)�� 
string add(string a,string b) {

	int i = a.size() - 1;
	int j = b.size() - 1;
	int in = 0;											//��λ 
	string result = "";
	while (i >= 0 && j >= 0) {							//��λ����ͬ�Ĳ��ֽ���ģ��ӷ����� 
		int tmp = (a[i] - '0') + (b[j] - '0') + in;
		in = tmp / 10;
		tmp %= 10;
		result += (tmp + '0');
		//result = char(tmp + '0') + result;
		
		i--;
		j--;
	}
	//��λ����Ķ������λ����������
	while (i >= 0) {										 
		int tmp = (a[i] - '0') + in;
		in = tmp / 10;
		tmp %= 10;
		result += (tmp + '0');
		//result = char(tmp + '0') + result;
		
		i--;
	}
	while (j >= 0) {
		int tmp = (b[j] - '0') + in;
		in = tmp / 10;
		tmp %= 10;
		result += (tmp + '0');
		//result = char(tmp + '0') + result;		//���������������е�ʱ�䣬ԭ��Ӧ����ǿ������ת�������ѵ�ʱ�� 
		
		j--;
	}
	if(in) result += (in + '0');					//���һλ��λ����0	
	reverse(result.begin(),result.end());			//��ת����Ϊ�ǴӺ�ӵ�ǰ��� 
	return result;
}
/*
//������������������һ��ʼ��ķ�����ʱ 
//��ӡ����˿�ͷ��Fibonacci���򣬳�ʱ�� 
void print_sq(string s2) {
	int flag = 1;
	for(int i = 0; i < maxp; i++) {
		string s1 = Fibonacci(i);
		cout << s1 << endl;
	}
	if(flag) printf("Case #%d: -1", ++num);
	
}
//��n�����µ�Fibonacci��ֵ
string Fibonacci(int n) {
	if(n == 0 || n == 1) return "1";
	
	string a, b, tmp;
	a = b = "1";
	
	for(int i = 2; i <= n; i++) {
		tmp = b;
		b = add(a, b);
		a = tmp;	
	}
	return b;
} 
*/ 
/* 
//��malloc��free��ʾnew���൱��malloc��ԭʼ���أ�new���Ѿ��ֺõ����� 
void * operator new (sieze_t size)
{
    if(void * mem = malloc(size)) 
        return mem;
    else
        throw bad_alloc();
}
void operator delete(void *mem) noexcept
{
    free(mem);
} 
*/ 


