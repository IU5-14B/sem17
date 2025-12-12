#include "heap.h"
#include <iostream>
#include <algorithm>

static void print(const std::vector<int>& a) {
    for (int x : a) std::cout << x << " ";
    std::cout << std::endl;
}

static void siftUp(std::vector<int>& a, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (a[p] >= a[i]) break;
        std::swap(a[p], a[i]);
        i = p;
    }
}

static void siftDown(std::vector<int>& a, int i, int n) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;

        if (largest == i) break;
        std::swap(a[i], a[largest]);
        i = largest;
    }
}

void buildHeapTopDown(std::vector<int> data) {
    std::cout << "Восходящее построение пирамиды (алгоритм сверху вниз):" << std::endl;

    std::vector<int> heap;
    for (int x : data) {
        heap.push_back(x);
        siftUp(heap, (int)heap.size() - 1);
        print(heap); // выводим состояние пирамиды после каждой вставки
    }
}

void buildHeapBottomUp(std::vector<int> data) {
    std::cout << "Нисходящее построение пирамиды (алгоритм снизу вверх):" << std::endl;

    print(data); // исходный массив
    for (int i = (int)data.size() / 2 - 1; i >= 0; --i) {
        siftDown(data, i, (int)data.size());
        print(data); // выводим состояние после каждого siftDown
        if (i == 0) break; // чтобы не уйти в бесконечный цикл при i-- (для int)
    }
}

void heapSortChars(const std::string& word) {
    std::vector<char> a(word.begin(), word.end());
    int n = (int)a.size();

    // строим max-heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        int j = i;
        while (true) {
            int l = 2 * j + 1;
            int r = 2 * j + 2;
            int largest = j;

            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;

            if (largest == j) break;
            std::swap(a[j], a[largest]);
            j = largest;
        }
        if (i == 0) break;
    }

    // сортировка: переносим максимум в конец и восстанавливаем кучу
    for (int i = n - 1; i > 0; --i) {
        std::swap(a[0], a[i]);
        int j = 0;
        while (true) {
            int l = 2 * j + 1;
            int r = 2 * j + 2;
            int largest = j;

            if (l < i && a[l] > a[largest]) largest = l;
            if (r < i && a[r] > a[largest]) largest = r;

            if (largest == j) break;
            std::swap(a[j], a[largest]);
            j = largest;
        }
    }

    std::cout << "Результат пирамидальной сортировки: ";
    for (char c : a) std::cout << c << " ";
    std::cout << std::endl;
}
