#include<iostream>
#include<cstdio>
#include<vector> 
#include<sstream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=144+10;
const int maxr=70;//���佱������� 
const int DQ_s=500;
struct player{
	string name;
	vector<int> round_s;//����DQ���򽫴��ֵ�ֵ��ֵΪ500(�����б��������)	
	int g12,g1234;//����ԽСԽ�� 
	bool Pro,DQ,T;//�ж��Ƿ�ְҵ�������ͬ��   
	int num_T;//ͬ�ִ��� 
	int rank; 
	
	
}p[maxn];
int comp1(const player &a,const player &b)
{
    return a.g12 < b.g12;
}
int comp2(const player &a,const player &b)
{
    return a.g1234 < b.g1234;
}
int comp3(const player &a,const player &b)
{
    int min_len = a.name.length() < b.name.length() ? a.name.length() : b.name.length();
    for(int i = 0;i < min_len; i++){
    	if(a.name[i]!=b.name[i])
    		return a.name[i] < b.name[i];
	}
	return a.name.length() < b.name.length();
}

vector<double> rate;//��1~70���Ľ������
vector<double> real_r;//���淢�Ÿ�ѡ�ֵĽ������ 
const int dist[]={21,10,5,5,5,5,10};
const string msg[]={"Palyer Name","Place","RD1","RD2","RD3","RD4","TOTAL"};
string itos(int i);
void print(const string &s,int len,char extra);
int main(){

	//���������
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int t,flag=0;
	cin >> t; 
	while(t--){
		//memset(p,0,sizeof(sturct player)*maxn);
		//������
		double total_bonus;
		cin >> total_bonus;//���ܽ��� 
		//cout << total_bonus << "\n";
		rate.clear();
		for(int i=1;i<=maxr;i++){ double r; cin >> r; rate.push_back(r); }; 
		//for(int i=0;i<maxr;i++) cout << rate[i] << " ";
		//cout << "\n"; 
		 
		//��ѡ����Ϣ
		int Pnum,flag1=1;
		cin >> Pnum;
		//cout << Pnum << "\n"; 
		
		for(int i=1;i<=Pnum;i++){
			//Ԥ���� 
			string line;
			if(flag1){ char c=getchar(); flag1=0;}
			getline(cin,line);
			for(int j=0 ;j<line.length();j++){ 
				if(line[j]==' '){ 
					if(line[j+1]==' ') break;
					line[j]='-'; 
				}
			
			}
			stringstream ss(line);
			//��ѡ������ 
			p[i].name.clear();
			ss >> p[i].name ;
			int lens=p[i].name.length();
			//cout << lens << "\n";
			for(int j=0;j<lens;j++){ if(p[i].name[j]=='-') p[i].name[j]=' '; }
			
			//cout << p[i].name << "\n";
			
			//�ж��Ƿ���ְҵѡ�� 
			if(p[i].name[lens-1]=='*') p[i].Pro=false;
			else p[i].Pro=true;
			//cout << p[i].Pro << "\n";
			//��ÿ�ַ��� 
			p[i].round_s.clear();
			string s;
			int flag2=0;
			p[i].g12=p[i].g1234=0;
			for(int j=0;j<4;j++){
				ss >> s;
				//cout << s << " ";
				if(s[0]=='D'|| flag2){  
					p[i].DQ=true; 
					p[i].round_s.push_back(DQ_s);
					flag2=1;
				}//DQ֮��ķ���ȫ��ΪDQ_s=500 
				else { p[i].DQ=false; p[i].round_s.push_back(atoi(s.c_str()));}//atoi�������ַ���������� 
				if(j<2) p[i].g12+=p[i].round_s[j];//ǰ�����ܷ� 
				p[i].g1234+=p[i].round_s[j];//�����ܷ� 
				
			}
			/*
			cout << p[i].DQ << "\n";
			for(int j=0;j<4;j++){ cout << p[i].round_s[j] << " ";}
			cout << "\n";
			cout << p[i].g12 << " " << p[i].g1234 << "\n";
			*/
			
		}
		
		
		//ǰ���ֱ��� 
		sort(p+1,p+Pnum+1,comp1);
		/*
		for(int i=1;i<=Pnum;i++){
			cout << p[i].name << " " <<  p[i].g12 << "\n" ;
		}
		*/
		//��ѡǰmaxr������70��������У���һͬ������һ�� 
		int num_rise,count1=0; 
		for(int j=maxr+1;p[j].g12==p[maxr].g12;j++)
			count1++;
		
		num_rise=maxr+count1;
		//cout << num_rise << "\n"; 

		//�����ֱ������ӽ�����ѡ����Ƚ������ܷ�
		sort(p+1,p+num_rise+1,comp2);
		//�Գɼ���ͬ��ѡ�ֽ��д��� 
		int num_s=0,num_p=0;
		for(int i=1;i<=num_rise;i++){
			if(i-1>1 && (p[i].g1234==p[i-1].g1234)){
				p[i].T=true; p[i-1].T=true;
				num_s++;
				sort(p+i-num_s,p+i+1,comp3); 
				
			}else if(num_s!=0){ 
				for(int j=i-num_s-1;j<=i-1;j++){ 
					if(p[j].Pro){
						num_p++;
					}
				}
				for(int j=i-1;j>=i-1-num_s;j--){
					p[j].num_T=num_p;
				}
				p[i].num_T=0; 
				p[i].T=false;
				num_p=0;
				num_s=0;
			}else{
				p[i].num_T=0; 
				p[i].T=false;
				//num_p=1;
				//num_s=0;
			}
		} 
		/*
		for(int i=1;i<=num_rise;i++){
			cout << p[i].name << " " <<  p[i].g1234 << " " << p[i].num_T << "\n" ;
		}
		*/
		real_r.clear();
		for(int i=1;i<=num_rise+1;i++){
			real_r.push_back(-10.0);
		}
		/* 
		for(int i=1;i<=num_rise;i++){
			cout << real_r[i] << " "; 
		}
		cout << "\n";
		*/ 
		int count2=0;
		//���κͷ��佱����� 
		for(int i=1;i<=num_rise;i++){
			if(p[i].Pro==true){
				//cout << count2 << " " << "\n";
				int tmp1=i-count2-1;
				p[i].rank=tmp1;
				if(p[i].T==true && real_r[i]<0){
					real_r[i]=0;

					for(int j=0;j<p[i].num_T;j++){
						real_r[i]+=rate[tmp1+j];
						
					}
					for(int j=1;p[i+j].g1234==p[i].g1234;j++){
						if(p[i+j].Pro!=true) continue;
						else real_r[i+j]=real_r[i];
						
					}
				}else if(real_r[i]<0){
					//cout << i << "\n";
					real_r[i]=rate[tmp1];
					
				}
			}else{
				count2++;
			}
			//cout << p[i].name << " " <<p[i].g1234 << " " << real_r[i] << "\n";
		}

		 
		//��ӡ
		//��ͷ 
		if(flag) cout << "\n";
		flag=1;
		for(int i=0;i<7;i++){
			print(msg[i],dist[i],' ');
		} 
		cout << "Money Won\n";
		print("",72,'-');
		cout << "\n";
		
		
		//ѡ����Ϣ 
		int Place=1,num_t=0;
		for(int i=1;i<=num_rise;i++){
			//����
			print(p[i].name,dist[0],' ');
			
			//���� 
			if(p[i].T!=true && p[i].DQ!=true){ //������������ͬ 
				print(itos(i),dist[1],' ');
				num_t=0;
				
			}else if(p[i].DQ!=true){ 
				Place=i-num_t;
				if(p[i].Pro==true && p[i].num_T>1) print(itos(Place)+"T",dist[1],' ');//������ͬ����ְҵѡ�� 
				else print(itos(Place),dist[1],' ');
				if(p[i].g1234==p[i+1].g1234) num_t++;
				else num_t=0;				
			}else
				print("",dist[1],' ');
			//cout << p[i].name << " " <<  p[i].g1234 << " " << p[i].rank << "\n" ;
			
			
			
			//���ַ��� 
			for(int j=0;j<4;j++){
				if(p[i].round_s[j]==DQ_s) print("",dist[2],' ');
				else print(itos(p[i].round_s[j]),dist[2],' ');
			}
			
			//�ܷ�
			if(p[i].DQ==true) print("DQ",dist[6],' ');
			else print(itos(p[i].g1234),dist[6],' '); 
			//cout << "\n";
			
			//����
			if(p[i].DQ==true || p[i].Pro!=true) cout << "\n";//����Ͳ���ְҵѡ�� 
			else if(p[i].num_T!=0 && p[i].rank<=maxr){//����������ͬ 
		
				//printf("2");
				printf("$  %.2f\n",real_r[i]*total_bonus/100/p[i].num_T);
			} 
			else if(p[i].rank<=maxr){//������������ͬ 
				//printf("3 ");
				//cout << p[i].rank << " "<< real_r[i];
				printf("$  %.2f\n",real_r[i]*total_bonus/100); 
			}
			else cout << "\n";//������������ 
			
			
			
		}
		
		
		
	}
	 
	
	return 0;
} 
void print(const string& s,int len,char extra){
	cout << s;
	for(int i=0;i<len-s.length();i++){
		cout << extra;
		
	}
	

}
string itos(int i){//��intת����string
    stringstream s;
    s << i;
    return s.str();
}
