#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    const int n = 5; 

    int dicesBot[n];
    int dicesPlayer[n];

    cout << "Кидает бот: " << endl;
    for (int i = 0; i < n; i++) {
        dicesBot[i] = 1 + rand() % 6;
        cout << dicesBot[i] << " ";
    }
    cout << endl;

    cout << "Нажмите что-нибудь, чтобы бросить кости";
    cin.get();

    cout << "Бросаем кости..." << endl;
    for (int i = 0; i < n; i++) {
        dicesPlayer[i] = 1 + rand() % 6;
        cout << dicesPlayer[i] << " ";
    }
    cout << endl;

    
    sort(dicesBot, dicesBot + n);
    sort(dicesPlayer, dicesPlayer + n);

    
    bool botAllSame = (dicesBot[0] == dicesBot[n - 1]);
    bool playerAllSame = (dicesPlayer[0] == dicesPlayer[n - 1]);

    if (botAllSame && playerAllSame) {
        cout << "Ничья! Оба игрока имеют все одинаковые значения на костях." << endl;
    }
    else if (botAllSame) {
        cout << "Бот победил! У него все значения на костях одинаковы." << endl;
    }
    else if (playerAllSame) {
        cout << "Игрок победил! У него все значения на костях одинаковы." << endl;
    }
    else {
        int botSum = 0;
        int playerSum = 0;

        for (int i = 0; i < n; i++) {
            botSum += dicesBot[i];
            playerSum += dicesPlayer[i];
        }

        if (botSum > playerSum) {
            cout << "Бот победил! Сумма значений костей бота больше." << endl;
        }
        else if (botSum < playerSum) {
            cout << "Игрок победил! Сумма значений костей игрока больше." << endl;
        }
        else {
            cout << "Ничья! Суммы значений на костях у бота и игрока равны." << endl;
        }
    }

    return 0;
}