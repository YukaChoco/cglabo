#include <iostream>

using namespace std;

// トランプのマークを表す列挙型
enum Suit
{
    Spade = '&',   // スペード
    Heart = '%',   // ハート
    Diamond = '*', // ダイヤ
    Club = '#',    // クラブ
    Joker = 'J'    // ジョーカー
};

// トランプのカードを表す構造体
struct TrampCard
{
    // コンストラクタ
    TrampCard() {}

protected:
    int number; // 数字
    Suit suit;  // スート

public:
    // カードを設定する関数
    void setCard(int num, Suit st)
    {
        number = num;
        suit = st;
    }
    // 数字を取得する関数
    int getNumber()
    {
        return number;
    }
    // スートを取得する関数
    Suit getSuit()
    {
        return suit;
    }

    // トランプのカードを表示する関数
    void printTramp()
    {
        // ジョーカーの場合は数字を表示しない
        if (suit == Joker)
        {
            cout << " *Joker*";
        }
        else
        {
            // スートを表示
            cout << "  " << static_cast<char>(suit) << " ";
            // 数字を表示(2文字で表示)
            if (number < 10)
            {
                cout << " ";
            }
            cout << number << "  ";
        }
    }
};
