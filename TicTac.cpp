#include <iostream>
#include <vector>
using namespace std;

class Subject {
	vector < class Observer * > views;
	int value;
public:
	void attach(Observer *obs) {
		views.push_back(obs);
	}
	void setVal(int val) {
		value = val;
		notify();
	}
	int getVal() {
		return value;
	}
	void notify();
};

class Observer {
	Subject *model;
	int posX;
	int posY;
public:
	Observer(Subject *mod, int x, int y) {
		model = mod;
		posX = x;
		posY = y;
		model->attach(this);
	}
	virtual void update() = 0;
protected:
	Subject * getSubject() {
		return model;
	}
	int getPosX() {
		return posX;
	}
	int getPosY() {
		return posY;
	}
};

void Subject::notify() {
	for (int i = 0; i < views.size(); i++)
		views[i]->update();
}

class Player1 : public Observer {
public:
	Player1(Subject *mod, int x, int y) : Observer(mod, x, y) {}
	void update() {
		int noPlayer = getSubject()->getVal(), X = getPosX(), Y = getPosY();
		cout << "Player: " << "(X)" << "\t" << "memilih posisi (x,y) = " << X << " , " << Y << '\n';
	}
};

class Player2 : public Observer {
public:
	Player2(Subject *mod, int x, int y) : Observer(mod, x, y) {}
	void update() {
		int noPlayer = getSubject()->getVal(), X = getPosX(), Y = getPosY();
		cout << "Player: " << "(O)" << "\t" << "memilih posisi (x,y) = " << X << " , " << Y << '\n';
	}
};

int main() {
	Subject subj;
	int PosisiX, PosisiY;
	int Giliran = 0;
	while (true)
	{
		if (Giliran == 0)
		{
			cout << "Giliran Player X, masukkan koordinat(x,y)(1-3,1-3)" << endl;
			cout << "Masukkan koordinat X: "; cin >> PosisiX;
			cout << "Masukkan koordinat Y: "; cin >> PosisiY;
			Player1 playerObj1(&subj, PosisiX, PosisiY);
			subj.setVal(1);
			Giliran = 1;
			cout << '\n' <<endl;
		}

		else if (Giliran == 1)
		{
			cout << "Giliran Player O, masukkan koordinat(x,y)(1-3,1-3)" << endl;
			cout << "Masukkan koordinat X: "; cin >> PosisiX;
			cout << "Masukkan koordinat Y: "; cin >> PosisiY;
			Player2 playerObj1(&subj, PosisiX, PosisiY);
			subj.setVal(2);
			Giliran = 0;
			cout << '\n' <<endl;
		}
	}

}
