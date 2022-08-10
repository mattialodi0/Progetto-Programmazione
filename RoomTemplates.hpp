#include "Drawable.hpp"


#define ROOM_LENGTH 31
#define ROOM_WIDTH 91
#define DOORS_LENGTH 4

/*L'approccio con una matrice per rappresentare tutta la stanza dava problemi con la grafica e 
non era effiiente copiare tutta la matrice per ogni stanza
Quindi uso array a 2 dimensioni solo per muri e porte*/

class general_template {
public:
    Drawable walls[4];
    int walls_num;
    Drawable doors[4];
    int doors_num;
};

class template_0 : public general_template {
public:
    Drawable walls[4];
    int walls_num = 4;
    //Drawable doors[4];
    //int doors_num = 4*DOORS_LENGTH;
    template_0() 
    {
        Drawable w0 = Drawable(3,3,'X');
        Drawable w1 = Drawable(4,4,'X');
        Drawable w2 = Drawable(5,5,'X');
        Drawable w3 = Drawable(6,6,'X');
        walls[0] = w0;
        walls[1] = w1;
        walls[2] = w2;
        walls[3] = w3;
    }
};
