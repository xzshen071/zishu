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
		//set<int> all_pri;		//�������Ԫ�ص����ȼ�����С����
		vector<int> all_pri;	//set���ܰ����ظ�Ԫ�� ,ֻ����vector�� 
		int n, pos;
		cin >> n >> pos;
		for(int i = 0; i < n; i++){
			int pri;
			cin >> pri;
			//all_pri.insert(pri);	//�����ȼ�����set���� 
			
			all_pri.push_back(pri); //�����ȼ�����vector 
			q.push(pri); 			//�����ȼ�������� 
			
		}
		/*
		set<int>:: iterator it;
		for(it = all_pri.begin(); it != all_pri.end(); it++) cout << *it << " ";
		cout << endl;
		*/
		
		sort(all_pri.begin(),all_pri.end());	//��all_pri���Ԫ�ؽ�������
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
			//�ж϶������Ƿ���ڱȶ���ͷ���ȼ����Ԫ��
			//vector<int>:: iterator it = all_pri.end();	//*it���Ԫ���Ǹ��ֵܹ�������Ϊ��vector����ָ��������һ��Ԫ�ص���һ��Ԫ�أ�����set�в�ͬ 
			int end_pos = all_pri.size() -1;
			int max_pri = all_pri[ end_pos];
			//cout << q.front()<< " " << max_pri << " " << pos <<endl;	
			if(q.front() < max_pri){	//�����д������ȼ��ȶ�ͷ���Ԫ�� 
				q.push(q.front());	
				q.pop();
				pos = ( pos + q.size() -1) % q.size();	//Ŀ���λ�ñ仯 
				
				//cout << "1" <<endl;
				
			}else if(pos == 0){		//Ŀ���ڶ�ͷ 
				time++;
				
				//cout << "2" <<endl;
				break; 
				
			}else{					//Ŀ�겻�ڶ�ͷ
				time++;
				//pos = ( pos + q.size() -1) % q.size();	//Ŀ���λ�ñ仯 
				pos--;
				q.pop();
				
				//cout << "4" <<endl;
				//all_pri.erase( all_pri.end());	//ɾ��all_pri��������ȼ���ĩβ������������⣨��Ϊall_pri.end()ָ��������һ��Ԫ�ص���һ��Ԫ�ص�ָ�룩 
				//all_pri.erase( all_pri.end() -1);	//����д����ɾ�����һ��Ԫ�� 
			
				all_pri.pop_back();
				
				//cout << "3" <<endl;
				
				
			}
			
			
			
		}
		cout << time << endl; 
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
