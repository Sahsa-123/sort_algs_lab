/**
 * @file main.cpp
 * @brief Главный модуль лабораторной работы.
 *
 * Программа выполняет:
 * - генерацию тестовых CSV-файлов с объектами `Person`
 * - применение различных алгоритмов сортировки к этим данным
 * - замер времени выполнения сортировок
 * - запись результатов и метрик в отдельные файлы
 *
 * Используемые сортировки:
 * - Пузырьковая
 * - Шейкерная
 * - Пирамидальная
 * - std::sort (для сравнения)
 *
 * Результаты сохраняются в папках outputs_* и benchmarks.csv.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>  
#include <algorithm>
#include "class.h"
#include "algs.h"
#include "generateData.h"
#include "csvReaderWriter.h"

/**
 * @brief Генерирует равномерно распределённые размеры массивов для тестирования.
 *
 * @param start Начальный размер (по умолчанию 100).
 * @param end Конечный размер (по умолчанию 100.000).
 * @param size Количество размеров (по умолчанию 10).
 * @return Вектор размеров выборок.
 */
std::vector<int> linear_distrib_sizes(int start = 100, int end = 100'000, int size = 10) {//равномерно распределяем размеры выборок
    std::vector<int> sizes;
    int step_size = (end - start) / (size - 1);
    for (int i = 0; i < size; ++i)
        sizes.push_back(start + i * step_size);
    return sizes;
}

/**
 * @brief Точка входа в программу. Генерирует тестовые данные, применяет сортировки и сохраняет результаты.
 */

int main() {
    srand(time(0));

    //Предварительная подготовка
    //Генерация данных
    std::vector<int> sizes = linear_distrib_sizes();
    for (int i = 0; i < sizes.size(); ++i) {
        int size = sizes[i];
        std::string inputFile = "inputs/inputs_" + std::to_string(i + 1) + "_" + std::to_string(size) + ".csv";
        std::vector<Person> people = generateTestData(size);
        writeCSV(inputFile, people);
    }

    //Сортировки
    struct SortInfo {
        std::string name;
        std::vector<Person> (*func)(const std::vector<Person>&);
    };

    std::vector<SortInfo> sorts = {
        {"bubble", bubbleSortImmutable},
        {"shaker", shakerSortImmutable},
        {"heap", heapSortImmutable},
        {"std", [](const std::vector<Person>& v) {
            std::vector<Person> copy = v;
            std::sort(copy.begin(), copy.end());
            return copy;
        }}
    };
    //Предварительная подготовка

    //Бенчмарки
    for (const auto& sort : sorts) {
        std::string outputDir = "outputs_" + sort.name;
        std::string benchFile = outputDir + "/benchmarks.csv";

        std::ofstream benchOut(benchFile);
        benchOut << "index,len,time\n";

        for (int i = 0; i < sizes.size(); ++i) {
            int size = sizes[i];
            std::string inputFile = "inputs/inputs_" + std::to_string(i + 1) + "_" + std::to_string(size) + ".csv";
            std::string outputFile = outputDir + "/outputs_" + std::to_string(i + 1) + "_" + std::to_string(size) + ".csv";

            std::vector<Person> data = readCSV(inputFile);

            auto start = std::chrono::high_resolution_clock::now();
            std::vector<Person> sorted = sort.func(data);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            double time = elapsed.count();

            writeCSV(outputFile, sorted);
            benchOut << (i + 1) << "," << size << "," << time << "\n";
        }
    }
    //Бенчмарки

    return 0;
}

