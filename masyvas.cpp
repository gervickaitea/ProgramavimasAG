#include <iostream>
#include <string>
#include <iomanip>

struct duomenys {
    std::string Vard, Pav;
    int paz[10] = { 0 };
    int egz;
    float GP = 0;
};

void count_median(int pazymiai[]) //funkcija suskaiciuoja mediana
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] > 0)
        {
            counter++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            //counter--;
            break;
        }
    }
    if (counter % 2 == 0) 
    {
        std::cout << float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        std::cout << pazymiai[(counter / 2)];
    }
    std::cout << std::endl;
}

int generate_random_mark() //sugeneruoja random skaiciu nuo 1 iki 10
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

void automated_marks_input(duomenys Eil[], int i, int how_many_marks) //funckija automatiskai suveda pazymius ir egz. pazymi
{
    Eil[i].egz = generate_random_mark();
    for (int x = 0; x < how_many_marks; x++)
    {
        Eil[i].paz[x] = generate_random_mark();
    }
    Eil[i].GP = Eil[i].GP / how_many_marks;
    Eil[i].GP = Eil[i].GP * 0.4 + 0.6 * Eil[i].egz;

}


void input_by_hand(duomenys Eil[], int i) //funkcija duoda vartotojui suvest pazymius ir egzamino pazymi
{
    do {
        std::cout << "Iveskite studento egzamino pazymi:\n";
        std::cin >> Eil[i].egz;
    } while (Eil[i].egz < 0 || Eil[i].egz > 10);
    std::cout << "Iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
    int counter = 0;
    do {
        std::cin >> Eil[i].paz[counter];
        if (Eil[i].paz[counter] != -1) { Eil[i].GP = Eil[i].GP + (float)Eil[i].paz[counter]; }
        counter++;
    } while (Eil[i].paz[counter - 1] != -1);
    counter--;
    Eil[i].GP = Eil[i].GP / counter;
    Eil[i].GP = Eil[i].GP * 0.4 + 0.6 * Eil[i].egz;
}
bool has_digit(std::string s)
{
    return (s.find_first_of("0123456789") != std::string::npos);
}

void name_input(duomenys Eil[], int i) //duoda suvest vardus ir pavardes
{
    std::cout << "Iveskite studento nr. " << i + 1 << " duomenis:\n";
    do {
        std::cout << "Iveskite studento nr. " << i + 1 << " VARDA:\n";
        std::cin >> Eil[i].Vard;
    } while (Eil[i].Vard.length() < 0 || Eil[i].Vard.length() > 25 || has_digit(Eil[i].Vard));
    do {
        std::cout << "Iveskite studento nr. " << i + 1 << " PAVARDE:\n";
        std::cin >> Eil[i].Pav;
    } while (Eil[i].Pav.length() < 0 && Eil[i].Pav.length() > 25 || has_digit(Eil[i].Pav));
    std::cout << std::endl;
}

void print_student(duomenys Eil[], int studentu_sk) //atspausdina rezultatus
{
    std::cout << "\n\n";
    std::cout << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        std::cout << std::setw(20) << std::left << Eil[i].Vard
            << std::setw(20) << std::left << Eil[i].Pav
            << std::setw(18) << std::left << Eil[i].GP;
        count_median(Eil[i].paz);
    }
    std::cout << "\n\n";
}

int main()
{
    int studentu_sk;
    char temp;
    do
    {
        std::cout << "Iveskite studentu kieki:\n";
        std::cin >> studentu_sk;
    } while (int(studentu_sk) < 0 || int(studentu_sk) > 255);
    duomenys Eil[25];
    //std::vector<duomenys> Eil_vect;
    do
    {
        std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai - SPAUSKITE \"R\"\n Jeigu norite suvesti duomenis patys - RASYKITE \"P\"\n";
        std::cin >> temp;
        if (temp != 'r' && temp != 'R' && temp != 'p' && temp != 'P') { std::cout << "pakartokite, netinkamas simbolis\n"; }
    } while (temp != 'r' && temp != 'R' && temp != 'p' && temp != 'P');
    for (int i = 0; i < studentu_sk; i++)
    {
        name_input(Eil, i);
        if (temp == 'p' || temp == 'P') { input_by_hand(Eil, i); }
        else { automated_marks_input(Eil, i, 5); }
    }
    print_student(Eil, studentu_sk);
    system("pause");
    return 0;
}