// Copyright 2016
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

class Hero {
 public:
    enum attribute_t {ATTACK, DEFENSE, HEALING};

    Hero(std::string n = ""): m_name(n) {
        m_points.resize(3);
        std::fill(m_points.begin(), m_points.end(), 0);
    }

    // Setters
    void setAttack(int a) {
        m_points[ATTACK] = a;
    }
    void setDefense(int a) {
        m_points[DEFENSE] = a;
    }
    void setHealing(int a) {
        m_points[HEALING] = a;
    }

    // Getters
    int getAttack(void) const {
        return m_points[ATTACK];
    }
    int getDefense(void) const {
        return m_points[DEFENSE];
    }
    int getHealing(void) const {
        return m_points[HEALING];
    }
    std::string getName(void) const {
        return m_name;
    }

 private:
    std::string m_name;
    std::vector<int> m_points;
};

std::ostream & operator<< (std::ostream &_os, const Hero &_h) {
    _os << "{<" << _h.getName()
        << ">, A = " << _h.getAttack()
        << ", D = " << _h.getDefense()
        << ", H = " << _h.getHealing()
        << "}";

    return _os;
}

bool compareByName(const Hero &_h1, const Hero &_h2) {
    return _h1.getName() < _h2.getName();
}

int main(int argc, char const *argv[]) {
    std::vector<Hero> heros = {
        Hero("Hulk"),
        Hero("Batman"),
        Hero("Superman"),
        Hero("Spiderman"),
        Hero("Wolwerine")
    };

    enum heros_t {HULK, BATMAN, SUPERMAN, SPIDERMAN, WOLWERINE};

    heros[HULK].setAttack(10000);
    heros[HULK].setDefense(10000);
    heros[HULK].setHealing(10);

    heros[BATMAN].setAttack(100);
    heros[BATMAN].setDefense(10);
    heros[BATMAN].setHealing(10);

    heros[SUPERMAN].setAttack(200000);
    heros[SUPERMAN].setDefense(200000);
    heros[SUPERMAN].setHealing(2000);

    heros[WOLWERINE].setAttack(560);
    heros[WOLWERINE].setDefense(800);
    heros[WOLWERINE].setHealing(10000000);

    std::cout << ">>> Heroes list before sorting: [\n";
    std::copy(heros.begin(), heros.end(),
        std::ostream_iterator<Hero> (std::cout, "\n"));
    std::cout << "]\n";

    std::sort(heros.begin(), heros.end(), compareByName);

    std::cout << ">>> Heroes list after sorting: [\n";
    std::copy(heros.begin(), heros.end(),
        std::ostream_iterator<Hero> (std::cout, "\n"));
    std::cout << "]\n";

    return EXIT_SUCCESS;
}