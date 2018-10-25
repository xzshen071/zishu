//输入数据的每行包含若干个（至少一个）以空格隔开的整数，输出每行中所有整数之和
#include<iostream>
//string类在string头文件中 
#include<string>
//stringstream在sstream头文件中 
#include<sstream>
using namespace std;
int main(){
	//不需要定义字符串的最大长度 
	string line;
	//getline函数读一行数据，相当于fgets(a,maxn,fin)，但由于是string类，无须指定字符串最大长度 
	while(getline(cin,line)){
		int sum=0,x;
		//创建字符串流，即可想读取cin那样读取ss 
		stringstream ss(line);
		while(ss>>x)
			sum+=x;
		cout<<sum<<"\n";
		
	}	
	//getline(cin,line);
	//cout << line << "\n"; 
	
	return 0;
} 
//可以把string作为流进行读写，定义在sstream头文件中。
//虽然string和sstream都很方便，但是string很慢，sstream更慢，谨慎使用。 
