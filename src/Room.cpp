#include "Room.hpp"

int locked_door_num = 0;

/* Costruttore di default, usato solo per la stanza di partenza */
Room::Room(Board &game_board)
{
    this->y = 0;
    this->x = 0;
    this->has_north_door = true;
    this->has_south_door = true;
    this->has_west_door = true;
    this->has_est_door = true;
    this->north = NULL;
    this->south = NULL;
    this->west = NULL;
    this->est = NULL;
    this->room_template_number = 0;
    initializeRoomTemplate(0, 0, game_board);
}

/* Costruttore per le stanze, inizializza il template, le porte chiuse tra quelle presenti
 *  e la collega a quelle vicine */
Room::Room(int y, int x, vector<Room *> room_index, int room_pos, Board &game_board)
{
    this->y = y;
    this->x = x;
    int num = randomRoomNumber();
    this->room_template_number = num;
    initializeRoomTemplate(num, room_pos, game_board);
    decideIfDoors();
    this->north = findRoom(room_index, y + 1, x, up);
    this->south = findRoom(room_index, y - 1, x, down);
    this->west = findRoom(room_index, y, x - 1, sx);
    this->est = findRoom(room_index, y, x + 1, dx);
    lockDoor(room_index.size());
}

/* Aggiunge le componenti della stanza allo schermo */
void Room::drawRoom(Board &board)
{
    drawArtifact(board);
    drawProjectiles(board);
    board.addBorder();
    drawWalls(board);
    drawDoors(board);
    drawEnemies(board);
}

/* Muove i nemici */
void Room::moveEnemies(Board &board, Hero &hero)
{
    for (int i = 0; i < room_template->enemies_num; i++)
    {
        if (room_template->enemies[i] != NULL)
        {
            this->room_template->enemies[i]->chooseDirection(board, hero);
            this->room_template->enemies[i]->checkProjectile(board, hero);
            if (this->room_template->enemies[i]->getisFlyer())
            {
                if (this->room_template->enemies[i]->checkFlyerCollision(board))
                {
                    this->room_template->enemies[i]->moveCharacter(board);
                }
            }
            else
            {
                if (this->room_template->enemies[i]->checkCollision(board))
                {
                    this->room_template->enemies[i]->moveCharacter(board);
                }
            }
        }
    }
}

int Room::checkEnemiesHp(Board &board_win)
{
    int killed = 0;

    for (int j = 0; j < room_template->enemies_num; j++)
    {
        if (this->room_template->enemies[j]->getHp() <= 0)
        {
            board_win.addAt(this->room_template->enemies[j]->gety(), this->room_template->enemies[j]->getx(), ' ');
            if (this->room_template->enemies[j]->isBoss())
            {
                int k = 0;
                while (this->room_template->artifact[k].getIcon() != 0)
                {
                    k++;
                }
                k++;
                this->room_template->artifact[k] = Artifact(this->room_template->enemies[j]->gety(), this->room_template->enemies[j]->getx());
            }
            else
            {
                if (this->room_template->enemies[j]->getIcon() == 'K')
                {
                    if ((rand() % drop_chance) == 0)
                    {
                        int k = 0;
                        while (this->room_template->artifact[k].getIcon() != 0)
                        {
                            k++;
                        }
                        k++;
                        this->room_template->artifact[k] = Artifact(this->room_template->enemies[j]->gety(), this->room_template->enemies[j]->getx());
                    }
                }
            }
            removeEnemy(j, board_win);
            killed++;
        }
    }
    return killed;
}

void Room::checkHeroProjectile(Board &board_win, Hero &hero)
{
    for (int i = 0; i < hero.projectile.size(); i++)
    {

        if (hero.projectile[i] != NULL)
        {
            hero.projectile[i]->setUptime(hero.projectile[i]->getUptime() + 1);
            if (!hero.projectile[i]->checkProjectileCollision(board_win) || hero.projectile[i]->getUptime() > hero.getRange())
            {
                hero.projectile[i]->moveCharacter(board_win);
                bool found = false;
                int j = 0;
                while (j < this->room_template->enemies_num && !found)
                {
                    if (this->room_template->enemies[j] != NULL)
                    {
                        if (hero.projectile[i]->getx() == this->room_template->enemies[j]->getx() && hero.projectile[i]->gety() == this->room_template->enemies[j]->gety())
                        {
                            this->room_template->enemies[j]->reduceHealth(hero.getDmg());
                            hero.projectile.erase(hero.projectile.begin() + i);
                            found = true;
                        }
                    }
                    j++;
                }
                if (!found)
                {
                    board_win.addAt(hero.projectile[i]->gety(), hero.projectile[i]->getx(), ' ');
                    hero.projectile.erase(hero.projectile.begin() + i);
                }
            }
            else
            {
                hero.projectile[i]->moveCharacter(board_win);
            }
        }
    }
}

