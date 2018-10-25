#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=10+5;
map<string,int> IDcache;//������ӳ��ΪID 
map<long long,int> Rcache;//����Ԫ��ӳ��Ϊ�� 
vector<int> v[maxn];
int num;//���� 
int ID(string s);
long long combine(int x,int y);

int main(){
	//����������
	int cols,rows,flag;
	while(cin >> rows >> cols){
		num=0;flag=1;
		IDcache.clear();//��IDcache��� 
		//һ��һ�����룬����ӳ��Ϊ���
		for(int i=0;i<rows;i++){
			string line;
			if(flag){//�ѵ�һ������Ŀո���� 
				char c=getchar();
				flag=0;
			}
			getline(cin,line);
			//cout << line.size() << "\n";
			
			//��' '�����'.'����','��ɡ� ��
			for(int j=0;j<line.size();j++){
				if(line[j]==' ')
					line[j]='-';
				else if(line[j]==',')
					line[j]=' ';				
				
			} 
			//cout << line << "\n";
			
			//���д��ַ��� 
			stringstream ss(line);
			string s;
			for(int j=0;j<cols;j++){
				ss >> s;
				//cout << s << "\n";
				
				//�����ϱ�� 
				if(IDcache.count(s)==0){
					IDcache[s]=num;
					num++;					
				} 
				//����ַ���
				v[j].push_back(IDcache[s]);
				
			}
				 
		}
		
		for(int i=0;i<cols;i++){
			for(int j=0;j<rows;j++){
				cout << v[i][j] << " ";
				
			}
			cout << "\n";
		} 
		
		int flag1=1,flag2=1;
		Rcache.clear();//��Rcache��� 
		//��ɨ�裬��������
		for(int i=0;i<cols;i++){
			for(int j=i+1;j<cols;j++){
				for(int k=0;k<rows;k++){
					//��ɶ�Ԫ��ab����ʽ
					long long ab=combine(v[i][k],v[j][k]);
					cout << ab << "\n";
					if(Rcache.count(ab)==0) 
						Rcache[ab]=k;
					else{
						if(flag1){ printf("NO\n"); flag1=0;}
						printf("%d %d\n%d %d\n",Rcache[ab]+1,k+1,i+1,j+1);
						flag2=0;
					}
					
					
				}
				
			}
			
		}
		if(flag2) cout << "YES" << "\n"; 
	
	
	}	
	

	
	return 0;
} 
//���ɶ�Ԫ�� 
long long combine(int x,int y){
	int len,y1=y;
	while(y1){
		y1/=10;
		len++;
	}
	long long z=x*pow(10,len)+y;
	return z;
	
}


