#include <iostream>

using namespace std;

void input(double **p, int m, int n) {
    for(int i = 0; i < m; i++) {
        *(p + i) = new double[n];
        for(int j = 0; j < n; j++) {
            cout << "p[" << i << "][" << j << "] = ";
            cin >> *(*(p  + i) + j);
        }
    }
}

void output(double **p, int m, int n) {
    for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
        cout << *(*(p + i) + j) << "\t";
    cout << endl;
    }
}

void maxminofrows(double **p,int m, int n,double *maxrow, double *minrow) {
    for(int i = 0; i < m; i++) {
        *(maxrow + i) = *(*(p + i));
        *(minrow + i) = *(*(p + i));
        for(int j = 0; j < n; j++) {
            *(maxrow + i) = max(*(maxrow + i),*(*(p + i) + j));
            // *(maxrow + i) = *(maxrow + i) < *(*(p + i) + j) ? *(*(p + i) + j) : *(maxrow + i);
            *(minrow + i) = min(*(minrow + i),*(*(p + i) + j));
        }
        cout << "GIA TRI LON NHAT HANG " << i << ": " << *(maxrow + i) << endl << "GIA TRI NHO NHAT HANG " << i << ": " << *(minrow + i) << endl << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    double **p = new double*[m];
    input(p,m,n);
    output(p,m,n);
    double *maxrow = new double[m], *minrow = new double[m];
    maxminofrows(p,m,n,maxrow,minrow);
    for(int i = 0; i < m; i++) delete [] p[i];
    delete [] p; delete [] maxrow; delete [] minrow;
    return 0;
}

/*
**CẤP PHÁT TỐI ƯU
double *data = new double[m * n];
double **p = new double*[m];
for(int i = 0; i < m; i++) p[i] = data + i*n;
**DELETE TỐI ƯU
delete [] data; delete [] p;
*/