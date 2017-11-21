/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
 /**
   * @file moments.c Contains the implementations of everythings declared in
   * moments.h
   */
#include "../../include/fct/moments.h"
#include <stdio.h>

struct moments {
  int m0; /** The number of pixels */
  double m1[3]; /** The summing of colors (RGB)*/
  double m2[3]; /** The summing ^2 of colors (RGB)*/
};

Moments createMoments(int pixels[][3],int nbPixels){

  return NULL;
}

void destroyMoments(Moments moments){

}

Moments mergeMoments(Moments m1,Moments m2){

  return NULL;
}

Moments copyMoments(Moments moments){
  return NULL;
}

int getM0(Moments moments){
  return moments->m0;
}

double* getM1(Moments moments){
  return moments->m1;
}

double* getM2(Moments moments){
  return moments->m2;
}

static double* computeM1(int pixels[][3],int nbPixels){
  return NULL;
}

static double* computeM2(int pixels[][3],int nbPixels){
  return NULL;
}
