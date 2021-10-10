#include <iostream>
#include "BigInteger.h"

using std::cout;
using std::endl;

int main() {
    BigInteger newBigInt1("123879431782134432678237845679");
    BigInteger newBigInt2("-123879431782134432678237845678");
    cout << std::boolalpha << (newBigInt1 >= newBigInt2) << endl;
    cout << newBigInt1 << endl;
    cout << newBigInt2 << endl;
    return 0;
}