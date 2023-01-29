/* 
    ADT 线性表 (List)   //  NOTE 数组实现
    DATA
    数据对象集合为 {  ， ，  } ,每个元素的类型均为 DataType
    Operation
    InitList(): 初始化操作，建立一个空的线性表 
    ListEmpty(): 若线性表为空，返回 true ,否则返回 false
    ClearList(): 将线性表清空
    GetElem( L, i, *e): 将线性表 L 中第 i 个位置元素值返回给 e
    LocateElem( L, e): 查找与给定值 e 相等的元素，查找成功，返回序号，否则返回 0
    ListInsert( *L, i, e): 线性表 L 中第 i 个位置插入新元素 e
    ListDelete( *L, i, *e): 删除线性表 L 中第 i 个位置元素，用 e 返回其值
    ListDelete( *L, i): 删除线性表 L 中第 i 个位置元素
    ListLength()( L ): 返回线性表 L 的元素个数
    endADT
*/
#include <iostream>
typedef int DataType;
using namespace std;
class mySqlList {
public:
    mySqlList() {}
    mySqlList(int tempCapacity) : capacity(tempCapacity) {
        this->array = new DataType[this->capacity];
        this->length = 0;
    }
    bool initList() {
        if (!array) {
            return false;
        }
        return true;
    }
    bool listEmpty() {
        if (!listLength()) {
            return true;
        }
        return false;
    }
    void getElem(int index, DataType& element) {
        if (index < 1 || index > listLength()) {
            cout << "get element was useless" << endl;
            return;
        }
        element = array[index - 1];
    }

    /// @brief 查找与给定值 e 相等的元素，查找成功，返回序号，否则返回 0 (二分查找)
    /// @param element 值 e
    /// @return 返回查找元素的序号 successful return index, unsuccessful return 0

    int locateElem(const DataType& element) {
        int left = 0;
        int right = listLength() - 1;
        while (left <= right) {
            int middle = left + (right - left) >> 1;
            if (array[middle] < element) {
                left = middle + 1;
            } else if (array[middle] > element) {
                right = middle - 1;
            } else {
                return middle + 1;
            }
        }
        return 0;
    }

    bool listInsert(int index, DataType element) {
        if (index < 1 || index - 1 > listLength() || listLength() == this->capacity) {
            return false;
        }
        this->array[index - 1] = element;
        ++length;
        return true;
    }
    bool listDelete(int index) {
        if (index < 1 || index > listLength()) {
            return false;
        }
        while (index < length) {
            this->array[index - 1] = this->array[index];
            ++index;
        }
        --length;
        return true;
    }
    bool listDelete(int index, DataType& element) {
        if (index < 1 || index > listLength()) {
            return false;
        }
        element = this->array[index - 1];
        while (index < length) {
            this->array[index - 1] = this->array[index];
            ++index;
        }
        return true;
    }
    int listLength() {
        return length;
    }
    bool printList() {
        if (listEmpty()) {
            cout << "list is empty" << endl;
            return false;
        }
        for (int i = 0; i < listLength(); ++i) {
            cout << this->array[i] << ' ';
        }
        cout << endl;
        return true;
    }
    ~mySqlList() {
        if (array) {
            delete [] array;
        }
    }

private:
    int capacity = 0;
    int length = 0;
    DataType * array = NULL;
};

int main()
{
    mySqlList list(8);
    system("pause");
    return 0;
}
