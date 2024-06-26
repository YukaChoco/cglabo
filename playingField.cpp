#include <iostream>
#include <cctype>
#include "gameCard.cpp"

using namespace std;

// ゲームの場を表すクラス
class PlayingField
{
private:
    // カードの枚数
    static const int cardNum = 4;
    // カードの列数
    static const int columnNum = 2;
    // カードの行数
    static const int rowNum = cardNum / columnNum;

public:
    // カードの配列
    GameCard cards[cardNum];

    // コンストラクタ
    PlayingField()
    {
        // 乱数の初期化
        srand((unsigned)time(NULL));

        // 10組のカードを生成
        for (int i = 0; i < cardNum / 2; i++)
        {
            // 重複判定用のフラグ
            bool isDuplicate = false;
            // 数字初期化
            int numRandom = 0;
            // マーク初期化
            Suit suit;

            // 今までに生成したカードと重複しないようにする
            do
            {
                // 1~10の数字をランダムに生成
                numRandom = rand() % 10 + 1;

                // suitをランダムに生成
                int suitRandom = rand() % 41;
                if (suitRandom == 0) // Jokerは1/41の確率で生成する
                {
                    suit = Joker;
                }
                else // それ以外は1/4の確率で生成する
                {
                    switch (suitRandom % 4)
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

                    if (cards[j].getNumber() == numRandom && cards[j].getSuit() == suit)
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
            cards[i].setCard(numRandom, suit);
            cards[(cardNum / 2) + i].setCard(numRandom, suit);
        }

        // 全てのカードを表示
        for (int i = 0; i < cardNum; i++)
        {
            cout << "num:  " << cards[i].getNumber() << ",  suit:  " << static_cast<char>(cards[i].getSuit()) << endl;
        }
        cout << "suffle" << endl;

        // カードをシャッフル
        for (int i = 0; i < cardNum; i++)
        {
            int random = rand() % cardNum;
            GameCard temp = cards[i];
            cards[i] = cards[random];
            cards[random] = temp;
        }

        // カード番号を設定
        for (int i = 0; i < cardNum; i++)
        {
            cards[i].setCardNumber(i + 1);
            cout << "num:  " << cards[i].getNumber() << ",  suit:  " << static_cast<char>(cards[i].getSuit()) << endl;
        }
    }

    // カードの枚数を取得する関数
    int getCardNum()
    {
        return cardNum;
    }

    // カードを表示する関数
    void printField()
    {
        cout << "\n\n\n\n\n";
        for (int i = 0; i < rowNum; i++)
        {
            cout << endl;
            for (int j = 0; j < columnNum; j++)
            {
                cout << "+------------+    ";
            }
            cout << endl;
            for (int j = 0; j < columnNum; j++)
            {
                cout << "|  ";
                cards[i * columnNum + j].printCard();
                cout << "  |    ";
            }
            cout << endl;
            for (int j = 0; j < columnNum; j++)
            {
                cout << "+------------+    ";
            }
            cout << endl;
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