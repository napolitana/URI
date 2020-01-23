#include <iostream>
#include <string>
#include <locale.h>
#include <stdio.h>

using namespace std;

bool validarLetras(string palavra)
{
	int i = 0, cont = 0;
	
	for (i = 0; i < palavra.length(); i++)
	{
		if(isalpha(palavra[i]))
		{
			cont++;
		}
	}
	if(cont == palavra.length() && palavra.length()!=0)
	{
		return true;
	}
	else return false;
}

bool validarPalavraPonto(string palavra)
{
	int contPonto = 0, i = 0, contLetras = 0;

	//Conta a quantidade de na palavra
	for (i = 0; i < palavra.length(); i++)
	{
		if (palavra[i] == '.')
		{
			contPonto++;
		}
		if(isalpha(palavra[i])){
			contLetras++;
		}
	}
	//Se houver apenas um ponto e ele estiver no final da palavra, a palavra é válida
	if(contPonto == 1 && palavra[i - 1] == '.' && palavra.length() > 1 && contLetras==palavra.length()-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



int contaCaracteres(string palavra)
{
	int i, cont = 0;;
	for (i = 0; i < palavra.length(); i++)
	{
		if(palavra[i] != '.')
		{
			cont++;
		}
	}
	return cont;
}

int main ()
{
	//setlocale(LC_ALL, "");
	string entrada, palavra, aux;
	int i = 0, cont = 0, pos = 0, qtd = 0, qtdLetras = 0, comp = 0, tamanho=0;
	bool achou = false;

getline(cin, entrada); 
	do
	{	
		   	
		if(entrada != "\0")
		{
			while (!achou)
			{
				tamanho = entrada.length();
				for (i = 0; i < entrada.length(); i++)
				{
					if(entrada[i] != ' ')
					{
						cont++;
					}
					else
					{
						pos = i;
						break;
					}

				}

				if (entrada.length() - (cont) != 0)
				{
					if(entrada[0] == ' ')
					{
						aux = entrada.substr(pos - cont, cont + 1);
					}
					else
					{
						aux = entrada.substr(pos - cont, cont);						
					}

					if (validarPalavraPonto(aux) || validarLetras(aux))
					{
						//cout << aux << " é uma palavra valida"<<endl;
						qtdLetras += contaCaracteres(aux);
						qtd++;
					}
					
					//else cout <<aux << " é uma palavra invalida"<<endl;
					entrada = entrada.substr(pos+1, entrada.length() - (cont));
					//cout << "aux = " << aux <<endl;

				}
				else
				{
					aux = entrada;
					achou = true;

				}



				cont = 0;
				pos = 0;

			};
			achou = false;

			if ((validarPalavraPonto(aux) || validarLetras(aux)) && aux!="" )
			{
				qtdLetras += contaCaracteres(aux);
				qtd++;
			}
			

			if(qtd == 0)
			{
				comp = 0;
			}
			else
			{
				comp = qtdLetras / qtd;

			}
			if(comp <= 3)
			{
				cout << 250;
			}
			else if(comp >= 4 && comp <= 5)
			{
				cout << 500;
			}
			else
			{
				cout << 1000;
			}
			cout << endl;
			qtd = 0;
			qtdLetras = 0;

			fflush(stdin);
			

		}
getline(cin, entrada); 
	}
	while(entrada!="\0");

	return 0;
}