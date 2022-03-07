#include <iostream>
#include "deque.cpp"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int option;
    bool stop = false;
    Deque a, b;
    a.push(2, Priority::rear_high);
    a.push(66, Priority::rear_high);
    a.push(9, Priority::rear_medium);
    a.push(100, Priority::rear_low);
    a.push(13, Priority::rear_low);
    a.push(8, Priority::rear_low);
    b.push(0, Priority::rear_high);
    b.push(100000, Priority::rear_medium);
   
    cout << a << endl;

    cout << "Введите номер операции." << endl;
    try {
        while (!stop) {
            cout << "1. Определить количество всех элементов и количество элементов с каждым приоритетом;\n"
                << "2. Проверить на пустоту\n"
                << "3. Вставить элемент\n"
                << "4. Удалить элемент\n"
                << "5. Получить значение и приоритет первого элемента;\n"
                << "6. Проверить operator=\n"
                << "7. Проверка конструктора копирования, где третья очередь копирует значения первой: Deque c(a)\n"
                << "Операция(для выхода любой другой ввод): - ";
            cin >> option;
            switch (option)
            {
            case 1:
            {
                cout << "Всего элементов " << a.size()
                    << ", включая: низкий приоритет - " << a.sizePriority(rear_low)
                    << ", средний приоритет - " << a.sizePriority(rear_medium)
                    << ", высокий приоритет - " << a.sizePriority(rear_high) << endl;
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "очередь " << (a.IsEmpty() ? "пуста" : "не пуста") << endl;
                cout << endl;
                break;
            }
            case 3:
            {
                int value, priority;
                cout << "Введите число: ";
                cin >> value;
                cout << "Введите цифру приоритета(high это 1,medium это 2,low это 3): ";
                cin >> priority;
                switch (priority)
                {
                case 1:
                {
                    a.push(value, Priority::rear_high);
                    break;
                }
                case 2:
                {
                    a.push(value, Priority::rear_medium);
                    break;
                }
                case 3:
                {
                    a.push(value, Priority::rear_low);
                    break;
                }
                default:
                {
                    cout << "Ошибка: неверный параметр" << endl;
                    break;
                }
                }
                cout << a << endl;
                break;
            }
            case 4:
            {
                a.pop();
                cout << a << endl;
                break;
            }
            case 5:
            {
                cout << "Первый элемент это " << a.getFirstValue()
                    << ", его приоритет - " << a.getFirstPriority() << endl<<endl;
              
                break;
            }
            case 6:
            {
                cout << "был таким первый " << a << endl << "а второй "<< b << endl;
                b=a;
                cout << "Сейчас первый " << a << endl << "а второй "<< b << endl;
                break;
            }
            case 7:
            {
                Deque c(a);
                cout << "первый " << a << endl << "а третий " << c << endl;
                break;
            }
            default:exit(1);
            }
        }
    }
    catch (exception& error) {
        cerr << error.what() << endl;
    }
}