#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<int, vector<int> > goal;
int n;
vector<int> sou;  //��ѧ��ԭУ 
bool is_sucess(map<int, vector<int> > m);
int main(){
	while(cin >> n && n != 0){
		sou.clear();
		goal.clear();
		//��ѧ����Ϣ��ԭѧУ��ź�Ŀ��ѧУ
		for(int i = 0; i < n; i++) {
			int loc,tar;
			cin >> loc >> tar;
			sou.push_back(loc);
			
			goal[loc].push_back(tar);							//ԭУ����ѧ��ӳ����һ��vector������ 
				
		} 
		
		//ԭѧУ��Ϣȥ�� 
		sort(sou.begin(),sou.end());							//������ 
    	sou.erase(unique(sou.begin(), sou.end()), sou.end());	//ȥ���Ҹı�size()����֤�����ԭУ���ظ� 
    	/*
    	cout << sou.size() << endl;
    	for(int i = 0; i < sou.size(); i++) cout << sou[i] << " ";
    	cout << endl;
    	*/
    	
    	/*
    	//����erase����
		vector<int > a;
		a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
		a.push_back(4); a.push_back(3); a.push_back(2); a.push_back(1);
		vector<int>::iterator result = find(a.begin(), a.end(), 4);
		a.erase(result);
		cout << a.size() << endl;
		for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
		cout << endl;
		result = find(a.begin(), a.end(), 4);
		a.erase(result);
		cout << a.size() << endl;
		for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
		cout << endl;
		*/
		
		
		if(is_sucess( goal)) cout << "YES" << endl;
		else cout << "NO" << endl;
		
		
		
	}
	
	
	return 0;
} 

bool is_sucess(map<int, vector<int> > m){
	for(int i = 0; i < sou.size(); i++) {
		int s = sou[i];
		//cout << s << endl;
		for(int j = 0; j < m[s].size(); j++){
			int g = m[s][j];
			//cout << g << endl;
			vector<int>::iterator result = find(m[g].begin(), m[g].end(), s);	//����Ŀ��ѧУ�Ƿ�����ȥԭУ��ѧ�� 
			if(result == m[g].end()) return false;
			else m[g].erase(result);											//����ɾ�� 
			
			
			
		}
		
	
	}
	 
	return true;
	
	
}
