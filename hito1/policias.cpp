#include "pch.h"
#include "policias.h"
#include "mapas.h"
#include "bolsasbasura.h"
const int MAX_POLICIAS = 7;
int *px[MAX_POLICIAS];
int *py[MAX_POLICIAS];
bool pactivo[MAX_POLICIAS];

int cantidadPoliciasMapa1 = 3;
int cantidadPoliciasMapa2 = 4;
int cantidadPoliciasMapa3 = 5;
int cantidadPoliciasMapa4 = 6;
int cantidadPoliciasMapa5 = 7;

void DibujarPolicia(int x, int y) {
    if (mapaActual == mapa1) {
        Console::ForegroundColor = ConsoleColor::DarkRed;
        Console::BackgroundColor = ConsoleColor::DarkGray;
        Console::SetCursorPosition(x, y);     Console::Write(" # ");
        Console::SetCursorPosition(x, y + 1); Console::Write("/P\\");
        Console::SetCursorPosition(x, y + 2); Console::Write(" | ");
        Console::SetCursorPosition(x, y + 3); Console::Write("/ \\");
        Console::ResetColor();
    }
    else if (mapaActual == mapa2) {
        Console::ForegroundColor = ConsoleColor::DarkRed;
        Console::BackgroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(x, y);     Console::Write(" # ");
        Console::SetCursorPosition(x, y + 1); Console::Write("/P\\");
        Console::SetCursorPosition(x, y + 2); Console::Write(" | ");
        Console::SetCursorPosition(x, y + 3); Console::Write("/ \\");
        Console::ResetColor();
    }
    else if (mapaActual == mapa3) {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(x, y);     Console::Write(" # ");
        Console::SetCursorPosition(x, y + 1); Console::Write("/P\\");
        Console::SetCursorPosition(x, y + 2); Console::Write(" | ");
        Console::SetCursorPosition(x, y + 3); Console::Write("/ \\");
        Console::ResetColor();
    }
    
}
void BorrarPolicia(int x, int y) {
    if (mapaActual == mapa1) {
        Console::BackgroundColor = ConsoleColor::DarkGray;
        for (int i = 0; i < 4; i++) {
            Console::SetCursorPosition(x, y + i);
            Console::Write("    ");
        }
        Console::ResetColor();
    }
    else if (mapaActual == mapa2) {
        Console::BackgroundColor = ConsoleColor::Yellow;
        for (int i = 0; i < 4; i++) {
            Console::SetCursorPosition(x, y + i);
            Console::Write("    ");
        }
        Console::ResetColor();
    }
    else if (mapaActual == mapa3) {
        for (int i = 0; i < 4; i++) {
            Console::SetCursorPosition(x, y + i);
            Console::Write("    ");
        }
    }
}
void InicializarPolicias1() { 
    for (int i = 0; i < cantidadPoliciasMapa1; i++) {
        px[i] = new int;
        py[i] = new int;
    }
    *px[0] = 37;   *py[0] = 12;
    *px[1] = 105; *py[1] = 12;
    *px[2] = 62;  *py[2] = 17;
    for (int i = 0; i < MAX_POLICIAS - 4; i++) {
        pactivo[i] = true;
        DibujarPolicia(*px[i], *py[i]);
    }
}
void InicializarPolicias2() {
    for (int i = 0; i < cantidadPoliciasMapa2; i++) {
        px[i] = new int;
        py[i] = new int;
    }
    *px[0] = 7;*py[0] = 12;
    *px[1] = 9;*py[1] = 22;
    *px[2] = 110;*py[2] = 12;
    *px[3] = 45;*py[3] = 21;
    for (int i = 0; i < MAX_POLICIAS - 3; i++) {
        pactivo[i] = true;
        DibujarPolicia(*px[i], *py[i]);
    }

}
void InicializarPolicias3() {
    for (int i = 0;i < cantidadPoliciasMapa3;i++) {
        px[i] = new int;
        py[i] = new int;
    }
    *px[0] = 35;*py[0] = 3;
    *px[1] = 20;*py[1] = 10;
    *px[2] = 32;*py[2] = 7;
    *px[3] = 110;*py[3] = 6;
    *px[4] = 79;*py[4] = 18;
    for (int i = 0;i < MAX_POLICIAS - 2;i++) {
        pactivo[i] = true;
        DibujarPolicia(*px[i], *py[i]);
    }
}