/* Verifica che la stanza non abbia altri nemici */
bool Room::isClear()
{
    if (room_template->must_complete)
        return room_template->enemies_num == 0; // per il testing è disattivata
    else
        return 1;
}

/* Sblocca la porta nella direzione in cui si punta */
void Room::unlockDoor(int y, int x, Board &game_board)
{
    int j = 0;
    bool f = true;
    while (f)
    {
        f = false;
        for (int i = 0; i < room_template->doors_num; i++)
        {
            int ty = room_template->doors[i].gety();
            int tx = room_template->doors[i].getx();
            if ((ty == y - j || ty == y + j || ty == y) && (tx == x - j || tx == x + j || tx == x))
            {
                if (room_template->doors[i].getIcon() == 'Q')
                {
                    f = true;
                    room_template->doors[i] = Door(ty, tx);
                    game_board.addAt(ty, tx, 'O');
                }
            }
        }
        j++;
    }
}

/* rimove il nemico in posizione i*/
void Room::removeEnemy(int pos, Board &board_win)
{
    for (int i = 0; i < room_template->enemies[pos]->projectile.size(); i++)
    {
        board_win.addAt(room_template->enemies[pos]->projectile[i]->gety(), room_template->enemies[pos]->projectile[i]->getx(), ' ');
        room_template->enemies[pos]->projectile.erase(room_template->enemies[pos]->projectile.begin() + i);
    }
    pEn temp = room_template->enemies[pos];
    room_template->enemies[pos] = room_template->enemies[room_template->enemies_num - 1];
    room_template->enemies[room_template->enemies_num - 1] = temp;

    room_template->enemies_num--;
}

/* rimove l'artefatto in posizione i*/
void Room::removeArtifact(int pos)
{
    Drawable temp = room_template->artifact[pos];
    room_template->artifact[pos] = room_template->artifact[room_template->artifact_num - 1];
    room_template->artifact[room_template->artifact_num - 1] = temp;
    room_template->artifact_num--;
}

/* ritorna la coordinata y della stanza*/
int Room::gety()
{
    return this->y;
}
/* ritorna la coordinata y della stanza*/
int Room::getx()
{
    return this->x;
}

/* ritorna il puntatore alla stanza a nord*/
prm Room::getNorth()
{
    return this->north;
}
/* ritorna il puntatore alla stanza a sud*/
prm Room::getSouth()
{
    return this->south;
}
/* ritorna il puntatore alla stanza a ovest*/
prm Room::getWest()
{
    return this->west;
}
/* ritorna il puntatore alla stanza a est*/
prm Room::getEst()
{
    return this->est;
}

/* modifica il puntatore alla stanza a nord*/
void Room::setNorth(prm p)
{
    this->north = p;
}
/* modifica il puntatore alla stanza a sud*/
void Room::setSouth(prm p)
{
    this->south = p;
}
/* modifica il puntatore alla stanza a ovest*/
void Room::setWest(prm p)
{
    this->west = p;
}
/* modifica il puntatore alla stanza a est*/
void Room::setEst(prm p)
{
    this->est = p;
}

// funzioni private

/* Funzione usata per trovare le stanze da collegare a quella corrente, in base alle porte disponibili */
Room *Room::findRoom(vector<Room *> room_index, int y, int x, Direction dir)
{
    int n = -1;
    for (int i = 0; i < room_index.size(); i++)
    {
        if (room_index[i]->y == y && room_index[i]->x == x)
        {
            n = i;
            break;
        }
    }
    if (n < 0)
        return NULL;
    else
    {
        switch (dir)
        {
        case up:
            if (!room_index[n]->has_south_door)
                this->has_north_door = false;
            else
                this->has_north_door = true;
            break;
        case down:
            if (!room_index[n]->has_north_door)
                this->has_south_door = false;
            else
                this->has_south_door = true;
            break;
        case sx:
            if (!room_index[n]->has_est_door)
                this->has_west_door = false;
            else
                this->has_west_door = true;
            break;
        case dx:
            if (!room_index[n]->has_west_door)
                this->has_est_door = false;
            else
                this->has_est_door = true;
            break;
        }
        return room_index[n];
    }
}

/* Genera il numero di un template, in base alla loro rarità */
int Room::randomRoomNumber()
{
    int prob[2][NUMBER_OF_ROOMS] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40}, // numero del tempate
                                    {0, 1, 8, 8, 8, 8, 8, 10,10, 8,  3,  2,  6,  4,  4,  7, 0 ,  0,  7,  8, 0,  5,  0,  0,  0,  0,  1,  8,  0, 10, 10, 10, 10, 10, 10, 10,  1,  1,  6,  3}};                   // rarità (5 comune, 1 rara)
    int parts = 0;
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        parts += prob[1][i];
    }
    int n = rand() % parts + 1;
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        n -= prob[1][i];
        if (n <= 0)
            return prob[0][i];
    }
    return -1;
}

