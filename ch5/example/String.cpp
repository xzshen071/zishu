//�������ݵ�ÿ�а������ɸ�������һ�����Կո���������������ÿ������������֮��
#include<iostream>
//string����stringͷ�ļ��� 
#include<string>
//stringstream��sstreamͷ�ļ��� 
#include<sstream>
using namespace std;
int main(){
	//����Ҫ�����ַ�������󳤶� 
	string line;
	//getline������һ�����ݣ��൱��fgets(a,maxn,fin)����������string�࣬����ָ���ַ�����󳤶� 
	while(getline(cin,line)){
		int sum=0,x;
		//�����ַ��������������ȡcin������ȡss 
		stringstream ss(line);
		while(ss>>x)
			sum+=x;
		cout<<sum<<"\n";
		
	}	
	//getline(cin,line);
	//cout << line << "\n"; 
	
	return 0;
} 
//���԰�string��Ϊ�����ж�д��������sstreamͷ�ļ��С�
//��Ȼstring��sstream���ܷ��㣬����string������sstream����������ʹ�á� 
