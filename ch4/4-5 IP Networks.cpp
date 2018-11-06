#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>   
#include<algorithm>
using namespace std;
#define maxn 30
int ip[1005][6];
int yanma[9]={255,254,252,248,240,224,192,128,0};
string chang_er(int a); 
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	while(scanf("%d",&n) == 1){
        //int weim=-1;//存所有Ip地址的最大位
		memset(ip,0,sizeof(ip)); 
		//读所有的ip地址 
		int pos = -1;
		scanf("%d.%d.%d.%d",&ip[0][3],&ip[0][2],&ip[0][1],&ip[0][0]); 
        for(int i = 1; i < n; i++){
            //分成4部分读
            scanf("%d.%d.%d.%d",&ip[i][3],&ip[i][2],&ip[i][1],&ip[i][0]); 
            //printf("%d %d %d %d\n",ip[i][3],ip[i][2],ip[i][1],ip[i][0]);
            for(int j = 3; j >= 0; j--) {
            	if(ip[i][j] != ip[0][j]) {
            		if(j > pos)
            			pos = j;
            		break;
				}
			}
        }
    	/*
    	//超时了，把此循环放在读入数据中 
        //找出ip地址不相同的地方（记录每个ip对应的4个十进制数的不同之处） 
        int pos, flag = 0;				//记录哪一个十进制数存在不同 
		for(int j = 3; j >=0; j--)  {		//以第一个为参照 
			for(int i = 1; i < n; i++) {	//从最高位开始，找到不同就退出 
				if(ip[0][j] != ip[i][j]) {
					pos = j;
					flag = 1;
					break;
				}  	
			} 
			if(flag) break;
		} 
		//cout << pos << endl;
		*/
		
		//对读入的ip地址进行处理 	
        //对pos位的十进制数进行二进制转化，记录相同的位数 
        int min_w = 999999;
        //cout << ip[0][pos] << endl;
        string tmp1, tmp2; 
		tmp1 = chang_er(ip[0][pos]);	//做参照 
        //cout << tmp1 << endl;
        //那第一个做参照物，计算最小相同的位数 
        for(int i = 1; i < n; i++) {
			tmp2 = chang_er(ip[i][pos]);
			//cout << tmp2 << endl;
			for(int j = 0; j < 8; j++) {
				if(tmp1[j] != tmp2[j]) {
					if(j < min_w)
						min_w = j;
					break;
				}
			}
        } 
        //cout << min_w << endl;

        //输出网络地址，即除了pos位置之后的全部置零和pos位只打印相同的部分 
        if(n == 1) {
			min_w = 8;
			pos = -1;
		}
        int flag1 = 1, tmp_ip;
		for(int j = 3; j >=0; j--) {
			if(flag1) flag1 = 0;
			else cout << ".";
			if(j > pos) cout << ip[0][j];
			else if(j == pos) {
				ip[0][j] = ip[0][j] >> (8 - min_w);
				tmp_ip = ip[0][j] << (8 - min_w);
				cout << tmp_ip;
			}else {
				cout << "0";
			}
		}  
		cout << endl;
		
		//输出子网掩码
		flag1 = 1; 
		for(int j = 3; j >=0; j--) {
			if(flag1) flag1 = 0;
			else cout << ".";
			if(j > pos) cout << yanma[0];
			else if(j == pos) cout << yanma[8 - min_w];
			else cout << "0";
		}
		cout << endl;
		
	}
	return 0;
} 
//将十进制转化成二进制 
string chang_er(int a){
	int er;
	string s = "";
	for(int i = 0; i < 8; i++) {	//变成8位
		er = a % 2;
		//cout << er << endl;
		s += (er + '0');
		a /= 2;
	}
	reverse(s.begin(),s.end());		//字符串反转 
	//cout << s << endl;
	return s;
	//printf("%d\n",num);
}

