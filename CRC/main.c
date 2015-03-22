#include <stdio.h>
#include <stdlib.h>
int main()
{
   printf("%d",Crc(44));
}
int Crc(int input){
     int pattern = 13; // 1101 n==3 双方约定的除数
     int n = 3 ;// partten 二进制位数减1
     int temp; //存储算法过程量
     int k = 6;// 输入数据的二进制长度
     int getPre4 = 480 ;// (480)2 =  111100000 取出输入数据的前四位
     int i;
    input <<= n; // 后面添加n个零
    temp = input&getPre4;
    temp = temp>>(k+n-4); // 为了将pattern和input的前四位异或
    temp = temp^pattern;   //  input的前四位和pattern 异或
    for(i = 16;i>=1 ; i/=2){
    /*
        input = 101100000
        16 = 10000  相与取第五位
        8 = 1000   相与取第四位
        。。。。。。。
    */
     if((input&i)!=0){
        temp<<=1;
        temp++;
        }else
        temp<<=1;
    /*
      取出第五，第六。。位后
      添加到 temp的后面
      若temp小于 0111 则continue
      否则与pattern 异或
    */
        if(temp<=7)
        continue;
        temp^=pattern;
    }
  return temp;
}
