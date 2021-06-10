/*
** EPITECH PROJECT, 2020
** hunter.h
** File description:
** hunter
*/

#ifndef HUNTER_H
#define HUNTER_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <time.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

///////////// ↓  sfvector2f ↓  ///////////////
typedef struct
{
    sfVector2f bg1v;
    sfVector2f bg2v;
    sfVector2f bg3v;
    sfVector2f bg4v;
    sfVector2f bg5v;
    sfVector2f bg6v;
    sfVector2f bg7v;
    sfVector2f bg8v;
    sfVector2f bg9v;
    sfVector2f youv;
    sfVector2f upv;
    sfVector2f dwv;
} pos_t;

typedef struct
{
    sfVector2f you_scl;
    sfVector2f dw_scl;
    sfVector2f up_scl;
} scl_t;

///////////// ↓  int ↓  ///////////////
typedef struct
{
    int count_rect_pos_you;
    int count_rect_pos_dw;
    int count_meters;
    int jump;
}count_t;

///////////// ↓  rect  ↓  ///////////////
typedef struct
{
    sfIntRect rect;
    int offset;
    int offset_;
    int max;
    int max_;
}myrect_t;

///////////// ↓  file ↓  /sfvector2f/int/rect////////////
typedef struct
{
    int fd;
    char *buffer;
    int *nb;
    int sz;
    int consumed;
} file_t;

///////////// ↓  bool ↓  /sfvector2f/int/rect////////////
typedef struct
{
    bool lobby;
    bool lose;
    bool win;
    bool pause;
}bool_t;

///////////// ↓  nb ↓  /sfvector2f/int/rect/bool///////////
typedef struct
{
    pos_t xy;
    scl_t sz;
    count_t count;
    myrect_t you;
    myrect_t up;
    myrect_t dw;
    bool_t b;
    float speed;
    float faster;
} nb_t;

////////////    IMAGE   ////////////////
typedef struct
{
    sfSprite *bg1s;
    sfSprite *bg2s;
    sfSprite *bg3s;
    sfSprite *bg4s;
    sfSprite *bg5s;
    sfSprite *bg6s;
    sfSprite *bg7s;
    sfSprite *bg8s;
    sfSprite *bg9s;
    sfSprite *yous;
    sfSprite *ups;
    sfSprite *dws;
} spr_t;

typedef struct
{
    sfTexture *bg1t;
    sfTexture *bg2t;
    sfTexture *bg3t;
    sfTexture *bg4t;
    sfTexture *bg5t;
    sfTexture *bg6t;
    sfTexture *bg7t;
    sfTexture *bg8t;
    sfTexture *bg9t;
    sfTexture *yout;
    sfTexture *upt;
    sfTexture *dwt;
} txr_t;

////////////   ↓ music ↓   //////////////
typedef struct
{
    sfMusic *ra;
    float ra_volume;
    sfMusic *jump;
} music_t;

////////////   ↓ text ↓   //////////////
typedef struct
{
    sfVector2f compteur_pos;
    sfVector2f compteur_scl;
    sfFont *font;
    sfText *compteur;
    int move_count;
    char *str;
}txt_t;

////////////   ↓ global game ↓   /nb/texture/sprite/music/text/////////
typedef struct
{
    sfRenderWindow *window;
    sfEvent event;
    sfKeyEvent key;
    file_t file;
    nb_t nb;
    txr_t txr;
    spr_t sprt;
    music_t music;
    txt_t txt;
} game_t;

////////////   ↓ lobby / lose / win / pause ↓   //////////////
typedef struct
{
    sfTexture *pauset;
    sfSprite *pauses;
    sfVector2f pause_scl;
    sfVector2f pausev;
}pause_t;

// my_atof
double my_atof(char *str);

//  window | -h
sfRenderWindow *create_Window(void);
void describe(void);

//  set all
game_t set_map(int ac, char **av);
game_t set_all(game_t runner, int ac, char **av);

game_t init1(game_t aretourner);
game_t init2(game_t aretourner);

void mk_txt(game_t runner);
void mk_music(music_t music);
void mk_sprite(txr_t txr, spr_t sprt);
void change_scale(game_t runner);
void image_position(spr_t sprt, pos_t xy);

//bloc_pause
game_t lobby(game_t runner, sfEvent event);
game_t lose(game_t runner, sfEvent event);
game_t win(game_t runner, sfEvent event);
game_t my_pause(game_t runner, sfEvent event);

game_t init_runner(game_t runner);

//  event
game_t check_event(sfEvent event, game_t h_pos);

game_t check_event_close(sfEvent event, game_t my_struct);
game_t check_event_key(sfEvent event, game_t my_struct);
game_t check_event_volume(game_t runner, sfEvent event);

//position
game_t changes(game_t runner);
game_t change_pos(game_t runner);
game_t change_pos5(game_t runner);
game_t change_rect(game_t runner);
game_t change_txt(game_t runner);
game_t print_compteur(game_t runner);


//draw
void draw_image(sfRenderWindow *window, game_t hunter);

//destroy, free
void to_destruct(game_t to_destruct);

#endif
