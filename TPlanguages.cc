#include <iostream>
#include <cstdlib>

using namespace std;

struct Automate
{
	string intitule;
	int nbEtats, etatPuit, etatTerm[100], nbEtatsTerm, nbTrans;
	int matrice[][4];
};

int conversionVersInt(char a)
{
	switch(a)
	{
		case 'a':
			return 0;
		case 'b':
			return 1;
		case 'c':
			return 2;
		case 'd':
			return 3;
	}
	return 0;
}
char conversionVersChar(int a)
{
	switch(a)
	{
		case 0 :
			return 'a';
		case 1 :
			return 'b';
		case 2 :
			return 'c';
		case 3 :
			return 'd';
	}
	return 0;
}

void initAutomate(Automate &a)
{
	cout << "Intitulé : " << endl;
	cin >> a.intitule;
	cout << "Nombre d'états : " << endl;
	cin >> a.nbEtats;
	cout << "Nombre de transitions : " << endl;
	cin >> a.nbTrans;
	cout << "Liste des transitions : " << endl;
	int etat1, etat2;
	char carac;
	for (int i=0 ; i<a.nbEtats ; i++)
	{
		for (int j=0 ; j<4 ; j++)
			a.matrice[i][j] = -1;
	}
	for (int i=0 ; i<a.nbTrans ; i++)
	{
		cout << "Transition " << i+1 << endl;
		cout << "Etat source | Caractère | Etat cible" << endl;
		cin >> etat1;
		cin >> carac;
		cin >> etat2;
        
		a.matrice[etat1][conversionVersInt(carac)] = etat2;
	}
	cout << "Nombre d'états terminaux : " << endl;
	cin >> a.nbEtatsTerm;
	cout << "Etats terminaux : " << endl;
	for (int i=0 ; i<a.nbEtatsTerm ; i++)
	{
		cout << "Etat terminal " << i+1 << " : " << endl;
		cin >> a.etatTerm[i];
	}
}

void afficheAutomate(Automate &a)
{
	cout << "Intitulé : " << a.intitule << endl;
	cout << "Nombre d'états : " << a.nbEtats << endl;
	cout << "Nombre de transitions : " << a.nbTrans << endl;
	cout << "Liste des transitions : " << endl;
    
	for (int i=0 ; i<a.nbEtats ; i++)
	{
		for (int j=0 ; j<4 ; j++)
		{
			if(a.matrice[i][j] != -1)
				cout << i << " " << conversionVersChar(j) << " " << a.matrice[i][j] << endl;
		}
	}
	cout << "Nombre d'états terminaux : " << a.nbEtatsTerm << endl;
	for (int i=0 ; i<a.nbEtatsTerm ; i++)
	{
		cout << "Etat terminal " << i+1 << " : " << a.etatTerm[i] << endl;
	}
}

int main()
{
	Automate automate;
	initAutomate(automate);
	afficheAutomate(automate);
	return 0;
}



