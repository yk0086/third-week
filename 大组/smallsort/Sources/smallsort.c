#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"
//��������
void insertSort(int *a,int n){
	int i;
	
	for (i = 0; i < n; i++) {
		
		int min = i, j;
		
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}			
		}
		if (min != i) {
			Swap(&a[min],&a[i],sizeof(int));
		}//����ͬ,�򲻽���λ��,���ȶ����� 
	}
}
//�鲢����
void MergeSort(int *a,int begin,int end,int *temp)
{
	/*������������в���ʱ*/
	if(begin<end){
		int mid = (begin + end) / 2;
		//(�ֶ�)���
		MergeSort(a, begin, mid, temp);
		//�ұ�
		MergeSort(a, mid+1, end, temp);
		//�ϲ�(��֮)
		MergeArray(a, begin, mid, end, temp);
	}
}
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i;
	/*���������յ�λ��*/
	int LeftEnd = mid-1;
	int RightEnd = end;
	/*Ԫ�ش�beginλ�ÿ�ʼ���*/
	int tmp = begin;
	/*����һ��Ҫ�鲢���ٸ�Ԫ��*/
	int Num = end-begin+1;
	/*�����������ж���Ϊ��*/
	while(begin<=LeftEnd && mid<=RightEnd){
		/*�Ƚ�����Ԫ��*/
		if(a[begin]<=a[mid]) temp[tmp++] = a[begin++];//���ں���������Ϊ�˱�֤���λ�� 
		else temp[tmp++] = a[mid++]; //�ı�С�ȷ��ı�
	}
	/*��ʣ�µ������зŽ�ȥ*/
	while(begin<=LeftEnd) temp[tmp++] = a[begin++]; 
	while(mid<=RightEnd) temp[tmp++] = a[mid++]; 
	/*�ı�a*/
	for(i=0;i<Num;i++){
		/*��ߵ�λ���Ѿ���ʧ,�ʴ���������*/
		a[RightEnd--] = temp[RightEnd--];
	}
}
//��������  ��С����
void QuickSort_Recursion(int *a, int begin, int end)
{
	int i = begin;
	int j = end;
	//ѡ����Ԫ(������Ŧ) 
	int temp = a[begin];
	if (i < j) {
		while(i < j){
			//��������ȥ�ұȻ�׼��С��Ԫ��
			while (i < j && a[j]>=temp){
				j--;
			}
			//���
			if (i < j) {
				a[i] = a[j];//��a[j]�a[i]�У�a[j]���γ���һ���µĿ�
				i++;
			}
			//�������� �ұȻ�׼�������
			while (i < j && a[i] < temp) {
				i++;
			}
			//���
			if (i < j) {
				a[j] = a[i];//��a[i]�a[j]�У�a[i]���γ���һ���µĿ�
				j--;
			}
		}
		//����벿�֣��ݹ飩���п�������
		QuickSort_Recursion(a, begin, i - 1);
		//�ѻ�׼���ŵ�i=j��λ��
		a[i] = temp;
		//���Ҳ��֣��ݹ飩���п�������
		QuickSort_Recursion(a, j + 1, end);
	}
}
/*��������*/
void CountSort(int *a, int size , int max)
{
	int *count_arr = (int *) malloc(sizeof(int) * max);
	int *sorted_arr = (int *) malloc(sizeof(int) * size);
    int i, j, k;
    /*����Ͱ��������Ŀ0*/
    for (k = 0; k < max; k++)
        count_arr[k] = 0;
    /*������Ͱ*/
    for (i = 0; i < size; i++)
        count_arr[a[i]]++;
    /*����С�ڵ��ڸ�ֵ��Ԫ�ظ���*/
    for (k = 1; k < max; k++)
        count_arr[k] += count_arr[k - 1];
    /*������з���*/
    //���Ԫ�غ���ǰ����˶��ٸ���,��֪�������źõ�������Ӧ�÷����ĸ�λ��,��������Ϊ�˱�֤�����������������ͬ�����,������
	for (j = size-1; j > 0; j--)
        sorted_arr[--count_arr[a[j]]] = a[j];
    for (i = 0; i < size; i++)
    	a[i] = sorted_arr[i];
    free(count_arr);
    free(sorted_arr);
}
/*��������*/
void RadixCountSort(int *a,int size)
{
	int i, max = a[0], base = 1;
	for (i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int *t = (int*)malloc(sizeof(int)*size);
	//λ���ɵ͵��� 
	while (max / base > 0) {
		int bucket[10] = { 0 };
		//���Ƽ������� 
		for (i = 0; i < size; i++) {
			bucket[a[i] / base % 10]++;
		}
		
		for (i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		}
		for (i =size - 1; i>= 0; i--) {
			//ͨ��ĳһλ���ҵ�ĳ������Ҫ��ŵ�λ�� 
			t[--bucket[a[i] / base % 10 ]] = a[i];
		}
		//���źõķ���ȥ 
		for (i = 0; i < size; i++) {
			a[i] = t[i];
		}
		//λ������ 
		base = base * 10;
	}
}
int *CreatArray() {
	int i;
	int *arr = (int*)malloc(sizeof(int)*MAX);
	srand((unsigned int)time(NULL));
	for (i = 0; i < MAX; i++) {

		int randNum = rand() % MAX;
		arr[i] = randNum;
	}
	return arr;
}
int GetNumber()
{
	int num, judge, flag;

	flag = scanf("%d",&num);
	judge = getchar();
	while(judge != '\n'){ 
		fflush(stdin);
		printf("����Ƿ�!\n����������Ҫ������!\n");
		scanf("%d",&num);
		judge = getchar();
	}
	return num;
}
void Menu(){
	printf("**�����㷨�Ƚ�(100������*100k������)**\n");
	printf("================================\n");
	printf("**        1 ---��������             **\n");
	printf("**        2 ---�鲢����             **\n");
	printf("**        3 ---��������(�ǵݹ�)     **\n");
	printf("**        4 ---��������             **\n");
	printf("**        5 ---��������             **\n");
//	printf("**        6 ---��������(�ݹ�)       **\n");
	printf("**        7 ---�˳�����             **\n");
	printf("**        8 ---����                 **\n");
	printf("======================================\n");
	printf("\n");
}
/*���ͽ���*/
void Swap(void *vp1,void *vp2,int size){  
    char buffer[size];
    memcpy(buffer,vp1,size);  
    memcpy(vp1,vp2,size);  
    memcpy(vp2,buffer,size);  
} 
int MaxNum(int *a, int Max)
{
	int max = a[0],i;
	for(i=1;i<Max;i++){
		if(a[i]>max)
			max = a[i];
	}
	return max;
}
