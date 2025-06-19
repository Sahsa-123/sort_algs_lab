/**
 * @file generateData.h
 * @brief Генерация случайных записей для тестирования алгоритмов сортировки.
 * @defgroup DataGen Генерация данных
 * @brief Содержит генерацию случайных объектов Person.
 */


#pragma once
#include <vector>
#include "class.h"

/**
 * @ingroup DataGen
 * @brief Генерирует тестовые данные для массива Person.
 *
 * Каждый объект будет содержать случайное ФИО, год рождения и смерти,
 * а также случайное количество детей (от 0 до 14).
 *
 * @param size Количество записей, которое нужно сгенерировать.
 * @return Вектор объектов Person с случайными данными.
 */

std::vector<Person> generateTestData(int size);
