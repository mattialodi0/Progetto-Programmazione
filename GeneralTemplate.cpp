#include "GeneralTemplate.hpp"

General_template::General_template() {}

General_template::General_template(int w, int d, int e, int a)
{
    this->walls_num = w; 
    this->doors_num = d;
    this->enemies_num = e;
    this->artifact_num = a;
    walls = new Drawable[walls_num];
    doors = new Drawable[doors_num];
    enemies = new pEn[enemies_num];
    artifact = new Drawable[artifact_num];
}

General_template::~General_template() 
{
    delete [] walls;
    delete [] doors;
    delete [] enemies;
    delete [] artifact;
}

void General_template::createEnemies(bool is_random_enemies,bool is_random_coords,int x, int y,int chosen,int ite,int room_pos,Board &game_board,pEn enemies[])
{
            if(is_random_enemies){
                chosen=rand()%(max_n_enemies+1);
            }
            if(is_random_coords)
            {
                bool acceptable=false;
            do{
                if(room_pos!=0){
            game_board.getEmptyCoordinates(y,x);
            
                }
                else{
                    x=30;
                    y=5+(2*ite);
                }

                if(!game_board.getTaken(x,y)){
            switch(room_pos){
                case(1):
                if(abs(x-HALF_COLS)>tols || y>tols){
                acceptable=true;
                }
                break;
                case(-1):
                if(abs(x-HALF_COLS)>tols || y<BOARD_ROWS-tols){
                acceptable=true;
                }
                break;
                case(2):
                if(x<BOARD_COLS-tols || abs(y-HALF_ROWS)>tols){
                acceptable=true;
                }
                break;
                case(-2):
                if(x>tols || abs(y-HALF_ROWS)>tols){
                acceptable=true;
                }
                break;
                case(0):
                if(abs(x-HALF_COLS)>tols || abs(y-HALF_ROWS)>tols){
                acceptable=true;
                }
                break;
                default:
                acceptable=false;
                break;

            }
}
            }
            while(!acceptable&&room_pos!=0);
            }
            game_board.setTaken(x,y,true);
                    switch(chosen)
                    {
                        case 0:
                        enemies[ite] = new Drunk(y,x,game_board.getDifficulty());
                        break;
                        case 1:
                        enemies[ite] = new Coward(y,x,game_board.getDifficulty());
                        break;
                        case 2:
                        enemies[ite] = new Shooter(y,x,game_board.getDifficulty());
                        break;
                        case 3:
                        enemies[ite] = new Chaser(y,x,game_board.getDifficulty());
                        break;
                        case 4:
                        enemies[ite] = new Boom(y,x,game_board.getDifficulty());
                        break;
                        case 5:
                        enemies[ite] = new Flyer(y,x,game_board.getDifficulty());
                        break;
                        case 6:
                        enemies[ite] = new Stalker(y,x,game_board.getDifficulty());
                        break;
                    }
                }

void General_template::drawDoors()
{
    doors[0] = Door(0,HALF_COLS-2);   //north doors
    doors[1] = Door(0,HALF_COLS-1);
    doors[2] = Door(0,HALF_COLS);
    doors[3] = Door(0,HALF_COLS+1);
    doors[4] = Door(0,HALF_COLS+2);
    doors[5] = Door(BOARD_ROWS-1,HALF_COLS-2);   //south doors
    doors[6] = Door(BOARD_ROWS-1,HALF_COLS-1);
    doors[7] = Door(BOARD_ROWS-1,HALF_COLS);
    doors[8] = Door(BOARD_ROWS-1,HALF_COLS+1);
    doors[9] = Door(BOARD_ROWS-1,HALF_COLS+2);
    doors[10] = Door(HALF_ROWS-1,0);   //west doors
    doors[11] = Door(HALF_ROWS,0);
    doors[12] = Door(HALF_ROWS+1,0);
    doors[13] = Door(HALF_ROWS-1,BOARD_COLS-1);   //est doors
    doors[14] = Door(HALF_ROWS,BOARD_COLS-1);
    doors[15] = Door(HALF_ROWS+1,BOARD_COLS-1);
}

//funzioni per disegnare set di muri
//assumiamo che lo si possa sempre fare, cioè che non sbattano con pareti ecc

/*a,b,c,d sono i verici dell area in cui diseganre gli n muri*/
int General_template::drawRandom(int num, int ya, int xa, int yb, int xb, int i)
{
    //this->walls_num += num;
    for(int j=0; j < num; j++)
    {
        int y,x;
        y = rand()%(yb-ya)+ya;
        x = rand()%(xb-xa)+xa;
        walls[i] = Wall(y, x); i++;
    }
    return i;
}

int General_template::drawHorizontalLine(int num, int start_y, int start_x, int i)
{
    //this->walls_num += num;
    for(int j=0; j < num; j++)
    {
        walls[i] = Wall(start_y, start_x+j); i++;
    }
    return i;
}

int General_template::drawVerticalLine( int num, int start_y, int start_x, int i)
{
    //this->walls_num += num;
    for(int j=0; j < num; j++)
    {
        walls[i] = Wall(start_y+j, start_x); i++;
    }
    return i;
}

int General_template::drawFilledSquare(int start_y, int start_x, int height, int width, int i) 
{
    //this->walls_num += heigth*widht;
    for(int j=0; j < height; j++)
    {
        for(int k=0; k < width; k++)
        {
            walls[i] = Wall(start_y+j, start_x+k); i++;
        }
    }
    return i;
}

int General_template::drawEmptySquare(int start_y, int start_x, int height, int width, int i) 
{
    //this->walls_num += 2*(heigth+widht)-1;
    for(int j=0; j < width; j++)
    {
        walls[i] = Wall(start_y, start_x+j); i++;
        walls[i] = Wall(start_y+height-1, start_x+j); i++;
    }
    for(int j=1; j < height-1; j++)
    {
        walls[i] = Wall(start_y+j, start_x); i++;
        walls[i] = Wall(start_y+j, start_x+width-1); i++;
    }
    return i;
}

int General_template::drawOrtogonalCross(int start_y, int start_x, int h_height, int h_width, int i) 
{
    //this->walls_num += (1+2*h_height+2*h_width);
    walls[i] = Wall(start_y, start_x); i++;
    for(int j=1; j <= h_height; j++)
    {
        walls[i] = Wall(start_y+j, start_x); i++;
        walls[i] = Wall(start_y-j, start_x); i++;
    }
    for(int k=1; k <= h_width; k++)
    {
        walls[i] = Wall(start_y, start_x+k); i++;
        walls[i] = Wall(start_y, start_x-k); i++;
    }

    return i;
}

int General_template::drawFilledSquareDoor(int start_y, int start_x, int height, int width, int i) 
{
    //this->walls_num += heigth*widht;
    for(int j=0; j < height; j++)
    {
        for(int k=0; k < width; k++)
        {
            doors[i] = Door(start_y+j, start_x+k); i++;
        }
    }
    return i;
}