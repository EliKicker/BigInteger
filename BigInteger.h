//This is a datatype for a 64 bit register

#ifndef BIGINTEGER_BIGINTEGER_H
#define BIGINTEGER_BIGINTEGER_H
#include <bits/stdc++.h>

using std::string;
typedef unsigned long long uint64;

class BigInteger {
    private:
        static string binBitShift(string dec_num);
        static string DecToBin(string dec);
        static string getDecimalString(std::vector<uint64> a);

    protected:
        std::vector<uint64> bigInt;
        void setSign(int sign);
        static int takeSign(std::vector<uint64> &a);
        static void TrimLeadingZeros(std::vector<uint64> &a);

    public:
        //Debug
        void Debug();
        //End Debug

        BigInteger();
        explicit BigInteger(string s);
        static void Print(std::ostream &os, BigInteger a);
        //static BigInteger Parse(string s);

        //operators
        friend std::ostream& operator<<(std::ostream &os, const BigInteger &a);
        friend std::istream& operator>>(std::istream &is, BigInteger &a);
        friend bool operator<(BigInteger a, BigInteger b);
        friend bool operator>(BigInteger a, BigInteger b);
        friend bool operator==(BigInteger a, BigInteger b);
        friend bool operator<=(BigInteger a, BigInteger b);
        friend bool operator>=(BigInteger a, BigInteger b);
        friend bool operator<(BigInteger a, int b);
        friend bool operator>(BigInteger a, int b);
        friend bool operator==(BigInteger a, int b);
        friend bool operator<=(BigInteger a, int b);
        friend bool operator>=(BigInteger a, int b);
        friend bool operator<(int a, BigInteger b);
        friend bool operator>(int a, BigInteger b);
        friend bool operator==(int a, BigInteger b);
        friend bool operator<=(int a, BigInteger b);
        friend bool operator>=(int a, BigInteger b);
        friend BigInteger operator+(BigInteger a, BigInteger b);
        friend BigInteger operator+(BigInteger a, int b);
        friend BigInteger operator+(int a, BigInteger b);
        friend BigInteger operator++(BigInteger &a);
        friend BigInteger operator+=(BigInteger &a, BigInteger b);
        friend BigInteger operator+=(BigInteger &a, int b);
        //end operators
};

//operator prototypes
std::ostream& operator<<(std::ostream &os, const BigInteger &a);
std::istream& operator>>(std::istream &is, BigInteger &a);
bool operator<(BigInteger a, BigInteger b);
bool operator>(BigInteger a, BigInteger b);
bool operator==(BigInteger a, BigInteger b);
bool operator<=(BigInteger a, BigInteger b);
bool operator>=(BigInteger a, BigInteger b);
bool operator<(BigInteger a, int b);
bool operator>(BigInteger a, int b);
bool operator==(BigInteger a, int b);
bool operator<=(BigInteger a, int b);
bool operator>=(BigInteger a, int b);
bool operator<(int a, BigInteger b);
bool operator>(int a, BigInteger b);
bool operator==(int a, BigInteger b);
bool operator<=(int a, BigInteger b);
bool operator>=(int a, BigInteger b);
BigInteger operator+(BigInteger a, BigInteger b);
BigInteger operator+(BigInteger a, int b);
BigInteger operator+(int a, BigInteger b);
BigInteger operator++(BigInteger &a);
BigInteger operator+=(BigInteger &a, BigInteger b);
BigInteger operator+=(BigInteger &a, int b);
//end operator prototypes

#endif //BIGINTEGER_BIGINTEGER_H