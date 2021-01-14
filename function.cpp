#include "Header.h"
bool checkSorted(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}
void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Array[" << i << "] = " << a[i];
		cout << endl;
	}
}
void GenerateRandomData(int* a, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
void GenerateSortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
void GenerateReverseData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void GenerateNearlySortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		int temp;
		temp = a[r1];
		a[r1] = a[r2];
		a[r2] = temp;
	}
}
void GenerateData(int*& a, int n, int dataType)
{
	switch (dataType)
	{
	case 0:
		GenerateRandomData(a, n);
		break;
	case 1:
		GenerateSortedData(a, n);
		break;
	case 2:
		GenerateReverseData(a, n);
		break;
	case 3:
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Chi nhap cac so co trong Menu!\n");
	}
}
void selectionSort(int* a, int n)
{
	int min;
	for (int j = 0; j < n; j++)
	{
		min = j;
		for (int i = j+1; i < n; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		swap(a[min], a[j]);
		
	}
}
void stableSelectionSort(int* a, int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		int key = a[min];
		for (int k = min; k > i; k--)
		{
			a[k] = a[k-1];
		}
		a[i] = key;
	}
}
void insertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int key = a[i];
		while (key < a[j] && j>0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j] = key;
	}
}
int binarySearch(int* a, int l,int r, int key)
{
	if (r < l)
	{
		if (a[r] < key)
			return r + 1;
		return r;
	}
	int m = (l + r) / 2;
	if (key == a[m])
		return m;
	if (key > a[m])
		return binarySearch(a, m + 1, r, key);
	return binarySearch(a, l, m - 1, key);
}
void binaryInsertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int key = a[i];
			int j = binarySearch(a, 0, i - 1, a[i]);
			for (int k = i; k > j; k--)
				a[k] = a[k - 1];
			a[j] = key;
		}
	}
}
void bubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);	
			}

		}
	}
}
void improvedBubbleSort(int* a, int n)
{
	bool swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
void shakerSort(int* a, int n)
{
	bool swapped = true;
	int start = 0, end = n;
	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		end--;
		for (int i = end; i > start; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				swapped = true;
			}
		}
		start++;
	}
}
int partition(int* a, int low,int high)
{
	int pivot = high-1;
	int j = low - 1;
	for (int i = low; i < high-1; i++)
	{
		if (a[i]<a[pivot])
		{
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[j+1], a[pivot]);
	return j+1;
}
void quickSort(int* a, int low,int high)
{
	if (low < high)
	{
		int pivot = partition(a, low, high);
		quickSort(a, low, pivot);
		quickSort(a, pivot+1, high);
	}

}
void shellSort(int* a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int key = a[i];
			int j;
			for (j = i; j >= gap && key < a[j - gap]; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = key;
		}
	}
}
void heapify(int* a, int n,int max)
{
	int temp = max;
	if (max * 2 + 1 <n&&a[temp] < a[max * 2 + 1])
	{
		temp = max * 2 + 1;
	}
	if (max * 2 + 2 < n&&a[temp] < a[max * 2 + 2])
	{
		temp = max * 2 + 2;
	}
	if (temp != max)
	{
		swap(a[temp], a[max]);
		heapify(a, n, temp);
	}
}
void heapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = 1; i < n; i++)
	{
		swap(a[0], a[n-i]);
		heapify(a, n -i, 0);
	}
}
void merge(int* a, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int* temp1 = new int[n1];
	int* temp2 = new int[n2];
	for (int i = 0; i < n1; i++)
	{
		temp1[i] = a[l+i];
	}
	for (int i = 0; i < n2; i++)
	{
		temp2[i] = a[m + i + 1];
	}
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (temp1[i] <= temp2[j])
		{
			a[k] = temp1[i];
			i++;
		}
		else
		{
			a[k] = temp2[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = temp1[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = temp2[j];
		j++;
		k++;
	}
	delete[] temp1;
	delete[] temp2;
}
void mergeSort(int* a, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}
void countingSort(int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	int m = max + 1;
	int* countArr = new int[m];
	for (int i = 0; i < m; i++)
	{
		countArr[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i]]++;
	}
	for (int i = 1; i < m; i++)
	{
		countArr[i] += countArr[i - 1];
	}
	int* temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[countArr[arr[i]] - 1] = arr[i];
		countArr[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
	delete[]temp;
	delete[]countArr;
}
void countingSortforRS(int* arr, int n, int exp)
{

	int countArr[10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		countArr[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		countArr[i] += countArr[i - 1];
	}
	int* temp = new int[n];
	for (int i = n - 1; i >= 0; i--)//reverse lai
	{
		temp[countArr[arr[i] / exp % 10] - 1] = arr[i];
		countArr[arr[i] / exp % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
	delete[]temp;
}
void radixSort(int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	for (int i = 1; max / i > 0; i *= 10)
	{
		countingSortforRS(arr, n, i);
	}
}





















//void merge(int* a, int l,int m, int r)
//{						//0 1 2 3 4 5 6
//	int n1 = m - l + 1; //      l   m r
//	int n2 = r - m;     //1 2 3 4 5 6 7
//						// n1=4 n2=3
//	int* temp1 = new int[n1];
//	int* temp2 = new int[n2];
//	for (int i = 0; i < n1; i++)
//	{
//		temp1[i] = a[i+l];
//	}
//	for (int i = 0; i < n2; i++)
//	{
//		temp2[i] = a[i +m+1];
//	}
//	int i = 0, j = 0, k = l;
//	while (i < n1 && j < n2)
//	{
//		if (temp1[i] <= temp2[j])
//		{
//			a[k] = temp1[i];
//			i++;
//			k++;
//		}
//		else
//		{
//			a[k] = temp2[j];
//			j++;
//			k++;
//		}
//	}
//	if (i < n1)
//	{
//		for (i; i < n1; i++)
//		{
//			a[k] = temp1[i];
//			k++;
//		}
//	}
//	else if(j<n2)
//	{	
//		for (j; j < n2; j++)
//		{
//			a[k] = temp2[j];
//			k++;
//		}
//	}
//
//}
//void mergeSort(int* a, int l,int r)
//{
//	if (l < r)
//	{
//		int m;
//		m = (l + r) / 2;
//		mergeSort(a, l, m);
//		mergeSort(a, m + 1, r);
//		merge(a, l, m, r);
//	}
//	
//
//}