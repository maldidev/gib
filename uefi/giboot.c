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

char* programs[3] = {
  "./gibsh",
  "./memtest",
  "./firmware"
};

int main(void) {
  struct termios a,b;
  tcgetattr(STDIN_FILENO, &a);
  memcpy(&b, &a, sizeof(struct termios));
  b.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &b);

  printf("\033[H\033[2J");
  char c,ch;
  ch=0;
  fputs("\nChoose an option: ", stdout);
  while (1) {
    puts("\033[H\033[30m\033[48;5;250m\033[K    GiBoot bootloader\n\033[0mChoose an option by using arrow keys");
    for (int i = 0; i < 3; i++) {
      printf((i==ch)?"\033[47m\033[K\033[0m    \033[47m\033[30m%s\033[160C\033[3D\033[0m    \n":"\033[0m\033[K    %s\n", options[i]);
    }
    c = getchar();
    if (c == '\033') { getchar(); c = getchar();
      if (c == 'A') {
        ch = (ch - 1) % 3;
      }
      if (c == 'B') {
        ch = (ch + 1) % 3;
      }
    }
    else if (c == '\n') {
      tcsetattr(STDIN_FILENO, TCSANOW, &a);
      system(programs[ch]);
    }
  }
  puts("\b");
  tcsetattr(STDIN_FILENO, TCSANOW, &a);
  return 0;
}
