#include <iostream>
#include "BigInteger.h"

using std::cout;
using std::endl;

int main() {
    BigInteger newBigInt1("10000000000000000000000000000000000000");
    BigInteger newBigInt2("18446744073709551614"); //18446744073709551615
    cout << newBigInt1 << endl;
    cout << newBigInt2 << endl;
    BigInteger b = newBigInt1 - newBigInt2;
    cout << b << endl;
    cout << std::boolalpha << (newBigInt1 > newBigInt2) << endl;
    cout << std::boolalpha << (newBigInt1 < newBigInt2) << endl;
    return 0;
}