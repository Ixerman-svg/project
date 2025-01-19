#include <iostream>
using namespace std;

class Hero {
protected:
    string name;
    string klass;
    int damage;
    int armor;
    int hp = 100;
    int level = 0;
public:
    Hero(string name, string klass, int damage, int armor) {
        this->name = name;
        this->klass = klass;
        this->damage = damage;
        this->armor = armor;
    }

    void getInfo() {
        cout << " _______________" << endl;
        cout << "|    " << name << "    |" << endl;
        cout << "|---------------|" << endl;
        cout << "| hp : " << hp << "      |" << endl;
        cout << "| klas : " << klass << " |" << endl;
        cout << "| armor : " << armor << "    |" << endl;
        cout << "| damage : " << damage << "   |" << endl;
        cout << "|_______________|" << endl;
    }

    int getDamage() {
        return damage;
    }

    int getHP(int e) {
        hp -= e;
        return hp;
    }

    int getArmor() {
        return armor;
    }

    int CheckHP() {
        return hp;
    }
};

class Enemy {
protected:
    string enemyName;
    int enemyHp;
    int enemyDamage;
    int enemyArmor;
public:
    Enemy(string name, int hp, int damage, int armor) {
        this->enemyName = name;
        this->enemyHp = hp;
        this->enemyDamage = damage;
        this->enemyArmor = armor;
    }

    virtual void PrintInfo() = 0;


};

class Skeleton : public Enemy {
public:
    Skeleton(string name, int hp, int damage, int armor) : Enemy(name, hp, damage, armor) {};

    virtual void PrintInfo() {
        cout << "______________" << endl;
        cout << "|   " << enemyName << "   |" << endl;
        cout << "|------------|" << endl;
        cout << "| hp : " << enemyHp << "    |" << endl;
        cout << "| armor : " << enemyArmor << " |" << endl;
        cout << "| damage : " << enemyDamage << "|" << endl;
        cout << "|____________|" << endl;
    }

    int getHP(int x) {
        enemyHp -= x;
        return enemyHp;
    }

    int getEnemyDamage() {
        return enemyDamage;
    }

    int CheckHp() {
        return enemyHp;
    }

};

class Werewolf : public Enemy{
public:
    Werewolf(string name, int hp, int damage, int armor) : Enemy(name, hp, damage, armor) {};

    virtual void PrintInfo() {
        cout << "______________" << endl;
        cout << "|" << enemyName << "   |" << endl;
        cout << "|------------|" << endl;
        cout << "| hp : " << enemyHp << "   |" << endl;
        cout << "| armor : " << enemyArmor << " |" << endl;
        cout << "| damage : " << enemyDamage << "|" << endl;
        cout << "|____________|" << endl;
    }

    int getHP(int x) {
        enemyHp -= x;
        return enemyHp;
    }

    int getEnemyDamage() {
        return enemyDamage;
    }

    int CheckHp() {
        return enemyHp;
    }
};

int FightWithEnemy(string name, string klass, int damage, int armor) {
    Hero hero(name, klass, damage, armor);
    string enemy_q;
    string vibor;
    string tipy[2] = { "skeleton", "werewolf" };

    if (tipy[rand() % 2] == " skeleton") {
        enemy_q = "skeleton";
        Skeleton s(enemy_q, 75, 12, 10);
        cout << "на вас напал скелет";
        while (s.CheckHp()) {
            system("cls");
            cout << "---------------------------------------------------" << endl;
            cout << "|      [E - Атаковать]                            |" << endl;
            cout << "|      [F - заблокировать удар]                   |" << endl;
            cout << "|      [M - посмотреть информацию]                | " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "Действие : "; cin >> vibor;
            if (vibor == "E" or vibor == "e") {
                s.getHP(hero.getDamage());
                hero.getHP(s.getEnemyDamage());
            }
            else if (vibor == "F" or vibor == "f") {
                if (rand() % 7 + 1 > 5) {
                    cout << "\nВы заблокировали удар!\n";
                }
                else {
                    cout << "\nВы не смоглу заблокировать удар!\n";
                    hero.getHP(s.getEnemyDamage());
                }
            }
            else if (vibor == "M" or vibor == "m") {
                hero.getInfo();
                s.PrintInfo();
            }
            if (hero.CheckHP() == 0) {
                cout << "\n Вы погибли!\n";
            }
            else {
                continue;
            }
        }
    }
    else if (tipy[rand() % 2] == " werewolf") {
        enemy_q = "werewolf";
        Werewolf w(enemy_q, 150, 25, 20);

        cout << "на вас напал оборотень";
        while (w.CheckHp()) {
            system("cls");
            cout << "---------------------------------------------------" << endl;
            cout << "|      [E - Атаковать]                            |" << endl;
            cout << "|      [F - заблокировать удар]                   |" << endl;
            cout << "|      [M - посмотреть информацию]                | " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "Действие : "; cin >> vibor;
            if (vibor == "E" or vibor == "e") {
                w.getHP(hero.getDamage());
                hero.getHP(w.getEnemyDamage());
            }
            else if (vibor == "F" or vibor == "f") {
                if (rand() % 7 + 1 > 5) {
                    cout << "\nВы заблокировали удар!\n";
                }
                else {
                    cout << "\nВы не смоглу заблокировать удар!\n";
                    hero.getHP(w.getEnemyDamage());
                }
            }
            else if (vibor == "M" or vibor == "m") {
                hero.getInfo();
                w.PrintInfo();
            }
            if (hero.CheckHP() == 0) {
                cout << "\n Вы погибли!\n";
            }
            else {
                continue;
            }
        }
    }
    return hero.CheckHP();
}

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
    string name, klass;
    int damage, armor;

    bool flag = true;
    cout << "Введите имя вашего героя : ";
    cin >> name;
    while (flag) {
        try {
            cout << "Возможные классы : \n [knight]\t [archer]\t [wizard]\n Класс : ";
            cin >> klass;
            if ((klass != "knight") and (klass != "archer") and (klass != "wizard")) {
                throw klass;
            }
            flag = false;
        }
        catch (string error) {
            cout << "Нет такого класса!" << endl;
        }
    }
    if (klass == "knight") {
        damage = 55;
        armor = 40;
    }
    else if (klass == "archer") {
        damage = 65;
        armor = 25;
    }
    else if (klass == "wizard") {
        damage = 70;
        armor = 5;
    }

    Hero hero(name, klass, damage, armor);

    damage = hero.getDamage();
    armor = hero.getArmor();
    
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
                else if (map[pos1_1][pos2_2] == " 7 ") {
                    cout << FightWithEnemy(name, klass, damage, armor);
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

