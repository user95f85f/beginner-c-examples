
#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc and free*/
#include <string.h> /*strcpy*/

typedef struct{
  int n1;
  int address;
  char str[255];
} AData;

int main(int _argc, char *argv[]){
  AData *ptrdata = (AData*)malloc(sizeof(AData));
  ptrdata->n1 = 2;
  ptrdata->address = 3;
  strcpy(ptrdata->str, "me");
  printf("name: %s. @ 0x%d: %d\n", ptrdata->str, ptrdata->address, ptrdata->n1);
  free(ptrdata);
  return 0;
}
