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
  * @file region.c
  */
#include "fct/region.h"
#include "fct/moments.h"
#include "list/linkedlist.h"
#include <stdlib.h>
#include <stdio.h>


struct pRegion{
  struct region *region;
};

struct region{
  Moments moments;
  LinkedList neighbourgs;
};

Region createRegion(Moments moments){
  struct region *reg = malloc(sizeof(struct region));
  Region preg = malloc(sizeof(struct pRegion));
  preg->region = reg;

  reg->moments = moments;
  reg->neighbourgs = createList();

  return preg;
}

void destroyRegion(Region region){

}

Region getBestNeighbourgs(Region region){

  return NULL;
}

void fusion(Region reg1,Region reg2){
  struct region* res = malloc(sizeof(struct region));

  res->moments = mergeMoments(reg1->region->moments, reg2->region->moments);


  reg1->region = res;
  reg2->region = res;
}

void addNeighbourg(Region region){

}

int isSame(Region r1,Region r2) {
  return r1->region == r2->region ? 1 : 0;
}

rgb getColor(Region reg) {
  int nbPixels = getM0(reg->region->moments);
  rgb col = getM1(reg->region->moments);

  /* each section of rgb is a sum of all pixels. To get the average colors
  of the region we must devide it by the number of pixels */
  col.red = col.red/nbPixels;
  col.blue = col.blue/nbPixels;
  col.green = col.green/nbPixels;
  return col;
}


static double getFusionCost(Region reg1,Region reg2){

  return 0.0;
}
