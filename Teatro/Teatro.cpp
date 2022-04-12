#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;



#define LIN 15
#define COL 40
int quantidadeVIP;
int quantidadePremiun;
int quantidadeComun;
int resposta;
int selecionarpoltrona;
int selecionarfileira;
int selecionarlugar;
int preco;


void mapaSala(int** x) {
	for (int C = 1; C < 15; C++)
	{
		for (int F = 1; F < 40; F++)
		{
			cout << setw(1) << (x[C][F] == 0 ? "." : "#") << "| ";
		}
	}
}
void reserva_de_lugares(int** x)
{
	mapaSala(x);

	cout << "\n\n Qual fileira deseja reservar?: ";
	cin >> selecionarfileira;
	cout << "\n\n Qual coluna deseja reservar?: ";
	cin >> selecionarlugar;
	if (selecionarfileira <= 5)
	{
		if (x[selecionarfileira][selecionarlugar] == 0)
		{
			x[selecionarfileira][selecionarlugar] = 1;
			cout << "\n\nAssento reservado\n\n";
			quantidadeVIP++;
			preco += 50;
		}

		else 
		{
			cout << "\n\nAssento indisponivel\n\n ";
		}
	}
	else {
		if (selecionarfileira >= 6 && selecionarfileira <= 10) {
			if (x[selecionarlugar][selecionarfileira] == 0)
			{
				x[selecionarlugar][selecionarfileira] = 1;
				cout << "Assento reservado\n\n";
				quantidadePremiun++;
				preco += 30;
			}
			else {
				cout << "\n\nAssento indisponivel\n\n ";

			}
		}
		else if (selecionarfileira >= 11 && selecionarfileira <= 15) {
			if (x[selecionarlugar][selecionarfileira] == 0)
			{
				x[selecionarlugar][selecionarfileira] = 1;
				cout << "\n\nAssento reservado\n\n";
				quantidadeComun++;
				preco += 15;
			}
			else {
				cout << "\n\nAssento indisponivel\n\n";

			}
		}
		else {
			cout << "\n\nEscolha indisponivel\n\n";
		}
	}


}



int main(int argc, char** argv)

{
	

	int i;
	int j;


	int** mat;

	// Inicialização de cada "linha" do aray
	mat = (int**)malloc(LIN * sizeof(int));

	for (i = 0; i < LIN; ++i) // Percorre as linhas
	{
		mat[i] = (int*)malloc(COL * sizeof(int)); // Inicialização de cada coluna
	}
	// Fim da declaração do array


	for (i = 0; i < LIN; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			mat[i][j] = 0;
		}
	}

	for (i = 0; i < LIN; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			cout << setw(1) << (mat[i][j] == 0 ? "." : "#") << "|";
		}
		cout << endl;
	}


	while (true) {

		cout << "\n0 - Finalizar programa\n1- Reservar poltrona\n2- Mapa de ocupacao\n3- Faturamento\n";
		cout << "Selecione uma das opcoes: ";
		cin >> resposta;

		switch (resposta)
		{
		case 0:
			return 0;
		case 1:
			cout << "=======================" << endl;
			reserva_de_lugares(mat);
			break;
		case 2:
			cout << " M A P A - D A - S A L A\n\n";
			mapaSala(mat);
			break;
		case 3:
			cout << "\n\nO preco total da compra eh: ";
			cout << preco; cout << " reais\n\n";

			break;

		}
	};



}
