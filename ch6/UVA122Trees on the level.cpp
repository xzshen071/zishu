/* 
//指针实现
#include<cstdio> 
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100000 + 5;
char s[maxn];
int failed;			//判断输入是否有错误，包括对一个结点有两次以上的赋值、树中有些结点没有赋值	

struct Node {
	bool have_value;							//是否被赋值过
	int v;										//结点值
	Node *L, *R;		
	Node():have_value(false), L(NULL), R(NULL) { }	//构造函数，方便初始化结点的中的变量 
};
Node *root;										//二叉树根结点 

//分配空间。并进行初始化 
Node* newnode() {return new Node(); }			//定义静态的内存空间(确定大小)，内存是存放在栈中，程序执行完后自动销毁；定义动态的内存空间（不确定大小，需要根据实际确定），内存放在堆中，需要程序释放
//构建树
void addnode(int v, char *s) {
	int n = strlen(s);
	Node *u = root;								//从根结点往下走 
	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') {
			if(u->L == NULL) u->L = newnode();	//没有则创建结点 
			u = u->L;
		}else if(s[i] == 'R') {
			if(u->R == NULL) u->R = newnode();
			u = u->R;
		}
	}
	if(u->have_value) failed = true;
	u->v = v;
	u->have_value = true; 
} 
//读输入 
bool read_input() {
	failed = false;
	root = newnode();							//初始化根结点 
	for(;;) {
		if(scanf("%s", s) != 1) return false;	//没有输入了
		if(!strcmp(s, "()")) break;				//一课树的数据输入完毕
		int v;
		//sscanf(&s[1], "%d", &v);				//读入正整数，即结点数据
		sscanf(s+1, "%d", &v);
		addnode(v, strchr(s, ',')+1);			//strchr找到s中','的位置（指针），+1则对应后面的字母，这些字母对应结点在树中的位置	 
	} 
	return true; 
}
//遍历树（从上到下，从左到右） 
bool bfs(vector<int>& ans) {
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()) {
		Node* u = q.front(); q.pop();
		if(!u->have_value) return false;		//树中结点没有值
		ans.push_back(u->v);
		if(u->L != NULL) q.push(u->L); 
		if(u->R != NULL) q.push(u->R); 
	} 
	return true;
} 
//释放空间
void remove_tree(Node* u) {
	if(u == NULL) return;
	remove_tree(u->L);
	remove_tree(u->R);
	delete u;									//与new对应，delete释放通过new分配的空间 
} 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(read_input()) {
		//遍历树，结果存储在ans中 
		vector<int> ans;
		if(failed || !bfs(ans)) {
			cout << "not complete" << endl; 
		}else {									//打印遍历结果 
			bool flag = false; 
			for(int i = 0; i < ans.size(); i++) {
				if(flag) cout << " "; 
				else flag = true;
				cout << ans[i];
			} 
			cout << endl;
		} 
		remove_tree(root); 
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
*/
//数组实现（并不是用数组实现二叉树，因为最多可包含256个结点，开辟的数组大小将不可估量，而是不用指针，用数组也不用进行内存释放）
#include<cstdio> 
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxc = 100000 + 5;					//最大输入字符个数 
const int maxn = 256 + 5;						//最大节点数					
char s[maxc];
bool failed;									//判断输入是否有错误，包括对一个结点有两次以上的赋值、树中有些结点没有赋值	

const int root = 1;							    //二叉树根结点 
int cnt;										//存编号 
int L[maxn], R[maxn], value[maxn];			        //存左子树与右子树的编号和编号对应的值
bool have_value[maxn];							//编号对应是否存在值 

//初始化结点 
void newtree() {
	L[root] = R[root] = 0;
	have_value[root] = false;
	cnt = root;
}
int newnode() {
	int u = ++cnt;
	L[cnt] = R[cnt] = 0;
	have_value[cnt] = false;
	return u;
} 
			
//构建树
void addnode(int v, char *s) {
	int n = strlen(s);
	int u = root;								//从根结点往下走 
	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') {
			if(L[u] == 0) L[u] = newnode();	//没有则创建结点 
			u = L[u];
		}else if(s[i] == 'R') {
			if(R[u] == 0) R[u] = newnode();
			u = R[u];
		}
	}
	if(have_value[u]) failed = true;
	value[u] = v;
	have_value[u] = true; 
} 
//读输入 
bool read_input() {
	failed = false;
	newtree();									//初始化根结点 
	for(;;) {
		if(scanf("%s", s) != 1) return false;	//没有输入了
		if(!strcmp(s, "()")) break;				//一课树的数据输入完毕
		int v;
		//sscanf(&s[1], "%d", &v);				//读入正整数，即结点数据
		sscanf(s+1, "%d", &v);
		addnode(v, strchr(s, ',')+1);			//strchr找到s中','的位置（指针），+1则对应后面的字母，这些字母对应结点在树中的位置	 
	} 
	return true; 
}
//遍历树（从上到下，从左到右） 
bool bfs(vector<int>& ans) {
	queue<int> q;
	ans.clear();
	q.push(root);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(!have_value[u]) return false;		//树中结点没有值
		ans.push_back(value[u]);
		if(L[u] != 0) q.push(L[u]); 
		if(R[u] != 0) q.push(R[u]); 
	} 
	return true;
} 

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(read_input()) {
		//遍历树，结果存储在ans中 
		vector<int> ans;
		if(failed || !bfs(ans)) {
			cout << "not complete" << endl; 
		}else {									//打印遍历结果 
			bool flag = false; 
			for(int i = 0; i < ans.size(); i++) {
				if(flag) cout << " "; 
				else flag = true;
				cout << ans[i];
			} 
			cout << endl;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

 
