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
#include <stdlib.h>
#include <stdio.h>


struct pRegion{
  struct region *region;
};

struct region{
  Moments moments;
  Regions* neighbourgs;
  int nbNeighbourgs;
};

Region createRegion(){
  struct region *reg = malloc(sizeof(struct region));
  Region preg = malloc(sizeof(struct pRegion));
  preg->region = reg;

  return preg;
}
