#define pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>
#include <stdexcept>
#include <list>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stoi;
using std::getline;
using std::istringstream;
using std::swap;
using std::istream;
using std::streamsize;
using std::setprecision;
using std::max;
using std::list;


struct Studentas
{
    string Vardas, Pavarde;
    vector <int> Rezultatai;
    int     Egzaminas;
};


const string Error = "Jusu ivesti duomenys neatitinka reikalavimu. Bandykite dar karta.";

double Vidurkis(vector<int> Grade);
double Mediana(vector<int> Grade);
double GP(double Exam, double Score);
double GP(const Studentas& S, double (*Criteria)(vector<int>) = Vidurkis);
bool Raides(string Input);
bool Skaiciai(const string& str);
void DidRaid(string& Text);
bool Lyginimas(const Studentas& x, const Studentas& y);
void NewLine();
int pasirinkimas();

