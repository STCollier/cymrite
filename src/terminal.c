#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "../include/cymrite/color.h"
#include "../include/cymrite/terminal.h"

static FILE* cymrite_terminalInput;
static FILE* cymrite_terminalOutput;
static int cymrite_terminalInputDescriptor;

static int cymrite_terminalInputBlockingStatus;
static struct termios cymrite_terminalInputCookedMode;

static bool cymrite_terminalInputBlocking;
static bool cymrite_terminalInputEcho;
static bool cymrite_terminalInputCanonical;
static bool cymrite_terminalInputSignals;
static bool cymrite_terminalOutputProcessing;

static void cymrite_updateTerminal() {
	fcntl(cymrite_terminalInputDescriptor, F_SETFL, cymrite_terminalInputBlockingStatus | (O_NONBLOCK * !cymrite_terminalInputBlocking));
	struct termios rawMode = cymrite_terminalInputCookedMode;
	rawMode.c_iflag &= ~((ICRNL * !cymrite_terminalInputSignals) | (IXON * !cymrite_terminalInputSignals));
	rawMode.c_lflag &= ~((ECHO * !cymrite_terminalInputEcho) | (ICANON * !cymrite_terminalInputCanonical) | (IEXTEN * !cymrite_terminalInputSignals) | (ISIG * !cymrite_terminalInputSignals));
	rawMode.c_oflag &= ~(OPOST * !cymrite_terminalOutputProcessing);
	tcsetattr(cymrite_terminalInputDescriptor, TCSANOW, &rawMode);
}

cymrite_TerminalPosition cymrite_TerminalPosition_create(const int row, const int column) {
	cymrite_TerminalPosition position;
	position.row = row;
	position.column = column;
	return position;
}

void cymrite_initializeTerminal(FILE* input, FILE* output) {
	cymrite_terminalInput = input;
	cymrite_terminalOutput = output;
	cymrite_terminalInputDescriptor = fileno(input);
	cymrite_terminalInputBlockingStatus = fcntl(cymrite_terminalInputDescriptor, F_GETFL);
	tcgetattr(cymrite_terminalInputDescriptor, &cymrite_terminalInputCookedMode);
	cymrite_terminalInputBlocking = true;
	cymrite_terminalInputEcho = true;
	cymrite_terminalInputCanonical = true;
	cymrite_terminalInputSignals = true;
	cymrite_terminalOutputProcessing = true;
	cymrite_updateTerminal();
}

void cymrite_terminateTerminal() {
	fcntl(cymrite_terminalInputDescriptor, F_SETFL, cymrite_terminalInputBlockingStatus);
	tcsetattr(cymrite_terminalInputDescriptor, TCSANOW, &cymrite_terminalInputCookedMode);
	cymrite_resetTerminalStyles();
}

void cymrite_setTerminalInputBlocking(const bool value) {
	if (cymrite_terminalInputBlocking != value) {
		cymrite_terminalInputBlocking = value;
		cymrite_updateTerminal();
	}
}

void cymrite_setTerminalInputEcho(const bool value) {
	if (cymrite_terminalInputEcho != value) {
		cymrite_terminalInputEcho = value;
		cymrite_updateTerminal();
	}
}

void cymrite_setTerminalInputCanonical(const bool value) {
	if (cymrite_terminalInputCanonical != value) {
		cymrite_terminalInputCanonical = value;
		cymrite_updateTerminal();
	}
}

void cymrite_setTerminalInputSignals(const bool value) {
	if (cymrite_terminalInputSignals != value) {
		cymrite_terminalInputSignals = value;
		cymrite_updateTerminal();
	}
}

void cymrite_setTerminalOutputProcessing(const bool value) {
	if (cymrite_terminalOutputProcessing != value) {
		cymrite_terminalOutputProcessing = value;
		cymrite_updateTerminal();
	}
}

void cymrite_setTerminalForegroundColor(const cymrite_Color color) {
	fprintf(cymrite_terminalOutput, "\x1B[38;2;%i;%i;%im", color.red, color.green, color.blue);
}

void cymrite_resetTerminalForegroundColor() {
	fprintf(cymrite_terminalOutput, "\x1B[38m");
}

void cymrite_setTerminalBackgroundColor(const cymrite_Color color) {
	fprintf(cymrite_terminalOutput, "\x1B[48;2;%i;%i;%im", color.red, color.green, color.blue);
}

void cymrite_resetTerminalBackgroundColor() {
	fprintf(cymrite_terminalOutput, "\x1B[48m");
}

