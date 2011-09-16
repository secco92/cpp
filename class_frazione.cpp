#include <iostream>
#include <math.h>
using namespace std;

class frazione{
	friend frazione somma(frazione,frazione);
	private:
		int num,den;
	  void semplifica();
		int mcd(int,int);
	public:
		frazione();
		frazione(int,int);
		void setNum(int);
		void setDen(int);
		void print();
};

frazione::frazione()
{
  num=0;
  den=1;
}

frazione::frazione(int a,int b)
{
  den=b;
	num=a;
}

frazione somma(frazione a,frazione b)
{
  frazione t;
	t.den=a.den*b.den;
  t.num=(a.num*b.den)+(b.num*a.den);
	t.print();
	if((t.num%t.den)!=0)
  t.semplifica();
	return t;
}

void frazione::setNum(int n)
{
  num=n;
}

void frazione::setDen(int n)
{
	den=n;
}

void frazione::print()
{
	if(den==1)
    cout << num << endl;
	else
  	cout<<num<<"/"<<den<<endl;
}

int frazione::mcd(int a,int b)
{
	if(a==b)
		return a;
	else if(a>b) return mcd(a-b,b);
	else if(a<b) return mcd(b-a,a);
}

void frazione::semplifica()
{
 	int MCD = mcd(num,den);
	num/=MCD;
	den/=MCD;
}

int main()
{
	frazione f1(9,0),f2(11,5),ris,f3(2,5);
	cout << "frazione 1: "; 
	f1.print();
	cout << endl;
	cout << "frazione 2: "; 
	f2.print();
	cout << endl;
	cout << "frazione 3: "; 
	f3.print(); 
	cout << endl;
	cout << "frazione ris: ";
	ris.print();
	cout << endl;
	ris=somma(f2,f3);
	cout << "risultato somma tra f2 e f3: ";
	ris.print();
	cout << endl;
	f1.setNum(4);
	f1.setDen(5);
	cout << "frazione f1 con numeratore e denominatore cambiati: ";
	f1.print();
	cout << endl;
	cin.get();
	return 0;
}
