//This is a datatype for a 64 bit register

#include <bits/stdc++.h>
#include "BigInteger.h"

using std::string;
typedef unsigned long long uint64;
const uint64 base = 0xFFFFFFFFFFFFFFFF;
std::vector<uint64> bigInt;

//Debug
void BigInteger::Debug() {
    std::cout << &bigInt << std::endl;
}
//End Debug

void BigInteger::TrimLeadingZeros(std::vector<uint64> &a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}

int BigInteger::takeSign(std::vector<uint64> &a) { //0 - pos && 1 - neg
    if ((int) ((a[a.size() - 1] & 0x8000000000000000) >> 63) == 1) {
        a[a.size() - 1] = a[a.size() - 1] ^ 0x8000000000000000;
        TrimLeadingZeros(a);
        return -1;
    } else {
        TrimLeadingZeros(a);
        return 1;
    }
}

void BigInteger::setSign(int sign) {
    (sign == -1) ? sign = 1 : sign = 0; //0 - pos && 1 - neg
    if ((bigInt[bigInt.size() - 1] & 0x8000000000000000) == 0) {
        bigInt[bigInt.size() - 1] ^= sign * 0x8000000000000000;
    } else {
        bigInt.insert(bigInt.end(), sign * 0x8000000000000000);
    }
}

string BigInteger::binBitShift(string dec_num) {
    int carry, next = 0;
    for (char &i : dec_num) {
        carry = next;
        (((i - 48) & 1) != 0) ? next = 5 : next = 0;
        i = (char) (((int) (i - 48) >> 1) + carry + 48);
    }
    size_t s = dec_num.find_first_not_of('0');
    (s != std::string::npos) ? dec_num = dec_num.substr(s, dec_num.size() - s) : dec_num = '0';
    return dec_num;
}

string BigInteger::DecToBin(string dec) {
    if (dec[0] == '-') dec[0] = '0';
    string result;
    while (dec != "0") {
        (((dec[dec.size() - 1] - 48) & 1) != 0) ? result = '1' + result : result = '0' + result;
        dec = binBitShift(dec);
    }
    return result;
}

string BigInteger::getDecimalString(std::vector<uint64> a) {
    string result;
    //while (result.empty() || (result.size() & 0x3F) != 0) result = '0' + result;
    for (int i = 0; i < a.size() * 64; i += 64) {
        uint64 num = a[a.size() - 1 - i / 64];
        for (int k = 0; k < 64; k++) {
            if (result[0] != '0') result = '0' + result;
            //Check cols
            for (int j = result.size() - 1; j >= 0; j--) {
                if (result[j] - 48 >= 5) {
                    result[j] = (char) (result[j] + 3);
                }
            }

            //Bitshift
            for (int j = 0; j < result.size() - 1; j++) {
                result[j] = (char) (((((result[j] - 48) << 1) + ((result[j + 1] - 48) >> 3)) & 0xF) + 48);
            }
            result[result.size() - 1] = (char) (((((result[result.size() - 1] - 48) << 1) + ((num & (0x8000000000000000 >> k)) >> (63 - k))) & 0xF) + 48);
        }
    }
    size_t s;
    if ((s = result.find_first_not_of('0')) != std::string::npos) result.erase(0, s);
    return result;
}

BigInteger::BigInteger() = default;

BigInteger::BigInteger(string s) {
    int sign = (s[0] == '-') ? -1 : 1;
    s = DecToBin(s);
    while ((s.size() & 0x3F) != 0) s = '0' + s; //64 bit Padding
    for (int i = 0; i < s.size(); i += 64) {
        uint64 temp = 0;
        for (int j = i; j < i + 64; j++) {
            temp += (s[j] - 48) * (0x8000000000000000 >> (j - i));
        }
        bigInt.insert(bigInt.begin(), temp);
    }
    setSign(sign);
}

void BigInteger::Print(std::ostream &os, BigInteger a) {
    string result;
    int sign;
    if (!a.bigInt.empty()) {
        sign = takeSign(a.bigInt);
        os << ((sign == -1) ? "-" : "");
        os << getDecimalString(a.bigInt);
    }
}

