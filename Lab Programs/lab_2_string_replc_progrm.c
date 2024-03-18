#include <stdio.h>
#include <string.h>

int slen(char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
    ;
  return i;
}

void replace(char *T, char *P, char *REP, char *FIN);
// {
//   int q = 0, e = 0, k = 0, z = 0;
//   int s = slen(T), r = slen(P);
//   for (; k < s;)
//   {
//     for (e = 0; e < r; e++)
//     {
//       if (P[e] != T[e + k])
//         break;
//     }
//     if (e == r)
//     {
//       for (z = 0; z < slen(REP); z++)
//       {
//         FIN[q++] = REP[z];
//       }
//       k = k + r;
//     }
//     else
//     {
//       FIN[q++] = T[k++];
//     }
//   }
//   FIN[q] = '\0';
// }

int main()
{
  char T[20] = {"bapqrgbahba"};
  char P[10] = {"ba"};
  char REP[5] = {"BAN"}, FIN[50];
  replace(T, P, REP, FIN);
  printf("\n output=%s", FIN);
}

void replace(char *T, char *P, char *REP, char *FIN)
{
  int a = 0, b = 0, c = 0;
  int r = slen(P), s = slen(T);
  while (a < s)
  {
    for (b = 0; b < r; b++)
    {
      if (P[b] != T[b + a])
        break;
    }
    if (b == r)
    {
      for (int k = 0; k < slen(REP); k++)
      {
        FIN[c++] = REP[k];
      }
      a = a + r;
    }
    else
      FIN[c++] = T[a++];
  }
  FIN[c] = '\0';
}