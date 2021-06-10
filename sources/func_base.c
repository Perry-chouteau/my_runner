/*
** EPITECH PROJECT, 2020
** windows
** File description:
** windows
*/

#include "../includes/runner.h"

sfRenderWindow *create_Window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode,  \
    "Viens chercher ton gouter.", sfDefaultStyle, NULL);
    return (window);
}

void mk_music(music_t music)
{
    sfMusic_setLoop(music.ra, sfTrue);
    sfMusic_setVolume(music.ra, music.ra_volume);
    sfMusic_play(music.ra);

    sfMusic_setLoop(music.jump, sfFalse);
}

void change_scale(game_t runner)
{
    sfSprite_setScale(runner.sprt.yous, runner.nb.sz.you_scl);
    sfSprite_setScale(runner.sprt.ups, runner.nb.sz.up_scl);
    sfSprite_setScale(runner.sprt.dws, runner.nb.sz.dw_scl);
}