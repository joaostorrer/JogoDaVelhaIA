// C++ program to find the next optimal move for
// a player
#include <stdlib.h>
#include <conio.h>
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

#define ESC 27

char topLeft = (char)201;
char topRight = (char)187;
char bottomLeft = (char)200;
char bottomRight = (char)188;
char horBar = (char)205;
char vertBar = (char)186;
char midUp = (char)203;
char midLeft = (char)204;
char midRight = (char)185;
char midDown = (char)202;
char mid = (char)206;

int jogador = 1;

char board[3][3] =
{
	{ '_', '_', '_' },
	{ '_', '_', '_' },
	{ '_', '_', '_' }
};

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';

void printaTab()
{
	system("cls");
	cout << topLeft << horBar << horBar << horBar << midUp << horBar << horBar << horBar << midUp << horBar << horBar << horBar << topRight << endl;
	cout << vertBar << " " << board[0][0] << " " << vertBar << " " << board[0][1] << " " << vertBar << " " << board[0][2] << " " << vertBar << endl;
	cout << midLeft << horBar << horBar << horBar << mid << horBar << horBar << horBar << mid << horBar << horBar << horBar << midRight << endl;
	cout << vertBar << " " << board[1][0] << " " << vertBar << " " << board[1][1] << " " << vertBar << " " << board[1][2] << " " << vertBar << endl;
	cout << midLeft << horBar << horBar << horBar << mid << horBar << horBar << horBar << mid << horBar << horBar << horBar << midRight << endl;
	cout << vertBar << " " << board[2][0] << " " << vertBar << " " << board[2][1] << " " << vertBar << " " << board[2][2] << " " << vertBar << endl;
	cout << bottomLeft << horBar << horBar << horBar << midDown << horBar << horBar << horBar << midDown << horBar << horBar << horBar << bottomRight << endl;
}

void limpaTab()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '_';
		}
	}
}

void printaMenu()
{
	cout << "          Jogo da Velha          " << endl << endl;
	cout << "Menu: " << endl;
	cout << "1 - Jogar contra adversario" << endl;
	cout << "2 - Jogar contra IA" << endl;
}

void realizaJogada(int linha, int coluna, int jogador)
{
	if (jogador == 1)
	{
		board[linha][coluna] = 'x';
	}
	else
	{
		if (jogador == 2)
		{
			board[linha][coluna] = 'o';
		}
	}
}

bool verificaJogada(int linha, int coluna)
{
	if (board[linha][coluna] == '_')
		return 1;
	else
		return 0;
}

void finalizaJogo(int jogador)
{
	cout << "Parabens jogador " << jogador << ", voce ganhou o jogo!" << endl;
}

void empate()
{
	cout << "Jogo deu empate!" << endl;
}

bool reiniciaJogo()
{
	char key;
	cout << "Deseja reiniciar o jogo ? (s/n)" << endl;
	key = getch();
	if (key == 's')
		return 1;
	else
	{
		if (key == 'n')
			return 0;
		else
		{
			cout << "Utilize as teclas s/n para informar sua decisao!" << endl;
			reiniciaJogo();
		}
	}
}

void msgErro()
{
	cout << "Posicao nao valida!" << endl;
	cout << "Utilize as teclas 1 a 9 do teclado para jogar!" << endl;
}

int trocaJogador(int jogador)
{
	if (jogador == 1)
		jogador = 2;
	else
	{
		if (jogador == 2)
			jogador = 1;
	}
	return jogador;
}

Move verificaPosicao(int posicao)
{
	Move posicaoJogada;
	switch (posicao)
	{
		case 0:
			posicaoJogada.row = 2;
			posicaoJogada.col = 0;
			return posicaoJogada;
			break;
		case 1:
			posicaoJogada.row = 2;
			posicaoJogada.col = 1;
			return posicaoJogada;
			break;
		case 2:
			posicaoJogada.row = 2;
			posicaoJogada.col = 2;
			return posicaoJogada;
			break;
		case 3:
			posicaoJogada.row = 1;
			posicaoJogada.col = 0;
			return posicaoJogada;
			break;
		case 4:
			posicaoJogada.row = 1;
			posicaoJogada.col = 1;
			return posicaoJogada;
			break;
		case 5:
			posicaoJogada.row = 1;
			posicaoJogada.col = 2;
			return posicaoJogada;
			break;
		case 6:
			posicaoJogada.row = 0;
			posicaoJogada.col = 0;
			return posicaoJogada;
			break;
		case 7:
			posicaoJogada.row = 0;
			posicaoJogada.col = 1;
			return posicaoJogada;
			break;
		case 8:
			posicaoJogada.row = 0;
			posicaoJogada.col = 2;
			return posicaoJogada;
			break;
		default:
			break;
	}
}

char procedReiniciaJogo()
{
	char key;
	jogador = trocaJogador(jogador);
	system("cls");
	limpaTab();
	printaMenu();
	key = getch();
	if (key == '1')
	{
		printaTab();
		cout << "Jogador da vez: Jogador " << jogador << endl << endl;
		key = getch();
		return key;
	}
	else
	{
		printaTab();
		cout << "Jogador da vez: Jogador " << jogador << endl << endl;
		if (jogador == 2)
		{
			key = getch();
			return key;
		}
	}
}

