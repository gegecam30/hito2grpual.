#include"pch.h"
#include"mapas.h"

char (*mapaActual)[ZONA_ANCHO + 1] = nullptr;

void EstablecerMapaActual(char nuevoMapa[ZONA_ALTO][ZONA_ANCHO + 1]) {
    mapaActual = nuevoMapa;
}

char bienvenida[ZONA_ALTO][ZONA_ANCHO + 1] = {
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                       ********  **     ********    ***    **   ** ******* **   ** ********                            ",
    "                       **    **  **     **         ** **   ***  **    *    ***  ** **                                  ",
    "                       **        **     ****      **   **  **** **    *    **** ** ** *****                            ",
    "                       **    **  **  ** **       ********* ** ****    *    ** **** **    **                            ",
    "                       ********  ****** ******** *       * **  *** ******* **  *** ********                            ",
    "                                                                                                                       ",
    "          ____/-\\___                       ********* **     ** ********                       ____/-\\___              ",
    "        |-------------|                       ***    **     ** **                           |-------------|            ",
    "         | |   |   | |                        ***    ********* ****                          | |   |   | |             ",
    "         | |   O   | |                        ***    **     ** **                            | |   O   | |             ",
    "         | |  /|\\  | |                        ***    **     ** ********                      | |  /|\\  | |             ",
    "         | |   |   | |                                                                       | |   |   | |             ",
    "         | |  / \\  | |              **      ** ********* ********* **     *******            | |  / \\  | |             ",
    "         | |       | |              **      ** **     ** **     ** **     **     **          | |       | |             ",
    "         \\___________/              **      ** **     ** ********* **     **     **          \\___________/             ",
    "                                    **  **  ** **     ** **   **   **     **     **                                    ",
    "                                    ** *  * ** **     ** **     ** **  ** **     **                                    ",
    "                                    ***    *** ********* **     ** ****** *******                                      ",
    "                                                                                                                       ",
    "         O__  |                                                                         O__  |                         ",
    "         |--  |                                                                         |--  |                         ",
    "         |    |                                                                         |    |                         ",
    "        / \\  /|\\                                                                       / \\  /|\\                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       "
};
char mapa1[ZONA_ALTO][ZONA_ANCHO + 1] = {
    "|                         #                  #            #              #             #                              |",
    "|                         #                  #                           #             #                              |",
    "|                         #                                              #             #########                      |",
    "|                         #                                              #                                            |",
    "|                         #                                              #                                            |",
    "|                         #########                       ###            #                                    #       |",
    "|                         #                  ##############              #                                    #       |",
    "|##########################                               #              ####       ###############           #       |",
    "|         #                                               #              #                 #      #           #       |",
    "|         #                                               #                                #      #           #       |",
    "|                                                         #                                #                  #       |",
    "|                                                         #                                #                  ########|",
    "|                         #######                         #                                #                          |",
    "|                         #     #           #################        ###############################                  |",
    "|         #################                        #                            #                                     |",
    "|                         #                        #                            #                                     |",
    "|                         #                        #                            #                                     |",
    "|                         #                        #                            #                                     |",
    "|                         #                        #                            #######################       ########|",
    "|                         #########        ################                     #                     #       #       |",
    "|                         #                #             #           ############                     #       #       |",
    "|#      ###################                #             #           #          #      ######                         |",
    "|               #                          #             #          ##          ########                              |",
    "|               #                          #         #####                                                            |",
    "|               #                                    #                                                                |",
    "|               #                                    #                                       ####                     |",
    "|               #                                    #                                       #                 #      |",
    "|_____________________________________________________________________________________________________________________|"


};
char mapa2[ZONA_ALTO][ZONA_ANCHO + 1] = {
    "                                                                                                       \\   |   /       ",
    "                                                                                                         .-*-.         ",
    "                                                                                                    -   |     |  -     ",
    "                                                                                                         '-*-'         ",
    "                                                                                                       /   |   \\       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "-----------------------------------------------------------------------------------------------------------------------",
    "         _____________                                    _____________                                               ",
    "        /_____________\\                                  /_____________\\                                               ",
    "                                                                                                                       ",
    "                                                                                       ___________________             ",
    "                                                                                      /                   \\            ",
    "                                                                                     /_____________________\\           ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "            ___________________                                                   ___________________                  ",
    "           /___________________\\                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                                                                                                       ",
    "                                           _____________                                                               ",
    "                                          /             \\                                                              ",
    "                                         /_______________\\                                                             "
};
char mapa3[ZONA_ALTO][ZONA_ANCHO + 1] = {
    "                         |                                                                                             ",
    "                         |                                                                           *                 ",
    "                         |                  *                                                       /|\\                ",
    "                         |                 /|\\                                                     /_|_\\               ",
    "                         |                /_|_\\                                                      |                 ",
    "                         |                  |                                                      ~~|~~               ",
    "_________________________|                ~~|~~                                                                        ",
    "                                                                                                                       ",
    "                                                                                         *                             ",
    "                          ~~~                                                           /|\\                            ",
    "                                                                                       /_|_\\                          ",
    "                                                             *                          /|\\                            ",
    "                                                            /|\\                        /_|_\\                           ",
    "                                                           /_|_\\                         |                             ",
    "                                                             |                         ~~|~~                           ",
    "                                  *                        ~~|~~                                                       ",
    "                                 /|\\                                                                                   ",
    "                                /_|_\\                                                                                  ",
    "                                  |                                                                                    ",
    "                                ~~|~~                                                                                  ",
    "                                                                                                                       ",
    "                                                                       *                                *              ",
    "       *                                                              /|\\                              /|\\             ",
    "      /|\\                                                            /_|_\\                            /_|_\\            ",
    "     /_|_\\                                                             |                               /|\\             ",
    "       |                                     ~~~~                    ~~|~~                            /_|_\\            ",
    "     ~~|~~                                                                                              |              ",
    "                                                                                                      ~~|~~            "
};


