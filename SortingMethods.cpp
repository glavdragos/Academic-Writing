#include <bits/stdc++.h>
#include <ctime>
using namespace std;




void bubbleSort(int v[], int n) 
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
        if (v[j] > v[j + 1])
            swap(v[j], v[j + 1]);

}




void selectionSort(int v[], int n)
{
    int i, j, min_index;
    for (i = 0; i < n - 1; i++)
    { 
        min_index = i;
        for (j = i + 1; j < n; j++) 
            if (v[j] < v[min_index])
                min_index = j;
        swap(v[min_index], v[i]);
    }
}




void insertionSort(int v[], int n) 
{
    int i, j, key;
    for (i = 1; i < n; i++) 
    {
        key = v[i];
        j = i - 1;
        while (j >= 0 && key < v[j]) 
        {
            v[j + 1] = v[j];
            j = j -1;
        }
        v[j + 1] = key;
    }
}




int partition(int v[], int low, int high) 
{
    int pivot = v[high]; 
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (v[j] <= pivot) 
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(int v[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}




void mergeSort(int v[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;    
    vector<int> L(n1), R(n2); 
    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            v[k] = L[i];
            i++;
        } 
        else 
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
    {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        mergeSort(v, left, mid, right);
    }
}


void countingSortRadix(int v[], int n, int exp)
{
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        v[i] = output[i];
}


void radixSort(int v[], int n)
{
    int max_val = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max_val)
            max_val = v[i];

    for (int exp = 1; max_val / exp > 0; exp *= 10)
        countingSortRadix(v, n, exp);
}






vector<int> randomArray(int n) 
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand(); 
    return v;
}

vector<int> sortedArray(int n) 
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
    return v;
}

vector<int> reverseArray(int n) 
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = n - i;
    return v;
}

vector<int> almostSortedArray(int n) 
{
    vector<int> v = sortedArray(n);
    int swaps = n / 50;
    for (int i = 0; i < swaps; i++) 
    {
        int a = rand() % n;
        int b = rand() % n;
        swap(v[a], v[b]);
    }
    return v;
}

vector<int> fewValuesArray(int n) 
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 5; 
    return v;
}


vector<string> randomStringArray(int n)
{
    vector<string> v(n);
    string chars = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < n; i++)
    {
        int len = 5 + rand() % 10; // lungime 5–15
        string s = "";

        for (int j = 0; j < len; j++)
            s += chars[rand() % chars.size()];

        v[i] = s;
    }

    return v;
}


void testSortString(const vector<string>& original, const string& name, int repetitions)
{
    long long totalTime = 0;

    for (int r = 0; r < repetitions; r++)
    {
        vector<string> v = original;

        auto start = chrono::high_resolution_clock::now();
        sort(v.begin(), v.end());
        auto end = chrono::high_resolution_clock::now();

        totalTime += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }

    cout << name << ": " << (totalTime / repetitions) << " microseconds (avg)\n";
}


void testSort(const vector<int>& original, const string& name, 
              function<void(int*, int)> sortFunc, int repetitions) 
{
    long long totalTime = 0;

    for (int r = 0; r < repetitions; r++)
    {
        vector<int> v = original;
        auto start = chrono::high_resolution_clock::now();
        sortFunc(v.data(), v.size());
        auto end = chrono::high_resolution_clock::now();
        totalTime += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }

    cout << name << ": " << (totalTime / repetitions) << " microseconds (avg)\n";
}

// QuickSort wrapper:
void quickSortWrapper(int v[], int n) { quickSort(v, 0, n - 1); }

// MergeSort wrapper:
void mergeSortWrapper(int v[], int n) { mergeSort(v, 0, n - 1); }


vector<float> randomFloatArray(int n)
{
    vector<float> v(n);
    for (int i = 0; i < n; i++)
        v[i] = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
    return v;
}


void testSortFloat(const vector<float>& original, const string& name, int repetitions)
{
    long long totalTime = 0;

    for (int r = 0; r < repetitions; r++)
    {
        vector<float> v = original;
        auto start = chrono::high_resolution_clock::now();
        sort(v.begin(), v.end());
        auto end = chrono::high_resolution_clock::now();

        totalTime += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }

    cout << name << ": " << (totalTime / repetitions) << " microseconds (avg)\n";
}


void stdSortWrapper(int v[], int n) 
{
    std::sort(v, v + n);
}


