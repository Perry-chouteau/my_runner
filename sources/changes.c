/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** pos.c
*/

#include "../includes/runner.h"

game_t collision(game_t runner)
{
    if ((runner.nb.xy.youv.y + 100) > runner.nb.xy.dwv.y &&   \
    (runner.nb.xy.youv.x + 100) > (runner.nb.xy.dwv.x + 50) && \
    (runner.nb.xy.youv.x + 100) < (runner.nb.xy.dwv.x + 155))
        runner.nb.b.lose = 1;

    if (((runner.nb.xy.youv.y) < (runner.nb.xy.upv.y + 50) &&    \
    ((runner.nb.xy.youv.x + 100) > (runner.nb.xy.upv.x) &&    \
    (runner.nb.xy.youv.x + 100) < (runner.nb.xy.upv.x + 50))) \
    ||  \
    ((runner.nb.xy.youv.y) < (runner.nb.xy.upv.y + 50) &&  \
    ((runner.nb.xy.youv.x) > (runner.nb.xy.upv.x) &&    \
    (runner.nb.xy.youv.x) < (runner.nb.xy.upv.x + 50))))
        runner.nb.b.lose = 1;
    return runner;
}

game_t changes(game_t runner)
{
    runner = change_pos(runner);
    runner = change_rect(runner);
    runner = change_txt(runner);
    runner = collision(runner);
    runner.nb.speed += runner.nb.faster;
    return runner;
}