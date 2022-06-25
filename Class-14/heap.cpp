#include<iostream>
#include<vector>
using namespace std;

// TC : O(log n)
// Aux Space : O(log n)
void top_down_heapify(vector<int> &heap, int index) {
    int left = 2*index + 1;
    int right = left + 1;

    // find max of index, left and right

    int largest = index;

    if (left < heap.size() and heap[left] > heap[largest])
        largest = left;

    if (right < heap.size() and heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        top_down_heapify(heap, largest);
    }
}

void delete_from_max_heap(vector<int> &heap) {
    int n = heap.size();

    if (n == 0)
        return;

    // Step 1 : Replace the root with the last node and delete last node
    heap[0] = heap[n-1];
    heap.pop_back();

    // Step 2 : Call top-down heapify
    top_down_heapify(heap,0);
}

// -----------------------------------------------------------------------------------------------------

// TC : O(log n)
// Aux Space : O(log n)

void bottom_up_heapify(vector<int> &heap, index index) {

    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        bottom_up_heapify(heap, parent);
    }
}


void insert_in_max_heap(vector<int> &heap, int element) {

    // Step 1 & 2 : Increment heap size by 1 and insert element at the end
    heap.push_back(element);

    // Step 3 : Call bottom-up heapify on last index
    bottom_up_heapify(heap, heap.size()-1);
}