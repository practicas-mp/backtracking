Práctica de Backtracking
==========================
El problema que teníamos que resolver era el siguiente:

> Dada una serie de jugadores con distintas habilidades identificadas con enteros, encontrad la división en equipos más equilibrada

### Soluciones
Tal como nos decían en la tarea, hemos desarrollado dos algoritmos:
* **Backtracking**: este algoritmo introduce al primer jugador en la solución y explora con DFS a partir de ahí todos los equipos que contengan a este jugador. En cuanto se encuentre un equipo que tenga como puntuación la mitad de la puntuación total, se devuelve. Está implementado en ````src/algorithms/backtrack.cpp````

* **Branch and Bound**: este algoritmo incorpora una función de poda para no explorar soluciones que no van a llevar a la óptima. En cuanto la puntuación de un equipo es mayor que la puntuación que se busca, no tiene sentido seguir añadiendo jugadores al equipo (lo que es bastante obvio), y por lo tanto se puede descartar la solución. Está implementado en ````src/algorithms/bb.cpp````


### Sets de datos
Los sets de datos han sido generados con ````scripts/generate.py <NUMBER-OF-PLAYERS> [exact]````. Generan según se le pase segundo argumento o no un set de datos con una división exacta.

La primera línea de los sets de datos incluyen una cota superior para la diferencia óptima entre los equipos. Los sets de datos se pueden encontrar en ````data/````.