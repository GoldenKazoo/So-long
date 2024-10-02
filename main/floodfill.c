#include <stdbool.h>
#include "parsing.h"

void flood_fill(t_data *data, int x, int y, int *found_exit, int *collectibles_left) {
	// Est ce qu'on est hors de la map ?
	if (x < 0 || x >= data -> map_width || y < 0 || y >= data -> map_height)
		return;

	// Si la case est un mur ou déjà visitée, on stop
	if (data -> tab[y][x] == '1' || data -> tab[y][x] == 'V')
		return;

	// Si on trouve un collectible, on marque
	if (data ->tab[y][x] == 'C') {
		(*collectibles_left)--;
	}

	// Si on trouve la sortie, on la marque
	if (data -> tab[y][x] == 'E') {
		*found_exit = 1;
	}

	// met les cases check en V
	data -> tab[y][x] = 'V';

	// Appeler la fonction récursivement dans les 4 directions
	flood_fill(data, x + 1, y, found_exit, collectibles_left); // droite
	flood_fill(data, x - 1, y, found_exit, collectibles_left); // gauche
	flood_fill(data, x, y + 1, found_exit, collectibles_left); // bas
	flood_fill(data, x, y - 1, found_exit, collectibles_left); // haut
}

int	check_map_accessibility(t_data *data) {

	int	found_exit;
	int	collectibles_left;
	int x = 0;
	int y = 0;
	found_exit = 0;
	collectibles_left = 0;

	// Check la position du joueur et compter les items
	while (y < data -> map_height)
	{
		x = 0;
		while (x < data ->map_width)
		{
			if (data->tab[y][x] == 'P')
			{
				data -> player_posX = x;
				data -> player_posY = y;
			} else if (data->tab[y][x] == 'C')
			{
				collectibles_left++;
			}
			x++;
		}
		y++;
	}
	// Lancer l'algorithme ff depuis la position du joueur
	flood_fill(data, data -> player_posX, data -> player_posY, &found_exit, &collectibles_left);

	// Vérifier si tous les collectibles ont été ramassés et si la sortie est accessible
	if ((collectibles_left == 0) && (found_exit == 1))
		return(1);
	else
		return(0);
}
