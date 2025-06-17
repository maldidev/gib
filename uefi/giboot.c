#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

char* options[3] = {
    "Start Kernel in normal mode",
    "Boot into memtest+",
    "GibCore Firmware Settings"
};

int main(void) {
    char c;
    puts("GiBoot bootloader");
    for (int i = 0; i < 3; i++) {
        printf(" %d.\t%s\n", i+1, options[i]);
    }
    fputs("\nChoose an option: ", stdout);
    do {
        c = getchar();
        if (c == '1') {
            // Already to shell in OS (do not run in kernel-mode!)
            system("./gibsh");
        }
        else if (c == '2') {
            // Already to memtest in OS (do not run in kernel-mode!)
            system("./memtest");
        }
        else if (c == '3') {
            // Already to firmware in OS (do not run in kernel-mode!)
            system("./firmware");
        }
    } while ((c < '1') || (c > '3'));
    puts("\b");
    return 0;
}