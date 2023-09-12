// cppm-homeworks_08_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>
#include <stdexcept>

int function(std::string str, int forbidden_length);

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string word;
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    std::cin.ignore();
    bool flag = true;
    while (flag) {
        
        std::cout << "Введите слово: ";        
        getline(std::cin, word);   
        try {
            std::cout << "Длина слова \"" << word << "\" равна " << function(word, forbidden_length) << std::endl;
        }
        catch (std::length_error& error) {
            std::cout << error.what() << "До свидания" << std::endl;
            flag = false;
        }
        catch (...) {
            std::cout << "Неизвестная ошибка!" << std::endl;
            flag = false;
        }
    }

    
}

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) { 
        throw std::length_error("Вы ввели слово запретной длины! ");
    }
    return str.length();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
