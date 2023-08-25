#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    setlocale(LC_CTYPE, "");
    printf("\tSalut, si vous entrez 'O pour Oui', vous aurez l'heure actuelle, et si vous entrez 'N pour Non', vous entrez dans un jeu.\n\n");

    char reponse;
    do {
        printf("\t\tVoulez-vous conna�tre l'heure actuelle? (O/N)\n");
        reponse = getchar();
        clearInputBuffer();

        if (reponse == 'O' || reponse == 'o') {
            time_t temps_actuel = time(NULL);
            struct tm *temps_decompose = localtime(&temps_actuel);
            printf("\n\tIl est actuellement %02d:%02d:%02d\n",
                    temps_decompose->tm_hour,
                    temps_decompose->tm_min,
                    temps_decompose->tm_sec);
        } else if (reponse != 'N' && reponse != 'n') {
            printf("\nEntr�e non valide, entrez 'O' ou 'N'\n\n");
        }
    } while (reponse != 'N' && reponse != 'n');

    printf("\n\t\tVous �tes entr� dans le jeu.\n");
    printf("\tEntrez 'q' si vous voulez sortir du jeu.\n");
    //printf("Veuillez SVP espacer vos phrases avec : _\n");
    printf("Vous devez aussi tenir compte des majuscules et des minuscules.\n");

    int points = 0;
    int tentatives = 3;
    char reponse_joueur[20];
    char * devinettes[10] = { "Quel est le continent sur lequel se trouve l��tat de Palestine?",
                                                "\nQuelle est la plus grande ville du continent europ�en?",
                                                "\nQuelle est la ville de l�amour et de la beaut�?",
                                                "\nCombien de pays arabes y a-t-il sur le continent africain?",
                                                "\nQuel pays s�appelle le pays des lapins",
                                                "\nQuel est le plus grand animal?",
                                                "\nCombien de mois ont 31 jours?",
                                                "\nQuel est le plus grand oc�an?",
                                                "\nQuel est le plus grand pays?",
                                                "\nQuel est le plus grand volcans?" };

    char * reponses[10] = {   "Asie","Londres",
                                                "Paris",
                                                "9",
                                                "Espagne",
                                                "Baleine bleue",
                                                "7",
                                                "Oc�an Pacifique",
                                                "Russie",
                                                "Mauna Loa"  };
    int nbDevinettes = 10;
    srand(time(NULL));

    while (points != nbDevinettes) {
        int devinetteActuelle = rand() % nbDevinettes;
        printf("%s\n\n", devinettes[devinetteActuelle]);

        while (tentatives > 0) {
            int index = 0;
            char c;
            while ((c = getchar()) != '\n' && c != EOF && index < 19) {
                reponse_joueur[index++] = c;
            }
            reponse_joueur[index] = '\0';

            if (strcmp(reponse_joueur, reponses[devinetteActuelle]) == 0) {
                printf("Correct!\n\n");
                points++;
                break;
            } else if (strcmp(reponse_joueur, "q") == 0) {
                printf("\n\nVous avez quitt� le jeu.\n");
                return 0;
            } else {
                tentatives--;
                if (tentatives == 0) {
                    printf("\n\nD�sol�, vous avez atteint le nombre maximum de tentatives. La r�ponse correcte �tait: %s\n",
                            reponses[devinetteActuelle]);
                } else {
                    printf("\nIncorrect. Il vous reste %d tentatives ou tapez 'q' pour quitter\n", tentatives);
                }
            }
        }
        tentatives = 3;
    }

    printf("Bravo, vous avez r�solu toutes les questions pos�es ! Votre score est de : %d\n", points);
    return 0;
}
