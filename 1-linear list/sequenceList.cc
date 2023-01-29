/* 
    ADT ���Ա� (List)   //  NOTE ����ʵ��
    DATA
    ���ݶ��󼯺�Ϊ {  �� ��  } ,ÿ��Ԫ�ص����;�Ϊ DataType
    Operation
    InitList(): ��ʼ������������һ���յ����Ա� 
    ListEmpty(): �����Ա�Ϊ�գ����� true ,���򷵻� false
    ClearList(): �����Ա����
    GetElem( L, i, *e): �����Ա� L �е� i ��λ��Ԫ��ֵ���ظ� e
    LocateElem( L, e): ���������ֵ e ��ȵ�Ԫ�أ����ҳɹ���������ţ����򷵻� 0
    ListInsert( *L, i, e): ���Ա� L �е� i ��λ�ò�����Ԫ�� e
    ListDelete( *L, i, *e): ɾ�����Ա� L �е� i ��λ��Ԫ�أ��� e ������ֵ
    ListDelete( *L, i): ɾ�����Ա� L �е� i ��λ��Ԫ��
    ListLength()( L ): �������Ա� L ��Ԫ�ظ���
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

    /// @brief ���������ֵ e ��ȵ�Ԫ�أ����ҳɹ���������ţ����򷵻� 0 (���ֲ���)
    /// @param element ֵ e
    /// @return ���ز���Ԫ�ص���� successful return index, unsuccessful return 0

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
