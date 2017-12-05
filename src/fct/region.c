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
  int nbNeighbourgs;
};

Region createRegion(Moments moments){
  struct region *reg = malloc(sizeof(struct region));
  Region preg = malloc(sizeof(struct pRegion));
  preg->region = reg;

  return preg;
}

void destroyRegion(Region region){

}

Region getBestNeighbourgs(Region region){

  return NULL;
}

void fusion(Region reg1,Region reg2){

}

void addNeighbourg(Region region){

}

static double getFusionCost(Region reg1,Region reg2){

  return 0.0;
}
