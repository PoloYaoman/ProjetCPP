#include "Game.hpp"
// #include "ControlInterface.hpp"
// #include "DrawInterface.hpp"

Game::Game()/*liste des wall et ground � charger type, greenWall(path) */ {

    setMapUpdate();

}

bool Game::playerIsAlive(Player& player) {
    return player.isAlive();
}


///////////////////////////gestion des colisions///////////////////////////////////////////////////////////////////


void ColisionInterface::collideMonster(Player& player, Monster& monster) {
    if (collideTwoSprite64x64(player.position(), monster.position())) {// si il y a colision avec le monstre
        if (monster.isAlive()) {//si le monstre est toujours en vie
            player.receiveDamage(monster.power());//le monstre inflige des degats au joueur

            //int collide = collidePosition(player.position(), monster.position());// retourne le type de collision

            // if (!sword.getExecution()) {
            //     if (collide == DOWN_COLLIDE && !previewCollide(player.position(), sf::Vector2f(0.f, -64.f)) &&
            //         !previewLimitMap(player.position(), sf::Vector2f(0.f, -64.f))) {// colision de haut en bas avec un monstre
            //         player.recoilUp();// fait reculer le joueur vers le haut de l'ecran
            //     }
            //     else if (collide == UP_COLLIDE && !previewCollide(player.position(), sf::Vector2f(0.f, 64.f)) &&
            //         !previewLimitMap(player.position(), sf::Vector2f(0.f, 64.f))) { // colision de bas en haut avec un monstre
            //         player.recoilDown();// fait reculer le joueur vers le bas de l'ecran
            //     }
            //     else if (collide == RIGHT_COLLIDE &&
            //         !previewCollide(player.position(), sf::Vector2f(-64.f, 0.f)) &&
            //         !previewLimitMap(player.position(), sf::Vector2f(-64.f, 0.f))) {// colision de gauche � droite
            //         player.recoilLeft();// fait reculer le joueur vers la gauche de l'ecran
            //     }
            //     else if (collide == LEFT_COLLIDE &&
            //         !previewCollide(player.position(), sf::Vector2f(64.f, 0.f)) &&
            //         !previewLimitMap(player.position(), sf::Vector2f(64.f, 0.f))) {//colision de droite a gauche
            //         player.recoilRight();// fait reculer le joueur vers la droite de l'ecran
            //     }
            // }
        }
        //else if (monster.thereGain()) {//check si on a obtenu un gain en tuant le monstre
            //si oui on recupere la recompense

            /* Pas d'interet de faire un test ici, s'il y a du loot on le rajoute a celui du joueur et 
            sinon on rajoute zero */

        else {
            player.heal(monster.heartLoot());
            player.updateRubis(monster.rubisLoot());
        }

        //     monster.gainIsGet();
        // }
    }
}

bool ColisionInterface::collideTwoSprite64x64(sf::Vector2f sprite1, sf::Vector2f sprite2) { 
    float sprite1x = sprite1.x,
        sprite1y = sprite1.y,

        sprite2x = sprite2.x,
        sprite2y = sprite2.y;

    return (sprite1x + 5 <= sprite2x + SPRITE_SIZE && sprite1x + 59 >= sprite2x &&
        sprite1y + 32 <= sprite2y + SPRITE_SIZE && sprite1y + SPRITE_SIZE > sprite2y);
}

