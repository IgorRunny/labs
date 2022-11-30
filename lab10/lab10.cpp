
#include <iostream>
#include <vector>
#include <string>
class subscriber
{
private:
    unsigned int m_id;
    std::string m_address;
public:
    subscriber(int id, std::string address)
    {
        m_id = id;
        m_address = address;
    }
    int getid()
    {
        return m_id;
    }
}; 
class provider
{
private:
    std::string m_title;
    std::vector <subscriber*> m_listsub;
public:
    provider(std::string title)
    {
        m_title = title;
    }
    void Addsub(subscriber* subscriber)
    {
        m_listsub.push_back(subscriber);
    }
    void getsubs()
    {
        for (size_t i = 0; i < m_listsub.size(); i++)
        {
            std::cout << m_listsub[i]->getid() << "\n";
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";
    provider provider0("ROSTELEKOM");
    subscriber subscriber0 (rand(), "Leninsky av. 14");
    subscriber subscriber1 (rand(), "Mira av. 27b");
    provider0.Addsub(&subscriber0);
    provider0.Addsub(&subscriber1);
    provider0.getsubs();



}

