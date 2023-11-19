#include <iostream> //Для cout cin
#include <conio.h> //Для _getch()
#include <windows.h> //Для цвета
#include <ctime> //Для времени
#include <string> //Для строчек

using namespace std;

void nastroykicase();
void rulescase();
void gamecase();
void check();
void answnum();

char num0;  // для switch
int difficulty = 20; //сложность
int num1, num2, num3; // в 30 не повторяющихся чисел
double num4;//для времени
int num5;
int mas[30]; // массив из 30 вопросов
int clue = 1; // подсказка
int life = 3; //жизни
int gametime = 600;//время
int answer; //ответ пользователя
bool answer1[4]{false,false,false,false};//ответ пользователя приравненный к массиву в фор
bool answers=true;
int Beginning_Time = 0;//Начало отсчета
int Ending_Time = 0; //Переменная для значения времени окончания работы одного бланка
int Result_Time = 0;//Для результата времени
int mas1[4];//для выведения вариантов ответа 
string mas2[4];
HANDLE hConsole;
string Question[30]{
"\t Какая команда должна быть после окончания case?",
"\t Какую команду мы используем для вывода на консоль?",
"\t Какие знаки используются с командой cin?" ,
"\t Какие знаки используются с командой cout?" ,
"\t Какие знаки используются в цикле if для обозначения \"ИЛИ\"?",
"\t Какие знаки используются в цикле if для обозначения \"И\"?" ,
"\t Какие знаки используются для вывода текста на консоль?" ,
"\t Какие знаки используются для комментария в коде?" ,
"\t Какие знаки используются для условия в цикле for?",
"\t Какие знаки используются после обозначения условий в цикле for?",
"\t Какие знаки используются чтобы обозначить массив?",
"\t Какую команду мы используем ввода с консоли?",
"\t Какую команду мы используем для установки ширины поля?",
"\t Какую команду мы используем для вписывания в переменную текст?",
"\t Что делает команда endl?",
"\t Что делает команда end(0)?",
"\t Что делает команда \\t?",
"\t \"cin<<num1;\"-в чем ошибка?" ,
"\t Для чего используется команда _getch?" ,
"\t Для чего используется команда system(\"pause\")?" ,
"\t Для чего используется команда system(\"cls\")?" ,
"\t Для чего используется команда clock()?" ,
"\t Для чего используется команда rand?" ,
"\t Для чего используется команда setlocale?" ,
"\t Для чего используется команда switch?" ,
"\t Для чего используется команда break?" ,
"\t Для чего используется команда return?" ,
"\t Для чего используется using namespace std?" ,
"\t Какое полное название колледжа?" ,
"\t Полное ФИО преподавателя по Системному программированию в 2ИП-1?"
};
string Answers[30][4]{
    {"switch","default","break", "end"}, //1.3
    {"cin","cout","setw","string"}, //2.2
    {">>","||","&&","<<"}, //3.1
    {">>","||","&&","<<"}, //4.4
    {">>","||","&&","<<"}, //5.2
    {">>","||","&&","<<"}, //6.3
    {"//","\"\"","()","{}"}, //7.2
    {"//","[]","()","{}"}, //8.1
    {"//","[]","()","{}"}, //9.3
    {"//","[]","()","{}"}, //10.4
    {"//","[]","()","{}"}, //11.2
    {"cin","cout","setw","string"}, //12.1
    {"cin","cout","setw","string"}, //13.3
    {"cin","cout","setw","string"}, //14.4
    {"Заканчивает программу","Делает пробел","Делает отступ","Переходит на следующую строку"}, //15.4
    {"Заканчивает программу","Делает пробел","Делает отступ","Переходит на следующую строку"}, //16.1
    {"Заканчивает программу","Делает пробел","Делает отступ","Переходит на следующую строку"}, //17.3
    {"Должен быть один знак <","Нет такой команды cin","<< повернуты не в ту сторону","точка с запятой не нужна"}, //18.3
    {"Ставит код на паузу","Ставит код на паузу выводя текст при этом","Делает рандомайзер чисел","Используется для времени в коде"}, //19.1
    {"Ставит код на паузу","Ставит код на паузу выводя текст при этом","Делает рандомайзер чисел","Используется для времени в коде"}, //20.2
    {"Ставит код на паузу","Очищает консоль","Делает рандомайзер чисел","Используется для времени в коде"}, //21.2
    {"Ставит код на паузу","Очищает консоль","Делает рандомайзер чисел","Используется для времени в коде"}, //22.4
    {"Ставит код на паузу","Очищает консоль","Делает рандомайзер чисел", "Локализовывает текст"}, //23.3
    {"Осуществляет выбор пользователя","Прерывает выполнение кода","Делает рандомайзер чисел","Локализовывает текст"}, //24.4
    {"Осуществляет выбор пользователя","Прерывает выполнение кода","Делает рандомайзер чисел","Локализовывает текст"}, //25.1
    {"Для возращения данных","Прерывает выполнение кода","Делает рандомайзер чисел","Для вывода значений"}, //26.2
    {"Для возращения данных","Прерывает выполнение кода","Делает рандомайзер чисел","Для вывода значений"}, //27.1
    {"Для возращения данных","Прерывает выполнение кода","Делает рандомайзер чисел","Для вывода значений"}, //28.4
    {"Морской Авиомоторный Дорожный Колледж","Московский Автомобильный Дорожный Колледж","Московский Автомобильно Дорожный Колледж","Московский Авиалетный Дорогой Колледж"}, //29.3
    {"Семенова Екатерина Владимировна","Семеновна Елена Викторовна","Семенова Анна Александровна","Семеновна Екатерина Владимировна"} //30.1
};
string Correct[30]{
    "break",
    "cout",
    ">>",
    "<<",
    "||",
    "&&",
    "\"\"",
    "//",
    "()",
    "{}",
    "[]",
    "cin",
    "setw",
    "string",
    "Переходит на следующую строку",
    "Заканчивает программу",
    "Делает отступ",
    "<< повернуты не в ту сторону",
    "Ставит код на паузу",
    "Ставит код на паузу выводя текст при этом",
    "Очищает консоль",
    "Используется для времени в коде",
    "Делает рандомайзер чисел",
    "Локализовывает текст",
    "Осуществляет выбор пользователя",
    "Прерывает выполнение кода",
    "Для возращения данных",
    "Для вывода значений",
    "Московский Автомобильно Дорожный Колледж",
    "Семенова Екатерина Владимировна"
};

