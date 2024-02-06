#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();
int main()
{
    rules();
    string pName;
    int pBalance, bet;
    short pNum, dice;
    char choice;

    srand(time(0));

    cout << "\t\t=====ДОБРО ПОЖАЛОВАТЬ В КАЗИНО=====\n";
    cout << "\tВведите свое имя: "; cin >> pName;
    cout << "\tВведите свой баланс: $"; cin >> pBalance;
    do {
        system("cls");
        setlocale(0, "");
        rules();
        cout << "\n\n Ваш баланс: $" << pBalance << "\n";
        do {
            cout << pName << ", введите вашу ставку: $"; cin >> bet;
            if (bet > pBalance) {
                cout << "Ставка не может быть больше баланса.\n" << "Вы должны ввести вашу ставку повторно.\n";
            }
        } while (bet > pBalance);
        
        do {
            cout << "Введите число от 1 до 5: "; cin >> pNum;
            if (pNum <= 0 or pNum >= 6) cout << "Число дожно быть от 1 до 5.\n" << "Введите число еще раз.\n";
        } while(pNum <= 0 or pNum >= 6);
        dice = rand() % 5 + 1;
        if (dice == pNum) {
            cout << "Вы угадали число.\n";
            pBalance += bet * 2;
        }
        else {
            cout << "Вы не угадали.\n" << "Правильное число: " << dice <<endl;
            pBalance -= bet;
        }
        cout << "Ваш баланс:" << pBalance << endl;
        if (pBalance == 0) {
            cout << "\n";
            break;
        }
        cout << "Хотите ли продолжить игру(y/n)?";
        cout << "---> "; cin >> choice;
    } while (choice =='Y' or choice == 'y');
    cout << "\n\n\n\nСпасибо, что посетили наше казино.\n" << "Ваш выигрыш: $" << pBalance;
    return 0;
}

void rules() {
    setlocale(0, "");
    cout << "\t\t=====ПРАВИЛА КАЗИНО=====\n";
    cout << "\t1:Выберите номер от 1 до 10.\n";
    cout << "\t2:Победитель получает выйгрыш равный двум ставкам.\n";
    cout << "\t3:При проигрыше ставка сгорает.\n\n";
}