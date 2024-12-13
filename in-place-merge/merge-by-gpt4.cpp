#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void mergeSortedArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    // Initial gap
    int gap = ceil((double)(n + m) / 2);

    while (gap > 0) {
        int i = 0;

        // Compare elements in the first array
        while (i + gap < n) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
            }
            i++;
        }

        // Compare elements between the two arrays
        int j = gap > n ? gap - n : 0;
        while (i < n && j < m) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
            }
            i++;
            j++;
        }

        // Compare elements in the second array
        j = 0;
        while (j + gap < m) {
            if (b[j] > b[j + gap]) {
                swap(b[j], b[j + gap]);
            }
            j++;
        }

        // Reduce the gap
        gap = gap > 1 ? (int)ceil((double)gap / 2) : 0;
    }
}

int main() {
    vector<int> a = {1, 4, 7, 8 10};
    vector<int> b = {2, 3, 9};

    mergeSortedArrays(a, b);

    cout << "Array a: ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Array b: ";
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
