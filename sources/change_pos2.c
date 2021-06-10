/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** change_pos2.c
*/

#include "../includes/runner.h"

game_t change_pos5(game_t runner)
{
    runner.nb.xy.dwv.x -= 4 * runner.nb.speed;
    runner.nb.xy.upv.x -= 4 * runner.nb.speed;
    if (runner.nb.xy.dwv.x < -100 && runner.nb.xy.upv.x < -100) {
        if (runner.file.nb[runner.file.consumed] == 0)
            runner.nb.xy.upv.x = 2000;
        if (runner.file.nb[runner.file.consumed] == 1)
            runner.nb.xy.dwv.x = 2000;
        if (runner.file.nb[runner.file.consumed] == 2)
            runner.nb.b.win = 1;
        runner.file.consumed += 1;
    }
    sfSprite_setPosition(runner.sprt.dws, runner.nb.xy.dwv);
    sfSprite_setPosition(runner.sprt.ups, runner.nb.xy.upv);
    return runner;
}