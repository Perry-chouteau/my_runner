/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** init2.c
*/

#include "../includes/runner.h"

game_t init_rect(game_t aretourner)
{
    aretourner.nb.you.offset = 100;
    aretourner.nb.you.max = 600;
    aretourner.nb.you.rect.top = 0;
    aretourner.nb.you.rect.left = 0;
    aretourner.nb.you.rect.height = 100;
    aretourner.nb.you.rect.width = 100;

    aretourner.nb.dw.offset = 205;
    aretourner.nb.dw.offset_ = 384;
    aretourner.nb.dw.max = 1230,
    aretourner.nb.dw.max_ = 1920;
    aretourner.nb.dw.rect.top = 0;
    aretourner.nb.dw.rect.left = 0;
    aretourner.nb.dw.rect.height = 384;
    aretourner.nb.dw.rect.width = 205;
    return aretourner;
}

game_t init_scale(game_t aretourner)
{
    aretourner.nb.sz.you_scl.x = 1.8;
    aretourner.nb.sz.you_scl.y = 1.8;
    sfSprite_setScale(aretourner.sprt.yous, aretourner.nb.sz.you_scl);
    aretourner.nb.sz.dw_scl.x = 0.5;
    aretourner.nb.sz.dw_scl.y = 0.5;
    sfSprite_setScale(aretourner.sprt.dws, aretourner.nb.sz.dw_scl);
    aretourner.nb.sz.up_scl.x = 0.125;
    aretourner.nb.sz.up_scl.y = 0.125;
    sfSprite_setScale(aretourner.sprt.ups, aretourner.nb.sz.up_scl);
    return aretourner;
}

game_t init_txt(game_t aretourner)
{
    aretourner.txt.str = malloc(sizeof(char) * 22);
    for (int i = 0; i < 20; i += 1)
        aretourner.txt.str[i] = '0';
    aretourner.txt.str[20] = ' ';
    aretourner.txt.str[21] = 'm';
    aretourner.txt.compteur_pos.x = -480;
    aretourner.txt.compteur_pos.y = 0;
    aretourner.txt.compteur_scl.x = 1.5;
    aretourner.txt.compteur_scl.y = 1.5;
    aretourner.txt.move_count = 18;
    aretourner.txt.compteur = sfText_create();
    aretourner.txt.font = sfFont_createFromFile("text/Roboto-Light.ttf");
    sfText_setFont(aretourner.txt.compteur, aretourner.txt.font);
    sfText_setPosition(aretourner.txt.compteur, aretourner.txt.compteur_pos);
    sfText_setScale(aretourner.txt.compteur, aretourner.txt.compteur_scl);
    return aretourner;
}       //pos.x = 760;

game_t init2(game_t aretourner)
{
    aretourner = init_rect(aretourner);
    aretourner = init_scale(aretourner);
    aretourner = init_txt(aretourner);
    return aretourner;
}