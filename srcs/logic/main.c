#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Vous devez inclure vos propres fichiers d'en-tête ici
// #include "get_next_line.h"
// #include "libft.h"

// Pour cet exemple, nous allons supposer que vous avez les fonctions suivantes :
char *get_next_line(int fd); // Fonction pour lire une ligne du fichier
size_t ft_strlen(const char *s); // Fonction pour obtenir la longueur d'une chaîne
void ft_putstr_fd(char *s, int fd); // Fonction pour écrire une chaîne dans un fd

// Structure pour stocker la carte et ses dimensions
typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
}   t_map;

// Fonction pour lire la carte depuis le fichier
t_map *read_map(const char *file_path)
{
    int     fd;
    char    *line;
    t_map   *map;
    int     i;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return (NULL);
    }

    map = malloc(sizeof(t_map));
    if (!map)
    {
        perror("Erreur d'allocation mémoire pour la carte");
        close(fd);
        return (NULL);
    }
    map->grid = NULL;
    map->height = 0;
    map->width = -1;

    while ((line = get_next_line(fd)) != NULL)
    {
        int line_length = ft_strlen(line);
        if (line[line_length - 1] == '\n')
            line[--line_length] = '\0'; // Supprimer le caractère de nouvelle ligne

        if (map->width == -1)
            map->width = line_length;
        else if (line_length != map->width)
        {
            ft_putstr_fd("Erreur : La carte n'est pas rectangulaire\n", 2);
            free(line);
            close(fd);
            return (NULL);
        }

        char **new_grid = realloc(map->grid, sizeof(char *) * (map->height + 1));
        if (!new_grid)
        {
            perror("Erreur lors de la réallocation de la grille");
            free(line);
            close(fd);
            return (NULL);
        }
        map->grid = new_grid;
        map->grid[map->height] = line;
        map->height++;
    }
    close(fd);

    if (map->height == 0 || map->width == 0)
    {
        ft_putstr_fd("Erreur : La carte est vide\n", 2);
        return (NULL);
    }

    return (map);
}

// Fonction pour vérifier que la carte est entourée de murs ('1')
int check_walls(t_map *map)
{
    int i;

    // Vérifier la première et la dernière ligne
    for (i = 0; i < map->width; i++)
    {
        if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
            return (0);
    }

    // Vérifier les premières et dernières colonnes de chaque ligne
    for (i = 0; i < map->height; i++)
    {
        if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
            return (0);
    }

    return (1);
}

// Fonction pour compter les composants ('E', 'P', 'C') dans la carte
void count_components(t_map *map, int *exit_count, int *start_count, int *collectible_count)
{
    int i, j;

    *exit_count = 0;
    *start_count = 0;
    *collectible_count = 0;

    for (i = 0; i < map->height; i++)
    {
        for (j = 0; j < map->width; j++)
        {
            if (map->grid[i][j] == 'E')
                (*exit_count)++;
            else if (map->grid[i][j] == 'P')
                (*start_count)++;
            else if (map->grid[i][j] == 'C')
                (*collectible_count)++;
        }
    }
}

// Fonction principale de validation de la carte
int validate_map(t_map *map)
{
    int exit_count;
    int start_count;
    int collectible_count;

    if (!check_walls(map))
    {
        ft_putstr_fd("Erreur : La carte n'est pas correctement entourée de murs\n", 2);
        return (0);
    }

    count_components(map, &exit_count, &start_count, &collectible_count);

    if (exit_count == 0)
    {
        ft_putstr_fd("Erreur : La carte doit avoir au moins une sortie ('E')\n", 2);
        return (0);
    }
    else if (exit_count > 1)
    {
        ft_putstr_fd("Erreur : La carte ne doit avoir qu'une seule sortie ('E')\n", 2);
        return (0);
    }

    if (start_count == 0)
    {
        ft_putstr_fd("Erreur : La carte doit avoir au moins un point de départ ('P')\n", 2);
        return (0);
    }
    else if (start_count > 1)
    {
        ft_putstr_fd("Erreur : La carte ne doit avoir qu'un seul point de départ ('P')\n", 2);
        return (0);
    }

    if (collectible_count == 0)
    {
        ft_putstr_fd("Erreur : La carte doit avoir au moins un collectible ('C')\n", 2);
        return (0);
    }

    return (1); // La carte est valide
}

// Fonction pour libérer la mémoire allouée pour la carte
void free_map(t_map *map)
{
    int i;

    if (!map)
        return;
    for (i = 0; i < map->height; i++)
        free(map->grid[i]);
    free(map->grid);
    free(map);
}

int main(int argc, char **argv)
{
    t_map *map;

    if (argc != 2)
    {
        ft_putstr_fd("Usage: ./programme nom_de_fichier.ber\n", 2);
        return (1);
    }

    map = read_map(argv[1]);
    if (!map)
    {
        ft_putstr_fd("Erreur : Impossible de lire la carte\n", 2);
        return (1);
    }

    if (validate_map(map))
    {
        ft_putstr_fd("La carte est valide !\n", 1);
        // Vous pouvez continuer avec le reste de votre programme ici
    }
    else
    {
        ft_putstr_fd("La carte est invalide.\n", 2);
    }

    free_map(map);
    return (0);
}
