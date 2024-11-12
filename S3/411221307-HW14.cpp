#include <bits/stdc++.h>

template<class T>
class MinMaxHeap {
public:
    MinMaxHeap() {}

    void insert(T value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    T getMin() const {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        return heap[0];
    }

    T getMax() const {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        if (heap.size() == 1) return heap[0];
        return std::max(heap[1], heap[2]);
    }

    void deleteMin() {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        std::swap(heap[0], heap.back());
        heap.pop_back();
        if (!heap.empty()) bubbleDown(0);
    }

    void deleteMax() {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        int maxIndex = findMaxIndex();
        std::swap(heap[maxIndex], heap.back());
        heap.pop_back();
        if (maxIndex < heap.size()) bubbleDown(maxIndex);
    }

private:
    std::vector<T> heap;

    int findMaxIndex() {
        if (heap.size() == 1) return 0;
        if (heap.size() == 2) return 1;
        return heap[1] > heap[2] ? 1 : 2;
    }

    void bubbleUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (isMinLevel(index)) {
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                bubbleUpMax(parent);
            } else {
                bubbleUpMin(index);
            }
        } else {
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                bubbleUpMin(parent);
            } else {
                bubbleUpMax(index);
            }
        }
    }

    void bubbleUpMin(int index) {
        if (index == 0) return;
        int grandparent = (index - 3) / 4;
        if (grandparent >= 0 && heap[index] < heap[grandparent]) {
            std::swap(heap[index], heap[grandparent]);
            bubbleUpMin(grandparent);
        }
    }

    void bubbleUpMax(int index) {
        if (index == 0) return;
        int grandparent = (index - 3) / 4;
        if (grandparent >= 0 && heap[index] > heap[grandparent]) {
            std::swap(heap[index], heap[grandparent]);
            bubbleUpMax(grandparent);
        }
    }

    void bubbleDown(int index) {
        if (isMinLevel(index)) {
            bubbleDownMin(index);
        } else {
            bubbleDownMax(index);
        }
    }

    void bubbleDownMin(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            bubbleDown(smallest);
        }
    }

    void bubbleDownMax(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            bubbleDown(largest);
        }
    }

    bool isMinLevel(int index) {
        int level = 0;
        while (index > 0) {
            index = (index - 1) / 2;
            level++;
        }
        return level % 2 == 0;
    }
};

int main() {
    MinMaxHeap<int> mmHeap; //minmaxHeap (x moremoreHeap (o
    int j;
    srand(time(NULL));
    for (j = 0; j < 10; j++)
        mmHeap.insert(rand() % 100);

    while (true) {
        try {
            std::cout << mmHeap.getMin() << " ";
            mmHeap.deleteMin();
        }
        catch (std::exception&) {
            break;
        }
    }
    std::cout << std::endl;

    for (j = 0; j < 10; j++)
        mmHeap.insert(rand() % 100);

    while (true) {
        try {
            std::cout << mmHeap.getMax() << " ";
            mmHeap.deleteMax();
        }
        catch (std::exception&) {
            break;
        }
    }

    return 0;
}