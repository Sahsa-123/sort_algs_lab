/**
 * @file class.h
 * @brief реализация класса Person.
 */

#pragma once
#include <string>

/**
 * @class Person
 * @brief Класс, представляющий данные о человеке из генеалогического фонда.
 *
 * Класс содержит ФИО, годы рождения и смерти, а также количество детей.
 * Реализует перегрузки операторов сравнения для сортировки по правилам:
 * 1. Год рождения
 * 2. ФИО
 * 3. Количество детей
 */

class Person {
public:
    /**
     * @brief Полное имя человека (ФИО).
     */
    std::string fullName;

    /**
     * @brief Год рождения.
     */
    int birthYear;
    
    /**
     * @brief Год смерти.
     */
    int deathYear;

    /**
     * @brief Количество детей.
     */
    int numChildren;

     /**
     * @brief Конструктор класса Person.
     * @param name ФИО.
     * @param birth Год рождения.
     * @param death Год смерти.
     * @param children Количество детей.
     */
    Person(std::string name = "", int birth = 0, int death = 0, int children = 0);

    /**
     * @brief Оператор меньше.
     * @details Сравнение по полям: год рождения → ФИО → число детей.
     * @param other Другой объект Person.
     * @return true, если текущий объект меньше other.
     */
    bool operator<(const Person& other) const;
    
    /**
     * @brief Оператор больше.
     * @param other Другой объект Person.
     * @return true, если текущий объект больше other.
     */
    bool operator>(const Person& other) const;
    
    /**
     * @brief Оператор меньше или равно.
     * @param other Другой объект Person.
     * @return true, если текущий объект меньше или равен other.
     */
    bool operator<=(const Person& other) const;

    /**
     * @brief Оператор больше или равно.
     * @param other Другой объект Person.
     * @return true, если текущий объект больше или равен other.
     */
    bool operator>=(const Person& other) const;
};