enum Color { Green = 2, Red = 4, White = 15 };
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
        system("cls");
        cout << "\n\n[+] Вы вышли из игры";
        _getch();
        exit(0);
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
            if (num0 != '1' && num0 != '2' && num0 != '3')
                cout << endl << "[!] Вы ввели некорректные данные!" << endl;
        } while (num0 != '1' && num0 != '2' && num0 != '3');
        if (num0 == '1')
            difficulty = 10;
        else if (num0 == '2')
            difficulty = 15;
        else if (num0 == '3')
            difficulty = 20;
        nastroykicase();
        break;
    case '2':
        cout << "[+] Настройки:\n\n";
        do {
            cout << "[+] Введите количество жизней (макс 3):";
            cin >> num0;
            if (num0 != '0' && num0 != '1' && num0 != '2' && num0 != '3')
                cout << endl << "[!] Вы ввели некорректные данные!" << endl;
        } while (num0 != '0' && num0 != '1' && num0 != '2' && num0 != '3');
        if (num0 == '0')
            life = 0;
        else if (num0 == '1')
            life = 1;
        else if (num0 == '2')
            life = 2;
        else if (num0 == '3')
            life = 3;
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
        if (num0 == '0')
            clue = 0;
        else if (num0 == '1')
            clue = 1;
        nastroykicase();
        break;
    case '4':
        cout << "[+] Настройки:\n\n";
        cout << "[+] Время на викторину от 2 до 10 минут (Пример записи: 3.30-3 минуты 30 секунд)";
        do {
            cout << endl << "[+] Введите ваше время на викторину:";
            cin >> num4;
            if (num4 < 2 || num4>10)
                cout << endl << "[!] Вы ввели некорректные данные!";
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
void check()
{
    cout << endl;
    cout << "[+] Жизней осталось: " << life << endl;
    Ending_Time = clock();
    Result_Time = Ending_Time - Beginning_Time;
    if ((gametime - (Ending_Time / 1000) / 60) > 0 && (gametime - (Ending_Time / 1000)) - (((gametime - (Ending_Time / 1000)) / 60) * 60) > 0)
        cout << "[+] Времени осталось: " << (gametime - (Ending_Time / 1000)) / 60 << ":" << (gametime - (Ending_Time / 1000)) - (((gametime - (Ending_Time / 1000)) / 60) * 60) << endl;
    else
        cout << "[+] Времени осталось: 0:0" << endl;
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
void gamecase()        // Игра меню
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
        for (int j = 0;j < 30;j++) //выбор определенного вопроса
            if (mas[i] == j + 1)
                num5 = j;
        cout << "[+] " << i + 1 << " Вопрос:" << endl;
        cout << Question[num5] << endl << endl;
        for (int j = 0; j < 4; j++) {         // выведение вариантов в консоль
            if (mas1[j] == 1) {
                if (Answers[num5][0] == Correct[num5])
                    mas2[j] = Correct[num5];
                cout << "[" << j + 1 << "] " << Answers[num5][0] << endl;
            }
            else if (mas1[j] == 2) {
                if (Answers[num5][1] == Correct[num5])
                    mas2[j] = Correct[num5];
                cout << "[" << j + 1 << "] " << Answers[num5][1] << endl;
            }
            else if (mas1[j] == 3) {
                if (Answers[num5][2] == Correct[num5])
                    mas2[j] = Correct[num5];
                cout << "[" << j + 1 << "] " << Answers[num5][2] << endl;
            }
            else if (mas1[j] == 4) {
                if (Answers[num5][3] == Correct[num5])
                    mas2[j] = Correct[num5];
                cout << "[" << j + 1 << "] " << Answers[num5][3] << endl;
            }
        }
        cout << endl << "[5] Подсказка 50/50" << endl << endl;
        answnum();
        if (answer == 5 && clue > 0) {
            clue--;
            system("cls");
            cout << "[+] " << i + 1 << " Вопрос:" << endl;
            cout << Question[num5] << endl << endl;
            for (int j = 0; j < 4; j++) {         // выведение вариантов в консоль 50/50
                if (mas1[j] == 1) {
                    if (Answers[num5][0] == Correct[num5])
                        SetConsoleTextAttribute(hConsole, White);
                    else if (answers == true) {
                        answers = false;
                        SetConsoleTextAttribute(hConsole, White);
                    }
                    else
                        SetConsoleTextAttribute(hConsole, Red);
                    cout << "[" << j + 1 << "] " << Answers[num5][0] << endl;
                }
                else if (mas1[j] == 2) {
                    if (Answers[num5][1] == Correct[num5])
                        SetConsoleTextAttribute(hConsole, White);
                    else if (answers == true) {
                        answers = false;
                        SetConsoleTextAttribute(hConsole, White);
                    }
                    else
                        SetConsoleTextAttribute(hConsole, Red);
                    cout << "[" << j + 1 << "] " << Answers[num5][1] << endl;
                }
                else if (mas1[j] == 3) {
                    if (Answers[num5][2] == Correct[num5])
                        SetConsoleTextAttribute(hConsole, White);
                    else if (answers == true) {
                        answers = false;
                        SetConsoleTextAttribute(hConsole, White);
                    }
                    else
                        SetConsoleTextAttribute(hConsole, Red);
                    cout << "[" << j + 1 << "] " << Answers[num5][2] << endl;
                }
                else if (mas1[j] == 4) {
                    if (Answers[num5][3] == Correct[num5])
                        SetConsoleTextAttribute(hConsole, White);
                    else if (answers == true) {
                        answers = false;
                        SetConsoleTextAttribute(hConsole, White);
                    }
                    else
                        SetConsoleTextAttribute(hConsole, Red);
                    cout << "[" << j + 1 << "] " << Answers[num5][3] << endl;
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
        else if (answer == 5 && clue == 0) {
        do {
            cout << endl << endl << "[!] У вас кончились подсказки!"<<endl;
            answnum();
        } while (answer == 5);
        }
        system("cls");
        cout << "[+] " << i + 1 << " Вопрос:" << endl;
        cout << Question[num5] << endl << endl;
        
        for (int j = 0; j < 4; j++) {         // выведение вариантов в консоль ответ
            if (mas1[j] == 1) {
                if (Answers[num5][0] == Correct[num5])
                    SetConsoleTextAttribute(hConsole, Green);
                else
                    SetConsoleTextAttribute(hConsole, Red);
                cout << "[" << j + 1 << "] " << Answers[num5][0] << endl;
            }
            else if (mas1[j] == 2) {
                if (Answers[num5][1] == Correct[num5])
                    SetConsoleTextAttribute(hConsole, Green);
                else
                    SetConsoleTextAttribute(hConsole, Red);
                cout << "[" << j + 1 << "] " << Answers[num5][1] << endl;
            }
            else if (mas1[j] == 3) {
                if (Answers[num5][2] == Correct[num5])
                    SetConsoleTextAttribute(hConsole, Green);
                else
                    SetConsoleTextAttribute(hConsole, Red);
                cout << "[" << j + 1 << "] " << Answers[num5][2] << endl;
            }
            else if (mas1[j] == 4) {
                if (Answers[num5][3] == Correct[num5])
                    SetConsoleTextAttribute(hConsole, Green);
                else
                    SetConsoleTextAttribute(hConsole, Red);
                cout << "[" << j + 1 << "] " << Answers[num5][3] << endl;
             }
        }
        SetConsoleTextAttribute(hConsole, White);
        cout << endl << "[5] Подсказка 50/50" << endl << endl;
        cout << "Введите ваш ответ:" << answer << endl << endl;
        for (int j = 0;j < 4;j++) {
            if (answer == j + 1) {
                if (mas2[j] == Correct[num5])
                    cout << "[+] Поздравляем, вы выбрали правильный ответ" << endl << endl;
                else {
                    cout << "[+] Вы выбрали неправильный ответ" << endl;
                    life--;
                }
            }
        }
        check();
    }
system("cls");
cout << "[!] Поздравляем! Вы выиграли!" << endl;
_getch();
}
void answnum() {
    do {
        cout << "Введите ваш ответ:";
        cin >> num0;
        if (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4' && num0 != '5')
            cout << endl << "[!] Вы ввели некорректные данные!" << endl;
    } while (num0 != '1' && num0 != '2' && num0 != '3' && num0 != '4' && num0 != '5');
    if (num0 == '1')
        answer = 1;
    else if (num0 == '2')
        answer = 2;
    else if (num0 == '3')
        answer = 3;
    else if (num0 == '4')
        answer = 4;
    else if (num0 == '5')
        answer = 5;
}
