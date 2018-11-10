#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn=30;
int n;
vector<int> pile[maxn];
void find_wood(int a,int &p,int &h);//�����õķ�ʽ�ı�����Ĳ�����ֵ 
void clear_above(int p,int h);
void pile_onto(int p,int h,int p1);
void printf();
int main(){
	cin >> n;
	int a,b;
	string s1,s2;
	//��ʼ�� 
	for(int i=0;i<n;i++) 
		pile[i].push_back(i);//����β�� 
	while(cin >> s1 >> a >> s2 >> b){
		int pa,ha,pb,hb; 
		//�ҵ����a��bľ���λ��,������ 
		find_wood(a,pa,ha);		 
		find_wood(b,pb,hb);
		if(pa==pb) continue;//�Ƿ�ָ��
		//��λ 
		if(s1=="move") clear_above(pa,ha);
		if(s2=="onto") clear_above(pa,hb); 
		//��a���ϵ�ľ��ŵ�b��
		pile_onto(pa,ha,pb); 
		
	}
	//��ӡÿ��vector������
	printf();
	return 0;	
	
} 
//�ҵ�ľ��a���ڵ�λ�ã�����¼ 
void find_wood(int a,int &p,int &h){
	for(p=0;p<n;p++){
		for(h=0;h<pile[p].size();h++){
			if(pile[p][h]==a) return;
			
		}
	}
	
	
} 
//����λ�����ϵ�ľ��ȫ����λ 
void clear_above(int p,int h){
	for(int i=h+1;i<pile[p].size();i++){
		int b=pile[p][i];
		pile[b].push_back(b);
		
	} 
	//���´�λ�öѵĴ�С
	pile[p].resize(h+1);//0~h 
	
}
//��p��hλ�ü����ϵ�ľ�����p1�� 
void pile_onto(int p,int h,int p1){
	for(int i=h;i<pile[p].size();i++){
		pile[p1].push_back(pile[p][i]);
	} 
	//����p��
	pile[p].resize(h);//0~h-1 
	
	
}
//��ӡÿ�ѵ���� 
void printf(){
	for(int i=0;i<n;i++){
		//printf("%d:",i);
		cout << i <<":";
		for(int j=0;j<pile[i].size();j++){
			cout << " " << pile[i][j];
		}
		cout << "\n";
	} 
}
/*
1��vector��һ�������������飻 
2��eg:vector<int> a��<>�ж������͡������Զ���һ����ά���飬eg:vector<int> a[num]��һά�̶�����ά���̶��� 
������a.size:��ȡ��С��a.resize():�ı��С��a.push_back():��β�����Ԫ�أ�a.pop.back():ɾ�����һ��Ԫ�أ�a.clear():��գ�a.empty:�����Ƿ�Ϊ�գ�
	  vector֮�����ֱ�Ӹ�ֵ��������Ϊ�����ķ���ֵ�� 
3��д����ʱ����ҵ�ָ��֮��Ĺ�ͬ�㣬�����ظ����� 


*/
