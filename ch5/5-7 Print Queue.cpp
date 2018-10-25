#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
 

int main(){
	int t;
	cin >> t;
	while(t--){
		queue<int> q;
		//set<int> all_pri;		//存队列中元素的优先级（从小到大）
		vector<int> all_pri;	//set不能包含重复元素 ,只能用vector了 
		int n, pos;
		cin >> n >> pos;
		for(int i = 0; i < n; i++){
			int pri;
			cin >> pri;
			//all_pri.insert(pri);	//将优先级存入set容器 
			
			all_pri.push_back(pri); //将优先级存入vector 
			q.push(pri); 			//将优先级存入队列 
			
		}
		/*
		set<int>:: iterator it;
		for(it = all_pri.begin(); it != all_pri.end(); it++) cout << *it << " ";
		cout << endl;
		*/
		
		sort(all_pri.begin(),all_pri.end());	//对all_pri里的元素进行排序
		/* 
		for(int i = 0; i < n; i++){
			cout << all_pri[i] << " "; 
		}
		cout << endl;
		for(int i = 0; i < n; i++){
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
		*/
	
		
		int time = 0; 
		while(1){
			//判断队列中是否存在比队列头优先级大的元素
			//vector<int>:: iterator it = all_pri.end();	//*it里的元素是个很怪的数，因为在vector中它指向的是最后一个元素的下一个元素，而在set中不同 
			int end_pos = all_pri.size() -1;
			int max_pri = all_pri[ end_pos];
			//cout << q.front()<< " " << max_pri << " " << pos <<endl;	
			if(q.front() < max_pri){	//队列中存在优先级比队头大的元素 
				q.push(q.front());	
				q.pop();
				pos = ( pos + q.size() -1) % q.size();	//目标的位置变化 
				
				//cout << "1" <<endl;
				
			}else if(pos == 0){		//目标在队头 
				time++;
				
				//cout << "2" <<endl;
				break; 
				
			}else{					//目标不在队头
				time++;
				//pos = ( pos + q.size() -1) % q.size();	//目标的位置变化 
				pos--;
				q.pop();
				
				//cout << "4" <<endl;
				//all_pri.erase( all_pri.end());	//删除all_pri的最大优先级（末尾），会出现问题（因为all_pri.end()指向的是最后一个元素的下一个元素的指针） 
				//all_pri.erase( all_pri.end() -1);	//这样写才能删除最后一个元素 
			
				all_pri.pop_back();
				
				//cout << "3" <<endl;
				
				
			}
			
			
			
		}
		cout << time << endl; 
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
