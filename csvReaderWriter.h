/**
 * @file csvReaderWriter.h
 * @brief Ф-ии чтения и записи объектов Person в CSV-файлы.
 * @defgroup CSV Работа с CSV
 * @brief Содержит функции ввода/вывода данных в формате CSV.
 */

#pragma once
#include <string>
#include <vector>
#include "class.h"

/**
 * @ingroup CSV
 * @brief Считывает список людей из CSV-файла.
 *
 * CSV-файл должен содержать заголовок и строки в формате:  
 * ФИО,ГодРождения,ГодСмерти,ЧислоДетей
 *
 * @param filename Путь к CSV-файлу.
 * @return Вектор объектов Person.
 */

std::vector<Person> readCSV(const std::string& filename);

/**
 * @ingroup CSV
 * @brief Записывает список людей в CSV-файл.
 *
 * Результирующий файл будет содержать заголовок и строки в формате:  
 * ФИО,ГодРождения,ГодСмерти,ЧислоДетей
 *
 * @param filename Путь к выходному CSV-файлу.
 * @param people Вектор объектов Person для записи.
 */

void writeCSV(const std::string& filename, const std::vector<Person>& people);
