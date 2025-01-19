#include <iostream>
using namespace std;

int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    string arr[20][70];
    string movement[20][70];
    string map[7][7];
    string temp[6] = {" 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 "}; // 1 - пусто 2 - нет выхода на право 3 - выход прямо и назад 4 - файт 5 - лут 6 - лут
    int pos1 = 17, pos2 = 16;
    int pos1_1 = 0, pos2_2 = 0;
    string vibor;
    string move;
    bool flag, flag_1 = true;
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == 0 and j == 0) {
                map[i][j] = "|X|";
            }
            else if (i == 6 and j == 6) {
                map[i][j] = "|R|";
            }
            else {
                map[i][j] = temp[rand() % 6];
            }

        }
    }

    while (flag_1) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 70; j++) {
                    if (i == 0 or i == 19) {
                        arr[i][j] = "-";
                    }
                    else if (j == 0 or j == 69) {
                        arr[i][j] = "|";
                    }
                    else if (i == 17) {
                        arr[i][j] = "_";
                    }
                    else {
                        arr[i][j] = " ";
                    }
                if (map[pos1_1][pos2_2] == "|X|") {
                    if (j >= 5 and j <= 15 and i == 11) {
                        arr[i][j] = "_";
                    }
                    else if ((i < 18 and i > 11) and (j == 5 or j == 15)) {
                        arr[i][j] = "|";
                    }
                  }
                else if (map[pos1_1][pos2_2] == " 1 ") {
                    if (j >= 5 and j <= 15 and i == 11) {
                        arr[i][j] = "_";
                    }
                    else if ((i < 18 and i > 11) and (j == 5 or j == 15)) {
                        arr[i][j] = "|";
                    }
                    else if (j >= 40 and j <= 50 and i == 11) {
                        arr[i][j] = "_";
                    }
                    else if ((i < 18 and i > 11) and (j == 40 or j == 50)) {
                        arr[i][j] = "|";
                    }
                }
                else if (map[pos1_1][pos2_2] == " 2 ") {
                    if (j >= 5 and j <= 15 and i == 11) {
                        arr[i][j] = "_";
                    }
                    else if ((i < 18 and i > 11) and (j == 5 or j == 15)) {
                        arr[i][j] = "|";
                    }
                    else if (j >= 40 and j <= 50 and i == 11) {
                        arr[i][j] = "_";
                    }
                    else if ((i < 18 and i > 11) and (j == 40 or j == 50)) {
                        arr[i][j] = "|";
                    }
                }
                else if (map[pos1_1][pos2_2] == "|R|") {
                    cout << "Вы вышли с данжа!" << endl;
                }
            }
        }

        flag = true;
        vibor = " ";
        pos1 = 17, pos2 = 16;

        while (flag) {
            system("cls");

            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    if (i == pos1_1 and j == pos2_2) {
                        map[i][j] = "|*|";
                    }
                }
                cout << endl;
            }
            

            if (pos2 >= 69) {
                pos2_2 += 1;
                flag = false;
            }
            else if (pos2 <= 1) {
                pos2_2 -= 1;
                flag = false;
            }

            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 70; j++) {
                    if ((i == pos1 - 1 or i == pos1 or i == pos1 + 1) and j == pos2) {
                        movement[i][j] = "X";
                    }
                    else if (arr[i][j] != movement[i][j]) {
                        movement[i][j] = arr[i][j];
                    }
                    cout << movement[i][j];
                }
                cout << endl;
            }

            if (pos2 < 15 and pos2 > 5 and vibor == " ") {
                cout << "Хотите войти в дверь? \t[Yes]\t[No]\n Действие: ";
                std::cin >> vibor;

                if (vibor == "Yes" or vibor == "yes") {
                    pos1_1 += 1;
                    flag = false;
                }
                else if (vibor == "No") {
                    cout << "Вы продолжили свой путь" << endl;
                }
            }
            else if (pos2 < 50 and pos2 > 40 and vibor == " ") {
                cout << "Хотите войти в дверь? \t[Yes]\t[No]\n Действие: ";
                std::cin >> vibor;

                if (vibor == "Yes" or vibor == "yes") {
                    pos1_1 -= 1;
                    flag = false;
                }
                else if (vibor == "No") {
                    cout << "Вы продолжили свой путь" << endl;
                }
            }

            cout << "[W - вперёд]\t[S - назад]\t[E - открыть карту]\n Действие: ";
            std::cin >> move;
            if (move == "w" or move == "W") {
                pos2 += 5;
            }
            else if (move == "s" or move == "S") {
                pos2 -= 5;
            }
            else if (move == "e" or move == "E") {
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (map[i][j] == "|*|") {
                            cout << map[i][j];
                        }
                        else {
                            cout << "| |";
                        }
                    }
                    cout << endl;
                    for (int a = 0; a < 7; a++) {
                        cout << "---";
                    }
                    cout << endl;
                }
                cin >> vibor;
            }
        }
    }

}

