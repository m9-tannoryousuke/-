#include<iostream>
#include<random>
#include<regex>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
using namespace std;

class Enemy {
	string name; //�����X�^�[�̖��O//
	string ATK; //���͂��ꂽ�U����//
	int hp_pre; //�����X�^�[�̍ŏ��̍U����//
	int hp; //�U�����󂯂����HP//
	int def; //�����X�^�[�̖h���//
	int dama; //�_���[�W��//
	int atk; //�U����//
public:
	Enemy(string n, int h, int d) {
		name = n;
		hp_pre = h;
		def = d;
	}

	void Atack() {					//�U���͂���͂���֐�//
		cout << name <<"�ւ̍U���͂���͂��Ă�������:" << endl;
		cin >> ATK;
		cout << "���Ȃ��̍U���͂�:" << ATK << endl << endl;
		atk = stoi(ATK);
	}

	void Damage1() {				//��������������ꍇ�̃_���[�W��//
		srand(time(NULL));
		int r = rand() % 4;
		dama = (atk - def)*r;

		cout <<  r<<"�{" << endl;
		if (r == 0) {
			cout << "�����X�^�[A�ւ̍U���͎��s����!"<< endl;
		}
	}

	void Damage2() {				//�������������Ȃ��ꍇ�̃_���[�W��//
		dama = (atk - def);
	}

	int HP(void) {					//�����X�^�[�̎c���HP//
		 hp = hp_pre - (dama);
		 return(hp);
	}

	void PutSpec() {				//�����X�^�[��HP,�h��͂̕\��//
		cout << name << "�@HP:" << hp_pre << "�@�h���:" << def << endl;
	}
};

int main() {
	cout << "(�_���[�W��)=(�����̍U����)-(����̖h���)" <<endl<<endl;

	Enemy m1("�����X�^�[A", 200, 20);
	Enemy m2("�����X�^�[B", 200, 20);

	string str = "������0,1,2,3������";
	regex rx(R"(\d+)");
	sregex_iterator it(str.begin(), str.end(), rx);
	sregex_iterator end;
	while (it != end) {
		cout << "�_���[�W�ʂ�"<< it++->str()<<"�{" << endl;
	}

	cout << "�̂ǂꂩ�ɂȂ�" << endl<<endl;
	cout << "�����X�^�[A,B�ɗ^����20�ȏ�̍U���͓���"<<endl<<endl;
	
	m1.Atack();
	m2.Atack();
	
	m1.Damage1();
	m2.Damage2();
	
	m1.PutSpec();
	cout << "�@�@�@  �c��HP�F" << m1.HP() << endl << endl;

	m2.PutSpec();
	cout << "�@�@�@  �c��HP�F" << m2.HP() << endl;
}