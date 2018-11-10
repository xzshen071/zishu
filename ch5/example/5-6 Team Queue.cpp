//�����������У�һ�����д�ÿ���Ŷ�����Ĵ������һ�����д�ĳ���Ŷ���Ĵ���
#include<iostream>
#include<map>
#include<queue>
#include<string> 
using namespace std;
const int maxn=1000+10;
map<int,int> team;

int main(){
	//���������
	int t,kase=0,x;
	while(scanf("%d",&t)==1 && t!=0){
		printf("Sample Output\nScenario #%d\n",++kase);
		for(int i=0;i<t;i++){
			//����������������mapӳ�������
			int n;
			scanf("%d",&n);
			while(n--){
				scanf("%d",&x);//����Ա���
				team[x]=i;
				
			} 
			
		}
		 
	} 
	
	//ģ�����
	queue<int> q,q2[maxn];//�����������У�q���ŶӵĶ��У�q2[i]���Ŷ�i��Ա���� 
	while(1){
		string s; 
		cin >> s;//������
		if(s[0]=='S') break;
		else if(s[0]=='E'){
			scanf("%d",&x); //�����˱��
			int i=team[x];
			if(q2[i].empty()) q.push(i);//�Ŷ�t������� 
			q2[i].push(x);//�����ŶӶ����� 
			
		}else if(s[0]=='D'){
			int i=q.front();
			printf("%d\n",q2[i].front()); q2[i].pop();
			if(q2[i].empty()) q.pop();//����tȫ����� 
			
			
			
		}
		
	} 
	 
	
	
	
	return 0;
} 
/*
1��STL��queueͷ�ļ����ṩ�����ȶ��У��á�priority_queue<int> s����ʽ����: 
2����push()��pop()����Ԫ�ص���Ӻͳ��Ӳ�����top()ȡ����Ԫ�أ�����ɾ������ 
3�����ȶ����Ǹ������ȼ��Ĵ�С���ӵ�
4������
   ԽС���������ȼ�Խ�͵Ķ��У����壩��priority_queue<int> pq����Ĭ�ϣ� 
   ԽС�������ȼ�Խ������ȶ��У������ģ���priority_queue<int,vector<int>,greater<int> >pq��ע���������>>Ҫ�м�϶����ϵͳ����Ϊ���������������
   �Զ�������������ȶ��У�ǰ���Ǳ���Ϊÿ��Ԫ�ض���һ�����ȼ���ֻ��Ҫ�ܱȽϴ�С���ɣ���sort��set�����ƣ�
		eg:����λ������������ȼ�����С�������ȶ���
		��1���ȶ���һ���ṹ��cmp�����ء�()���������ʹ�䡰����ȥ����һ��������
		��2��Ȼ����"priority_queue<int,vector<int>,cmp> pq"
		cmp�Ķ��壺
			struct cmp{
				bool operator() (const int a,const int b) const {//a�����ȼ���bСʱ����true 
					
					return a % 10 > b % 10;
				
				}
			
			
			};		 



*/
