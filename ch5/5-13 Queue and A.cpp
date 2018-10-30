#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 20 + 5;
const int INF = 999999999;

//���� 
struct topi{
	int nt;					//��ɴ�������Ҫ��ʱ�� 
	queue<int> r_t;			//�յ������ʱ�̣����ж������� 
	
};
//�ͷ� 
struct person{
	int id, k, tid[ maxn];	//id�����Դ���k�����⡢���Դ�����������ȼ�����	
	int st;					//�ϴδ��������ʱ�� 
	int ft;					//�������ʱ�� 
	bool operator < (const person& that) const{	//������� 
		if( st != that.st) return st < that.st;	//�ȱȽ��ϴο�ʼ���������ʱ�� 
		return id < that.id;					//�ٱȽϿͷ�id 
	
	}
	
	
};

int main(){
	//freopen( "input.txt", "r", stdin);
	//freopen( "output.txt", "w", stdout);
	
	int n; 
	int Scenario = 0; 
	while( cin >> n && n != 0){
		int now_t = INF;							//��������Ŀ�ʼʱ�� 
		map<int, topi> name_topi;					//�����������������ӳ��
		//�������� 
		for( int i = 0; i < n; i++){
			int name, num, t0, t, dt;
			cin >> name >> num >> t0 >> t >> dt;
		
			now_t = min( now_t, t0);			
		
			name_topi[ name].nt = t;				//����һ�����⻨�ѵ�ʱ�� 
			for( int j = 0; j < num; j++)			//��ͬһ����Ŀ�ʼʱ�� 
				name_topi[ name].r_t.push( t0 + j * dt);
			/*
			cout << name_topi[ name].nt << " ";
			while( !name_topi[ name].r_t.empty()){ cout << name_topi[ name].r_t.front() << " "; name_topi[ name].r_t.pop(); } cout << endl;
 			*/	
		}
		//cout << now_t <<endl;
		
		
		//����ͷ�
		int m; cin >> m;
		vector<person> psnl(m);						//����һ������ΪM��Person���͵�һ������(��������ֱ����λ�귨��ֵ)
		for( int i = 0; i < m; i++){
			cin >> psnl[i].id >> psnl[i].k;
			for( int j = 0; j < psnl[i].k; j++) 
				cin >> psnl[i].tid[j];
			psnl[i].ft = 0; 
			
		} 
		/*
		for( int i = 0; i < m; i++){
			cout << psnl[i].id << " " << psnl[i].k << " " << psnl[i].ft << endl;
			for( int j = 0; j < psnl[i].k; j++) 
				cout <<  psnl[i].tid[j] << " ";	
			cout << endl;
		}
		*/
		
		//��������	
		int c_t = -1;																							//�����滨�ѵ���ʱ�� 
		while( n){																								//��������������
			int tmp_t = INF;																					//�������в�������С����һʱ��
			sort( psnl.begin(), psnl.end());																	//�Կͷ��������� 
			
			for( int i = 0; i < m; i++){
				int pti = INF;																					//�����в�������С����һʱ�� 
				//�ж�����æ��æ��now_tָ�������пͷ��в�������Сʱ�� 
				if( psnl[i].ft > now_t) pti = psnl[i].ft;														//æ������һʱ���в�����ʱ��Ϊ�������ʱ�� 
				else{																							//��æ 
					//�����ȼ�����ÿһ������ 
					for( int j = 0; j < psnl[i].k; j++){						
						int tmp_n = psnl[i].tid[j];	
						if( name_topi[ tmp_n].r_t.empty()) continue;											//���������Ϊ�գ�����һ������
						if( name_topi[ tmp_n].r_t.front() <= now_t){											//�����ѵ��� 
							pti = now_t +  name_topi[ tmp_n].nt;												//��һʱ���в�����ʱ��Ϊ��ɴ����� 
							if( c_t < pti) c_t = pti;															//��󻨷�ʱ�伴Ϊ�ܹ�ʱ�� 
							psnl[i].st= now_t;																	//��ʼʱ�� 
							name_topi[ tmp_n].r_t.pop();
							if( name_topi[ tmp_n].r_t.empty()) n--;
							break;																				//������һ������Ͳ�������һ�������� 
							
						}else if( name_topi[ tmp_n].r_t.front() < pti) pti = name_topi[ tmp_n].r_t.front();		//��һʱ���в�����ʱ��Ϊ������ĵ���ʱ�� 
						
					
					}
					psnl[i].ft= pti;																			//�����ʱ�䣨�������õ�ʱ�䣩 
					
				} 
				tmp_t = min( tmp_t, pti);																		//��������һ�׶���С��ʱ��  
					
			} 
			now_t = tmp_t;																						//����ʱ�� 
		} 
		printf("Scenario %d: All requests are serviced within %d minutes.\n", ++Scenario, c_t);
		
		
	} 
	return 0;
} 
