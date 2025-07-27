# 🎲 CIEN o Escalera – Juego de dados en C++

Este proyecto fue desarrollado como **Trabajo Práctico Integrador** para la materia **Programación 1** (Primer año, primer cuatrimestre) de la carrera **Técnico Universitario en Programación**.

## 📌 Descripción

Se trata de un juego de dados por turnos, en el que uno o dos jugadores compiten para alcanzar 100 puntos o sacar una escalera. El juego se ejecuta en consola y respeta todas las reglas planteadas por la consigna original del TPI.

## 🕹️ Modos de juego

- 👤 **Modo un jugador**  
  Jugás contra vos mismo hasta alcanzar 100 puntos o sacar una escalera.

- 👥 **Modo dos jugadores**  
  Cada jugador lanza sus dados por turnos. Gana quien llega primero a 100 puntos o consigue una escalera.

- 🧪 **Modo simulado (testing)**  
  Permite ingresar manualmente los valores de los dados para probar combinaciones. Ideal para correcciones o tests. *Este modo puede estar oculto en el menú.*

## 🏆 Sistema de ranking

El programa guarda un **ranking de los 4 mejores puntajes**, que se actualiza automáticamente cuando un jugador supera alguna marca.  
Además, el ranking **se mantiene entre ejecuciones del programa** gracias al uso de archivos de texto.

## 🎯 Objetivo del juego

- Alcanzar **100 puntos** en la menor cantidad de rondas posibles.
- O bien, ganar instantáneamente si obtenés una **escalera (1 a 6)** en un solo lanzamiento.
- Cuidado con el **sexteto de 6**: ¡resetea tu puntaje a 0!

## 📋 Reglas de puntuación

| Combinación             | Descripción                        | Puntos              |
|------------------------|-------------------------------------|---------------------|
|Menos de 6 dados iguales| Suma de todos los dados           | Total de la suma    |
| Sexteto (6 dados iguales, excepto 6) "X * 10" (ej: 5*10 = 50)| Según el valor repetido |
| Sexteto de 6           | Puntaje total se reinicia a 0       | 0                   |
| Escalera (1 a 6)       | Ganás la partida automáticamente    | -                   |

> El puntaje de cada ronda es el **más alto** de los 3 lanzamientos posibles.

## 🧱 Tecnologías usadas

- Lenguaje: **C++**
- IDE: **Code::Blocks**
- Entrada/Salida por consola
- Manejo de archivos para guardar el ranking (`ranking.txt`)

## 💡 Aprendizajes y objetivos cumplidos

✅ Estructuración de código con funciones  
✅ Uso de vectores  
✅ Modularización del programa con encabezados (`.h`)  
✅ Implementación de lógica de turnos, rondas y combinaciones  
✅ Persistencia de datos con archivos  
✅ Práctica con estructuras de control y flujo

## 📂 Estructura del proyecto
/dados
├── main.cpp
├── funciones.cpp
├── funciones.h
├── ranking.txt
└── README.md

## 🚀 Cómo ejecutar el juego

1. Abrí el proyecto en Code::Blocks.
2. Compilá el proyecto.
3. Ejecutá el programa y seguí las instrucciones del menú principal.

---

Este juego representa mis primeros pasos en el mundo del desarrollo de software.  
¡Gracias por leer y espero que lo disfrutes!

