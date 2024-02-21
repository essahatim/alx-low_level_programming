#!/usr/bin/python3
"""Define island perimeter """


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.
    Returns: the perimeter of the island.
    """
    perimeter = 0
    heigth = len(grid)
    if heigth > 0:
        width = len(grid[0])
    else:
        width = 0

    for i in range(heigth):
        for j in range(width):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
