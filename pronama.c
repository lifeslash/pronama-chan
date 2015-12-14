/*========================================
 *        Copyright 1993,1998,2014
 *                  Toyoda Masashi
 *                  (mtoyoda@acm.org)
 *========================================
*/
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "pronama.h"

int add_pro(int x);
int my_mvaddstr(int y, int x, char *str);

int my_mvaddstr(int y, int x, char *str)
{
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

int main(int argc, char *argv[])
{
    int x;
    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    for (x = COLS - 1; ; --x) {
        if (add_pro(x) == ERR) break;
        getch();
        refresh();
        usleep(40000);
    }
    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();
}


int add_pro(int x)
{
    static char *pronama[HIGHT + 1]
        = {pro1, pro2, pro3, pro4, pro5, pro6, pro7, pro8, pro9, pro10,
           pro11,pro12,pro13,pro14,pro15,pro16,pro17,pro18,pro19,pro20,
           pro21,pro22,pro23,pro24,pro25,pro26,pro27,pro28,pro29,pro30,proDEL};
    int i, y, py1 = 0, py2 = 0, py3 = 0;

    if (x < - LENGTH)  return ERR;
    y = LINES / 2 - 3;

    for (i = 0; i <= HIGHT; ++i) {
        my_mvaddstr(y + i, x, pronama[i]);
    }
    return OK;
}
