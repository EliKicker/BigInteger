#include <iostream>
#include "BigInteger.h"

using std::cout;
using std::endl;

int main() {
    BigInteger newBigInt1("-1");
    BigInteger newBigInt2("-18446744073709551614");
    cout << newBigInt1 << endl;
    cout << newBigInt2 << endl;
    BigInteger b = newBigInt1 + newBigInt2;
    cout << b << endl;
    return 0;
}