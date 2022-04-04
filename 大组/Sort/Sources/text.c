#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "text.h"
void GetRandNum(int Max)
{
	srand((unsigned)time(NULL));//先种种子 
	int i,RandNum;
	FILE *fp = NULL;
	//清空文件 
	fp = fopen("text.txt","w");
	fclose(fp);
	for(i = 0 ; i < Max ; i ++)
	{
		RandNum = rand();
		fp = fopen("text.txt","a");
		fprintf(fp,"%-6d",RandNum); //把随机数写进文件
		fclose(fp);
    }
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
	printf("**     排序算法比较           **\n");
	printf("================================\n");
	printf("**     1 ---插入排序          **\n");
	printf("**     2 ---归并排序          **\n");
	printf("**     3 ---快速排序(非递归)  **\n");
	printf("**     4 ---计数排序          **\n");
	printf("**     5 ---基数排序          **\n");
	printf("**     6 ---快速排序(递归)    **\n");
	printf("**     7 ---退出程序          **\n");
	printf("**     7 ---清屏              **\n");
	printf("================================\n");
	printf("\n");
}
//创建数组
int *CreatArray(Max){
	FILE *fp;
	int i,RandNum;
	fp = fopen("text.txt","r");
	int *arr = (int*)malloc(sizeof(int)*Max);
	for ( i = 0; i < Max; i++) {
		fscanf(fp,"%6d",&RandNum);//把文件数据读到RandNum 
		arr[i] = RandNum;
		//printf("%-6d\n",arr[i]);
	}
	fclose(fp);
	return arr;
}
/*泛型交换*/
void Swap(void *vp1,void *vp2,int size){  
    char buffer[size];
    memcpy(buffer,vp1,size);  
    memcpy(vp1,vp2,size);  
    memcpy(vp2,buffer,size);  
} 
//优化快排
/* 
void Good_QuickSort_Recursion(int *a, int begin, int end)
{
	//判断规模 
	if(Cutoff<=begin-end){
		int i = begin;
		int j = end-1;
		int mid = (begin + end) / 2;
		//取头中尾中位数
		//int temp = getSecond(a[begin],a[end],a[mid]);
		//int temp = MID(a[begin],a[end],a[mid]);
		//printf("%d",temp);
		//已经移位
		int pivot = Median3(a, begin, end);
		for(;;){
			//移动下标 ,直到两边都不满足条件 
			while(a[++i]<pivot);
			while(a[--j]>pivot);
			//判断ij位置
			if(i<j) 
				Swap(&a[i],&a[j]);
			//已经遍历一遍了应该结束 
			else break;
		}
		//换主元位置 
		Swap(&a[i],&a[end-1]);
		Good_QuickSort_Recursion(a, begin, i-1);
		Good_QuickSort_Recursion(a, i+1, end);
	} 
	else
		insertSort(a+begin ,end - begin + 1);
}
*/
//取中位数 
int Median3(int *a, int begin, int end)
{
	//必须执行三遍 
	int mid = (begin + end) / 2;
	if(a[begin]>a[end]){
		Swap(&a[begin],&a[end],sizeof(int));
	}
	if(a[begin]>a[mid]){
		Swap(&a[begin],&a[mid],sizeof(int));
	}
	if(a[mid]>a[end]){
		Swap(&a[mid],&a[end],sizeof(int));
	}
	/*
	未曾设想的道路
	将pivot藏到右边,省了三个元素 
	swap(&a[mid], &a[right-1]);
	*/
	return a[mid];
}
/*
int getSecond(int a,int b,int c){
    int max = a > b ? a : b;
    max = max > c ? max : c;
    int min = a < b ? a: b;
    min = min < c ? min : c;
    int second = a + b + c - max - min;
    return second;
}
*/
int MaxNum(int *a, int Max)
{
	int max = a[0],i;
	for(i=1;i<Max;i++){
		if(a[i]>max)
			max = a[i];
	}
	return max;
}

