#include <iostream>
#include "card.cpp"

// 実行方法
// g++ -o main main.cpp card.cpp

using namespace std;

int main()
{
    // 4つのカードを作成
    TrampCard card1 = {1, Spade};
    TrampCard card2 = {13, Heart};
    TrampCard card3 = {10, Diamond};
    TrampCard card4 = {4, Club};

    // 4つのカードを表示
    card1.printCard();
    card2.printCard();
    card3.printCard();
    card4.printCard();

    return 0;
}