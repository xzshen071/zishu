//���ϣ�set
#include<cstdio>
#include<iostream>
#include<set>
#include<sstream>
using namespace std;
//��vector�������� 
set<string> dict;//string���� 

int main(){
	string s,buf;
	while(cin >> s){
		//�ѵ����в�����ĸ���ַ����' ' 
		for(int i=0;i<s.length();i++){
			if(isalpha(s[i])) s[i]=tolower(s[i]);//tolower������ĸ�ַ�ת����Сд
			else s[i]=' ';
		}
		//cout << s<< "\n";
		stringstream ss(s);
		while(ss >> buf){
			//cout << buf << "\n";//buf���������s��ͬ 
			dict.insert(buf);//����set����,set�е�Ԫ���Ѵ�С��������string���Ѷ������ͣ��Զ�������Ҳ���Թ���set����sort���ƣ� 
		} 
			
		
	} 
	//iteratorΪ����������STL�е���Ҫ���������ָ�룬��vector�����������÷����ơ�set<string>::iterator it=dict.begin()��int *p=begin���ơ� 
	for(set<string>::iterator it=dict.begin();it !=dict.end();++it)
		cout << *it << "\n";
		return 0;
	
} 
