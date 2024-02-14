#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Totes les variables i punters.
    int* pDiners;
    int Opcio = 0;//Opcio de jugar o no jugar.
    int Diners = 100;//Diners actuals del jugador.
    int* pAposta;
    int apostaDiners;//Diners apostats per el jugador.
    int* pDau1;
    int Tirada1;//Primera tirada.
    int* pDau2;
    int Tirada2;//Segona tirada.
    int* pApostanum;
    int Numero;//Numero seleccionat per apostar del jugador.
    int Resultat = 0;//Resultat de les tirades.
    srand(NULL);
    void* prt;
    prt = new int;
    pDiners = &Diners;
    pAposta = &apostaDiners;
    pDau1 = &Tirada1;
    pDau2 = &Tirada2;
    pApostanum = &Numero;

    //Benvinguda al jugador
    cout << "##### Benvingut a la casa d'apostes virtuals #####" << endl;
    cout << "##### Disposes de " << Diners << " Monedes #####" << endl;
    cout << "##### Que t'agradaria fer? 1. Jugar 2. Sortir #####" << endl;
    cin >> Opcio;

    do
    {
        if (Diners <= 0) {//Comprovem que el jugador disposi de diners suficients.

            cout << "##### T'has quedat sense diners! #####" << endl;
            break;
        }
        
        cout << "##### Quina cuantitat apostaras? #####" << endl;//Deamanem al jugador la quantitat a 
        cin >> apostaDiners;
        Diners = Diners - apostaDiners;
        cout << "##### Disposes de " << Diners << " Monedes #####" << " ##### Has apostat " << apostaDiners << " #####" << endl;

        cout << "##### Quin numero vols apostar? Min. 2 Max. 12 #####" << endl;//Aqui guardem el numero que el jugador vol apostar.
        cin >> Numero;

        Tirada1 = rand() % 6 + 1;//Calculem la primera tirada.

        cout << "##### Primera tirada, es un " << Tirada1 << " #####" << endl;

        Tirada2 = rand() % 6 + 1;//Calculem la segona tirada.

        cout << "##### Segona tirada, es un " << Tirada2 << " #####" << endl;

        Resultat = Tirada1 + Tirada2;//Calculem el numero final.

        cout << "##### El numero final es " << Resultat << " #####" << endl;

        if (Resultat == Numero) {//Si el resultat es exacte a la aposta multipliquem els diners apostats per 10.
            
            cout << "##### Bravo has encertat #####" << endl;

            Diners = Diners + apostaDiners * 10;//Aqui fem el calcul necessari.

            cout << "##### Vols tornar a jugar? #####" << endl;

            cin >> Opcio;

            continue;
        }

        //Aqui es gestionen els resultats del jugador
        if (Resultat == Numero +1) {//Per si ens passem per un punt amunt.

            cout << "##### Casi! T'has passat per poc #####" << endl;

            Diners = Diners + apostaDiners * 2;

            cout << "##### Vols tornar a jugar? 1. Si 2. No #####" << endl;

            cin >> Opcio;

            continue;
        }
        if (Resultat == Numero - 1) {//Per si ens passem per un punt avall.

            cout << "##### Casi! T'has passat per poc #####" << endl;

            Diners = Diners + apostaDiners * 2;

            cout << "##### Vols tornar a jugar? 1. Si 2. No #####" << endl;

            cin >> Opcio;

            continue;
        }
        if (Resultat == Numero + 2) {//Per si ens passem per dos punts amunt.

            cout << "##### Casi! T'has passat per dos numeors #####" << endl;

            Diners = Diners + apostaDiners * 1;

            cout << "##### Vols tornar a jugar? 1. Si 2. No #####" << endl;

            cin >> Opcio;

            continue;
        }
        if (Resultat == Numero - 2) {//Per si ens passem per dos punts avall.

            cout << "##### Casi! T'has passat per dos numeors #####" << endl;

            Diners = Diners + apostaDiners * 1;

            cout << "##### Vols tornar a jugar? 1. Si 2. No #####" << endl;

            cin >> Opcio;

            continue;
        }


        if (Resultat != Numero) {//Per si ens passem per mes de dos punts amunt o avall.

            cout << "##### Mala Sort #####" << endl;

            cout << "##### Vols tornar a jugar? 1. Si 2. No #####" << endl;

            cin >> Opcio;

            continue;
        }


    } while (Diners > 0 && Opcio == 1);// El bucle s'acaba si el jugador vol deixar de jugar o si se li acaben els diners.

    cout << "##### Espero que haguis aconseguit una gran fortuna #####" << endl;//finalment em despedeixo del jugador.


}



