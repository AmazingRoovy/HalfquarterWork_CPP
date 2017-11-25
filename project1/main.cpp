#include <iostream>  // cout << и cin >>.
#include <vector>    // Использование векторов.
#include <string>    // Использование строк.
#include <cstring>   // Некоторые полезные функции для работ со строками.
#include <algorithm> // Использование функций-алгоритмов.
#include <utility>   // Использование пар.
#include <map>       // Использование ассоциативных массивов.

using namespace std; // Отказ от неудобных конструкций пространства имен (std::operator).

// Некоторые определения типов данных для удобства последующего использования в коде.
typedef map <string, string> m_type;
typedef vector <pair <float, float>> v_type;


// *************** ЗАДАНИЕ 1 ***************

template <class X>                                      // Шаблонный класс QueueTemplate.
class QueueTemplate {
    int n = 0;                                          // Размер массива arr.
    X *arr = new X[n];                                  // Динамический массив размерностью n.
public:
    QueueTemplate(int len) {                            // Конструктор QueueTemplate, в котором задается размер дин. массива arr.
        cout << "Array has been created! Ex.1 has begun." << endl;
        this -> n = len;
        for (int i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }
    }

    ~QueueTemplate() {                                  // Деструктор QueueTemplate, в котором удаляется массив arr.
        delete [] arr;
        cout << endl << "Array has been destroyed! Ex.1 has ended." << endl;
    }

    void show() {                                       // Вспомогательная функция, чтобы выводить значения нашего массива на экран.
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
    }

    void add_elem(X k) {                                // Функция добавления нового k элемента в начало массив.
        X *new_arr = new X[sizeof(arr) + 1];            // увеличение размера дин. массива (n - длина массива в данном случае).
        for (unsigned int i = 0; i < sizeof(arr); ++i) {
            new_arr[i + 1] = arr[i];
        }
        new_arr[0] = k;
        delete [] arr;
        arr = new_arr;
    }

    void del_elem() {                                   // Функция удаления элемента из конца массива.

        // Вариант 1. (Не работает!)

        X *new_arr = new X[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            new_arr[i] = arr[i];
        }
        delete [] arr;
        arr = new_arr;


        // Вариант 2. (Также не работает...)

        vector <int> help_v;
        vector <int>::iterator it1;
        for (unsigned int i = 0; i < sizeof(arr); ++i) {
            help_v[i] = arr[i];
        }
        help_v.pop_back();
        delete [] arr;
        arr = new int[help_v.size()];
        int i = 0;
        for (it1 = help_v.begin(); it1 != help_v.end(); ++it1) {
            arr[i] = *it1;
            i++;
        }
    }

    void empty_or_size() {                              // Функция выводит текущее размерное "состояние" массива.
        if (n == 0) {
            cout << "Array is not empty!";
        } else {
            cout << "In this array we have: " << n << " elements now.";
        }
    }
};



// *************** ЗАДАНИЕ 2 ***************

class PointPairVector {
    v_type ppv_vec;                                     // Вектор пар, состоящих из двух float'ов - координат точек. v_type описан выше.
public:
    PointPairVector() {                                 // Конструктор PointPairVector'a.
        cout << endl << "PointPairVector object has been created! Ex.2 has begun." << endl;
    }

    void clear_all() {                                  // Функция зачистки вектора.
        ppv_vec.clear();
    }

    ~PointPairVector() {                                // Деструктор PointPairVector'a.
        cout << endl << "PointPairVector object has been destroyed! Ex.2 has ended." << endl;
    }

    void add_point(float x, float y) {                  // Функция добавления новой точки (пары координат) в вектор ppv_vec.
        pair <float, float> new_pair;
        new_pair.first = x;
        new_pair.second = y;
        ppv_vec.push_back(new_pair);
    }

    void clear_more_5() {                               // Функция зачистки всех пар вектора, первый элемент которых (т.е. x) превышает значение 5.
        v_type::iterator it;
        for (it = ppv_vec.begin(); it != ppv_vec.end(); ++it) {
            if (it -> first > 5.0) {
                ppv_vec.erase(it);
            }
        }
    }

    void show_points() {                                // Вспомогательная функция вывода всех элементов пар нашего вектора ppv_vec.
        for (unsigned int i = 0; i < ppv_vec.size(); ++i) {
            cout << ppv_vec[i].first << ' ' << ppv_vec[i].second << endl;
        }
    }
};


// *************** ЗАДАНИЕ 3 ***************

class ExtStringV1 {
    string str;                                         // Исходная строка (пустая).
public:

    void show_ES() {
        string::iterator it_s;
        for (it_s = str.begin(); it_s != str.end(); ++it_s) {
            cout << *it_s;
        }
    }

    ExtStringV1(string value) {                         // Конструктор ExtStringV1
        this -> str = value;
        cout << "ExtStringV1 object has been created! Ex.3 has begun." << endl;
    }

    ~ExtStringV1() { // Деструктор ExtStringV1.
        str.clear();
        cout << endl << "ExtStringV1 object has been destroyed! Ex.3 has ended."; // Мы говорим здесь условно, что строка удалена.
    }                                                   // Стерты все значения в ней, но сама она еще существует в виде пустой строки.

    string *find_substring(string sub) {                   // Функция поиска подстроки sub в нашей строке str;
        string::iterator it;
        it = find (str.begin(), str.end(), sub);
        return str;                                       // возвращение значения.
    }

    int str_cmp(char* another_s) {                     // Функция сравнения двух строк между собой.
        return (strcmp(str.c_str(), another_s));
    }

    void str_ins(string another_s, int k) {             // Функция вставки в строку str k элементов из строки another (в данном случае).
        str.insert(k, another_s);
    }
};


// *************** ЗАДАНИЕ 4 ***************

