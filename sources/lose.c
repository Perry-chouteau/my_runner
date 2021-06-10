/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** win.c
*/

#include "../includes/runner.h"

pause_t init_lose(void)
{
    pause_t lose;

    lose.pauset = sfTexture_createFromFile("image/lose.png", NULL);
    lose.pauses = sfSprite_create();
    sfSprite_setTexture(lose.pauses, lose.pauset, sfTrue);
    lose.pause_scl.x = 1;
    lose.pause_scl.y = 1;
    lose.pausev.x = 0;
    lose.pausev.y = 0;
    sfSprite_setPosition(lose.pauses, lose.pausev);
    sfSprite_setScale(lose.pauses, lose.pause_scl);
    return lose;
}

game_t lose_event(game_t runner, sfEvent event)
{
    runner = check_event_volume(runner, event);
    runner = check_event_close(event, runner);
    return runner;
}

game_t lose(game_t runner, sfEvent event)
{
    if (runner.nb.b.lose == 1) {
        pause_t lose = init_lose();
        runner = init_runner(runner);
        for (; runner.nb.b.lose == 1;) {
            while (sfRenderWindow_pollEvent(runner.window, &event))
                runner = lose_event(runner, event);
            sfRenderWindow_drawSprite(runner.window, lose.pauses, NULL);
            sfRenderWindow_drawText(runner.window, runner.txt.compteur, NULL);
            sfRenderWindow_display(runner.window);
        }
        sfRenderWindow_setMouseCursorVisible(runner.window, sfFalse);
        sfTexture_destroy(lose.pauset);
        sfSprite_destroy(lose.pauses);
    }
    return runner;
}