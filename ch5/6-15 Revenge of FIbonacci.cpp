//此题第一步应该求出次序0 ~ 100000的Fibonacci的值，第二部用字典树只存储前40个数字，最后查找即可。 
#include<iostream>
#include<cstring>
#include<cstdlib>				//malloc函数在里面 
#include<algorithm>
#include<new>
using namespace std;
const int maxp = 100000;

int num = 0;
//void print_sq(string s);		//打印满足此开头的Fibonacci次序 
//string Fibonacci(int n);		//求n次序下的Fibonacci的值 
string add(string a, string b);	//string类型加法 

struct node{					//字典树中结点的信息
	int id;						//从根结点到此结点最早出现此前缀的次序
	node *next[10];				//定义从此结点出发的编号为0 ~ 9的子结点
	node() {					//初始化结点信息 
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
	
	//得到0 ~ 100000的Fibonacci的值，并且插入字典树中
	//字典树初始化 
	//node *root = (node*)malloc(sizeof(node)); 		//malloc不会调用对象的构造函数，而new会，如此题的node() {}，new也不需要指定开辟内存 
	node *root = new node;								//new和malloc都可以开辟空间，new是从自由储存区分配，而malloc是从堆上分配；new和delete对应，malloc和free对应 
	insert(root, "0", 0); 
	insert(root, "1", 1);
	
	string a, b, sum;
	a = "0"; b = "1";
	for(int i = 2; i <= maxp; i++) {					//次序编号比我们想的要-1，因为初始值是0，1 
		//string sum = add(a, b);
		sum = add(a, b);
		a = b;
		b = sum;
		if(sum.size() > 40) sum = sum.substr(0,40);		//只取前40个数字（因为输入不超过40） 
		insert(root, sum, i); 
	}
	//cout << sum << endl;
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		printf("Case #%d: ", i);
		
		int pos = research(root, s);					//找到满足此开头的Fibonacci次序 
		if(pos == -1) cout << "-1" << endl;
		else cout << (pos - 1) << endl;
	}
	
	return 0;
}
/*
//(1)string类型加法
string add(string a, string b) {
	string result;
	
	int len1 = a.length();
	int len2 = b.length();
	//前面补零弄成相同长度
	if(len1 < len2) {
		for(int i = 1; i <= len2 - len1; i++)
			a = "0" + a;
	}else {
		for(int i = 1; i <= len1 - len2; i++)
			b = "0" + b;		
	}
	int len = a.length();								//两者长度 
	int cf = 0;											//进位
	int tmp;											//得两位得相加数
	for(int i = len -1; i >=0; i--) {
		tmp = a[i] - '0' + b[i] -'0' + cf;
		cf = tmp / 10;									//进位 
		tmp %= 10;										//余数
		result = char(tmp + '0') + result; 
	} 
	if(cf != 0) result = char(cf + '0') + result;		//最后一位进位不是0 
	return result; 
} 
*/
//(2)string类型加法，(2)比(1)快 
string add(string a,string b) {

	int i = a.size() - 1;
	int j = b.size() - 1;
	int in = 0;											//进位 
	string result = "";
	while (i >= 0 && j >= 0) {							//对位数相同的部分进行模拟加法操作 
		int tmp = (a[i] - '0') + (b[j] - '0') + in;
		in = tmp / 10;
		tmp %= 10;
		result += (tmp + '0');
		//result = char(tmp + '0') + result;
		
		i--;
		j--;
	}
	//对位数大的多出来的位数单独处理
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
		//result = char(tmp + '0') + result;		//这句语句增加了运行的时间，原因应该是强制类型转换所花费的时间 
		
		j--;
	}
	if(in) result += (in + '0');					//最后一位进位不是0	
	reverse(result.begin(),result.end());			//反转，因为是从后加到前面的 
	return result;
}
/*
//不用下面两个函数，一开始想的方法超时 
//打印满足此开头的Fibonacci次序，超时。 
void print_sq(string s2) {
	int flag = 1;
	for(int i = 0; i < maxp; i++) {
		string s1 = Fibonacci(i);
		cout << s1 << endl;
	}
	if(flag) printf("Case #%d: -1", ++num);
	
}
//求n次序下的Fibonacci的值
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
//用malloc和free表示new，相当于malloc是原始土地，new是已经种好的土地 
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


