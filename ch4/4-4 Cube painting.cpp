//��ͨ����ת��ÿ��������Ӷ����ڶ���һ�Σ�ѡ�ö��˺�׶�Ҳȷ���ˣ�ͨ����ת4���ж��Ƿ��к�����һ�����ӳ�����ͬ�����
#include<iostream>
#include<cstring>
using namespace std;

//��ʼ������0~5(��Ϊ����0~5��λ�ô�ģ����Ա�ʾΪ��ʼλ��)����ͨ����ת�����ˣ�Ҳ������������ֻҪ��֤����ת�����ľ��У���Ϊȷ���˶��˻���Ҫ����4����ת�����������
int dir[6][6] = { {0,1,2,3,4,5}, {1,5,2,3,0,4}, {2,1,5,0,4,3}, {3,1,0,5,4,2}, {4,0,2,3,5,1}, {5,4,2,3,1,0} }; 	//��ά���鸳ֵ 
char s[20], s1[10], s2[10];	//s1������1��s2������2
char tmp[10];				//tmp������任�Ľ�� 

//�ж��Ƿ������ͬ��� 
int is_some();
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
		
	while(cin >> s) {
		//cout << s << endl;
		//��2��������Ϣ���ٽ���Ϣ�ֿ��� 
		for(int i = 0; i < 6; i++) s1[i] = s[i];
		for(int i = 6; i < 12; i++) s2[i - 6] = s[i];
		//cout << s1 << " " << s2 << endl; 
		
		if(is_some()) cout << "TRUE" << endl;
		else cout << "FALSE" << endl;	
	}
	return 0;
} 
int is_some() {
	//��6�ֶ���������з��� 
	for(int i = 0; i < 6; i++) { 
		//dir[i]��ʾ6�ֶ������ 
		for(int j = 0; j < 6; j++) 
			tmp[j] = s2[dir[i][j]];
		//���˺͵׶˲��䣬��ת4�� 
		for(int j = 0; j < 4; j++) {
			char tmp_c;
			tmp_c = tmp[1];		//��¼�õڶ���λ�õ�����
			//��ʼ��ת
			tmp[1] = tmp[2];
			tmp[2] = tmp[4];
			tmp[4] = tmp[3];
			tmp[3] = tmp_c;
			//��ת���ж��Ƿ���s1��� 
			if(strcmp(tmp, s1) == 0) return 1;
		} 	
	}
	return 0;
	
}
