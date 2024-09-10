#ifndef PILOTE_I2C1_H
#define PILOTE_I2C1_H

#include <stdint.h>

// Function prototypes for I2C operations
int piloteI2C1_configureLAdresse(int fdPortI2C, int adresse);
int piloteI2C1_ecritDesOctets(int *message, int taille);
int piloteI2C1_litDesOctets(int *commande, int tailleCommande, uint8_t *donnees, int tailleDonnees);

#endif // PILOTE_I2C1_H