int ObtenerCantidadPolicias() {
    if (mapaActual == mapa1) {
        return cantidadPoliciasMapa1;
    }
    else if (mapaActual == mapa2) {
        return cantidadPoliciasMapa2;
    }
    else if (mapaActual == mapa3) {
        return cantidadPoliciasMapa3;
    }
}
void MoverPolicias(bool mover) {
    if (mapaActual == mapa1) {
        MoverPoliciasMapa1(mover);
    } else if (mapaActual == mapa2) {
        MoverPoliciasMapa2(mover);
    } else if (mapaActual == mapa3) {
        MoverPoliciasMapa3(mover);
    }
}


bool ImpactaPolicia(int x, int y) {
    for (int j = 0; j < MAX_POLICIAS; ++j) {
        if (!pactivo[j]) continue;

        int ex = *px[j];
        int ey = *py[j];

        bool colisiona =
            x >= ex && x < ex + 3 &&
            y >= ey && y < ey + 4;

        if (colisiona) {
            BorrarPolicia(ex,ey);
            pactivo[j] = false;
            return true;
        }
    }
    return false;
}

//descendente
void MoverPoliciasMapa1(bool mover) {
    if (!mover) return;

    int cantidadPolicias = cantidadPoliciasMapa1;
    int minY = 2;
    int maxY = ZONA_ALTO - 5;

    for (int i = 0; i < cantidadPolicias; i++) {
        if (pactivo[i]) {
            BorrarPolicia(*px[i], *py[i]);

            int dy = 1;
            int nuevaY = *py[i] + dy;

            if (nuevaY > maxY) {
                nuevaY = minY;
            }

            *py[i] = nuevaY;
            DibujarPolicia(*px[i], *py[i]);
        }
    }
}
//Mismo movimiento para mapa 2 y 3

//Movimiento para mapa2
void MoverPoliciasMapa2(bool mover) {
    if (!mover) return;

    int cantidadPolicias = ObtenerCantidadPolicias();

    for (int i = 0; i < cantidadPolicias; i++) {
        if (pactivo[i]) {
            BorrarPolicia(*px[i], *py[i]);

            int dx = (rand() % 3) - 1;
            int dy = (rand() % 3) - 1;

            int nuevaX = *px[i] + dx;
            int nuevaY = *py[i] + dy;

            int maxX = ZONA_ANCHO - 5;
            int maxY = ZONA_ALTO - 5;
            int minX = 1;
            int minY = 2;

            if (nuevaX > maxX) nuevaX = maxX;
            if (nuevaY > maxY) nuevaY = maxY;
            if (nuevaX < minX) nuevaX = minX;
            if (nuevaY < minY) nuevaY = minY;

            if (ColisionaPolicia(nuevaX, nuevaY)) {
                nuevaX = *px[i];
                nuevaY = *py[i];
            }

            *px[i] = nuevaX;
            *py[i] = nuevaY;

            DibujarPolicia(*px[i], *py[i]);
        }
    }
}

//Movimiento para mapa3   
void MoverPoliciasMapa3(bool mover) {
    if (!mover) return;

    int cantidadPolicias = ObtenerCantidadPolicias();

    for (int i = 0; i < cantidadPolicias; i++) {
        if (pactivo[i]) {
            BorrarPolicia(*px[i], *py[i]);

            int dx = (rand() % 3) - 1;
            int dy = (rand() % 3) - 1;

            int nuevaX = *px[i] + dx;
            int nuevaY = *py[i] + dy;

            int maxX = ZONA_ANCHO - 5;
            int maxY = ZONA_ALTO - 5;
            int minX = 1;
            int minY = 2;

            if (nuevaX > maxX) nuevaX = maxX;
            if (nuevaY > maxY) nuevaY = maxY;
            if (nuevaX < minX) nuevaX = minX;
            if (nuevaY < minY) nuevaY = minY;

            if (ColisionaPolicia(nuevaX, nuevaY)) {
                nuevaX = *px[i];
                nuevaY = *py[i];
            }

            *px[i] = nuevaX;
            *py[i] = nuevaY;

            DibujarPolicia(*px[i], *py[i]);
        }
    }
}