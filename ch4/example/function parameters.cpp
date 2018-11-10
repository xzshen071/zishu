//将一个函数传递给另一个函数
//C语言中的快速排序程序（qsort）
#include<stblib.h>//在此声明中
//qsort的是声明
//参数说明：待排序的数组起始地址、元素个数和每个元素的大小、指向函数的指针； 
void qsort(void* base,size_t num,size_t size,int (* comparator)(const void*, const void*)); 
//该函数具有的形式
//参数说明：const void* 是指向常数的万能指针，如果排序的对象是整形数组，则 
int cmp(const void *a, const void *b){//int* a和int *a没有区别，定义的时候建议写成int *a 
	return *(int*)a - *(int*)b;//强制转换成int*类型，若*a>*b则返回1，等于返回0，小于返回负数 
	 
} 
//将一个函数作为参数传递给另外一个函数很有用 
