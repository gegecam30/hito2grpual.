#include "pch.h"
#include "mapas.h"
#include "escenarios.h"
#include "policias.h"
#include "personaje.h"
#include "bolsasbasura.h"
#include "pantallas.h"

Personaje pj;               
int NumVidas = 3;
int NumBolsaInicial = 0;

void PanelDeEstado1() {
    Console::ForegroundColor = ConsoleColor::Black;
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0);Console::Write("__________________________");
    Console::SetCursorPosition(0, 1);Console::Write("|   ESTADO DEL JUGADOR   |");
    Console::SetCursorPosition(0, 2);Console::Write("|------------------------|");
    Console::SetCursorPosition(0, 3);Console::Write("|   VIDAS  : ");Console::Write(*GetVidas());
    Console::Write("           |");
    Console::SetCursorPosition(0, 4);Console::Write("|   ENGRANAJES: ");Console::Write(*GetBolsa());Console::Write("/6");
    Console::Write("          |");
    Console::SetCursorPosition(0, 5);Console::Write("|   NIVEL  : 1           |");
    Console::SetCursorPosition(0, 6);Console::Write("|________________________|");
    Console::ResetColor();
}
void PanelDeEstado2() {
    Console::ForegroundColor = ConsoleColor::Black;
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0);Console::Write("__________________________");
    Console::SetCursorPosition(0, 1);Console::Write("|   ESTADO DEL JUGADOR   |");
    Console::SetCursorPosition(0, 2);Console::Write("|------------------------|");
    Console::SetCursorPosition(0, 3);Console::Write("|   VIDAS  : ");Console::Write(*GetVidas());
    Console::Write("           |");
    Console::SetCursorPosition(0, 4);Console::Write("|   ENGRANAJES: ");Console::Write(*GetBolsa());Console::Write("/5");
    Console::Write("           |");
    Console::SetCursorPosition(0, 5);Console::Write("|   NIVEL  : 2           |");
    Console::SetCursorPosition(0, 6);Console::Write("|________________________|");
    Console::ResetColor();
}
void PanelDeEstado3() {
    Console::ForegroundColor = ConsoleColor::Black;
    Console::BackgroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 0);Console::Write("__________________________");
    Console::SetCursorPosition(0, 1);Console::Write("|   ESTADO DEL JUGADOR   |");
    Console::SetCursorPosition(0, 2);Console::Write("|------------------------|");
    Console::SetCursorPosition(0, 3);Console::Write("|   VIDAS  : ");Console::Write(*GetVidas());
    Console::Write("           |");
    Console::SetCursorPosition(0, 4);Console::Write("|   ENGRANAJES: ");Console::Write(*GetBolsa());Console::Write("/6");
    Console::Write("           |");
    Console::SetCursorPosition(0, 5);Console::Write("|   NIVEL  : 3           |");
    Console::SetCursorPosition(0, 6);Console::Write("|________________________|");
    Console::ResetColor();
}

void InicializarPersonaje1() {
    NumBolsaInicial = 0;
    NumVidas = 3;
    pj.x = 46;
    pj.y = 7;
    pj.frameActual = 0;
    pj.direccion = DERECHA;
    pj.necesitaRedibujar = true;

    SetPersonaje(&pj);
    SetVidas(&NumVidas);
}
void InicializarPersonaje2() {
    NumBolsaInicial = 0;
    NumVidas = 3;
    pj.x = 30;
    pj.y = 9;
    pj.frameActual = 0;
    pj.direccion = DERECHA;
    pj.necesitaRedibujar = true;
    SetPersonaje(&pj);
}
void InicializarPersonaje3() {
    NumBolsaInicial = 0;
    NumVidas = 3;
    pj.x = 60;
    pj.y = 2;
    pj.frameActual = 0;
    pj.direccion = DERECHA;
    pj.necesitaRedibujar = true;
    SetPersonaje(&pj);
}


