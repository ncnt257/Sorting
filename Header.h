#pragma once
#ifndef header_h
#define header_h

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;
bool checkSorted(int* a, int n);
void printArray(int* a, int n);
void GenerateRandomData(int* a, int n);
void GenerateSortedData(int* a, int n);
void GenerateReverseData(int* a, int n);
void GenerateNearlySortedData(int* a, int n);
void GenerateData(int*& a, int n, int dataType);
void selectionSort(int* a, int n);
void stableSelectionSort(int* a, int n);
void insertionSort(int* a, int n);
int binarySearch(int* a, int l, int r, int key);
void binaryInsertionSort(int* a, int n);
void bubbleSort(int* a, int n);
void improvedBubbleSort(int* a, int n);
void shakerSort(int* a, int n);
int partition(int* a, int low,int high);
void quickSort(int* a, int low, int high);
void shellSort(int* a, int n);
void heapify(int* a, int l,int h);
void heapSort(int* a, int n);
void mergeSort(int* a, int l,int r);
void merge(int* a, int l, int m, int r);
void countingSort(int* a, int n);
void countingSortforRS(int* arr, int n, int exp);
void radixSort(int* arr, int n);
#endif
