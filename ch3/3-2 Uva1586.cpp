#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<cctype>
#include<sstream>
using namespace std;

const int maxn = 80 + 5;

char atom[maxn];				//ԭ������ 
int num[maxn];					//��Ӧ��ԭ������ 
map<char, double> atom_w;		//ԭ��ӳ��ԭ������ 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//ԭ��ӳ��ԭ����
	atom_w['C'] = 12.01;
	atom_w['H'] = 1.008;
	atom_w['O'] = 16.00;
	atom_w['N'] = 14.01;
	
	//����ԭ�����ƺ͸������ֿ��棩
	int n;
	while(cin >> n) {
		while(n--) {	
			memset(atom, 0, sizeof(atom));				//��ʼ��ԭ������ 
			for(int i = 0; i < maxn; i++) num[i] = 1;	//��ʼ��ԭ������ 
			string tmp;
			cin >> tmp;
			//cout << tmp << endl;	
		 
			int pos = 0;							//������ʾ�洢��ԭ�����Ƶ�λ�� 
			for(int i = 0; i < tmp.size(); i++) {
				if(isalpha(tmp[i])) {				//����ĸ 
					atom[pos] = tmp[i];
					pos++; 
					tmp[i] = ' '; 					//�����λ�ñ�Ϊ�ո񣬷������ֵĶ�ȡ 
				}else {
					if(pos > 0) num[pos - 1] = 0;	//����ǣ�˵�����λ�ö�Ӧ��ԭ�������г�����Ŀ1������ 
				} 
			}
			//cout << tmp << endl;
			
			//cout << pos << endl;
			//�������Ŀ1��ԭ�Ӹ���������Ĭ��Ϊ1 
			stringstream ss(tmp);
			for(int i = 0; i < pos; i++) {
				if(num[i] == 0) {
					ss >> num[i];
				}
			}
			//for(int i = 0; i < pos; i++) cout << num[i] << " ";
			//cout << endl; 
			
			//���������
			double sum = 0.0; 
			for(int i = 0; i < pos; i++) {
				sum += (atom_w[atom[i]] * num[i]);
				//cout << (atom_w[atom[i]] * num[i]) << " ";
			}
			//cout << endl;
			printf("%.3f\n", sum); 	
		}		
	} 
	
	return 0;
} 
