//
// Created by venkataramana on 09/02/18.
//
/*
 * https://www.interviewbit.com/problems/valid-sudoku/
 * Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
 * The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.
 * The input corresponding to the above configuration :
 * ["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
 * A partially filled sudoku which is valid.
 * Return 0 / 1 ( 0 for false, 1 for true ) for this problem
 * */
#include <stdio.h>

int validate_sudoku(char *sudoku);

int checkRows(const char *sudoku);

int checkCols(char *sudoku);

int checkBox(char *sudoku);

void main() {
    char in_sudoku[9][9];
    for (int i = 0; i < 9; i++)
        scanf("%9s", in_sudoku[i]);
    printf(validate_sudoku(in_sudoku) ? "true" : "false");
}

void printSudoku(char *sudoku) {
    for (int i = 0; i < 9; i++) {
        printf("%d, %.9s\n", i, sudoku);
        sudoku += sizeof(char) * 9;
    }
}

int validate_sudoku(char *sudoku) {
    printSudoku(sudoku);
    return checkRows(sudoku) && checkCols(sudoku) && checkBox(sudoku) ? 1 : 0;
}

int checkRows(const char *sudoku) {
    for (int i = 0; i < 9; ++i) {
        int hash[10] = {0};
        for (int j = 0; j < 9; ++j) {
            printf("%d,%d\n", j, *sudoku - '0');
            if (*sudoku == '.' && sudoku++)
                continue;
            else if (hash[*sudoku - '0'] > 0)
                return 0;
            else hash[*sudoku - '0']++;
            sudoku++;
        }
    }
    return 1;
}

int checkCols(char *sudoku) {
    for (int i = 0; i < 9; ++i) {
        int hash[10] = {0};
        char *cur = sudoku;
        for (int j = 0; j < 9; ++j) {
            printf("%d,%d,%d\n", i, j, *cur - '0');
            if (*cur == '.') {
                cur += 9;
                continue;
            } else if (hash[*cur - '0'] > 0)
                return 0;
            else hash[*cur - '0']++;
            cur += 9;
        }
        sudoku++;
    }
    return 1;
}

int checkBox(char *sudoku) {
    for (int i = 0; i < 9; ++i) {
        if (i != 0 && i % 3 == 0) sudoku += 9 * 2;
        int hash[10] = {0};
        char *cur = sudoku;
        for (int j = 0; j < 9; ++j) {
            if (j != 0 && j % 3 == 0) cur += 6;
            printf("%d,%d,%d\n", i, j, *cur - '0');
            if (*cur == '.' && cur++)
                continue;
            else if (hash[*cur - '0'] > 0)
                return 0;
            else hash[*cur - '0']++;
            cur++;
        }
        sudoku += 3;
    }
    return 1;
}