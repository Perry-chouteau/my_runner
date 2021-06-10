/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** init
*/

#include "../includes/runner.h"

void to_destruct1(game_t to_destruct)
{
    sfTexture_destroy(to_destruct.txr.bg1t);
    sfTexture_destroy(to_destruct.txr.bg2t);
    sfTexture_destroy(to_destruct.txr.bg3t);
    sfTexture_destroy(to_destruct.txr.bg4t);
    sfTexture_destroy(to_destruct.txr.bg5t);
    sfTexture_destroy(to_destruct.txr.bg6t);
    sfTexture_destroy(to_destruct.txr.bg7t);
    sfTexture_destroy(to_destruct.txr.bg8t);
    sfTexture_destroy(to_destruct.txr.bg9t);
    sfTexture_destroy(to_destruct.txr.yout);
    sfTexture_destroy(to_destruct.txr.upt);
    sfTexture_destroy(to_destruct.txr.dwt);
}

void to_destruct2(game_t to_destruct)
{
    sfSprite_destroy(to_destruct.sprt.bg1s);
    sfSprite_destroy(to_destruct.sprt.bg2s);
    sfSprite_destroy(to_destruct.sprt.bg3s);
    sfSprite_destroy(to_destruct.sprt.bg4s);
    sfSprite_destroy(to_destruct.sprt.bg5s);
    sfSprite_destroy(to_destruct.sprt.bg6s);
    sfSprite_destroy(to_destruct.sprt.bg7s);
    sfSprite_destroy(to_destruct.sprt.bg8s);
    sfSprite_destroy(to_destruct.sprt.bg9s);
    sfSprite_destroy(to_destruct.sprt.yous);
    sfSprite_destroy(to_destruct.sprt.ups);
    sfSprite_destroy(to_destruct.sprt.dws);
    return ;
}

void to_destruct(game_t to_destruct)
{
    to_destruct2(to_destruct);
    to_destruct1(to_destruct);
    free(to_destruct.txt.str);
    sfMusic_destroy(to_destruct.music.ra);
    sfMusic_destroy(to_destruct.music.jump);
    sfRenderWindow_destroy(to_destruct.window);
}