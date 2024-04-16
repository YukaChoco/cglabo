#include <iostream>
#include "card.cpp"

// 実行方法
// g++ -o main main.cpp card.cpp

using namespace std;

int main(){
    // 4つのカードを作成
    Card card1 = {1, Spade};
    Card card2 = {13, Heart};
    Card card3 = {10, Diamond};
    Card card4 = {4, Club};

    // 4つのカードを表示
    card1.printCard();
    card2.printCard();
    card3.printCard();
    card4.printCard();

    return 0;
}