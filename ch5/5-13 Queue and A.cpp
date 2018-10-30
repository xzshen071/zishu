#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 20 + 5;
const int INF = 999999999;

//主题 
struct topi{
	int nt;					//完成此主题需要的时间 
	queue<int> r_t;			//收到主题的时刻，进行队列排序 
	
};
//客服 
struct person{
	int id, k, tid[ maxn];	//id、可以处理k种主题、可以处理的主题优先级数组	
	int st;					//上次处理请求的时间 
	int ft;					//请求完成时间 
	bool operator < (const person& that) const{	//排序规则 
		if( st != that.st) return st < that.st;	//先比较上次开始处理请求的时间 
		return id < that.id;					//再比较客服id 
	
	}
	
	
};

int main(){
	//freopen( "input.txt", "r", stdin);
	//freopen( "output.txt", "w", stdout);
	
	int n; 
	int Scenario = 0; 
	while( cin >> n && n != 0){
		int now_t = INF;							//出现请求的开始时间 
		map<int, topi> name_topi;					//主题名对主题参数的映射
		//读入主题 
		for( int i = 0; i < n; i++){
			int name, num, t0, t, dt;
			cin >> name >> num >> t0 >> t >> dt;
		
			now_t = min( now_t, t0);			
		
			name_topi[ name].nt = t;				//处理一个主题花费的时间 
			for( int j = 0; j < num; j++)			//存同一主题的开始时刻 
				name_topi[ name].r_t.push( t0 + j * dt);
			/*
			cout << name_topi[ name].nt << " ";
			while( !name_topi[ name].r_t.empty()){ cout << name_topi[ name].r_t.front() << " "; name_topi[ name].r_t.pop(); } cout << endl;
 			*/	
		}
		//cout << now_t <<endl;
		
		
		//读入客服
		int m; cin >> m;
		vector<person> psnl(m);						//定义一个长度为M的Person类型的一个数组(这样可以直接用位标法赋值)
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
		
		//处理请求	
		int c_t = -1;																							//用来存花费的总时间 
		while( n){																								//所有请求结束则结
			int tmp_t = INF;																					//用来存有操作的最小的下一时段
			sort( psnl.begin(), psnl.end());																	//对客服进行排序 
			
			for( int i = 0; i < m; i++){
				int pti = INF;																					//此人有操作的最小的下一时段 
				//判断现在忙不忙，now_t指的是所有客服有操作的最小时刻 
				if( psnl[i].ft > now_t) pti = psnl[i].ft;														//忙，则下一时段有操作的时刻为此人完成时间 
				else{																							//不忙 
					//按优先级处理每一个主题 
					for( int j = 0; j < psnl[i].k; j++){						
						int tmp_n = psnl[i].tid[j];	
						if( name_topi[ tmp_n].r_t.empty()) continue;											//此主题队列为空，则下一个主题
						if( name_topi[ tmp_n].r_t.front() <= now_t){											//请求已到达 
							pti = now_t +  name_topi[ tmp_n].nt;												//下一时段有操作的时刻为完成此请求 
							if( c_t < pti) c_t = pti;															//最大花费时间即为总共时间 
							psnl[i].st= now_t;																	//开始时间 
							name_topi[ tmp_n].r_t.pop();
							if( name_topi[ tmp_n].r_t.empty()) n--;
							break;																				//操作了一个请求就不操作下一个请求了 
							
						}else if( name_topi[ tmp_n].r_t.front() < pti) pti = name_topi[ tmp_n].r_t.front();		//下一时段有操作的时刻为此请求的到达时刻 
						
					
					}
					psnl[i].ft= pti;																			//存完成时间（包括闲置的时间） 
					
				} 
				tmp_t = min( tmp_t, pti);																		//所有人下一阶段最小的时刻  
					
			} 
			now_t = tmp_t;																						//更新时间 
		} 
		printf("Scenario %d: All requests are serviced within %d minutes.\n", ++Scenario, c_t);
		
		
	} 
	return 0;
} 
