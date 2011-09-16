#include <iostream>
#define DIM 10
using namespace std;
int main()
{
   int num,vet[DIM];
   cout << "inserire 10 numeri: ";
   
   for(int i=0;i<DIM;i++)
   {
      cin >> num;
      vet[i]=num;
   }
      
   for(int i=0;i<DIM;i++)
      cout << vet[i] << ' ';
      
   cin.get();
   return 0;
}
