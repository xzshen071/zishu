#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio> 
#include<set>
#include<map>
#include<algorithm> 
using namespace std;
//大整数类BigInteger，通过结构体实现
//给结构体重载赋值运算符，使得用起来更方便 
struct BigInteger{
	 //静态成员变量---只属于BigInteger这个类型，该结构体中函数都可以直接调用；想在结构外用（其他地方），则需要写成BigInteger::BASE 
	static const int BASE=100000000;//能表示的最大数,要用10的次方，因为我们输入的整数是十进制 
	static const int WIDTH=8;//能表示的最大位数（10的次方） 
	vector<int> s;
	
	//构造函数 
	BigInteger(long long num=0){ *this=num; }//那是不是也只能表示long long这么大的整数（对），面对不超过long long的整数  
	//赋值运算符，对象是long long型的对象 
	BigInteger operator =(long long num){ 
		s.clear();
		do{
			s.push_back(num%BASE);
			num/=BASE;
			
		}while(num>0);
		
		return *this;//删除此语句后，没有输出结果。我的理解：*this是当前对象（此结构体定义的对象），即将内容返回给s（vector<int>）
		
	} 
	 //long long类型不够的情况
	//赋值运算符，对象是string类型
	BigInteger operator =(const string &str){
		s.clear();
		//从右向左8位8位的储存整数到vector<int>中 
		int x,len=(str.length()-1)/WIDTH +1;//字符串长度是8：0+1=1；字符串长度是9：1+1=2 
		for(int i=0;i<len;i++){
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			//格式：string.substr(start,length)，返回string中从start位置开始的长度为length的子字符串 
			//格式：string.c_str()，返回一个指针指向字符串相当于一个'\0'结尾的正规C字符串数组，所以才能用sscanf提取整形 
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);//读取整形x是字符串中的数字？（对）（因为数组是0开始，所以不是end-start+1） 
			
			//要注意在最高位前面的几组8位中，如果他们的第八位为0，那么组成整数的时候就不会有八位，输出时要注意(得到验证)
			s.push_back(x); 
			
		}
		return *this;//返回本对象 
		
		
	} 
	
	//加法 
	BigInteger operator + (const BigInteger &b) const{//第二个const放在最后的成员函数叫常函数,此const用来防止在此函数中修改此类的成员数据
		BigInteger c;//用来返回答案 
		c.s.clear();
		for(int i=0,g=0;;i++){//从i=0开始,注意是i=0,g=0;; 
			if(g==0 && i>=s.size() && i>=b.s.size()) break;
			int x=g;//进位位 
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x % BASE);
			g=x/BASE;			
			
		}
		return c;
	
	
	} 
	//+=运算符 
	BigInteger operator += (const BigInteger& b){
		*this = *this +b;//*this为该结构体对象，因为定义了+，所以能直接用
		return *this; 
	
		
	}
	//比较运算符 
	bool operator < (const BigInteger &b) const{
		if(s.size() != b.s.size()) return s.size() < b.s.size();
		for(int i=s.size()-1;i>=0;i--) //从后往前面比较，因为(低位在vector的前面)注:这样做的前提是两个都没有前导0，否则不能比较 
			if(s[i]!=b.s[i]) return s[i] < b.s[i];
	
		return false;//相等 


	} 
	//通过 <符号，可以很方便的定义其他比较运算符
	bool operator > (const BigInteger &b) const{ return b< *this;}
	bool operator <= (const BigInteger &b) const{ return!(b< *this);}
	bool operator >= (const BigInteger &b) const{ return!(*this< b);}
	bool operator != (const BigInteger &b) const{ return b<*this || *this <b;}
	bool operator == (const BigInteger &b) const{ return!(*this< b) && !(b< *this);}
	//因为sort、set和map都依赖于类型“小于”运算符，至此三者都支持BigInteger 

	
};
//流输出 
ostream& operator << (ostream &out,const BigInteger &x){//x定义位常数，防止它变化 
	out << x.s.back();//输出最高位（可能不是8位）,按后述输出会补0，所以单独输出 
	for(int i=x.s.size()-2;i>=0;i--){ 
		char buf[20];
		sprintf(buf,"%08d",x.s[i]);//%08d防止8位里后几位是0输出不出来，将x.s[i]里的内容读给buf 
		for(int j=0;j<strlen(buf);j++) out << buf[j]; 
		
	} 
	return out;
	
}
//流输入 
istream& operator >> (istream &in,BigInteger &x){
	string s;
	if(!(in >> s)) return in;
	x=s; //输入正确的流 
	return in;
	
	
}

int main(){
/* 
	//测试substr(start,length)和c_str()函数 
	string s="www.wohen666.com";
	printf("%s\n",s.substr(4,8).c_str());//printf("%s",s.substr(4,8))会报错，因为标准的输入输出不适合string类型 
	cout << s.substr(4,8) << "\n";//不会报错，流输出可以输出string类型 
*/
	 
/*
	BigInteger b1;
	b1=12345678976; 
	//b1="1034567890765432103456789";//b1=1234567898765432123456789，报错，说明要输出超过long long型的整数必须用字符串表示 
	//printf("%d\n",b1.s.back()); 
	for(int i=b1.s.size()-1;i>=0;i--){
		printf("%d",b1.s[i]);
		
	}
*/
	
/*
	//测试+，+= 
	BigInteger b1,b2;
	cin >> b1 >> b2;//全输入成string形式，所以超过long long型也不会出错 
	b1+=b2;
	cout << b1; 
*/
	

	//用set、map、sort测试 
	int t;
	set<BigInteger> s;
	vector<BigInteger> v;
	map<BigInteger,int> m;
	cin >> t;
	for(int i=0;i<t;i++){
		BigInteger b;
		cin >> b;
		s.insert(b);
		v.push_back(b);
		m[b]=i;
				
	}
	/* 
	for(int i=0;i<t;i++){
		cout << v[i] << " ";
		
	}
	cout << "\n";
	sort(v.begin(),v.end());
	for(int i=0;i<t;i++){
		cout << v[i] << " ";
		
	}
	cout << "\n";
	*/	
	
	/*
	for(set<BigInteger>::iterator it=s.begin();it !=s.end();++it)
		cout << *it << "\n";
		return 0;
	*/
	
	/*
	for(int i=0;i<t;i++){
		cout << m[v[i]] << " ";
		
	}
	*/
	
} 
