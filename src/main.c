#include <ncurses.h>
#include "train.h"
#include "play.h"

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

/* Draw the board and cursor */
void draw_board(int cy, int cx) {
    clear();
    mvprintw(0, 0, "Tic Tac Toe (Arrow keys to move, Enter to place)");
    mvprintw(1, 0, "Player X vs Player O");

    int y = 3;
    for (int i = 0; i < 3; i++) {
        int x = 0;
        for (int j = 0; j < 3; j++) {
            if (i == cy && j == cx)
                attron(A_REVERSE);

            mvprintw(y, x, " %c ", board[i][j]);

            if (i == cy && j == cx)
                attroff(A_REVERSE);

            if (j < 2) mvprintw(y, x + 3, "|");
            x += 4;
        }
        if (i < 2)
            mvprintw(y + 1, 0, "---+---+---");
        y += 2;
    }
    refresh();
}

/* Check winner */
char check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0];

        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return board[0][i];
    }

    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    return 0;
}

/* Check draw */
int is_draw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    int cy = 0, cx = 0;
    char player = 'X';

    while (1) {
        draw_board(cy, cx);
        int ch = getch();

        if (ch == 'w' && cy > 0) cy--;
        else if (ch == 's' && cy < 2) cy++;
        else if (ch == 'a' && cx > 0) cx--;
        else if (ch == 'd' && cx < 2) cx++;

        else if (ch == '\n' || ch == KEY_ENTER) {
            if (board[cy][cx] == ' ') {
                board[cy][cx] = player;
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        char win = check_winner();
        if (win) {
            clear();
            mvprintw(5, 5, "Player %c Wins!", win);
            mvprintw(7, 5, "Press any key to exit...");
            refresh();
            getch();
            break;
        }

        if (is_draw()) {
            clear();
            mvprintw(5, 5, "It's a Draw!");
            mvprintw(7, 5, "Press any key to exit...");
            refresh();
            getch();
            break;
        }
    }

    endwin();
    return 0;
}
