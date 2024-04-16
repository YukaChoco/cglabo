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