int ColisionInterface::collidePosition(sf::Vector2f sprite1, sf::Vector2f sprite2) {
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

bool ColisionInterface::collideSword(Character attacker, Character target) {
    //stockage des positions de l'epee et de la cible

    float sprite1x = float(attacker.posx()),
        sprite1y = float(attacker.posy()),

        sprite2x = float(target.posx()),
        sprite2y = float(target.posy());

    //gestion du type d'attack pour prevoir le type d'animation plus tard

    if (attacker.inRange(target.position()) == 'D') {
        return (sprite1x >= sprite2x && sprite1x - SPRITE_SIZE <= sprite2x + SPRITE_SIZE &&
            sprite1y + SPRITE_SIZE >= sprite2y && sprite1y + SPRITE_SIZE <= sprite2y + SPRITE_SIZE);
    }
    else if (attacker.inRange(target.position()) == 'L') {
        return (sprite1x - SPRITE_SIZE <= sprite2x + SPRITE_SIZE && sprite1x - SPRITE_SIZE >= sprite2x &&
            sprite1y >= sprite2y && sprite1y - SPRITE_SIZE <= sprite2y + SPRITE_SIZE);
    }
    else if (attacker.inRange(target.position()) == 'R') {
        return (sprite1x <= sprite2x + SPRITE_SIZE && sprite1x + SPRITE_SIZE >= sprite2x &&
            sprite1y <= sprite2y + SPRITE_SIZE && sprite1y + SPRITE_SIZE > sprite2y);
    }
    else if (attacker.inRange(target.position()) == 'U') {
        return (sprite1x + SPRITE_SIZE >= sprite2x && sprite1x <= sprite2x + SPRITE_SIZE &&
            sprite1y - SPRITE_SIZE <= sprite2y + SPRITE_SIZE && sprite1y - SPRITE_SIZE >= sprite2y);
    }
    return false;
}

bool ColisionInterface::collideWall(sf::Vector2f sprite, std::vector <sf::Vector2f> wall) {
    for (int x = 0; x < wall.size(); x++) {
        if (collideTwoSprite64x64(sprite, wall[x])) {
            return true;
        }
    }
    return false;
}

bool ColisionInterface::previewCollide(sf::Vector2f user, sf::Vector2f moove) {
    float nextx = user.x + moove.x,
        nexty = user.y + moove.y;

    bool collide = false;

    if (map.hasWall() && !collide) {
        collide = collideWall(sf::Vector2f(nextx, nexty), map.getListPositionWall());
    }
    if (map.thereChest() && !collide) {
        collide = collideTwoSprite64x64(sf::Vector2f(nextx, nexty), map.getChestSprite().position());
    }
    return collide;
}

bool ColisionInterface::previewLimitMap(sf::Vector2f user, sf::Vector2f moove) {
    float nextx = user.x + moove.x,
        nexty = user.y + moove.y;

    if (nextx > LIMIT_RIGHT_GAME || nextx < LIMIT_LEFT_GAME || nexty > LIMIT_DOWN_GAME || nexty < LIMIT_UP_GAME) {
        return true;
    }
    return false;
}

/////////////////////////////////////execution des evenements///////////////////////////////////////////////

void ControlInterface::executionGame(void) {
    allDrawWindow();
    moveMonster();
    switchMap();
    swordAttack();
    collideMonster();
    gainChest();
    if (player.isInvulnerable()) {
        player.frameInvulnerable();
    }
    if (monster.isInvulnerable()) {
        monster.frameInvulnerable();
    }
}

void ControlInterface::key(const char* key) {
    switch (*key) {

    case 'D':
        if (!sword.getExecution()) { // si l'ep�e n'est pas en mouvement
            if (!previewCollide(player.position(), sf::Vector2f(0.f, player.getSpeed() * 1.f))) {// Si le joeur ne va pas rencontrer un obstacle en descendant de une unit�
                player.animationMoveDown();// alors le joeur bouge vers le bas
            }
            if (!player.getOrientationDown()) {// si le joeur n'a pas son orientation dans le sens du mouvement , alors on lui done
                player.setOrientationDown();
            }
        }
        break;

    case 'L':

        if (!sword.getExecution()) {
            if (!previewCollide(player.position(), sf::Vector2f(player.getSpeed() * -1.f, 0.f))) {
                player.animationMoveLeft();
            }
            if (!player.getOrientationLeft()) {
                player.setOrientationLeft();
            }
        }
        break;

    case 'R':

        if (!sword.getExecution()) {
            if (!previewCollide(player.position(), sf::Vector2f(player.getSpeed() * 1.f, 0.f))) {
                player.animationMoveRight();
            }
            if (!player.getOrientationRight()) {
                player.setOrientationRight();
            }
        }
        break;

    case 'U':

        if (!sword.getExecution()) {
            if (!previewCollide(player.position(), sf::Vector2f(0.f, player.getSpeed() * -1.f))) {
                player.animationMoveUp();
            }
            if (!player.getOrientationUp()) {
                player.setOrientationUp();
            }
        }
        break;
    
    case 'S':

        if (!sword.getExecution()) {

            // on met � true l'orientation de l'ep�e corresoondante � l'orientation du joeur

            sword.setOrientationUp(player.getOrientationUp());
            sword.setOrientationDown(player.getOrientationDown());
            sword.setOrientationRight(player.getOrientationRight());
            sword.setOrientationLeft(player.getOrientationLeft());

            // On met en mouvement l'epee

            sword.startAnimation(player.positionSword(), player.getOrientationValue());

        }

    default:
        std::cout << " Erreur dans la variable de la fonction  Game::key(key)" << std::endl;

    }
}


////////////////////////////////////////methode draw///////////////////////////////////////////////

//getteur

std::vector <sf::Sprite> DrawInterface::getDrawingSprite(void) const {
    return vectorSprite;
}

std::vector <sf::Text> DrawInterface::getDrawingText(void) const {
    return vectorText;
}

//autre methode


void DrawInterface::allDrawWindow(void) {
    vectorSprite.clear();
    vectorText.clear();

    // Up screen
    extractSpriteFromVector(player.getListSpriteHeart()); // Life bar
    drawRubis(); // Rubis number

    // Element Immobile
    drawMap(); // Map
    //drawChest(); // Chest
    //drawChestGain();

    // Element Mobile
    m_vectorsprite.push_back(m_Mob1.getSprite()); // Monster
    m_vectorsprite.push_back(m_Player.getSprite()); // Player

    // Over all
    drawSword(); // Sword
}

void DrawInterface::drawChestGain(void) {
    m_vectorsprite.push_back(m_Map.getGainSprite());
}

void DrawInterface::drawChest(void) {
    if (m_Map.thereChest()) {
        m_vectorsprite.push_back(m_Map.getChestSprite());
    }
}

void DrawInterface::drawSword(void) {
    if (m_Sword.getExecution()) {
        m_Sword.animateAttack();
        m_vectorsprite.push_back(m_Sword.getSprite());
    }
}

void DrawInterface::drawRubis(void) {
    m_vectorsprite.push_back(m_Player.getLogoRubis());
    m_vectortext.push_back(m_Player.getRubisHundred());
    m_vectortext.push_back(m_Player.getRubisTen());
    m_vectortext.push_back(m_Player.getRubisUnit());
}

void DrawInterface::drawMap(void) {
    extractSpriteFromVector(m_Bloc.getListSprite());
    extractSpriteFromVector(m_Cavern.getListSprite());
    extractSpriteFromVector(m_Tree.getListSprite());
    extractSpriteFromVector(m_Ground.getListSprite());
    extractSpriteFromVector(m_OrangeTree.getListSprite());
    extractSpriteFromVector(m_Water.getListSprite());
    extractSpriteFromVector(m_WhiteTree.getListSprite());
    extractSpriteFromVector(m_Bridge.getListSprite());
    extractSpriteFromVector(m_GreyGround.getListSprite());
    extractSpriteFromVector(m_Rock.getListSprite());
    extractSpriteFromVector(m_RedRock.getListSprite());
    extractSpriteFromVector(m_WhiteRock.getListSprite());
}

void DrawInterface::extractSpriteFromVector(std::vector <sf::Sprite> vector) {
    for (int number = 0; number < vector.size(); number++) {
        m_vectorsprite.push_back(vector[number]);
    }
}


/////////////MAP////////////////////


void Game::setMapUpdate(void) {
    map.generateMap();
    setBackground(); // met en place le decor
    makeListMonster(); //
}

void Game::switchMap(void) {
    if (player.position().x < 0) {
        map.setMapLeft();
        setMapUpdate();
        player.setPositionLeft();
    }
    else if (player.position().x > 1024) {
        map.setMapRight();
        setMapUpdate();
        player.setPositionRight();
    }
    else if (player.position().y < 64) {
        map.setMapUp();
        setMapUpdate();
        player.setPositionUp();
    }
    else if (player.position().y > 768) {
        map.setMapDown();
        setMapUpdate();
        player.setPositionDown();
    }
}

void Game::setBackground(void) {

    classicTree.setPositionVector(map.getListPosition(*classicTree_c)); // getListPosition renvoie un veceur de veteur2f ( vecteur de position ) , dont la cl� dans HashMap est le const char*  "classicTree_c"  ensuite setPositionVector met sur la map tout les arbres necessaire au positions adequates
    classicRock.setPositionVector(map.getListPosition(*classicRock_c));
    classicGrass.setPositionVector(map.getListPosition(*classicGrass_c));
}

void Game::gainChest(void) {
    if (collideTwoSprite64x64(player.position(), map.getGainSprite().position())) {
        player.setHeart(map.getGainLife());
        player.updateRubis(map.getGainRubis());
        map.gainIsGet();
    }
}

/////////////// sword ////////////////

void Game::swordAttack(void) {
    if (sword.getExecution()) {
        if (collideSword(monster.position()) && monster.isAlive()) {
            sword.setDamage(sword.getPower());
            if (monster.isAlive()) {
                if (player.getOrientationDown() && !previewCollide(monster.position(), sf::Vector2f(0.f, 64.f))) {
                    monster.recoilDown();
                }
                else if (player.getOrientationUp() &&
                    !previewCollide(monster.position(), sf::Vector2f(0.f, -64.f))) {
                    monster.recoilUp();
                }
                else if (player.getOrientationRight() &&
                    !previewCollide(monster.position(), sf::Vector2f(64.f, 0.f))) {
                    monster.recoilRight();
                }
                else if (player.getOrientationLeft() &&
                    !previewCollide(monster.position(), sf::Vector2f(-64.f, 0.f))) {
                    monster.recoilLeft();
                }
            }
            //monsterReceveAttack(x);
        }
        else if (collideSword(map.getChestSprite().position())) {
            map.oprenChest();
        }
    }
}

void Game::monsterReceveAttack(int mob) {
    listMonster[mob].setDamage(sword.getPower());
    if (listMonster[mob].isAlive()) {
        if (player.getOrientationDown() && !previewCollide(listMonster[mob].position(), sf::Vector2f(0.f, 64.f))) {
            listMonster[mob].recoilDown();
        }
        else if (player.getOrientationUp() &&
            !previewCollide(listMonster[mob].position(), sf::Vector2f(0.f, -64.f))) {
            listMonster[mob].recoilUp();
        }
        else if (player.getOrientationRight() &&
            !previewCollide(listMonster[mob].position(), sf::Vector2f(64.f, 0.f))) {
            listMonster[mob].recoilRight();
        }
        else if (player.getOrientationLeft() &&
            !previewCollide(listMonster[mob].position(), sf::Vector2f(-64.f, 0.f))) {
            listMonster[mob].recoilLeft();
        }
    }
}


//////////////monster//////////////

void Game::moveMonster(void) {
    monster.nextPosition();
    if (!previewCollide(monster.position(), monster.getNextPosition()) && monster.isAlive() &&
        !previewLimitMap(monster.position(), monster.getNextPosition())) {
        monster.move();
    }
}

void Game::makeListMonster(void) {
    listMonster.clear();
    listMonster.push_back(monster);
}