void cymrite_setTerminalTextBold(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[%im", 21 - value * 20);
}

void cymrite_setTerminalTextItalic(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[%im", 23 - value * 20);
}

void cymrite_setTerminalTextUnderline(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[%im", 24 - value * 20);
}

void cymrite_setTerminalTextBlinking(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[%im", 25 - value * 20);
}

void cymrite_setTerminalColorsSwapped(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[%im", 27 - value * 20);
}

void cymrite_setTerminalTextVisible(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[%im", 8 + value * 20);
}

void cymrite_setTerminalTextStrikethrough(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[%im", 29 - value * 20);
}

void cymrite_resetTerminalStyles() {
	fprintf(cymrite_terminalOutput, "\x1B[0m");
}

void cymrite_clearTerminalScreen() {
	fprintf(cymrite_terminalOutput, "\x1B[2J");
}

void cymrite_clearTerminalLine() {
	fprintf(cymrite_terminalOutput, "\x1B[2K");
}

cymrite_TerminalPosition cymrite_getTerminalCursorPosition() {
	const bool canonical = cymrite_terminalInputCanonical;
	cymrite_setTerminalInputCanonical(false);
	fprintf(cymrite_terminalOutput, "\x1B[6n");
	cymrite_TerminalPosition position;
	fscanf(cymrite_terminalInput, "\x1B[%i;%iR", &position.row, &position.column);
	cymrite_setTerminalInputCanonical(canonical);
	return cymrite_TerminalPosition_create(position.row - 1, position.column - 1);
}

void cymrite_setTerminalCursorPosition(const cymrite_TerminalPosition position) {
	fprintf(cymrite_terminalOutput, "\x1B[%i;%iH", position.row + 1, position.column + 1);
}

void cymrite_moveTerminalCursorPosition(const cymrite_TerminalPosition difference) {
	if (difference.row) {
		fprintf(cymrite_terminalOutput, "\x1B[%i%c", abs(difference.row), "CD"[difference.row < 0]);
	}
	if (difference.column) {
		fprintf(cymrite_terminalOutput, "\x1B[%i%c", abs(difference.column), "BA"[difference.column < 0]);
	}
}

void cymrite_setTerminalCursorVisible(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[?25%c", "lh"[value]);
}

void cymrite_setTerminalCursorAlternative(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[ %i", 8 - value);
}

void cymrite_setTerminalScreenAlternative(const bool value) {
	fprintf(cymrite_terminalOutput, "\x1B[?47%c", "lh"[value]);
}

cymrite_TerminalPosition cymrite_getTerminalScreenSize() {
	struct winsize size;
	ioctl(cymrite_terminalInputDescriptor, TIOCGWINSZ, &size);
	return cymrite_TerminalPosition_create(size.ws_row, size.ws_col);
}

char cymrite_readTerminalCharacter() {
	const bool blocking = cymrite_terminalInputBlocking;
	const bool canonical = cymrite_terminalInputCanonical;
	cymrite_setTerminalInputBlocking(false);
	cymrite_setTerminalInputCanonical(false);
	const char input = fgetc(cymrite_terminalInput);
	cymrite_setTerminalInputBlocking(blocking);
	cymrite_setTerminalInputCanonical(canonical);
	return input;
}

char* cymrite_readTerminalString() {
	const bool blocking = cymrite_terminalInputBlocking;
	const bool canonical = cymrite_terminalInputCanonical;
	cymrite_setTerminalInputBlocking(false);
	cymrite_setTerminalInputCanonical(false);
	size_t chunkSize = 4096;
	size_t inputSize = 0;
	char* input = malloc(chunkSize);
	while (true) {
		const size_t bytesRead = fread(input + inputSize, sizeof(char), chunkSize, cymrite_terminalInput);
		if (bytesRead == chunkSize) {
			inputSize += chunkSize;
			chunkSize *= 2;
			input = realloc(input, inputSize + chunkSize);
		} else {
			input[inputSize + bytesRead] = '\0';
			break;
		}
	}
	cymrite_setTerminalInputBlocking(blocking);
	cymrite_setTerminalInputCanonical(canonical);
	return input;
	// TODO: return a structure containing both the resulting string and `inputSize` in case of null-bytes
}

void cymrite_backspaceTerminal(const size_t count) {
	if (count) {
		char spaces[count];
		memset(spaces, ' ', count);
		fprintf(cymrite_terminalOutput, "\x1B[%iD%s\x1B[%iD", count, spaces, count);
	}
}
