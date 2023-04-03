#include <iostream>
#include <string>

using namespace std;
int main()
{
	int n, m, k, temp;
	char direction = 'N';
	bool dot;
	cin >> n;
	cin >> m;

	string* tab = new string[n];

	for (int i = 0; i < n; i++)
	{
		cin >> tab[i];
	}

	cin >> k;

	string text;

	cin >> text;
	for (int a = 0; a < k; a++)
	{
		if ((text[a] == 'G' || text[a] == 'D'))
		{
			if (!(text[a + 1] == 'G' || text[a + 1] == 'D'))
			{
				if (text[a] == 'G' && direction != 'G')
				{
					for (int i = 0; i < m; i++)
					{
						dot = 0;
						for (int j = 0; j < n; j++)
						{
							if (tab[j][i] == '.' && !dot)
							{
								dot = 1;
								temp = j;
							}
							else if (tab[j][i] != '.' && dot)
							{
								swap(tab[temp][i], tab[j][i]);
								temp++;
							}
						}
					}
					direction = 'G';
				}
				else if (text[a] == 'D' && direction != 'D')
				{
					for (int i = 0; i < m; i++)
					{
						dot = 0;
						for (int j = n - 1; j >= 0; j--)
						{
							if (tab[j][i] == '.' && !dot)
							{
								dot = 1;
								temp = j;
							}
							else if (tab[j][i] != '.' && dot)
							{
								swap(tab[temp][i], tab[j][i]);
								temp--;
							}
						}
					}
					direction = 'D';
				}
			}
		}
		else if ((text[a] == 'L' || text[a] == 'P'))
		{
			if (!(text[a + 1] == 'L' || text[a + 1] == 'P'))
			{
				if (text[a] == 'L' && direction != 'L')
				{
					for (int i = 0; i < n; i++)
					{
						dot = 0;
						for (int j = 0; j < m; j++)
						{
							if (tab[i][j] == '.' && !dot)
							{
								dot = 1;
								temp = j;
							}
							else if (tab[i][j] != '.' && dot)
							{
								swap(tab[i][temp], tab[i][j]);
								temp++;
							}
						}
					}
					direction = 'L';
				}
				else if (text[a] == 'P' && direction != 'P')
				{
					for (int i = 0; i < n; i++)
					{
						dot = 0;
						for (int j = m - 1; j >= 0; j--)
						{
							if (tab[i][j] == '.' && !dot)
							{
								dot = 1;
								temp = j;
							}
							else if (tab[i][j] != '.' && dot)
							{
								swap(tab[i][temp], tab[i][j]);
								temp--;
							}
						}
					}
					direction = 'P';
				}

			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << tab[i] << "\n";
	}
}