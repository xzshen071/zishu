#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<int> l_w_h;						//运用set容器的去重的功能 
vector<int> rect;			 		//存矩形数据 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	while(cin >> a >> b) {
		int same_n = 0;				//存元素相同的二元组个数 
		rect.clear();
		l_w_h.clear(); 
		
		//对第一组数据处理 
		if(a == b) same_n++;
		rect.push_back(a); rect.push_back(b);
		l_w_h.insert(a); l_w_h.insert(b);
		//对后5组数据进行相同的处理 
		for(int i = 0; i < 5; i++) {
			cin >> a >> b;
			if(a == b) same_n++;
			rect.push_back(a); rect.push_back(b);
			l_w_h.insert(a); l_w_h.insert(b);
		}
		
		
		//输出 
		if(l_w_h.size() == 1) {							//正方形，只存在一种元素 
			//cout << "1" << endl;
			cout << "POSSIBLE" << endl;
		}else if(l_w_h.size() == 2 && same_n == 2) {	//存在两种元素且元素相同的二元组有且只有2个 
			//cout << "2" << endl;
			cout << "POSSIBLE" << endl;
		}else if(l_w_h.size() == 3 && same_n == 0) {	//存在三种元素且没有元素相同的二元组 
			//cout << "3" << endl;
			set<int>::iterator it = l_w_h.begin();
			int l = *it; it++;
			int w = *it; it++;
			int h = *it;
			//cout << l << " " << w << " " << h << endl; 
			
			//得到l、w、h出现的次数 
			int num_l, num_w, num_h;
			num_l = num_w = num_h = 0;
			for(int i = 0; i < rect.size(); i++) {
				if(rect[i] == l) num_l++;
				else if(rect[i] == w) num_w++;
				else if(rect[i] == h) num_h++;
			}
			//cout << num_l << " " << num_w << " " << num_h << endl;
			if(num_l == 4 && num_w == 4 && num_h == 4) cout << "POSSIBLE" << endl;
			else cout << "IMPOSSIBLE" << endl;
			
		}else {
			//cout << "4" << endl;
			cout << "IMPOSSIBLE" << endl;
		} 
	}
	
	return 0;
} 
