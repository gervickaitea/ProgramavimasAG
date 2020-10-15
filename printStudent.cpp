#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "printStudent.h"
#include "count_median.h"

void print_student(std::vector<duomenys> Eil, int pazymiu_sk) //atspausdina rezultatus
{
    std::ofstream output;
    output.open("rezultatai.txt");
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        output << std::setw(20) << std::left << Eil[i].Vard
            << std::setw(20) << std::left << Eil[i].Pav
            << std::setw(18) << std::left << Eil[i].GP
            << count_median(Eil[i].paz) << std::endl;
    }
    output << "\n\n";
}