#include "heap.h"
#include <iostream>

int main() {
    std::vector<int> data = {1, 8, 6, 5, 3, 7, 4};

    buildHeapTopDown(data);
    std::cout << std::endl;

    buildHeapBottomUp(data);
    std::cout << std::endl;

    heapSortChars("SORTING");
    std::cout << std::endl;

    std::cout << "Пирамидальная сортировка не является устойчивой: "
              << "равные элементы могут менять взаимный порядок."
              << std::endl;

    return 0;
}
