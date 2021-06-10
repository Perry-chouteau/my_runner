/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** lobby.c
*/

#include "../includes/runner.h"
    pause_t init_lobby(void)
{
    pause_t lobby;
    lobby.pauset = sfTexture_createFromFile("image/lobby.png", NULL);
    lobby.pauses = sfSprite_create();
    sfSprite_setTexture(lobby.pauses, lobby.pauset, sfTrue);
    lobby.pause_scl.x = 1;
    lobby.pause_scl.y = 1;
    lobby.pausev.x = 0;
    lobby.pausev.y = 0;
    sfSprite_setPosition(lobby.pauses, lobby.pausev);
    sfSprite_setScale(lobby.pauses, lobby.pause_scl);
    return lobby;
}

game_t lobby_event(game_t runner, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
            runner.nb.b.lobby = 0;
    runner = check_event_volume(runner, event);
    runner = check_event_close(event, runner);
    return runner;
}

game_t lobby(game_t runner, sfEvent event)
{
    if (runner.nb.b.lobby == 1) {
        pause_t lobby = init_lobby();
        sfRenderWindow_setMouseCursorVisible(runner.window, sfTrue);
        for (; runner.nb.b.lobby == 1;) {
            while (sfRenderWindow_pollEvent(runner.window, &event))
                runner = lobby_event(runner, event);
            sfRenderWindow_drawSprite(runner.window, lobby.pauses, NULL);
            sfRenderWindow_display(runner.window);
        }
        sfRenderWindow_setMouseCursorVisible(runner.window, sfFalse);
        sfTexture_destroy(lobby.pauset);
        sfSprite_destroy(lobby.pauses);
    }
    return runner;
}