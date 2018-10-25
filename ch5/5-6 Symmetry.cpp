#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//vector<int > all_y;				//存所有的y值 
set<int > all_y; 					//用容器set可以去重排序 
map<int, vector<int> > point;	//存y映射的x 

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	while( t--){
		int n;
		cin >> n;
		all_y.clear();
		point.clear(); 
		while( n--){
			int x, y;
			cin >> x >> y;
			//all_y.push_back(y);
			all_y.insert(y);
			point[y].push_back(x);
		
		}
		
		//cout << all_y.size() << endl;
		//sort(all_y.begin(), all_y.end());																	//去重前先排序 
		//all_y.erase(unique(all_y.begin(), all_y.end()), all_y.end());										//对all_y去重
		//for(int i = 0; i < all_y.size(); i++)	sort(point[ all_y[i]].begin(), point[ all_y[i]].end());		//对point[y]里的元素进行排序 
		set<int>:: iterator it;
		for( it = all_y.begin(); it != all_y.end(); it++) sort(point[ *it].begin(), point[ *it].end());
		
		/* 
		//cout << all_y.size() << endl;
		for( int i = 0; i < all_y.size(); i++)	cout << all_y[i] << " ";
		cout << endl;
		  
		for(int i = 0; i < all_y.size(); i++){
			int lens = point[all_y[i]].size();
			//cout << lens << endl;
			for(int j =0; j < lens; j++){
				cout <<  point[all_y[i]][j] << " ";
			} 
			cout << endl;
		} 
		 */ 
		
		it = all_y.begin();
		int pos = point[ *it].size() - 1;
		//cout << pos << " ";
		//double axis_x = (point[ all_y[0]][0] + point[ all_y[0]][pos] ) / 2.0;								//获得对称参照轴的x坐标
		double axis_x = (point[ *it][0] + point[ *it][pos] ) / 2.0;	
		//cout << axis_x << endl;
		
		
		/*
		pos = point[ all_y[1]].size() - 1;
		cout << pos << " ";
		axis_x = (point[ all_y[1]][0] + point[ all_y[1]][pos] ) / 2.0;
		cout << axis_x << endl;
		*/
		
		/*
		//判断是否存在对称轴
		int flag = 1;
		for(int i = 0; i < all_y.size(); i++){
			int lens = point[all_y[i]].size();
			for(int j =0; j < lens; j++){
				double mid_x = (point[all_y[i]][j] + point[all_y[i]][lens - 1 - j]) / 2.0;
				if(mid_x != axis_x){
					flag = 0;
					//cout << "1" << endl;
					cout << "NO" << endl;
					break;
				}
			
				
			}
			if(flag == 0) break;
			
		} 
		if(flag) cout << "YES" << endl;
		*/
		
		int flag = 1;
		for( it = all_y.begin(); it != all_y.end(); it++){
			int lens = point[ *it].size();
			for(int j =0; j < lens; j++){
				double mid_x = (point[ *it][j] + point[ *it][lens - 1 - j]) / 2.0;
				if(mid_x != axis_x){
					flag = 0;
					//cout << "1" << endl;
					cout << "NO" << endl;
					break;
				}
			
				
			}
			if(flag == 0) break;
			
		} 
		if(flag) cout << "YES" << endl;
		
		
	
	}
	
	
	
	
	return 0;
} 
