/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** sprite.c
*/

#include "../includes/runner.h"

void mk_sprite(txr_t txr, spr_t sprt)
{
    sfSprite_setTexture(sprt.bg1s, txr.bg1t, sfTrue);
    sfSprite_setTexture(sprt.bg2s, txr.bg2t, sfTrue);
    sfSprite_setTexture(sprt.bg3s, txr.bg3t, sfTrue);
    sfSprite_setTexture(sprt.bg4s, txr.bg4t, sfTrue);
    sfSprite_setTexture(sprt.bg5s, txr.bg5t, sfTrue);
    sfSprite_setTexture(sprt.bg6s, txr.bg6t, sfTrue);
    sfSprite_setTexture(sprt.bg7s, txr.bg7t, sfTrue);
    sfSprite_setTexture(sprt.bg8s, txr.bg8t, sfTrue);
    sfSprite_setTexture(sprt.bg9s, txr.bg9t, sfTrue);
    sfSprite_setTexture(sprt.yous, txr.yout, sfTrue);
    sfSprite_setTexture(sprt.ups, txr.upt, sfTrue);
    sfSprite_setTexture(sprt.dws, txr.dwt, sfTrue);
}

void image_position(spr_t sprt, pos_t xy)
{
    sfSprite_setPosition(sprt.bg1s, xy.bg1v);
    sfSprite_setPosition(sprt.bg2s, xy.bg2v);
    sfSprite_setPosition(sprt.bg3s, xy.bg3v);
    sfSprite_setPosition(sprt.bg4s, xy.bg4v);
    sfSprite_setPosition(sprt.bg5s, xy.bg5v);
    sfSprite_setPosition(sprt.bg6s, xy.bg6v);
    sfSprite_setPosition(sprt.bg7s, xy.bg7v);
    sfSprite_setPosition(sprt.bg8s, xy.bg8v);
    sfSprite_setPosition(sprt.bg9s, xy.bg9v);
    sfSprite_setPosition(sprt.yous, xy.youv);
    sfSprite_setPosition(sprt.ups, xy.upv);
    sfSprite_setPosition(sprt.dws, xy.dwv);
}

void draw_image(sfRenderWindow *window, game_t runner)
{
    sfRenderWindow_drawSprite(window, runner.sprt.bg1s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg2s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg3s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg4s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg5s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg6s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg7s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg8s, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.yous, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.ups, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.dws, NULL);
    sfRenderWindow_drawSprite(window, runner.sprt.bg9s, NULL);
    sfRenderWindow_drawText(runner.window, runner.txt.compteur, NULL);
}
