#include "stos.h"
#include "czas.h"
#include <time.h>
#include <chrono>

int main(int argc, char* argv[])
{
   
   using namespace std::chrono;
   //timespec ts_beg, ts_end;
 
   Stos A;
   
   Stoper czas;
   A.Opcje(argc, argv);
   
   int *Dane = A.Pobierz_dane();
   /*
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_beg);

   for(int i = 0; i < A.zakres; i++)
      A.push(Dane[i]);
   
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_end);

   cout << (ts_end.tv_sec - ts_beg.tv_sec) + (ts_end.tv_nsec - ts_beg.tv_nsec) / 1e9 << " sec\n";

   fstream plik;
   plik.open("Wyniki_temp.txt", ios::out | ios::app);
   
   plik << (ts_end.tv_sec - ts_beg.tv_sec) + (ts_end.tv_nsec - ts_beg.tv_nsec) / 1e9 << endl;

   plik.close();
   *//*
   czas.Start();
   
   for(int i = 0; i < A.zakres; i++)
      A.push(Dane[i]);
   
   czas.Stop();
   czas.Eksport_wyniki();
   */
   auto start=high_resolution_clock::now();
   
   for(int i = 0; i < A.zakres; i++)
      A.push(Dane[i]);
   
   auto diff=duration_cast<nanoseconds>(high_resolution_clock::now()-start);
   //clog << diff.count() << "ns elapsed" << endl;
	      
   fstream plik;
   plik.open("Wyniki_temp.txt", ios::out | ios::app);
   
   plik << diff.count() << endl;
   
   plik.close();
  
}