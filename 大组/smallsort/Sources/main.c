#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 100 
clock_t start, stop;

int main()
{
	int i,num;
	int Max,*arr;
	Menu();
	Max = MAX;
	while(1){
		
		printf("\n");	
		printf("«Î—°‘Ò≈≈–ÚÀ„∑®£∫");
		num = GetNumber();
		start = clock();
		int cnt = 0;
		switch(num){	
			case 1 : while(cnt!=1000){
				arr = CreatArray(Max);
				insertSort(arr,Max);
				cnt++;
			} break;
			case 2 : while(cnt!=1000){
				arr = CreatArray(Max);
				int *temp = (int*)malloc(sizeof(int)*Max);
				MergeSort(arr,0,Max-1,temp);
				free(temp);
				cnt++;
			}break;
			case 3 :while(cnt!=1000){
				arr = CreatArray(Max);
				QuickSort_Recursion(arr, 0, Max-1);
				cnt++;
			}break;
			case 4 :while(cnt!=1000){
				arr = CreatArray(Max);
				CountSort(arr, Max, MaxNum(arr,Max));
				cnt++;
			}break; 
			case 5 :
				while(cnt!=1000){
				arr = CreatArray(Max);	
				RadixCountSort(arr,Max);
				cnt++;
			}break;
			case 6 : exit(0);
			case 7 :
				system("pause");
				system("cls");
				break;
			default : printf("«Î ‰»Î[1,7]");break;
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