void DibujarBienvenida() {
    Console::CursorVisible = false;
    Console::SetCursorPosition(0, 0);
    for (int i = 0;i < ZONA_ALTO;i++) {
        for (int j = 0;j < ZONA_ANCHO;j++) {
            if (bienvenida[i][j] == '*') {
                Console::BackgroundColor = ConsoleColor::Red;
                Console::ForegroundColor = ConsoleColor::Red;
                Console::Write("*");
                Console::ForegroundColor = ConsoleColor::White;
                Console::BackgroundColor = ConsoleColor::Black;
            }
            else if (bienvenida[i][j] == '|') {
                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("|");
                Console::ForegroundColor = ConsoleColor::White;
            }
            else if (bienvenida[i][j] == '_') {

                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("_");
                Console::ForegroundColor = ConsoleColor::White;

            }
            else if (bienvenida[i][j] == 'O') {

                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("O");
                Console::ForegroundColor = ConsoleColor::White;

            }
            else if (bienvenida[i][j] == '/') {

                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write("/");
                Console::ForegroundColor = ConsoleColor::White;

            }
            else if (bienvenida[i][j] == '\\') {
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
        Thread::Sleep(20);

    }
    Console::SetCursorPosition(45, 23);
    Console::ForegroundColor = ConsoleColor::White;
    Console::Write("Welcome to the video game");
    Console::ForegroundColor = ConsoleColor::White;
}
void DibujarMapa1() {
    Console::SetCursorPosition(0, 0);
    for (int i = 0;i < ZONA_ALTO;i++) {
        for (int j = 0;j < ZONA_ANCHO;j++) {
            if (mapa1[i][j] == '~') {
                Console::BackgroundColor = ConsoleColor::Blue;
                Console::ForegroundColor = ConsoleColor::DarkBlue;
                Console::Write("~");
            }
            else if (mapa1[i][j] == '|') {
                Console::ForegroundColor = ConsoleColor::White;
                Console::Write("|");
            }
            else if (mapa1[i][j] == '_') {
                Console::BackgroundColor = ConsoleColor::Black;
                Console::ForegroundColor = ConsoleColor::Black;
                Console::Write("_");
            }
            else if (mapa1[i][j] == '*') {
                Console::BackgroundColor = ConsoleColor::Gray;
                Console::ForegroundColor = ConsoleColor::DarkGray;
                Console::Write("*");
            }
            else if (mapa1[i][j] == '#') {
                Console::BackgroundColor = ConsoleColor::Gray;
                Console::ForegroundColor = ConsoleColor::Gray;
                Console::Write("#");
            }
            else {
                Console::BackgroundColor = ConsoleColor::DarkGray;
                Console::Write(" ");
            }
        }
        Console::ResetColor();
        cout << endl;
    }

}
void DibujarMapa2() {
    Console::SetCursorPosition(0, 0);
    for (int i = 0;i < ZONA_ALTO;i++) {
        for (int j = 0;j < ZONA_ANCHO;j++) {
            if (mapa2[i][j] == '/') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("/");
            }
            else if (mapa2[i][j] == '_') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("_");
            }
            else if (mapa2[i][j] == '\\') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("\\");
            }
            else if (mapa2[i][j] == '-') {
                Console::BackgroundColor = ConsoleColor::Yellow;
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("-");
            }
            else if (mapa2[i][j] == '*') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("*");
            }
            else if (mapa2[i][j] == '.') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write(".");
            }
            else if (mapa2[i][j] == '\'') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("'");
            }
            else if (mapa2[i][j] == '|') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("|");
            }
            else {
                Console::BackgroundColor = ConsoleColor::Yellow;
                Console::Write(" ");
            }
        }
        Console::ResetColor();
        cout << endl;
    }
}
void DibujarMapa3() {
    Console::SetCursorPosition(0, 0);
    for (int i = 0;i < ZONA_ALTO;i++) {
        for (int j = 0;j < ZONA_ANCHO;j++) {
            if (mapa3[i][j] == '/') {
                Console::ForegroundColor = ConsoleColor::Green;
                Console::Write("/");
            }
            else if (mapa3[i][j] == '\\') {
                Console::ForegroundColor = ConsoleColor::Green;
                Console::Write("\\");
            }
            else if (mapa3[i][j] == '_') {
                Console::ForegroundColor = ConsoleColor::Green;
                Console::Write("_");
            }
            else if (mapa3[i][j] == '~') {
                Console::ForegroundColor = ConsoleColor::Green;
                Console::Write("~");
            }
            else if (mapa3[i][j] == '|') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("|");
            }
            else if (mapa3[i][j] == '*') {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::Write("*");
            }
            else {
                
                Console::Write(" ");
            }
            Console::ResetColor();
        }
        cout << endl;
    }
}

