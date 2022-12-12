#include <iostream>
template<typename T>
class Array
{
private:
    T* m_arr;
    int m_size{};
    int m_capacity{};
public:
    Array()
    {
        m_arr = new T[1];
        m_capacity = 1;
    }
    int Size() const
    {
        return m_size;
    }
    int Capacity() const
    {
        return m_capacity;
    }
    void AddMem()
    {
        m_capacity *= 2;
        T* tmp = m_arr;
        m_arr = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_arr[i] = tmp[i];
        }
        delete[] tmp;
    }
    void SetBack(const T& x)
    {
        if (m_size >= m_capacity)
        {
            AddMem();
        }
        m_arr[m_size++] = x;
    }
    void DeleteUnit(int a)
    {
        for (int i = a + 1; i < m_size; i++)
        {
            m_arr[i - 1] = m_arr[i];
        }
        m_size--;
    }
    T GetUnit(int i)
    {
        return m_arr[i];
    }
    ~Array()
    {
        delete[] m_arr;
    }
    void ChangeUnit(int i, const T& x)
    {
        m_arr[i] = x;
    }
    void AddByIndex(int j, const T& x)
    {
        if (m_size + 1 >= m_capacity)
        {
            AddMem();
        }
        T* tmp = m_arr;
        for (int i = j; i < Size() + 1; i++)
        {
            m_arr[i + 1] = tmp[i];
        }
        m_arr[j] = x;
        
    }
};


int main()
{

    Array<int> arr1;
    for (int i = 0; i < 5; i++)
    {
        int x = rand();
        arr1.SetBack(x);
    }
    std::cout << "size of array: " << arr1.Size();
    std::cout << "\n" << "\n";
    std::cout << "Old value index 3: " << arr1.GetUnit(3) << "\n";
    arr1.AddByIndex(3, 78);
    std::cout << "new value index 3: " << arr1.GetUnit(3) << "\n";
    arr1.ChangeUnit(3, 0);
    std::cout << "Changing value index 3: " << arr1.GetUnit(3) << "\n";
    arr1.DeleteUnit(3);
    for (int i = 0; i < arr1.Size(); i++)
    {
        std::cout << arr1.GetUnit(i) << "\n";
    }
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
