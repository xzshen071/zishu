#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn=30;
int n;
vector<int> pile[maxn];
void find_wood(int a,int &p,int &h);//用引用的方式改变输入的参数的值 
void clear_above(int p,int h);
void pile_onto(int p,int h,int p1);
void printf();
int main(){
	cin >> n;
	int a,b;
	string s1,s2;
	//初始化 
	for(int i=0;i<n;i++) 
		pile[i].push_back(i);//插入尾部 
	while(cin >> s1 >> a >> s2 >> b){
		int pa,ha,pb,hb; 
		//找到编号a与b木块的位置,并返回 
		find_wood(a,pa,ha);		 
		find_wood(b,pb,hb);
		if(pa==pb) continue;//非法指令
		//归位 
		if(s1=="move") clear_above(pa,ha);
		if(s2=="onto") clear_above(pa,hb); 
		//把a以上的木块放到b上
		pile_onto(pa,ha,pb); 
		
	}
	//打印每个vector的内容
	printf();
	return 0;	
	
} 
//找到木块a所在的位置，并记录 
void find_wood(int a,int &p,int &h){
	for(p=0;p<n;p++){
		for(h=0;h<pile[p].size();h++){
			if(pile[p][h]==a) return;
			
		}
	}
	
	
} 
//将此位置以上的木块全部归位 
void clear_above(int p,int h){
	for(int i=h+1;i<pile[p].size();i++){
		int b=pile[p][i];
		pile[b].push_back(b);
		
	} 
	//更新此位置堆的大小
	pile[p].resize(h+1);//0~h 
	
}
//将p，h位置即以上的木块放在p1上 
void pile_onto(int p,int h,int p1){
	for(int i=h;i<pile[p].size();i++){
		pile[p1].push_back(pile[p][i]);
	} 
	//更新p堆
	pile[p].resize(h);//0~h-1 
	
	
}
//打印每堆的情况 
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
1、vector是一个不定长的数组； 
2、eg:vector<int> a，<>中定义类型。还可以定义一个二维数组，eg:vector<int> a[num]，一维固定，二维不固定； 
操作：a.size:读取大小；a.resize():改变大小；a.push_back():向尾部添加元素；a.pop.back():删除最后一个元素；a.clear():清空；a.empty:测试是否为空；
	  vector之间可以直接赋值，或者作为函数的返回值； 
3、写代码时最好找到指令之间的共同点，减少重复代码 


*/
