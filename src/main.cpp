#include <iostream>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include "Seqlist/SeqList.hpp"
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    SeqList<int> a;
    a.Insert(1, 1);
    a.Traverse();
    return 0;
}

