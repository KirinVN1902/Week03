#ifndef FUNC_H
#define FUNC_H
#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <time.h>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
template <class T>
void HoanVi(T &a, T &b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
void swap(int &x, int &y);
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
void shakerSort(int a[], int n);
void shellSort(int a[], int n);
void heapify(int a[], int n, int i);
void heapSort(int a[], int n);
void merge(int a[], int l, int m, int r);
void mergeSoft(int a[], int l, int r);
int partition(int a[], int n, int l, int r);
void quickSort(int a[], int n, int l, int r);
void countingSort(int a[], int n);
void countingSortForRadixSort(int a[], int n, int exp);
int maxDigit(int a[], int n);
void radixSort(int a[], int n);
void typeToSort(int a[], int n, string type);
void flashSort(int a[], int n);
#endif