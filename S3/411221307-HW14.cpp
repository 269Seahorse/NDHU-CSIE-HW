#include <bits/stdc++.h>


template<class T>
class MinMaxHeap {
public:
    MinMaxHeap() {}
    //The insert function in a Min-Max Heap adds a new element to the heap while maintaining its unique properties.
    void insert(T value) {
        heap.push_back(value);
        nodeUp(heap.size() - 1);
    }
    // Retrieve the minimum element in the heap, throw an exception when heap is empty
    T getMin() const {
        if(heap.empty()) throw std::out_of_range("Heap is empty");
        return heap[0];
    }
    // Retrieve the maximum element in the heap, throw an exception when heap is empty
    T getMax() const {
        if(heap.empty()) throw std::out_of_range("Heap is empty");
        if(heap.size() == 1) return heap[0];
        return std::max(heap[1], heap[2]);
    }
    // Delete the minimum element in the heap, throw an exception when heap is empty
    void deleteMin() {
        if(heap.empty()) throw std::out_of_range("Heap is empty");
        std::swap(heap[0], heap.back());
        heap.pop_back();
        if(!heap.empty()) nodeDown(0);
    }
    // Delete the maximum element in the heap, throw an exception when heap is empty
    void deleteMax() {
        if(heap.empty()) throw std::out_of_range("Heap is empty");
        if(heap.size() == 1){
            heap.pop_back();
            return;
        }
        int maxI = findMaxI();
        std::swap(heap[maxI], heap.back());
        heap.pop_back();
        if(!heap.empty()) nodeDown(maxI);
    }
    void print(){
        for(auto i : heap){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
private:
    std::vector<T> heap;
    int findMaxI(){
        if(heap.size() == 1) return 0;
        if(heap.size() == 2) return 1;
        return heap[1] > heap[2] ? 1 : 2;
    }
    void nodeUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;

        if (isMinL(index)) { 
            //  min 層
            if (heap[index] > heap[parent]) {
                // 大於父移到 max 
                std::swap(heap[index], heap[parent]);
                nodeUpMax(parent);
            } else {
                // 小於父 min 
                nodeUpMin(index);
            }
        } else {  // max 層
            //大於父節點?
            if (heap[index] < heap[parent]) {
                // 小於父移到 min 
                std::swap(heap[index], heap[parent]);
                nodeUpMin(parent);
            } else {
                // 大於父 max 
                nodeUpMax(index);
            }
        }
    }
    void nodeUpMin(int index) {
        if (index == 0) return;
        int grandparent = (index - 3) / 4; 
        if (grandparent >= 0 && heap[index] < heap[grandparent]) {
            std::swap(heap[index], heap[grandparent]);
            nodeUpMin(grandparent);  
        }
    }
    void nodeUpMax(int index) {
        if (index == 0) return;
        int grandparent = (index - 3) / 4; 
        if (grandparent > 0 && heap[index] > heap[grandparent]) {
            std::swap(heap[index], heap[grandparent]);
            nodeUpMax(grandparent);  
        }
    }
    void nodeDown(int index){
        if(isMinL(index)){
            nodeDownMin(index);
        }
        else{
            nodeDownMax(index);
        }
    }
    void nodeDownMin(int index){
        int smallest = index;
        int leftchild = left(index);
        int rightchild = right(index);
        
        for(int child:{leftchild, rightchild, left(leftchild),right(leftchild),left(rightchild),right(rightchild)}){ {
            if(child < heap.size() && heap[child] < heap[smallest]) smallest = child;
        }
        }
        
        
        //if(leftchild < heap.size() && heap[leftchild] < heap[smallest]) smallest = leftchild;
        //if(rightchild < heap.size() && heap[rightchild] < heap[smallest]) smallest = rightchild;

        if(smallest != index){
            std::swap(heap[index], heap[smallest]);
            nodeDownMin(smallest);
        }
    }
    void nodeDownMax(int index){
        int largest = index;
        int leftchild = left(index);
        int rightchild = right(index);
        for(int child:{leftchild, rightchild, left(leftchild),right(leftchild),left(rightchild),right(rightchild)}){ {
            if(child < heap.size() && heap[child] > heap[largest]) largest = child;
        }
        }
        // if(leftchild < heap.size() && heap[leftchild] > heap[largest]) largest = leftchild;
        // if(rightchild < heap.size() && heap[rightchild] > heap[largest]) largest = rightchild;

        if(largest != index){
            std::swap(heap[index], heap[largest]);
            nodeDownMax(largest);
        }
    }
    bool isMinL(int index){
        int level = log2(index + 1);//index在幾層 
        return level % 2 == 0;
    }
    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }
    int parent(int index) { return (index - 1) / 2; }
};
int main() {
    MinMaxHeap<int> mmHeap;
    int j;
    srand(time(NULL));
    for(j = 0;j < 10;j ++){
      mmHeap.insert(rand() % 100);
      
    }
    //mmHeap.print();
    while(true) {
      try {
        std::cout << mmHeap.getMin() << " ";
        mmHeap.deleteMin();
      }
      catch(std::exception) {
        break;
      }
    }
    std::cout << std::endl;
    // std::cout << std::endl;
    for(j = 0;j < 10;j ++)
      mmHeap.insert(rand() % 100);
   // mmHeap.print();
    
    while(true) {
      try {
        std::cout << mmHeap.getMax() << " ";
        mmHeap.deleteMax();
      }
      catch(std::exception) {
        break;
      }
    }

    return 0;
}
