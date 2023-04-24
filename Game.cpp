#include "Game.h"

Game::Game(void)/*liste des wall et ground à charger type, greenWall(path) */ {

    setMapUpdate();

}

std::vector <sf::Sprite> Game::getDrawingSprite(void) const {
    return vectorSprite;
}

std::vector <sf::Text> Game::getDrawingText(void) const {
    return vectorText;
}

bool Game::playerIsAlive(void) {
    return player.isAlive();
}


//gestion des colisions


void Game::collideMonster(void) {
    if (collideTwoSprite64x64(player.getPosition(), monster.getPosition())) {// si il y a colision avec le monstre
        if (monster.isAlive()) {//si le monstre est toujours en vie
            player.setDamage(monster.getPower());//le monstre inflige des degats au joueur
            int collide = collidePosition(player.getPosition(), monster.getPosition());// retourne le type de collision

            if (!sword.getExecution()) {
                if (collide == DOWN_COLLIDE && !previewCollide(player.getPosition(), sf::Vector2f(0.f, -64.f)) &&
                    !previewLimitMap(player.getPosition(), sf::Vector2f(0.f, -64.f))) {// colision de haut en bas avec un monstre
                    player.recoilUp();// fait reculer le joueur vers le haut de l'ecran
                }
                else if (collide == UP_COLLIDE && !previewCollide(player.getPosition(), sf::Vector2f(0.f, 64.f)) &&
                    !previewLimitMap(player.getPosition(), sf::Vector2f(0.f, 64.f))) { // colision de bas en haut avec un monstre
                    player.recoilDown();// fait reculer le joueur vers le bas de l'ecran
                }
                else if (collide == RIGHT_COLLIDE &&
                    !previewCollide(player.getPosition(), sf::Vector2f(-64.f, 0.f)) &&
                    !previewLimitMap(player.getPosition(), sf::Vector2f(-64.f, 0.f))) {// colision de gauche à droite
                    player.recoilLeft();// fait reculer le joueur vers la gauche de l'ecran
                }
                else if (collide == LEFT_COLLIDE &&
                    !previewCollide(player.getPosition(), sf::Vector2f(64.f, 0.f)) &&
                    !previewLimitMap(player.getPosition(), sf::Vector2f(64.f, 0.f))) {//colision de droite a gauche
                    player.recoilRight();// fait reculer le joueur vers la droite de l'ecran
                }
            }
        }
        else if (monster.thereGain()) {//check si on a obtenu un gain en tuant le monstre
            //si oui on recupere la recompense
            player.setHeart(monster.getGainLifeValor());
            player.updateRubis(monster.getGainRubisValor());
            monster.gainIsGet();
        }
    }
}

bool Game::collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2) {
    float sprite1x = sprite1.x,
        sprite1y = sprite1.y,

        sprite2x = sprite2.x,
        sprite2y = sprite2.y;

    return (sprite1x + 5 <= sprite2x + SPRITE_SIZE && sprite1x + 59 >= sprite2x &&
        sprite1y + 32 <= sprite2y + SPRITE_SIZE && sprite1y + SPRITE_SIZE > sprite2y);
}

int Game::collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2) {
    //stock les coordones des deux sprites

    float sprite1x = sprite1.x,
        sprite1y = sprite1.y,

        sprite2x = sprite2.x,
        sprite2y = sprite2.y;

    //gestion du type de colision


    if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x && sprite1y < sprite2y + SPRITE_SIZE &&
        sprite1y +  32 > sprite2y) {
        return UP_COLLIDE;
    }
    else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x + SPRITE_SIZE &&
        sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
        return LEFT_COLLIDE;
    }
    else if (sprite1x < sprite2x && sprite1x + SPRITE_SIZE > sprite2x && sprite1y < sprite2y + SPRITE_SIZE &&
        sprite1y + SPRITE_SIZE > sprite2y) {
        return RIGHT_COLLIDE;
    }
    else if (sprite1x < sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE > sprite2x &&
        sprite1y + SPRITE_SIZE > sprite2y && sprite1y + SPRITE_SIZE < sprite2y + SPRITE_SIZE) {
        return DOWN_COLLIDE;
    }
    return NO_COLLIDE;
}

bool Game::collideSword(sf::Vector2f target) {
    //stockage des positions de l'epee et de la cible

    float sprite1x = sword.getPosition().x,
        sprite1y = sword.getPosition().y,

        sprite2x = target.x,
        sprite2y = target.y;

    //gestion du type d'attack pour prevoir le type d'animation plus tard

    if (sword.getAttackDown()) {
        return (sprite1x >= sprite2x && sprite1x - SPRITE_SIZE <= sprite2x + SPRITE_SIZE &&
            sprite1y + SPRITE_SIZE >= sprite2y && sprite1y + SPRITE_SIZE <= sprite2y + SPRITE_SIZE);
    }
    else if (sword.getAttackLeft()) {
        return (sprite1x - SPRITE_SIZE <= sprite2x + SPRITE_SIZE && sprite1x - SPRITE_SIZE >= sprite2x &&
            sprite1y >= sprite2y && sprite1y - SPRITE_SIZE <= sprite2y + SPRITE_SIZE);
    }
    else if (sword.getAttackRight()) {
        return (sprite1x <= sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE >= sprite2x &&
            sprite1y <= sprite2y + SPRITE_SIZE && sprite1y + SPRITE_SIZE > sprite2y);
    }
    else if (sword.getAttackUp()) {
        return (sprite1x + SPRITE_SIZE >= sprite2x && sprite1x <= sprite2x + SPRITE_SIZE &&
            sprite1y - SPRITE_SIZE <= sprite2y + SPRITE_SIZE && sprite1y - SPRITE_SIZE >= sprite2y);
    }
    return false;
}

bool Game::collideWall(sf::Vector2f sprite, std::vector <sf::Vector2f> wall) {
    for (int x = 0; x < wall.size(); x++) {
        if (collideTwoSprite64x64(sprite, wall[x])) {
            return true;
        }
    }
    return false;
}

bool Game::previewCollide(sf::Vector2f user, sf::Vector2f moove) {
    float nextx = user.x + moove.x,
        nexty = user.y + moove.y;

    bool collide = false;

    if (map.hasWall() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), map.getListPositionWall());
    }
    if (map.thereChest() && !collide) {
        collide = collideTwoSprite64x64(sf::Vector2f(nextx, nexty), map.getChestSprite().getPosition());
    }
    return collide;
}

bool Game::previewLimitMap(sf::Vector2f user, sf::Vector2f moove) {
    float nextx = user.x + moove.x,
        nexty = user.y + moove.y;

    if (nextx > LIMIT_RIGHT_GAME || nextx < LIMIT_LEFT_GAME || nexty > LIMIT_DOWN_GAME || nexty < LIMIT_UP_GAME) {
        return true;
    }
    return false;
}