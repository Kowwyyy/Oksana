#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Самостоятельная реализация минимальной кучи
class Min_Heap {
private:
    vector<int> heap;

    void Up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] >= heap[parent]) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void Down(int index) {
        int n = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;
            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == index) break;
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    int size() const { return heap.size(); }
    int top() const { return heap[0]; }

    void push(int val) {
        heap.push_back(val);
        Up(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        swap(heap[0], heap.back());
        heap.pop_back();
        if (!heap.empty()) Down(0);
    }

    vector<int> getSorted() {
        vector<int> result = heap;
        sort(result.begin(), result.end()); // сорт по возрастанию
        return result;
    }
};

vector<int> find_max_el(const vector<int>& numbers, int K) {
    Min_Heap min_heap;

    for (int num : numbers) {
        if (min_heap.size() < K) {
            min_heap.push(num);
        } else if (num > min_heap.top()) {
            min_heap.pop();
            min_heap.push(num);
        }
    }

    return min_heap.getSorted();
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, K;
    fin >> N >> K;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        fin >> numbers[i];
    }

    vector<int> topK = find_max_el(numbers, K);

    for (int num : topK) {
        fout << num << " ";
    }

    return 0;
}
