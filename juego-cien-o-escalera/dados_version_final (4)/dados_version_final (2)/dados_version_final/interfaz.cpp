#include <iostream>
#include "interfaz.h"

using namespace std;

std::string obtenerNombre(){

    system("cls");
    std::string nombre;
    cout<<"Ingrese su nombre: "; cin>>nombre;
    system("cls");
    return nombre;

}

void mostrarPuntuacionMaxima(std::string nombre, int infoMejorJugada[]){

    int posRondas = 0, posPuntos = 1, ESCALERA = -1;

    if(infoMejorJugada[posPuntos] == ESCALERA){

        cout<<endl;
        cout<<"EL JUGADOR "<<nombre<<" GANO CON ESCALERA EN LA RONDA "<<infoMejorJugada[posRondas]<<" ALTA SUERTE TIENE EL LOCO"<<endl;

    } else if(nombre == "Sin ganador"){

        cout<<endl;
        cout<<"Aun no se han registrado victorias."<<endl;

    } else{

        cout<<endl;
        cout<<"El mejor jugador fue: "<<nombre<<endl;
        cout<<"Obtuvo un puntaje de "<<infoMejorJugada[posPuntos]<<" en "<<infoMejorJugada[posRondas]<<" rondas!"<<endl<<endl;

    }

}

void mostrarGanadorPorLanzamientos(std::string nombre){

    cout<<"El ganador por lanzamientos efectivos es: "<<nombre<<" felicidades!";

}

bool establecerRondas(){

    char respuesta;
    cout<<"Quiere establecer un numero maximo de rondas? s/n "<<endl; cin>>respuesta;

    while(respuesta != 's' && respuesta != 'n'){
        system("cls");
        cout<<"Responda con 's' para SI o 'n' para NO: "; cin>>respuesta;
    }

    system("cls");

    if(respuesta == 's'){
        return true;
    } else {
        return false;
    }

}

int obtenerCantidadRondas(){

    int rondas;
    cout<<"Ingrese numero maximo de rondas: "; cin>>rondas;

    while(rondas <= 0){
        system("cls");
        cout<<"Ingrese un numero mayor que 0"; cin>>rondas;
    }

    system("cls");
    return rondas;

}

void mostrarDados(int dados[], int cantidadDados){

    for(int i = 0; i<cantidadDados; i++){
        cout<<dados[i]<<"   ";
    }

}

void mostrarRondaActual(std::string nombre, int ronda, int puntaje){

    cout<<"Jugador: "<<nombre<<" | Ronda N°"<<ronda<<" | Puntaje: "<<puntaje<<endl;

}

void mostrarPuntajeDeRonda(int numRonda, int puntajeDeRonda){

    cout<<endl;
    cout<<"Tu puntaje de la ronda "<<numRonda<<" fue de: "<<puntajeDeRonda;
    cout<<endl;

    system("pause");
    system("cls");

}

void mostrarNumeroLanzamiento(int numLanzamiento){

    cout<<"-------"<<"Lanzamiento N°"<<numLanzamiento<<"-------"<<endl;

}

void mostrarPuntajeTirada(int puntajeTirada){

    cout<<"Puntaje de la tirada: "<<puntajeTirada;

    cout<<endl;
    system("pause");
    cout<<endl;

}

void mostrarCombinacion(int combinacion, int valorDado){

    const int ESCALERA = -1;
    const int RESETEAR = -2;
    const int SUMA = 1;
    const int MULTIPLICAR = 2;

    switch(combinacion){
        case ESCALERA:      cout<<"COMBINACION: Escalera"<<endl;                break;
        case SUMA:          cout<<"COMBINACION: Suma de dados"<<endl;           break;
        case RESETEAR:      cout<<"COMBINACION: Sexteto de 6"<<endl;            break;
        case MULTIPLICAR:   cout<<"COMBINACION: Sexteto de "<<valorDado<<endl;  break;
    }

}

void mostrarGanador(std::string nombre, int puntaje, int rondas){

    const int ESCALERA = -1;

    if(puntaje == ESCALERA){

        cout<<"FELICIDADES "<<nombre<<" GANASTE POR ESCALERA TENES UNA SUERTE INCREIBLE JUGALE AL KINI METE TODO AL ROJO ANDA AL BINGO NOSE HACE ALGO"<<endl<<endl;

    } else{

        cout<<"Felicidades "<<nombre<<"! Ganaste en "<<rondas<<" rondas con un puntaje de "<<puntaje<<endl<<endl;

    }

}
void mostrarJugadorPierde(std::string nombre, int puntaje){

    cout<<"Se terminaron las rondas y no alcanzaste el objetivo :c. Tu puntaje: "<<puntaje<<endl<<endl;

}

void mostrarSeReseteanPuntos(){

    cout<<"Uhh tuviste mala suerte, se te van a resetear los puntos a 0 :c"<<endl<<endl;
    system("pause");
    system("cls");

}

void mostrarPuntajeParcial(std::string nombre1, int puntaje1, std::string nombre2, int puntaje2) {

    std::cout << "Puntaje de " << nombre1 << ": " << puntaje1 << std::endl;
    std::cout << "Puntaje de " << nombre2 << ": " << puntaje2 << std::endl;
    system("pause");
    system("cls");


}

int pedirValorDado(int numDado){

    int valorDado;

    cout<<"Ingrese valor del dado #"<<numDado<<": "; cin>>valorDado;

    while(valorDado < 1 || valorDado > 6){
        cout<<"Ingrese un valor entre 1 y 6 por favor. Valor del dado #"<<numDado<<": "; cin>>valorDado;
    }

    return valorDado;

}

void mostrarEmpate(int puntaje) {
    cout << "-----------------------------------------" << endl;
    cout << "EMPATE: ambos jugadores terminaron con " << puntaje << " puntos." << endl;
    cout << "No hay un ganador. ¡Que partida pareja loco!" << endl;
    cout << "-----------------------------------------" << endl;
}

