//��һ���������ݸ���һ������
//C�����еĿ����������qsort��
#include<stblib.h>//�ڴ�������
//qsort��������
//����˵�����������������ʼ��ַ��Ԫ�ظ�����ÿ��Ԫ�صĴ�С��ָ������ָ�룻 
void qsort(void* base,size_t num,size_t size,int (* comparator)(const void*, const void*)); 
//�ú������е���ʽ
//����˵����const void* ��ָ����������ָ�룬�������Ķ������������飬�� 
int cmp(const void *a, const void *b){//int* a��int *aû�����𣬶����ʱ����д��int *a 
	return *(int*)a - *(int*)b;//ǿ��ת����int*���ͣ���*a>*b�򷵻�1�����ڷ���0��С�ڷ��ظ��� 
	 
} 
//��һ��������Ϊ�������ݸ�����һ������������ 
