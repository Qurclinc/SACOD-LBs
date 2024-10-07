#include <iostream>
#include <vector>
#include <string>

typedef unsigned long long ull;

class Integer {
private:
    int m_d = 1000;
    std::vector<int> m_number;

public:
    Integer();
    Integer(ull num);
    Integer(std::string num);
    Integer(std::vector<int> &num);
    Integer(const Integer &obj);

    Integer operator=(const Integer &obj);
    bool operator==(const Integer &obj) const;
    bool operator>(const Integer &obj) const;

    bool operator!=(const Integer &obj) const;
    bool operator>=(const Integer &obj) const;
    bool operator<(const Integer &obj) const;
    bool operator<=(const Integer &obj) const;

    Integer operator+(const Integer &obj) const;

    void print() const;


};