#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_diag(int pos, int i, int *tab);

int check_col(int pos, int *tab, int i)
{
	int k;
	
	k = 0;
	while(k < 8)
	{
		if(pos == tab[k] && k != i)
		{
			return 0;
		}
		k++;
	}
	return 1;
}
void display(int grid[])
{
	int i;
	i = 0;
	while(i < 8)
	{
		ft_putchar(grid[i] + '0');
		i++;
	}
	ft_putchar('\n');
	
}
int eight_queens(int col, int i, int grid[], int result)
{
	if(i == 0 && col == 9)
		return result;
	else if(i == 8)
        {
		display(grid);
        	result = result + 1;
        	col = grid[i - 1];
        	grid[i - 1] = 0;
        	return(eight_queens(col + 1, i - 1, grid, result));
        }
	else if(i != 0 && col == 9)
	{
		col = grid[i - 1];
		grid[i - 1] = 0;
		return(eight_queens(col + 1, i - 1, grid, result));
	}
	else if(check_col(col, grid, i) == 1 && check_diag(col, i, grid) == 1)
	{
		grid[i] = col;
		col = 1;
		return(eight_queens(col, i + 1, grid, result));
	}
	else
		return(eight_queens(col + 1, i, grid, result));
}


int check_diag(int pos, int i, int *tab)
{
	int k;
	
	k = 0;
	while(k < 8)
	{
		if((tab[k] - pos == k - i) && k != i && tab[k] != 0)
			return 0;
		k++;
	}
	k = k - 1;	
	while(k >= 0)
	{
		if(k + tab[k]  ==  pos + i && k != i && tab[k] != 0)
			return 0;
		k--; 
	}
	return 1;
}

int ft_eight_queens_puzzle(void)
{
	int grid[8];
	int i;
	int j;
	int result;
	
	i = 0;
	j = 1;
	result = 0;
	while(i < 8)
	{
		grid[i] = 0;
		i++;
	}
	i = 0;
	i = eight_queens(j, i, grid, result);
	ft_putchar((i/10) + '0');
	ft_putchar((i % 10) + '0');
	return 0;	
}

int main()
{
	ft_eight_queens_puzzle();	
}
