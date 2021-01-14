#include "Header.h"

int main()
{
	clock_t start, end;
	double cpu_time_used;
	int* a;
	fstream outf;
	outf.open("data.csv");
	outf << "Data Order" << "," << "Data Size" << "," << "Algorithm" << "," << "Run time" << endl;
	int dts[5] = { 3000,10000,30000,100000,300000 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			for (int g = 0; g < 2; g++) {
				a = new int[dts[j]];
				GenerateData(a, dts[j], i);
				start = clock();
				switch (g)
				{
				case 0: {
					shellSort(a, dts[j]);
					break;
				}
				case 1: {
					shellSort1(a, dts[j]);
					break;
				}
				
				
				
				}
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
				outf << i << "," << dts[j] << "," << g << "," << cpu_time_used << endl;
				delete[]a;
			}
		}
	}
	outf.close();



    /*int n = 100;
    int* a = new int[n];
    GenerateData(a, n, 0);
    printArray(a, n);
    cout << "\n\n";
	mergeSort(a,0,n-1);
    printArray(a, n);
    if (checkSorted(a, n))
        cout << "SORTED!!!";
    else
        cout << "UNSORTED!!!";*/
}

