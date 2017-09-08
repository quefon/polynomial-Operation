#include "CircularList.h"

CircularList::CircularList(){
	coeff = 0;
	index = -1;

	next = this;
	next_index = -1;

}

CircularList::CircularList(int coe, int ind, CircularList* nex, int n_in){
	coeff = coe;
	index = ind;

	next = nex;
	next_index = n_in;

}

CircularList::~CircularList(){
	if(next_index!=-1){
		delete next;
	}
}

void CircularList::add_node(int coe, int ind){
	if(index == ind){
		coeff += coe;
		return;
	}else if(ind > next_index){
		next = new CircularList(coe, ind, next, next_index);

		next_index = ind;
	}else{
		next->add_node(coe, ind);
	}
}

void CircularList::ls(){
	cout<<this;
}

int CircularList::get_index(){
	return index;
}

int CircularList::get_next_index(){
	return next_index;
}

int CircularList::get_coeff(){
	return coeff;
}

void CircularList::shift(int arg){
	CircularList* ptr = next;
	while(ptr->index!=-1){
		ptr->index+=arg;
		ptr = ptr -> next;
	}
}

void CircularList::multi(int arg){
	CircularList* ptr = next;
	while(ptr->index!=-1){
		ptr->coeff*=arg;
		ptr = ptr -> next;
	}
}

CircularList* CircularList::copy(){
	CircularList* tmp = new CircularList;
	CircularList* ptr = next;
	while(ptr->index!=-1){
		tmp->add_node(ptr->coeff, ptr->index);
		ptr = ptr -> next;
	}
	return tmp;
}


CircularList* CircularList::derivative(){
	CircularList* tmp = new CircularList;
	CircularList* ptr = next;
	while(ptr->index!=-1 && ptr->index!=0){
		if(ptr->coeff!=0){
			tmp->add_node(ptr->coeff * ptr->index, ptr->index-1);
		}
		ptr = ptr -> next;
	}
	return tmp;
}







CircularList operator+(int i, CircularList& cl){
	CircularList tmp = *cl.copy();
	tmp.add_node(i, 0);
	return tmp;
	
}

CircularList operator-(int i, CircularList& cl){
	CircularList tmp = *cl.copy();
	tmp.add_node(-1*i, 0);
	return tmp;
}

CircularList operator*(int i, CircularList& cl){
	CircularList tmp = *cl.copy();
	tmp.multi(i);
	return tmp;
}

ostream& operator<<(ostream& ost,const CircularList& cl){
	int flag = 0;
	CircularList* ptr = cl.next;
	while(ptr->index!=-1){
		if(ptr->coeff!=0){

			if(ptr->coeff!=1 || ptr->index==0){
				ost<< ptr->coeff;
				flag = 1;
			}
			if(ptr->index!=0){
				ost<<"x";
				flag = 1;
				if(ptr->index!=1)
					ost<<"^"<<ptr->index<<" ";
			}
			if(ptr->next->index!=-1){
				ost<<" + ";
			}
		}
		ptr = ptr -> next;
		
	}
	if(!flag){
		cout<<0;
	}


	return ost;
}

void CircularList::dump(vector<int>& vcoe, vector<int>& vind){

	if(next->coeff!=0 || next->index!=-1){
		vcoe.push_back(next->coeff);
		vind.push_back(next->index);
		next->dump(vcoe, vind);
	}
	return;
}

CircularList* CircularList::go_next(){
	return next;
}

int CircularList::is_zero(){
	CircularList* ptr = next;
	while(ptr->index!=-1){

		if(ptr->coeff!=0){
			return 0;
		}
		ptr = ptr->next;
	}
	return 1;
}



