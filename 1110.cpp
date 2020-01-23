#include <iostream>

using namespace std;

struct celula
{
	int valor;
	celula *prox;
};

struct pilha
{
	celula *topo;
};

void criarPilha(pilha &p)
{
	p.topo = NULL;
}

bool pilhaVazia(pilha &p)
{
	if(p.topo == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(pilha &p, int valor)
{
	celula *nova = new celula;
	nova->valor = valor;
	nova->prox = p.topo;
	p.topo = nova;
}

void pop(pilha &p)
{
	if(pilhaVazia(p))
	{
		celula *aux = new celula;
		aux = p.topo;
		p.topo = p.topo->prox;
		delete aux;
	}
	else
	{
		cout << "Pilha vazia!";
	}
}

void insereNoFinal(pilha &p, int valor)
{
	celula *nova = new celula;
	nova->valor = valor;
	if(pilhaVazia(p))
	{
		p.topo = nova;
		nova->prox = NULL;
	}
	else
	{
		celula *aux = new celula;
		aux = p.topo;
		while (aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = nova;
		nova->prox = NULL;
	}
}

int contar(pilha &p)
{
	int cont = 0;
	celula *aux = new celula;
	aux = p.topo;
	while(aux)
	{
		cont++;
		aux = aux->prox;
	}
	return cont;
}


void imprimir(pilha &p)
{
	if (pilhaVazia(p))
	{
		cout << "Pilha vazia!";
	}
	else
	{
		celula *aux = new celula;
		aux = p.topo;
		while (aux->prox != NULL)
		{
			cout << aux->valor << ", ";
			aux = aux->prox;
		}
		cout << aux->valor;
		cout << endl;
	}
}

void esvaziarPilha(pilha &p)
{
	if(pilhaVazia(p) == false)
	{
		celula *aux = new celula;
		aux = p.topo;
		while (aux)
		{
			p.topo = p.topo->prox;
			delete aux;
			aux = p.topo;
		}
	}
}

void teste (pilha &p)
{
	pilha descart;
	criarPilha(descart);
	if (pilhaVazia(p) == false and contar(p) > 2)
	{
		while (contar(p) > 2)
		{
			celula *aux = new celula;
			aux = p.topo->prox;
			insereNoFinal(descart, p.topo->valor); //delete p.topo;
			p.topo = aux->prox;
			insereNoFinal(p, aux->valor);
			contar(p);
		}
		celula *aux = new celula;
		aux = p.topo->prox;
		insereNoFinal(descart, p.topo->valor); //delete p.topo;
		p.topo = aux;

		cout << "Discarded cards: ";
		imprimir(descart);
		esvaziarPilha(descart);
		cout << "Remaining card: ";
		imprimir(p);
		esvaziarPilha(p);
	}
}


int main()
{

	pilha pPrinc;
	criarPilha(pPrinc);
	int n, i;
	do
	{
		cin >> n;
		if(n >= 1 && n <= 50)
		{
			for (i = 0; i <= n - 1; i++)
			{
				insereNoFinal(pPrinc, i + 1);
			}
			teste(pPrinc);
		}
		else
		{
			return 0;
		}

	}
	while (n != 0);

	return 0;
}
