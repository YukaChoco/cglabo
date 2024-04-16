#include <iostream>
#include "player.cpp"

// 実行方法
// g++ -o main main.cpp card.cpp

using namespace std;

int main()
{
    // 2名のプレイヤーを生成
    Player player[] = {Player(1), Player(2)};

    // プレイヤーの名前を設定
    player[0].setName();
    player[1].setName();

    cout << player[0].getName() << " vs " << player[1].getName() << endl;

    // プレイヤーのスコアを表示
    cout << player[0].getName() << " のスコア: " << player[0].getScore() << endl;
    cout << player[1].getName() << " のスコア: " << player[1].getScore() << endl;

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