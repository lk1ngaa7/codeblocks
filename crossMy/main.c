#include <stdio.h>
#include <stdlib.h>
int condition[16][4];
void Create(){
  int i;
 for(i = 0;i< 16;i++){
     if((i%2 == ((i/4)%2))&&((i/4)%2 != (i/2)%2)&&((i/8)%2 != (i/4)%2))
       {


  condition[i][3] =i%2;
  condition[i][2] =(i/2)%2;
  condition[i][1] = (i/4)%2;
  condition[i][0] = (i/8)%2;
   }

 }
}
int main()
{
    int i;
    Create();
    for(i  =0;i<16;i++)
    printf("%d %d %d %d\n",condition[i][0],condition[i][1],condition[i][2],condition[i][3]);
    return 0;
}
