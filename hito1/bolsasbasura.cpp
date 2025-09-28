#include "pch.h"
#include "bolsasbasura.h"
#include "mapas.h"

const int MAX_BOLSAS = 8;
int bx[MAX_BOLSAS];
int by[MAX_BOLSAS];
int bactivo[MAX_BOLSAS];

void BorrarBolsas(int x, int y) {
	if (mapaActual == mapa1) {
		for (int i = 0; i < 2; i++) {
			Console::BackgroundColor = ConsoleColor::DarkGray;
			Console::SetCursorPosition(x, y + i);
			Console::Write("   ");
			Console::ResetColor();
		}
	}
	else if (mapaActual == mapa2) {
		for (int i = 0; i < 2; i++) {
			Console::BackgroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(x, y + i);
			Console::Write("   ");
			Console::ResetColor();
		}
	}
	else if (mapaActual == mapa3) {
		for (int i = 0; i < 2; i++) {
			Console::SetCursorPosition(x, y + i);
			Console::Write("   ");
		}
	}
	
}
void DibujarBolsas(int x,int y) {
	if (mapaActual == mapa1) {
		Console::BackgroundColor = ConsoleColor::DarkGray;
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(x, y);
		Console::Write("***");
		Console::SetCursorPosition(x, y + 1);
		Console::Write("|*|");
		Console::ResetColor();
	}
	else if(mapaActual == mapa2) {
		Console::BackgroundColor = ConsoleColor::Yellow;
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(x, y);
		Console::Write("***");
		Console::SetCursorPosition(x, y + 1);
		Console::Write("|*|");
		Console::ResetColor();
	}
	else if (mapaActual == mapa3) {
		Console::ForegroundColor = ConsoleColor::DarkYellow;
		Console::SetCursorPosition(x, y);
		Console::Write("***");
		Console::SetCursorPosition(x, y + 1);
		Console::Write("|*|");
		Console::ResetColor();
	}
}
void InicializarBolsas() {
	if (mapaActual == mapa1) {
		for (int i = 0;i < MAX_BOLSAS - 2;i++) {
			bactivo[i] = true;
		}
	}
	else if (mapaActual == mapa2) {
		for (int i = 0;i < MAX_BOLSAS - 3;i++) {
			bactivo[i] = true;
		}
	}
	else if (mapaActual == mapa3) {
		for (int i = 0;i < MAX_BOLSAS - 2;i++) {
			bactivo[i] = true;
		}
	}	
}
void DibujarBolsas1() {
	bx[0] = 115;by[0] = 8;
	bx[1] = 20; by[1] = 17;
	bx[2] = 19; by[2] = 24;
	bx[3] = 89; by[3] = 23;
	bx[4] = 84; by[4] = 15;
	bx[5] = 54; by[5] = 16;
	for (int i = 0;i < MAX_BOLSAS - 2;i++) {
		if (bactivo[i]) {
			DibujarBolsas(bx[i], by[i]);
		}
	}
}
void DibujarBolsas2() {
	bx[0] = 2; by[0] = 8;
	bx[1] = 20;by[1] = 21;
	bx[2] = 25;by[2] = 10;
	bx[3] = 60;by[3] = 11;
	bx[4] = 94;by[4] = 23;
	for (int i = 0;i < MAX_BOLSAS - 3;i++) {
		if (bactivo[i]) {
			DibujarBolsas(bx[i], by[i]);
		}
	}
}
void DibujarBolsas3() {
	bx[0] = 2;  by[0] = 8;
	bx[1] = 12; by[1] = 17;
	bx[2] = 45; by[2] = 18;
	bx[3] = 55; by[3] = 6;
	bx[4] = 94; by[4] = 23;
	bx[5] = 110;by[5] = 15;
	for (int i = 0;i < MAX_BOLSAS - 2;i++) {
		if (bactivo[i]) {
			DibujarBolsas(bx[i], by[i]);
		}
	}
}

bool ImpactaBolsas(int objX, int objY) {
	for (int i = 0; i < MAX_BOLSAS; i++) {
		if (!bactivo[i]) continue;

		int bolsaX = bx[i];
		int bolsaY = by[i];
		int ancho = 3;  
		int alto = 2;   

		if (objX >= bolsaX && objX <= bolsaX + ancho - 1 &&
			objY >= bolsaY && objY <= bolsaY + alto - 1) {

			BorrarBolsas(bolsaX, bolsaY);
			bactivo[i] = false;

			return true;
		}
	}
	return false;
}