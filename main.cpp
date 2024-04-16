#include <iostream>
#include "trampCard.cpp"

// 実行方法
// g++ -o main main.cpp card.cpp

using namespace std;

int main()
{
    // 5つのカードを作成
    TrampCard card1(1, Spade);
    TrampCard card2(13, Heart);
    TrampCard card3(10, Diamond);
    TrampCard card4(4, Club);
    TrampCard card5(0, Joker);

    // 5つのカードを表示
    card1.printCard();
    card2.printCard();
    card3.printCard();
    card4.printCard();
    card5.printCard();

    return 0;
}