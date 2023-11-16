#include <iostream> //Для cout cin
#include <conio.h> //Для _getch()
#include <windows.h> //Для цвета
#include <ctime> //Для времени
#include <string> //Для строчек

using namespace std;

void nastroykicase();
void exitcase();
void rulescase();
void gamecase();
void check();
void answnum();
void ansfor();
void ansif();
void ans12();
void ans34();
void ans1();
void ans2();
void ans3();
void ans4();

char num0;  // для switch
int difficulty = 1; //сложность
int num1, num2, num3; // в 30 не повторяющихся чисел
double num4;//для времени
int mas[30]; // массив из 30 вопросов
int clue = 1; // подсказка
int life = 3; //жизни
int gametime = 600;//время
int answer; //ответ пользователя
int answer1;//ответ пользователя приравненный к массиву в фор
int Beginning_Time = 0;//Начало отсчета
int Ending_Time = 0; //Переменная для значения времени окончания работы одного бланка
int Result_Time = 0;//Для результата времени
int mas1[4];//для выведения вариантов ответа 
int mas2[4];//для определения вариантов ответа
string question, numq, answ1, answ2, answ3, answ4;

HANDLE hConsole;

enum Color { Green = 2, Red = 4, White = 15, Black = 0 };
int main()
{
    setlocale(0, "");
    system("cls");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Игра викторина :)\n\n";
    cout << "1. Правила\n";
    cout << "2. Настройки\n";
    cout << "3. Начать игру\n";
    cout << "4. Выход\n\n";
    do {
        cout << "Введите нужный вам пункт:";
        cin >> num0;
        if (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4') {
            cout << endl << "[!] Вы ввели некорректные данные!" << endl;
            _getch();
            main();
        }
    } while (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4');
    system("cls");
    switch (num0) {
    case '1':
        rulescase();
        break;
    case '2':
        nastroykicase();
        break;
    case '3':
        gamecase();
        break;
    case '4':
        exitcase();
        break;
    }
    return 0;
}
void nastroykicase()
{
    system("cls");
    cout << "[+] Настройки:" << endl << endl;
    cout << "[1] Сложность" << endl;
    cout << "[2] Жизни" << endl;
    cout << "[3] Подсказка" << endl;
    cout << "[4] Время на викторину" << endl << endl;
    cout << "[5] Вернуться в главное меню" << endl << endl;
    do {
        cout << "[+] Выберете нужный вам пункт:";
        cin >> num0;
        if (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4' && num0 != '5') {
            cout << endl << "[!] Вы ввели некорректные данные!" << endl;
            _getch();
            nastroykicase();
        }
    } while (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4' && num0 != '5');
    system("cls");
    switch (num0) {
    case '1':
        cout << "[+] Настройки:\n\n";
        cout << "[+] Выберете сложность:\n";
        cout << "[1] Легкая (10 вопросов)\n";
        cout << "[2] Средняя (15 вопросов)\n";
        cout << "[3] Сложная (20 вопросов)\n\n";
        do {
            cout << "[+] Выберете нужный вам пункт:";
            cin >> num0;
            if (num0 != '1' && num0 != '2' && num0 != '3') {
                cout << endl << "[!] Вы ввели некорректные данные!" << endl;
            }
        } while (num0 != '1' && num0 != '2' && num0 != '3');
        if (num0 == '1')
        {
            difficulty = 10;
        }
        else if (num0 == '2') {
            difficulty = 15;
        }
        else if (num0 == '3') {
            difficulty = 20;
        }
        nastroykicase();
        break;
    case '2':
        cout << "[+] Настройки:\n\n";
        do {
            cout << "[+] Введите количество жизней (макс 3):";
            cin >> num0;
            if (num0 != '0' && num0 != '1' && num0 != '2' && num0 != '3') {
                cout << endl << "[!] Вы ввели некорректные данные!" << endl;
            }
        } while (num0 != '0' && num0 != '1' && num0 != '2' && num0 != '3');
        if (num0 == '0') {
            life = 0;
        }
        else if (num0 == '1')
        {
            life = 1;
        }
        else if (num0 == '2') {
            life = 2;
        }
        else if (num0 == '3') {
            life = 3;
        }
        nastroykicase();
        break;
    case '3':
        cout << "[+] Настройки:\n\n";
        do {
            cout << "[+] Подсказка 50/50 (макс 1):";
            cin >> num0;
            if (num0 != '0' && num0 != '1') {
                cout << endl << "[!] Вы ввели некорректные данные!" << endl;
            }
        } while (num0 != '0' && num0 != '1');
        if (num0 == '0') {
            clue = 0;
        }
        else if (num0 == '1')
        {
            clue = 1;
        }
        nastroykicase();
        break;
    case '4':
        cout << "[+] Настройки:\n\n";
        cout << "[+] Время на викторину от 2 до 10 минут (Пример записи: 3.30-3 минуты 30 секунд)";
        do {
            cout << endl << "[+] Введите ваше время на викторину:";
            cin >> num4;
            if (num4 < 2 || num4>10) {
                cout << endl << "[!] Вы ввели некорректные данные!";
            }
        } while (num4 < 2 || num4>10);
        num1 = num4; //минуты
        num4 = (num4 - num1) * 100; //секунды
        gametime = (num1 * 60) + num4;
        nastroykicase();
        break;
    case '5':
        main();
        break;
    }
}
void rulescase()
{
    system("cls");
    cout << "[1] ПИСАТЬ ТОЛЬКО ТЕ СИМВОЛЫ, КОТОРЫЕ ПРОСИТ ПРОГРАММА!!!" << endl;
    cout << "[2] При запуске игры выводятся разные вопросы из возможных 30(какой именно подписывается на вопросе)" << endl;
    cout << "[3] Вам нужно выбрать правильный ответ из 4 вариантов ответа данных вам" << endl;
    cout << "[4] Вы можете использовать только " << clue << " подсказку для отсеивания двух вариантов ответа" << endl;
    cout << "[5] У вас есть только " << life << " жизни" << endl;
    cout << "[6] Времени в общем " << (gametime - (Ending_Time / 1000)) / 60 << ":" << (gametime - (Ending_Time / 1000)) - (((gametime - (Ending_Time / 1000)) / 60) * 60) << endl;
    cout << "[+] Удачи в прохождении викторины!" << endl << endl;
    system("pause");
    main();
}
void exitcase()
{
    system("cls");
    cout << "\n\n[+] Вы вышли из игры";
    _getch();
    exit(0);
}
void check()
{
    cout << endl;
    cout << "[+] Жизней осталось: " << life << endl;
    Ending_Time = clock();
    Result_Time = Ending_Time - Beginning_Time;
    if ((gametime - (Ending_Time / 1000) / 60) > 0 && (gametime - (Ending_Time / 1000)) - (((gametime - (Ending_Time / 1000)) / 60) * 60) > 0) {
        cout << "[+] Времени осталось: " << (gametime - (Ending_Time / 1000)) / 60 << ":" << (gametime - (Ending_Time / 1000)) - (((gametime - (Ending_Time / 1000)) / 60) * 60) << endl;
    }
    else {
        cout << "[+] Времени осталось: 0:0" << endl;
    }
    system("pause");
    if (Result_Time > gametime * 1000) {
        system("cls");
        cout << "[!] Время вышло, конец игры!" << endl;
        _getch();
        exit(0);
    }
    if (life == 0) {
        system("cls");
        cout << "[+] У вас закончились жизни! Игра окончена!" << endl;
        _getch();
        exit(0);;
    }
    system("cls");
}
void gamecase()          // Игра меню
{
    srand(time(0));
    system("cls");
    for (int i = 0; i < 30; i++)     // выведение 30 не повторяюзихся чисел
    {
        num1 = rand() % 30;
        while (mas[num1])
            num1 = rand() % 30;
        mas[num1] = i + 1;
    }
    for (int i = 0; i < 4; i++)     // выведение повторящихся вариантов ответа
    {
        num2 = rand() % 4;
        while (mas1[num2])
            num2 = rand() % 4;
        mas1[num2] = i + 1;
    }
    int Beginning_Time = clock();
    for (int i = 0; i < difficulty; i++)
    {                                          //Главный фор
        system("cls");
        num3 = i + 1;
        if (mas[i] == 1) {
            question = "\tКакая команда должна быть после окончания case?";
            answ1 = "switch";
            answ2 = "default";
            answ3 = "break";
            answ4 = "end";
            ans3();
        }
        else if (mas[i] == 2) {
            question = "\tКакую команду мы используем для вывода на консоль?";
            answ1 = "cin";
            answ2 = "cout";
            answ3 = "setw";
            answ4 = "string";
            ans2();
        }
        else if (mas[i] == 3) {
            question = "\tКакие знаки используются с командой cin?";
            answ1 = ">>";
            answ2 = "||";
            answ3 = "&&";
            answ4 = "<<";
            ans1();
        }
        else if (mas[i] == 4) {
            question = "\tКакие знаки используются с командой cout?";
            answ1 = ">>";
            answ2 = "||";
            answ3 = "&&";
            answ4 = "<<";
            ans4();
        }
        else if (mas[i] == 5) {
            question = "\tКакие знаки используются в цикле if для обозначения \"ИЛИ\"?";
            answ1 = ">>";
            answ2 = "||";
            answ3 = "&&";
            answ4 = "<<";
            ans2();
        }
        else if (mas[i] == 6) {
            question = "\tКакие знаки используются в цикле if для обозначения \"И\"?";
            answ1 = ">>";
            answ2 = "||";
            answ3 = "&&";
            answ4 = "<<";
            ans3();
        }
        else if (mas[i] == 7) {
            question = "\tКакие знаки используются для вывода текста на консоль?";
            answ1 = "//";
            answ2 = "\"\"";
            answ3 = "()";
            answ4 = "{}";
            ans2();
        }
        else if (mas[i] == 8) {
            question = "\tКакие знаки используются для комментария в коде?";
            answ1 = "//";
            answ2 = "[]";
            answ3 = "()";
            answ4 = "{}";
            ans1();
        }
        else if (mas[i] == 9) {
            question = "\tКакие знаки используются для условия в цикле for?";
            answ1 = "//";
            answ2 = "[]";
            answ3 = "()";
            answ4 = "{}";
            ans3();
        }
        else if (mas[i] == 10) {
            question = "\tКакие знаки используются после обозначения условий в цикле for?";
            answ1 = "//";
            answ2 = "[]";
            answ3 = "()";
            answ4 = "{}";
            ans4();
        }
        else if (mas[i] == 11) {
            question = "\tКакие знаки используются чтобы обозначить массив?";
            answ1 = "//";
            answ2 = "[]";
            answ3 = "()";
            answ4 = "{}";
            ans2();
        }
        else if (mas[i] == 12) {
            question = "\tКакую команду мы используем ввода с консоли?";
            answ1 = "cin";
            answ2 = "cout";
            answ3 = "setw";
            answ4 = "string";
            ans1();
        }
        else if (mas[i] == 13) {
            question = "\tКакую команду мы используем для установки ширины поля?";
            answ1 = "cin";
            answ2 = "cout";
            answ3 = "setw";
            answ4 = "string";
            ans3();
        }
        else if (mas[i] == 14) {
            question = "\tКакую команду мы используем для вписывания в переменную текст?";
            answ1 = "cin";
            answ2 = "cout";
            answ3 = "setw";
            answ4 = "string";
            ans4();
        }
        else if (mas[i] == 15) {
            question = "\tЧто делает команда endl?";
            answ1 = "Заканчивает программу";
            answ2 = "Делает пробел";
            answ3 = "Делает отступ";
            answ4 = "Переходит на следующую строку";
            ans4();
        }
        else if (mas[i] == 16) {
            question = "\tЧто делает команда end(0)?";
            answ1 = "Заканчивает программу";
            answ2 = "Делает пробел";
            answ3 = "Делает отступ ";
            answ4 = "Переходит на следующую строку";
            ans1();
        }
        else if (mas[i] == 17) {
            question = "\tЧто делает команда \\t?";
            answ1 = "Заканчивает программу";
            answ2 = "Делает пробел";
            answ3 = "Делает отступ";
            answ4 = "Переходит на следующую строку";
            ans3();
        }
        else if (mas[i] == 18) {
            question = "\t\"cin<<num1;\"-в чем ошибка?";
            answ1 = "Должен быть один знак <";
            answ2 = "Нет такой команды cin";
            answ3 = "<< повернуты не в ту сторону";
            answ4 = "точка с запятой не нужна";
            ans3();
        }
        else if (mas[i] == 19) {
            num1 = i;
            cout << "[+] " << num3 << " Вопрос:" << endl;
            question = "\tДля чего используется команда _getch?";
            answ1 = "Ставит код на паузу";
            answ2 = "Ставит код на паузу выводя текст при этом";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Используется для времени в коде";
            ans1();
        }
        else if (mas[i] == 20) {
            question = "\tДля чего используется команда system(\"pause\")?";
            answ1 = "Ставит код на паузу";
            answ2 = "Ставит код на паузу выводя текст при этом";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Используется для времени в коде";
            ans2();
        }
        else if (mas[i] == 21) {
            question = "\tДля чего используется команда system(\"cls\")?";
            answ1 = "Ставит код на паузу";
            answ2 = "Очищает консоль";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Используется для времени в коде";
            ans2();
        }
        else if (mas[i] == 22) {
            question = "\tДля чего используется команда clock()?";
            answ1 = "Ставит код на паузу";
            answ2 = "Очищает консоль";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Используется для времени в коде";
            ans4();
        }
        else if (mas[i] == 23) {
            question = "\tДля чего используется команда rand?";
            answ1 = "Ставит код на паузу";
            answ2 = "Очищает консоль";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Локализовывает текст";
            ans3();
        }
        else if (mas[i] == 24) {
            question = "\tДля чего используется команда setlocale?";
            answ1 = "Осуществляет выбор пользователя";
            answ2 = "Прерывает выполнение кода";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Локализовывает текст";
            ans4();
        }
        else if (mas[i] == 25) {
            question = "\tДля чего используется команда switch?";
            answ1 = "Осуществляет выбор пользователя";
            answ2 = "Прерывает выполнение кода";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Локализовывает текст";
            ans1();
        }
        else if (mas[i] == 26) {
            question = "\tДля чего используется команда break?";
            answ1 = "Для возращения данных";
            answ2 = "Прерывает выполнение кода";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Для вывода значений";
            ans2();
        }
        else if (mas[i] == 27) {
            question = "\tДля чего используется команда return?";
            answ1 = "Для возращения данных";
            answ2 = "Прерывает выполнение кода";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Для вывода значений";
            ans1();
        }
        else if (mas[i] == 28) {
            question = "\tДля чего используется using namespace std?";
            answ1 = "Для возращения данных";
            answ2 = "Прерывает выполнение кода";
            answ3 = "Делает рандомайзер чисел";
            answ4 = "Для вывода значений";
            ans4();
        }
        else if (mas[i] == 29) {
            question = "\tКакое полное название колледжа?";
            answ1 = "Морской Авиомоторный Дорожный Колледж";
            answ2 = "Московский Автомобильный Дорожный Колледж";
            answ3 = "Московский Автомобильно Дорожный Колледж";
            answ4 = "Московский Авиалетный Дорогой Колледж";
            ans3();
        }
        else if (mas[i] == 30) {
            question = "\tПолное ФИО преподавателя по Системному программированию в 2ИП-1?";
            answ1 = "Семенова Екатерина Владимировна";
            answ2 = "Семеновна Елена Викторовна";
            answ3 = "Семенова Анна Александровна";
            answ4 = "Семеновна Екатерина Владимировна";
            ans1();
        }

    }
    system("cls");
    cout << "[!] Поздравляем! Вы выиграли!" << endl;
    cout << "      + + + + + + + + + + +\n";
    cout << "+ + + +                   + + + +\n";
    cout << "+     +                   +     +\n";
    cout << "+     +                   +     +\n";
    cout << "+ +   +                   +   + +\n";
    cout << "  + + +                   + + +\n";
    cout << "      +                   +\n";
    cout << "      + +               + + \n";
    cout << "        + +           + +\n";
    cout << "          + +       + +\n";
    cout << "              +   +\n";
    cout << "              +   +\n";
    cout << "              +   +\n";
    cout << "            + +   + +\n";
    cout << "          +           +\n";
    cout << "          + + + + + + +\n";
    _getch();
}
void answnum() {
    do {
        cout << "Введите ваш ответ:";
        cin >> num0;
        if (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4' && num0 != '5') {
            cout << endl << "[!] Вы ввели некорректные данные!" << endl;
        }
    } while (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4' && num0 != '5');
    if (num0 == '1') {
        answer = 1;
    }
    else if (num0 == '2') {
        answer = 2;
    }
    else if (num0 == '3') {
        answer = 3;
    }
    else if (num0 == '4') {
        answer = 4;
    }
    else if (num0 == '5') {
        answer = 5;
    }
}
void ansfor()
{
    cout << "[+] " << num3 << " Вопрос:" << endl;
    cout << question << endl << endl;
    for (int i = 0; i < 4; i++) {         // выведение вариантов в консоль
        if (mas1[i] == 1) {
            mas2[i] = 1;
            cout << "[" << i + 1 << "] " << answ1 << endl;
        }
        else if (mas1[i] == 2) {
            mas2[i] = 2;
            cout << "[" << i + 1 << "] " << answ2 << endl;
        }
        else if (mas1[i] == 3) {
            mas2[i] = 3;
            cout << "[" << i + 1 << "] " << answ3 << endl;
        }
        else if (mas1[i] == 4) {
            mas2[i] = 4;
            cout << "[" << i + 1 << "] " << answ4 << endl;
        }
    }
    cout << endl << "[5] Подсказка 50/50" << endl << endl;
    answnum();
}
void ansif()
{
    if (answer == 1) {                    //подстраивание ответов
        answer1 = mas2[0];
    }
    else if (answer == 2) {
        answer1 = mas2[1];
    }
    else if (answer == 3) {
        answer1 = mas2[2];
    }
    else if (answer == 4) {
        answer1 = mas2[3];
    }
}
void ans12() {

    for (int i = 0; i < 4; i++) {                           // выведение вариантов в консоль 50/50 (ответ 12)
        if (mas1[i] == 1) {
            mas2[i] = 1;
            SetConsoleTextAttribute(hConsole, White);
            cout << "[" << i + 1 << "] " << answ1 << endl;
        }
        else if (mas1[i] == 2) {
            mas2[i] = 2;
            SetConsoleTextAttribute(hConsole, White);
            cout << "[" << i + 1 << "] " << answ2 << endl;
        }
        else if (mas1[i] == 3) {
            mas2[i] = 3;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ3 << endl;
        }
        else if (mas1[i] == 4) {
            mas2[i] = 4;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ4 << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, White);
    cout << endl << "[5] Подсказка 50/50" << endl << endl;
    answnum();
    if (answer == 5) {
        do {
            cout << endl << "[!] Вы не можете использовать подсказку дважды!" << endl;
            answnum();
        } while (answer == 5);
    }
}
void ans34() {

    for (int i = 0; i < 4; i++) {                           // выведение вариантов в консоль 50/50 (ответ 34)
        if (mas1[i] == 1) {
            mas2[i] = 1;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ1 << endl;
        }
        else if (mas1[i] == 2) {
            mas2[i] = 2;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ2 << endl;
        }
        else if (mas1[i] == 3) {
            mas2[i] = 3;
            SetConsoleTextAttribute(hConsole, White);
            cout << "[" << i + 1 << "] " << answ3 << endl;
        }
        else if (mas1[i] == 4) {
            mas2[i] = 4;
            SetConsoleTextAttribute(hConsole, White);
            cout << "[" << i + 1 << "] " << answ4 << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, White);
    cout << endl << "[5] Подсказка 50/50" << endl << endl;
    answnum();
    if (answer == 5) {
        do {
            cout << endl << "[!] Вы не можете использовать подсказку дважды!" << endl;
            answnum();
        } while (answer == 5);
    }
}
void ans1() {
    ansfor();
    if (answer == 5 && clue > 0) {
        clue--;
        system("cls");
        cout << "[+] " << num3 << " Вопрос:" << endl;
        cout << question << endl << endl;
        ans12();
    }
    else if (answer == 5 && clue == 0) {
        do {
            cout << endl << endl << "[!] У вас кончились подсказки! Введите свой ответ:";
            answnum();
        } while (answer == 5);
    }
    system("cls");
    cout << "[+] " << num3 << " Вопрос:" << endl;
    cout << question << endl << endl;
    ansif();
    for (int i = 0; i < 4; i++) {         // выведение вариантов в консоль (ответ 1)
        if (mas1[i] == 1) {
            mas2[i] = 1;
            SetConsoleTextAttribute(hConsole, Green);
            cout << "[" << i + 1 << "] " << answ1 << endl;
        }
        else if (mas1[i] == 2) {
            mas2[i] = 2;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ2 << endl;
        }
        else if (mas1[i] == 3) {
            mas2[i] = 3;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ3 << endl;
        }
        else if (mas1[i] == 4) {
            mas2[i] = 4;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ4 << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, White);
    cout << endl << "[5] Подсказка 50/50" << endl << endl;
    cout << "Введите ваш ответ:" << answer << endl << endl;
    if (answer1 == 1) {
        cout << "[+] Поздравляем, вы выбрали правильный ответ" << endl << endl;
    }
    else {
        cout << "[+] Вы выбрали неправильный ответ" << endl;
        life--;
    }
    check();
}
void ans2()
{
    ansfor();
    if (answer == 5 && clue > 0) {
        clue--;
        system("cls");
        cout << "[+] " << num3 << " Вопрос:" << endl;
        cout << question << endl << endl;
        ans12();
    }
    else if (answer == 5 && clue == 0) {
        do {
            cout << endl << endl << "[!] У вас кончились подсказки! Введите свой ответ:";
            answnum();
        } while (answer == 5);
    }
    system("cls");
    cout << "[+] " << num3 << " Вопрос:" << endl;
    cout << question << endl << endl;
    ansif();
    for (int i = 0; i < 4; i++) {         // выведение вариантов в консоль (ответ 2)
        if (mas1[i] == 1) {
            mas2[i] = 1;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ1 << endl;
        }
        else if (mas1[i] == 2) {
            mas2[i] = 2;
            SetConsoleTextAttribute(hConsole, Green);
            cout << "[" << i + 1 << "] " << answ2 << endl;
        }
        else if (mas1[i] == 3) {
            mas2[i] = 3;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ3 << endl;
        }
        else if (mas1[i] == 4) {
            mas2[i] = 4;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ4 << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, White);
    cout << endl << "[5] Подсказка 50/50" << endl << endl;
    cout << "Введите ваш ответ:" << answer << endl << endl;
    if (answer1 == 2) {
        cout << "[+] Поздравляем, вы выбрали правильный ответ" << endl << endl;
    }
    else {
        cout << "[+] Вы выбрали неправильный ответ" << endl;
        life--;
    }
    check();
}
void ans3()
{
    ansfor();
    if (answer == 5 && clue > 0) {
        clue--;
        system("cls");
        cout << "[+] " << num3 << " Вопрос:" << endl;
        cout << question << endl << endl;
        ans34();
    }
    else if (answer == 5 && clue == 0) {
        do {
            cout << endl << endl << "[!] У вас кончились подсказки! Введите свой ответ:";
            answnum();
        } while (answer == 5);
    }
    system("cls");
    cout << "[+] " << num3 << " Вопрос:" << endl;
    cout << question << endl << endl;
    ansif();
    for (int i = 0; i < 4; i++) {         // выведение вариантов в консоль (ответ 3)
        if (mas1[i] == 1) {
            mas2[i] = 1;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ1 << endl;
        }
        else if (mas1[i] == 2) {
            mas2[i] = 2;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ2 << endl;
        }
        else if (mas1[i] == 3) {
            mas2[i] = 3;
            SetConsoleTextAttribute(hConsole, Green);
            cout << "[" << i + 1 << "] " << answ3 << endl;
        }
        else if (mas1[i] == 4) {
            mas2[i] = 4;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ4 << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, White);
    cout << endl << "[5] Подсказка 50/50" << endl << endl;
    cout << "Введите ваш ответ:" << answer << endl << endl;
    if (answer1 == 3) {
        cout << "[+] Поздравляем, вы выбрали правильный ответ" << endl << endl;
    }
    else {
        cout << "[+] Вы выбрали неправильный ответ" << endl;
        life--;
    }
    check();
}
void ans4() {
    ansfor();
    if (answer == 5 && clue > 0) {
        clue--;
        system("cls");
        cout << "[+] " << num3 << " Вопрос:" << endl;
        cout << question << endl << endl;
        ans34();
    }
    else if (answer == 5 && clue == 0) {
        do {
            cout << endl << endl << "[!] У вас кончились подсказки! Введите свой ответ:";
            answnum();
        } while (answer == 5);
    }
    system("cls");
    cout << "[+] " << num3 << " Вопрос:" << endl;
    cout << question << endl << endl;
    ansif();
    for (int i = 0; i < 4; i++) {         // выведение вариантов в консоль (ответ 4)
        if (mas1[i] == 1) {
            mas2[i] = 1;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ1 << endl;
        }
        else if (mas1[i] == 2) {
            mas2[i] = 2;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ2 << endl;
        }
        else if (mas1[i] == 3) {
            mas2[i] = 3;
            SetConsoleTextAttribute(hConsole, Red);
            cout << "[" << i + 1 << "] " << answ3 << endl;
        }
        else if (mas1[i] == 4) {
            mas2[i] = 4;
            SetConsoleTextAttribute(hConsole, Green);
            cout << "[" << i + 1 << "] " << answ4 << endl;

        }
    }
    SetConsoleTextAttribute(hConsole, White);
    cout << endl << "[5] Подсказка 50/50" << endl << endl;
    cout << "Введите ваш ответ:" << answer << endl << endl;
    if (answer1 == 4) {
        cout << "[+] Поздравляем, вы выбрали правильный ответ" << endl << endl;
    }
    else {
        cout << "[+] Вы выбрали неправильный ответ" << endl;
        life--;
    }
    check();
}
