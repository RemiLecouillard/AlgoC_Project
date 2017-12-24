/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
#include <stdio.h>
#include <time.h>
#include "image/image.h"
#include "fct/rag.h"
#include "fct/algo.h"

int main(int argc, char *argv[]) {
  image input, output;
  Rag rag;
  int x, y;
  FILE* foutput;
  double limit;

  limit = 1.000628;
  if (argc > 2) {
    x = 4;
    y = 4;
    if ( argc >= 5) {
      x = atoi(argv[3]);
      y = atoi(argv[4]);
      if (argc > 5) {
        limit = atoi(argv[5]);
      }
    }
    input = FAIRE_image();
    image_charger(input, argv[1]);

    rag = createRag(input, x, y);
    if (rag != NULL) {
      segmentateRegion(rag, limit);
      output = getRegionImage(rag);
      foutput = fopen(argv[2], "w+");

      if(foutput != NULL){
        image_to_stream(output, foutput);
        printf("Image saved under %s\n", argv[2]);
      }
      DEFAIRE_image(input);
    }

  } else {
    perror("Not enough arguments. Please specify a file name\n");
  }

   return 0;
}
