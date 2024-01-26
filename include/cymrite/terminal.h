#ifndef CYMRITE_HEADER_TERMINAL
	#define CYMRITE_HEADER_TERMINAL

	#include <stdbool.h>
	#include <stddef.h>
	#include <stdio.h>
	#include "./color.h"

typedef struct {
	int row;
	int column;
} cymrite_TerminalPosition;

cymrite_TerminalPosition cymrite_TerminalPosition_create(int row, int column);

void cymrite_initializeTerminal(FILE* input, FILE* output);

void cymrite_terminateTerminal();

void cymrite_setTerminalInputBlocking(bool value);

void cymrite_setTerminalInputEcho(bool value);

void cymrite_setTerminalInputCanonical(bool value);

void cymrite_setTerminalInputSignals(bool value);

void cymrite_setTerminalOutputProcessing(bool value);

void cymrite_setTerminalForegroundColor(cymrite_Color color);

void cymrite_resetTerminalForegroundColor();

void cymrite_setTerminalBackgroundColor(cymrite_Color color);

void cymrite_resetTerminalBackgroundColor();

void cymrite_setTerminalTextBold(bool value);

void cymrite_setTerminalTextItalic(bool value);

void cymrite_setTerminalTextUnderline(bool value);

void cymrite_setTerminalTextBlinking(bool value);

void cymrite_setTerminalColorsSwapped(bool value);

void cymrite_setTerminalTextVisible(bool value);

void cymrite_setTerminalTextStrikethrough(bool value);

void cymrite_resetTerminalStyles();

void cymrite_clearTerminalScreen();

void cymrite_clearTerminalLine();

cymrite_TerminalPosition cymrite_getTerminalCursorPosition();

void cymrite_setTerminalCursorPosition(cymrite_TerminalPosition position);

void cymrite_moveTerminalCursorPosition(cymrite_TerminalPosition difference);

void cymrite_setTerminalCursorVisible(bool value);

void cymrite_setTerminalCursorAlternative(bool value);

void cymrite_setTerminalScreenAlternative(bool value);

cymrite_TerminalPosition cymrite_getTerminalScreenSize();

char cymrite_readTerminalCharacter();

char* cymrite_readTerminalString();

void cymrite_backspaceTerminal(size_t count);

#endif
