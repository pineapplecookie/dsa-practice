#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (i <= high - 1 && arr[i] <= pivot) {
            i++;
        }

        while (j > low && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pindex = partition(arr, low, high);
        qs(arr, low, pindex - 1);
        qs(arr, pindex + 1, high);
    }
}

vector<int> quicksort(vector<int> arr) {
    if (!arr.empty()) {
        qs(arr, 0, static_cast<int>(arr.size()) - 1);
    }
    return arr;
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 3};

    arr = quicksort(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
