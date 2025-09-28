#pragma once
#ifndef _MAPAS_H_
#define _MAPAS_H_

extern char mapa1[ZONA_ALTO][ZONA_ANCHO + 1];
extern char mapa2[ZONA_ALTO][ZONA_ANCHO + 1];
extern char mapa3[ZONA_ALTO][ZONA_ANCHO + 1];

extern char (*mapaActual)[ZONA_ANCHO + 1];

void EstablecerMapaActual(char nuevoMapa[ZONA_ALTO][ZONA_ANCHO + 1]);

void DibujarBienvenida();
void DibujarMapa1();
void DibujarMapa2();
void DibujarMapa3();
bool ColisionaPersonaje(int, int);
bool ColisionaPolicia(int, int);
void winnerf();
#endif
