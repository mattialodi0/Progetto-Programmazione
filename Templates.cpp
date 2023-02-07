#include "Templates.hpp"

Template_0::Template_0(int n,Board &game_board) : General_template(0,16,0,0)
{
    drawDoors();
}

Template_1::Template_1(int n,Board &game_board) : General_template(10,16,rand() % (max_n_enemies+1),1)
{
    drawRandom(10, 2, 2,BOARD_ROWS-3, BOARD_COLS-3,0);

    drawDoors();

    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    for(int i=0;i<this->artifact_num;i++){
        createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }
}

Template_2::Template_2(int n,Board &game_board) : General_template(18,16,0,1)
{
    need_doors = true; has_north_door = false; has_south_door = false; has_west_door = false; has_est_door = false;
    int i = 0;
    walls[i] = Wall(HALF_ROWS-3, HALF_COLS-6); i++;
    walls[i] = Wall(HALF_ROWS-3, HALF_COLS-5); i++;
    walls[i] = Wall(HALF_ROWS-3, HALF_COLS-2); i++;
    walls[i] = Wall(HALF_ROWS-2, HALF_COLS-6); i++;
    walls[i] = Wall(HALF_ROWS+3, HALF_COLS-6); i++;
    walls[i] = Wall(HALF_ROWS+3, HALF_COLS-5); i++;
    walls[i] = Wall(HALF_ROWS+3, HALF_COLS-2); i++;
    walls[i] = Wall(HALF_ROWS+2, HALF_COLS-6); i++;
    walls[i] = Wall(HALF_ROWS-3, HALF_COLS+6); i++;
    walls[i] = Wall(HALF_ROWS-3, HALF_COLS+5); i++;
    walls[i] = Wall(HALF_ROWS-3, HALF_COLS+2); i++;
    walls[i] = Wall(HALF_ROWS-2, HALF_COLS+6); i++;
    walls[i] = Wall(HALF_ROWS+3, HALF_COLS+6); i++;
    walls[i] = Wall(HALF_ROWS+3, HALF_COLS+5); i++;
    walls[i] = Wall(HALF_ROWS+3, HALF_COLS+2); i++;
    walls[i] = Wall(HALF_ROWS+2, HALF_COLS+6); i++;
    walls[i] = Wall(HALF_ROWS, HALF_COLS-6); i++;
    walls[i] = Wall(HALF_ROWS, HALF_COLS+6); i++;
    
    drawDoors();

    artifact[0] = Artifact(HALF_ROWS, HALF_COLS);
}

Template_3(int n,Board &game_board) : General_template(30,19,rand() % (max_n_enemies+1),1)
{
    int i = 0;
    i = drawHorizontalLine(BOARD_COLS/3,(BOARD_ROWS/3)*2,(BOARD_COLS/3)*2,i);
    i = drawVerticalLine(BOARD_ROWS/3,(BOARD_ROWS/3)*2,(BOARD_COLS/3)*2,i);

    doors[16] = Door((BOARD_ROWS/3)*2,(BOARD_COLS/3)*2+4);
    doors[17] = Door((BOARD_ROWS/3)*2,(BOARD_COLS/3)*2+3);
    doors[18] = Door((BOARD_ROWS/3)*2,(BOARD_COLS/3)*2+2);
    drawDoors();

    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    for(int i=0;i<this->artifact_num;i++){
        createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }    
}

Template_4(int n,Board &game_board) : General_template(30,19,rand() % (max_n_enemies+1),1)
{
    int i = 0;
    i = drawHorizontalLine(BOARD_COLS/3,BOARD_ROWS/3,(BOARD_COLS/3)*2,i);
    i = drawVerticalLine(BOARD_ROWS/3,1,(BOARD_COLS/3)*2,i);
    
    doors[16] = Door(BOARD_ROWS/3,(BOARD_COLS/3)*2+4);
    doors[17] = Door(BOARD_ROWS/3,(BOARD_COLS/3)*2+3);
    doors[18] = Door(BOARD_ROWS/3,(BOARD_COLS/3)*2+2);
    drawDoors();

    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    for(int i=0;i<this->enemies_num;i++){   
    createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    for(int i=0;i<this->artifact_num;i++){
        createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }    
}

Template_5(int n,Board &game_board) : General_template(30,19,rand() % (max_n_enemies+1),1)
{
    int i = 0;
    i = drawHorizontalLine(BOARD_COLS/3, BOARD_ROWS/3,1,i);
    i = drawVerticalLine(BOARD_ROWS/3, 1,BOARD_COLS/3,i);
    
    doors[16] = Door(BOARD_ROWS/3,BOARD_COLS/3-4);
    doors[17] = Door(BOARD_ROWS/3,BOARD_COLS/3-3);
    doors[18] = Door(BOARD_ROWS/3,BOARD_COLS/3-2);
    drawDoors();
    
    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    //chosen_enemies={}
    //x_chosen={}
    //y_chosen={}
    for(int i=0;i<this->enemies_num;i++){   
    createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    //chosen_artifact={}
    //x_chosen_artifact={}
    //y_chosen_artifact={}
    for(int i=0;i<this->artifact_num;i++){
    createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }
}

Template_6(int n,Board &game_board) : General_template(30,19,rand() % (max_n_enemies+1),1)
{
    
    int i = 0;
    i = drawHorizontalLine(BOARD_COLS/3, (BOARD_ROWS/3)*2,1,i);
    i = drawVerticalLine(BOARD_ROWS/3, (BOARD_ROWS/3)*2,BOARD_COLS/3,i);
    
    doors[16] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-4);
    doors[17] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-3);
    doors[18] = Door((BOARD_ROWS/3)*2,BOARD_COLS/3-2);
    drawDoors();
    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    for(int i=0;i<this->artifact_num;i++){
        createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }    
}

