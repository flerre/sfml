#include <iostream>
#include <TGUI/TGUI.hpp>

int main()
{
        // variables to the mouse
    int mousex=0;
    int mousey=0;
        
        // drawing the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Button");
    
        // drawing the circle and setting position/color
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(800.f, 500.f));
        
        // drawing texture 
    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromFile("image.png"))
    {
    }
    sprite.setTexture(texture);

        // drawing text
    //sf::String text;
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("arial-black.ttf"))
    {
    }
    text.setFont(font);
    text.setString("Hello world");
    text.setPosition(200,300);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    
        // adding gui to the window and creating a button/editbox
    tgui::Gui gui(window);
    gui.setFont(font);
    //tgui::Theme blackTheme{"TGUI/themes/Black.txt"};
    tgui::Button::Ptr button = tgui::Button::create();
    button->setPosition(800, 500);
    gui.add(button);
    
    tgui::EditBox::Ptr editBox = tgui::EditBox::create();
    gui.add(editBox, "MyWidgetName");

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
	        if (event.type == sf::Event::MouseMoved)
	        {
    		        mousex = event.mouseMove.x;
    		        mousey = event.mouseMove.y;
	        }
	        if (shape.getGlobalBounds().contains(mousex, mousey)) 
	        {
                        if (event.mouseButton.button == sf::Mouse::Left)
	                {
	                        std::cout << "Click" << std::endl;
	                        sprite.setPosition(sf::Vector2f(10.f, 50.f));
	                        sprite.setColor(sf::Color(100, 255, 100, 200));   
	                }
                }
                if (event.type == sf::Event::Closed)
                        window.close();

                gui.handleEvent(event);
           }
        window.clear();
        gui.draw();
        window.draw(shape);
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
    return 0;
}


