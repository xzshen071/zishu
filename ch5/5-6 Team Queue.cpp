//构造两个队列，一个队列存每个团队整体的次序，另个一个队列存某个团队里的次序
#include<iostream>
#include<map>
#include<queue>
#include<string> 
using namespace std;
const int maxn=1000+10;
map<int,int> team;

int main(){
	//读队伍个数
	int t,kase=0,x;
	while(scanf("%d",&t)==1 && t!=0){
		printf("Sample Output\nScenario #%d\n",++kase);
		for(int i=0;i<t;i++){
			//读队伍人数，且用map映射队伍编号
			int n;
			scanf("%d",&n);
			while(n--){
				scanf("%d",&x);//读队员编号
				team[x]=i;
				
			} 
			
		}
		 
	} 
	
	//模拟操作
	queue<int> q,q2[maxn];//建立两个队列，q是团队的队列，q2[i]是团队i成员队列 
	while(1){
		string s; 
		cin >> s;//读操作
		if(s[0]=='S') break;
		else if(s[0]=='E'){
			scanf("%d",&x); //读此人编号
			int i=team[x];
			if(q2[i].empty()) q.push(i);//团队t进入队列 
			q2[i].push(x);//进入团队队列中 
			
		}else if(s[0]=='D'){
			int i=q.front();
			printf("%d\n",q2[i].front()); q2[i].pop();
			if(q2[i].empty()) q.pop();//团体t全体出列 
			
			
			
		}
		
	} 
	 
	
	
	
	return 0;
} 
/*
1、STL中queue头文件还提供了优先队列，用“priority_queue<int> s”方式定义: 
2、用push()和pop()进行元素的入队和出队操作，top()取队首元素（但不删除）； 
3、优先队列是根据优先级的大小出队的
4、例子
   越小的整数优先级越低的队列（定义）：priority_queue<int> pq；（默认） 
   越小整数优先级越大的优先队列（常见的）：priority_queue<int,vector<int>,greater<int> >pq（注意最后两个>>要有间隙，怕系统误以为是左移运算符）；
   自定义类型组成优先队列，前提是必须为每个元素定义一个优先级，只需要能比较大小即可，与sort、set等类似：
		eg:“个位数大的整数优先级反而小”的优先队列
		（1）先定义一个结构体cmp，重载“()”运算符，使其“看上去”像一个函数。
		（2）然后用"priority_queue<int,vector<int>,cmp> pq"
		cmp的定义：
			struct cmp{
				bool operator() (const int a,const int b) const {//a的优先级比b小时返回true 
					
					return a % 10 > b % 10;
				
				}
			
			
			};		 



*/
