#include <iostream>
#include "juego.h"
#include "interfaz.h"
#include "operaciones.h"
#include <ctime>
#include <cstdlib>

using namespace std;

std::string modoUnJugador(int infoPartida[], bool partidaSimulada){
    int ESCALERA = -1;
    std::string nombre = obtenerNombre();
    std::string ganador = "Sin ganador";
    int puntaje = 0, ronda = 1, rondasEstablecidas = -1;
    int lanzamientos = 0;

    if(establecerRondas()) rondasEstablecidas = obtenerCantidadRondas();

    while(rondasEstablecidas != 0){
        mostrarRondaActual(nombre, ronda, puntaje);
        puntaje = jugarTurno(puntaje, ronda, partidaSimulada, lanzamientos);

        if(chequearGanador(puntaje)){
            guardarInfoPartida(infoPartida, puntaje, ronda);
            mostrarGanador(nombre, puntaje, ronda);
            ganador = nombre;
            break;
        }

        ronda++;
        rondasEstablecidas--;
    }

    if(puntaje < 100 && puntaje != ESCALERA) mostrarJugadorPierde(nombre, puntaje);

    return ganador;
}

std::string modoDosJugadores(int infoPartida[], bool partidaSimulada){
    int ESCALERA = -1;
    string jugador1 = obtenerNombre();
    string jugador2 = obtenerNombre();
    string ganador = "Sin ganador";

    int puntaje1 = 0, puntaje2 = 0;
    int ronda = 1, rondasEstablecidas = -1;
    int lanzamientos1 = 0, lanzamientos2 = 0;

    if(establecerRondas()) rondasEstablecidas = obtenerCantidadRondas();

    while(rondasEstablecidas != 0){
        mostrarRondaActual(jugador1, ronda, puntaje1);
        puntaje1 = jugarTurno(puntaje1, ronda, partidaSimulada, lanzamientos1);

        if(puntaje1 == ESCALERA){
            guardarInfoPartida(infoPartida, ESCALERA, ronda);
            mostrarGanador(jugador1, puntaje1, ronda);
            ganador = jugador1;
            break;
        }

        mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);

        mostrarRondaActual(jugador2, ronda, puntaje2);
        puntaje2 = jugarTurno(puntaje2, ronda, partidaSimulada, lanzamientos2);

        if(puntaje2 == ESCALERA){
            guardarInfoPartida(infoPartida, ESCALERA, ronda);
            mostrarGanador(jugador2, puntaje2, ronda);
            ganador = jugador2;
            break;
        }

        mostrarPuntajeParcial(jugador1, puntaje1, jugador2, puntaje2);

        int idGanador = obtenerGanador(puntaje1, puntaje2);

        if(idGanador == 1){
            guardarInfoPartida(infoPartida, puntaje1, ronda);
            mostrarGanador(jugador1, puntaje1, ronda);
            ganador = jugador1;
            break;
        } else if(idGanador == 2){
            guardarInfoPartida(infoPartida, puntaje2, ronda);
            mostrarGanador(jugador2, puntaje2, ronda);
            ganador = jugador2;
            break;
        } else if(idGanador == 3){
            mostrarEmpate(puntaje1);

            if(lanzamientos1 < lanzamientos2){
                mostrarGanadorPorLanzamientos(jugador1);
            } else {
                mostrarGanadorPorLanzamientos(jugador2);
            }

            break;
        }

        ronda++;
        rondasEstablecidas--;
    }

    return ganador;
}

int jugarTurno(int puntosActuales, int ronda, bool partidaSimulada, int &lanzamientosUsados) {
    const int ESCALERA = -1, RESETEO = -2;
    int puntosDeRonda = jugarRonda(partidaSimulada, lanzamientosUsados);

    switch (puntosDeRonda) {
        case ESCALERA:  return ESCALERA;
        case RESETEO:   mostrarSeReseteanPuntos(); return 0;
        default:        mostrarPuntajeDeRonda(ronda, puntosDeRonda); return puntosDeRonda + puntosActuales;
    }
}

int jugarRonda(bool partidaSimulada, int &lanzamientosUsados) {
    const int ESCALERA = -1, RESETEAR = -2;
    int puntos[3];
    int lanzamientosEfectivos = 0;
    int maxPuntaje = 0;

    for (int i = 0; i < 3; i++) {
        mostrarNumeroLanzamiento(i + 1);
        int puntajeTirada = tirarDados(partidaSimulada);

        if (puntajeTirada == ESCALERA) return ESCALERA;
        if (puntajeTirada == RESETEAR) return RESETEAR;

        puntos[i] = puntajeTirada;
        mostrarPuntajeTirada(puntajeTirada);

        if (puntajeTirada > maxPuntaje) {
            maxPuntaje = puntajeTirada;
            lanzamientosEfectivos = i + 1;
        }
    }

    lanzamientosUsados += lanzamientosEfectivos;
    return maxPuntaje;
}