class GETQuery {
    m_type my_map;                                      // Ассоциативный массив типа m_type. Этот тип описан выше.
public:
    GETQuery() {                                        // Конструктор GETQuery.
        cout << "GETQuery object has been created! Ex.4 has begun.";
    }

    ~GETQuery() {                                        // Деструктор GETQuery.
        cout << endl << "GETQuery object has been destroyed! Ex.4 has ended.";
    }

    void search(string key) {                           // Функция поиска по ключу.
        cout << my_map[key];
    }

    void add_new_pair(string key, string value) {       // Функция добавления новой ассоциативной пары.
        my_map[key] = value;
    }

    void del_pair(string key) {                         // Функция удаления пары по ключу.
        my_map.erase(key);
    }

    void show_GQ() {                                    // Демонстрационная вспомогательная функция.
        m_type::iterator it;
        cout << "Your map now is:" << endl;
        cout << '{';
        for (it = my_map.begin(); it != my_map.end(); ++it){
            if (it != my_map.begin()) {
                cout << ", ";
            }
            cout << "\"" << it -> first << ": " << it -> second << '\"';
        }
        cout << '}' << endl << endl;
    }

    void change_key(string key) {                       // Функция изменения значения ключа.
        string new_value;
        show_GQ();                                      // Вызываем функцию-пощницу для удобства пользователя.
        getline(cin, new_value);
        my_map[key] = new_value;
    }

    void output_res(char keys[]) {                      // Функция по запросу (подробнее - последнее подзадание задания 4 в к/р).
        m_type::iterator it;
        char *st = strtok(keys, " ");
        cout << "?";
        int i = 0;
        while (st != NULL) {
            for (it = my_map.begin(); it != my_map.end(); ++it) {
                if (st == it -> first) {
                    if (i != 0) {
                        cout << '&';
                    }
                    cout << it -> first << '=' << it -> second;
                    i++;
                }
            }
            st = strtok(NULL, " ");
        }
    }
};

int main() {

    cout << "Welcome! Please, input number of elements of the array in first ex.: ";
    /*
    // ЗАДАНИЕ 1

    int m = 0;
    cin >> m;                                           // Ввод первоначального размера массива m.

    QueueTemplate <int> qt(m);                          // Создаем QueueTemplate объект, задавая конструктором размер атрибута arr = m.

    qt.empty_or_size();                                 // Здесь и далее - проверяем размер массива arr.
    cout << endl;

    qt.add_elem(42);                                    // Добавляем элемент 42 в начало массива arr.
    cout << endl;
    qt.show();                                          // Демонстрируем массив arr.

    qt.add_elem(11);
    cout << endl;
    qt.show();
    cout << endl;

    // qt.del_elem(); <- эту функцию надо доработать для корректной работы.

    */

    // ЗАДАНИЕ 2

    PointPairVector vec_p;

    cout << "Input coordinates of new point: ";
    float x, y;
    cin >> x >> y;                                      // Введем координаты одной точки с клавиатуры, чтобы тестировать.
    vec_p.add_point(x, y);                              // Добавим эту точку в наш вектор.

    float x1 = 7.4, x2 = 10.3, x3 = 1.0;                // Создадим еще несколько точек, чтобы был заметен эффект функции удаления...
    float y1 = 4.5, y2 = 5.1, y3 = 9.6;                 // ...по x'у и y'у.

    vec_p.add_point(x1, y1);                            // Добавляем их в вектор.
    vec_p.add_point(x2, y2);
    vec_p.add_point(x3, y3);
                                                        // Показываем конечное содержание вектора.
    vec_p.show_points();
                                                        // Удаляем все пары, где x > 5.
    vec_p.clear_more_5();
                                                        // Показываем, что получилось.
    cout << endl;
    vec_p.show_points();
                                                        // Зачищаем вектор полностью.
    vec_p.clear_all();

    // ЗАДАНИЕ 3

    ExtStringV1 ext_s("Hello");                        // Создаем ExtStringV1, присваивая атрибуту-строке значение "Hello!" через конструктор

    string *fin = ext_s.find_substring("He");
    cout << endl;
    cout << *fin;


    char an_str[] = "Hello!";

    int p = ext_s.str_cmp(an_str);
    cout << endl;
    if (p == 0) {
        cout <<  "This strings are equally!";
    } else if (p > 0) {
        cout << "String #1 is more than string #2.";
    } else if (p < 0) {
        cout << "String #2 is more than string #1.";
    }
    cout << endl;
    ext_s.str_ins(an_str, 2);
    ext_s.show_ES();
    cout << endl;


    // ЗАДАНИЕ 4

    GETQuery map1;

    map1.add_new_pair("USA", "New York");               // Задаем ассоциативные пары в нашем map'е.
    map1.add_new_pair("Japan", "Tokio");
    map1.add_new_pair("France", "Paris");
    map1.add_new_pair("Russia", "Pushkino");

    map1.search("USA");                                 // Ищем значение элемента под ключом "USA". Воспользуемся вспомогательным методом .search() для этого.
    map1.del_pair("France");                            // Удаляем пару под заданным ключом (тут - "France").

    cout << endl << endl;

    map1.change_key("Russia");                          // Меняем значение под ключом "Russia"
                                                        // (Например, можем задать вместо "Pushkino" значение "Moscow".


    cout << "Input word 'Go' and after this - your request: ";
    const int N = 50;
    char mas_char[N];

    cin.get();
    cin.getline(mas_char, sizeof(mas_char));            // Вводим запрос! (А точнее заполняем массив char'а символами).

    cout << endl << endl;

    map1.output_res(mas_char);                          // Последнее подзадание задания 4-ого. На вход принимаем массив char ключей,
                                                        // вывод которых надо выполнить.

}
