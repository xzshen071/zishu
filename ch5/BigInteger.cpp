#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio> 
#include<set>
#include<map>
#include<algorithm> 
using namespace std;
//��������BigInteger��ͨ���ṹ��ʵ��
//���ṹ�����ظ�ֵ�������ʹ�������������� 
struct BigInteger{
	 //��̬��Ա����---ֻ����BigInteger������ͣ��ýṹ���к���������ֱ�ӵ��ã����ڽṹ���ã������ط���������Ҫд��BigInteger::BASE 
	static const int BASE=100000000;//�ܱ�ʾ�������,Ҫ��10�Ĵη�����Ϊ���������������ʮ���� 
	static const int WIDTH=8;//�ܱ�ʾ�����λ����10�Ĵη��� 
	vector<int> s;
	
	//���캯�� 
	BigInteger(long long num=0){ *this=num; }//���ǲ���Ҳֻ�ܱ�ʾlong long��ô����������ԣ�����Բ�����long long������  
	//��ֵ�������������long long�͵Ķ��� 
	BigInteger operator =(long long num){ 
		s.clear();
		do{
			s.push_back(num%BASE);
			num/=BASE;
			
		}while(num>0);
		
		return *this;//ɾ��������û�����������ҵ���⣺*this�ǵ�ǰ���󣨴˽ṹ�嶨��Ķ��󣩣��������ݷ��ظ�s��vector<int>��
		
	} 
	 //long long���Ͳ��������
	//��ֵ�������������string����
	BigInteger operator =(const string &str){
		s.clear();
		//��������8λ8λ�Ĵ���������vector<int>�� 
		int x,len=(str.length()-1)/WIDTH +1;//�ַ���������8��0+1=1���ַ���������9��1+1=2 
		for(int i=0;i<len;i++){
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			//��ʽ��string.substr(start,length)������string�д�startλ�ÿ�ʼ�ĳ���Ϊlength�����ַ��� 
			//��ʽ��string.c_str()������һ��ָ��ָ���ַ����൱��һ��'\0'��β������C�ַ������飬���Բ�����sscanf��ȡ���� 
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);//��ȡ����x���ַ����е����֣����ԣ�����Ϊ������0��ʼ�����Բ���end-start+1�� 
			
			//Ҫע�������λǰ��ļ���8λ�У�������ǵĵڰ�λΪ0����ô���������ʱ��Ͳ����а�λ�����ʱҪע��(�õ���֤)
			s.push_back(x); 
			
		}
		return *this;//���ر����� 
		
		
	} 
	
	//�ӷ� 
	BigInteger operator + (const BigInteger &b) const{//�ڶ���const�������ĳ�Ա�����г�����,��const������ֹ�ڴ˺������޸Ĵ���ĳ�Ա����
		BigInteger c;//�������ش� 
		c.s.clear();
		for(int i=0,g=0;;i++){//��i=0��ʼ,ע����i=0,g=0;; 
			if(g==0 && i>=s.size() && i>=b.s.size()) break;
			int x=g;//��λλ 
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x % BASE);
			g=x/BASE;			
			
		}
		return c;
	
	
	} 
	//+=����� 
	BigInteger operator += (const BigInteger& b){
		*this = *this +b;//*thisΪ�ýṹ�������Ϊ������+��������ֱ����
		return *this; 
	
		
	}
	//�Ƚ������ 
	bool operator < (const BigInteger &b) const{
		if(s.size() != b.s.size()) return s.size() < b.s.size();
		for(int i=s.size()-1;i>=0;i--) //�Ӻ���ǰ��Ƚϣ���Ϊ(��λ��vector��ǰ��)ע:��������ǰ����������û��ǰ��0�������ܱȽ� 
			if(s[i]!=b.s[i]) return s[i] < b.s[i];
	
		return false;//��� 


	} 
	//ͨ�� <���ţ����Ժܷ���Ķ��������Ƚ������
	bool operator > (const BigInteger &b) const{ return b< *this;}
	bool operator <= (const BigInteger &b) const{ return!(b< *this);}
	bool operator >= (const BigInteger &b) const{ return!(*this< b);}
	bool operator != (const BigInteger &b) const{ return b<*this || *this <b;}
	bool operator == (const BigInteger &b) const{ return!(*this< b) && !(b< *this);}
	//��Ϊsort��set��map�����������͡�С�ڡ���������������߶�֧��BigInteger 

	
};
//����� 
ostream& operator << (ostream &out,const BigInteger &x){//x����λ��������ֹ���仯 
	out << x.s.back();//������λ�����ܲ���8λ��,����������Ჹ0�����Ե������ 
	for(int i=x.s.size()-2;i>=0;i--){ 
		char buf[20];
		sprintf(buf,"%08d",x.s[i]);//%08d��ֹ8λ���λ��0�������������x.s[i]������ݶ���buf 
		for(int j=0;j<strlen(buf);j++) out << buf[j]; 
		
	} 
	return out;
	
}
//������ 
istream& operator >> (istream &in,BigInteger &x){
	string s;
	if(!(in >> s)) return in;
	x=s; //������ȷ���� 
	return in;
	
	
}

int main(){
/* 
	//����substr(start,length)��c_str()���� 
	string s="www.wohen666.com";
	printf("%s\n",s.substr(4,8).c_str());//printf("%s",s.substr(4,8))�ᱨ����Ϊ��׼������������ʺ�string���� 
	cout << s.substr(4,8) << "\n";//���ᱨ��������������string���� 
*/
	 
/*
	BigInteger b1;
	b1=12345678976; 
	//b1="1034567890765432103456789";//b1=1234567898765432123456789������˵��Ҫ�������long long�͵������������ַ�����ʾ 
	//printf("%d\n",b1.s.back()); 
	for(int i=b1.s.size()-1;i>=0;i--){
		printf("%d",b1.s[i]);
		
	}
*/
	
/*
	//����+��+= 
	BigInteger b1,b2;
	cin >> b1 >> b2;//ȫ�����string��ʽ�����Գ���long long��Ҳ������� 
	b1+=b2;
	cout << b1; 
*/
	

	//��set��map��sort���� 
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
