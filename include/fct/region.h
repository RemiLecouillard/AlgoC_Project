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

#include "image/image.h"

typedef struct pRegion* Region;

Region createRegion(int pixels[][3],int nbPixels);

void destroyRegion(Region region);

Region getBestNeighbourgs(Region region);

void fusion(Region reg1,Region reg2);

void addNeighbourg(Region region);

static double getFusionCost(Region reg1,Region reg2);

#endif
