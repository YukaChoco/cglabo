#include <iostream>
#include <cctype>
#include "gameCard.cpp"

using namespace std;

// Playerクラス
class Player
{
private:
    // プレイヤーの名前
    string name;

public:
    // コンストラクタ
    Player() : name("") {}

    // 名前を設定する関数
    void setName() {
        cout << "名前を入力してください: ";
        cin >> name;
    }
    // 名前を取得する関数
    string getName() {
        return name;
    }

    // カードをめくる関数
    void flipCard(GameCard card)
    {
        // カードをめくる
        card.printCard(true);
    }
};
