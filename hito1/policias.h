#pragma once
#ifndef _POLICIAS_H_
#define _POLICIAS_H_

void BorrarPolicia(int, int);
void DibujarPolicia(int, int);
void InicializarPolicias1();
void InicializarPolicias2();
void InicializarPolicias3();

int ObtenerCantidadPolicias();


void MoverPoliciasMapa1(bool mover); 
void MoverPoliciasMapa2(bool mover); 
void MoverPoliciasMapa3(bool mover); 

void MoverPolicias(bool);

bool ImpactaPolicia(int, int);

#endif
