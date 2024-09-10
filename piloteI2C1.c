#include "piloteI2C1.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>

#include "main.h"
#include "piloteI2C1.h"

// Function to configure the I2C address
int piloteI2C1_configureLAdresse(int fdPortI2C, uint8_t adresse) {
    if (ioctl(fdPortI2C, I2C_SLAVE_FORCE, adresse) < 0) {
        perror("Erreur lors de la configuration de l'adresse I2C");
        return -1; // Error setting I2C address
    }
    return 0; // Success
}

// Function to write a number of bytes to the I2C device
int piloteI2C1_ecritDesOctets(uint8_t *message, int taille) {
    if (write(fdPortI2C, message, taille) != taille) {
        perror("Erreur lors de l'écriture sur l'I2C");
        return -1; // Error writing bytes
    }
    return 0; // Success
}

// Function to read a number of bytes from the I2C device
int piloteI2C1_litDesOctets(uint8_t *commande, int tailleCommande, uint8_t *donnees, int tailleDonnees) {
    // Write the command to the device
    if (write(fdPortI2C, commande, tailleCommande) != tailleCommande) {
        perror("Erreur lors de l'envoi de la commande I2C");
        return -1; // Error writing command
    }

    // Read the data from the device
    if (read(fdPortI2C, donnees, tailleDonnees) != tailleDonnees) {
        perror("Erreur lors de la lecture des données I2C");
        return -1; // Error reading data
    }

    return 0; // Success
}
