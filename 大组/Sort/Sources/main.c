#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t start, stop;

int main()
{
	int i,num;
	int Max,*arr;
	Menu();
	
	while(1){
		
		printf("请输入要产生的随机数的个数:");
		Max = GetNumber();
		GetRandNum(Max);
		arr = CreatArray(Max);
		
		for(i=0;i<Max;i++){
			printf("arr[%d]=%d\t",i, arr[i]);
			if(i!=0 && i%5==0) printf("\n");
		}
		printf("\n");	
		printf("请选择排序算法：");
		num = GetNumber();
		start = clock();
		
		switch(num){	
			case 1 : insertSort(arr,Max); break;
			case 2 : {
				int *temp = (int*)malloc(sizeof(int)*Max);
				MergeSort(arr,0,Max-1,temp);
				free(temp);
				break;
			}
			case 3 :
				QuickSort_Recursion(arr, 0, Max-1);
				break;
			case 4 :
				CountSort(arr, Max, MaxNum(arr,Max));
				break; 
			case 5 :
				RadixCountSort(arr,Max);
				break;
			case 7 : exit(0);
			case 8 :
				system("pause");
				system("cls");
				break;
			case 9:
				//Good_QuickSort_Recursion(arr, 0, Max-1);
			default : printf("请输入[1,9]");break;
		}
		stop = clock();
		for(i=0;i<Max;i++){
			printf("arr[%d]=%d\t",i, arr[i]);
			if(i!=0 && i%5==0) printf("\n");
		}
		printf("\n\n");
		printf("insertSort duration = %6.2e\n", (double)(stop-start));
		system("pause");
		system("cls");
		Menu();
	
	}
	return 0;
}
