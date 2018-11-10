#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<int> l_w_h;						//����set������ȥ�صĹ��� 
vector<int> rect;			 		//��������� 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	while(cin >> a >> b) {
		int same_n = 0;				//��Ԫ����ͬ�Ķ�Ԫ����� 
		rect.clear();
		l_w_h.clear(); 
		
		//�Ե�һ�����ݴ��� 
		if(a == b) same_n++;
		rect.push_back(a); rect.push_back(b);
		l_w_h.insert(a); l_w_h.insert(b);
		//�Ժ�5�����ݽ�����ͬ�Ĵ��� 
		for(int i = 0; i < 5; i++) {
			cin >> a >> b;
			if(a == b) same_n++;
			rect.push_back(a); rect.push_back(b);
			l_w_h.insert(a); l_w_h.insert(b);
		}
		
		
		//��� 
		if(l_w_h.size() == 1) {							//�����Σ�ֻ����һ��Ԫ�� 
			//cout << "1" << endl;
			cout << "POSSIBLE" << endl;
		}else if(l_w_h.size() == 2 && same_n == 2) {	//��������Ԫ����Ԫ����ͬ�Ķ�Ԫ������ֻ��2�� 
			//cout << "2" << endl;
			cout << "POSSIBLE" << endl;
		}else if(l_w_h.size() == 3 && same_n == 0) {	//��������Ԫ����û��Ԫ����ͬ�Ķ�Ԫ�� 
			//cout << "3" << endl;
			set<int>::iterator it = l_w_h.begin();
			int l = *it; it++;
			int w = *it; it++;
			int h = *it;
			//cout << l << " " << w << " " << h << endl; 
			
			//�õ�l��w��h���ֵĴ��� 
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