/* Inizializza il template con il numero indicato */
void Room::initializeRoomTemplate(int template_num, int room_pos, Board &game_board)
{

    switch (template_num)
    {
    case 0:
        this->room_template = new Template_0(room_pos, game_board);
        break;
    case 1:
        this->room_template = new Template_1(room_pos, game_board);
        break;
    case 2:
        this->room_template = new Template_2(room_pos, game_board);
        break;
    case 3:
        this->room_template = new Template_3(room_pos, game_board);
        break;
    case 4:
        this->room_template = new Template_4(room_pos, game_board);
        break;
    case 5:
        this->room_template = new Template_5(room_pos, game_board);
        break;
    case 6:
        this->room_template = new Template_6(room_pos, game_board);
        break;
    case 7:
        this->room_template = new Template_7(room_pos, game_board);
        break;
    case 8:
        this->room_template = new Template_8(room_pos, game_board);
        break;
    case 9:
        this->room_template = new Template_9(room_pos, game_board);
        break;
    case 10:
        this->room_template = new Template_10(room_pos, game_board);
        break;
    case 11:
        this->room_template = new Template_11(room_pos, game_board);
        break;
    case 12:
        this->room_template = new Template_12(room_pos, game_board);
        break;
    case 13:
        this->room_template = new Template_13(room_pos, game_board);
        break;
    case 14:
        this->room_template = new Template_14(room_pos, game_board);
        break;
    case 15:
        this->room_template = new Template_15(room_pos, game_board);
        break;
    case 16:
        this->room_template = new Template_16(room_pos, game_board);
        break;
    case 17:
        this->room_template = new Template_17(room_pos, game_board);
        break;
    case 18:
        this->room_template = new Template_18(room_pos, game_board);
        break;
    case 19:
        this->room_template = new Template_19(room_pos, game_board);
        break;
    case 20:
        this->room_template = new Template_20(room_pos, game_board);
        break;
    case 21:
        this->room_template = new Template_21(room_pos, game_board);
        break;
    case 22:
        this->room_template = new Template_22(room_pos, game_board);
        break;
    case 23:
        this->room_template = new Template_23(room_pos, game_board);
        break;
    case 24:
        this->room_template = new Template_24(room_pos, game_board);
        break;
    case 25:
        this->room_template = new Template_25(room_pos, game_board);
        break;
    case 26:
        this->room_template = new Template_26(room_pos, game_board);
        break;
    case 27:
        this->room_template = new Template_27(room_pos, game_board);
        break;
    case 28:
        this->room_template = new Template_28(room_pos, game_board);
        break;
    case 29:
        this->room_template = new Template_29(room_pos, game_board);
        break;
    case 30:
        this->room_template = new Template_30(room_pos, game_board);
        break;
    case 31:
        this->room_template = new Template_31(room_pos, game_board);
        break;
    case 32:
        this->room_template = new Template_32(room_pos, game_board);
        break;
    case 33:
        this->room_template = new Template_33(room_pos, game_board);
        break;
    case 34:
        this->room_template = new Template_34(room_pos, game_board);
        break;
    case 35:
        this->room_template = new Template_35(room_pos, game_board);
        break;
    case 36:
        this->room_template = new Template_36(room_pos, game_board);
        break;
    case 37:
        this->room_template = new Template_37(room_pos, game_board);
        break;
    case 38:
        this->room_template = new Template_38(room_pos, game_board);
        break;
    case 39:
        this->room_template = new Template_39(room_pos, game_board);
        break;
    case 40:
        this->room_template = new Template_40(room_pos, game_board);
        break;
    default:
        this->room_template = new Template_0(room_pos, game_board);
        break;
    }
}

/* Sceglie quali porte tenere/togliere, anche in base al template */
void Room::decideIfDoors()
{
    if (room_template->need_doors)
    {
        this->has_north_door = room_template->has_north_door;
        this->has_south_door = room_template->has_south_door;
        this->has_west_door = room_template->has_west_door;
        this->has_est_door = room_template->has_est_door;
    }
    else
    {
        this->has_north_door = true;
        this->has_south_door = true;
        this->has_west_door = true;
        this->has_est_door = true;

        int r = rand() % 9 - 5; // minore è il primo numero maggiore è la possibilità di non avere porte, il secondo è il primo -4
        for (int i = 0; i < r; i++)
        {
            switch (rand() % 4)
            {
            case 0:
                this->has_north_door = false;
                break;
            case 1:
                this->has_south_door = false;
                break;
            case 2:
                this->has_west_door = false;
                break;
            case 3:
                this->has_est_door = false;
                break;
            default:
                break;
            }
        }
    }
}

