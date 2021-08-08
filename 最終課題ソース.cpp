#include<iostream>
#include<random>
#include<regex>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
using namespace std;

class Enemy {
	string name; //モンスターの名前//
	string ATK; //入力された攻撃力//
	int hp_pre; //モンスターの最初の攻撃力//
	int hp; //攻撃を受けた後のHP//
	int def; //モンスターの防御力//
	int dama; //ダメージ量//
	int atk; //攻撃力//
public:
	Enemy(string n, int h, int d) {
		name = n;
		hp_pre = h;
		def = d;
	}

	void Atack() {					//攻撃力を入力する関数//
		cout << name <<"への攻撃力を入力してください:" << endl;
		cin >> ATK;
		cout << "あなたの攻撃力は:" << ATK << endl << endl;
		atk = stoi(ATK);
	}

	void Damage1() {				//乱数を加味する場合のダメージ量//
		srand(time(NULL));
		int r = rand() % 4;
		dama = (atk - def)*r;

		cout <<  r<<"倍" << endl;
		if (r == 0) {
			cout << "モンスターAへの攻撃は失敗した!"<< endl;
		}
	}

	void Damage2() {				//乱数を加味しない場合のダメージ量//
		dama = (atk - def);
	}

	int HP(void) {					//モンスターの残りのHP//
		 hp = hp_pre - (dama);
		 return(hp);
	}

	void PutSpec() {				//モンスターのHP,防御力の表示//
		cout << name << "　HP:" << hp_pre << "　防御力:" << def << endl;
	}
};

int main() {
	cout << "(ダメージ量)=(自分の攻撃力)-(相手の防御力)" <<endl<<endl;

	Enemy m1("モンスターA", 200, 20);
	Enemy m2("モンスターB", 200, 20);

	string str = "乱数は0,1,2,3がある";
	regex rx(R"(\d+)");
	sregex_iterator it(str.begin(), str.end(), rx);
	sregex_iterator end;
	while (it != end) {
		cout << "ダメージ量は"<< it++->str()<<"倍" << endl;
	}

	cout << "のどれかになる" << endl<<endl;
	cout << "モンスターA,Bに与える20以上の攻撃力入力"<<endl<<endl;
	
	m1.Atack();
	m2.Atack();
	
	m1.Damage1();
	m2.Damage2();
	
	m1.PutSpec();
	cout << "　　　  残りHP：" << m1.HP() << endl << endl;

	m2.PutSpec();
	cout << "　　　  残りHP：" << m2.HP() << endl;
}