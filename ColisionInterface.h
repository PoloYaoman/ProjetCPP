#ifndef _COLISIONINTERFACE_H_
#define _COLISIONINTERFACE_H_

/// Special library
#include <SFML/Graphics.hpp>

/// STL
#include <iostream>
#include <vector>
#include <string>

class ColisionInterface {

public:



    /// Check if two sprite are in contact
     /// \param sprite1 First sprite
     /// \param sprite2 Second sprite
     /// \return True if the two sprite are in contact
    virtual bool collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2) = 0;

    /// Chec if the player's sword is in conctact with the target
    /// \param target the sprite in contact with the sword
    /// \return True if the sprite is in constact with the sword
    virtual bool collideSword(sf::Vector2f target) = 0;

    /// Check if the sprite is in contact with a list of sprite
    /// \param user The sprite Checked
    /// \param wall List of sprite
    /// \return True if the sprite is in constact with at least one
    virtual bool collideWall(sf::Vector2f user, std::vector <sf::Vector2f> wall) = 0;

    /// Check if the next move is possible
    /// \param user The sprite who will move
    /// \param move His deplacement
    /// \return True if he can't move
    virtual bool previewCollide(sf::Vector2f user, sf::Vector2f move) = 0;

    /// Check if the sprite will go out the map
    /// \param user The sprite Check
    /// \param move His deplacement
    /// \return True if he go out the map
    virtual bool previewLimitMap(sf::Vector2f user, sf::Vector2f move) = 0;

    ///
    virtual void collideMonster(void) = 0;

    /// Check where the sprite if in contact
    /// \param sprite1 The sprite who suffered the contact
    /// \param sprite2 The sprite who afflict the contact
    virtual int collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2) = 0;

};
#endif

#pragma once
