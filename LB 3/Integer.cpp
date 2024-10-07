#include "Integer.h"

Integer::Integer() {
    m_number.push_back(0);
}

Integer::Integer(ull num) {
    std::string s = std::to_string(num);
}

Integer::Integer(std::string num) {
    int i = num.length();
    while (i > 0) {
        int start = (i - 3 > 0) ? i - 3 : 0;
        m_number.push_back(std::stoi(num.substr(start, i - start)));
        i -= 3;
    }
}

Integer::Integer(std::vector<int> &num) {
    m_number = num;
}

Integer::Integer(const Integer& obj): m_number(obj.m_number), m_d(obj.m_d) {}

Integer Integer::operator=(const Integer& obj) {
    m_number = obj.m_number;
    m_d = obj.m_d;
    return *this;
}

bool Integer::operator==(const Integer &obj) const {
    if (m_number.size() == obj.m_number.size()) {
        for (int i = m_number.size() - 1; i >= 0; i--) {
            if (m_number[i] != obj.m_number[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Integer::operator>(const Integer &obj) const {
    if (m_number.size() < obj.m_number.size()) {
        return false;
    }
    else if (m_number.size() > obj.m_number.size()) {
        return true;
    }
    else {
        for (int i = m_number.size() - 1; i >= 0; i--) {
            if (m_number[i] > obj.m_number[i]){
                return true;
            }
            else if (m_number[i] < obj.m_number[i]) {
                return false;
            }
        }
    }
    return false;
}

bool Integer::operator!= (const Integer &obj) const{
    return (*this == obj);
}

bool Integer::operator<(const Integer &obj) const {
    return (obj > *this);
}

bool Integer::operator<= (const Integer &obj) const {
    return !(*this > obj);
}

bool Integer::operator>= (const Integer &obj) const {
    return !(*this < obj);
}

Integer Integer::operator+(const Integer &obj) const {
    int buf = 0;
    Integer min, max;
    std::vector<int> res;
    (*this < obj) ? min = *this : min = obj;
    (*this > obj) ? max = *this : max = obj;
    for (int i = 0; i < min.m_number.size(); i++) {
        int sum = max.m_number[i] + min.m_number[i];
        res.push_back((sum % m_d) + buf);
        buf = sum / m_d;
    }
    for (int i = min.m_number.size(); i < max.m_number.size(); i++) {
        int sum = max.m_number[i] + buf;
        res.push_back(sum % m_d);
        buf = sum / m_d;
    }

    if (buf) {
        res.push_back(buf);
    }
    return Integer(res);
}

void Integer::print() const {
    for (int i = m_number.size() - 1; i >= 0; i--) {
        std::string buf = std::to_string(m_number[i]);
        if (buf.length() != 3 && i != m_number.size() - 1) {
            buf = "0" + buf;
        }
        std::cout << buf;

    }
    std::cout << "\n";
}