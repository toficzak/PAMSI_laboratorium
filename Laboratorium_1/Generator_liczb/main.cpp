#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
   int zakres = 100;
   
   fstream plik;
   plik.open("Dane_testowe.txt", ios::out);
   
   
   for(int i = 0; i < 10000; i++)
      plik << rand()%zakres + 1 << endl;
   
   plik.close();
}