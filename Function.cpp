#include "Function.h"
using namespace std;
template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}
void selectionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int minPos = i;
        for (int j = i + 1; j < n; j++){
            if(a[j] < a[minPos]){
                minPos = j;
            }
        }
        swap(a[i], a[minPos]);
    }
}
void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int curNum = a[i];
        for (int j = i - 1; j >= 0; j--){
            if(curNum < a[j]){
                a[j + 1] = a[j];
                if(j == 0){
                    a[j] = curNum;
                }
            }
            else{
                a[j + 1] = curNum;
                break;
            }
        }
    }
}
void bubbleSort(int a[], int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void shakerSort(int a[], int n){
    int left = 0, right = n - 1, k = 0;
    while (left < right){
        for (int i = left; i < right; i++){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;
        for (int i = right; i > left; i--){
            if(a[i] < a[i - 1]){
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}
void shellSort(int a[], int n){
    int dis = 1;
    while(dis < n){
        dis = dis * 3 + 1;
    }
    while(dis > 0){
        for (int i = dis; i < n; i++){
            int tmp = a[i];
            int j = i;
            while(j >= dis && a[j - dis] > tmp){
                a[j] = a[j - dis];
                j -= dis;
            }
            a[j] = tmp;
        }
        dis = (dis - 1) /3;
    }
}
void heapify(int a[], int n, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if(left <= n - 1 && a[left] > a[largest]){
        largest = left;
    }
    if(right <= n - 1 && a[right] > a[largest]){
        largest = right;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
void merge(int a[], int l, int m, int r){
    vector<int> vl(a + l, a + m + 1);
    vector<int> vr(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < vl.size() && j < vr.size()){
        if(vl[i] <= vr[j]){
            a[l] = vl[i];
            l++; i++;
        }
        else{
            a[l] = vr[j];
            l++; j++;
        }
    }
    while(i < vl.size()){
        a[l] = vl[i];
        l++; i++;
    }
    while(l < vr.size()){
        a[l] = vr[j];
        l++; j++;
    }
}
void mergeSoft(int a[], int l, int r){
    if(l >= r){
        return;
    }
    int m = l + (r - l) / 2;
    mergeSoft(a, l, m);
    mergeSoft(a, m + 1, r);
    merge(a, l, m, r);
}
int partition(int a[], int n, int l, int r){
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(i < j){
        do{
            i++;
        } while (a[i] < pivot && i <= r);
        do{
            j--;
        } while (a[j] > pivot && j >= l);
        if(i < j){
            swap(a[i], a[j]);
        }
        else{
            return j;
        }
    }
}
void quickSort(int a[], int n, int l, int r){
    if(l >= r) return;
    int p = partition(a, n, l, r);
    quickSort(a, n, l, p);
    quickSort(a, n, p + 1, r);
}
void countingSort(int a[], int n){
    int b[500000] = {0};
    for (int i = 0; i < n; i++){
        b[a[i]]++;
    }
    int index = 0;
    for (int i = 0; i < 500000; i++){
        while(b[i] > 0){
            a[index] = i;
            index++;
            b[i]--;
        }
    }
}
void countingSortForRadixSort(int a[], int n, int exp){
    int count[10] = {0};
    int output[100];
    for (int i = 0; i < n; i++){
        count[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--){
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++){
        a[i] = output[i];
    }
}
int maxDigit(int a[], int n){
    int res = 0;
    int max = a[0];
    for (int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    while(max != 0){
        res++;
        max /= 10;
    }
    return res;
}
void radixSort(int a[], int n){
    int max = maxDigit(a, n);
    int exp = 1;
    for (int i = 1; i <= max; i++){
        countingSortForRadixSort(a, n, exp);
        exp *= 10;
    }
}
void flashSort(int a[], int n){
    int max = a[0], min = a[0];
    int maxIndex = 0;
    for (int i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
            maxIndex = i;
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    int bucket = 0.43 * n;
    if(bucket < 2){
        bucket = 2;
    }
    int *cnt = new int [bucket];
    for (int i = 0; i < n; i++){
        int k = ((a[i] - min) * (bucket - 1)) / (max - min);
        cnt[k]++;
    }
    for (int i = 0; i < n - 1; i++){
        cnt[i + 1] += cnt[i];
    }
    swap(a[0], a[maxIndex]);
    int move = 0, j = 0, stage = bucket - 1, flash;
    while(move < n - 1){
        while(j > cnt[stage] - 1){
            j++;
            stage = ((a[j] - min) * (bucket - 1)) / (max - min);
        }
        flash = a[j];
        while(j != cnt[stage]){
            stage = ((flash - min) * (bucket - 1)) / (max - min);
            cnt[stage]--;
            swap(flash, a[cnt[stage]]);
            move++;
        }
    }
    for (int i = 1; i < n; i++){
        int temp = a[i], k = i - 1;
        while(k >= 0 && temp < a[k]){
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = temp;
    }
    delete []cnt;
}
void typeToSort(int a[], int n, string type){
    int l = 0, r = n - 1;
    if(type == "selection-sort"){
        selectionSort(a, n);
    }
    else if(type == "insertion-sort"){
        insertionSort(a, n);
    }
    else if(type == "bubble-sort"){
        bubbleSort(a, n);
    }
    else if(type == "shaker-sort"){
        shakerSort(a, n);
    }
    else if(type == "shell-sort"){
        shellSort(a, n);
    }
    else if(type == "heap-sort"){
        heapSort(a, n);
    }
    else if(type == "merge-sort"){
        mergeSoft(a, l, r);
    }
    else if(type == "quick-sort"){
        quickSort(a, n, l, r);
    }
    else if(type == "counting-sort"){
        countingSort(a, n);
    }
    else if(type == "radix-sort"){
        radixSort(a, n);
    }
    else if(type == "flash-sort"){
        flashSort(a, n);
    }
    else{
        cout << "Enter an invalid sort!";
    }
}

