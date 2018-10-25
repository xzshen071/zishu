//离散化 
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
	bool operator < (const Building &rhs) const {		//坐标x指的是西南角向东起始位置 
		return x < rhs.x || (x == rhs.x && y < rhs.y);	//若x相等，则比较西南角向北的起始位置（考前的排在前） 
	
	}
	
}b[maxn];

int n;
double x[maxn*2];

bool cover(int i, double mx) {
	return b[i].x <= mx && b[i].x+b[i].w >= mx;			//要在此为位置可见，首先需包含这个坐标点 
}

//判断建筑物i在x=mx处是否可见（只是判断在这个坐标点是否可见） 
bool visible(int i, double mx) {
	if(!cover(i, mx)) return false;
	for(int k = 0; k < n; k++)
		if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx)) return false;	//判断其他建筑是否在此点也可见，若可见则比较两者的深度和高度 
	return true;
} 

int main(){
	int kase = 0;
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h); 
			x[i*2] = b[i].x; x[i*2+1] = b[i].x + b[i].w;						//存一个建筑物的邻域 
			b[i].id = i + 1;
		}
		sort(b,b+n);
		sort(x,x+n*2);
		int m = unique(x, x+n*2) - x;	//x坐标排序后去重，得到m个坐标（相邻两x坐标作为一个邻域） 
	
		if(kase++) printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n%d",kase, b[0].id);
		
		for(int i = 1; i < n; i++) {
			bool vis = false;
			for(int j = 0; j < m-1; j++ )
				if(visible(i, (x[j] + x[j+1])/2)) {		//一个区间要么完全可见，要么完全不可见，这样只需在这个区间内任取一点，此处取中点 
					vis = true; break;
				}
			if(vis) printf("  %d", b[i].id); 
		}
		printf("\n"); 
	
	
	}
	
	

	return 0;
}


/*
	unique函数：
	1、格式：
		//在[it_1,it_2)范围的元素进行去重，返回值为迭代器，指向去重后容器中的不重复序列最后一个的下一个元素 
		iterator unique(iterator it_1,iterator it_2);	
		iterator unique(iterator it_1,iterator it_2,bool MyFunc);	//MffunC是自定义元素是否相等的函数，与sort等类似 
	2、原理：
		不停的把后面不重复的元素移到前面来，也可以说是用不重复的元素占领重复元素的位置 
	3、unique函数等价的子函数： 
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
//自行定义相等函数
bool myfunc(int i,int j){	//int,bool型都可以 
	//return (i+1) == j;
	return i == j;
} 

int b[]={2,6,3,2,1,7,1,3};
//测试unique函数
int main(){

	vector<int> a;
	for(int i = 0; i < 8; i++){
		a.push_back(b[i]);
	}
	//vector<int>::iterator it_1 = a.begin();	//迭代器可以算是指针 
	//vector<int>::iterator it_2 = a.end();
	vector<int>::iterator new_end; 
	
	//进行去重操作前基本上都需要排序，因为用unique函数原理是使相邻的两元素不相等，若没有经过排序，序列里会有跟其他位置相同的元素，达不到去重的效果 
	//sort(it_1, it_2); 
	sort(a.begin(),a.end()); 
	cout << "去重前的 a："; 
	for(int i = 0;i < a.size(); i++){
		cout << a[i];
	}
	cout << endl;
	//unique(it_1,it_2);
	//unique(a.begin(),a.end());
	//int m = unique(a.begin(),a.end(),myfunc) - a; //报错，说类型不能转换成int
	//cout << m << endl; 
	new_end = unique(a.begin(),a.end());
	cout << "去重后的 a："; 
	for(int i = 0;i < a.size(); i++){ 	//容器长度不变 
		cout << a[i];
	}
	cout << endl << a.size() << endl;	//endl相当于换行符 
	
	//unique经常搭配erase函数，真正删除重复元素，容器长度也发生变化 
	a.erase(new_end,a.end());	//注意是从new_ewd到end()，就是删除new_end之后的元素 
    cout<<"删除重复元素后的 a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout<<a[i];
    cout << endl << a.size() << endl;


/*
	//用数组测试unique的返回值 
	sort(b,b+8);	//普通数组没有.begin and .end 
	cout << "去重前的 b："; 
	for(int i = 0;i < 8; i++){
		cout << b[i];
	}
	cout << endl;
	//unique(b,b+8);
	int m = unique(b,b+8,myfunc) - b;	//unique当对象是数组的时候返回指针，赋值对象要为指针（地址）;两个指针相减得元素个数，验证了unique的返回值 
	cout << m << endl;
	cout << "去重后的 b：";
	for(int i = 0;i < 8; i++){
		cout << b[i];
	}
	cout << endl;

	
	
	
	
	return 0;
}
*/

