#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

const int max_step= 1000;
vector<int> tmp_t;		//存临时元组
vector<int> tup[max_step];	//存所有元组	 
int num;				//所存元组的个数 
int n;
void ducci(vector<int> &v); 
bool is_zero(vector<int> v);
bool is_loop(vector<int> v);
int main(){
	int t;
	cin >> t;
	while(t--){
		//初始化 
		int flag = 1;
		num = 0;
		tmp_t.clear();
		for(int i = 0; i < max_step; i++)	tup[i].clear();
		
		cin >> n;
		//读入，当把读入放入循环时，注意位置，可能造成你想得到结果，却还要输入的情况 
		for(int i = 0; i < n; i++){
			int x;
			cin >> x; 
			tmp_t.push_back(x);
			tup[num].push_back(x);
			
		}
		/*
		for(int i = 0; i < n; i++){
			//cout << tmp_t[i] << " ";
				
		}
		cout << endl;
		*/		
		for(int step = 0; step < max_step; step++){
			ducci(tmp_t);	//元组进行操作，改变元组内的值，且将此元组加入元组数组中 
			
			/* 
			for(int i = 0; i < n; i++){
				cout << tmp_t[i] << " ";
				
			}
			cout << endl;

			for(int i = 0; i < n; i++){
				//cout << tmp_t[i] << " ";
				cout << tup[num][i] << " ";
				
			}
			cout << endl;
			*/
		
			if(is_zero(tmp_t)){ cout << "ZERO" << endl; flag = 0; break;}
			if(is_loop(tmp_t)){ cout << "LOOP" << endl; flag = 0; break;}
			
		}
		
		if(flag) cout << "False input" << endl;
		
	}

	return 0;
} 

void ducci(vector<int> &v){
	num++;
	vector<int> tmp;
	for(int i = 0; i < n; i++){
		tmp.push_back(v[i]);
	}
	
	for(int i = 0; i < n; i++){
		v[i] = abs(tmp[i]-tmp[(i+1)%n]);
		tup[num].push_back(v[i]);
		
	}
	
	return;
}

bool is_zero(vector<int> v){
	for(int i = 0; i < n; i++) {
		if(v[i] != 0)
			return false;
		
	}
	
	return true;
}
bool is_loop(vector<int> v){
	for(int i = 0; i < num; i++){
		if(v == tup[i])
			return true;
		
	}
	return false;
	
}
