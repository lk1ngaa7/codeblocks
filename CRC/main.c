#include <stdio.h>
#include <stdlib.h>
int main()
{
   printf("%d",Crc(44));
}
int Crc(int input){
     int pattern = 13; // 1101 n==3 ˫��Լ���ĳ���
     int n = 3 ;// partten ������λ����1
     int temp; //�洢�㷨������
     int k = 6;// �������ݵĶ����Ƴ���
     int getPre4 = 480 ;// (480)2 =  111100000 ȡ���������ݵ�ǰ��λ
     int i;
    input <<= n; // �������n����
    temp = input&getPre4;
    temp = temp>>(k+n-4); // Ϊ�˽�pattern��input��ǰ��λ���
    temp = temp^pattern;   //  input��ǰ��λ��pattern ���
    for(i = 16;i>=1 ; i/=2){
    /*
        input = 101100000
        16 = 10000  ����ȡ����λ
        8 = 1000   ����ȡ����λ
        ��������������
    */
     if((input&i)!=0){
        temp<<=1;
        temp++;
        }else
        temp<<=1;
    /*
      ȡ�����壬��������λ��
      ��ӵ� temp�ĺ���
      ��tempС�� 0111 ��continue
      ������pattern ���
    */
        if(temp<=7)
        continue;
        temp^=pattern;
    }
  return temp;
}
