#include <iostream>

using std::cout;
using std::endl;

namespace myhanoi {

void move(char x, int n, char z) {
    static int c = 0;
    cout << "Step number " << ++c << " Move the number of discs from " << x << " to "  << z << endl;

}


void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        move(x, n, z);
    } else {
        hanoi(n - 1, x, z, y);
        move(x, n, z);
        hanoi(n - 1, y, x, z);
    }
}

}