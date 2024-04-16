#include <iostream>
#include "player.cpp"

// 実行方法
// g++ -o main main.cpp card.cpp

using namespace std;

int main()
{
    // 2名のプレイヤーを生成
    Player player1;
    Player player2;

    // プレイヤーの名前を設定
    player1.setName();
    player2.setName();

    cout << player1.getName() << " vs " << player2.getName() << endl;

    // 5つのカードを生成
    GameCard cards[] = {
        GameCard(1, 5, Spade),
        GameCard(2, 10, Heart),
        GameCard(3, 12, Diamond),
        GameCard(4, 4, Club),
        GameCard(20, 3, Joker),
    };

    // 5つのカードを表示(表面)
    for (int i = 0; i < 5; i++)
    {
        cout << "カード" << i + 1 << endl;
        cards[i].printCard(true);
        cout << endl;
    }

    cout << ">>>>>>>>>>>>>>>>" << endl;

    // 5つのカードを表示(裏面)
    for (int i = 0; i < 5; i++)
    {
        cout << "カード" << i + 1 << endl;
        cards[i].printCard(false);
        cout << endl;
    }
}