/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** init
*/

#include "../includes/runner.h"

game_t init_txr(game_t aretourner)
{
    aretourner.window = create_Window();
    aretourner.music.ra = sfMusic_createFromFile("music/run_away.ogg");
    aretourner.music.jump = sfMusic_createFromFile("music/jump.ogg");
    aretourner.txr.bg1t = sfTexture_createFromFile("image/sky.png", NULL);
    aretourner.txr.bg2t = sfTexture_createFromFile("image/star1.png", NULL);
    aretourner.txr.bg3t = sfTexture_createFromFile("image/rock.png", NULL);
    aretourner.txr.bg4t = sfTexture_createFromFile("image/castle.png", NULL);
    aretourner.txr.bg5t = sfTexture_createFromFile("image/hill.png", NULL);
    aretourner.txr.bg6t = sfTexture_createFromFile("image/star2.png", NULL);
    aretourner.txr.bg7t = sfTexture_createFromFile("image/cloud1.png", NULL);
    aretourner.txr.bg8t = sfTexture_createFromFile("image/ice.png", NULL);
    aretourner.txr.bg9t = sfTexture_createFromFile("image/cloud2.png", NULL);
    aretourner.txr.yout = sfTexture_createFromFile("image/player.png", NULL);
    aretourner.txr.dwt = sfTexture_createFromFile("image/dw.png", NULL);
    aretourner.txr.upt = sfTexture_createFromFile("image/ghost.png", NULL);
    return aretourner;
}

game_t init_sprt_create(game_t aretourner)
{
    aretourner.sprt.bg1s = sfSprite_create();
    aretourner.sprt.bg2s = sfSprite_create();
    aretourner.sprt.bg3s = sfSprite_create();
    aretourner.sprt.bg4s = sfSprite_create();
    aretourner.sprt.bg5s = sfSprite_create();
    aretourner.sprt.bg6s = sfSprite_create();
    aretourner.sprt.bg7s = sfSprite_create();
    aretourner.sprt.bg8s = sfSprite_create();
    aretourner.sprt.bg9s = sfSprite_create();
    aretourner.sprt.ups = sfSprite_create();
    aretourner.sprt.yous = sfSprite_create();
    aretourner.sprt.dws = sfSprite_create();
    return aretourner;
}

game_t init_vol_jump_lobby_end(game_t aretourner)
{
    aretourner.music.ra_volume = 50;
    sfMusic_setVolume(aretourner.music.ra, aretourner.music.ra_volume);
    sfRenderWindow_setFramerateLimit(aretourner.window, 144);
    sfRenderWindow_setMouseCursorVisible(aretourner.window, sfFalse);
    aretourner.nb.count.count_rect_pos_dw = 0;
    aretourner.nb.count.count_rect_pos_you = 0;
    aretourner.nb.count.jump = 0;
    aretourner.nb.b.lobby = 1;
    aretourner.nb.b.lose = 0;
    aretourner.nb.b.win = 0;
    aretourner.nb.xy.bg1v.x = 0;
    aretourner.nb.xy.bg1v.y = 0;
    aretourner.nb.xy.bg2v.x = 0;
    aretourner.nb.xy.bg2v.y = 0;
    aretourner.nb.xy.bg3v.x = 0;
    aretourner.nb.xy.bg3v.y = 0;
    aretourner.nb.xy.bg4v.x = 0;
    aretourner.nb.speed = 1;
    return aretourner;
}

game_t init_pos_xy(game_t aretourner)
{
    aretourner.nb.xy.bg4v.y = -50;
    aretourner.nb.xy.bg5v.x = 0;
    aretourner.nb.xy.bg5v.y = 0;
    aretourner.nb.xy.bg6v.x = 0;
    aretourner.nb.xy.bg6v.y = 0;
    aretourner.nb.xy.bg7v.x = 0;
    aretourner.nb.xy.bg7v.y = 0;
    aretourner.nb.xy.bg8v.x = 0;
    aretourner.nb.xy.bg8v.y = 0;
    aretourner.nb.xy.bg9v.x = 0;
    aretourner.nb.xy.bg9v.y = -50;
    aretourner.nb.xy.youv.x = 200;
    aretourner.nb.xy.youv.y = 725;
    aretourner.nb.xy.dwv.x = -200;
    aretourner.nb.xy.dwv.y = 700;
    aretourner.nb.xy.upv.x = -200;
    aretourner.nb.xy.upv.y = 550;
    return aretourner;
}

game_t init1(game_t aretourner)
{
    aretourner = init_txr(aretourner);
    aretourner = init_sprt_create(aretourner);
    aretourner = init_vol_jump_lobby_end(aretourner);
    aretourner = init_pos_xy(aretourner);
    aretourner.nb.faster = 0;
    return aretourner;
}
