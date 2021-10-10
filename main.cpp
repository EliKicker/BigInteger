#include <iostream>
#include "BigInteger.h"

using std::cout;
using std::endl;

int main() {
    BigInteger newBigInt("-123879431782134432678237845678");
    cout << newBigInt << endl;
    BigInteger a;
    std::cin >> a;
    cout << a << endl;
    return 0;
}