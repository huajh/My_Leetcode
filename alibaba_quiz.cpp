// 一个摸金校尉要通过一个矩形墓室，入口的位置为(0,0)，出口的位置为(m,n)。
// 墓室中散布着一些激光发射器，某些激光发射器之间有激光。
// m,n和激光的起始和终止位置(x1,y1,x2,y2)均为整数。请问他能否不碰到激光，成功通过墓室。


// 编译器版本: gcc 4.8.4
// 请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
// 时间限制: 1S (C/C++以外的语言为: 3 S)   内存限制: 64M (C/C++以外的语言为: 576 M)
// 输入:
// 共2行。 第1行，为m和n，空格分隔。 第2行，第一个数字为激光的个数，后面为每个激光的起始和终止位置的坐标x1,y1,x2,y2，都为空格分隔。
// 输出:
// 共一行，0或1，0表示不能通过墓室，1表示可以通过。
// 输入范例:
// 100 80
// 3 10 2 8 25 44 12 6 6 5 6 10 51
// 输出范例:
// 1


#include <iostream>
#include <string.h>

#include <vector>
#include<stack>
#include <cmath>

using namespace std;



class point
{
private:
    int x;
    int y;
public:
    point(int x0, int y0): x(x0), y(y0){}
    int getx(){
        return x;
    }
    int gety()
    {
        return y;
    }
};

void swap0(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

bool Find(int m, int n, const vector<int>& tx, const vector<int>& ty,
          const vector<int>& wx, const vector<int>& wy)
{
    bool ** accessable = new bool*[m+1];
    bool ** visitored = new bool*[m+1];
    for (int i=0;i<m+1;i++)
    {
        accessable[i] = new bool [n+1];
        visitored[i] = new bool [n+1];
        
        memset(accessable[i], 1, (n+1) * sizeof(bool));
        memset(visitored[i], 0, (n+1) * sizeof(bool));
    }
    
    // flag the line
    unsigned long line_num = tx.size();
    for (int i=0;i<line_num;i++)
    {
        int x1 = tx[i], y1 = ty[i], x2 = wx[i], y2 = wx[i];
        if (x1>=x2)
        {
            swap0(x1,x2);
            swap0(y1,y2);
        }
        double k = ((double)(y2-y1))/(x2-x1);
        accessable[x1][y1] = false;
        accessable[x2][y2] = false;
        if (abs(k)<=1)
        {
            for (int x=x1+1;x<x2;x++)
            {
                int y = (int) (y1+k*(x-x1));
                accessable[x][y] = false;
            }
        }else
        {
            k=1/k;
            for (int y=y1+1;y<y2;y++)
            {
                int x = (int) (x1+k*(y-y1));
                accessable[x][y] = false;
            }
        }
    }
    
    stack<point> sta;
    sta.push(point(0,0));
    bool is_find = false;
    while(!sta.empty())
    {
        point cur = sta.top();
        sta.pop();
        
        int x = cur.getx();
        int y = cur.gety();
        
        visitored[x][y] = 1;
        
        if (x == m && y == n)
        {
            is_find = true;
            break;
        }
        if (x-1>=0 && accessable[x-1][y] && !visitored[x-1][y])
        {
            sta.push(point(x-1,y));
        }
        if (x+1<=m && accessable[x+1][y] && !visitored[x+1][y])
        {
            sta.push(point(x+1,y));
        }
        if (y-1>=0 && accessable[x][y-1] && !visitored[x][y-1])
        {
            sta.push(point(x,y-1));
        }
        if (y+1<=n && accessable[x][y+1] && !visitored[x][y+1])
        {
            sta.push(point(x,y+1));
        }
    }
    

    for (int i =0;i<m+1; i++)
    {
        delete [] accessable[i];
        accessable[i] = NULL;
        delete [] visitored[i];
        visitored[i] = NULL;
    }
    delete [] accessable;
    accessable = NULL;
    delete [] visitored;
    visitored = NULL;
    
    return is_find;
    
}


int main()
{
    int m = 0;
    int n = 0;
    vector<int> tx;
    vector<int> ty;
    vector<int> wx;
    vector<int> wy;
    int num = 0;
    cin>>m;
    cin>>n;
    cin>>num;
    for (int i = 0; i < num; ++i) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        tx.push_back(x1);
        ty.push_back(y1);
        wx.push_back(x2);
        wy.push_back(y2);
    }
    cout << Find(m,n,tx,ty,wx,wy) << endl;
    return 0;
}

// 100 80
// 3 10 2 8 25 44 12 6 6 5 6 10 51
