
#include <stdio.h>
#include <unistd.h> /*unlink*/

int main(int _argc, char *_argv[]){
  FILE *f;
  char tmpSz[255];
  int n1=1, n2=2, n3=3;
  int arNums[7] = {4,5,6,7,8,9,10};
  int *p = arNums;
  int i;
  
  f = fopen("a.dat", "w");
  if(f == NULL) return 3;
  fwrite(&n1, sizeof(n1), 1, f);
  fwrite(&n2, sizeof(n2), 1, f);
  fwrite(&n3, sizeof(n3), 1, f);
  fwrite(arNums, sizeof(int), 7, f);
  fclose(f);
  f = NULL;
  puts("wrote data to a.dat");
  printf("press ENTER key to Continue");
  fgets(tmpSz, 200, stdin);
  if(rename("a.dat", "b.dat") != 0) return 4;
  puts("renamed file a.dat to b.dat");
  printf("press ENTER key to Continue");
  fgets(tmpSz, 200, stdin);
  f = fopen("b.dat", "r");
  if(f == NULL) return 5;
  n1 = n2 = n3 = p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = 0;
  fread(&n1, sizeof(int), 1, f);
  fread(&n2, sizeof(int), 1, f);
  fread(&n3, sizeof(int), 1, f);
  fread(arNums, sizeof(int), 7, f);
  fclose(f);
  f = NULL;
  printf("%d %d %d\n", n1, n2, n3);
  for(i=0; i<7; i++)
    printf("%d  ", arNums[i]);
  puts("");
  puts("removing b.dat");
  printf("press ENTER key to Continue");
  fgets(tmpSz, 200, stdin);
  unlink("b.dat");
  return 0;
}
