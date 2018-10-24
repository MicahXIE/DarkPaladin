/*
冒泡法： 这是最原始，也是众所周知的最慢的算法了。 ...
直接插入排序：O(n*n)
选择排序：O(n*n)
快速排序：平均时间复杂度log2(n)*n，所有内部排序方法中最高好的，大多数情况下总是最好的。
归并排序：log2(n)*n.
堆排序：O(n*log(2n)).  
希尔排序：算法的复杂度为n的1.2次幂

堆排序：
完全二叉树，最适用找出数组中前几个最大／最小值

i节点的父节点 parent(i) = floor((i-1)/2)
i节点的左子节点 left(i) = 2i + 1
i节点的右子节点 right(i) = 2i + 2

步骤
构造最大堆（Build Max Heap）：首先将当前元素放入最大堆下一个位置，然后将此元素依次和它的父节点比较，如果大于父节点就和父节点交换，
直到比较到根节点。重复执行到最后一个元素。

最大堆调整（Max Heapify）：调整最大堆即将根节点移除后重新整理堆。整理方法为将根节点和最后一个节点交换，然后把堆看做n-1长度，
将当前根节点逐步移动到其应该在的位置。

堆排序（HeapSort）：重复执行2，直到所有根节点都已移除。


堆排序：O(n*log(2n)). T(n) <= O(n) + (n-1)*O(log(2n)) = O(n*log(2n))
构造最大堆 O(n)
n-1次调整堆 (n-1)*O(log(2n))

reference:
http://yansu.org/2015/09/07/sort-algorithms.html
https://www.cnblogs.com/MOBIN/p/5374217.html

*/


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//debug usage
void print_vec(vector<int> &nums){

	for(auto hp_iter = nums.begin(); hp_iter != nums.end(); hp_iter++){
		cout << *hp_iter << " ";
	}
	cout << endl;

}

//max heapify
void max_heapify(vector<int> &nums, int beg, int end) {
	int curr = beg;
	int child = curr * 2 + 1;

	while (child < end) {
		if(child + 1 <= end && nums[child] < nums[child+1]) {
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

void heap_sort(vector<int> &nums){
	int n = nums.size();

	//build max heap
	for(int i = n/2 - 1; i >= 0; i--) {
		max_heapify(nums, i, nums.size()-1);
	}

	print_vec(nums);

	cout << endl;
	

	//heap sort
	for(int i=n-1; i>0; i--){
		int temp = nums[i];
		nums[i] = nums[0];
		nums[0] = temp;

		print_vec(nums);
		
		max_heapify(nums, 0, i-1);
	}

	cout << endl;
}


int main(){
	int a[] = {20,50,20,40,70,10,60,30,80};
	vector<int> v;
	v.insert(v.begin(), a, a+9);
	heap_sort(v);

	for(auto iter=v.begin(); iter != v.end(); iter++){
		cout << *iter << " ";
	}

	cout << endl;

}