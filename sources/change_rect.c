/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** you_rect_pos.c
*/

#include "../includes/runner.h"

game_t rect_pos_you(game_t runner, int i)
{
        runner.nb.you.rect.left += runner.nb.you.offset;
        if (runner.nb.you.rect.left >= runner.nb.you.max)
            runner.nb.you.rect.left = 0;
        runner.nb.count.count_rect_pos_you = 0;
    return runner;
}

game_t rect_pos_dw(game_t runner, int i)
{
    runner.nb.dw.rect.left += runner.nb.dw.offset;
    if (runner.nb.dw.rect.left >= runner.nb.dw.max) {
        runner.nb.dw.rect.top += runner.nb.dw.offset_;
        if (runner.nb.dw.rect.top >= runner.nb.dw.max_)
            runner.nb.dw.rect.top = 0;
        runner.nb.dw.rect.left = 0;
    }
    runner.nb.count.count_rect_pos_dw = 0;
    return runner;
}

game_t rect_pos_jump(game_t runner)
{
    if (runner.nb.count.jump >= 1 && runner.nb.count.jump <= 15) {
        runner.nb.you.rect.top = 100;
        runner.nb.you.rect.left = 0;
    }
    if (runner.nb.count.jump >= 15 && runner.nb.count.jump <= 30) {
        runner.nb.you.rect.top = 100;
        runner.nb.you.rect.left = 100;
    }
    if (runner.nb.xy.youv.y >= 725) {
        runner.nb.you.rect.top = 0;
    }
    return runner;
}

game_t change_rect(game_t runner)
{
    int i = runner.nb.count.count_rect_pos_you += 1;
    if (i >= 20 / runner.nb.speed)
        runner = rect_pos_you(runner, i);
    i = runner.nb.count.count_rect_pos_dw += 1;
    if (i == 2)
        runner = rect_pos_dw(runner, i);
    runner = rect_pos_jump(runner);
    sfSprite_setTextureRect(runner.sprt.yous, runner.nb.you.rect);
    sfSprite_setTextureRect(runner.sprt.dws, runner.nb.dw.rect);
    return runner;
}