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
#include "list/linkedlist.h"
#include "fct/region.h"
#include "fct/moments.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

struct pRegion{
  struct region *region;
};

struct region{
  Moments moments;
  LinkedList neighbours;
  double quadraticError;
};

static double getFusionCost(Region reg1,Region reg2);

static void destroyStructRegion(struct region* region);

Region createRegion(int** pixels,int nbPixels){
  struct region *reg = malloc(sizeof(struct region));
  Region preg = malloc(sizeof(struct pRegion));

  preg->region = reg;
  reg->moments = createMoments(pixels, nbPixels);
  reg->neighbours = createList();
  reg->quadraticError = getQE(reg->moments);

  /*rgb = getColor(preg);
  for (i = 0; i < nbPixels; i ++) {
    reg->quadraticError += pow((double)pixels[i][0] - rgb.red, 2) + pow((double)pixels[i][1]
    - rgb.green, 2) + pow((double)pixels[i][2] - rgb.blue, 2);
  }*/

  return preg;
}

void destroyRegion(Region region){
  destroyStructRegion(region->region);
  free(region);
}

Region getBestNeighbours(Region region,double* cost){
  struct region* self = region->region;
  Iterator iterator;
  double min, tmp;
  Region current, best;

  min = DBL_MAX;
  iterator = getIterator(self->neighbours);

  while(moveNext(iterator)) {
    current = getElement(iterator);
    tmp = getFusionCost(region, current);
    if (tmp < min) {
      min = tmp;
      best = current;
    }
  }
  *cost = min;
  return best;
}

void fusion(Region reg1,Region reg2){
  struct region* res = malloc(sizeof(struct region));

  res->moments = mergeMoments(reg1->region->moments, reg2->region->moments);
  res->neighbours = mergeList(reg1->region->neighbours, reg2->region->neighbours);
  res->quadraticError = getQE(res->moments);

  destroyStructRegion(reg1->region);
  destroyStructRegion(reg2->region);
  reg1->region = res;
  reg2->region = res;
}

LinkedList getNeighbours(Region reg){
  return reg->region->neighbours;
}

void addNeighbourg(Region region, Region neighbourg){
  addRegion(getNeighbours(region), neighbourg);
}

int isSame(Region r1,Region r2) {
  if(r1 != NULL && r2 != NULL) {
    return r1->region == r2->region ? 1 : 0;
  }
  return 0;
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
  double cost, norm;
  Moments A,B;
  rgb col;
  A = reg1->region->moments;
  B = reg2->region->moments;
  col.red = getColor(reg1).red - getColor(reg2).red;
  col.green = getColor(reg1).green - getColor(reg2).green;
  col.blue = getColor(reg1).blue - getColor(reg2).blue;
  norm = sqrt(pow(col.blue, 2) + pow(col.green, 2) + pow(col.red, 2));
  cost = ( getM0(A)*getM0(B)/(getM0(A)+getM0(B)) ) * norm;
  return cost;
}

static void destroyStructRegion(struct region* region) {
  destroyMoments(region->moments);
  destroyList(region->neighbours);
  free(region);
}

double getQuadraticError(Region rag) {
  return rag->quadraticError;
}