std::ostream &operator<<(std::ostream &os, const BigInteger &a) {
    BigInteger::Print(os, a);
    return os;
}

std::istream &operator>>(std::istream &is, BigInteger &a) {
    string s;
    std::getline(is, s);
    a = BigInteger(s);
    return is;
}

bool operator<(BigInteger a, BigInteger b) {
    int sgn_a = BigInteger::takeSign(a.bigInt), sgn_b = BigInteger::takeSign(b.bigInt);
    if (sgn_a == -1 && sgn_b != -1) {a.setSign(sgn_a); b.setSign(sgn_b); return true;}
    if (sgn_a != -1 && sgn_b == -1) {a.setSign(sgn_a); b.setSign(sgn_b); return false;}
    if (a.bigInt.size() != b.bigInt.size()) {a.setSign(sgn_a); b.setSign(sgn_b); return (sgn_a == -1 && sgn_b == -1) ? a.bigInt.size() > b.bigInt.size() : a.bigInt.size() < b.bigInt.size();}
    for (int i = a.bigInt.size() - 1; i >= 0; i--) {
        if (a.bigInt[i] != b.bigInt[i]) {a.setSign(sgn_a); b.setSign(sgn_b); return (sgn_a == -1 && sgn_b == -1) ? a.bigInt[i] > b.bigInt[i] : a.bigInt[i] < b.bigInt[i];}
    }
    a.setSign(sgn_a);
    b.setSign(sgn_b);
    return false;
}

bool operator>(BigInteger a, BigInteger b) {
    return b < a;
}

bool operator==(BigInteger a, BigInteger b) {
    int sgn_a = BigInteger::takeSign(a.bigInt), sgn_b = BigInteger::takeSign(b.bigInt);
    if (sgn_a != sgn_b) {a.setSign(sgn_a); b.setSign(sgn_b); return false;}
    if (a.bigInt.size() != b.bigInt.size()) {a.setSign(sgn_a); b.setSign(sgn_b); return false;}
    for (int i = a.bigInt.size() - 1; i >= 0; i--) {
        if (a.bigInt[i] != b.bigInt[i]) {a.setSign(sgn_a); b.setSign(sgn_b); return false;}
    }
    a.setSign(sgn_a);
    b.setSign(sgn_b);
    return true;
}

bool operator<=(BigInteger a, BigInteger b) {
    return a < b || a == b;
}

bool operator>=(BigInteger a, BigInteger b) {
    return b < a || b == a;
}

bool operator<(BigInteger a, int b) {
    return a < BigInteger(std::to_string(b));
}

bool operator>(BigInteger a, int b) {
    return BigInteger(std::to_string(b)) < a;
}

bool operator==(BigInteger a, int b) {
    return a == BigInteger(std::to_string(b));
}

bool operator<=(BigInteger a, int b) {
    return a <= BigInteger(std::to_string(b));
}

bool operator>=(BigInteger a, int b) {
    return a >= BigInteger(std::to_string(b));
}

bool operator<(int a, BigInteger b) {
    return BigInteger(std::to_string(a)) < b;
}

bool operator>(int a, BigInteger b) {
    return b < BigInteger(std::to_string(a));
}

bool operator==(int a, BigInteger b) {
    return BigInteger(std::to_string(a)) == b;
}

bool operator<=(int a, BigInteger b) {
    return BigInteger(std::to_string(a)) <= b;
}

bool operator>=(int a, BigInteger b) {
    return BigInteger(std::to_string(a)) >= b;
}

BigInteger operator+(BigInteger a, BigInteger b) {
    return BigInteger();
}

BigInteger operator+(BigInteger a, int b) {
    return BigInteger();
}

BigInteger operator+(int a, BigInteger b) {
    return BigInteger();
}

BigInteger operator++(BigInteger &a) {
    return BigInteger();
}

BigInteger operator+=(BigInteger &a, BigInteger b) {
    return BigInteger();
}

BigInteger operator+=(BigInteger &a, int b) {
    return BigInteger();
}