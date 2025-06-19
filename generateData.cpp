#include "generateData.h"
#include "class.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

/**
 * @ingroup DataGen
 * @brief Генерирует случайное полное имя (ФИО) на основе предопределённых списков.
 *
 * Состоит из случайной фамилии, имени и отчества.
 *
 * @return Строка с полным именем.
 */

std::string randomFullName() {
    const std::vector<std::string> lastNames = {
        "Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов",
        "Попов", "Лебедев", "Новиков", "Фролов", "Волков"
    };

    const std::vector<std::string> firstNames = {
        "Алексей", "Никита", "Иван", "Петр", "Дмитрий",
        "Сергей", "Юрий", "Андрей", "Артем", "Владимир"
    };

    const std::vector<std::string> patronymics = {
        "Иванович", "Петрович", "Алексеевич", "Сергеевич", "Дмитриевич",
        "Андреевич", "Николаевич", "Федорович", "Васильевич", "Юрьевич"
    };

    int i1 = rand() % lastNames.size();
    int i2 = rand() % firstNames.size();
    int i3 = rand() % patronymics.size();

    return lastNames[i1] + " " + firstNames[i2] + " " + patronymics[i3];
}

std::vector<Person> generateTestData(int size) {
    std::vector<Person> data;

    for (int i = 0; i < size; ++i) {
        std::string name = randomFullName();
        int a = 1800 + rand() % (2025 - 1800);
        int b = 1800 + rand() % (2025 - 1800);
        int deathYear = std::max(a, b);
        int birthYear = std::min(a, b);
        int numChildren = rand() % 15;

        data.emplace_back(name, birthYear, deathYear, numChildren);
    }

    return data;
}
