#include <iostream>

using namespace std;

// トランプのマークを表す列挙型
enum Suit{
    Spade = 'S', // スペード
    Heart = 'H', // ハート
    Diamond = 'D', // ダイヤ
    Club = 'C' // クラブ
};

// トランプのカードを表す構造体
struct Card{
    int number; // 数字
    Suit suit; // スート
    // トランプのカードを表示する関数
    void printCard(){
        // 数字を表示
        cout << number << "/";
        // スートを表示
        cout << static_cast<char>(suit) << endl;
    }
};

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