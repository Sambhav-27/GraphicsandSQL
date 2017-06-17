#include<bits/stdc++.h>
using namespace std;
void sum(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int n)
{
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            C[i][j]=A[i][j]+B[i][j];
}
void sub(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int n)
{
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            C[i][j]=A[i][j]-B[i][j];
}

void strassen(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int n)
{
    if(n<2)
    {
        C[0][0]=A[0][0]*B[0][0]; return;
    }
    else
    {
        int t=n/2;
        vector<int> inner(t);
        vector< vector<int> > a11(t, inner), a12(t, inner), a21(t, inner), a22(t, inner), b11(t, inner), b12(t, inner), b21(t, inner), b22(t, inner), c11(t, inner),
        c12(t, inner), c21(t, inner), c22(t, inner), p1(t, inner), p2(t, inner), p3(t, inner), p4(t, inner), p5(t, inner), p6(t, inner), p7(t, inner), aresult(t, inner), bresult(t, inner);

        int i,j;
        for(i=0;i<t;++i)
        {
            for(j=0;j<t;++j)
            {
                a11[i][j]=A[i][j];
                a12[i][j]=A[i][j+t];
                a21[i][j]=A[i+t][j];
                a22[i][j]=A[i+t][j+t];

                b11[i][j]=B[i][j];
                b12[i][j]=B[i][j+t];
                b21[i][j]=B[i+t][j];
                b22[i][j]=B[i+t][j+t];
            }
        }
        sum(a11, a22, aresult, t);
        sum(b11, b22, bresult, t);
        strassen(aresult, bresult, p1, t);

        sum(a21, a22, aresult, t);
        strassen(aresult, b11, p2, t);

        sub(b12, b22, bresult, t);
        strassen(a11, bresult, p3, t);

        sub(b21, b11, bresult, t);
        strassen(a22, bresult, p4, t);

        sum(a11, a12, aresult, t);
        strassen(aresult, b22, p5, t);

        sub(a21, a11, aresult, t);
        sum(b11, b12, bresult, t);
        strassen(aresult, bresult, p6, t);


        sub(a12, a22, aresult, t);
        sum(b21, b22, bresult, t);
        strassen(aresult, bresult, p7, t);

        sum(p3, p5, c12, t);
        sum(p2, p4, c21, t);

        sum(p1, p4, aresult, t);
        sum(aresult, p7, bresult, t);
        sub(bresult, p5, c11, t);

        sum(p1, p3, aresult, t);
        sum(aresult, p6, bresult, t);
        sub(bresult, p2, c22, t);

        // final matrix
        for(i=0;i<t;++i)
        {
            for(j=0;j<t;++j)
            {
                C[i][j]=c11[i][j];
                C[i][j+t]=c12[i][j];
                C[i+t][j]=c21[i][j];
                C[i+t][j+t]=c22[i][j];
            }
        }


    }
}

int main()
{
    int i,j,n=4;
    vector< int > inner(n);
    vector< vector<int> > A(n, inner), B(n, inner), C(n, inner);


    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            cin>>A[i][j];
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            cin>>B[i][j];
    }
    strassen(A, B, C, n);
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            cout<<C[i][j]<<"  ";
        cout<<"\n\n";
    }


}
