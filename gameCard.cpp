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

public:
    // コンストラクタ
    GameCard(int cardNumber, int num, Suit st) : TrampCard(num, st), cardNumber(cardNumber) {}

    // カードを表示する関数
    void printCard(bool isFaceUp = true)
    {
        cout << "+------------+" << endl;
        cout << "|            |" << endl;
        cout << "|  ";
        // 表面を表示する場合
        if (isFaceUp)
        {
            printTramp();
        }
        // 裏面を表示する場合
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