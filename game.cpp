#include <iostream>
#include "player.cpp"

using namespace std;

// ゲームの進行を管理するクラス
class Game
{
private:
    // プレイヤー
    Player player[2];
    // カード
    GameCard cards[20];

public:
    // コンストラクタ
    Game()
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

        // 10組のカードを生成
        for (int i = 0; i < 10; i++)
        {
            // 重複判定用のフラグ
            bool isDuplicate = false;
            // 数字初期化
            int num = 0;
            // マーク初期化
            Suit suit;

            // 今までに生成したカードと重複しないようにする
            do
            {
                // 1~10の数字をランダムに生成
                num = rand() % 10 + 1;

                // suitをランダムに生成
                int random = rand() % 41;
                if (random == 0) // Jokerは1/41の確率で生成する
                {
                    suit = Joker;
                }
                else // それ以外は1/4の確率で生成する
                {
                    switch (random % 4)
                    {
                    case 0:
                        suit = Spade;
                        break;
                    case 1:
                        suit = Heart;
                        break;
                    case 2:
                        suit = Diamond;
                        break;
                    case 3:
                        suit = Club;
                        break;
                    }
                }

                // 重複判定
                for (int j = 0; j < i; j++)
                {
                    isDuplicate = false;

                    if (cards[j].getNumber() == num && cards[j].getSuit() == suit)
                    {
                        isDuplicate = true;
                        break;
                    }
                    else if (suit == Joker && cards[j].getSuit() == Joker)
                    {
                        isDuplicate = true;
                        break;
                    }
                }
            } while (isDuplicate);

            cout << "card" << i + 1 << " | num: " << num << ", suit: " << suit << endl;
            cards[i].setCardNumber(i + 1);
            cards[i].setCard(num, suit);
            cards[10 + i].setCardNumber(10 + i + 1);
            cards[10 + i].setCard(num, suit);
        }
    }

    // ゲームを開始する関数
    void startGame()
    {
        cout << player[0].getName() << " vs " << player[1].getName() << endl;

        // カードをシャッフル
        for (int i = 0; i < 100; i++)
        {
            int random1 = rand() % 20;
            int random2 = rand() % 20;
            GameCard tmp = cards[random1];
            cards[random1] = cards[random2];
            cards[random2] = tmp;
        }

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
                        player[i % 2].flipCard(cards[flipCardNumber[flipCount] - 1]);
                        flipCount++;
                    }
                }
            }
            if (cards[flipCardNumber[0] - 1].getNumber() == cards[flipCardNumber[1] - 1].getNumber() && cards[flipCardNumber[0] - 1].getSuit() == cards[flipCardNumber[1] - 1].getSuit())
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