#include"iostream"
using namespace std;
typedef unsigned char uchar;

char cc[2]={'+','-'};   //�������
int n,                  //��һ�з�������
    half,               //ȫ����������һ��
    counter;            //1����������-���ż���
uchar **p;              //���Ŵ洢�ռ�
long sum;               //���������������μ���

void Backtrace(int t)   //t����һ�е�t������
{
    int i, j;
    if( t > n )
    {//����������
        sum++;
        //��ӡ����
        cout << "��" << sum << "��:\n";
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
            p[1][t] = i;        //��һ�е�t������
            counter += i;       //��-����ͳ��,��Ϊ"+"��ֵ��0

            for(j=2; j<=t; ++j)  //����һ�з���>=2ʱ����������������е�ĳЩ���ţ�j�ɴ����к�
            {
               p[j][t-j+1] = p[j-1][t-j+1]^p[j-1][t-j+2];//ͨ������������з��ţ�t-j+1ȷ���ĺ���
               counter += p[j][t-j+1];
            }
            if( (counter <= half) && ( t*(t+1)/2 - counter <= half) )
            {//������ͳ��δ����������������һ�ַ���Ҳδ����������ͬʱ�������߱�����Ȳ��ܽ���
                Backtrace(t+1);         //�ڵ�һ��������һ������
            }
            //���ݣ��ж���һ�ַ������   ���ǳ�ջһ�����ָ����ж�counter�Ĳ���
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
    cout << "�������һ�з��Ÿ���n��";
    cin >> n;
    counter = 0;
    sum = 0;
    half = n*(n+1)/2;
    int i=0;

    if( half%2 == 0 )
    {//������Ϊż������Ϊ�������޽�
        half /= 2;
        p = new uchar *[n+1];

        for(i=0; i<=n; ++i)
        {
           p[i] = new uchar[n+1];
           memset(p[i], 0, sizeof(uchar)*(n+1));
        }

        Backtrace(1);
        for(i=0; i<=n; ++i)   //ɾ����ά��̬����ķ���
        {
            delete[] p[i];
        }
        delete[] p;
    }

    cout << "\n�ܹ� " << sum << " ��"<< endl;
    return 0;
}
