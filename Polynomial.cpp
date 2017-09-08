#include "Polynomial.h"

Polynomial::Polynomial(){
	List = new CircularList;
}


Polynomial::Polynomial(Polynomial &l){
	List = l.List->copy();

}

Polynomial::~Polynomial(){

}


void Polynomial::set(int arr[], int num){
	int coef = arr[0], inde = arr[1];
	num=0;
	while(coef!=0 && inde!=-1){
		List->add_node(coef, inde);
		num+=2;
		coef = arr[num];
		inde = arr[num+1];
	}
	return;
}

void Polynomial::ls(){
	List->ls();
	return;
}

void Polynomial::get(int arr[], int num){
	//static int* ptr = NULL;
	vector<int> vcoe;
	vector<int> vind;
	int ptr = 0, i = 0;
	List->dump(vcoe, vind);
	for (i = 0; i < num/2&& ptr <vcoe.size(); ++i)
	{
		while(vcoe[ptr]==0 && vind[ptr]!=-1){
			//cout<<ptr<<" "<<vcoe[ptr]<<" "<<vind[ptr]<<endl;
			++ptr;
		}
		if(vcoe[ptr]==0&&vind[ptr]==-1){
			break;
		}
		arr[i*2] = vcoe[ptr];
		arr[i*2+1] = vind[ptr];
		++ptr;
	}
	if(i>num/2){
		i=(num/2)-1;
	}
	arr[i*2] = 0;
	arr[i*2+1] = -1;



	return ;
}

Polynomial& Polynomial::derivative(){
	Polynomial* res = new Polynomial(*this);
	Polynomial&q = *res;
	res->List = res->List->derivative();
	return q;
}


ostream& operator<<(ostream& ost, const Polynomial& pol){
	ost<<*(pol.List);
	return ost;
}

istream& operator>>(istream& ist, const Polynomial& pol){
	int co, in;
	while(1){
		ist>> co >> in;
		if(co==0 && in ==-1){
			break;
		}
		pol.List->add_node(co,in);
	}

}


Polynomial& operator+(const int i, Polynomial& pol){
	Polynomial res(pol);
	Polynomial& q = res;
	res.List->add_node(i, 0);
	return q;
}
Polynomial& operator-(const int i, Polynomial& pol){
	Polynomial res(pol);
	Polynomial& q = res;
	res.List->add_node(-1*i,0);
	return q;
}
Polynomial& operator*(const int i, Polynomial& pol){
	Polynomial res(pol);
	Polynomial& q = res;
	res.List->multi(i);
	return q;
}

Polynomial& operator+(Polynomial& pol, const int i){
	Polynomial res(pol);
	Polynomial& q = res;
	res.List->add_node(i, 0);
	return q;
}
Polynomial& operator-(Polynomial& pol, const int i){
	Polynomial res(pol);
	Polynomial& q = res;
	res.List->add_node(-1*i,0);
	return q;
}
Polynomial& operator*(Polynomial& pol, const int i){
	Polynomial res(pol);
	Polynomial& q = res;
	res.List->multi(i);
	return q;
}

Polynomial& Polynomial::operator+(Polynomial& right){
	Polynomial res(*this);
	Polynomial& q = res;
	CircularList* tmp = right.List->copy();

	CircularList* ptr = tmp;
	ptr = ptr->go_next();

	while(ptr->get_index()!=-1){
		res.List->add_node(ptr->get_coeff(), ptr->get_index());
		ptr = ptr -> go_next();
	}

	return q;
}

Polynomial& Polynomial::operator-(Polynomial& right){
	Polynomial res(*this);
	Polynomial& q = res;
	CircularList* tmp = right.List->copy();

	CircularList* ptr = tmp;
	ptr = ptr->go_next();

	while(ptr->get_index()!=-1){
		res.List->add_node(-1*ptr->get_coeff(), ptr->get_index());
		ptr = ptr -> go_next();
	}

	return q;
}

Polynomial& Polynomial::operator*(Polynomial& right){
	Polynomial res;
	Polynomial& q = res;
	CircularList* tmp = right.List->copy();

	CircularList* ptr = tmp;
	ptr = ptr->go_next();

	while(ptr->get_index()!=-1){

		CircularList* ptr1 = List;
		ptr1 = ptr1->go_next();

		while(ptr1->get_index()!=-1){
			//cout<<"ADD "<<ptr->get_coeff()* ptr1->get_coeff()<<","<<ptr->get_index()+ ptr1->get_index()<<endl;
			res.List->add_node(ptr->get_coeff()* ptr1->get_coeff(), ptr->get_index()+ ptr1->get_index());
			ptr1 = ptr1->go_next();
		}
		ptr = ptr->go_next();
	}

	return q;
}







Polynomial& Polynomial::operator+=(Polynomial& right){

	Polynomial& q = *this;
	CircularList* tmp = right.List->copy();

	CircularList* ptr = tmp;
	ptr = ptr->go_next();

	while(ptr->get_index()!=-1){
		this->List->add_node(ptr->get_coeff(), ptr->get_index());
		ptr = ptr -> go_next();
	}

	return q;
}

Polynomial& Polynomial::operator-=(Polynomial& right){

	Polynomial& q = *this;
	CircularList* tmp = right.List->copy();

	CircularList* ptr = tmp;
	ptr = ptr->go_next();

	while(ptr->get_index()!=-1){
		this->List->add_node(-1*ptr->get_coeff(), ptr->get_index());
		ptr = ptr -> go_next();
	}

	return q;
}

Polynomial& Polynomial::operator*=(Polynomial& right){
	Polynomial& q = *this;
	CircularList* tmp = right.List->copy();
	CircularList* tmp2 = this->List->copy();
	CircularList blank;
	this->List = blank.copy();

	CircularList* ptr = tmp;
	ptr = ptr->go_next();

	while(ptr->get_index()!=-1){

		CircularList* ptr1 = tmp2;
		ptr1 = ptr1->go_next();

		while(ptr1->get_index()!=-1){

			this->List->add_node(ptr->get_coeff()* ptr1->get_coeff(), ptr->get_index()+ ptr1->get_index());
			ptr1 = ptr1->go_next();
		}
		ptr = ptr->go_next();
	}

	return q;
}

int Polynomial::is_zero(){
	return List->is_zero();
}

bool Polynomial::operator==(Polynomial& right){
	return ((*this)-right).is_zero();
}

bool Polynomial::operator!=(Polynomial& right){
	return !( ((*this)-right).is_zero());
}

int Polynomial::operator()(int value){
	int total = 0;

	CircularList* ptr = this->List;
	ptr = ptr->go_next();

	while(ptr->get_index()!=-1){
		total += ptr->get_coeff() * pow(value, ptr->get_index());
		ptr = ptr -> go_next();
	}
	return total;

}


Polynomial& operator+=(Polynomial& cl, const int i){
	cl.List->add_node(i, 0);
	return cl;
}

Polynomial& operator-=(Polynomial& cl, const int i){
	cl.List->add_node(-1*i, 0);
	return cl;
}

Polynomial& operator*=(Polynomial& cl, const int i){
	cl.List->multi(i);
	return cl;
}
