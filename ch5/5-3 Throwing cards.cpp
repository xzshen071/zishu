#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n;
	while(cin >> n && n != 0){
		queue<int> card;
		//将1 ~ n的卡片编号加入队列中
		for(int i = 1; i <= n; i++)
			card.push(i);
		//循环至队列只剩一个元素为止
		printf("Discarded cards:");		//n等于1时，没有Discarded cards，所以：后不能有空格 
		int flag = 1; 
		while(card.size() != 1){
			if(flag){ cout << " "; flag = 0;}
			else cout << ", ";
			//弹出两个元素，并将最后一个元素插入队列尾
			cout << card.front();		//删除队头的元素 
			card.pop();
			
			card.push(card.front());	//将第二个元素加入队尾 
			card.pop();
			 
			
		}
		cout << endl;
		
		printf("Remaining card: ");
		cout << card.front() << endl;
		
		
		
	}
	
	
	
	
	
	
	return 0;
} 
