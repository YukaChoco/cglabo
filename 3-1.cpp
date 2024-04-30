#include <iostream>
#include <cmath>

// 定数の指定
const int MAX = 50;           // 最大反復回数
const double X0 = 1.;         // 初期値
const double EPS_FX = 1.0e-6; // 終了条件の誤差

// 関数f(x),df(x)の定義
inline double f(double x) { return (x - cos(x)); }
inline double df(double x) { return (1 + sin(x)); }

int main()
{
    // 変数xを初期値x_0で初期化
    double x = X0;
    // 更新量delta_x,関数値の誤差fx_errの定義
    double delta_x, fx_err;

    // 表示精度の設定
    std::cout.precision(8);
    // precision(int n)
    // 出力ストリーム std::cout の精度を設定するコードです。
    // std::cout を使用して浮動小数点数を出力する際に、小数点以下の桁数を指定

    // 終了条件に用いる誤差の表示
    std::cout << "\n終了条件に用いる誤差: " << EPS_FX << "\n"
              << std::endl;

    // 初期値x0の表示
    std::cout << "x0 = " << x << std::endl;

    // 反復計算
    for (int n = 1; n <= MAX; n++)
    {
        // 更新量の計算
        delta_x = -f(x) / df(x);
        // xの更新
        x += delta_x;

        // 現在のxの表示
        std::cout << "x" << n << " = " << x << std::endl;

        // 終了条件の判定
        fx_err = fabs(f(x));
        if (fx_err < EPS_FX) // 終了条件を満たした場合
        {
            break; // 反復計算を終了
        }
    }

    // 終了時の結果の表示
    std::cout << "\n結果: x = " << x << "\n"
              << std::endl;

    return 0;
}
