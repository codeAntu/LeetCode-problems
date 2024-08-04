def get_beauty(grid, start_row, start_col, size):
    subgrid = [grid[i][start_col:start_col+size] for i in range(start_row, start_row+size)]
    flat_subgrid = [item for row in subgrid for item in row]
    return max(flat_subgrid) - min(flat_subgrid)

def max_sum_of_beauties(grid):
    N = len(grid)
    max_sum = 0

    # We iterate over all possible sub-grids
    for size1 in range(1, N+1):
        for row1 in range(N - size1 + 1):
            for col1 in range(N - size1 + 1):
                beauty1 = get_beauty(grid, row1, col1, size1)

                # Find a non-overlapping sub-grid
                for size2 in range(1, N+1):
                    for row2 in range(N - size2 + 1):
                        for col2 in range(N - size2 + 1):
                            # Check if the two sub-grids overlap
                            if not (row2 < row1 + size1 and row2 + size2 > row1 and col2 < col1 + size1 and col2 + size2 > col1):
                                beauty2 = get_beauty(grid, row2, col2, size2)
                                max_sum = max(max_sum, beauty1 + beauty2)

    return max_sum

# Example usage
N = 4
grid = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
]

print(max_sum_of_beauties(grid))
