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

        int currentPlayerIndex = 0;
        int cardNum = playingField.getCardNum() - 1;

        // ゲームを進行
        while (1)
        {
            // カードをめくる
            int flipCount = 0;
            int flipCardNumber[2] = {0, 0};

            cout << "\n\n\n\n\n\n\n";
            cout << "*                                               *" << endl;
            cout << "  " << player[currentPlayerIndex].getName() << " のターン" << endl;
            cout << "*                                               *\n"
                 << endl;
            playingField.printField();
            printCurrentScore();
            cout << "\n\n\n\n\n\n\n";

            while (flipCount < 2)
            {
                cout << "めくるカードの番号を入力してください(1~" << cardNum + 1 << "): ";
                cin >> flipCardNumber[flipCount];
                if (flipCardNumber[flipCount] < 1 || flipCardNumber[flipCount] > cardNum + 1)
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
                        if (playingField.flipCard(flipCardNumber[flipCount] - 1))
                        {
                            flipCount++;
                        }
                    }
                }
            }

            bool isPaired = playingField.checkPair(flipCardNumber[0] - 1, flipCardNumber[1] - 1);

            if (isPaired)
            {
                if (playingField.isAllPaired())
                {
                    cout << "****************** Good Pair ! ******************" << endl;
                    cout << "       おめでとうございます！  全てのペアが揃いました！       " << endl;
                    cout << "*************************************************\n"
                         << endl;
                    cout << "\n\n\n";
                    cout << "Enterを押して結果を確認しましょう!\n\n"
                         << endl;
                    player[currentPlayerIndex].addScore();
                    playingField.resetCard();
                    cin.ignore();
                    cin.get();
                    cout << "\n\n\n";
                    break;
                }
                else
                {
                    cout << "****************** Good Pair ! ******************" << endl;
                    cout << "       おめでとうございます！  ペアが揃いました！       " << endl;
                    cout << "*************************************************\n"
                         << endl;
                    cout << "\n\n\n";
                    cout << "もう一度挑戦できます!Enterを押してください。\n\n"
                         << endl;
                    player[currentPlayerIndex].addScore();
                    playingField.resetCard();
                    cin.ignore();
                    cin.get();
                    cout << "\n\n\n";
                }
            }
            else
            {
                cout << "残念！ ペアではありませんでした" << endl;
                playingField.resetCard();
                currentPlayerIndex = (currentPlayerIndex + 1) % 2;
                cout << "\n\n\n";
                cout << "次のプレイヤーのターンです。交代したらEnterを押してください。\n"
                     << endl;
                cin.ignore();
                cin.get();
                cout << "\n\n\n";
            }

            // 今の状態を表示
            printCurrentScore();
        }
        // 結果を表示
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "*************************************************" << endl;
        cout << "*                      結果                      *" << endl;
        cout << "*************************************************\n"
             << endl;

        printScore();
        cout << endl;
    }

private:
    // 現在のスコアを表示する関数
    void printCurrentScore()
    {
        cout << "\n\n\n";
        // 左にPlayer0のスコア、右にPlayer1のスコアを表示
        cout << "-------------------------------------------------" << endl;
        cout << "  " << player[0].getName() << " のスコア | " << player[0].getScore();
        cout << "        " << player[1].getScore() << " | " << player[1].getName() << " のスコア" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "\n\n\n";
    }
    // 最終的なスコアを表示する関数
    void printScore()
    {
        printCurrentScore();

        if (player[0].getScore() > player[1].getScore())
        {
            cout << "*****  " << player[0].getName() << " の勝利です！  *****" << endl;
        }
        else if (player[0].getScore() < player[1].getScore())
        {
            cout << "*****  " << player[1].getName() << " の勝利です！  *****" << endl;
        }
        else
        {
            cout << "引き分けです！" << endl;
        }
    }
};