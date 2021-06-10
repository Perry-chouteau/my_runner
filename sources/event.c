/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myhunter-perry.chouteau
** File description:
** event.c
*/

#include "../includes/runner.h"

game_t check_event_close(sfEvent event, game_t runner)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        runner.nb.b.lobby = 0;
        runner.nb.b.lose = 0;
        runner.nb.b.win = 0;
        runner.nb.b.pause = 0;
        sfRenderWindow_close(runner.window);
    }
    return runner;
}

game_t check_event_key(sfEvent event, game_t runner)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        if (runner.nb.count.jump == 0) {
            runner.nb.count.jump = 1;
            sfMusic_stop(runner.music.jump);
            sfMusic_play(runner.music.jump);
        }
    if (sfKeyboard_isKeyPressed(sfKeyTab))
        runner.nb.b.pause = 1;
    return runner;
}

game_t check_event_volume(game_t runner, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyAdd))
        if (runner.music.ra_volume < 100){
            runner.music.ra_volume += 2;
        sfMusic_setVolume(runner.music.ra, runner.music.ra_volume);
        }
    if (sfKeyboard_isKeyPressed(sfKeySubtract))
        if (runner.music.ra_volume > 0) {
            runner.music.ra_volume -= 2;
        sfMusic_setVolume(runner.music.ra, runner.music.ra_volume);
        }
    return runner;
}

game_t check_event(sfEvent event, game_t runner)
{
    runner = check_event_close(event, runner);
    runner = check_event_key(event, runner);
    runner = check_event_volume(runner, event);
    return runner;
}