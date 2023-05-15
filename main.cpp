#include "./Seqlist/SeqList.hpp"
#include "./Linklist/LinkList.hpp"

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
#include <vector>


using namespace std;


int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 6, 6, 4};
    // my_linklist::LinkList<int> l(a);
    my_seqlist::SeqList<int> sql(b, 4);
    sql.Delete_Element(6);
    system("pause");
}
