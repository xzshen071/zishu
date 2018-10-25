//集合：set
#include<cstdio>
#include<iostream>
#include<set>
#include<sstream>
using namespace std;
//与vector定义类似 
set<string> dict;//string集合 

int main(){
	string s,buf;
	while(cin >> s){
		//把单词中不是字母的字符变成' ' 
		for(int i=0;i<s.length();i++){
			if(isalpha(s[i])) s[i]=tolower(s[i]);//tolower函数字母字符转换成小写
			else s[i]=' ';
		}
		//cout << s<< "\n";
		stringstream ss(s);
		while(ss >> buf){
			//cout << buf << "\n";//buf与修正后的s相同 
			dict.insert(buf);//插入set集合,set中的元素已从小到大排序（string是已定义类型，自定义类型也可以构造set，与sort类似） 
		} 
			
		
	} 
	//iterator为迭代器，是STL中的重要概念，类似与指针，和vector类似于数组用法类似。set<string>::iterator it=dict.begin()与int *p=begin类似。 
	for(set<string>::iterator it=dict.begin();it !=dict.end();++it)
		cout << *it << "\n";
		return 0;
	
} 
