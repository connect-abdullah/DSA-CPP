#include <iostream>
#include <utility>
using namespace std;

class Heap {
private:
    int heap[100];
    int size;

public:
    Heap(){
        size = 0;
    }

    void insertMax(int val) {
        int i = size;
        heap[size++] = val;

        while(i > 0 && heap[(i-1)/2] < heap[i]){
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void insertMin(int val) {
        int i = size;
        heap[size++] = val;

        while(i > 0 && heap[(i-1)/2] > heap[i]){
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapifyMax(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapifyMax(arr, n, largest);
        }
    }

    void heapifyMin(int arr[], int n, int i) {
        int minimum = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && arr[left] < arr[minimum]) minimum = left;
        if(right < n && arr[right] < arr[minimum]) minimum = right;

        if(minimum != i){
            swap(arr[i], arr[minimum]);
            heapifyMin(arr, n, minimum);
        }
    }

    void sortMaxAsc(int arr[], int n) {
        // Building Max Heap
        for(int i = n/2-1; i >= 0; i--) {
            heapifyMax(arr,n,i);
        }

        // Sort
        for(int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMax(arr, i, 0);
        }
    } 

    void sortMinDes(int arr[], int n) {
        // Building Min Heap
        for(int i = n/2-1; i >= 0; i--) {
            heapifyMin(arr,n,i);
        }

        // Sort
        for(int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMin(arr, i, 0);
        }
    }

    void deleteMax() {
        if(size <= 0) return; // empty arr
        if(size == 1) {
            size--; // only one element
            return;
        }
        heap[0] = heap[size-1];
        size--;
        heapifyMax(heap, size, 0);
    }

    void deleteMin() {
        if(size <= 0) return; // empty arr
        if(size == 1) {
            size--; // only one element
            return;
        }

        heap[0] = heap[size-1];
        size--;
        heapifyMin(heap, size, 0);
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    // ======== Max-Heap Operations ========
    cout << "Max-Heap Insertions:\n";
    h.insertMax(10);
    h.insertMax(20);
    h.insertMax(5);
    h.insertMax(30);
    h.insertMax(25);
    cout << "Max Heap: ";
    h.print();

    cout << "Deleting Max...\n";
    h.deleteMax();
    h.print();

    // Sorting array using Max Heap
    int arr1[] = {10, 20, 5, 30, 25};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    cout << "Sort Max Heap Ascending: ";
    h.sortMaxAsc(arr1, n1);
    for(int i = 0; i < n1; i++) cout << arr1[i] << " ";
    cout << endl;

    // ======== Min-Heap Operations ========
    Heap h2;
    cout << "\nMin-Heap Insertions:\n";
    h2.insertMin(10);
    h2.insertMin(20);
    h2.insertMin(15);
    h2.insertMin(5);
    cout << "Min Heap: ";
    h2.print();

    cout << "Deleting Min...\n";
    h2.deleteMin();
    h2.print();

    // Sorting array using Min Heap
    int arr3[] = {10, 20, 15, 5};
    int n2 = sizeof(arr3)/sizeof(arr3[0]);

    cout << "Sort Min Heap Descending: ";
    int arr4[] = {10, 20, 15, 5};
    h2.sortMinDes(arr4, n2);
    for(int i = 0; i < n2; i++) cout << arr4[i] << " ";
    cout << endl;

    return 0;
}

