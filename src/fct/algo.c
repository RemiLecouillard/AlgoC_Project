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
#include <float.h>

void segmentateRegion(Rag rag, double limit) {

  int end, step;
  double cost, bestCost, partitionError;
  Region region = NULL;
  Region neighbour = NULL;
  Region bestRegion = NULL;
  Region bestNeighbour = NULL;
  LinkedList list = NULL;
  Iterator iter = NULL;

  partitionError = getPartitionError(rag);
  cost = 0.0;
  step = 0;
  end = 1017;
  limit *= partitionError;

  while(partitionError < limit && step < end) {
    /*printf("error %f/%f limit\n", partitionError, limit);*/
    list = getBlocks(rag);
    iter = getIterator(list);
    bestCost = DBL_MAX;

    printf("Step %d : ", step);
    while(moveNext(iter)) {
      region = getElement(iter);
      /*printf("%p =>\n", region);*/
      neighbour = getBestNeighbours(region, &cost);
    /*  printf("\t%p with %f\n", neighbour, cost); */
      if(bestCost >= cost){
        bestCost = cost;
        bestRegion = region;
        bestNeighbour = neighbour;
      }
      cost = 0.0;
    }
    printf("%p and %p ... \n", bestRegion, bestNeighbour);
    fusion(bestRegion, bestNeighbour);
    /*printf("Fusion done\n");*/
    partitionError += bestCost;
    step++;
    bestCost = 0.0;
    destroyIterator(iter);
  }
}
