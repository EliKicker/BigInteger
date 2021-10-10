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

int BigInteger::takeSign(std::vector<uint64> &a) {
    if ((int) ((a[a.size() - 1] & 0x8000000000000000) >> 63) == 1) {
        a[a.size() - 1] = a[a.size() - 1] ^ 0x8000000000000000;
        TrimLeadingZeros(a);
        return 1;
    } else {
        TrimLeadingZeros(a);
        return 0;
    }
}

void BigInteger::setSign(int sign) {
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
    int sign = (s[0] == '-') ? 1 : 0;
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

void BigInteger::Print(BigInteger a) {
    string result;
    int sign;
    if (!a.bigInt.empty()) {
        sign = takeSign(a.bigInt);
        std::cout << ((sign == 1) ? "-" : "");
        std::cout << getDecimalString(a.bigInt);
    }
    //std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const BigInteger &a) {
    BigInteger::Print(a);
    return os;
}

std::istream &operator>>(std::istream &is, BigInteger &a) {
    string s;
    std::getline(is, s);
    a = BigInteger(s);
    return is;
}