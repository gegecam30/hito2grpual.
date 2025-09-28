#include "pch.h"
#include "personaje.h"
#include "policias.h"
#include "bolsasbasura.h"
#include "mapas.h"

Personaje* jugador = nullptr;
int* vidas = nullptr;
int* numBolsa = nullptr;

void SetBolsa(int* ptr) { numBolsa = ptr; }
int* GetBolsa() { return numBolsa; }

void SetVidas(int* ptr) { vidas = ptr; }
int* GetVidas() { return vidas; }

void SetPersonaje(Personaje* ptr) { jugador = ptr; }
void DibujarPersonaje() {
    if (!jugador->necesitaRedibujar) return;
    char(*frame)[ANCHO_PJ + 1] = jugador->frames[jugador->direccion][jugador->frameActual];
    for (int i = 0; i < ALTO_PJ; i++) {
        Console::SetCursorPosition(jugador->x, jugador->y + i);
        for (int j = 0; j < ANCHO_PJ; j++) {
            if (mapaActual == mapa1) {
                Console::BackgroundColor = ConsoleColor::DarkGray;
                Console::ForegroundColor = ConsoleColor::DarkCyan;
                Console::Write(static_cast<wchar_t>(frame[i][j]));
                Console::ResetColor();
            }
            else if (mapaActual == mapa2) {
                Console::BackgroundColor = ConsoleColor::Yellow;
                Console::ForegroundColor = ConsoleColor::DarkCyan;
                Console::Write(static_cast<wchar_t>(frame[i][j]));
                Console::ResetColor();
            }
            else if (mapaActual == mapa3) {
                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::Write(static_cast<wchar_t>(frame[i][j]));
                Console::ResetColor();
            }
        }
        
    }
}
void BorrarPersonaje() {
    for (int i = 0; i < ALTO_PJ; i++) {
        Console::SetCursorPosition(jugador->x, jugador->y + i);
        for (int j = 0; j < ANCHO_PJ; j++) {
            if (mapaActual == mapa1) {
                Console::BackgroundColor = ConsoleColor::DarkGray;
                Console::Write(" ");
                Console::ResetColor();
            }
            else if (mapaActual == mapa2) {
                Console::BackgroundColor = ConsoleColor::Yellow;
                Console::Write(" ");
                Console::ResetColor();
            }
            else if (mapaActual == mapa3) {
                Console::Write(" ");
            }
            
        }
    }
}
void MoverPersonaje(ConsoleKeyInfo tecla) {
    jugador->enMovimiento = false;

    int nuevoX = jugador->x;
    int nuevoY = jugador->y;

    switch (tecla.Key) {
    case ConsoleKey::UpArrow:
        nuevoY--;
        jugador->direccion = ARRIBA;
        break;
    case ConsoleKey::DownArrow:
        nuevoY++;
        jugador->direccion = ABAJO;
        break;
    case ConsoleKey::LeftArrow:
        nuevoX--;
        jugador->direccion = IZQUIERDA;
        break;
    case ConsoleKey::RightArrow:
        nuevoX++;
        jugador->direccion = DERECHA;
        break;
    }

    // Verifica si está dentro de los límites del mapa
    bool dentroLimites =
        nuevoX >= 1 &&
        nuevoX + ANCHO_PJ <= ZONA_ANCHO &&
        nuevoY >= 1 &&
        nuevoY + ALTO_PJ <= ZONA_ALTO;

    if (dentroLimites && !ColisionaPersonaje(nuevoX, nuevoY)) {
        BorrarPersonaje();
        jugador->x = nuevoX;
        jugador->y = nuevoY;
        jugador->enMovimiento = true;
    }

    if (jugador->enMovimiento) {
        jugador->frameActual = (jugador->frameActual + 1) % FRAMES_PERSONAJE;
        jugador->necesitaRedibujar = true;
    }
}
void DetectarColisionesPP() {
    for (int i = 0; i < ALTO_PJ; ++i) {
        for (int j = 0; j < ANCHO_PJ; j++) {
            int nuevoX = jugador->x + j;
            int nuevoY = jugador->y + i;

            if (ImpactaPolicia(nuevoX, nuevoY)) {
                *GetVidas() -= 1;
                DibujarPersonaje();
            }
        }
    }
}
void DetectarColisionesPB() {
    for (int i = 0; i < ALTO_PJ; ++i) {
        for (int j = 0; j < ANCHO_PJ; j++) {
            int nuevoX = jugador->x + j;
            int nuevoY = jugador->y + i;

            if (ImpactaBolsas(nuevoX, nuevoY)) {
                *GetBolsa() += 1;
                DibujarPersonaje();
            }
        }
    }
}