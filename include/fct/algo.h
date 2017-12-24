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
  * @file algo.h contains the main function of the image segmentation algorithm
  */
#ifndef _ALGO_H
#define _ALGO_H

#include "image/image.h"
#include "fct/rag.h"

/**
 * Transform an original Rag (loaded from a picture) into a segmentate Rag by
 * merging the right regions up to a certain limited value
 * @param the Rag you want to segmentate
 * @param the limit value of the segmentation algorithm
 */
void segmentateRegion(Rag rag, double limit);


#endif
