#include "Function.h"
using namespace std;
int a[1000000];
int n;
int main(int argc, char *argv[]){
    if(argc != 7 || string(argv[1]) != "-a" || string(argv[3]) != "-i" || string(argv[5]) != "-o"){
        cout << "Error!";
        return 1;
    }
    ifstream f1;
    ofstream f2;
    string typeSort = argv[2];
    string s1 = argv[4];
    string s2 = argv[6];
    // đọc file
    f1.open(s1);
    f2.open(s2);
    if(!f1.is_open()){
        cout << "Cannot open file to read!";
        return 1;
    }
    if(!f2.is_open()){
        cout << "Cannot open file to write!";
        return 1;
    }
    f1 >> n;
    int dataType;
    for (int i = 0; i < n; i++){
        f1 >> a[i];
    }
    typeToSort(a, n, typeSort);
    for (int i = 0; i < n; i++){
        f2 << a[i] << " ";
    }
    f1.close();
    f2.close();
    return 0;
}