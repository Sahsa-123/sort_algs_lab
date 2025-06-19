#include "class.h"

Person::Person(std::string name, int birth, int death, int children)
    : fullName(name), birthYear(birth), deathYear(death), numChildren(children) {}

bool Person::operator<(const Person& other) const {
    if (birthYear != other.birthYear)
        return birthYear < other.birthYear;
    if (fullName != other.fullName)
        return fullName < other.fullName;
    return numChildren < other.numChildren;
}

bool Person::operator>(const Person& other) const {
    return other < *this;
}

bool Person::operator<=(const Person& other) const {
    return !(*this > other);
}

bool Person::operator>=(const Person& other) const {
    return !(*this < other);
}
