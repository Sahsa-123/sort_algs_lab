#include "csvReaderWriter.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Person> readCSV(const std::string& filename) {
    std::vector<Person> people;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл: " << filename << std::endl;
        return people;
    }

    std::string line;
    std::getline(file, line); // пропустить заголовок

    while (std::getline(file, line)) {
        std::stringstream inputStream(line);
        std::string name, birthStr, deathStr, childrenStr;

        std::getline(inputStream, name, ',');
        std::getline(inputStream, birthStr, ',');
        std::getline(inputStream, deathStr, ',');
        std::getline(inputStream, childrenStr, ',');

        int birth = std::stoi(birthStr);
        int death = std::stoi(deathStr);
        int children = std::stoi(childrenStr);

        people.emplace_back(name, birth, death, children);
    }

    return people;
}

void writeCSV(const std::string& filename, const std::vector<Person>& people) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    file << "ФИО,ГодРождения,ГодСмерти,ЧислоДетей\n";
    for (size_t i = 0; i < people.size(); ++i) {
        const Person& p = people[i];
        file << p.fullName << "," << p.birthYear << "," << p.deathYear << "," << p.numChildren << "\n";
    }
}
