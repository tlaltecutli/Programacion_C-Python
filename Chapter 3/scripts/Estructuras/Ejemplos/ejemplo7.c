/*
*/

#include <stdio.h>
#include <string.h>

struct Estudiante {
	char nombre[50];
	int edad;
	float promedio;
};

int main() {
	struct Estudiante *ptr_est;
	struct Estudiante est = {"Pedro", 23, 8.8};

	ptr_est = &est;

// Acceso a través de puntero
	return 0;
}