void escolhaJogadorIniciar()
{
	char key;
	cout << "Escolha qual jogador ira comecar a partida (1 = IA 2 = Voce): ";
	key = getch();
	switch (key)
	{
		case '1':
			jogador = 1;
			break;
		case '2':
			jogador = 2;
			break;
		default:
			cout << endl << "Informe um numero (1 ou 2)!" << endl;
			escolhaJogadorIniciar();
	}
}

// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i<3; i++)
	for (int j = 0; j<3; j++)
	if (board[i][j] == '_')
		return true;
	return false;
}

// This is the evaluation function as discussed
// in the previous article ( http://goo.gl/sJgv68 )
int evaluate(char b[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++)
	{
		if (b[row][0] == b[row][1] &&
			b[row][1] == b[row][2])
		{
			if (b[row][0] == player)
				return +10;
			else if (b[row][0] == opponent)
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		if (b[0][col] == b[1][col] &&
			b[1][col] == b[2][col])
		{
			if (b[0][col] == player)
				return +10;

			else if (b[0][col] == opponent)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == player)
			return +10;
		else if (b[0][0] == opponent)
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == player)
			return +10;
		else if (b[0][2] == opponent)
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her
	// evaluated score
	if (score == -10)
		return score;

	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(board) == false)
		return 0;

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == '_')
				{
					// Make the move
					board[i][j] = player;

					// Call minimax recursively and choose
					// the maximum value
					best = max(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}

	// If this minimizer's move
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == '_')
				{
					// Make the move
					board[i][j] = opponent;

					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}

// This will return the best possible move for the player
Move findBestMove(char board[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	// Traverse all cells, evalutae minimax function for
	// all empty cells. And return the cell with optimal
	// value.
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			// Check if celll is empty
			if (board[i][j] == '_')
			{
				// Make the move
				board[i][j] = player;

				// compute evaluation function for this
				// move.
				int moveVal = minimax(board, 0, false);

				// Undo the move
				board[i][j] = '_';

				// If the value of the current move is
				// more than the best value, then update
				// best/
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	//printf("The value of the best Move is : %dnn",
	//	bestVal);

	return bestMove;
}

// Driver code
int main()
{
	char key;
	int posicao = 0;
	printaMenu();

	key = getch();

	switch (key)
	{
		case '1':
			printaTab();
			cout << "Jogador da vez: Jogador " << jogador << endl << endl;
			key = getch();
			break;
		case '2':
			escolhaJogadorIniciar();
			printaTab();
			cout << "Jogador da vez: Jogador " << jogador << endl << endl;
			if (jogador == 2)
				key = getch();
			while ((key != ESC) && ((evaluate(board) != 10) || evaluate(board) != -10) && (isMovesLeft(board)))
			{
				if (jogador == 1)
				{
					Move bestMove = findBestMove(board);
					realizaJogada(bestMove.row, bestMove.col, jogador);
					if ((evaluate(board) == 10) || (evaluate(board) == -10))
					{
						printaTab();
						finalizaJogo(jogador);
						if (reiniciaJogo())
							key = procedReiniciaJogo();
						else
						{
							system("PAUSE");
							return 0;
						}
					}
					else
					{
						if (!isMovesLeft(board))
						{
							printaTab();
							empate();
							if (reiniciaJogo())
								key = procedReiniciaJogo();
							else
							{
								system("PAUSE");
								return 0;
							}
						}
						else
						{
							jogador = trocaJogador(jogador);
							printaTab();
							cout << "Jogador da vez: Jogador " << jogador << endl << endl;
							key = getch();
						}
					}
				}
				else
				{
					if ((key < 49) || (key > 57))
					{
						msgErro();
						key = getch();
					}
					else
					{
						posicao = key - 49;
						if (verificaJogada(verificaPosicao(posicao).row, verificaPosicao(posicao).col))
						{
							realizaJogada(verificaPosicao(posicao).row, verificaPosicao(posicao).col, jogador);
							if ((evaluate(board) == 10) || (evaluate(board) == -10))
							{
								printaTab();
								finalizaJogo(jogador);
								if (reiniciaJogo())
									key = procedReiniciaJogo();
								else
								{
									system("PAUSE");
									return 0;
								}
							}
							else
							{
								if (!isMovesLeft(board))
								{
									printaTab();
									empate();
									if (reiniciaJogo())
										key = procedReiniciaJogo();
									else
									{
										system("PAUSE");
										return 0;
									}
								}
								else
								{
									jogador = trocaJogador(jogador);
									printaTab();
									cout << "Jogador da vez: Jogador " << jogador << endl << endl;
								}
							}
						}
						else
						{
							msgErro();
							key = getch();
						}
					}
				}
			}
			break;
		default:
			while (key != '1' && key != '2')
			{
				cout << "Escolha nao valida! Utilize apenas o numero 1 ou 2 para escolha" << endl;
				key = getch();
			}
			system("cls");
			printaMenu();
			key = getch();
	}

	//Move bestMove = findBestMove(board);

	//cout << "O melhor movimento eh: Linha = " << bestMove.row << " Coluna =  " << bestMove.col << endl;

	system("PAUSE");

	return 0;
}
