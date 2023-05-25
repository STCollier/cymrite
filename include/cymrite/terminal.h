#ifndef CYMRITE_HEADER_TERMINAL
#define CYMRITE_HEADER_TERMINAL

#include <cymrite/color.h>
#include <stdbool.h>
#include <termios.h>

typedef struct {
	struct termios cookedMode;
	int blockingMode;

	bool blocking;
	bool echo;
	bool canonical;
	bool signals;
	bool processing;

	bool locked;
} cymrite_TerminalMode;

cymrite_TerminalMode cymrite_TerminalMode_create();

void cymrite_TerminalMode_delete(cymrite_TerminalMode* terminalMode);

void cymrite_TerminalMode_setBlocking(cymrite_TerminalMode* terminalMode, bool value);

void cymrite_TerminalMode_setEcho(cymrite_TerminalMode* terminalMode, bool value);

void cymrite_TerminalMode_setCanonical(cymrite_TerminalMode* terminalMode, bool value);

void cymrite_TerminalMode_setSignals(cymrite_TerminalMode* terminalMode, bool value);

void cymrite_TerminalMode_setProcessing(cymrite_TerminalMode* terminalMode, bool value);

void cymrite_TerminalMode_lock(cymrite_TerminalMode* terminalMode);

void cymrite_TerminalMode_unlock(cymrite_TerminalMode* terminalMode);

void cymrite_setBoldText(bool value);

void cymrite_setDimText(bool value);

void cymrite_setItalicText(bool value);

void cymrite_setUnderlineText(bool value);

void cymrite_setBlinkText(bool value);

void cymrite_setInverseText(bool value);

void cymrite_setInvisibleText(bool value);

void cymrite_setStrikethroughText(bool value);

void cymrite_setForegroundColor(cymrite_Color color);

void cymrite_resetForegroundColor();

void cymrite_setBackgroundColor(cymrite_Color color);

void cymrite_resetBackgroundColor();

void cymrite_resetStyle();

void cymrite_clearScreen();

void cymrite_clearLine();

void cymrite_setInvisibleCursor(bool value);

void cymrite_setAlternativeCursor(bool value);

void cymrite_setAlternativeScreen(bool value);

#endif // CYMRITE_HEADER_TERMINAL
