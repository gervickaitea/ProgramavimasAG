#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>

struct duomenys {
    std::string Vard, Pav;
    std::vector<int> paz = { 0 };
    int egz;
    float GP = 0;
};


float count_median(std::vector<int> pazymiai) //funkcija suskaiciuoja mediana
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] != 0)
        {
            counter++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0)
    {
        return float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        return float(pazymiai[(counter / 2)]);
    }
}

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

unsigned int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void read_from_file(std::vector<duomenys>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    std::string buff;
    fileRead.open("studentai100000.txt.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).Vard;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(student_counter).Pav;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;
            //std::cout << Eil.at(student_counter).Vard;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
        }
    }
    else { std::cout << "-\n"; }
}

int main()
{
    int pazymiu_sk;
    char temp;
    std::vector<duomenys> Eil;
    read_from_file(Eil, &pazymiu_sk);
    print_student(Eil, pazymiu_sk);
    system("pause");
    return 0;
}