#include <stdio.h>

void chessboard(int s[][10]);

void play_chess(int s[][10], int n);

int det_chess(int s[][10], int n);

void computer(int s[][10], int n);

void play_chess2(int s[][10], int n, int i, int j);

int main(void)
{
	int a[10][10] = {0};
	int n = 1;

	chessboard(a);
	printf("You can input 4 4 to put a chess on board!\n");
	while (1) {
		if (n == 1) {
			play_chess(a, n);
			n = det_chess(a, n);
			if (n) break;
			n = 2;
		}
		if (n == 2) {
			computer(a, n);
			n = det_chess(a, n);
			if (n) {
				n++;
				break;
			}
			n = 1;
		}
	}
	if (n == 1) 
		printf("Congratulations, Play %d WIN!\n",n);
	else 
		printf("Congratulations, Computer WIN!\n");

	return 0;
}

void chessboard(int s[][10])
{
	int a, b;

	printf("%2c", '*');
	for (a = 0; a < 10; a++)
		printf("%2d", a);
	printf("\n");
	for (a = 0; a < 10; a++) {
		printf("%2d", a);
		for (b = 0; b < 10; b++) 	
			printf("%2d", s[a][b]);
		printf("\n");
	}
	printf("\n");
}

void play_chess(int s[][10], int n)
{
	int i, j;

	printf("Play %d:", n);
	scanf("%d %d", &i, &j);
	if (i > 9 || i < 0 || j < 0 || j > 9) {
		printf("%d %d is not permitted! please reonput.\n", i, j);
		play_chess(s,n);	
	}
	if (s[i][j] != 0) {
		printf("%d %d is not permitted! please reonput.\n", i, j);
		play_chess(s, n);
	}
	else {
		s[i][j] = n;
		chessboard(s);
	}
}

int det_chess(int s[][10], int n)
{
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (s[i][j] == n ) {
				if (i < 6) {
					if (s[i + 1][j] == n && s[i + 2][j] == n && s[i + 3][j] == n && s[i + 4][j] == n)
						return 1;
				}
				if (i < 6 && j < 6) {
					if (s[i + 1][j + 1] == n && s[i + 2][j + 2] == n && s[i + 3][j + 3] == n && s[i + 4][j + 4] == n)
						return 1;
				}
				if (i >= 4 && j < 6) {
					if (s[i - 1][j + 1] == n && s[i - 2][j + 2] == n && s[i -3][j + 3] == n && s[i - 4][j + 4] == n)
						return 1;
				}
				if (j < 6) {
					if (s[i][j + 1] == n && s[i][j + 2] == n && s[i][j + 3] == n && s[i][j + 4] == n)
						return 1;
				}
			}
		}
	}

	return 0;	
}

