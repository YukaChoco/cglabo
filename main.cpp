#include <iostream>
#include "gameCard.cpp"

// 実行方法
// g++ -o main main.cpp card.cpp

using namespace std;

int main()
{
    // 5つのカードを生成
    GameCard cards[] = {
        GameCard(1, 5, Spade),
        GameCard(2, 10, Heart),
        GameCard(3, 12, Diamond),
        GameCard(4, 4, Club),
        GameCard(5, 3, Joker),
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