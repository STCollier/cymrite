#include <cymrite/color.h>
#include <cymrite/terminal.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

struct termios cookedMode;
int blockingMode;

void enableRawMode(const bool echo) {
	tcgetattr(STDIN_FILENO, &cookedMode);
	struct termios rawMode = cookedMode;
	cfmakeraw(&rawMode);
	rawMode.c_lflag |= ECHO * echo;
	tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
}

void disableRawMode() {
	tcsetattr(STDIN_FILENO, TCSANOW, &cookedMode);
}

void disableBlockingMode() {
	blockingMode = fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, blockingMode | O_NONBLOCK);
}

void enableBlockingMode() {
	fcntl(STDIN_FILENO, F_SETFL, blockingMode);
}

void enableBold() {
	printf("\x1b[1m");
}

void disableBold() {
	printf("\x1b[21m");
}

void enableDim() {
	printf("\x1b[2m");
}

void disableDim() {
	printf("\x1b[22m");
}

void enableItalic() {
	printf("\x1b[3m");
}

void disableItalic() {
	printf("\x1b[23m");
}

void enableUnderline() {
	printf("\x1b[4m");
}

void disableUnderline() {
	printf("\x1b[24m");
}

void enableBlink() {
	printf("\x1b[5m");
}

void disableBlink() {
	printf("\x1b[25m");
}

void enableInverse() {
	printf("\x1b[6m");
}

void disableInverse() {
	printf("\x1b[26m");
}

void enableInvisible() {
	printf("\x1b[7m");
}

void disableInvisible() {
	printf("\x1b[27m");
}

void enableStrikethrough() {
	printf("\x1b[8m");
}

void disableStrikethrough() {
	printf("\x1b[28m");
}

void colorForeground(struct Color color) {
	printf("\x1b[38;2;%u;%u;%um", color.red, color.green, color.blue);
}

void resetForeground() {
	printf("\x1b[38m");
}

void colorBackground(struct Color color) {
	printf("\x1b[48;2;%u;%u;%um", color.red, color.green, color.blue);
}

void resetBackground() {
	printf("\x1b[48m");
}

void resetStyles() {
	printf("\x1b[0m");
}

void clearScreen() {
	printf("\x1b[2J");
}

void clearLine() {
	printf("\x1b[2K");
}

void hideCursor() {
	printf("\x1b[?25l");
}

void showCursor() {
	printf("\x1b[?25h");
}

void saveCursor() {
	printf("\x1b[s");
}

void restoreCursor() {
	printf("\x1b[u");
}

void saveScreen() {
	printf("\x1b[?47h");
}

void restoreScreen() {
	printf("\x1b[?47l");
}

void enableAlternative() {
	printf("\x1b[?1049h");
}

void disableAlternative() {
	printf("\x1b[?1049l");
}