void computer(int s[][10], int n)
{
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (s[i][j] == 2) {
				if (i < 7) {
					if (s[i + 1][j] == 2 && s[i + 2][j] == 2 && s[i + 3][j] == 2) {
						if (s[i - 1][j] == 0 && i > 0) {
							play_chess2(s, n, (i - 1), j);
							return ;
						}
						if (s[i + 4][j] == 0 && i < 6) {
							play_chess2(s, n, (i + 4), j);
							return ;
						}
					}
				}
				if (i < 7 && j < 7) {
					if (s[i + 1][j + 1] == 2 && s[i + 2][j + 2] == 2 && s[i + 3][j + 3] == 2) {
						if (s[i - 1][j - 1] == 0 && i > 0 && j > 0) {
							play_chess2(s, n, (i - 1), (j - 1));
							return ;
						}
						if (s[i + 4][j + 4] == 0 && i < 6 && j < 6) {
							play_chess2(s, n, (i + 4), (j + 4));
							return ;
						}
					}
				}
				if (i >= 3 && j < 7) {
					if (s[i - 1][j + 1] == 2 && s[i - 2][j + 2] == 2 && s[i -3][j + 3] == 2) {
						if (s[i + 1][j - 1] == 0 && i < 9 && j > 0) {
							play_chess2(s, n, (i + 1), (j - 1));
							return ;
						}
						if (s[i -4][j + 4] == 0 && i > 3 && j < 6) {
							play_chess2(s, n, (i - 4), (j + 4));
							return ;
						}
					}
				}
				if (j < 7) {
					if (s[i][j + 1] == 2 && s[i][j + 2] == 2 && s[i][j + 3] == 2) {
						if (s[i][j - 1] == 0 && j > 0) {
							play_chess2(s, n, i, (j - 1));
							return ;
						}
						if (s[i][j + 4] == 0 && j < 6) {
							play_chess2(s, n, i, (j + 4));
							return ;
						}
					}
				}
			}
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (s[i][j] == 2) {
				if (i < 8) {
					if (s[i + 1][j] == 2 && s[i + 2][j] == 2) {
						if (s[i + 3][j] == 0 && i < 7) {
							play_chess2(s, n, (i + 3), j);
							return ;
						}
						if (s[i - 1][j] == 0 && i > 0) {
							play_chess2(s, n, (i - 1), j);
							return ;
						}
					}
				}
				if (i < 8 && j < 8) {
					if (s[i + 1][j + 1] == 2 && s[i + 2][j + 2] == 2) {
						if (s[i + 3][j + 3] == 0 && i < 7 && j < 7) {
							play_chess2(s, n, (i + 3), (j + 3));
							return ;	
						}
						if (s[i -1][j -1] == 0 && i > 0 && j > 0) {
							play_chess2(s, n, (i - 1), (j - 1));
							return ;	
						}
					}
				}
				if (i >= 2 && j < 8) {
					if (s[i - 1][j + 1] == 2 && s[i - 2][j + 2] == 2) {
						if (s[i - 3][j + 3] == 0 && i > 2 && j < 7) {
							play_chess2(s, n, (i - 3), (j + 3));
							return ;
						}
						if (s[i + 1][j - 1] == 0 && i < 9 && j > 0) {
							play_chess2(s, n, (i + 1), (j - 1));
							return ;
						}
					}
				}
				if (j < 8) {
					if (s[i][j + 1] == 2 && s[i][j + 2] == 2) {
						if (s[i][j + 3] == 0 && j < 7) {
							play_chess2(s, n, i, (j + 3));
							return ;
						}
						if (s[i][j - 1] == 0 && j > 0) {
							play_chess2(s, n, i, (j - 1));
							return ;
						}
					}
				}
			}
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (s[i][j] == 1) {
				if (i < 8) {
					if (s[i + 1][j] == 1 && s[i + 2][j] == 1) {
						if (s[i - 1][j] == 0 && i > 0) {
							play_chess2(s, n, (i - 1), j);
							return ;
						}
						if (s[i + 3][j] == 0 && i < 7) {
							play_chess2(s, n, (i + 3), j);
							return ;
						}
					}
				}
				if (i < 8 && j < 8) {
					if (s[i + 1][j + 1] == 1 && s[i + 2][j + 2] == 1) {
						if (s[i + 3][j + 3] == 0 && i < 7 && j < 7) {
							play_chess2(s, n, (i + 3), (j + 3));
							return ;	
						}
						if (s[i -1][j - 1] == 0 && i > 0 && j > 0) {
							play_chess2(s, n, (i - 1), (j - 1));
							return ;	
						}
					}
				}
				if (i >= 2 && j < 8) {
					if (s[i - 1][j + 1] == 1 && s[i - 2][j + 2] == 1) {
						if (s[i - 3][j + 3] == 0 && i > 3 && j < 7) {
							play_chess2(s, n, (i - 3), (j + 3));
							return ;
						}
						if (s[i + 1][j - 1] == 0 && i < 9 && j > 0) {
							play_chess2(s, n, (i + 1), (j - 1));
							return ;
						}
					}
				}
				if (j < 8) {
					if (s[i][j + 1] == 1 && s[i][j + 2] == 1) {
						if (s[i][j + 3] == 0 && j < 7) {
							play_chess2(s, n, i, (j + 3));
							return ;
						}
						if (s[i][j - 1] == 0 && j > 0) {
							play_chess2(s, n, i, (j - 1));
							return ;
						}
					}
				}
			}
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (s[i][j] == 1) {
				if (i < 7) {
					if (s[i + 1][j] == 1 && s[i + 2][j] == 1 && s[i + 3][j] == 1) {
						if (s[i - 1][j] == 0 && i > 0) {
							play_chess2(s, n, (i - 1), j);
							return ;
						}
						if (s[i + 4][j] == 0 && i < 6) {
							play_chess2(s, n, (i + 4), j);
							return ;
						}
					}
				}
				if (i < 7 && j < 7) {
					if (s[i + 1][j + 1] == 1 && s[i + 2][j + 2] == 1 && s[i + 3][j + 3] == 1) {
						if (s[i - 1][j - 1] == 0 && i > 0 && j > 0) {
							play_chess2(s, n, (i - 1), (j - 1));
							return ;
						}
						if (s[i + 4][j + 4] == 0 && i < 6 && j < 6) {
							play_chess2(s, n, (i + 4), (j + 4));
							return ;
						}
					}
				}
				if (i >= 3 && j < 7) {
					if (s[i - 1][j + 1] == 1 && s[i - 2][j + 2] == 1 && s[i -3][j + 3] == 1) {
						if (s[i + 1][j - 1] == 0 && i < 9 && j > 0) {
							play_chess2(s, n, (i + 1), (j - 1));
							return ;
						}
						if (s[i - 4][j + 4] == 0 && i > 3 && j < 6) {
							play_chess2(s, n, (i -4), (j + 4));
							return ;
						}
					}
				}
				if (j < 7) {
					if (s[i][j + 1] == 1 && s[i][j + 2] == 1 && s[i][j + 3] == 1) {
						if (s[i][j - 1] == 0 && j > 0) {
							play_chess2(s, n, i, (j - 1));
							return ;
						}
						if (s[i][j + 4] == 0 && j < 6) {
							play_chess2(s, n, i, (j + 4));
							return ;
						}
					}
				}
			}
		}
	}

	for (j = 0; j < 10; j++) {
		for (i = 0; i < 10; i++) {
			if (s[i][j] == 1 && s[i + 1][j] == 1) {
				if (s[i + 2][j] == 0 && i < 8) {
					play_chess2(s, n, (i + 2),  j);
					return ;
				}
				if (s[i - 1][j] == 0 && i > 0) {
					play_chess2(s, n, (i - 1),  j);
					return ;
				}
			}
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (s[i][j] == 1) {
				if (j < 9 && s[i][j + 1] == 0) {
					play_chess2(s, n, i, (j + 1));
					return ;
				}
				if (i < 9 && j < 9 && s[i + 1][j + 1] == 0) {
					play_chess2(s, n, (i + 1), (j + 1));
					return ;
				}
				if (i < 9 && s[i + 1][j] == 0) {
					play_chess2(s, n, (i + 1), j);
					return ;
				}
				if (i < 9 && j > 0 && s[i + 1][j - 1] == 0) {
					play_chess2(s, n, (i + 1), (j - 1));
					return ;
				}	
				if (j > 0 && s[i][j - 1] == 0) {
					play_chess2(s, n, i, (j - 1));
					return ;
				}
				if (i > 0 && j > 0 && s[i - 1][j - 1] == 0) {
					play_chess2(s, n, (i - 1), (j - 1));
					return ;
				}
				if (i > 0 && s[i - 1][j] == 0) {
					play_chess2(s, n, (i - 1), j);
					return ;
				}
				if (i > 0 && j < 9 && s[i - 1][j + 1] == 0) {
					play_chess2(s, n, (i - 1), (j + 1));
					return ;
				}
			}
		}
	}
}

void play_chess2(int s[][10], int n, int i, int j)
{
	if (i > 9 || i < 0 || j < 0 || j > 9) {
		printf("%d %d is not permitted! please reonput.\n", i, j);
		play_chess(s,n);	
	}
	if (s[i][j] != 0) {
		printf("%d %d is not permitted! please reonput.\n", i, j);
		play_chess(s, n);
	}
	else {
		s[i][j] = n;
		chessboard(s);
	}
}