Template_7(int n,Board &game_board) : General_template(161*4,16,rand() % (max_n_enemies+1),1)
{
    need_doors = true;
    has_north_door = true; has_south_door = true; has_west_door = true; has_est_door = true;
    int i = 0;
    i = drawFilledSquare(1, 1, 8, 20, 0);   //126 walls
    i = drawFilledSquare(BOARD_ROWS-9, 1, 8, 20, i+1);   //126 walls
    i = drawFilledSquare(1, BOARD_COLS-21, 8, 20, i+1);   //126 walls
    i = drawFilledSquare(BOARD_ROWS-9, BOARD_COLS-21, 8, 20, i+1);   //126 walls

    drawDoors();

    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    for(int i=0;i<this->artifact_num;i++){
        createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }
}

Template_8(int n,Board &game_board) : General_template(72,32,rand() % (max_n_enemies+1),1)
{
    drawEmptySquare(HALF_ROWS-5, HALF_COLS-13, 11, 27, 0);     //72 walls
    
    drawDoors();
    doors[16] = No_Door(HALF_ROWS-5,HALF_COLS-2);   //north doors
    doors[17] = No_Door(HALF_ROWS-5,HALF_COLS-1);
    doors[18] = No_Door(HALF_ROWS-5,HALF_COLS);
    doors[19] = No_Door(HALF_ROWS-5,HALF_COLS+1);
    doors[20] = No_Door(HALF_ROWS-5,HALF_COLS+2);
    doors[21] = No_Door(HALF_ROWS+5,HALF_COLS-2);   //south doors
    doors[22] = No_Door(HALF_ROWS+5,HALF_COLS-1);
    doors[23] = No_Door(HALF_ROWS+5,HALF_COLS);
    doors[24] = No_Door(HALF_ROWS+5,HALF_COLS+1);
    doors[25] = No_Door(HALF_ROWS+5,HALF_COLS+2);
    doors[26] = No_Door(HALF_ROWS-1,HALF_COLS-13);   //west doors
    doors[27] = No_Door(HALF_ROWS,HALF_COLS-13);
    doors[28] = No_Door(HALF_ROWS+1,HALF_COLS-13);
    doors[29] = No_Door(HALF_ROWS-1,HALF_COLS+13);   //est doors
    doors[30] = No_Door(HALF_ROWS,HALF_COLS+13);
    doors[31] = No_Door(HALF_ROWS+1,HALF_COLS+13);
    
    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    for(int i=0;i<this->artifact_num;i++){
        createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }   
}

Template_9(int n,Board &game_board) : General_template(36,16,rand() % (max_n_enemies+1),1)
{
    int i = 0;
    int ry = rand()%(BOARD_ROWS-4)+1;
    int rx = rand()%(BOARD_COLS-4)+1;
    i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
    ry = rand()%(BOARD_ROWS-2)+1;
    rx = rand()%(BOARD_COLS-3)+1;
    i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
    ry = rand()%(BOARD_ROWS-2)+1;
    rx = rand()%(BOARD_COLS-3)+1;
    i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
    ry = rand()%(BOARD_ROWS-2)+1;
    rx = rand()%(BOARD_COLS-3)+1;
    i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
    ry = rand()%(BOARD_ROWS-2)+1;
    rx = rand()%(BOARD_COLS-3)+1;
    i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls
    ry = rand()%(BOARD_ROWS-2)+1;
    rx = rand()%(BOARD_COLS-3)+1;
    i = drawFilledSquare(ry, rx, 2, 3, i);   //15 walls

    drawDoors();

    int chosen_enemies[enemies_num];
    int x_chosen[enemies_num];
    int y_chosen[enemies_num];
    for(int i=0;i<enemies_num;i++){
        chosen_enemies[i]=x_chosen[i]=y_chosen[i]=0;
    }
    for(int i=0;i<this->enemies_num;i++){   
        createEnemies(true,true,x_chosen[i],y_chosen[i],chosen_enemies[i],i,n,game_board,enemies);
    }
    int chosen_artifact[artifact_num];
    int x_chosen_artifact[artifact_num];
    int y_chosen_artifact[artifact_num];
    for(int i=0;i<artifact_num;i++){
        chosen_artifact[i]=x_chosen_artifact[i]=y_chosen_artifact[i]=0;
    }
    for(int i=0;i<this->artifact_num;i++){
        createArtifact(true,true,x_chosen_artifact[i],y_chosen_artifact[i],chosen_artifact[i],game_board,n,artifact);
    }
}






