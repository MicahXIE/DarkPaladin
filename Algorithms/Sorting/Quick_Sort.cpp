/*
快速排序由C. A. R. Hoare在1962年提出，该算法是目前实践中使用最频繁，实用高效的最好排序算法，

快速排序算法是采用分治思想的算法，算法分三个步骤

1. 从数组中抽出一个元素作为基数v（我们称之为划界元素）,一般是取第一个、最后一个元素或中间的元素
2. 将剩余的元素中小于v的移动到v的左边，将大于v元素移动到v的右边
3. 对左右两个分区重复以上步骤直到所有元素都是有排序好。

快速排序算法的时间复杂度为O(nlogn)
ref: https://www.cnblogs.com/clc2008/p/6853060.html
*/

#include<iostream>
#include<algorithm>

using namespace std;

void exchange(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int a[], int start, int end){
	int key = a[end];
	//mark the biggest pos of the element less than key
	int i = start-1;

	for(int j=start; j<end; j++){
		if(a[j] <= key){
			i++;
			exchange(&a[i], &a[j]);
		}
	}

	exchange(&a[i+1],&a[end]);

	return (i+1);

}

void quickSort(int a[], int start, int end){
	int pos = 0;
	if(start < end){
		//find the pos of partition element
		pos = partition(a, start, end);
		//partition element left side
		quickSort(a, start, pos-1);
		//partition element right side
		quickSort(a, pos+1, end);
	}

}

int main(){
	int d[] = {6, 4, 1, 8, 7, 5};
	quickSort(d,0,5);

	for (int i=0; i<6; i++){
		cout << d[i] << " "; 
	}

	cout << endl;
}



