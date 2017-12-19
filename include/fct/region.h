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
  * @file region.h
  */
#ifndef _REGION_H
#define _REGION_H

typedef struct pRegion* Region;

#include "fct/moments.h"
#include "list/linkedlist.h"


Region createRegion(int** pixels,int nbPixels);

void destroyRegion(Region region);

Region getBestNeighbours(Region region,double* cost);

void fusion(Region reg1,Region reg2);

LinkedList getNeighbours(Region reg);

void addNeighbourg(Region region,Region neighbourg);

int isSame(Region r1,Region r2);

rgb getColor(Region reg);

#endif
