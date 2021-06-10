/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** my_pause.c
*/

#include "../includes/runner.h"

pause_t init_my_pause(void)
{
    pause_t my_pause;

    my_pause.pauset = sfTexture_createFromFile("image/my_pause.png", NULL);
    my_pause.pauses = sfSprite_create();
    sfSprite_setTexture(my_pause.pauses, my_pause.pauset, sfTrue);
    my_pause.pause_scl.x = 1;
    my_pause.pause_scl.y = 1;
    my_pause.pausev.x = 0;
    my_pause.pausev.y = 0;
    sfSprite_setPosition(my_pause.pauses, my_pause.pausev);
    sfSprite_setScale(my_pause.pauses, my_pause.pause_scl);
    return my_pause;
}

game_t check_event_my_pause2(game_t runner, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||  \
        sfKeyboard_isKeyPressed(sfKeyTab)) {
        runner.nb.b.pause = 0;
    }
    return runner;
}

game_t my_pause_event(game_t runner, sfEvent event)
{
    runner = check_event_close(event, runner);
    runner = check_event_my_pause2(runner, event);
    runner = check_event_volume(runner, event);
    return runner;
}

game_t my_pause(game_t runner, sfEvent event)
{
    if (runner.nb.b.pause == 1) {
        pause_t my_pause = init_my_pause();
        sfRenderWindow_setMouseCursorVisible(runner.window, sfTrue);
        sfRenderWindow_drawSprite(runner.window, my_pause.pauses, NULL);
        sfRenderWindow_drawText(runner.window, runner.txt.compteur, NULL);
        sfRenderWindow_display(runner.window);
        for (; runner.nb.b.pause == 1;) {
            while (sfRenderWindow_pollEvent(runner.window, &event))
                runner = my_pause_event(runner, event);
        }
        sfRenderWindow_setMouseCursorVisible(runner.window, sfFalse);
        sfTexture_destroy(my_pause.pauset);
        sfSprite_destroy(my_pause.pauses);
    }
    return runner;
}