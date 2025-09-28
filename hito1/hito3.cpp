#include "pch.h"
#include"mapas.h"
#include"escenarios.h"

char Titulo[ZONA_ALTO][ZONA_ANCHO + 1] = {
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "  ********  **     ********    ***    **   ** ******* **   ** ********                                                 ",
    "  **    **  **     **         ** **   ***  **    *    ***  ** **                                                       ",
    "  **        **     ****      **   **  **** **    *    **** ** ** *****                                                 ",
    "  **    **  **  ** **       ********* ** ****    *    ** **** **    **                                                 ",
    "  ********  ****** ******** *       * **  *** ******* **  *** ********                                                 ",
    "                                                                                                                       ",
    "  ********** *      ** ********                                                                                        ",
    "     ***     **     ** **                                                                                              ",
    "     ***     ********* ****                                                                                            ",
    "     ***     **     ** **                                ____/-\\___                                                   ",
    "     ***     **     ** ********                        |-------------|                                                 ",
    "                                                        | |   |   | |                                                  ",
    "     **      ** ********* ********* **     *******      | |   O   | |                                                  ",
    "     **      ** **     ** **     ** **     **     **    | |  /|\\  | |                                                 ",
    "     **      ** **     ** ********* **     **     **    | |   |   | |                                                  ",
    "     **  **  ** **     ** **   **   **     **     **    | |  / \\  | |                                                 ",
    "     ** *  * ** **     ** **     ** **  ** **     **    | |       | |                                                  ",
    "     ***    *** ********* **     ** ****** *******      \\___________/                                                 ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       "
};
void DibujarTitulo() {
    Console::CursorVisible = false;
    Console::SetCursorPosition(0, 0);
    for (int i = 0; i < ZONA_ALTO; i++) {
        for (int j = 0; j < ZONA_ANCHO; j++) {
            if (Titulo[i][j] == '*') {
                Console::BackgroundColor = ConsoleColor::Red;
                Console::ForegroundColor = ConsoleColor::Red;
                Console::Write("*");
                Console::ForegroundColor = ConsoleColor::White;
                Console::BackgroundColor = ConsoleColor::Black;
            }
            else if (Titulo[i][j] == '|') {
                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("|");
                Console::ForegroundColor = ConsoleColor::White;
            }
            else if (Titulo[i][j] == '_') {

                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("_");
                Console::ForegroundColor = ConsoleColor::White;

            }
            else if (Titulo[i][j] == 'O') {

                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("O");
                Console::ForegroundColor = ConsoleColor::White;

            }
            else if (Titulo[i][j] == '/') {

                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("/");
                Console::ForegroundColor = ConsoleColor::White;

            }
            else if (Titulo[i][j] == '\\') {
                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("\\");
                Console::ForegroundColor = ConsoleColor::White;
            }
            else {
                Console::BackgroundColor = ConsoleColor::Black;
                Console::Write(" ");
            }
        }
        Console::WriteLine();

    }
}
void MostrarInstrucciones() {
    system("cls");
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(34, 0); Console::Write("****************************************************");
    Console::SetCursorPosition(34, 1); Console::Write("*                                                  *");
    Console::SetCursorPosition(34, 2); Console::Write("*            ¡BIENVENIDO A MUNDO BASURA!           *");
    Console::SetCursorPosition(34, 3); Console::Write("*                                                  *");
    Console::SetCursorPosition(34, 4); Console::Write("****************************************************");
    Console::ForegroundColor = ConsoleColor::White;

    Console::SetCursorPosition(34, 6); Console::Write("\t\t>> INSTRUCCIONES DEL JUEGO <<");
    Console::SetCursorPosition(34, 7); Console::Write("   Te encuentras en un mundo donde la limpieza ha sido");
    Console::SetCursorPosition(34, 8); Console::Write("   prohibida en diferentes ecosistemas.");
    Console::SetCursorPosition(34, 9); Console::Write("   Tu misión es clara: ¡Recolecta TODAS las bolsas de");
    Console::SetCursorPosition(34, 10); Console::Write("   basura en cada nivel y limpia el planeta!");

    Console::SetCursorPosition(34, 12); Console::Write("   PERO CUIDADO:");
    Console::SetCursorPosition(34, 13); Console::Write("    - Esquiva obstáculos.");
    Console::SetCursorPosition(34, 14); Console::Write("    - ¡Evita chocar con la policía ambiental corrupta!");
    Console::SetCursorPosition(34, 15); Console::Write("    - Cada choque te quita una vida.");
    Console::SetCursorPosition(34, 16); Console::Write("    - Si pierdes todas tus vidas... GAME OVER. ");

    Console::SetCursorPosition(34, 18); Console::Write("  CONTROLES:");
    Console::SetCursorPosition(34, 19); Console::Write("    Usa las FLECHAS del teclado para mover a tu personaje.");
    Console::SetCursorPosition(34, 20); Console::Write("    -->  Derecha");
    Console::SetCursorPosition(34, 21); Console::Write("    <--  Izquierda");
    Console::SetCursorPosition(34, 22); Console::Write("    /\\   Arriba");
    Console::SetCursorPosition(34, 23); Console::Write("    \\/   Abajo");

    Console::SetCursorPosition(34, 25); Console::Write("    COMPLETA TODOS LOS NIVELES recogiendo los engranajes y");
    Console::SetCursorPosition(34, 26); Console::Write("    conviértete en el mesias del mundo.");

    Console::SetCursorPosition(34, 28); Console::Write(">> Presiona cualquier tecla para comenzar la aventura...");
    _getch();
}
void MiniMenu() {
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(86, 9); Console::Write("======== NIVELES ========");
    Console::SetCursorPosition(86, 11); Console::Write("1. Nivel 1 (por defecto)");
    Console::SetCursorPosition(86, 12); Console::Write("2. Nivel 2");
    Console::SetCursorPosition(86, 13); Console::Write("3. Nivel 3");
    Console::SetCursorPosition(86, 14); Console::Write("0. Regresar");
    Console::SetCursorPosition(86, 16); Console::Write("===========================");
    Console::SetCursorPosition(86, 17); Console::Write("Seleccione un nivel ");
    Console::ResetColor();
}
void MostrarMenu() {
    Console::Clear();
    DibujarTitulo();
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(84, 10); Console::Write("======== MENU ========");
    Console::SetCursorPosition(84, 12); Console::Write("1. Iniciar juego");
    Console::SetCursorPosition(84, 14); Console::Write("2. Niveles");
    Console::SetCursorPosition(84, 16); Console::Write("3. Créditos");
    Console::SetCursorPosition(84, 18); Console::Write("4. Salir");

    Console::ResetColor();
}
void MostrarCreditos() {
    Console::Clear();
    DibujarTitulo();
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(80, 9); Console::Write("========== CREDITOS ==========");
    Console::SetCursorPosition(80, 11); Console::Write("Proyecto desarrollado por:");
    Console::SetCursorPosition(80, 12); Console::Write("-Ryusei Murakami Tamashiro");
    Console::SetCursorPosition(80, 13); Console::Write("-Oswaldo Farfan Flores");
    Console::SetCursorPosition(80, 14); Console::Write("-Gengis Cam Pizarro");
    Console::SetCursorPosition(80, 16); Console::Write("=============================");
    Console::SetCursorPosition(80, 17); Console::Write("Presiona una tecla para volver al menu...");
    Console::ReadKey();
}

