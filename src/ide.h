#ifndef IDE_H
#define IDE_H

#include "error.h"
#include "keys.h"
#include "utils.h"

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <string.h>

// structs

struct editorConfig {
    int cx, cy; // cursor pos
    int screenrows;
    int screencols;
    struct termios orig_termios;
};

struct abuf {
    char *b;
    int len;
};
#define ABUF_INIT {NULL, 0}

enum editorKey {
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN
};

// datas & signals

void disableRawMode();

void enableRawMode();

// keyboard inputs

void editorMoveCursor(int key);

int editorReadKey();

void editorProcessKeypress();

// term output

void editorRefreshScreen();

void editorDrawRows(struct abuf *ab);

// init term

int getWindowSize(int *rows, int *cols);

int getCursorPosition(int *rows, int *cols);

void initEditor();

// buffer

void abAppend(struct abuf *ab, const char *s, int len);

void abFree(struct abuf *ab);

#endif
