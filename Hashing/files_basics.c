#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  fp = fopen("file.txt", "w");
  fprintf(fp, "%s %s %s %d", "my", "numbeer", "is", 3);
  fclose(fp);
  
}
