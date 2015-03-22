#include"iostream"
using namespace std;
typedef unsigned char uchar;

char cc[2]={'+','-'};   //便于输出
int n,                  //第一行符号总数
    half,               //全部符号总数一半
    counter;            //1计数，即“-”号计数
uchar **p;              //符号存储空间
long sum;               //符合条件的三角形计数

void Backtrace(int t)   //t，第一行第t个符号
{
    int i, j;
    if( t > n )
    {//符号填充完毕
        sum++;
        //打印符号
        cout << "第" << sum << "个:\n";
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<i; ++j)
            {
                cout << " ";
            }
            for(j=1; j<=n-i+1; ++j)
            {
                cout << cc[ p[i][j] ] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
       for(i=0; i<2; ++i)
       {
            p[1][t] = i;        //第一行第t个符号
            counter += i;       //“-”号统计,因为"+"的值是0

            for(j=2; j<=t; ++j)  //当第一行符号>=2时，可以运算出下面行的某些符号，j可代表行号
            {
               p[j][t-j+1] = p[j-1][t-j+1]^p[j-1][t-j+2];//通过异或运算下行符号，t-j+1确定的很巧
               counter += p[j][t-j+1];
            }
            if( (counter <= half) && ( t*(t+1)/2 - counter <= half) )
            {//若符号统计未超过半数，并且另一种符号也未超过半数，同时隐含两者必须相等才能结束
                Backtrace(t+1);         //在第一行增加下一个符号
            }
            //回溯，判断另一种符号情况   像是出栈一样，恢复所有对counter的操作
            for(j=2; j<=t; ++j)
            {
                counter -= p[j][t-j+1];
            }
            counter -= i;
       }
    }
}

int main()
{
    cout << "请输入第一行符号个数n：";
    cin >> n;
    counter = 0;
    sum = 0;
    half = n*(n+1)/2;
    int i=0;

    if( half%2 == 0 )
    {//总数须为偶数，若为奇数则无解
        half /= 2;
        p = new uchar *[n+1];

        for(i=0; i<=n; ++i)
        {
           p[i] = new uchar[n+1];
           memset(p[i], 0, sizeof(uchar)*(n+1));
        }

        Backtrace(1);
        for(i=0; i<=n; ++i)   //删除二维动态数组的方法
        {
            delete[] p[i];
        }
        delete[] p;
    }

    cout << "\n总共 " << sum << " 个"<< endl;
    return 0;
}
