#include <SFML/Graphics.hpp>

class AnimatedText
{
private:
    std::string m_text;
    double m_DurPerSec;
    std::vector <std::string> m_arr;
    void SetArr()
    {
        for (int i = 0; i < m_text.size(); i++)
        {
            m_arr.push_back(m_text.substr(0, i));
        }
    }
public:
    AnimatedText(const std::string& text, const int& duration)
    {
        m_text = text;
        m_DurPerSec = text.size() / duration;
    }

    std::string Get()
    {
        std::string temp;
        if (m_arr.size() == 0)
        {
            return "";
        }
        temp = *m_arr.begin();
        m_arr.erase(m_arr.begin());
        return temp;
    }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}