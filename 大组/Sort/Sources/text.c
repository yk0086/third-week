#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "text.h"
void GetRandNum(int Max)
{
	srand((unsigned)time(NULL));//�������� 
	int i,RandNum;
	FILE *fp = NULL;
	//����ļ� 
	fp = fopen("text.txt","w");
	fclose(fp);
	for(i = 0 ; i < Max ; i ++)
	{
		RandNum = rand();
		fp = fopen("text.txt","a");
		fprintf(fp,"%-6d",RandNum); //�������д���ļ�
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
		printf("����Ƿ�!\n����������Ҫ������!\n");
		scanf("%d",&num);
		judge = getchar();
	}
	return num;
}
void Menu(){
	printf("**     �����㷨�Ƚ�           **\n");
	printf("================================\n");
	printf("**     1 ---��������          **\n");
	printf("**     2 ---�鲢����          **\n");
	printf("**     3 ---��������(�ǵݹ�)  **\n");
	printf("**     4 ---��������          **\n");
	printf("**     5 ---��������          **\n");
	printf("**     6 ---��������(�ݹ�)    **\n");
	printf("**     7 ---�˳�����          **\n");
	printf("**     7 ---����              **\n");
	printf("================================\n");
	printf("\n");
}
//��������
int *CreatArray(Max){
	FILE *fp;
	int i,RandNum;
	fp = fopen("text.txt","r");
	int *arr = (int*)malloc(sizeof(int)*Max);
	for ( i = 0; i < Max; i++) {
		fscanf(fp,"%6d",&RandNum);//���ļ����ݶ���RandNum 
		arr[i] = RandNum;
		//printf("%-6d\n",arr[i]);
	}
	fclose(fp);
	return arr;
}
/*���ͽ���*/
void Swap(void *vp1,void *vp2,int size){  
    char buffer[size];
    memcpy(buffer,vp1,size);  
    memcpy(vp1,vp2,size);  
    memcpy(vp2,buffer,size);  
} 
//�Ż�����
/* 
void Good_QuickSort_Recursion(int *a, int begin, int end)
{
	//�жϹ�ģ 
	if(Cutoff<=begin-end){
		int i = begin;
		int j = end-1;
		int mid = (begin + end) / 2;
		//ȡͷ��β��λ��
		//int temp = getSecond(a[begin],a[end],a[mid]);
		//int temp = MID(a[begin],a[end],a[mid]);
		//printf("%d",temp);
		//�Ѿ���λ
		int pivot = Median3(a, begin, end);
		for(;;){
			//�ƶ��±� ,ֱ�����߶����������� 
			while(a[++i]<pivot);
			while(a[--j]>pivot);
			//�ж�ijλ��
			if(i<j) 
				Swap(&a[i],&a[j]);
			//�Ѿ�����һ����Ӧ�ý��� 
			else break;
		}
		//����Ԫλ�� 
		Swap(&a[i],&a[end-1]);
		Good_QuickSort_Recursion(a, begin, i-1);
		Good_QuickSort_Recursion(a, i+1, end);
	} 
	else
		insertSort(a+begin ,end - begin + 1);
}
*/
//ȡ��λ�� 
int Median3(int *a, int begin, int end)
{
	//����ִ������ 
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
	δ������ĵ�·
	��pivot�ص��ұ�,ʡ������Ԫ�� 
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

