#include <stdio.h>

// 交换元素
void swap(int array[], int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

//冒泡排序，每一个元素都需要遍历一遍数组，满足条件时进行元素值交换，n2
void bubble_sort(int array[], int len){

	int i, j;
	for (i = 0; i < len - 1; i ++){
	    for (j = i + 1; j < len; j++){
		    if (array[i] > array[j]){
			    swap(array, i, j);
		    }
	    } 
    }
}

//插入排序
void insert_sort(int array[], int len){

	int i, j;
	for (i = 1; i < len; i++){
	    for (j = i; j > 0 && array[j] < array[j-1]; j--){
		    swap(array, j, j-1);
	    }
    }
}

// 选择排序,每一个元素都需要遍历一遍数组，满足条件时交换下标，最后进行不同下标的元素交换，n2
void select_sort(int array[], int len){
	int i, j, lowindex;

    for (i = 0; i < len-1; i++){
	    lowindex = i;
	    // 满足条件时交换下标
	    for (j = len-1; j > i; j--){
		    if (array[j] < array[lowindex]){
			    lowindex = j;
		    }
	    }
	    // 下标改变则交换元素值
	    if (lowindex != i){
    		swap(array, lowindex, i);
	    }
    }
}

// Shell排序，
首先将待排序序列变成基本有序的，再使用插入排序
void shell_sort(int array[], int len){
	int gap, i, j;

	// 将数组变为基本有序
    for (gap = len/2; gap > 1; gap /= 2){
    	for (i = gap; i < len; i ++){
    		for (j = i - gap; j >= 0; j -= gap){
    			if (array[j] > array[j + gap]){
    				swap(array, j, j+gap);
    			}
    		}
    	}
    }
    
    // 当gap=1时，使用插入排序
    for (i = 1; i < len; i++) {
        for (j = i; j > 0; j--) {
            if (array[j] < array[j-1]) {
        	    swap(array, j-1, j);
        	} else {
        		break;  // 不再上升则退出循环
        	}
        }
    }
}

int partition(int s[], int begin, int end){

	int pivot = s[end];  // 权值
	int low = begin;  // 初始下标
	int high = end;  // 结束下标

	while (low < high){
		while (low < high && s[low] < pivot)
			low++;
		while (low < high && s[high] >= pivot)
			high--;
		// 将右边的大于权值的值与左边的小于权值的值进行交换
		if (low < high){
			swap(array, low, high);
		}
	}

	// 将权值和中间的值交换，保证中间值右边的都小于它，左边的都大于它
	swap(s, low, end);
	return low;
}

// 快速排序
void quick_sort(int s[], int begin, int end){
	if (begin < end){
		int p = partition(s, begin, end);
		quick_sort(s, begin, p-1);
		quick_sort(s, p+1, end);
	}
}


int main() {
	int array[] = {1, 3, 5, 9, 33, 4, 8, 22, 8, 12};
    int len = sizeof(array)/sizeof(int);
    
    //bubble_sort(array, len);
    //insert_sort(array, len);
    //select_sort(array, len);
    quick_sort(array, 0, len-1);
    // shell_sort(array, len);

    printf("%d\n", len);
    for (int i = 0; i < len; i++){
    	printf("%d\n", array[i]);
    }
	return 0;
}