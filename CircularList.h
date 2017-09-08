#ifndef __H_CIRCULARLIST
#define __H_CIRCULARLIST 0




#include "iostream"
#include <vector>

using namespace std;

class CircularList
{
private:
	int coeff;
	int index;

	CircularList* next;
	int next_index;

public:
	CircularList();
	CircularList(int coe, int ind, CircularList* nex, int n_in);
	~CircularList();

	void add_node(int coe, int ind);
	int get_next_index();
	int get_coeff();
	void shift(int arg);
	void multi(int arg);
	CircularList* copy();
	CircularList* derivative();
	void ls();
	void dump(vector<int>&, vector<int>&);
	CircularList* go_next();
	int get_index();

	int is_zero();

	friend ostream& operator<<(ostream& ost,const CircularList& cl);
	//friend istream& operator>>(istream& ist, CircularList& cl);
	friend CircularList operator+(int i, CircularList& cl);
	friend CircularList operator-(int i, CircularList& cl);
	friend CircularList operator*(int i, CircularList& cl);
};

#endif
