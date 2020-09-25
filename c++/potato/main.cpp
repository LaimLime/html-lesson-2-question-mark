#include <iostream>
#include <fstream>

using namespace std;

struct struktura{
    string name;
    int k, liko;
    double kaina;
};
void rikiavimas(int p, struktura par[]);
int main()
{
    int n, p;
    struktura kai[50]; //kainos
    struktura par[50]; //pardavimai

    ifstream in("kainos.txt");
    in >> n;
    char x[15];

    for(int i = 0; i < n; i++){

        in.ignore(80, '\n');
        in.get(x, 15);
        kai[i].name = x;

        in >> kai[i].k >> kai[i].kaina;
        kai[i].liko = kai[i].k;
    }
    in.close();

    ifstream in2("pardavimai.txt");
    in2 >> p;
    for(int i = 0; i < p; i++){

        in2.ignore(80, '\n');
        in2.get(x, 15);
        par[i].name = x;

        in2 >> par[i].k >> par[i].kaina;
    }
    in2.close();

    rikiavimas(p, par);

    double ukininkas, jonas;



    for(int i = 0; i < p; i++){


        for(int j = 0; j < n; j++){

            if(par[i].name == kai[j].name){
                if(kai[j].liko - par[i].k >= 0){
                    kai[j].liko -= par[i].k;

                    if(par[i].kaina >= kai[i].kaina){

                        ukininkas += par[i].kaina;
                    }
                    else{
                        kai[j].liko -= par[i].k % kai[j].liko;

                    }
                }
            }
        }
    }


    cout << "Parduota:" << endl;
    for(int i = 0; i < n; i++){
        cout << kai[i].name << kai[i].k - kai[i].liko << endl;
    }
    cout << "Liko neparduota" << endl;
    for(int i = 0; i < n; i++){
        if(kai[i].liko > 0){
            cout << kai[i].name << kai[i].liko << endl;
        }
    }
    for(int i = 0; i < p; i++){
        cout << par[i].name << par[i].k << " " << par[i].kaina << endl;
    }
    return 0;
}
void rikiavimas(int p, struktura par[])
{
    int did = 0;

    for(int i = 0; i < p; i++){
        did = i;
        for(int j = i + 1; j < p - 1; j++){

            if(par[j].kaina > par[did].kaina){

                did = j;
            }
        }
        swap(par[i], par[did]);
    }
}
