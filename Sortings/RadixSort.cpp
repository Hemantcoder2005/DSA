#include <iostream>
#include<climits>
using namespace std;

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int getMax(int* arr, int size) {
    int max = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int getMin(int* arr, int size) {
    int min = INT_MAX; // Initialize min to maximum possible value
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
void countSort(int* arr, int size, int exp) {
    int output[size];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[] so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int* radixSort(int* arr, int size) {
	int min=getMin(arr,size);
	if (min <0){
		for (int  i = 0; i < size; i++)
		{
			arr[i]-=min;
		}
	}
	    int max = getMax(arr, size);

	
    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, size, exp);
    }

	if(min<0){
		for (int  i = 0; i < size; i++)
		{
			arr[i]+=min;
		}

	}

    return arr;
}

int main() {
    int size = 8;
    int arr[size] = {-81, -82, -74, -72, -65, -61, -54, 1};
    cout << "Before Sort = ";
    print(arr, size);
    cout << endl;

    // Radix Sort
    int* SortedArr = radixSort(arr, size);
    cout << "After Sorting = ";
    print(SortedArr, size);

    return 0;
}
