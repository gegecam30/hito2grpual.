#pragma once
#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_

const int FRAMES_PERSONAJE = 4;
struct Personaje {
    int x = 46, y = 7;
    int frameActual = 0;
    int direccion = DERECHA;
    bool enMovimiento = false;
    bool necesitaRedibujar = true;
    int cooldownDisparo = 0;
    char frames[4][FRAMES_PERSONAJE][ALTO_PJ][ANCHO_PJ + 1] = { 
        // Izquierda
        {
            {
                " O_  ",
                "_/\\\\",
                "  /\\ ",
                " /  \\"
            },
            {
                " O_  ",
                "_/\\| ",
                "  /\\ ",
                "  \\ \\"
            },
            {
                " O_  ",
                "\\/\\|",
                "  /\\/",
                "  \\  "
            },
            {
                " O_  ",
                "\\/\\\\ ",
                "  /\\/",
                " /   "
            }
        },
        // Derecha
        {
            {
                "  _O ",
                " //\\_",
                " /\\  ",
                "/  \\ "
            },
            {
                "  _O ",
                " |/\\_",
                " /\\  ",
                "/ /  "
            },
            {
                "  _O ",
                " |/\\/",
                "\\/\\ ",
                "   / "
            },
            {
                "  _O ",
                " //\\/",
                "\\/\\ ",
                "   \\ "
            }
        },
        // Arriba
        {
            {
                "  O  ",
                " /|\\",
                "  |  ",
                " / \\ "
            },
            {
                "  O  ",
                "  \\| ",
                "  |\\ ",
                "  |  "
            },
            {
                "  O  ",
                " \\|/ ",
                "  |  ",
                " \\ / "
            },
            {
                "  O  ",
                "  |/ ",
                " /|  ",
                "  |  "
            }
        },
        // Abajo
        {
            {
                "  O  ",
                " /|\\",
                "  |  ",
                " / \\ "
            },
            {
                "  O  ",
                "  |\\ ",
                " /|  ",
                "  |  "
            },
            {
                "  O  ",
                " \\|/ ",
                "  |  ",
                " \\ / "
            },
            {
                "  O  ",
                "  /| ",
                "  |\\ ",
                "  |  "
            }
        }
    };
};

void SetPersonaje(Personaje*);

void SetBolsa(int*);
int* GetBolsa();

void SetVidas(int*);
int* GetVidas();

void DibujarPersonaje();
void BorrarPersonaje();
void MoverPersonaje(ConsoleKeyInfo);
void DetectarColisionesPP();
void DetectarColisionesPB();

#endif
