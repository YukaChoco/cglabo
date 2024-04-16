#include <iostream>
#include <cctype>
#include "gameCard.cpp"

using namespace std;

// ゲームの場を表すクラス
class PlayingField
{
private:
    // カードの枚数
    static const int cardNum = 20;
    // カードの列数
    static const int columnNum = 5;
    // カードの行数
    static const int rowNum = cardNum / columnNum;

public:
    // カードの配列
    GameCard cards[cardNum];

    // コンストラクタ
    PlayingField()
    {
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

            // カードを生成
            cards[i].setCard(num, suit);
            cards[10 + i].setCard(num, suit);
        }

        // カードをシャッフル
        for (int i = 0; i < cardNum; i++)
        {
            int random = rand() % cardNum;
            GameCard tmp = cards[i];
            cards[i] = cards[random];
            cards[random] = tmp;
        }

        // カード番号を設定
        for (int i = 0; i < cardNum; i++)
        {
            cards[i].setCardNumber(i + 1);
        }
    }

    // カードを表示する関数
    void printField()
    {
        cout << "\n\n\n\n\n";
        for (int i = 0; i < rowNum; i++)
        {
            cout << endl;
            cout << "+------------+    +------------+    +------------+    +------------+    +------------+" << endl;
            for (int j = 0; j < columnNum; j++)
            {
                cout << "|  ";
                cards[i * columnNum + j].printCard();
                cout << "  |    ";
            }
            cout << endl;
            cout << "+------------+    +------------+    +------------+    +------------+    +------------+" << endl;
        }
        cout << "\n\n\n\n\n";
    }

    // カードをめくる関数
    bool flipCard(int cardIndex)
    {
        if (cards[cardIndex].getPaired() == true)
        {
            cout << "Error: そのカードは既になくなっています" << endl;
            return false;
        }
        else if (cards[cardIndex].getFaceUp() == true)
        {
            cout << "Error: そのカードは既にめくられています" << endl;
            return false;
        }
        else
        {
            cards[cardIndex].setFaceUp(true);
            // 今の状態を表示
            printField();
            return true;
        }
    }

    // カードのペアが揃ったかどうかを判定する関数
    bool checkPair(int index1, int index2)
    {
        if (cards[index1].getNumber() == cards[index2].getNumber() && cards[index1].getSuit() == cards[index2].getSuit())
        {
            cards[index1].setPaired(true);
            cards[index2].setPaired(true);
            return true;
        }
        return false;
    }

    // 全てのカードがペアになったかどうかを判定する関数
    bool isAllPaired()
    {
        for (int i = 0; i < cardNum; i++)
        {
            if (cards[i].getPaired() == false)
            {
                return false;
            }
        }
        return true;
    }

    // カードの裏返しをリセットする関数
    void
    resetCard()
    {
        for (int i = 0; i < cardNum; i++)
        {
            cards[i].setFaceUp(false);
        }
    }
};