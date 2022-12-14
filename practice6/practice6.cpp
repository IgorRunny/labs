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
    ListOfPeople.push_back(people1); // ������� ��������� ������ � ����� �������
    ListOfPeople.push_back(people2);
    ListOfPeople.push_back(people3);
    std::cout << ListOfPeople[1].GetName() << "\n";
    ListOfPeople.erase(ListOfPeople.begin()+1); // ������� ������� ��������� �������(��� ������������������ ���������)
    std::cout << ListOfPeople[1].GetName() << "\n";
    people people4(10, 0, "Marlin");
    ListOfPeople.insert(ListOfPeople.begin()+1, people4); // ������� ��������� ����� ������� ����� ��������� ���������
    std::cout << ListOfPeople[1].GetName() << "\n";
    ListOfPeople.emplace_back(82, 1, "Oleg"); // ������� ������� ������ ������ � ����� �� ��������� ��� � ����� �������
    std::cout << ListOfPeople[3].GetName() << "\n";
    std::cout << ListOfPeople.size() << "\n";
    ListOfPeople.resize(3, people1); // ������� �������� ������ ������� 
    std::cout << ListOfPeople.size() << "\n";
    std::cout << ListOfPeople.capacity() << "\n"; // ������� ������ ���������� ������������������ �����
    ListOfPeople.reserve(5); // ������� ��������� ��������� capacity �������
    std::cout << ListOfPeople.capacity() << "\n";
    ListOfPeople.shrink_to_fit(); // ������� ��������� capasity �� size �������(�� ���� ������� ������������ ����������������� ������)
    std::cout << ListOfPeople.capacity() << "\n";
    std::cout << sizeof(ListOfPeople) << "\n";// 8 ���� �������� ��������� �� ������ �������; 8 - �� �����; 8 - �� ��������� ����������� ������� � 8 ����� ��� ������������ ������ ���������� ������
    ListOfPeople[0] = people3; // ������� ������������ � []

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
