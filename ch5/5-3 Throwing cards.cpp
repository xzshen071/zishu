#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n;
	while(cin >> n && n != 0){
		queue<int> card;
		//��1 ~ n�Ŀ�Ƭ��ż��������
		for(int i = 1; i <= n; i++)
			card.push(i);
		//ѭ��������ֻʣһ��Ԫ��Ϊֹ
		printf("Discarded cards:");		//n����1ʱ��û��Discarded cards�����ԣ������пո� 
		int flag = 1; 
		while(card.size() != 1){
			if(flag){ cout << " "; flag = 0;}
			else cout << ", ";
			//��������Ԫ�أ��������һ��Ԫ�ز������β
			cout << card.front();		//ɾ����ͷ��Ԫ�� 
			card.pop();
			
			card.push(card.front());	//���ڶ���Ԫ�ؼ����β 
			card.pop();
			 
			
		}
		cout << endl;
		
		printf("Remaining card: ");
		cout << card.front() << endl;
		
		
		
	}
	
	
	
	
	
	
	return 0;
} 
