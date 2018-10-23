/*
冒泡法： 这是最原始，也是众所周知的最慢的算法了。 ...
直接插入排序：O(n*n)
选择排序：O(n*n)
快速排序：平均时间复杂度log2(n)*n，所有内部排序方法中最高好的，大多数情况下总是最好的。
归并排序：log2(n)*n.
堆排序：log2(n)*n.
希尔排序：算法的复杂度为n的1.2次幂

堆排序：
i节点的父节点 parent(i) = floor((i-1)/2)
i节点的左子节点 left(i) = 2i + 1
i节点的右子节点 right(i) = 2i + 2

步骤
构造最大堆（Build Max Heap）：首先将当前元素放入最大堆下一个位置，然后将此元素依次和它的父节点比较，如果大于父节点就和父节点交换，
直到比较到根节点。重复执行到最后一个元素。

最大堆调整（Max Heapify）：调整最大堆即将根节点移除后重新整理堆。整理方法为将根节点和最后一个节点交换，然后把堆看做n-1长度，
将当前根节点逐步移动到其应该在的位置。

堆排序（HeapSort）：重复执行2，直到所有根节点都已移除。


reference:
http://yansu.org/2015/09/07/sort-algorithms.html
https://www.cnblogs.com/MOBIN/p/5374217.html

*/


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//max heapify
void max_heapify(vector<int> &nums, int beg, int end) {
	int curr = beg;
	int child = curr * 2 + 1;

	while (child < end) {
		if(child + 1 < end && nums[child] < nums[child+1]) {
			child++;
		}

		if(nums[curr] < nums[child]) {
			int temp = nums[curr];
			nums[curr] = nums[child];
			nums[child] = temp;
			curr = child;
			child = 2 * curr + 1;
		} else {
			break;
		}

	}
}

//build max heap
void heap_sort(vector<int> &nums){
	int n = nums.size();
	for(int i = n/2 - 1; i >= 0; i--) {
		max_heapify(nums, i, nums.size()-1);
	}

	for(int i=n-1; i>0; i--){
		int temp = nums[i];
		nums[i] = nums[0];
		nums[0] = temp;
		max_heapify(nums, 0, i);
	}
}


int main(){
	int a[] = {20,50,20,40,70,10,80,30,60};
	vector<int> v;
	v.insert(v.begin(), a, a+9);
	heap_sort(v);

	for(auto iter=v.begin(); iter != v.end(); iter++){
		cout << *iter << " ";
	}

	cout << endl;

}