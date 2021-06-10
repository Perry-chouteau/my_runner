/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** win.c
*/

#include "../includes/runner.h"

pause_t init_win(void)
{
    pause_t win;

    win.pauset = sfTexture_createFromFile("image/win.png", NULL);
    win.pauses = sfSprite_create();
    sfSprite_setTexture(win.pauses, win.pauset, sfTrue);
    win.pause_scl.x = 1;
    win.pause_scl.y = 1;
    win.pausev.x = 0;
    win.pausev.y = 0;
    sfSprite_setPosition(win.pauses, win.pausev);
    sfSprite_setScale(win.pauses, win.pause_scl);
    return win;
}

game_t win_event(game_t runner, sfEvent event)
{
    runner = check_event_close(event, runner);
    runner = check_event_volume(runner, event);
    return runner;
}

game_t win(game_t runner, sfEvent event)
{
    if (runner.nb.b.win == 1) {
        pause_t win = init_win();
        runner = init_runner(runner);
        for (; runner.nb.b.win == 1;) {
            while (sfRenderWindow_pollEvent(runner.window, &event))
                runner = win_event(runner, event);
            sfRenderWindow_drawSprite(runner.window, win.pauses, NULL);
            sfRenderWindow_drawText(runner.window, runner.txt.compteur, NULL);
            sfRenderWindow_display(runner.window);
        }
        sfRenderWindow_setMouseCursorVisible(runner.window, sfFalse);
        sfTexture_destroy(win.pauset);
        sfSprite_destroy(win.pauses);
    }
    return runner;
}