int main() {
    Console::CursorVisible = false;

    Console::Clear();
    DibujarBienvenida();
    Thread::Sleep(1000);

    Console::Clear();
    MostrarInstrucciones();

    bool regresarAlMenu = false;
    int opcion = 0;
    int opcion2 = 1;

    do {
        Console::Clear();
        MostrarMenu();

        do {
            Console::SetCursorPosition(84, 20);
            Console::ForegroundColor = ConsoleColor::Cyan;
            cout << "Seleccione una opcion(1-4)  ";
            // Espera una tecla sin presionar Enter
            ConsoleKeyInfo keyInfo = Console::ReadKey(true);
            switch (keyInfo.Key) {
            case ConsoleKey::D1:
            case ConsoleKey::NumPad1:
                opcion = 1;
                break;
            case ConsoleKey::D2:
            case ConsoleKey::NumPad2:
                opcion = 2;
                break;
            case ConsoleKey::D3:
            case ConsoleKey::NumPad3:
                opcion = 3;
                break;
            case ConsoleKey::D4:
            case ConsoleKey::NumPad4:
                opcion = 4;
                break;
            default:
                opcion = 0;
            }
            Console::ResetColor();
        } while (opcion < 1 || opcion > 4);

        switch (opcion) {

        case 1:
            switch (opcion2) {
            case 1:
                InicializarPersonaje1();
                EjecutarEscenario1(regresarAlMenu);
                break;
            case 2:
                InicializarPersonaje2();
                EjecutarEscenario2(regresarAlMenu);
                break;
            case 3:
                InicializarPersonaje3();
                EjecutarEscenario3(regresarAlMenu);
                break;
            default:
                InicializarPersonaje1();
                EjecutarEscenario1(regresarAlMenu);
                break;
            }

            if (regresarAlMenu) {
                regresarAlMenu = false;
                continue;
            }
            break;

        case 2: {
            Console::Clear();
            DibujarTitulo();
            MiniMenu();

            ConsoleKeyInfo keyInfo = Console::ReadKey(true);
            switch (keyInfo.Key) {
            case ConsoleKey::D1:
            case ConsoleKey::NumPad1:
                opcion2 = 1;
                break;
            case ConsoleKey::D2:
            case ConsoleKey::NumPad2:
                opcion2 = 2;
                break;
            case ConsoleKey::D3:
            case ConsoleKey::NumPad3:
                opcion2 = 3;
                break;
            case ConsoleKey::D4:
            case ConsoleKey::NumPad4:
                opcion2 = 4;
                break;
            case ConsoleKey::D5:
            case ConsoleKey::NumPad5:
                opcion2 = 5;
                break;
            case ConsoleKey::D0:
            case ConsoleKey::NumPad0:
                opcion2 = 0;
                break;
            default:
                opcion2 = 0;
            }

            Console::ResetColor();

            if (opcion2 == 0) {
                continue;
            }

            break;
        }

        case 3:
            MostrarCreditos();
            break;

        case 4:
            break;
        }

    } while (opcion != 4);

    Console::Clear();
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(40, 14);
    Console::Write("Gracias por jugar. ¡Hasta la próxima!");
    Console::ReadKey();
    return 0;
}