int main() 
{
    srand((unsigned)time(NULL));
    vector<int> sizes = {50, 100, 1000, 5000, 10000, 20000};

    for (int n : sizes)
{
    int repetitions;
    if (n <= 1000)
        repetitions = 100;
    else if (n <= 10000)
        repetitions = 20;
    else
        repetitions = 5;

    cout << "\n=============================\n";
    cout << "SIZE: " << n << "\n";
    cout << "=============================\n";

    vector<int> randomArr = randomArray(n);
    vector<int> sortedArr = sortedArray(n);
    vector<int> reverseArr = reverseArray(n);
    vector<int> almostArr = almostSortedArray(n);
    vector<int> fewArr = fewValuesArray(n);

    // --- RANDOM ARRAY ---
    cout << "--- RANDOM ARRAY ---\n";
    if (n <= 2000) testSort(randomArr, "BubbleSort", bubbleSort, repetitions);
    if (n <= 2000) testSort(randomArr, "SelectionSort", selectionSort, repetitions);
    if (n <= 2000) testSort(randomArr, "InsertionSort", insertionSort, repetitions);
    testSort(randomArr, "QuickSort", quickSortWrapper, repetitions);
    testSort(randomArr, "MergeSort", mergeSortWrapper, repetitions);
    testSort(randomArr, "RadixSort", radixSort, repetitions);
    testSort(randomArr, "std::sort", stdSortWrapper, repetitions);

    // --- SORTED ARRAY ---
    cout << "\n--- SORTED ARRAY ---\n";
    if (n <= 2000) testSort(sortedArr, "BubbleSort", bubbleSort, repetitions);
    if (n <= 2000) testSort(sortedArr, "SelectionSort", selectionSort, repetitions);
    if (n <= 2000)testSort(sortedArr, "InsertionSort", insertionSort, repetitions);
    testSort(sortedArr, "QuickSort", quickSortWrapper, repetitions);
    testSort(sortedArr, "MergeSort", mergeSortWrapper, repetitions);
    testSort(sortedArr, "RadixSort", radixSort, repetitions);
    testSort(sortedArr, "std::sort", stdSortWrapper, repetitions);

    // --- REVERSE ARRAY ---
    cout << "\n--- REVERSE ARRAY ---\n";
    if (n <= 2000) testSort(reverseArr, "BubbleSort", bubbleSort, repetitions);
    if (n <= 2000) testSort(reverseArr, "SelectionSort", selectionSort, repetitions);
    if (n <= 2000) testSort(reverseArr, "InsertionSort", insertionSort, repetitions);
    testSort(reverseArr, "QuickSort", quickSortWrapper, repetitions);
    testSort(reverseArr, "MergeSort", mergeSortWrapper, repetitions);
    testSort(reverseArr, "RadixSort", radixSort, repetitions);
    testSort(reverseArr, "std::sort", stdSortWrapper, repetitions);

    // --- ALMOST SORTED ARRAY ---
    cout << "\n--- ALMOST SORTED ARRAY ---\n";
    if (n <= 2000) testSort(almostArr, "BubbleSort", bubbleSort, repetitions);
    if (n <= 2000) testSort(almostArr, "SelectionSort", selectionSort, repetitions);
    if (n <= 2000) testSort(almostArr, "InsertionSort", insertionSort, repetitions);
    testSort(almostArr, "QuickSort", quickSortWrapper, repetitions);
    testSort(almostArr, "MergeSort", mergeSortWrapper, repetitions);
    testSort(almostArr, "RadixSort", radixSort, repetitions);
    testSort(almostArr, "std::sort", stdSortWrapper, repetitions);

    // --- FEW DISTINCT VALUES ARRAY ---
    cout << "\n--- FEW DISTINCT VALUES ARRAY ---\n";
    if (n <= 2000) testSort(fewArr, "BubbleSort", bubbleSort, repetitions);
    if (n <= 2000) testSort(fewArr, "SelectionSort", selectionSort, repetitions);
    if (n <= 2000)testSort(fewArr, "InsertionSort", insertionSort, repetitions);
    testSort(fewArr, "QuickSort", quickSortWrapper, repetitions);
    testSort(fewArr, "MergeSort", mergeSortWrapper, repetitions);
    testSort(fewArr, "RadixSort", radixSort, repetitions);
    testSort(fewArr, "std::sort", stdSortWrapper, repetitions);

    // --- FLOAT ARRAY ---
    vector<float> floatArr = randomFloatArray(n); 
    cout << "\n--- FLOAT ARRAY (std::sort) ---\n";
    testSortFloat(floatArr, "std::sort (float)", repetitions);

    // --- STRING ARRAY ---
    vector<string> stringArr = randomStringArray(n);

    cout << "\n--- STRING ARRAY (std::sort) ---\n";
    testSortString(stringArr, "std::sort (string)", repetitions);
}
    return 0;
}