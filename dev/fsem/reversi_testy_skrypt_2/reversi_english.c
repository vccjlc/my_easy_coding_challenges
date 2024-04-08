#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define LEGAL 7
#define DIMENSION 8
#define BLACK_TURN 10
#define WHITE_TURN 20
#define FIRST_INIT_FIELD 3
#define SECOND_INIT_FIELD 4

typedef int board_type[DIMENSION][DIMENSION];

void initialize_board(board_type board) {
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

void set_initial_state(board_type board) {
    board[FIRST_INIT_FIELD][FIRST_INIT_FIELD] = WHITE;
    board[FIRST_INIT_FIELD][SECOND_INIT_FIELD] = BLACK;
    board[SECOND_INIT_FIELD][FIRST_INIT_FIELD] = BLACK;
    board[SECOND_INIT_FIELD][SECOND_INIT_FIELD] = WHITE;
}

int change_turn(int turn) {
    if (turn == BLACK_TURN) {
        return WHITE_TURN;
    } else {
        return BLACK_TURN;
    }
}

bool in_range(int i) { return i >= 0 && i < DIMENSION; }

bool check_direction(board_type board, int row, int col, int drow,
                     int dcol, int turn) {
    int i, j;
    int enemy_piece = (turn == BLACK_TURN) ? WHITE : BLACK;

    if (board[row][col] != 0) {
        return false;
    }
    if (!in_range(row + drow) || !in_range(col + dcol)) {
        return false;
    }

    if (board[row + drow][col + dcol] != enemy_piece ||
        board[row + drow][col + dcol] == 0) {
        return false;
    }

    for (i = row + drow, j = col + dcol;
         in_range(i) && in_range(j) && board[i][j] == enemy_piece;
         i += drow, j += dcol) {
        if (board[i][j] == 0) {
            return false;
        }
    }

    if (!in_range(i) || !in_range(j) || board[i][j] == enemy_piece ||
        board[i][j] == EMPTY) {
        return false;
    }

    return true;
}

bool check_all(board_type board, int row, int col, int turn) {
    return check_direction(board, row, col, -1, -1, turn) ||
           check_direction(board, row, col, -1, 0, turn) ||
           check_direction(board, row, col, -1, 1, turn) ||
           check_direction(board, row, col, 0, -1, turn) ||
           check_direction(board, row, col, 0, 1, turn) ||
           check_direction(board, row, col, 1, -1, turn) ||
           check_direction(board, row, col, 1, 0, turn) ||
           check_direction(board, row, col, 1, 1, turn);
}

void find_legal_moves(board_type board, int turn,
                      board_type legal_moves) {
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            if (check_all(board, i, j, turn)) {
                legal_moves[i][j] = LEGAL;
            }
        }
    }
}

void print_legal_moves(board_type legal_moves, int turn) {
    if (turn == BLACK_TURN) {
        printf("C");
    } else {
        printf("B");
    }

    for (int j = 0; j < DIMENSION; ++j) {
        for (int i = 0; i < DIMENSION; ++i) {
            if (legal_moves[i][j] == LEGAL) {
                printf(" %c%d", 'a' + j, i + 1);
            }
        }
    }
    printf("\n");
}

typedef struct {
    int row, col;
    bool pass;
    bool end_game;
} player_move;

player_move get_move(void) {
    player_move input = {0, 0, false, false};

    int ch = getchar();

    if (ch == EOF) {
        exit(0);
    }

    if (ch == '-') {
        input.pass = true;
        while ((ch = getchar()) != '\n') {
            if (ch == EOF)
                exit(0);
        }
        return input;
    } else if (ch == '=') {
        input.end_game = true;
        return input;
    }

    input.col = ch - 'a';
    ch = getchar();
    if (ch == EOF)
        exit(0);
    input.row = ch - '1';

    while ((ch = getchar()) != '\n') {
        if (ch == EOF)
            exit(0);
    }

    return input;
}

void flip_in_direction(board_type board, int start_row, int start_col,
                       int drow, int dcol, int turn) {
    if (!check_direction(board, start_row, start_col, drow, dcol, turn)) {
        return;
    }

    int enemy_piece = (turn == BLACK_TURN) ? WHITE : BLACK;
    int piece = (turn == BLACK_TURN) ? BLACK : WHITE;
    int i = start_row + drow;
    int j = start_col + dcol;

    while (in_range(i) && in_range(j) && board[i][j] == enemy_piece) {
        board[i][j] = piece;
        i += drow;
        j += dcol;
    }
}

void flip_all(board_type board, int row, int col, int turn) {
    flip_in_direction(board, row, col, -1, -1, turn);
    flip_in_direction(board, row, col, -1, 0, turn);
    flip_in_direction(board, row, col, -1, 1, turn);
    flip_in_direction(board, row, col, 0, -1, turn);
    flip_in_direction(board, row, col, 0, 1, turn);
    flip_in_direction(board, row, col, 1, -1, turn);
    flip_in_direction(board, row, col, 1, 0, turn);
    flip_in_direction(board, row, col, 1, 1, turn);
}

void execute_move(board_type board, player_move input, int *turn) {
    if (input.end_game) {
        exit(0);
    } else if (input.pass) {
        *turn = change_turn(*turn);
        return;
    } else {
        int current_turn = *turn;
        int piece = (current_turn == BLACK_TURN) ? BLACK : WHITE;
        flip_all(board, input.row, input.col, current_turn);
        board[input.row][input.col] = piece;
        *turn = change_turn(*turn);
    }
}

int main(void) {

    board_type board;
    board_type legal_moves;

    initialize_board(board);
    set_initial_state(board);

    int turn = BLACK_TURN;

    while (true) {
        initialize_board(legal_moves);
        find_legal_moves(board, turn, legal_moves);
        print_legal_moves(legal_moves, turn);
        player_move input = get_move();
        execute_move(board, input, &turn);
    }
    return 0;
}
