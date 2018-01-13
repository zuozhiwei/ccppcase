/*
    cpp   �ַ�����    �˵�    ����У��
    ������    ģ��ͨ�Ź��̣����ú���У���ж��Ƿ��д����λ
    ʱ��        2018-1-8
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/

#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
string s;
char ss[15];
void Hamming(string str)
{
    bitset<13>  b;
    int j=0;
    int sum;
    reverse(str.begin(),str.end());
    for(int i=12;i>0;i--)
    {
        if(i==1||i==2||i==4||i==8)
        {
            continue;
        } else
        {
            if(str[j]=='1')
            {
                b.set(i);
                j++;
            } else
            {
                j++;
            }
        }
    }
    sum=0;
    sum=b.test(3)+b.test(5)+b.test(7)+b.test(9)+b.test(11);
    if(1==sum%2)
    {
        b.set(1);
    }
    sum=0;
    sum=b.test(3)+b.test(6)+b.test(7)+b.test(10)+b.test(11);
    if(1==sum%2)
    {
        b.set(2);
    }
    sum=0;
    sum=b.test(5)+b.test(6)+b.test(7)+b.test(12);
    if(1==sum%2)
    {
        b.set(4);
    }
    sum=0;
    sum=b.test(9)+b.test(10)+b.test(11)+b.test(12);
    if(1==sum%2)
    {
       b.set(8);
    }
    cout<<"���������Ϊ:"<<endl;
    ss[0]='0';
    for(int k=1;k<=12;k++)
    {
        if(b[k]&1)
        {
            ss[k] = '1';
        }
        else{
            ss[k] ='0';
        }
        cout<<b[k];
    }
    s = ss;
    cout<<endl;
    //s = b.template to_string< char, char_traits<char>,allocator<char> >();
    cout<<endl;
}
void  ReHamming(string str)
{
    bitset<13> b;
    bitset<5>  keyb;
    bool a1=0,a2=0,a4=0,a8=0;
    int sum=0;
    int j=0;
    reverse(str.begin(),str.end());
    for(int i=12;i>=1;i--)
    {
        if(str[j]=='1')
        {
            b.set(i);
            j++;
        }else{
            j++;
        }
    }
    if((b.test(3)+b.test(5)+b.test(7)+b.test(9)+b.test(11))%2==1)
    {
        a1=1;
    }
    if((b.test(3)+b.test(6)+b.test(7)+b.test(10)+b.test(11))%2==1)
    {
        a2=1;
    }
    if((b.test(5)+b.test(6)+b.test(7)+b.test(12))%2==1)
    {
        a4=1;
    }
    if((b.test(9)+b.test(10)+b.test(11)+b.test(12))%2==1)
    {
        a8=1;
    }
    if(b.test(1))
    {
        keyb.set(1);
    }
    if(b.test(2)==1)
    {
        keyb.set(2);
    }
    if(b.test(4)==1)
    {
        keyb.set(3);
    }
    if(b.test(8)==1)
    {
        keyb.set(4);
    }
    if(a1!=keyb.test(1))
    {
        sum+=1;
    }
    if(a2!=keyb.test(2))
    {
        sum+=2;
    }
    if(a4!=keyb.test(3))
    {
        sum+=4;
    }
    if(a8!=keyb.test(4))
    {
        sum+=8;
    }
    if(sum==0)
    {
        cout<<"�����������ȷ����"<<endl;
    }
    else if(sum>1&&sum<=12)
    {
        cout<<"�������"<<sum<<"λ����"<<endl;
        cout<<"��ȷ����Ϊ��"<<endl;
        if(b.test(sum)==1)
        {
            b.reset(sum);
        }
        else
        {
            b.set(sum);
        }
        for(int v=1;v<13;v++)
        {
            cout<<b[v];
        }
        cout<<endl;
    }
    else{
        cout<<"��λλ������1λ���޷�����"<<endl;
    }
    cout<<endl;
}
int main(int argc, char* argv[])
{
    string str;
    int select,x;
    cout<<"����Ҫ���͵Ķ��������У�"<<endl;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!='1'&&str[i]!='0')
        {
            cout<<"���벻�Ϸ���ֻ�ܰ���0,1�ַ���"<<endl;
            return 0;
        }
    }
    if(str.size()<=8&&str.size()>=1)
    {
        select=1;
    }else
        select=2;
    switch(select)
    {
        case 1:
            Hamming(str);
            break;
        case 2:
            cout<<"�������ݳ��Ȳ��Ϸ�������Ӧ��1~12������"<<endl;
            break;
    }
    cout<<"���ݴ������Ƿ������󣿣�1.�޴���2.����������У�"<<endl;
    cin>>x;
    if(x==1)
    {
        cout<<"���ܵ�������Ϊ��"<<endl;
        for(int i=1;i<=12;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
        ReHamming(s);
    }else if (x==2){
        string temp;
        cout<<"�����������(�޸�����ĳһλ��ĳ��λ)"<<endl;
        cin>>temp;
        cout<<"���ܵ�������Ϊ��"<<endl;
        cout<<temp<<endl;
        ReHamming(temp);
    }else{
        cout<<"��������"<<endl;
        return 0;
    }
  return 0;
}
