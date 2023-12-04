#ifndef DS_BAG_HPP
#define DS_BAG_HPP

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(1010, vector<int>(1010, 0));

namespace Bag {

class BagProblem {
public:
    BagProblem(int n, int c);

public:
    void setWightAndValue(int wight, int value);
    void showBag() {
        for (auto i : bagItem) {
            cout << "wight: " << i.first << " value: " << i.second << endl;
        }
        cout << endl;
    }
    int slove(int k, int m);

private:
    int stealNum = 0;
    int capacity = 0;
    pair<int, int> Item;
    vector<pair<int, int>> bagItem;

};


BagProblem::BagProblem(int n, int c) : stealNum(n), capacity(c), bagItem() { }

void BagProblem::setWightAndValue(int wight, int value) {
    Item = make_pair(wight, value);
    bagItem.push_back(Item);
}

// k 当前可以偷的数量
// m 当前的背包容量
int BagProblem::slove(int k, int w) {
    for (int i = 1; i <= k; ++i) {         // 物品       
        for (int j = 1; j <= w; ++j) {               // 背包容量    
            if (bagItem[i - 1].first > j) {  // 重量过大
                dp[i][j] = dp[i - 1][j];       // 不放置
            } else {
                dp[i][j] = max(dp[i - 1].at(j), dp[i - 1].at(j - bagItem[i - 1].first) + bagItem[i - 1].second);
            }
        }
    }
    return dp[k][w];
}

}



#endif //DS_BAG_HPP
