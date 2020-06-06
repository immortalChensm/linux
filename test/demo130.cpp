//
// Created by Administrator on 2020/6/6.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("in.txt");

    ofstream fout("out.txt");

    streambuf *oldcin;
    streambuf *oldcout;

    char a[100];
    oldcin = cin.rdbuf(fin.rdbuf());
    cin>>a;

    oldcout = cout.rdbuf(fout.rdbuf());

    cout<<a<<endl;

    cin.rdbuf(oldcin);
    cout.rdbuf(oldcout);

    fin.close();
    fout.close();

    return 0;
}