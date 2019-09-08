/* 
//ָ��ʵ��
#include<cstdio> 
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100000 + 5;
char s[maxn];
int failed;			//�ж������Ƿ��д��󣬰�����һ��������������ϵĸ�ֵ��������Щ���û�и�ֵ	

struct Node {
	bool have_value;							//�Ƿ񱻸�ֵ��
	int v;										//���ֵ
	Node *L, *R;		
	Node():have_value(false), L(NULL), R(NULL) { }	//���캯���������ʼ�������еı��� 
};
Node *root;										//����������� 

//����ռ䡣�����г�ʼ�� 
Node* newnode() {return new Node(); }			//���徲̬���ڴ�ռ�(ȷ����С)���ڴ��Ǵ����ջ�У�����ִ������Զ����٣����嶯̬���ڴ�ռ䣨��ȷ����С����Ҫ����ʵ��ȷ�������ڴ���ڶ��У���Ҫ�����ͷ�
//������
void addnode(int v, char *s) {
	int n = strlen(s);
	Node *u = root;								//�Ӹ���������� 
	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') {
			if(u->L == NULL) u->L = newnode();	//û���򴴽���� 
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
//������ 
bool read_input() {
	failed = false;
	root = newnode();							//��ʼ������� 
	for(;;) {
		if(scanf("%s", s) != 1) return false;	//û��������
		if(!strcmp(s, "()")) break;				//һ�����������������
		int v;
		//sscanf(&s[1], "%d", &v);				//���������������������
		sscanf(s+1, "%d", &v);
		addnode(v, strchr(s, ',')+1);			//strchr�ҵ�s��','��λ�ã�ָ�룩��+1���Ӧ�������ĸ����Щ��ĸ��Ӧ��������е�λ��	 
	} 
	return true; 
}
//�����������ϵ��£������ң� 
bool bfs(vector<int>& ans) {
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()) {
		Node* u = q.front(); q.pop();
		if(!u->have_value) return false;		//���н��û��ֵ
		ans.push_back(u->v);
		if(u->L != NULL) q.push(u->L); 
		if(u->R != NULL) q.push(u->R); 
	} 
	return true;
} 
//�ͷſռ�
void remove_tree(Node* u) {
	if(u == NULL) return;
	remove_tree(u->L);
	remove_tree(u->R);
	delete u;									//��new��Ӧ��delete�ͷ�ͨ��new����Ŀռ� 
} 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(read_input()) {
		//������������洢��ans�� 
		vector<int> ans;
		if(failed || !bfs(ans)) {
			cout << "not complete" << endl; 
		}else {									//��ӡ������� 
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
//����ʵ�֣�������������ʵ�ֶ���������Ϊ���ɰ���256����㣬���ٵ������С�����ɹ��������ǲ���ָ�룬������Ҳ���ý����ڴ��ͷţ�
#include<cstdio> 
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxc = 100000 + 5;					//��������ַ����� 
const int maxn = 256 + 5;						//���ڵ���					
char s[maxc];
bool failed;									//�ж������Ƿ��д��󣬰�����һ��������������ϵĸ�ֵ��������Щ���û�и�ֵ	

const int root = 1;							    //����������� 
int cnt;										//���� 
int L[maxn], R[maxn], value[maxn];			        //�����������������ı�źͱ�Ŷ�Ӧ��ֵ
bool have_value[maxn];							//��Ŷ�Ӧ�Ƿ����ֵ 

//��ʼ����� 
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
			
//������
void addnode(int v, char *s) {
	int n = strlen(s);
	int u = root;								//�Ӹ���������� 
	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') {
			if(L[u] == 0) L[u] = newnode();	//û���򴴽���� 
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
//������ 
bool read_input() {
	failed = false;
	newtree();									//��ʼ������� 
	for(;;) {
		if(scanf("%s", s) != 1) return false;	//û��������
		if(!strcmp(s, "()")) break;				//һ�����������������
		int v;
		//sscanf(&s[1], "%d", &v);				//���������������������
		sscanf(s+1, "%d", &v);
		addnode(v, strchr(s, ',')+1);			//strchr�ҵ�s��','��λ�ã�ָ�룩��+1���Ӧ�������ĸ����Щ��ĸ��Ӧ��������е�λ��	 
	} 
	return true; 
}
//�����������ϵ��£������ң� 
bool bfs(vector<int>& ans) {
	queue<int> q;
	ans.clear();
	q.push(root);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(!have_value[u]) return false;		//���н��û��ֵ
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
		//������������洢��ans�� 
		vector<int> ans;
		if(failed || !bfs(ans)) {
			cout << "not complete" << endl; 
		}else {									//��ӡ������� 
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

 
