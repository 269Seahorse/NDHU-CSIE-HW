#include <bits/stdc++.h>

template<class T>
class MaxHeap {
public:
    // Constructing an empty heap.
    MaxHeap() {}

    // To add an element to the heap.
    void insert(T value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    // To remove the root element in the heap and return it.
    T extract() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        T root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            bubbleDown(0);
        }
        return root;
    }

    // Return the number of elements in the heap.
    int count() const {
        return heap.size();
    }

private:
    std::vector<T> heap;

    void bubbleUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            bubbleUp(parent);
        }
    }

    void bubbleDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            bubbleDown(largest);
        }
    }
};