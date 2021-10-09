#include <iostream>
#include "BigInteger.h"

using std::cout;
using std::endl;

int main() {
    BigInteger newBigInt("-123879431782134432678237845678");
    int i = 0;
    BigInteger::Print(newBigInt);
    newBigInt.Debug();
    std::cout << &i << std::endl;
    return 0;
}