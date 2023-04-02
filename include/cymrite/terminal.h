#ifndef CYMRITE_TERMINAL_H
#	define CYMRITE_TERMINAL_H

#	include <cymrite/color.h>
#	include <stdbool.h>

void enableRawMode(bool echo = true);

void disableRawMode();

void disableBlockingMode();

void enableBlockingMode();

void enableBold();

void disableBold();

void enableDim();

void disableDim();

void enableItalic();

void disableItalic();

void enableUnderline();

void disableUnderline();

void enableBlink();

void disableBlink();

void enableInverse();

void disableInverse();

void enableInvisible();

void disableInvisible();

void enableStrikethrough();

void disableStrikethrough();

void colorForeground(struct Color color);

void resetForeground();

void colorBackground(struct Color color);

void resetBackground();

void resetStyles();

void clearScreen();

void clearLine();

void hideCursor();

void showCursor();

void saveCursor();

void restoreCursor();

void saveScreen();

void restoreScreen();

void enableAlternative();

void disableAlternative();

#endif
