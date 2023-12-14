// Source files includes
#include "error.h"
#include "ide.h"

// LibC includes
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    enableRawMode();
    initEditor();
    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }

    return 0;
}

