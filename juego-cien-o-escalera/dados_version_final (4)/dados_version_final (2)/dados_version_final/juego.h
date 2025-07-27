#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

std::string modoUnJugador(int infoPartida[], bool partidaSimulada);
std::string modoDosJugadores(int infoPartida[], bool partidaSimulada);
int jugarTurno(int puntosActuales, int ronda, bool partidaSimulada, int &lanzamientosUsados);
int jugarRonda(bool partidaSimulada, int &lanzamientosUsados);
int tirarDados(bool partidaSimulada);

int analizarCombinacion(int dados[], int cantidadDados);
int calcularCombinacion(int dados[], int cantidadDados, int combinacion);
int obtenerPuntajeMaximo(int puntos[], int cantidadPuntos);
bool chequearGanador(int puntaje);
int obtenerGanador(int puntaje1, int puntaje2);
void guardarInfoPartida(int infoPartida[], int puntaje, int ronda);

#endif // JUEGO_H_INCLUDED
