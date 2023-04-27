#ifndef _DRAWINTERFACE_H_
#define _DRAWINTERFACE_H_

/// Special library
#include <SFML/Graphics.hpp>

/// STL
#include <iostream>
#include <vector>
#include <string>

class DrawInterface {

private:

	//police d'ecriture
	const char* font = "font/SuperLegendBoy.ttf";

	/// Vector sprite for draw in the window
	std::vector <sf::Sprite> vectorSprite;

	/// Vector text for draw in the window
	std::vector <sf::Text> vectorText;


public:

	/// \return drawing srite
	std::vector <sf::Sprite> getDrawingSprite(void) const;

	/// \return drawing text
	std::vector <sf::Text> getDrawingText(void) const;

	/// Continue the animation of the Sword and add it in the list Sprite
	virtual void drawSword(void) = 0;

	///
	virtual void drawRubis(void) = 0;

	virtual void drawMap(void) = 0;

	virtual void drawChestGain(void) = 0;

	virtual void drawChest(void) = 0;

	virtual void allDrawWindow(void) = 0;

	virtual void extractSpriteFromVector(std::vector <sf::Sprite> vector) = 0;

};
#endif
