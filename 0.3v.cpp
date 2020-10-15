#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>
#include "readFromFile.h"
#include "printStudent.h"



int main()
{
    int pazymiu_sk;
    char temp;
    std::vector<duomenys> Eil;
    readFromFile(Eil, &pazymiu_sk);
    print_student(Eil, pazymiu_sk);
    system("pause");
    return 0;
}
