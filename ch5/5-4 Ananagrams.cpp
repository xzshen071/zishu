//映射：map 
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
		//存原来的单词
		words.push_back(s);
		//对原来的单词进行处理：全部变成小写，且按从小到大顺序排列
		string r =repr(s);
		//存入map中，记录格式相同单词的个数 
		if(!cnt.count(r)) cnt[r]=0;//cnt.count(r)->知道个数 
		cnt[r]++; 	
		
	} 
	//将单词格式只出现一次的单词存储
	
	vector<string> ans; 
	for(int i=0;i<words.size();i++){
		if(cnt[repr(words[i])]==1) ans.push_back(words[i]);

	} 
	//按照字典序排序，sort即可
	sort(ans.begin(),ans.end());
	//打印ans
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << "\n";
	/*
	//用set
	set<string> ans; 
	for(int i=0;i<words.size();i++){
		if(cnt[repr(words[i])]==1) ans.insert(words[i]);

	}
	//iterator为迭代器，是STL中的重要概念，类似与指针，和vector类似于数组用法类似。set<string>::iterator it=dict.begin()与int *p=begin类似。 
	for(set<string>::iterator it=ans.begin();it !=ans.end();++it)
		cout << *it << "\n";	
	*/
	return 0;
}
//将单词s进行“标准化” 
string repr(string s){
	/*
	string ans=s;
	//变成小写
	for(int i=0;i<ans.length();i++) 
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
	*/
	
	//变成小写
	for(int i=0;i<s.length();i++) 
		s[i]=tolower(s[i]);
	sort(s.begin(),s.end());
	return s;
	
}
/*
1、set和map分别是集合与映射。两者都支持insert、find、count和remove操作，并且可以按照从小到大的顺序循环遍历其中的元素； 
2、map还提供了“[]”运算符，使得map可以像数组一样使用。实际上map也被称为关联数组。（set没有）
 

*/ 
