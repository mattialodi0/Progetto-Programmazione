#include "GeneralTemplate.hpp"

#define ENEMIES rand() % (max_n_enemies) +1


//starting room
class Template_0 : public General_template {
public:
    Template_0(int n,Board &game_board);
};

//random walls
class Template_1 : public General_template {
public:
    Template_1(int n,Board &game_board);
};

//loot room
class Template_2 : public General_template {
public:
    Template_2(int n,Board &game_board);
};

//bottom-right subroom
class Template_3 : public General_template {
public:
    Template_3(int n,Board &game_board);
};

//top-right subroom
class Template_4 : public General_template {
public:
    Template_4(int n,Board &game_board);
};

//top-left cross
class Template_5 : public General_template {
public:
    Template_5(int n,Board &game_board);
};

//bottom-left center subroom
class Template_6 : public General_template {
public:
    Template_6(int n,Board &game_board);
};

//big  negative cross 
class Template_7 : public General_template {
public:
    Template_7(int n,Board &game_board);
};

//central sub-chamber no doors
class Template_8 : public General_template {
public:
    Template_8(int n,Board &game_board);
};

//radom wall blocks
class Template_9 : public General_template {
public:
    Template_9(int n,Board &game_board);
};

//random walls
class Template_10 : public General_template {
public:
    Template_10(int n,Board &game_board);
};

//maze concentric
class Template_11 : public General_template {
public:
    Template_11(int n,Board &game_board);
};

//maze spyral
class Template_12 : public General_template {
public:
    Template_12(int n,Board &game_board);
};

//subroom doors
class Template_13 : public General_template {
public:
    Template_13(int n,Board &game_board);
};

//tempio
class Template_14 : public General_template {
public:
    Template_14(int n,Board &game_board);
};

//chrome subchambers
class Template_15 : public General_template {
public:
    Template_15(int n,Board &game_board);
};

//hexagonal chamber
class Template_16 : public General_template {
public:
    Template_16(int n,Board &game_board);
};

//4 square x
class Template_17 : public General_template {
public:
    Template_17(int n,Board &game_board);
};

//4 square +
class Template_18 : public General_template {
public:
    Template_18(int n,Board &game_board);
};

//random cross
class Template_19 : public General_template {
public:
    Template_19(int n,Board &game_board);
};

//horizontal S
class Template_20 : public General_template {
public:
    Template_20(int n,Board &game_board);
};

//4 angoli 
class Template_21 : public General_template {
public:
    Template_21(int n,Board &game_board);
};

//pacman
class Template_22 : public General_template {
public:
    Template_22(int n,Board &game_board);
};

//verical blocking wall right 
class Template_23 : public General_template {
public:
    Template_23(int n,Board &game_board);
};

//verical blocking wall left 
class Template_24 : public General_template {
public:
    Template_24(int n,Board &game_board);
};

//horizontal blocking wall up 
class Template_25 : public General_template {
public:
    Template_25(int n,Board &game_board);
};

//horizontal blocking wall down 
class Template_26 : public General_template {
public:
    Template_26(int n,Board &game_board);
};

//turret boss
class Template_27 : public General_template {
public:
    Template_27(int n,Board &game_board);
};

//4 turret
class Template_28 : public General_template {
public:
    Template_28(int n,Board &game_board);
};

//16 turret
class Template_29 : public General_template {
public:
    Template_29(int n,Board &game_board);
};

//wall horizontal north rand
class Template_30 : public General_template {
public:
    Template_30(int n,Board &game_board);
};

//wall horizontal south rand
class Template_31 : public General_template {
public:
    Template_31(int n,Board &game_board);
};

//wall vertical west rand
class Template_32 : public General_template {
public:
    Template_32(int n,Board &game_board);
};

//wall vertical est rand
class Template_33 : public General_template {
public:
    Template_33(int n,Board &game_board);
};

//4 rand subchamber
class Template_34 : public General_template {
public:
    Template_34(int n,Board &game_board);
};

//3 rand subchamber vertical
class Template_35 : public General_template {
public:
    Template_35(int n,Board &game_board);
};

//3 rand subchamber horizontal
class Template_36 : public General_template {
public:
    Template_36(int n,Board &game_board);
};

//stalker boss, (4 deboli + il boss)
class Template_37 : public General_template {
public:
    Template_37(int n,Board &game_board);
};

//drunk boss (4 deboli + il boss)
class Template_38 : public General_template {
public:
    Template_38(int n,Board &game_board);
};

//ortogonal cross
class Template_39 : public General_template {
public:
    Template_39(int n,Board &game_board);
};

//ortogonal cross
class Template_40 : public General_template {
public:
    Template_40(int n,Board &game_board);
};