#include <iostream>

using namespace std;

// トランプのマークを表す列挙型
enum Suit{
    Spade = '&', // スペード
    Heart = '%', // ハート
    Diamond = '*', // ダイヤ
    Club = '#' // クラブ
};

// トランプのカードを表す構造体
struct TrampCard{
    int number; // 数字
    Suit suit; // スート
    // トランプのカードを表示する関数
    void printCard(){
        // スートを表示
        cout << static_cast<char>(suit) << " ";
        // 数字を表示(2文字で表示)
        if(number < 10){
            cout << " ";
        }
        cout << number << endl;
    }
};
