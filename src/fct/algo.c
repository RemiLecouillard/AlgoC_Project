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
  * @file algo.c
  */

#include "fct/algo.h"

void segmentateRegion(Rag rag, double limit) {

  int end, step;
  double cost, currentCost, partitionError;
  Region region, neighbour, currentRegion, currentNeighbour = NULL;
  LinkedList list = NULL;
  Iterator iter = NULL;

  partitionError = getPartitionError(rag);
  cost = 0.0;
  currentCost = 0.0;
  step = 0;
  end = 50;
  list = getBlocks(rag);

  printf("Start segmentation\n");

  while(partitionError < limit && step < end) {
    iter = getIterator(list);
    while(moveNext(iter)) {
      region = getElement(iter);
      neighbour = getBestNeighbours(region, &cost);
      printf("%p\n", neighbour);
      if(currentCost >= cost){
        currentCost = cost;
        currentRegion = region;
        currentNeighbour = neighbour;
      }
    }
    fusion(region, neighbour);
    partitionError += currentCost;
    step++;
    cost = 0.0;
    currentCost = 0.0;
  }
}
