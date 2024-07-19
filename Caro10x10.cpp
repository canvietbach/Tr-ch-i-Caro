#include <bits/stdc++.h> 
#define ll int
using namespace std;
char a[100][100];
vector<ll>x;
ll uio, oiu;
void Print()
{
    x.clear();
    x.push_back(-1);
    x.push_back(-1);
    x.push_back(-1);
    x.push_back(-1);
    x.push_back(-1);
    x.push_back(-1);
    x.push_back(-1);
    x.push_back(-1);
    for(ll i = 1; i <= oiu; i++)
    {
        x.push_back(i);
        x.push_back(-1);   
        x.push_back(-1);
        x.push_back(-1);
        x.push_back(-1);
    }
    for(auto i : x)
    {
        if(i == -1) cout << ' ';
        else cout << i;
    }
    cout << '\n';
    for(ll i = 1; i <= uio; i++)
    {
        ll danh_dau = 0;
        if(i >= 10 && i < 100)
        {
            cout << i;
            danh_dau++;
        }
        else if(i >= 100 && i < 1000)
        {
            cout << i;
            danh_dau += 2;
        }
        else if(i >= 1000 && i < 10000)
        {
            cout << i;
            danh_dau += 3;
        }
        else
        {
            cout << i;
        }
        ll h = 1;
        for(ll j = 1 + danh_dau; j <= x.size(); j++)
        {
            if(x[j] != -1 && h <= oiu) 
            {
                cout << a[i][h];
                if(h >= 10 && h < 100) cout << " ";
                else if(h >= 100 && h < 1000) cout << "  ";
                else if(h >= 1000 && h < 10000) cout << "   ";
                h++;
            }
            else cout << ' ';
        }
        cout << '\n';
    }
}
int check()
{
    for(int i = 1; i <= uio; i++)
    {
        int ans_X = 0;
        int ans_O = 0;
        for(int j = 1; j <= oiu; j++)
        {
            if(a[i][j] == 'X')
            {
                ans_X++;
                ans_O = 0;
            }
            else if(a[i][j] == 'O')
            {
                ans_X = 0;
                ans_O++;
            }
            else
            {
                ans_X = 0;
                ans_O = 0;
            }
            if(ans_X == 5 || ans_O == 5) return 1;
        }
    }
    for(int i = 1; i <= uio; i++)
    {
        int ans_X = 0;
        int ans_O = 0;
        for(int j = 1; j <= oiu; j++)
        {
            if(a[j][i] == 'X')
            {
                ans_X++;
                ans_O = 0;
            }
            else if(a[j][i] == 'O')
            {
                ans_X = 0;
                ans_O++;
            }
            else
            {
                ans_X = 0;
                ans_O = 0;
            }
            if(ans_X == 5 || ans_O == 5) return 1;
        }
    }
    for(ll i = 1; i <= uio; i++)
    {
        int ans_X = 0;
        int ans_O = 0;
        ll n = i;
        ll j = 1;
        while(n != 0)
        {
            if(a[n][j] == 'X')
            {
                ans_X++;
                ans_O = 0;
            }
            else if(a[n][j] == 'O')
            {
                ans_X = 0;
                ans_O++;
            }
            else
            {
                ans_X = 0;
                ans_O = 0;
            }
            if(ans_X == 5 || ans_O == 5) return 1;
            n--; j++;
        }
    }
    for(ll i = 1; i <= uio; i++)
    {
        ll m = i;
        ll j = oiu;
        int ans_X = 0;
        int ans_O = 0;
        while(m <= uio)
        {
            if(a[m][j] == 'X')
            {
                ans_X++;
                ans_O = 0;
            }
            else if(a[m][j] == 'O')
            {
                ans_X = 0;
                ans_O++;
            }
            else
            {
                ans_X = 0;
                ans_O = 0;
            }
            if(ans_X == 5 || ans_O == 5) return 1;
            m++; j--;
        }
    }
    for(ll i = uio; i > 0; i--)
    {
        ll n = i;
        ll j = 1;
        int ans_X = 0;
        int ans_O = 0;
        while(n <= uio)
        {

            if(a[n][j] == 'X')
            {
                ans_X++;
                ans_O = 0;
            }
            else if(a[n][j] == 'O')
            {
                ans_X = 0;
                ans_O++;
            }
            else
            {
                ans_X = 0;
                ans_O = 0;
            }
            if(ans_X == 5 || ans_O == 5) return 1;
            n++; j++;
        }
    }
    for(ll i = 2; i <= oiu; i++)
    {
        ll m = i;
        ll j = 1;
        int ans_X = 0;
        int ans_O = 0;
        while(j <= oiu)
        {
            if(a[j][m] == 'X')
            {
                ans_X++;
                ans_O = 0;
            }
            else if(a[j][m] == 'O')
            {
                ans_X = 0;
                ans_O++;
            }
            else
            {
                ans_X = 0;
                ans_O = 0;
            }
            if(ans_X == 5 || ans_O == 5) return 1;
            m++; j++;
        }
    }
    return 0;
}
int main()
{
    cout << "Nhập kích thước: ";
    cin >> uio >> oiu;
    while(uio > 10000 || uio < 1 || oiu > 10000 || oiu < 1)
    {
        cout << "Lỗi dữ liệu: ";
        cin >> uio >> oiu;
    }
    for(ll i = 1; i <= uio; i++)
    {
        for(ll j = 1; j <= oiu; j++) a[i][j] = '|';
    }
    cout << '\n';
    Print();
    cout << '\n';
    char nhap;
        cout << "Chọn X (đi trước) hay O (đi trước): "; 
        cin >> nhap;
        while(nhap != 'X' && nhap != 'O') 
        {
            cout << "Nhập lại ( Chỉ được nhập X hoặc O ): ";
            cin >> nhap;
        }
        ll luot = uio * oiu;
        while (luot--)
        {
            Print();
            ll i, j;
            cout << '\n';
            cout << "Người chơi "<< nhap <<" chọn ô: ";
            cin >> i >> j;
            while(true)
            {
                cout << "\033[2J\033[1;1H";
                if(i > uio || i < 1 || j < 1 || j > oiu)
                {
                    cout << "Ô KHÔNG HỢP LỆ\n";
                    cout << "Nhập lại: ";
                    cin >> i >> j;
                }
                else if(a[i][j] != '|')
                {
                    cout << "Ô ĐÃ NHẬP RỒI\n";
                    cout << "Nhập lại: ";
                    cin >> i >> j;
                }
                else break;
            }
            a[i][j] = nhap;
            if(check() == 1)
            {
                cout << "->NGƯỜI CHƠI " << nhap << " THẮNG\n";
                Print();
                break;
            } 
            if(nhap == 'X') nhap = 'O';
            else nhap = 'X';
        }
        if(luot == 0)
        {
            Print();
            cout << "\nHOA";
        } 
}