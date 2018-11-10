#include<stdio.h>
//数组作为返回参数
/*
int sum(int a[]){//其实把数组作为参数传递给函数时，实际上只有数组的首地址作为指针传给了函数。int a[]相当于int* a; 
	int ans=0;
	printf("%d\n",sizeof(a));//虽然sizeof(a)有值，但是这种传递方式不太正确 
	for(int i=0;i<sizeof(a);i++)
		ans+=a[i];
	return ans; 
	
} 
int main(){
	int a[]={1,2,3,4,5,6,7,3};
	int ans=sum(a);
	printf("%d\n",ans);
		
	return 0;
}
//正确的做法
int sum(int* a,int n){
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=a[i];//与*(a+i)等价 
	return ans;
	
} 
int main(){
	int a[]={1,2,3,4,5,6,7,3};
	//当实参时数组的时候，传递给形参时，不用写成&a，这样反而会报错，因为数组a传递的本来就是a的首地址（可以用指针的加减法把其他元素的首地址传递给函数） 
	int ans=sum(a+1,7);//a指向a[0];a+1指向a[1] 
	printf("%d\n",ans);//输出：30 
	
	return 0;

*/

//计算左闭右开区间内的元素和
/* 
//第一种 
int sum(int* begin,int* end){
	int ans=0; 
	//for(int i=0;i<end;i++){//i不能和指针比较 
		//ans+=*(begin+i)
	//}
	
	int n=end-begin;//这样赋值时可以的(两者相加减)
	for(int i=0;i<n;i++){
		ans+=begin[i];//*(begin+i)，可以直接当数组来用 
	} 
	
	//int n=end;//报错，不能把指针地址赋值给int型 
	//for(int i=begin;i<n;i++){//报错 
	//	ans+=*begin;
	//} 
	return ans;	
} 
//第二种
int sum(int* begin,int* end){
	int ans=0;
	for(int *p=begin;p!=end;p++)//用指针地址做循环变量 
		ans+=*p;
	
	return ans;
} 

int main(){
	int a[]={1,2,3,4,5,6,7,3};
	printf("%d",sum(a+1,a+7)); 
	
	return 0;
}
*/ 
/* 
//测试，修改数组元素里的值
void Change(int* a,int n){
	a[n]=6;
	
	return;
	
} 
int main(){
	int a[]={1,2,3,4,5,6,7};
	Change(a,2);//可以改变数组内容 
	printf("%d\n",sizeof(a));//这里的sizeof(a)的值不是7，是28，说明a[]={}赋值，数组中的元素个数不确定 
	printf("%d\n",a[2]);

}
*/ 
