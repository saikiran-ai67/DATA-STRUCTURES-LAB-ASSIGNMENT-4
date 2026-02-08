#include <stdio.h>
int main()
{
 int r1, c1, r2, c2;
 int a[50][50], b[50][50];
 int t1[100][3], t2[100][3], t3[200][3];
 int i, j, k1 = 1, k2 = 1, k3 = 1;
 printf("Enter rows and columns of Matrix 1: ");
 scanf("%d %d", &r1, &c1);
 printf("Enter elements of Matrix 1:\n");
 for(i = 0; i < r1; i++)
 for(j = 0; j < c1; j++)
 scanf("%d", &a[i][j]);
 printf("Enter rows and columns of Matrix 2: ");
 scanf("%d %d", &r2, &c2);
 printf("Enter elements of Matrix 2:\n");
 for(i = 0; i < r2; i++)
 for(j = 0; j < c2; j++)
 scanf("%d", &b[i][j]);
 if(r1 != r2 || c1 != c2)
 {
 printf("Size is not same");
 return 0;
 }
 t1[0][0] = r1;
 t1[0][1] = c1;
 for(i = 0; i < r1; i++)
 for(j = 0; j < c1; j++)
 if(a[i][j] != 0)
 {
 t1[k1][0] = i;
 t1[k1][1] = j;
 t1[k1][2] = a[i][j];
 k1++;
 }
 t1[0][2] = k1 - 1;
 t2[0][0] = r2;
 t2[0][1] = c2;
 for(i = 0; i < r2; i++)
 for(j = 0; j < c2; j++)
 if(b[i][j] != 0)
 {
 t2[k2][0] = i;
 t2[k2][1] = j;
 t2[k2][2] = b[i][j];
 k2++;
 }
 t2[0][2] = k2 - 1;
 printf("\nSparse Matrix 1 (Triplet Form):\n");
 for(i = 0; i < k1; i++)
 printf("%d %d %d\n", t1[i][0], t1[i][1], t1[i][2]);
 printf("\nSparse Matrix 2 (Triplet Form):\n");
 for(i = 0; i < k2; i++)
 printf("%d %d %d\n", t2[i][0], t2[i][1], t2[i][2]);
 i = 1;
 j = 1;
 t3[0][0] = r1;
 t3[0][1] = c1;
 while(i < k1 && j < k2)
 {
 if(t1[i][0] == t2[j][0] && t1[i][1] == t2[j][1])
 {
 t3[k3][0] = t1[i][0];
 t3[k3][1] = t1[i][1];
 t3[k3][2] = t1[i][2] + t2[j][2];
 i++;
 j++;
 k3++;
 }
 else if(t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1]))
 {
 t3[k3][0] = t1[i][0];
 t3[k3][1] = t1[i][1];
 t3[k3][2] = t1[i][2];
 i++;
 k3++;
 }
 else
 {
 t3[k3][0] = t2[j][0];
 t3[k3][1] = t2[j][1];
 t3[k3][2] = t2[j][2];
 j++;
 k3++;
 }
 }
 while(i < k1)
 {
 t3[k3][0] = t1[i][0];
 t3[k3][1] = t1[i][1];
 t3[k3][2] = t1[i][2];
 i++;
 k3++;
 }
 while(j < k2)
 {
 t3[k3][0] = t2[j][0];
 t3[k3][1] = t2[j][1];
 t3[k3][2] = t2[j][2];
 j++;
 k3++;
 }
 t3[0][2] = k3 - 1;
 printf("\nSum Sparse Matrix (Triplet Form):\n");
 for(i = 0; i < k3; i++)
 printf("%d %d %d\n", t3[i][0], t3[i][1], t3[i][2]);
 return 0;
}
