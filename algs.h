/**
 * @file algs.h
 * @brief Реализация алгоритмов сортировки
 * @defgroup Sorting Алгоритмы сортировки
 * @brief Содержит шаблонные функции сортировки: пузырьковой, шейкерной и пирамидальной.
 */


#pragma once
#include <vector>
#include <algorithm>

/**
 * @ingroup Sorting
 * @brief Выполняет пузырьковую сортировку in-place.
 * 
 * @tparam T Тип элементов.
 * @param a Вектор, который будет отсортирован.
 */
template<typename T>
void bubbleSort(std::vector<T>& a) {
    size_t size = a.size();
    for (size_t i = 0; i < size; ++i)
        for (size_t j = size - 1; j > i; --j)
            if (a[j - 1] > a[j])
                std::swap(a[j - 1], a[j]);
}

/**
 * @ingroup Sorting
 * @brief Возвращает отсортированную копию вектора с использованием пузырьковой сортировки.
 * 
 * @tparam T Тип элементов.
 * @param a Исходный вектор.
 * @return Отсортированный вектор.
 */
template<typename T>
std::vector<T> bubbleSortImmutable(const std::vector<T>& a) {
    std::vector<T> result = a;//созаст глубокую копию, тк мы используем только примитивы в качестве полей
    bubbleSort(result);
    return result;
}


/**
 * @ingroup Sorting
 * @brief Выполняет шейкерную сортировку in-place.
 * 
 * @tparam T Тип элементов.
 * @param a Вектор, который будет отсортирован.
 */
template<typename T>
void shakerSort(std::vector<T>& a) {
    size_t left = 0;
    size_t right = a.size() - 1;

    while (left < right) {
        size_t lastSwap = left;
        for (size_t i = right; i > left; --i) {
            if (a[i - 1] > a[i]) {
                std::swap(a[i - 1], a[i]);
                lastSwap = i;
            }
        }
        if (lastSwap == left) break;
        left = lastSwap;

        lastSwap = right;
        for (size_t i = left; i < right; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                lastSwap = i;
            }
        }
        if (lastSwap == right) break;
        right = lastSwap;
    }
}

/**
 * @ingroup Sorting
 * @brief Возвращает отсортированную копию вектора с использованием шейкерной сортировки.
 * 
 * @tparam T Тип элементов.
 * @param a Исходный вектор.
 * @return Отсортированный вектор.
 */
template<typename T>
std::vector<T> shakerSortImmutable(const std::vector<T>& a) {
    std::vector<T> result = a;
    shakerSort(result);
    return result;
}

/**
 * @ingroup Sorting
 * @brief Вспомогательная функция для поддержания свойства кучи.
 * 
 * @tparam T Тип элементов.
 * @param a Вектор элементов.
 * @param subtreeRootIndex Индекс корня поддерева.
 * @param treeSize Размер поддерева.
 */
template<typename T>
void downHeap(std::vector<T>& a, size_t subtreeRootIndex, size_t treeSize) {
    T currMax = a[subtreeRootIndex];//корневой элемент
    size_t childIndex;//индекс наибольшего ребенка

    while (2 * subtreeRootIndex + 1 <= treeSize) {
        childIndex = 2 * subtreeRootIndex + 1;
        // если есть правый ребёнок больше левого, берем его
        if (childIndex + 1 <= treeSize && a[childIndex] < a[childIndex + 1])
            ++childIndex;

        //если корень больше своих детей, все ок
        if (currMax >= a[childIndex])
            break;

        //иначе мы переходим к неудовлетворяющему поддереву
        a[subtreeRootIndex] = a[childIndex];
        subtreeRootIndex = childIndex;
    }

    a[subtreeRootIndex] = currMax;
}

/**
 * @ingroup Sorting
 * @brief Выполняет пирамидальную сортировку in-place.
 * 
 * @tparam T Тип элементов.
 * @param a Вектор, который будет отсортирован.
 */
template<typename T>
void heapSort(std::vector<T>& a) {
    size_t size = a.size();

    // Строим кучу из массива 
    for (size_t i = size / 2; i-- > 0;)
        downHeap(a, i, size - 1);

    // Сортировка
    for (size_t i = size - 1; i > 0; --i) {
        std::swap(a[0], a[i]);
        downHeap(a, 0, i - 1);
    }
}

/**
 * @ingroup Sorting
 * @brief Возвращает отсортированную копию вектора с использованием пирамидальной сортировки.
 * 
 * @tparam T Тип элементов.
 * @param a Исходный вектор.
 * @return Отсортированный вектор.
 */
template<typename T>
std::vector<T> heapSortImmutable(const std::vector<T>& a) {
    std::vector<T> result = a;
    heapSort(result);
    return result;
}
