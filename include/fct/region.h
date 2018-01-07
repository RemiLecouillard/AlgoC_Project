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


/**
  * A structure representing a region. With a moments and neighbours
  * This is a proxy. The real region is not reachable outside the
  * inside of those functions.
  */
typedef struct pRegion* Region;

#include "fct/moments.h"
#include "list/linkedlist.h"


/**
  * @param pixels An array of pixels
  * @param nbPixels the number of pixels
  * @return the created Region
  */
Region createRegion(int** pixels,int nbPixels);

/** Destroyes the region
  * @param region The region used.
  */
void destroyRegion(Region region);

/** Find the best neighbour to fusion with
  * @param region The region used.
  * @param cost The cost of the fusion
  * @return the best region to fusion
  */
Region getBestNeighbours(Region region,double* cost);

/** Fusion two regions together.
  * Being proxies, the regions merged are pointing to the same memory space.
  * @param reg1 The first region.
  * @param reg2 The first region.
  */
void fusion(Region reg1,Region reg2);

/**
  * @param region The region used.
  * @return the list of the neighbours
  */
LinkedList getNeighbours(Region reg);

/**
  * @param region The region used.
  * @param neighbour the neighbour to add
  */
void addNeighbourg(Region region,Region neighbourg);

/** Check if two regions are the same
  * @param r1 the first region
  * @parem r2 the second region
  * @return 1 if they'r the same. 0 either
  */
int isSame(Region r1,Region r2);

/**
  * @param region The region used.
  * @return the color of the region.
  */
rgb getColor(Region reg);

/**
  * @param region The region used.
  * @return the quadratic error
  */
double getQuadraticError(Region rag);

#endif
