#pragma once

#include "Board.hpp"
#include "Chaser.hpp" //../enemies/
#include "Coward.hpp"
#include "Drunk.hpp"
#include "Shooter.hpp"
#include "Boom.hpp"
#include "Artifact.hpp"
#include "Flyer.hpp"
#include "Stalker.hpp"
#include "Turret.hpp"
#include "Door.hpp"
#include "Wall.hpp"

#include <cstdlib>

#define HALF_COLS BOARD_COLS / 2
#define HALF_ROWS BOARD_ROWS / 2
const int n_enemies = 4;
const int max_n_enemies = 6;
const int n_artifact = 5;
const int tols = 6;
const int drop_chance = 3;

class General_template
{
public:
    Drawable *walls;
    Drawable *doors;
    Drawable *artifact;
    pEn *enemies;
    int walls_num;
    int doors_num;
    int enemies_num = 0;
    int artifact_num = 1;
    int my_xp = 3;
    bool is_north_door_locked, is_south_door_locked, is_west_door_locked, is_est_door_locked;
    bool need_doors;
    bool has_north_door, has_south_door, has_west_door, has_est_door;
    bool must_complete = true;
    General_template();
    General_template(int w, int d, int e, int a);
    ~General_template();

    void drawDoors();

    // in chosen enemies 0=drunk,1=coward,2=shooter,3=chaser,4=boom,5=flyer,6=stalker,7=turret
    void createEnemies(bool is_random_enemies, bool is_random_coords, int x, int y, int chosen, int ite, int room_pos, Board &game_board, pEn enemies[]);

    // in chosen artifact 0=R,1=E,2=H,3=J
    void createArtifact(bool is_random_artifact, bool is_random_coords, int x, int y, int chosen, int ite, Board &game_board, int room_pos, Drawable *artifact);
    int drawRandom(int num, int ya, int xa, int yb, int xb, int i);
    int drawHorizontalLine(int num, int start_y, int start_x, int i);
    int drawVerticalLine(int num, int start_y, int start_x, int i);
    int drawFilledSquare(int start_y, int start_x, int height, int width, int i);
    int drawEmptySquare(int start_y, int start_x, int height, int width, int i);
    int drawOrtogonalCross(int start_y, int start_x, int h_height, int h_width, int i);

    int drawFilledSquareDoor(int start_y, int start_x, int height, int width, int i);
    int drawFilledSquareLockedDoor(int start_y, int start_x, int height, int width, int i);
    int drawFilledSquareNoDoor(int start_y, int start_x, int height, int width, int i);
    int checkHeroProjectile(Board &board_win, Hero &hero);
};