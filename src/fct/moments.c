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
#include <math.h>
#include <stdlib.h>

struct moments {
  int m0; /** The number of pixels */
  rgb m1; /** The summing of colors (RGB)*/
  rgb m2; /** The summing ^2 of colors (RGB)*/
};

Moments createMoments(int pixels[][3],int nbPixels){
  Moments moments = malloc(sizeof(struct moments));
  moments->m0 = nbPixels;
  moments->m1 = computeM1(pixels, nbPixels);
  moments->m2 = computeM2(pixels, nbPixels);
  return moments;
}

void destroyMoments(Moments moments){
  free(moments);
}

Moments mergeMoments(Moments m1,Moments m2){
  Moments merged = malloc(sizeof(struct moments));
  merged->m0 = m1->m0 + m2->m0;

  merged->m1.red = m1->m1.red + m2->m1.red;
  merged->m1.green = m1->m1.green + m2->m1.green;
  merged->m1.blue = m1->m1.blue + m2->m1.blue;

  merged->m2.red = m1->m2.red + m2->m2.red;
  merged->m2.green = m1->m2.green + m2->m2.green;
  merged->m2.blue = m1->m2.blue + m2->m2.blue;

  return merged;
}

Moments copyMoments(Moments moments){
  Moments m = malloc(sizeof(struct moments));
  m->m0 = moments->m0;
  m->m1 = moments->m1;
  m->m2 = moments->m2;
  return m;
}

int getM0(Moments moments){
  return moments->m0;
}

rgb getM1(Moments moments){
  return moments->m1;
}

rgb getM2(Moments moments){
  return moments->m2;
}

static rgb computeM1(int pixels[][3],int nbPixels){
  int i;
  rgb m1;
  m1.red = 0;
  m1.green = 0;
  m1.blue = 0;

  for (i = 0; i < nbPixels; i ++) {
    m1.red += pixels[i][0];
    m1.green += pixels[i][1];
    m1.blue += pixels[i][2];
  }

  return m1;
}

static rgb computeM2(int pixels[][3],int nbPixels){
  int i;
  rgb m2;
  m2.red = 0;
  m2.green = 0;
  m2.blue = 0;

  for (i = 0; i < nbPixels; i ++) {
    m2.red += pow(pixels[i][0], 2);
    m2.green += pow(pixels[i][1], 2);
    m2.blue += pow(pixels[i][2], 2);
  }

  return m2;
}
