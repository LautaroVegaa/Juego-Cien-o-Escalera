#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include "operaciones.h"
#include<time.h>

using namespace std;

// Ranking global con los 4 mejores jugadores inicializado con valores altos
RankingEntry ranking[4] = {
    {"Sin jugador", 1000, 0 }, // El 0 para los puntos
    {"Sin jugador", 1000, 0 },
    {"Sin jugador", 1000, 0 },
    {"Sin jugador", 1000, 0 }
};


int main()
{
    // Cargar ranking desde archivo al iniciar el programa
    cargarRanking(ranking, "ranking.txt");

    srand(time(NULL));
    int seleccion, datos = 2;
    int infoMejorPartida[datos] = {1000,1000};
    bool simularPartida = true;

    std::string nombreMejorJugador = "Sin ganador";

    while(seleccion != 7){

        std::string nombreJugador = "Sin ganador";
        int infoPartida[datos];

        cout<<"-----MENU-----"<<endl;
        cout<<"Seleccione una opcion"<<endl;
        cout<<"1. Un jugador"<<endl;
        cout<<"2. Dos jugadores"<<endl;
        cout<<"3. Maxima puntuacion"<<endl;
        cout << "4. Modo simulado (1 jugador)" << endl;
        cout << "5. Modo simulado (2 jugadores)" << endl;
        cout<< "6. Mostrar Ranking de los 4 mejores" <<endl;
        cout<<"7. Salir"<<endl;
        cin>>seleccion;

        switch(seleccion){

            case 1: nombreJugador = modoUnJugador(infoPartida, !simularPartida);    system("pause"); break;
            case 2: nombreJugador = modoDosJugadores(infoPartida, !simularPartida); system("pause"); break;
            case 3: mostrarPuntuacionMaxima(nombreMejorJugador, infoMejorPartida);  system("pause"); break;
            case 4: modoUnJugador(infoPartida, simularPartida);                     system("pause"); break;
            case 5: modoDosJugadores(infoPartida, simularPartida);                  system("pause"); break;
            case 6: mostrarRanking(ranking);                                        system("pause"); break;
            }



        if(nombreJugador != "Sin ganador")nombreMejorJugador = analizarInfoPartida(nombreMejorJugador, nombreJugador, infoPartida, infoMejorPartida);
        if(nombreJugador != "Sin ganador")actualizarRanking(ranking, nombreJugador, infoPartida[0], infoPartida[1]); // infoPartida[0] = cantidad de rondas, //infoPartida[1] = Puntos



        system("cls");

    }

    cout<<"Gracias por jugar!"<<endl;

     // Guardar el ranking actualizado antes de salir del juego
    guardarRanking(ranking, "ranking.txt");

    return 0;
}
