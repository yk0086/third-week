#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"
//插入排序
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
		}//若相同,则不交换位置,是稳定排序 
	}
}
//归并排序
void MergeSort(int *a,int begin,int end,int *temp)
{
	/*当这个数组里有参数时*/
	if(begin<end){
		int mid = (begin + end) / 2;
		//(分而)左边
		MergeSort(a, begin, mid, temp);
		//右边
		MergeSort(a, mid+1, end, temp);
		//合并(治之)
		MergeArray(a, begin, mid, end, temp);
	}
}
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i;
	/*左右两边终点位置*/
	int LeftEnd = mid-1;
	int RightEnd = end;
	/*元素从begin位置开始存放*/
	int tmp = begin;
	/*计算一共要归并多少个元素*/
	int Num = end-begin+1;
	/*当左右子序列都不为空*/
	while(begin<=LeftEnd && mid<=RightEnd){
		/*比较两边元素*/
		if(a[begin]<=a[mid]) temp[tmp++] = a[begin++];//等于号在这里是为了保证相对位置 
		else temp[tmp++] = a[mid++]; //哪边小先放哪边
	}
	/*把剩下的子序列放进去*/
	while(begin<=LeftEnd) temp[tmp++] = a[begin++]; 
	while(mid<=RightEnd) temp[tmp++] = a[mid++]; 
	/*改变a*/
	for(i=0;i<Num;i++){
		/*左边的位置已经丢失,故从右往左处理*/
		a[RightEnd--] = temp[RightEnd--];
	}
}
//快速排序  从小到大
void QuickSort_Recursion(int *a, int begin, int end)
{
	int i = begin;
	int j = end;
	//选择主元(中枢枢纽) 
	int temp = a[begin];
	if (i < j) {
		while(i < j){
			//从右向左去找比基准数小的元素
			while (i < j && a[j]>=temp){
				j--;
			}
			//填坑
			if (i < j) {
				a[i] = a[j];//将a[j]填到a[i]中，a[j]就形成了一个新的坑
				i++;
			}
			//从左向右 找比基准数大的数
			while (i < j && a[i] < temp) {
				i++;
			}
			//填坑
			if (i < j) {
				a[j] = a[i];//将a[i]填到a[j]中，a[i]就形成了一个新的坑
				j--;
			}
		}
		//对左半部分（递归）进行快速排序
		QuickSort_Recursion(a, begin, i - 1);
		//把基准数放到i=j的位置
		a[i] = temp;
		//对右部分（递归）进行快速排序
		QuickSort_Recursion(a, j + 1, end);
	}
}
/*计数排序*/
void CountSort(int *a, int size , int max)
{
	int *count_arr = (int *) malloc(sizeof(int) * max);
	int *sorted_arr = (int *) malloc(sizeof(int) * size);
    int i, j, k;
    /*所有桶里数据数目0*/
    for (k = 0; k < max; k++)
        count_arr[k] = 0;
    /*遍历填桶*/
    for (i = 0; i < size; i++)
        count_arr[a[i]]++;
    /*计算小于等于该值的元素个数*/
    for (k = 1; k < max; k++)
        count_arr[k] += count_arr[k - 1];
    /*倒序进行分配*/
    //这个元素和它前面放了多少个数,就知道它在排好的数组里应该放在哪个位置,倒叙则是为了保证两个以至更多的数相同的情况,先入后出
	for (j = size-1; j > 0; j--)
        sorted_arr[--count_arr[a[j]]] = a[j];
    for (i = 0; i < size; i++)
    	a[i] = sorted_arr[i];
    free(count_arr);
    free(sorted_arr);
}
/*基数排序*/
void RadixCountSort(int *a,int size)
{
	int i, max = a[0], base = 1;
	for (i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int *t = (int*)malloc(sizeof(int)*size);
	//位数由低到高 
	while (max / base > 0) {
		int bucket[10] = { 0 };
		//类似计数排序 
		for (i = 0; i < size; i++) {
			bucket[a[i] / base % 10]++;
		}
		
		for (i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		}
		for (i =size - 1; i>= 0; i--) {
			//通过某一位数找到某个数需要存放的位置 
			t[--bucket[a[i] / base % 10 ]] = a[i];
		}
		//将排好的返回去 
		for (i = 0; i < size; i++) {
			a[i] = t[i];
		}
		//位数升高 
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
		printf("输入非法!\n请重新输入要求内容!\n");
		scanf("%d",&num);
		judge = getchar();
	}
	return num;
}
void Menu(){
	printf("**排序算法比较(100个数据*100k次排序)**\n");
	printf("================================\n");
	printf("**        1 ---插入排序             **\n");
	printf("**        2 ---归并排序             **\n");
	printf("**        3 ---快速排序(非递归)     **\n");
	printf("**        4 ---计数排序             **\n");
	printf("**        5 ---基数排序             **\n");
//	printf("**        6 ---快速排序(递归)       **\n");
	printf("**        7 ---退出程序             **\n");
	printf("**        8 ---清屏                 **\n");
	printf("======================================\n");
	printf("\n");
}
/*泛型交换*/
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
