/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** window.c
*/

#include "../includes/runner.h"

game_t init3(game_t runner, int ac, char **av)
{
    if (ac >= 3)
        if (my_atof(av[2]) > 0 && my_atof(av[2]) <= 5)
            runner.nb.speed = my_atof(av[2]);
    if (ac >= 4)
        if (my_atof(av[3]) >= 0 && my_atof(av[3]) <= 0.1)
            runner.nb.faster = my_atof(av[3]);
    return runner;
}

game_t set_all(game_t runner, int ac, char **av)
{
    runner = init1(runner);
    runner = init2(runner);
    runner = init3(runner, ac, av);
    mk_sprite(runner.txr, runner.sprt);
    change_scale(runner);
    mk_music(runner.music);
    image_position(runner.sprt, runner.nb.xy);
    return runner;
}

game_t bloc_pause(game_t runner, sfEvent event)
{
    runner = lobby(runner, event);
    runner = lose(runner, event);
    runner = win(runner, event);
    runner = my_pause(runner, event);
    return runner;
}

int main(int ac, char **av)
{
    sfEvent event;
    game_t runner;
    runner = set_map(ac, av);
    if (runner.nb.speed == -1)
        return 0;
    if (runner.nb.speed == -84)
        return 84;
    runner = set_all(runner , ac, av);
    while (sfRenderWindow_isOpen(runner.window)) {
        runner = bloc_pause(runner, event);
        while (sfRenderWindow_pollEvent(runner.window, &event))
            runner = check_event(event, runner);
        runner = changes(runner);
        draw_image(runner.window, runner);
        sfRenderWindow_display(runner.window);
        sfRenderWindow_clear(runner.window, sfWhite);
    }
    to_destruct(runner);
    return 0;
}