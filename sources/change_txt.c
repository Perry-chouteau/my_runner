/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** change_txt.c
*/

#include "../includes/runner.h"

game_t init_runner(game_t runner)
{
    sfRenderWindow_setMouseCursorVisible(runner.window, sfTrue);
    runner.txt.compteur_scl.x = 2;
    runner.txt.compteur_scl.y = 2;
    sfText_setScale(runner.txt.compteur, runner.txt.compteur_scl);
    runner.txt.compteur_pos.x = 650;
    runner.txt.compteur_pos.y = 50;
    sfText_setPosition(runner.txt.compteur, runner.txt.compteur_pos);
    return runner;
}

game_t change_txt(game_t runner)
{
    runner.txt.str[19] += 1;
    for (int i = 19; runner.txt.str[i] == ':' && i >= 0; i -= 1) {
        if (runner.txt.str[i] == ':')
            runner.txt.str[i] = '0';
        runner.txt.str[i - 1] += 1;
    }
    if (runner.txt.str[runner.txt.move_count] == '1' && \
    runner.txt.move_count >= 0) {
        runner.txt.compteur_pos.x += 25;
        runner.txt.move_count -= 1;
        sfText_setPosition(runner.txt.compteur, runner.txt.compteur_pos);
    }
    sfText_setString(runner.txt.compteur, runner.txt.str);
    return runner;
}