/* Sceglie quali porte bloccare, facendo in modo che non siano troppe da intrappolare il giocatore */
void Room::lockDoor(int n)
{
    if (locked_door_num + 1 < (n / 4))
    {
        int r = rand() % 4;
        switch (r)
        {
        case 0:
            if (has_north_door)
                north_door_locked = true;
            lockNorthDoor();
            locked_door_num++;
            break;
        case 1:
            if (has_south_door)
                south_door_locked = true;
            lockSouthDoor();
            locked_door_num++;
            break;
        case 2:
            if (has_west_door)
                west_door_locked = true;
            lockWestDoor();
            locked_door_num++;
            break;
        case 3:
            if (has_est_door)
                est_door_locked = true;
            lockEstDoor();
            locked_door_num++;
            break;
        }
    }
}

void Room::lockNorthDoor()
{
    this->room_template->is_north_door_locked = true;
    this->room_template->doors[0] = Locked_Door(0, HALF_COLS - 2);
    this->room_template->doors[1] = Locked_Door(0, HALF_COLS - 1);
    this->room_template->doors[2] = Locked_Door(0, HALF_COLS);
    this->room_template->doors[3] = Locked_Door(0, HALF_COLS + 1);
    this->room_template->doors[4] = Locked_Door(0, HALF_COLS + 2);
}
void Room::lockSouthDoor()
{
    this->room_template->is_south_door_locked = true;
    this->room_template->doors[5] = Locked_Door(BOARD_ROWS - 1, HALF_COLS - 2);
    this->room_template->doors[6] = Locked_Door(BOARD_ROWS - 1, HALF_COLS - 1);
    this->room_template->doors[7] = Locked_Door(BOARD_ROWS - 1, HALF_COLS);
    this->room_template->doors[8] = Locked_Door(BOARD_ROWS - 1, HALF_COLS + 1);
    this->room_template->doors[9] = Locked_Door(BOARD_ROWS - 1, HALF_COLS + 2);
}
void Room::lockWestDoor()
{
    this->room_template->is_west_door_locked = true;
    this->room_template->doors[10] = Locked_Door(HALF_ROWS - 1, 0);
    this->room_template->doors[11] = Locked_Door(HALF_ROWS, 0);
    this->room_template->doors[12] = Locked_Door(HALF_ROWS + 1, 0);
}
void Room::lockEstDoor()
{
    this->room_template->is_est_door_locked = true;
    this->room_template->doors[13] = Locked_Door(HALF_ROWS - 1, BOARD_COLS - 1);
    this->room_template->doors[14] = Locked_Door(HALF_ROWS, BOARD_COLS - 1);
    this->room_template->doors[15] = Locked_Door(HALF_ROWS + 1, BOARD_COLS - 1);
}

// funzioni private

void Room::drawProjectiles(Board &board)
{
    for (int j = 0; j < room_template->enemies_num; j++)
    {
        for (int i = 0; i < room_template->enemies[j]->projectile.size(); i++)
        {
            board.add(*room_template->enemies[j]->projectile[i]);
        }
    }
}

void Room::drawEnemies(Board &board)
{
    for (int i = 0; i < room_template->enemies_num; i++)
    {
        if (room_template->enemies[i] != NULL)
        {
            if (room_template->enemies[i]->isBoss())
                board.add_B(*room_template->enemies[i]);
            else
                board.add_E(*room_template->enemies[i]);
        }
    }
}

void Room::drawArtifact(Board &board)
{
    for (int i = 0; i < room_template->artifact_num; i++)
    {
        board.add_A(room_template->artifact[i]);
    }
}

void Room::drawWalls(Board &board)
{
    for (int i = 0; i < room_template->walls_num; i++)
    {
        board.add(room_template->walls[i]);
    }
}

/* Le porte che collegano le stanze sono indicizzate da 0 a 15 in ordine di direzione*/
void Room::drawDoors(Board &board)
{
    if (has_north_door)
    {
        for (int i = 0; i < 5; i++)
        {
            board.add_D(room_template->doors[i]);
        }
    }
    if (has_south_door)
    {
        for (int i = 5; i < 10; i++)
        {
            board.add_D(room_template->doors[i]);
        }
    }
    if (has_west_door)
    {
        for (int i = 10; i < 13; i++)
        {
            board.add_D(room_template->doors[i]);
        }
    }
    if (has_est_door)
    {
        for (int i = 13; i < 16; i++)
        {
            board.add_D(room_template->doors[i]);
        }
    }
    if (room_template->doors_num > 16)
    {
        for (int i = 16; i < room_template->doors_num; i++)
        {
            board.add_D(room_template->doors[i]);
        }
    }
}

/* aggiunge un nemico in ultima posizione */
void Room::addEnemy(pEn enemy)
{
    room_template->enemies_num++;
    room_template->enemies[room_template->enemies_num - 1] = enemy;
}
