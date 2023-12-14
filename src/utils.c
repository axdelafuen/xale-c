#include "utils.h"

int intLen(int n) {
    int count = 0;

    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }
    
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}
