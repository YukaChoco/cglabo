#include <iostream>
#include "player.cpp"
#include "playingField.cpp"

using namespace std;

// ゲームの進行を管理するクラス
class Game
{
private:
    // プレイヤー
    Player player[2];
    // カード
    PlayingField playingField;

public:
    // コンストラクタ
    Game() : playingField()
    {
        cout << "-------------------------------------------------" << endl;
        cout << "******************   神経衰弱   ******************" << endl;
        cout << "-------------------------------------------------\n"
             << endl;

        // プレイヤーの名前を設定
        player[0].setPlayerNumber(0);
        player[0].setName();
        player[1].setPlayerNumber(1);
        player[1].setName();
    }

    // ゲームを開始する関数
    void startGame()
    {
        cout << player[0].getName() << " vs " << player[1].getName() << endl;

        // ゲームを進行
        for (int i = 0; i < 20; i++)
        {
            cout << "----------" << endl;
            cout << "Player" << i % 2 + 1 << " のターン" << i + 1 << endl;

            // カードをめくる
            int flipCount = 0;
            int flipCardNumber[2] = {0, 0};
            while (flipCount < 2)
            {
                cout << "めくるカードの番号を入力してください(1~20): ";
                cin >> flipCardNumber[flipCount];
                if (flipCardNumber[flipCount] < 1 || flipCardNumber[flipCount] > 20)
                {
                    cout << "Error: 不適切な番号が入力されました" << endl;
                }
                else
                {
                    if (flipCount == 1 && flipCardNumber[0] == flipCardNumber[1])
                    {
                        cout << "Error: 同じカードを2回めくることはできません" << endl;
                    }
                    else
                    {
                        playingField.flipCard(flipCardNumber[flipCount]);
                        flipCount++;
                    }
                }
            }
            if (playingField.cards[flipCardNumber[0] - 1].getNumber() == playingField.cards[flipCardNumber[1] - 1].getNumber() && playingField.cards[flipCardNumber[0] - 1].getSuit() == playingField.cards[flipCardNumber[1] - 1].getSuit())
            {
                player[i % 2].addScore();
            }
        }

        // 結果を表示
        cout << "----------" << endl;
        cout << "結果" << endl;
        cout << "----------" << endl;
        cout << player[0].getName() << " のスコア: " << player[0].getScore() << endl;
        cout << player[1].getName() << " のスコア: " << player[1].getScore() << endl;
    }
};