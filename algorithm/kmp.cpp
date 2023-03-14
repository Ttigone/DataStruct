#include <iostream>
#include <vector>


using namespace std;

class kmp {
public:
    vector<int> getNext(const vector<char>& c_String) {
        vector<int> m_next;
        m_next.resize(c_String.size());
        switch (c_String.size()) {
          case 0: {
            return {};     
          }
          case 1: {
            return {-1};
          }
          case 2: {
            return {-1, 0};
          }
          default: {
            m_next[0] = -1;
            m_next[1] = 0;
            for (int i = 2; i < c_String.size(); ++i) {
                // cout << i;
                if (c_String[i - 1] == c_String[m_next[i - 1]])
                    m_next[i] = m_next[i - 1] + 1; 
                else {
                    int cur = m_next[i - 1]; // 
                    while (c_String[i - 1] != c_String[cur]) {
                        cur = m_next[cur];
                        if (cur == -1)
                            break;
                    }
                    m_next[i] = cur + 1; 
                }
            }
          }
        }
        return m_next;
    }
    vector<int> nextToVal(const vector<char>& c_String, const vector<int>& next) {
        vector<int> m_nextVal;
        m_nextVal.resize(next.size());
        m_nextVal[0] = {-1}; m_nextVal[1] = {0};
        for (int i = 2; i < next.size(); ++i) {
            if (c_String[i] == c_String[next[i]]) {
                m_nextVal[i] = m_nextVal[next[i]];
            } else {
                m_nextVal[i] = next[i];
            }
        }
        return m_nextVal;
    }
    int getIndexOfFirstletter(const vector<char>& o_String, 
                              const vector<char>& c_String,
                              const vector<int>& next) {
        int i = 0, j = 0;
        while (i < o_String.size() && j < c_String.size()) {
            if (o_String[i] == c_String[j]) {
                ++i, ++j;
            } else {
                j = next[j];
                if (j == -1) {
                    j = 0;
                    ++i;
                }
            }
        }
        if (j >= c_String.size()) {
            return i - c_String.size();
        } else return -1;
    }
};

int main(void)
{
    vector<char> originalString{'a', 'b', 'a', 'a', 'd', 'a', 'b', 'a', 'a', 'b', 'c', 'f'};
    // cout << originalString.size();
    vector<char> contrastString{'a', 'b', 'a', 'a', 'b'};
    kmp t;
    int index = t.getIndexOfFirstletter(originalString, contrastString, t.getNext(originalString));
    cout << index;
    system("pause");
    return 0;
}