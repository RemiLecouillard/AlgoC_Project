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
  * @file rag.c
  */
#include "fct/region.h"
#include "list/linkedlist.h"
#include "image/image.h"
#include "fct/rag.h"
#include <stdlib.h>
#include <stdio.h>


struct rag {
  image image;
  int height, width;
  LinkedList blocks;
};

Rag createRag(image img,int height,int width) {
 return NULL;
}

image getRegionImage(Rag rag) {
 return NULL;
}

int getHeight(Rag rag) {
  return 0;
}

int getWidth(Rag rag) {
  return 0;
}

LinkedList getBlocks(Rag rag) {
 return NULL;
}

static void initNeighbourgs(Rag rag) {

}

static LinkedList initRegion(Rag rag) {
 return NULL;
}
