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
            cards[i].setCardNumber(i + 1);
            cards[i].setCard(num, suit);
            cards[10 + i].setCardNumber(10 + i + 1);
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
    }

    // カードを表示する関数
    void printCard()
    {
        for (int i = 0; i < cardNum; i++)
        {
            cards[i].printCard();
        }
    }

    // カードをめくる関数
    void flipCard(int num)
    {
        cards[num].setFaceUp(true);
    }
};