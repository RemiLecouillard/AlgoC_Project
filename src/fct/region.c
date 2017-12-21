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
  Region father;
};

struct region{
  Moments moments;
  LinkedList neighbours;
};

static double getFusionCost(Region reg1,Region reg2);

static void destroyStructRegion(struct region* region);

static Region getPRegion(Region reg);

static struct region* getRegion(Region reg);

Region createRegion(int** pixels,int nbPixels){
  struct region *reg = malloc(sizeof(struct region));
  Region preg = malloc(sizeof(struct pRegion));

  preg->region = reg;
  preg->father = preg;
  reg->moments = createMoments(pixels, nbPixels);
  reg->neighbours = createList();

  return preg;
}

void destroyRegion(Region region){
  destroyStructRegion(region->region);
  free(region);
}

static struct region* getRegion(Region reg) {
  while(reg != reg->father) {
    reg = reg->father;
  }
  return reg->region;
}

static Region getPRegion(Region reg) {
  while(reg != reg->father) {
    reg = reg->father;
  }
  return reg;
}

Region getBestNeighbours(Region region,double* cost){
  struct region* self = getRegion(region);
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
  destroyIterator(iterator);
  *cost = min;
  return best;
}

void fusion(Region reg1,Region reg2){
  struct region* res = malloc(sizeof(struct region));

  reg1 = getPRegion(reg1);
  reg2 = getPRegion(reg2);
  res->moments = mergeMoments(reg1->region->moments, reg2->region->moments);
  res->neighbours = mergeList(reg1->region->neighbours, reg2->region->neighbours);

  reg2->father = reg1;
  reg1->region = res;

  while(deleteRegion(res->neighbours, reg1));
}

LinkedList getNeighbours(Region reg){
  return getRegion(reg)->neighbours;
}

void addNeighbourg(Region region, Region neighbourg){
  addRegion(getNeighbours(region), neighbourg);
}

int isSame(Region r1,Region r2) {
  if(r1 != NULL && r2 != NULL) {
    return getRegion(r1) == getRegion(r2) ? 1 : 0;
  }
  return 0;
}

rgb getColor(Region reg) {
  int nbPixels;
  rgb col;
  struct region* region;

  region = getRegion(reg);
  nbPixels = getM0(region->moments);
  col = getM1(region->moments);
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
  A = getRegion(reg1)->moments;
  B = getRegion(reg2)->moments;
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

double getQuadraticError(Region reg) {
  return getQE(getRegion(reg)->moments);
}
