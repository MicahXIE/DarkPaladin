#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

/*
size_t是一种无符号的整型数，它的取值没有负数，在数组中也用不到负数，而它的取值范围是整型数的双倍。
sizeof操作符的结果类型是size_t，它在头文件中typedef为unsigned int类型。
该类型保证能容纳实现所建立的最大对象的字节大小。

//模版类定义，一个是虚拟类型T，用来给定数组元素的类型，一个是整型值size，用来给定数组的大小，即元素个数
//此类是一个万能数组，数组类型可以任意给定，数组大小可任意给定
//模板类不仅可以传递类型T，也可以传递数值size
template <class T,int size>
class Array
{
... 
}
*/

template<size_t size_x, size_t size_y>
void fill_connected_block(int (&mat)[size_x][size_y], int x, int y) {
	if (mat[x][y] == 0)
		return;

    // very clever trick
	mat[x][y] = 0;

	if(x + 1 < size_x)
		fill_connected_block(mat, x+1, y);

	if(x - 1 >= 0)
		fill_connected_block(mat, x-1, y);

	if(y + 1 < size_y)
		fill_connected_block(mat, x, y+1);

	if(y - 1 >= 0)
		fill_connected_block(mat, x, y-1);
}

template<size_t size_x, size_t size_y>
int count_island(int (&mat)[size_x][size_y]) {
	int num_island = 0;

	for (int i = 0; i < size_x; i++){
		for (int j = 0; j < size_y; j++) {
			if(mat[i][j] == 1){
				num_island++;
				fill_connected_block(mat, i, j);
			}
		}
	}

	return num_island;
}

int main() {
	int mat[5][5] = {
        {1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1} 
	};

	int num_island = count_island(mat);
	cout << "number of island is: " << num_island << endl;
}