#include<iostream>
#include<vector>

//归并排序算法，分两步进行，分以及合


//合并两个有序数组(任意长度)的算法
void MergeArray(std::vector<int>& array,std::vector<int>&temp,int left,int mid,int right){ 
	

	int i = left; //左半区间的起始索引
	int j = mid + 1; //右半区间的起始索引
	int k = left; 

	while (i <= mid && j <= right) {
		if (array[i] < array[j]) {
			temp[k] = array[i];
			k++;
			i++;
		}
		else {
			temp[k] = array[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		temp[k] = array[i];
		k++;
		i++;
	}
	while (j <= right) {
		temp[k] = array[j];
		k++;
		j++;
	}


	for (int p = left; p <= right; p++) {

		array[p] = temp[p];
	}



}


void DivideSort(std::vector<int>& array,std::vector<int>& temp, int left, int right) {

	if (left >= right) {
		return;
	}
	
	int mid = left + (right - left) / 2;

	DivideSort(array, temp,left, mid);
	DivideSort(array, temp,mid + 1, right);

	MergeArray(array, temp,left, mid, right);//合并两个有序数组

}


int main() {
	std::vector<int> arr = { 38,27,43,3,9,82,10 };
	std::vector<int> temp(arr.size());
	int left = 0;
	int right = arr.size() - 1;
	DivideSort(arr, temp, left, right);
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}