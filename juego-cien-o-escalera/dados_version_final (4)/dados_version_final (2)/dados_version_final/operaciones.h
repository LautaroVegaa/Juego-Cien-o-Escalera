#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

#include <iostream>

using namespace std;

int calcularCombinacion(int dados[], int cantidadDados, int combinacion);
int analizarCombinacion(int dados[], int cantidadDados);
int obtenerPuntajeMaximo(int puntos[], int cantidadPuntos);
void ordenarDados(int dados[], int cantidadDados);
std::string analizarInfoPartida(std::string nombreActual, std::string nombreMejorJugador, int infoPartida[], int infoMejorPartida[]);

// RANKING TOP 4 DE JUGADORES

// Estructura que representa un jugador y la cantidad de rondas que tardó en ganar
struct RankingEntry {
    std::string nombre;
    int rondas;
    int puntos;
};

// Función que actualiza el ranking con un nuevo jugador si su resultado es mejor
void actualizarRanking(RankingEntry ranking[], std::string nombre, int rondas, int puntos);

// Función que muestra el ranking en pantalla
void mostrarRanking(RankingEntry ranking[]);

// Declaraciones de funciones para guardar y cargar el ranking
void guardarRanking(RankingEntry ranking[], const std::string& nombreArchivo);
void cargarRanking(RankingEntry ranking[], const std::string& nombreArchivo);


#endif // OPERACIONES_H_INCLUDED
