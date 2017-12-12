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

#ifndef _RAG_H
#define _RAG_H

#include "fct/region.h"

typedef struct rag* Rag;

Rag createRag(image img,int height,int width);

image getRegionImage(Rag rag);

int getHeight(Rag rag);

int getWidth(Rag rag);

LinkedList getBlocks(Rag rag);

#endif
