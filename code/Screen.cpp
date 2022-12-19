#include "Screen.h"

Screen::Screen(double width, double height) 
{
    Texture *texture2 = new Texture; 
    texture2->loadFromFile("images/bg.jpg"); 
    beginningbackground.setTexture(*texture2); 
    beginningbackground.setScale(0.53, 0.35); 

    Texture *texture3 = new Texture;
    texture3->loadFromFile("images/start.png"); 
    button.setTexture(*texture3); 
    button.setScale(0.4,0.4);    
    FloatRect bound = button.getGlobalBounds();
    button.setPosition((width/4)-(bound.width/2), 200);  
    
    Texture *texture4 = new Texture;
    texture4->loadFromFile("images/logo.png");
    logo.setTexture(*texture4);
    logo.setScale(0.4, 0.4); 
    FloatRect bound2 = logo.getGlobalBounds();
    logo.setPosition((width/4)-(bound2.width/2), 50);  

}; 


void Screen::start(RenderWindow& window, Font &font)
{
    Text text; 
	text.setFont(font);
	text.setPosition(125,400); 
    text.setOutlineColor(Color::Black);
    text.setOutlineThickness(2);  
	text.setString("CLICK TO START!");
	text.setCharacterSize(45);
	window.draw(beginningbackground); 
    window.draw(button); 
    window.draw(logo); 
    window.draw(text); 
}

Sprite Screen::bg(RenderWindow& window)
{
    beginningbackground.setScale(0.95, 0.8); 
	return beginningbackground; 
}


FloatRect Screen::getBounds() { return button.getGlobalBounds(); }

void Screen::endScreen(Player& player, RenderWindow& window, View& view, Font& font, Clock &clock)
{
    player.Draw(window); 
    Text text; 
    text.setPosition(220, 300); 
    text.setOutlineColor(Color::White); 
    text.setFillColor(Color::Black); 
    text.setFont(font); 
    text.setOutlineThickness(4); 
    text.setCharacterSize(140); 
    text.setString("GAME OVER!");
	if (player.GetPosition().y > 3500)
    {
        RectangleShape rect(Vector2f{WINDOW_WIDTH*2 , WINDOW_HEIGHT*2}); 
        rect.setFillColor(Color(0,0,0,100));
		view.setCenter(500,750); 
		rect.setPosition(0,0);
		window.setView(view); 
		window.draw(rect); 
        window.draw(text); 
    }
}

void Screen::playScreen(Player& player, View& view, RenderWindow& window, vector<Sprite>& platforms, Clock& clock, Font &font)
{
    Text points; 
    string str = "POINTS: " + to_string(static_cast<int>(clock.getElapsedTime().asSeconds())); 
    points.setPosition(30, player.GetPosition().y-830); 
    points.setColor(Color::Black);
    points.setFont(font); 
    points.setCharacterSize(50); 
    points.setString(str); 
    for (int i = 0; i < platforms.size(); i++) {window.draw((platforms[i]));}
    window.setView(view);
    player.Draw(window);
    window.draw(points); 
    view.setCenter(WINDOW_WIDTH/2, player.GetPosition().y-200);   
}
