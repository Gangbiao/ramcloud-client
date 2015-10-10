/* fread example: read an entire file */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main () {
  FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  pFile = fopen ( "data1" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  /* the whole file is now loaded in the memory buffer. */
  
  // terminate
  fclose (pFile);
 /* write the buffer to another file*/
  fopen("data2", "wb");
  fwrite(buffer, 1, lSize, pFile);
  fflush(pFile);
  free (buffer);
  return 0;
}
