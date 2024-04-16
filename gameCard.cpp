#include <iostream>
#include <cctype>
#include "trampCard.cpp"

using namespace std;

// ゲームで使用するカードをトランプのカードから派生させる
struct GameCard : public TrampCard
{
private:
    // 1~20の数字をメンバに持つ
    int cardNumber;
    // 表面か裏面かを判定するフラグ
    bool isFaceUp;
    // ペアが揃ったかどうかを判定するフラグ
    bool isPaired;

public:
    // コンストラクタ
    GameCard() : isFaceUp(false), isPaired(false), TrampCard() {}

    // cardNumberを設定する関数
    void setCardNumber(int num)
    {
        cardNumber = num;
    }

    // 裏表を取得する関数
    bool getFaceUp()
    {
        return isFaceUp;
    }
    // 裏表を設定する関数
    void setFaceUp(bool faceUp)
    {
        isFaceUp = faceUp;
    }

    // ペアが揃ったかどうかを取得する関数
    bool getPaired()
    {
        return isPaired;
    }
    // ペアが揃ったかどうかを設定する関数
    void setPaired(bool paired)
    {
        isPaired = paired;
    }

    // カードを表示する関数
    void printCard()
    {
        cout << "+------------+" << endl;
        cout << "|            |" << endl;
        cout << "|  ";
        // 表面を表示する場合

        if (isPaired)
        {
            printBlankCard();
        }
        else if (isFaceUp)
        {
            printTramp();
        }
        else
        {
            printBack();
        }
        cout << "  |" << endl;
        cout << "|            |" << endl;
        cout << "+------------+" << endl;
    }
    // 既にめくり終えた部分を表示する関数
    void printBlankCard()
    {
        cout << "              " << endl;
        cout << "              " << endl;
        cout << "              " << endl;
        cout << "              " << endl;
        cout << "              " << endl;
    }

private:
    // カードの裏面を表示する関数
    void printBack()
    {
        // cardNumberが1~20でない場合はエラーを表示
        if (cardNumber < 1 || cardNumber > 20)
        {
            cout << "Error: 不適切なcardNumberが渡されました" << endl;
            return;
        }

        // 数字を表示(2文字で表示)
        if (cardNumber < 10)
        {
            cout << " ";
        }
        cout << "   " << cardNumber << "   ";
    }
};