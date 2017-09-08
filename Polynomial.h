#include "iostream"
#include "cmath"

#include "CircularList.h"

using namespace std;

class Polynomial{
private:
    CircularList *List;
public:

    Polynomial();
    Polynomial(Polynomial &P);
    ~Polynomial();


    void set(int[], int);
    void ls();
    void get(int[], int);
    Polynomial& derivative();

    friend ostream& operator<<(ostream& ost, const Polynomial& pol);
    friend istream& operator>>(istream& ist, const Polynomial& pol);

	friend Polynomial& operator+(const int i, Polynomial& cl);
	friend Polynomial& operator-(const int i, Polynomial& cl);
	friend Polynomial& operator*(const int i, Polynomial& cl);

	friend Polynomial& operator+(Polynomial& cl, const int i);
	friend Polynomial& operator-(Polynomial& cl, const int i);
	friend Polynomial& operator*(Polynomial& cl, const int i);

	Polynomial& operator+(Polynomial& right);
	Polynomial& operator-(Polynomial& right);
	Polynomial& operator*(Polynomial& right);



	friend Polynomial& operator+=(Polynomial& cl, const int);
	friend Polynomial& operator-=(Polynomial& cl, const int);
	friend Polynomial& operator*=(Polynomial& cl, const int);


	Polynomial& operator+=(Polynomial& right);
	Polynomial& operator-=(Polynomial& right);
	Polynomial& operator*=(Polynomial& right);

	int is_zero();

	bool operator==(Polynomial& right);	
	bool operator!=(Polynomial& right);

	int operator()(int);





};

