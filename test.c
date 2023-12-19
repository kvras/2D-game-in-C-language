#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
typedef struct {
            int len;
            int width;
            char **map;
            int player_x;
            int collect;
            int exit;
        }map;
map_to_matrix(int fd)
{
    char *line;
    char **str;
    int i;
    i = 0;
    str = malloc(sizeof(char *) * 100);
    while((line = get_next_line(fd)))
    {
        strcat(str[i], line);
        i++;
        free(line);
        line = NULL;
    }
    return (str);
}
int flood_fill(int fd, int *exit, int *collecte,int x, int y, char **str)
{
    char *line;
    int i;
    i = 0;
    if (x >= i || y >= strlen(line) || x < 0 || y < 0  || str[x][y] == '1' || str[x][y] == '\0')
        return (0);
    if(str[x][y] == 'C')
        (*collecte)--;
    if(str[x][y] == 'E' && *collecte == 0)
        (*exit)--;
    flood_fill(fd, exit, collecte, x + 1, y);
    flood_fill(fd, exit, collecte, x - 1, y);
    flood_fill(fd, exit, collecte, x, y + 1);
    flood_fill(fd, exit, collecte, x, y - 1);
    if(collecte == 0 && exit == 0)
        return (1);
    return (0);
}
int main()
{
    map map;
    map.width = 0;
    map.map = NULL;
    map.player_x = 1;
    map.collect = 9;
    map.exit = 1;
    int fd;
    fd = open("map1.ber", O_RDONLY);
    char **str = map_to_matrix(fd);
    printf("%d\n",flood_fill(fd, &exit, &collecte, 1, 6, str));
    close(fd);
}