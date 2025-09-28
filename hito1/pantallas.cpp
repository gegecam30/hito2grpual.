#include "pch.h"
#include "pantallas.h"


void Winner() {
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(27,11);Console::Write("____    __    ____  __  .__   __. .__   __.  _______ .______      ");
	Console::SetCursorPosition(27,12);Console::Write("\\   \\  /  \\  /   / |  | |  \\ |  | |  \\ |  | |   ____||   _  \\     ");
	Console::SetCursorPosition(27,13);Console::Write(" \\   \\/    \\/   /  |  | |   \\|  | |   \\|  | |  |__   |  |_)  |    ");
	Console::SetCursorPosition(27,14);Console::Write("  \\            /   |  | |  . `  | |  . `  | |   __|  |      /     ");
	Console::SetCursorPosition(27,15);Console::Write("   \\    /\\    /    |  | |  |\\   | |  |\\   | |  |____ |  |\\  \\----.");
	Console::SetCursorPosition(27,16);Console::Write("    \\__/  \\__/     |__| |__| \\__| |__| \\__| |_______|| _| `._____|");
	Console::ResetColor();
	Console::SetCursorPosition(46, 18);Console::Write("Pasaste al siguiente nivel");
}
void winnerf() {
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(27, 11); Console::Write("____    __    ____  __  .__   __. .__   __.  _______ .______      ");
	Console::SetCursorPosition(27, 12); Console::Write("\\   \\  /  \\  /   / |  | |  \\ |  | |  \\ |  | |   ____||   _  \\     ");
	Console::SetCursorPosition(27, 13); Console::Write(" \\   \\/    \\/   /  |  | |   \\|  | |   \\|  | |  |__   |  |_)  |    ");
	Console::SetCursorPosition(27, 14); Console::Write("  \\            /   |  | |  . `  | |  . `  | |   __|  |      /     ");
	Console::SetCursorPosition(27, 15); Console::Write("   \\    /\\    /    |  | |  |\\   | |  |\\   | |  |____ |  |\\  \\----.");
	Console::SetCursorPosition(27, 16); Console::Write("    \\__/  \\__/     |__| |__| \\__| |__| \\__| |_______|| _| `._____|");
	Console::ResetColor();
	Console::SetCursorPosition(39, 18); Console::Write("Gracias por jugar. ¡Hasta la próxima!");
}
void GameOver() {
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(13, 11);Console::Write("  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______      ");
	Console::SetCursorPosition(13, 12);Console::Write(" /  _____|    /   \\     |   \\/   | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \\     ");
	Console::SetCursorPosition(13, 13);Console::Write("|  |  __     /  ^  \\    |  \\  /  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    ");
	Console::SetCursorPosition(13, 14);Console::Write("|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /     ");
	Console::SetCursorPosition(13, 15);Console::Write("|  |__| |  /  _____  \\  |  |  |  | |  |____    |  `--'  |    \\    /    |  |____ |  |\\  \\----.");
	Console::SetCursorPosition(13, 16);Console::Write(" \\______| /__/     \\__\\ |__|  |__| |_______|    \\______/      \\__/     |_______|| _| `._____|");
	Console::ResetColor();
	Console::SetCursorPosition(46, 18);Console::Write("Volviendo al menu principal");
	
}