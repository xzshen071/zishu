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
        //int weim=-1;//������Ip��ַ�����λ
		memset(ip,0,sizeof(ip)); 
		//�����е�ip��ַ 
		int pos = -1;
		scanf("%d.%d.%d.%d",&ip[0][3],&ip[0][2],&ip[0][1],&ip[0][0]); 
        for(int i = 1; i < n; i++){
            //�ֳ�4���ֶ�
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
    	//��ʱ�ˣ��Ѵ�ѭ�����ڶ��������� 
        //�ҳ�ip��ַ����ͬ�ĵط�����¼ÿ��ip��Ӧ��4��ʮ�������Ĳ�֮ͬ���� 
        int pos, flag = 0;				//��¼��һ��ʮ���������ڲ�ͬ 
		for(int j = 3; j >=0; j--)  {		//�Ե�һ��Ϊ���� 
			for(int i = 1; i < n; i++) {	//�����λ��ʼ���ҵ���ͬ���˳� 
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
		
		//�Զ����ip��ַ���д��� 	
        //��posλ��ʮ���������ж�����ת������¼��ͬ��λ�� 
        int min_w = 999999;
        //cout << ip[0][pos] << endl;
        string tmp1, tmp2; 
		tmp1 = chang_er(ip[0][pos]);	//������ 
        //cout << tmp1 << endl;
        //�ǵ�һ���������������С��ͬ��λ�� 
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

        //��������ַ��������posλ��֮���ȫ�������posλֻ��ӡ��ͬ�Ĳ��� 
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
		
		//�����������
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
//��ʮ����ת���ɶ����� 
string chang_er(int a){
	int er;
	string s = "";
	for(int i = 0; i < 8; i++) {	//���8λ
		er = a % 2;
		//cout << er << endl;
		s += (er + '0');
		a /= 2;
	}
	reverse(s.begin(),s.end());		//�ַ�����ת 
	//cout << s << endl;
	return s;
	//printf("%d\n",num);
}

