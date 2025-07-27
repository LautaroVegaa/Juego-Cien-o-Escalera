#include <iostream>
#include "operaciones.h"
#include "interfaz.h"
#include <fstream> // para leer y escribir archivos


int calcularCombinacion(int dados[], int cantidadDados, int combinacion){

    int SUMA = 1, MULTIPLICAR = 2, resultado = 0;

    if(combinacion == SUMA){

        for(int i = 0; i<cantidadDados; i++){
            resultado += dados[i];
        }

    } else if(combinacion == MULTIPLICAR){

        resultado = dados[0] * 10;

    }

    return resultado;

}

int analizarCombinacion(int dados[], int cantidadDados){

    int ESCALERA = -1;
    int RESETEAR = -2;
    int SUMA = 1;
    int MULTIPLICAR = 2;

    ordenarDados(dados, cantidadDados);

    int contCoincidencias = 1, contEscalera = 1;
    int dadoReferencia = dados[0];

    for(int i = 1; i<cantidadDados; i++){

        if(dados[0] == dados[i]) contCoincidencias++; //Se evalua si todos los numeros son iguales tomando como referencia el primer valor

        if(dadoReferencia+1 == dados[i]){ //Se evalua si hay escalera
            dadoReferencia = dados[i];
            contEscalera++;
        }
    }

    if(contCoincidencias == 6 && dadoReferencia == 6) return RESETEAR;
    if(contCoincidencias == 6) return MULTIPLICAR;
    if(contEscalera == 6) return ESCALERA;

    return SUMA;

}

void ordenarDados(int dados[], int cantidadDados){

    for(int i = 0; i<cantidadDados-1; i++){

        int posMin = i;
        int aux;

        for(int j = i+1; j<cantidadDados; j++){
            if(dados[j]<dados[posMin]) posMin=j;
        }

        aux = dados[i];
        dados[i] = dados[posMin];
        dados[posMin] = aux;
    }

}

int obtenerPuntajeMaximo(int puntos[], int cantidadPuntos){

    int posMax=0;

    for(int i = 1; i<cantidadPuntos ;i++){

        if(puntos[i]>puntos[posMax]) {
                posMax=i;
        }

    }

    return puntos[posMax];

}

std::string analizarInfoPartida(std::string nombreActual, std::string nombreJugador, int infoPartida[], int infoMejorPartida[]){

    int posRondas = 0, posPuntos = 1;

    if(nombreJugador == "Sin ganador") return nombreActual;

    if(infoPartida[posPuntos] <= infoMejorPartida[posPuntos] && infoPartida[posRondas] <= infoMejorPartida[posRondas]){

        infoMejorPartida[posRondas] = infoPartida[posRondas];
        infoMejorPartida[posPuntos] = infoPartida[posPuntos];
        return nombreJugador;
    }

    return nombreActual;

}

bool chequearGanador(int puntaje) {
    const int ESCALERA = -1;
    return puntaje >= 100 || puntaje == ESCALERA;
}

void guardarInfoPartida(int infoPartida[], int puntaje, int rondas) {
    int posRondas = 0, posPuntos = 1;
    infoPartida[posRondas] = rondas;
    infoPartida[posPuntos] = puntaje;
}

int obtenerGanador(int puntaje1, int puntaje2) {
    if (puntaje1 >= 100 && puntaje2 >= 100) {
        if (puntaje1 < puntaje2) return 1;
        if (puntaje2 < puntaje1) return 2;
        return 3;
    }
    if (puntaje1 >= 100) return 1;
    if (puntaje2 >= 100) return 2;
    return 0;
}

int tirarDados(bool partidaSimulada) {
    const int ESCALERA = -1;
    const int RESETEAR = -2;
    const int SUMA = 1;
    const int MULTIPLICAR = 2;

    int cantidadDados = 6, puntaje, combinacion;
    int dados[cantidadDados];

    for (int i = 0; i < cantidadDados; i++) {
        if (partidaSimulada) dados[i] = pedirValorDado(i + 1);  //  debe estar definida en otro módulo
        else dados[i] = (rand() % 6) + 1;
    }

    combinacion = analizarCombinacion(dados, cantidadDados);
    mostrarDados(dados, cantidadDados);

    switch (combinacion) {
        case RESETEAR:
            mostrarCombinacion(RESETEAR, dados[0]);
            puntaje = RESETEAR;
            break;
        case SUMA:
            mostrarCombinacion(SUMA, dados[0]);
            puntaje = calcularCombinacion(dados, cantidadDados, SUMA);
            break;
        case MULTIPLICAR:
            mostrarCombinacion(MULTIPLICAR, dados[0]);
            puntaje = calcularCombinacion(dados, cantidadDados, MULTIPLICAR);
            break;
        case ESCALERA:
            mostrarCombinacion(ESCALERA, dados[0]);
            puntaje = ESCALERA;
            break;
}

    return puntaje;
}

// FUNCIONES DE RANKING

// Inserta un nuevo jugador en el ranking si su cantidad de rondas es mejor (más baja)
void actualizarRanking(RankingEntry ranking[], std::string nombre, int rondas, int puntos) {
    for (int i = 0; i < 4; i++) {
        if (rondas < ranking[i].rondas) {
            for (int j = 3; j > i; j--) {
                ranking[j] = ranking[j - 1];
            }
            ranking[i].nombre = nombre;
            ranking[i].rondas = rondas;
            ranking[i].puntos = puntos;
            break;
        }
    }
}

// Muestra en pantalla el ranking de los 4 mejores jugadores
void mostrarRanking(RankingEntry ranking[]) {
    std::cout << "\n----- RANKING TOP 4 -----\n";
    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << ranking[i].nombre << "\n";
        std::cout << "  - " << ranking[i].rondas << " rondas\n";
        std::cout << "  - " << ranking[i].puntos << " puntos\n";
    }
    std::cout << "-------------------------\n\n";
}




// Guarda el ranking en un archivo de texto
void guardarRanking(RankingEntry ranking[], const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo); // Abre el archivo para escritura
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para guardar ranking.\n";
        return;
    }

    // Escribe los 4 jugadores línea por línea (nombre y rondas)
    for (int i = 0; i < 4; i++) {
        archivo << ranking[i].nombre << " " << ranking[i].rondas << "\n";
    }

    archivo.close(); // Cierra el archivo
}

// Carga el ranking desde un archivo de texto
void cargarRanking(RankingEntry ranking[], const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo); // Abre el archivo para lectura
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de ranking. Se usará el ranking por defecto.\n";
        return;
    }

    // Lee nombre y rondas. Si falla, pone valores por defecto.
    for (int i = 0; i < 4; i++) {
        if (!(archivo >> ranking[i].nombre >> ranking[i].rondas)) {
            ranking[i] = {"Sin jugador", 1000};
        }
    }

    archivo.close(); // Cierra el archivo
}