void DibujarZonaSegura() {
    for (int i = 0; i <= ZONA_ANCHO; i++) {
        Console::BackgroundColor = ConsoleColor::White;
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(i, 0);
        Console::Write("-");
        Console::SetCursorPosition(i, ZONA_ALTO);
        Console::Write("-");
        Console::ResetColor();
    }
    for (int j = 0; j <= ZONA_ALTO; j++) {
        Console::BackgroundColor = ConsoleColor::White;
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(0, j);
        Console::Write("|");
        Console::SetCursorPosition(ZONA_ANCHO, j);
        Console::Write("|");
        Console::ResetColor();
    }
}
void EjecutarEscenario1(bool &regresarAlMenu) {

    Console::CursorVisible = false;
    Console::Clear();

    SetVidas(&NumVidas);
    SetBolsa(&NumBolsaInicial);

    pj.necesitaRedibujar = true;
    EstablecerMapaActual(mapa1);
    DibujarMapa1();
    DibujarZonaSegura();
    InicializarPolicias1();
    InicializarBolsas();
    

    int altoConsola = Console::WindowHeight;
    Console::SetCursorPosition(0, altoConsola - 1);
    Console::Write("ESC = Regresa al menu principal");

    bool pasarAlSiguiente = false;

    while (true) {
        PanelDeEstado1();
        if (Console::KeyAvailable) {
            ConsoleKeyInfo keyInfo = Console::ReadKey(true);
            ConsoleKey tecla = keyInfo.Key;

            if (tecla == ConsoleKey::Escape) {
                regresarAlMenu = true;
                break;
            }
            if (*GetVidas() == 0) {
                GameOver();
                _sleep(3000);
                regresarAlMenu = true;
                break;
            }
            if (*GetBolsa() == 6) {
                Winner();
                _sleep(3000);
                pasarAlSiguiente = true;
                break;
            }
            bool debeAnimar = false;


            switch (tecla) {
            case ConsoleKey::LeftArrow:
            case ConsoleKey::RightArrow:
            case ConsoleKey::UpArrow:
            case ConsoleKey::DownArrow:
                MoverPersonaje(keyInfo);
                break;

            case ConsoleKey::Escape:
                break;
            }
        }

        if (pj.necesitaRedibujar)
            DibujarPersonaje();
        DibujarBolsas1();
        MoverPolicias(true);
        DetectarColisionesPB();
        DetectarColisionesPP();
        Thread::Sleep(100);
    }
    if (pasarAlSiguiente && !regresarAlMenu) {
        InicializarPersonaje2();
        EjecutarEscenario2(regresarAlMenu);
    }
}
void EjecutarEscenario2(bool& regresarAlMenu) {
    Console::CursorVisible = false;
    Console::Clear();

    SetVidas(&NumVidas);
    SetBolsa(&NumBolsaInicial);

    pj.necesitaRedibujar = true;
    EstablecerMapaActual(mapa2);
    
    DibujarMapa2();
    DibujarZonaSegura();
    InicializarPolicias2();
    InicializarBolsas();

    int altoConsola = Console::WindowHeight;
    Console::SetCursorPosition(0, altoConsola - 1);
    Console::Write("ESC = Regresa al menu principal");

    bool pasarAlSiguiente = false;

    while (true) {
        PanelDeEstado2();
        if (Console::KeyAvailable) {
            ConsoleKeyInfo keyInfo = Console::ReadKey(true);
            ConsoleKey tecla = keyInfo.Key;

            if (tecla == ConsoleKey::Escape) {
                regresarAlMenu = true;
                break;
            }
            if (*GetVidas() == 0) {
                GameOver();
                _sleep(3000);
                regresarAlMenu = true;
                break;
            }
            if (*GetBolsa() == 5) {
                Winner();
                _sleep(3000);
                pasarAlSiguiente = true;
                break;
            }
            bool debeAnimar = false;


            switch (tecla) {
            case ConsoleKey::LeftArrow:
            case ConsoleKey::RightArrow:
            case ConsoleKey::UpArrow:
            case ConsoleKey::DownArrow:
                MoverPersonaje(keyInfo);
                break;

            case ConsoleKey::Escape:
                break;
            }
        }
        if (pj.necesitaRedibujar)
            DibujarPersonaje();
        DibujarBolsas2();
        MoverPolicias(true);
        DetectarColisionesPB();
        DetectarColisionesPP();
        Thread::Sleep(100);
    }
    if (pasarAlSiguiente && !regresarAlMenu) {
        InicializarPersonaje3();
        EjecutarEscenario3(regresarAlMenu);
    }
}
void EjecutarEscenario3(bool& regresarAlMenu) {
    Console::CursorVisible = false;
    Console::Clear();

    SetVidas(&NumVidas);
    SetBolsa(&NumBolsaInicial);

    pj.necesitaRedibujar = true;
    EstablecerMapaActual(mapa3);
    
    DibujarMapa3();
    DibujarZonaSegura();
    InicializarPolicias3();
    InicializarBolsas();

    int altoConsola = Console::WindowHeight;
    Console::SetCursorPosition(0, altoConsola - 1);
    Console::Write("ESC = Regresa al menu principal");

    bool pasarAlSiguiente = false;

    while (true) {
        PanelDeEstado3();
        if (Console::KeyAvailable) {
            ConsoleKeyInfo keyInfo = Console::ReadKey(true);
            ConsoleKey tecla = keyInfo.Key;

            if (tecla == ConsoleKey::Escape) {
                regresarAlMenu = true;
                break;
            }
            if (*GetVidas() == 0) {
                GameOver();
                _sleep(3000);
                regresarAlMenu = true;
                break;
            }
            if (*GetBolsa() == 6) {
                Winner();
                _sleep(3000);
                pasarAlSiguiente = true;
                break;
            }
            bool debeAnimar = false;


            switch (tecla) {
            case ConsoleKey::LeftArrow:
            case ConsoleKey::RightArrow:
            case ConsoleKey::UpArrow:
            case ConsoleKey::DownArrow:
                MoverPersonaje(keyInfo);
                break;

            case ConsoleKey::Escape:
                break;
            }
        }
        if (pj.necesitaRedibujar)
            DibujarPersonaje();

        DibujarBolsas3();
        MoverPolicias(true);
        DetectarColisionesPB();
        DetectarColisionesPP();
        Thread::Sleep(100);
    }
    if (pasarAlSiguiente && !regresarAlMenu) {
        InicializarPersonaje3();
        EjecutarEscenario3(regresarAlMenu);
    }
}
