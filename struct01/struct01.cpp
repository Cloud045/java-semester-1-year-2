#include<iostream>
#include<math.h>
#define getbit(x,i) ((x>>(i))&1)
#define onbit(x,i) (x|(1<<i))
#define offbit(x,i) ()


using namespace std;
void print_bin(int x)
{
    for (int i = 31; i >= 0; i--) cout << getbit(x, i);
    cout << "\n";
}
int ex1(int x,int m)
{
    return (x | m);
}
int ex2(int x,int m)
{
    return (x & m);
}
int ex3(int x,int m)
{
    return (x << m);
}
int ex4(int x,int m)
{
    return (x >> m);
}
int ex5(int x,int n)
{
    return (x | (1 << n));
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "ИКБО-04-21-Нгием-Ву-Винь-Прак-01\n";
    int x;
    int m;
    int n;
    int num;
    cout << " 1. Задать 5, 7 биту значение 1. \n 2. Обнулить С 9-ого четыре слева. \n 3. Умножить ваше число на 8. \n 4. делит  заданое число на 8. \n 5. Установить n-ый бит в 1, используя маску 1. \n";
    cin >> num;
    switch(num) {
    case 1: {
        m = 0xA0;
        cout << "Input x : ";
        cin >> x;
        cout << "dex(x)= " << x << "\ndex(m)= " << m << "\n";
        cout << "bin(x): ";
        print_bin(x);
        cout << "bin(m): ";
        print_bin(m);
        x = ex1(x, m);
        cout << "x|m = " << x << "\n";
        cout << "bin(x): ";
        print_bin(x);
        break;
    }
    case 2: {
        m = ~(~(~(~0 << 4)) << 9);
        cout << "Input x : ";
        cin >> x;
        cout << "dex(x)= " << x << "\ndex(m)= " << m << "\n";
        cout << "bin(x): ";
        print_bin(x);
        cout << "bin(m): ";
        print_bin(m);
        cout << "x&m = " << ex2(x, m) << "\n";
        break;
    }
    case 3: {
        cout << "Input x : ";
        cin >> x;
        cout << "bin(x): ";
        print_bin(x);
        x = ex3(x, 3);
        cout << "x << 3 = " << x << "\n";
        cout << "bin(x): ";
        print_bin(x);
        break;
    }
    case 4: {
        cout << "Input x : ";
        cin >> x;
        cout << "bin(x): ";
        print_bin(x);
        x = ex4(x, 3);
        cout << "x >> 3 = " << x << "\n";
        cout << "bin(x): ";
        print_bin(x);
        break;
    }
    case 5: {
        cout << "Input x : ";
        cin >> x;
        cout << "Input n: ";
        cin >> n;
        cout << "bin(x): ";
        print_bin(x);
        x = ex5(x, n);
        cout << "x onbit " << n << " = " << x << "\n";
        cout << "bin(x): ";
        print_bin(x);
        break;
    }
    }
}
