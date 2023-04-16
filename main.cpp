#include "Seqlist/SeqList.hpp"
#include <limits>
#include <cstdio>
#include <functional>
#include <cstdio>
#include <functional>
#include <string>
#include <thread>
#include <string>
#include <list>
#include <iterator>
using namespace std;
int main() {
    list<int> l;
    for (int i = 1; i <= 10; ++i) {
        l.ins   ert(l.end(), i);
    }
    for (auto i : l) {
        cout << i << endl;
    }
    system("pause");
}
