#include <cymrite/color.h>
#include <cymrite/terminal.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

cymrite_TerminalMode cymrite_TerminalMode_create() {
	cymrite_TerminalMode terminalMode;
	tcgetattr(STDIN_FILENO, &terminalMode.cookedMode);
	terminalMode.blockingMode = fcntl(STDIN_FILENO, F_GETFL);
	terminalMode.blocking = true;
	terminalMode.echo = false;
	terminalMode.canonical = false;
	terminalMode.signals = false;
	terminalMode.processing = false;
	cymrite_TerminalMode_lock(&terminalMode);
	return terminalMode;
}

void cymrite_TerminalMode_delete(const cymrite_TerminalMode terminalMode) {
	cymrite_TerminalMode_unlock(&terminalMode);
}

void cymrite_TerminalMode_setBlocking(cymrite_TerminalMode* terminalMode, const bool value) {
	terminalMode->blocking = value;
	if (terminalMode->locked) {
		terminalMode = cymrite_TerminalMode_lock(terminalMode);
	}
	return terminalMode;
}

void cymrite_TerminalMode_setEcho(cymrite_TerminalMode* terminalMode, const bool value) {
	terminalMode->echo = value;
	if (terminalMode->locked) {
		terminalMode = cymrite_TerminalMode_lock(terminalMode);
	}
	return terminalMode;
}

void cymrite_TerminalMode_setCanonical(cymrite_TerminalMode* terminalMode, const bool value) {
	terminalMode->canonical = value;
	if (terminalMode->locked) {
		terminalMode = cymrite_TerminalMode_lock(terminalMode);
	}
	return terminalMode;
}

void cymrite_TerminalMode_setSignals(cymrite_TerminalMode* terminalMode, const bool value) {
	terminalMode->signals = value;
	if (terminalMode->locked) {
		terminalMode = cymrite_TerminalMode_lock(terminalMode);
	}
	return terminalMode;
}

void cymrite_TerminalMode_setProcessing(cymrite_TerminalMode* terminalMode, const bool value) {
	terminalMode->processing = value;
	if (terminalMode->locked) {
		terminalMode = cymrite_TerminalMode_lock(terminalMode);
	}
	return terminalMode;
}

void cymrite_TerminalMode_lock(cymrite_TerminalMode* terminalMode) {
	struct termios rawMode = terminalMode->cookedMode;
	rawMode.c_iflag &= ~((ICRNL * !terminalMode->signals) | (IXON * !terminalMode->signals));
	rawMode.c_lflag &= ~((ECHO * !terminalMode->echo) | (ICANON * !terminalMode->canonical) | (IEXTEN * !terminalMode->signals) | (ISIG * !terminalMode->signals));
	rawMode.c_oflag &= ~(OPOST * !terminalMode->processing);
	tcsetattr(STDIN_FILENO, TCSANOW, &rawMode);
	fcntl(STDIN_FILENO, F_SETFL, terminalMode->blockingMode | (O_NONBLOCK * !terminalMode->blocking));
	terminalMode->locked = true;
}

void cymrite_TerminalMode_unlock(cymrite_TerminalMode* terminalMode) {
	tcsetattr(STDIN_FILENO, TCSANOW, &terminalMode->cookedMode);
	fcntl(STDIN_FILENO, F_SETFL, terminalMode->blockingMode);
	terminalMode.locked = false;
}

void cymrite_setBoldText(const bool value) {
	printf(value ? "\u001b[1m" : "\u001b[21m");
}

void cymrite_setDimText(const bool value) {
	printf(value ? "\u001b[2m" : "\u001b[22m");
}

void cymrite_setItalicText(const bool value) {
	printf(value ? "\u001b[3m" : "\u001b[23m");
}

void cymrite_setUnderlineText(const bool value) {
	printf(value ? "\u001b[4m" : "\u001b[24m");
}

void cymrite_setBlinkText(const bool value) {
	printf(value ? "\u001b[5m" : "\u001b[25m");
}

void cymrite_setInverseText(const bool value) {
	printf(value ? "\u001b[7m" : "\u001b[27m");
}

void cymrite_setInvisibleText(const bool value) {
	printf(!value ? "\u001b[8m" : "\u001b[28m");
}

void cymrite_setStrikethroughText(const bool value) {
	printf(value ? "\u001b[9m" : "\u001b[29m");
}

void cymrite_setForegroundColor(cymrite_Color color) {
	printf("\u001b[38;2;%i;%i;%im", color.red, color.green, color.blue);
}

void cymrite_resetForegroundColor(const bool value) {
	printf("\u001b[38m");
}

void cymrite_setBackgroundColor(cymrite_Color color) {
	printf("\u001b[48;2;%i;%i;%im", color.red, color.green, color.blue);
}

void cymrite_resetBackgroundColor(const bool value) {
	printf("\u001b[48m");
}

void cymrite_resetStyle(const bool value) {
	printf("\u001b[0m");
}

void cymrite_clearScreen(const bool value) {
	printf("\u001b[2J");
}

void cymrite_clearLine(const bool value) {
	printf("\u001b[2K"); 
}

void cymrite_setInvisibleCursor(const bool value) {
	printf(!value ? "\u001b[?25h" : "\u001b[?25l");
}

void cymrite_setAlternativeCursor(const bool value) {
	printf(value ? "\u001b[s" : "\u001b[u");
}

void cymrite_setAlternativeScreen(const bool value) {
	printf(value ? "\u001b[?47h" : "\u001b[?47l");
}
