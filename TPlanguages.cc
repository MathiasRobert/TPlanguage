#include <iostream>
#include <cstdlib>

using namespace std;

enum alphabet{A,B,C,D}



class Automate
{
	private:
		string _intitule;
		int _nbEtats, _etatPuit, _etatTerm[], _nbEtatsTerm;
		enum _matrice[][];
		
	public:
		void setItitule(string s): _intitule(s); {}
		void setEtats(int nbEtats): _nbEtats(nbEtats); {}
		void setNbEtatsTerm(int nbEtatsTerm): _nbEtatsTerm(nbEtatsTerm); {}
		void setEtatsTerm(int tmp, int i): _etatTerm[i](tmp) {}
		void setMatrice(int etat1, int etat2, char carac)
		{
			enum _carac;
			switch(carac)
			{
				case 'a':
					_carac = A;
					break;
				case 'b':
					_carac = B;
					break;
				case 'c':
					_carac = C;
					break;
				case 'd':
					_carac = D;
					break;
			}
			_matrice[etat1][etat2] = _carac
		}
};

void afficher()
{
	string s;
	int nbEtats, nbEtatsTerm, nbTrans;
	cout << "Ititulé : " << endl;
	cin >> s;
	automate->setIntitule(s);
	cout << "Nombre d'états : " << endl;
	cin >> nbEtats;
	automate->setEtats(nbEtats);
	cout << "Nombre de transitions : " << endl;
	cin >> nbTrans;
	cout << "Liste des trasitions : " << endl;
	int etat1, etat2;
	char carac;
	for (int i=0 ; i<nbTrans ; i++)
	{
		cout << "Transition " << i << endl;
		cout << "Etat source : " << endl;
		cin >> etat1;
		cout << "Caractère : " << endl;
		cin >> carac;
		cout << "Etat cible : " << endl;
		cin >> etat2;
		atomate->setMatrice(etat1,etat2,carac);
	}
	cout << "Nombre d'états terminaux : " << endl;
	cin >> nbEtatsTerm;
	automate->setNbEtatsTerm(nbEtatsTerm);
	cout << "Etats terminaux : " << endl;
	for (int i=0 ; i<nbEtatsTerm ; i++)
	{
		int tmp;
		cout << "Etat terminal " << i << " : " << endl;
		cin >> tmp;
		automate->setEtatsTerm(tmp, i);
	}
}

int main()
{
	Automate *automate;
	afficher();
	return 0;
}


