/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** change_pos1.c
*/

#include "../includes/runner.h"

game_t change_pos1(game_t runner)
{
    if (runner.nb.xy.bg2v.x > -1920)
        runner.nb.xy.bg2v.x -= 1 * runner.nb.speed;
    else
        runner.nb.xy.bg2v.x = 0;
    sfSprite_setPosition(runner.sprt.bg2s, runner.nb.xy.bg2v);
    if (runner.nb.xy.bg3v.x > -1920)
        runner.nb.xy.bg3v.x -= 1.5 * runner.nb.speed;
    else
        runner.nb.xy.bg3v.x = 0;
    sfSprite_setPosition(runner.sprt.bg3s, runner.nb.xy.bg3v);
    if (runner.nb.xy.bg4v.x > -1920)
        runner.nb.xy.bg4v.x -= 2 * runner.nb.speed;
    else
        runner.nb.xy.bg4v.x = 1920;
    sfSprite_setPosition(runner.sprt.bg4s, runner.nb.xy.bg4v);
    if (runner.nb.xy.bg5v.x > -1920)
        runner.nb.xy.bg5v.x -= 2.5 * runner.nb.speed;
    else
        runner.nb.xy.bg5v.x = 0;
    return runner;
}

game_t change_pos2(game_t runner)
{
    sfSprite_setPosition(runner.sprt.bg5s, runner.nb.xy.bg5v);
    if (runner.nb.xy.bg6v.x > -1920)
        runner.nb.xy.bg6v.x -= 3 * runner.nb.speed;
    else
        runner.nb.xy.bg6v.x = 0;
    sfSprite_setPosition(runner.sprt.bg6s, runner.nb.xy.bg6v);
    if (runner.nb.xy.bg7v.x > -1920)
        runner.nb.xy.bg7v.x -= 3.5 * runner.nb.speed;
    else
        runner.nb.xy.bg7v.x = 0;
    sfSprite_setPosition(runner.sprt.bg7s, runner.nb.xy.bg7v);
    if (runner.nb.xy.bg8v.x > -1920)
        runner.nb.xy.bg8v.x -= 4 * runner.nb.speed;
    else
        runner.nb.xy.bg8v.x = 0;
    sfSprite_setPosition(runner.sprt.bg8s, runner.nb.xy.bg8v);
    return runner;
}

game_t change_pos3(game_t runner)
{
    if (runner.nb.xy.bg9v.x > -1920)
        runner.nb.xy.bg9v.x -= 4.5 * runner.nb.speed;
    else
        runner.nb.xy.bg9v.x = 0;
    sfSprite_setPosition(runner.sprt.bg9s, runner.nb.xy.bg9v);
    return runner;
}

game_t change_pos4(game_t runner)
{
    if (runner.nb.count.jump == 1) {
        if (runner.nb.xy.youv.y > 650)
            runner.nb.xy.youv.y -= 5;
        if (runner.nb.xy.youv.y > 550)
            runner.nb.xy.youv.y -= 4;
        if (runner.nb.xy.youv.y > 500)
            runner.nb.xy.youv.y -= 3;
    } else if (runner.nb.count.jump >= 30) {
        if (runner.nb.xy.youv.y > 600)
            runner.nb.xy.youv.y += 5;
        if (runner.nb.xy.youv.y > 500)
            runner.nb.xy.youv.y += 4;
        if (runner.nb.xy.youv.y <= 500)
            runner.nb.xy.youv.y += 3;
    }
    if (runner.nb.xy.youv.y <= 500)
        runner.nb.count.jump += 1;
    if (runner.nb.xy.youv.y >= 725)
        runner.nb.count.jump = 0;
    sfSprite_setPosition(runner.sprt.yous, runner.nb.xy.youv);
    return runner;
}

game_t change_pos(game_t runner)
{
    runner = change_pos1(runner);
    runner = change_pos2(runner);
    runner = change_pos3(runner);
    runner = change_pos5(runner);
    runner = change_pos4(runner);
    return runner;
}