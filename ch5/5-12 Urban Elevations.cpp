//��ɢ�� 
#include<cstdio>
#include<algorithm> 
#include<cassert>
#include<vector>
#include<iostream>
using namespace std;

const int maxn = 100 + 5;

struct Building {
	int id;
	double x, y, w, d, h;
	bool operator < (const Building &rhs) const {		//����xָ�������Ͻ�����ʼλ�� 
		return x < rhs.x || (x == rhs.x && y < rhs.y);	//��x��ȣ���Ƚ����Ͻ��򱱵���ʼλ�ã���ǰ������ǰ�� 
	
	}
	
}b[maxn];

int n;
double x[maxn*2];

bool cover(int i, double mx) {
	return b[i].x <= mx && b[i].x+b[i].w >= mx;			//Ҫ�ڴ�Ϊλ�ÿɼ�������������������� 
}

//�жϽ�����i��x=mx���Ƿ�ɼ���ֻ���ж������������Ƿ�ɼ��� 
bool visible(int i, double mx) {
	if(!cover(i, mx)) return false;
	for(int k = 0; k < n; k++)
		if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx)) return false;	//�ж����������Ƿ��ڴ˵�Ҳ�ɼ������ɼ���Ƚ����ߵ���Ⱥ͸߶� 
	return true;
} 

int main(){
	int kase = 0;
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h); 
			x[i*2] = b[i].x; x[i*2+1] = b[i].x + b[i].w;						//��һ������������� 
			b[i].id = i + 1;
		}
		sort(b,b+n);
		sort(x,x+n*2);
		int m = unique(x, x+n*2) - x;	//x���������ȥ�أ��õ�m�����꣨������x������Ϊһ������ 
	
		if(kase++) printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n%d",kase, b[0].id);
		
		for(int i = 1; i < n; i++) {
			bool vis = false;
			for(int j = 0; j < m-1; j++ )
				if(visible(i, (x[j] + x[j+1])/2)) {		//һ������Ҫô��ȫ�ɼ���Ҫô��ȫ���ɼ�������ֻ���������������ȡһ�㣬�˴�ȡ�е� 
					vis = true; break;
				}
			if(vis) printf("  %d", b[i].id); 
		}
		printf("\n"); 
	
	
	}
	
	

	return 0;
}


/*
	unique������
	1����ʽ��
		//��[it_1,it_2)��Χ��Ԫ�ؽ���ȥ�أ�����ֵΪ��������ָ��ȥ�غ������еĲ��ظ��������һ������һ��Ԫ�� 
		iterator unique(iterator it_1,iterator it_2);	
		iterator unique(iterator it_1,iterator it_2,bool MyFunc);	//MffunC���Զ���Ԫ���Ƿ���ȵĺ�������sort������ 
	2��ԭ��
		��ͣ�İѺ��治�ظ���Ԫ���Ƶ�ǰ������Ҳ����˵���ò��ظ���Ԫ��ռ���ظ�Ԫ�ص�λ�� 
	3��unique�����ȼ۵��Ӻ����� 
	iterator My_Unique (iterator first, iterator last){
  		if (first==last) return last;
 
  		iterator result = first;
 		while (++first != last){
    		if (!(*result == *first))  
      			*(++result)=*first;
  		}
  		return ++result;
	} 
	 

*/
/*
//���ж�����Ⱥ���
bool myfunc(int i,int j){	//int,bool�Ͷ����� 
	//return (i+1) == j;
	return i == j;
} 

int b[]={2,6,3,2,1,7,1,3};
//����unique����
int main(){

	vector<int> a;
	for(int i = 0; i < 8; i++){
		a.push_back(b[i]);
	}
	//vector<int>::iterator it_1 = a.begin();	//��������������ָ�� 
	//vector<int>::iterator it_2 = a.end();
	vector<int>::iterator new_end; 
	
	//����ȥ�ز���ǰ�����϶���Ҫ������Ϊ��unique����ԭ����ʹ���ڵ���Ԫ�ز���ȣ���û�о���������������и�����λ����ͬ��Ԫ�أ��ﲻ��ȥ�ص�Ч�� 
	//sort(it_1, it_2); 
	sort(a.begin(),a.end()); 
	cout << "ȥ��ǰ�� a��"; 
	for(int i = 0;i < a.size(); i++){
		cout << a[i];
	}
	cout << endl;
	//unique(it_1,it_2);
	//unique(a.begin(),a.end());
	//int m = unique(a.begin(),a.end(),myfunc) - a; //����˵���Ͳ���ת����int
	//cout << m << endl; 
	new_end = unique(a.begin(),a.end());
	cout << "ȥ�غ�� a��"; 
	for(int i = 0;i < a.size(); i++){ 	//�������Ȳ��� 
		cout << a[i];
	}
	cout << endl << a.size() << endl;	//endl�൱�ڻ��з� 
	
	//unique��������erase����������ɾ���ظ�Ԫ�أ���������Ҳ�����仯 
	a.erase(new_end,a.end());	//ע���Ǵ�new_ewd��end()������ɾ��new_end֮���Ԫ�� 
    cout<<"ɾ���ظ�Ԫ�غ�� a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout<<a[i];
    cout << endl << a.size() << endl;


/*
	//���������unique�ķ���ֵ 
	sort(b,b+8);	//��ͨ����û��.begin and .end 
	cout << "ȥ��ǰ�� b��"; 
	for(int i = 0;i < 8; i++){
		cout << b[i];
	}
	cout << endl;
	//unique(b,b+8);
	int m = unique(b,b+8,myfunc) - b;	//unique�������������ʱ�򷵻�ָ�룬��ֵ����ҪΪָ�루��ַ��;����ָ�������Ԫ�ظ�������֤��unique�ķ���ֵ 
	cout << m << endl;
	cout << "ȥ�غ�� b��";
	for(int i = 0;i < 8; i++){
		cout << b[i];
	}
	cout << endl;

	
	
	
	
	return 0;
}
*/

