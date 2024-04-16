#include <iostream>
#include <cctype>

using namespace std;

// Playerクラス
class Player
{
private:
    // プレイヤーの名前
    string name;
    // プレイヤーの番号
    int playerNumber;
    // 点数
    int score;

public:
    // コンストラクタ
    Player() : score(0) {}

    // プレイヤーの名前を設定する関数
    void setPlayerNumber(int num)
    {
        playerNumber = num;
    }

    // 名前を設定する関数
    void setName()
    {
        cout << "Player" << playerNumber << " の名前を入力してください: ";
        cin >> name;
    }

    // 名前を取得する関数
    string getName()
    {
        return name;
    }

    // 点数を取得する関数
    int getScore()
    {
        return score;
    }

    // 点数を加算する関数
    void addScore()
    {
        score += 10;
    }
};