bool ColisionaPersonaje(int nx, int ny) {
    for (int i = 0; i < ALTO_PJ; ++i) {
        for (int j = 0; j < ANCHO_PJ; ++j) {
            int posX = nx + j;
            int posY = ny + i;

            if (mapaActual[posY][posX] == '#'|| mapaActual[posY][posX] == '~' || mapaActual[posY][posX] == '|' || mapaActual[posY][posX] == '_' ||
                mapaActual[posY][posX] == '*' || mapaActual[posY][posX] == '/' || mapaActual[posY][posX] == '\\' || mapaActual[posY][posX] == '-' ||
                mapaActual[posY][posX] == '.' || mapaActual[posY][posX] == '\'' || mapaActual[posY][posX] == '(' || mapaActual[posY][posX] == ')'||mapaActual[posY][posX]=='w')
                return true;
        }
    }
    return false;
}
bool ColisionaPolicia(int nx, int ny) {
    for (int i = 0; i < ALTO_POLICIA; ++i) {
        for (int j = 0; j < ANCHO_POLICIA + 1; ++j) {
            int posX = nx + j;
            int posY = ny + i;

            if (mapaActual[posY][posX] == '#' || mapaActual[posY][posX] == '~' || mapaActual[posY][posX] == '|' || mapaActual[posY][posX] == '_' ||
                mapaActual[posY][posX] == '*' || mapaActual[posY][posX] == '/' || mapaActual[posY][posX] == '\\' || mapaActual[posY][posX] == '-' ||
                mapaActual[posY][posX] == '.' || mapaActual[posY][posX] == '\'' || mapaActual[posY][posX] == '(' || mapaActual[posY][posX] == ')' || mapaActual[posY][posX] == 'w')
                return true;
        }
    }
    return false;
}