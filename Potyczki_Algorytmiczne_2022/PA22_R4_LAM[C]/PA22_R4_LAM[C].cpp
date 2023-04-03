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

	string tekst;

	cin >> tekst;
	for (int a = 0; a < k; a++)
	{
		if ((tekst[a] == 'G' || tekst[a] == 'D'))
		{
			if (!(tekst[a + 1] == 'G' || tekst[a + 1] == 'D'))
			{
				if (tekst[a] == 'G' && direction != 'G')
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
				else if (tekst[a] == 'D' && direction != 'D')
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
		else if ((tekst[a] == 'L' || tekst[a] == 'P'))
		{
			if (!(tekst[a + 1] == 'L' || tekst[a + 1] == 'P'))
			{
				if (tekst[a] == 'L' && direction != 'L')
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
				else if (tekst[a] == 'P' && direction != 'P')
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