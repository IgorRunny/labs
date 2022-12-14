// practice6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
class people
{
private:
    std::string m_name;
    int m_age;
    bool m_gender; // 1 - male; 0 - female
public:
    people (int age, bool gender, std::string name)
    {
        m_name = name;
        m_age = age;
        m_gender = gender;
    }
    int GetAge()
    {
        return m_age;
    }
    bool GetGender()
    {
        return m_gender;
    }
    std::string GetName()
    {
        return m_name;
    }
    ~people()
    {}
};
int main()
{
    std::vector <people> ListOfPeople;
    people people1(17, 1, "Pasha");
    people people2(28, 0, "Alexa");
    people people3(40, 1, "Harry");
    ListOfPeople.push_back(people1); // команда добавляет объект в конец массива
    ListOfPeople.push_back(people2);
    ListOfPeople.push_back(people3);
    std::cout << ListOfPeople[1].GetName() << "\n";
    ListOfPeople.erase(ListOfPeople.begin()+1); // команда стирает указанный элемент(или последовательность элементов)
    std::cout << ListOfPeople[1].GetName() << "\n";
    people people4(10, 0, "Marlin");
    ListOfPeople.insert(ListOfPeople.begin()+1, people4); // команда вставляет новый элемент перед указанным элементом
    std::cout << ListOfPeople[1].GetName() << "\n";
    ListOfPeople.emplace_back(82, 1, "Oleg"); // команда создает объект класса и сразу же добывляет его в конец массива
    std::cout << ListOfPeople[3].GetName() << "\n";
    std::cout << ListOfPeople.size() << "\n";
    ListOfPeople.resize(3, people1); // команда изменяет размер вектора 
    std::cout << ListOfPeople.size() << "\n";
    std::cout << ListOfPeople.capacity() << "\n"; // команда выдает количество зарезервированного места
    ListOfPeople.reserve(5); // команда позволяет увеличить capacity вручную
    std::cout << ListOfPeople.capacity() << "\n";
    ListOfPeople.shrink_to_fit(); // команда уменьшает capasity до size объекта(то есть убирает незаполненую зарезервированную память)
    std::cout << ListOfPeople.capacity() << "\n";
    std::cout << sizeof(ListOfPeople) << "\n";// 8 байт занимает указатель на начало вектора; 8 - на конец; 8 - на последний добавленный элемент и 8 байта для выравнивания объема занимаемой памяти
    ListOfPeople[0] = people3; // команда присваивания и []

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
