//ӳ�䣺map 
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

#include<set>
using namespace std;

string repr(string s);
map<string,int> cnt; 
vector<string> words; 
int main(){
	string s;
	while(cin >> s){
		if(s[0]=='#') break;
		//��ԭ���ĵ���
		words.push_back(s);
		//��ԭ���ĵ��ʽ��д���ȫ�����Сд���Ұ���С����˳������
		string r =repr(s);
		//����map�У���¼��ʽ��ͬ���ʵĸ��� 
		if(!cnt.count(r)) cnt[r]=0;//cnt.count(r)->֪������ 
		cnt[r]++; 	
		
	} 
	//�����ʸ�ʽֻ����һ�εĵ��ʴ洢
	
	vector<string> ans; 
	for(int i=0;i<words.size();i++){
		if(cnt[repr(words[i])]==1) ans.push_back(words[i]);

	} 
	//�����ֵ�������sort����
	sort(ans.begin(),ans.end());
	//��ӡans
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << "\n";
	/*
	//��set
	set<string> ans; 
	for(int i=0;i<words.size();i++){
		if(cnt[repr(words[i])]==1) ans.insert(words[i]);

	}
	//iteratorΪ����������STL�е���Ҫ���������ָ�룬��vector�����������÷����ơ�set<string>::iterator it=dict.begin()��int *p=begin���ơ� 
	for(set<string>::iterator it=ans.begin();it !=ans.end();++it)
		cout << *it << "\n";	
	*/
	return 0;
}
//������s���С���׼���� 
string repr(string s){
	/*
	string ans=s;
	//���Сд
	for(int i=0;i<ans.length();i++) 
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
	*/
	
	//���Сд
	for(int i=0;i<s.length();i++) 
		s[i]=tolower(s[i]);
	sort(s.begin(),s.end());
	return s;
	
}
/*
1��set��map�ֱ��Ǽ�����ӳ�䡣���߶�֧��insert��find��count��remove���������ҿ��԰��մ�С�����˳��ѭ���������е�Ԫ�أ� 
2��map���ṩ�ˡ�[]���������ʹ��map����������һ��ʹ�á�ʵ����mapҲ����Ϊ�������顣��setû�У�
 

*/ 
