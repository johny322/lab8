#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#define _USE_MATH_DEFINES

using namespace std;
const int n = 100;
const int m = 100;
const double pi = M_PI;
int var = 1;
double a = 1.0, T = 1.0;
double U(double x, double t)
{
if (var == 1)
return exp(- 4.0 * 3.14159265 * 3.14159265 *t)*sin(2.0 * 3.14159265 * x);
}
/////////////////////////////////////////
double F(double x)
{
return U(x, 0);
}
double M1(double t)
{
return U(0, t);
}
double M2(double t)
{
return U(T, t);
}
///////////////////////////////////////////
int main()
{
fstream f1,f2;
setlocale(LC_ALL, "Russian");
//cout << "Введите:\n 1" << endl;
//cin >> var;
var = 1;
if (var == 1) { a = 1.0, T = 1.0; }
double he = a / n, Te = T / m;
double L = Te / (he*he);
double A = L, B = L, C = 2 * L + 1;
double x[n + 1];
for (int i = 0; i <= n; i++)
{
x[i] = 0 + i*he;
}
double t[m + 1];
for (int j = 0; j <= m; j++)
{
t[j] = 0 + Te*j;
}
double alpha[n + 1];
double beta[n + 1];
double u[n + 1][m + 1];
double u2[2 * n + 1][2 * m + 1];
for (int i = 0; i<n + 1; i++)
{
for (int j = 0; j<m + 1; j++)
{
u[i][j] = 0;
}
}
for (int j = 0; j <= m; j++)
{
u[0][j] = U(0, t[j]);
if (var == 1)u[n][j] = 0;
else u[n][j] = U(a, t[j]);
}
for (int i = 0; i <= n; i++)
{
u[i][0] = U(x[i], 0);
}
for (int j = 0; j<m; j++)
{
alpha[1] = 0;
beta[1] = M1(t[j + 1]);
for (int i = 1; i<n; i++)
{
alpha[i + 1] = B / (C - (A*alpha[i]));
beta[i + 1] = (0.0 - u[i][j] - A*beta[i]) / (A*alpha[i] - C);
}
for (int i = n - 1; i>0; i--)
{
u[i][j + 1] = alpha[i + 1] * u[i + 1][j + 1] + beta[i + 1];
}
}
double he1 = a / (2 * n), Te1 = T / (2 * m);
double L1 = Te1 / (he1*he1);
double A1 = L1, B1 = L1, C1 = (2 * L1) + 1;
double x2[2 * n + 1];
for (int i = 0; i <= 2 * n; i++)
{
x2[i] = 0 + i*he;
}
double t2[2 * m + 1];
for (int j = 0; j <= 2 * m; j++)
{
t2[j] = 0 + Te*j;
}
double alpha2[2 * n + 1];
double beta2[2 * n + 1];
for (int i = 0; i<2 * n + 1; i++)
{
for (int j = 0; j<2 * m + 1; j++)
{
u2[i][j] = 0;
}
}
for (int j = 0; j <= 2 * m; j++)
{
u2[0][j] = U(0, t2[j]);
u2[2 * n][j] = U(a, t2[j]);
}
for (int i = 0; i <= 2 * n; i++)
{
u2[i][0] = U(x2[i], 0);
}
for (int j = 0; j<2 * m; j++)
{
alpha2[1] = 0;
beta2[1] = M1(t2[j + 1]);
for (int i = 1; i<2 * n; i++)
{
alpha2[i + 1] = B / (C - (A*alpha2[i]));
beta2[i + 1] = (0.0 - u2[i][j] - A*beta2[i]) / (A*alpha2[i] - C);
}
for (int i = 2 * n - 1; i>0; i--)
{
u2[i][j + 1] = alpha2[i + 1] * u2[i + 1][j + 1] + beta2[i + 1];
}
}

f1.open("u.txt", ios::out);f2.open("U_.txt", ios::out);
for(int i = 0; i < n + 1; i++){
    for(int j = 0; j < m + 1; j++){
        if(f1){f1 << x[i] << "   " << t[j] << "  " << u[i][j] << endl;}
        if(f2){f2 << x[i] << "   " << t[j] << "  " << U(x[i],t[j]) << endl;}
        }
    }
f1.close();f2.close();
cout << "Programma zavershila rabotu." << endl;
return 0;
}
