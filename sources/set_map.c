/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** set_map.c
*/

#include "../includes/runner.h"

void describe1(void)
{
    write(1, "──────────────────────────────────────────────────────\
────────────\n", 199);
    write(1, "DESCRIPTION\n\n", 14);
    write(1, "goal:\t\t dodge all enemy\n", 26);
    write(1, "help:\t\t check the ”Readme.md”\n", 35);

    write(1, "──────────────────────────────────────────────────────\
────────────\n", 199);
    write(1, "USAGE\n\n", 8);
    write(1, "monde1:\t\t lvl1 → make lvl1\n", 29);
    write(1, "\t\t lvl2 → make lvl2\n", 23);
    write(1, "\t\t lvl3 → make lvl3\n", 23);
    write(1, "\t\t lvl4 → make lvl4\n", 23);
    write(1, "\t\t lvl5 → make lvl5\n\n", 24);
    write(1, "monde2:\t\t ”In progress”\n\n", 30);
}

void describe2(void)
{
    write(1, "example:\t./my_runner file.txt 3 ”0.00005”\t", 46);
    write(1, "(double quotes are useless)\n", 29);
    write(1, "map:\t\tUse ”file.txt” or your own file folowing the \
instruction write on ”Readme.md”\n", 93);
    write(1, "lvl:\t\tSet the lvl of the game among 1 to 5\n", 44);
    write(1, "quickning:\tSet the quickening of the game among 0 to 0.1\
    (of course you can use a number longer like 0.0005 (advised) )\n", 123);
    write(1, "──────────────────────────────────────────────────────\
────────────\n", 199);
    write(1, "OPTION\t\t(The Game is explicit)\n\n", 33);
    write(1, "Key/\t\tPress ”Space” to jump\n", 32);
    write(1, "Key/\t\tPress ”Tab” to Stop the game few seconds\n", 52);
    write(1, "Key/\t\tPress ”Enter” to play\n", 32);
    write(1, "Key/\t\tPress ”-” or ”+” to change de music volume\n", 57);
    write(1, "Key/\t\tPress ”Escape” or click on the close button to \
close the window\n", 74);
    write(1, "──────────────────────────────────────────────────────\
────────────\n", 199);
}

int st_size(char const *filepath)
{
    struct stat s;

    stat(filepath, &s);
    return s.st_size;
}

game_t init_map(int ac, char **av)
{
    game_t runner;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        describe1();
        describe2();
        runner.nb.speed = -1;
        return runner;
    }
    runner.file.consumed = 0;
    runner.file.sz = st_size(av[1]);
    runner.file.buffer = malloc(sizeof(char) * runner.file.sz + 1);
    runner.file.nb = malloc(sizeof(int) * runner.file.sz + 1);
    runner.file.fd = open(av[1], O_RDONLY);
    if (runner.file.fd == -1) {
        write(1, "Le nom du fichier est éroné.\n", 31);
        runner.nb.speed = -84;
    }
    return runner;
}

game_t set_map(int ac, char **av)
{
    game_t runner = init_map(ac, av);
    if (runner.nb.speed == -1)
        return runner;
    if (runner.nb.speed == -84)
        return runner;
    read(runner.file.fd, runner.file.buffer, runner.file.sz);
    runner.file.buffer[runner.file.sz] = '\0';
    for (int i = 0; runner.file.buffer[i] != '\0'; i += 1) {
        if (runner.file.buffer[i] == 'o')
            runner.file.nb[i] = 0;
        if (runner.file.buffer[i] == 'x')
            runner.file.nb[i] = 1;
        if (runner.file.buffer[i] == '|')
            runner.file.nb[i] = 2;
    }
    return runner;
}