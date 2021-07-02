#ifndef STRUCTPRODUTO_H
#define STRUCTPRODUTO_H
#include "pilhas.h"
#include "funcoes.h"
struct Produto{
    int codigo;
    int pilha;
    int prateleira;


};

struct Cliente{

    int codigoProduto1=0;
    int codigoProduto2=0;
    int codigoProduto3=0;
};


#include <iostream>
using namespace std;

ostream& operator<< (ostream& os, TPilha<Produto> produto){
    while(produto.topo!=NULL){
    os << "Codigo "<< produto.topo->dado.codigo <<endl;
    produto.topo = produto.topo->proximo;

    }
    return os;

}


#endif // STRUCTPRODUTO_H
