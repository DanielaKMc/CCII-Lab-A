#include<iostream>
#include<list>
#include<cmath>
using namespace std;

class pila{
private:
	int n;
	pila* next;
public:
	pila* create(int n_){
		pila* L = new(class pila);
		L->n=n_;
		L->next=NULL;
		return L;
	}
	void isrt(pila*& L, int n_){
		if(L==NULL){
			L=create(n_);
		}
		else{
			isrt(L->next,n_);
		}
	}
	void show(pila* L){
		if(L!=NULL){
			if(L->next==NULL){
				cout<<L->n<<endl;
			}
			else{
				cout<<L->n<<" -> ";
				show(L->next);
			}
		}
	}
	void dest(pila* &L){
		delete L;
	}
};

int main(){
	pila* tow=NULL;
	int op;
	cout<<"Indique la cantidad de discos: ";
	cin>>op;
	for(int i=op; i>0; i--){
		if(i==op){
			tow=tow->create(i);
		}
		else{
			tow->isrt(tow,i);
		}
	}
	cout<<"Lista: "<<endl;
	tow->show(tow);
	cout<<"Se eliminaron los elementos."<<endl;
	tow->dest(tow);
	
	return 0;
}
