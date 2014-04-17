#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Automate
{
	string intitule;
	int nbEtats, etatPuit, nbEtatsTerm, nbTrans;
	int etatTerm[100];
	int matrice[100][4];
};

int conversionVersInt(char a);
char conversionVersChar(int a);
bool menu(Automate &au);
void saveAutomate(Automate &au);
void loadAutomate(Automate &a);
void initAutomate(Automate &a);
void afficheAutomate(Automate &a);
void simulation(Automate &a);
void resetAutomate(Automate &a);

void resetAutomate(Automate &a)
{
	a.intitule = ' ';
	a.nbEtats = 0;
	a.etatPuit = 0;
	a.nbEtatsTerm = 0;
	a.nbTrans = 0;
}

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

bool menu(Automate &au)
{
	bool fini = false;
	int a;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|                 BIENVENUE SUR L'AUTOMATOR                      |" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "AUTOMATE ACTUEL : " << au.intitule << endl;
	cout << "Que souhaitez vous faire ?" << endl;
	cout << "1. Créer un automate" << endl;
	cout << "2. Voir l'automate" << endl;
	cout << "3. Sauvegarder l'automate" << endl;
	cout << "4. Charger un automate" << endl;
	cout << "5. Utiliser l'automate actuel" << endl;
	cout << "6. Quitter" << endl;
	do{
		cin >> a;
	}while(a < 1 || a > 6);

	switch(a)
	{
		case 1:
		initAutomate(au);
			break;
		case 2:
		afficheAutomate(au);
			break;
		case 3:
		saveAutomate(au);
			break;
		case 4:
		loadAutomate(au);
			break;
		case 5:
		simulation(au);
			break;
		case 6:
			fini = true;
			break;
	};
	return fini;
}

void saveAutomate(Automate &au)
{
    fstream myfile;
    myfile.open("test.txt", ios::out|ios::app);
    if( myfile.fail() )
    {
        cerr << "ouverture en lecture impossible" << endl;
    }
    myfile << au.intitule << " ";
    myfile << au.nbEtats << " ";
        myfile << au.nbTrans << " ";

        for (int i=0 ; i<au.nbEtats ; i++)
        {
            for (int j=0 ; j<4 ; j++)
            {
                if(au.matrice[i][j] != -1)
                {
                    myfile << i << " ";
                    myfile << j << " ";
                    myfile << au.matrice[i][j] << " ";
                }
            }
        }
        myfile << au.nbEtatsTerm << " ";
        for (int i=0 ; i<au.nbEtatsTerm ; i++)
        {
            myfile << au.etatTerm[i] << " ";
        }
        myfile.close();
}

void loadAutomate(Automate &a)
{
	int num;
	int tmp = 0;
	string intitules[100];
    fstream myfile;
    myfile.open("test.txt", ios::in);
    if( myfile.fail() )
    {
        cerr << "ouverture en lecture impossible" << endl;
    }
    while(!myfile.eof())
    {
		myfile >> a.intitule;
		myfile >> a.nbEtats;
		myfile >> a.nbTrans;
		for (int i=0 ; i<a.nbEtats ; i++)
		{
			for (int j=0 ; j<4 ; j++)
				a.matrice[i][j] = -1;
		}
		for (int i=0 ; i<a.nbTrans ; i++)
		{
			int k,b,c = 0;
			myfile >> k;
			myfile >> b;
			myfile >> c;
			a.matrice[k][b] = c;
		}
		myfile >> a.nbEtatsTerm;
		for (int i=0 ; i<a.nbEtatsTerm ; i++)
		{
			myfile >> a.etatTerm[i];
		}
		intitules[tmp] = a.intitule;
		tmp++;
	}
	myfile.close();
	
	cout << "Liste des automates disponibles : " << endl;
	for(int z=0 ; z<tmp-1 ; z++)
    {
		cout << z+1 << ". " << intitules[z] << endl;
	}
	cout << "Quel automate voulez vous ? (le numero)" << endl;
	cin >> num;
	
	myfile.open("test.txt", ios::in);
	if( myfile.fail() )
    {
        cerr << "ouverture en lecture impossible" << endl;
    }
    for(int z=0 ; z<num ; z++)
    {
		myfile >> a.intitule;
		myfile >> a.nbEtats;
		myfile >> a.nbTrans;
		for (int i=0 ; i<a.nbEtats ; i++)
		{
			for (int j=0 ; j<4 ; j++)
				a.matrice[i][j] = -1;
		}
		for (int i=0 ; i<a.nbTrans ; i++)
		{
			int k,b,c = 0;
			myfile >> k;
			myfile >> b;
			myfile >> c;
			a.matrice[k][b] = c;
		}
		myfile >> a.nbEtatsTerm;
		for (int i=0 ; i<a.nbEtatsTerm ; i++)
		{
			myfile >> a.etatTerm[i];
		}
	}
    myfile.close();
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
void simulation(Automate &a)
{
	cout << "Entrez votre chaine de caractère : ";
    string chaine;
    cin >> chaine;
    int etat=0;
    bool res = false;
    for (unsigned int i=0;i<chaine.size();i++)
    {
        etat=a.matrice[etat][conversionVersInt(chaine[i])];
    }
    for (int i=0;i<a.nbEtatsTerm ;i++ )
    {
    	if(etat==a.etatTerm[i])
    	res = true;
    }
    cout << "Résultat : ";
    if(res)
		cout << "OUI" << endl;
	else
		cout << "NON" << endl;
}

int main()
{
	Automate automate;
	resetAutomate(automate);

    bool fini = false;
	while(!fini)
        fini = menu(automate);

	return 0;
}
