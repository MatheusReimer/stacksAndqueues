#ifndef FUNCOES_H
#define FUNCOES_H
#include <ctime>
#include <cstdlib>
#include "filas.h"
#include "pilhas.h"
#include "structProduto.h"
#include "generica.h"





int calculoRestoPrateleira(float medidaUserC){
    int colunasDePrateleiras = medidaUserC/5.5;

    float restoC =  medidaUserC - (colunasDePrateleiras *5.5);

    int espacosNaPrateleira = 0;
    if(restoC>1.8 && restoC<2.7){
        //incluir prateileira de 2 pilhas(espacos)
        espacosNaPrateleira = 2;
    }
    if(restoC>=2.7 && restoC<3.6){
        //incluir prateleira de 3 pilhas(espacos)
        espacosNaPrateleira =3;

    }
    if(restoC>=3.6 && restoC<4.5){
        //incluir prateleira de 4 pilhas(espacos)
        espacosNaPrateleira=4;

    }
    if(restoC>=4.5 && restoC<5.4){
        //incluir prateleira de 5 pilhas(espacos)
        espacosNaPrateleira = 5;


    }
    return espacosNaPrateleira;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








int calculoPrateleira(float medidaUserL, float medidaUserC){
    int prateleirasParalelas = medidaUserL/1.5;
    int colunasDePrateleiras = medidaUserC/5.5;
    if(calculoRestoPrateleira(medidaUserC)>0){
        colunasDePrateleiras ++;
    }

    int resultadoPrateleiras = colunasDePrateleiras * prateleirasParalelas;
    //cout<<"Prateleiras:   "<<resultadoPrateleiras<<endl;
    return resultadoPrateleiras;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculoEspaco(float medidaUserC){
    int resultadoEspaco = (medidaUserC/5.5);
    resultadoEspaco = resultadoEspaco * 6;
    int prateleiraAdicional = calculoRestoPrateleira(medidaUserC);
    resultadoEspaco= resultadoEspaco+ prateleiraAdicional;
    if(resultadoEspaco<=2){
        cout<<"Nao pode ser feito uma prateleira com menos de 2 espacos"<<endl;
        resultadoEspaco=0;
    }

    //cout<<"Espacos:   "<<resultadoEspaco<<endl;

    return resultadoEspaco;
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculoModulos(int medidaUserH){
    int resultadoModulos;
    if(medidaUserH>=3 && medidaUserH<=3.9){
        resultadoModulos=9;
    }
    else if(medidaUserH>3.9){
        resultadoModulos=12;
    }
    else{
        cout<<"Nao cabe nenhuma prateleira com essa altura"<<endl;
        resultadoModulos=0;
    }
    //cout<<"Modulos:   "<<resultadoModulos<<endl;
    return resultadoModulos;
}

int calculoModulos2(int medidaUserH){
    int resultadoModulos;
    if(medidaUserH>=3 && medidaUserH<=3.9){
        resultadoModulos=2;
    }
    else if(medidaUserH>3.9){
        resultadoModulos=3;
    }
    else{
        cout<<"Nao cabe nenhuma prateleira com essa altura"<<endl;
        resultadoModulos=0;
    }
    //cout<<"Modulos:   "<<resultadoModulos<<endl;
    return resultadoModulos;
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculoProdutos(int medidaUserL,int medidaUserC,int medidaUserH){

        //6 COLUNAS * QUANTIDADE DE PRODUTOS QUE PODEM SER COLOCADOS NA PILHA * QUANTIDADE DE PRATELEIRAS
       /// QUANTIDADE DE COLUNAS * QUANTIDADE DE ALTURA
        int produtos;
        int prateleirasParalelas = medidaUserL/1.5;

        produtos = calculoEspaco(medidaUserC)* calculoModulos(medidaUserH)* prateleirasParalelas ;
        //cout<<"Total de produtos:    "<<produtos<<endl;
        return produtos;


}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculoProdutos2(int medidaUserL,int medidaUserC,int medidaUserH){

        //6 COLUNAS * QUANTIDADE DE PRODUTOS QUE PODEM SER COLOCADOS NA PILHA * QUANTIDADE DE PRATELEIRAS
        int produtos=0;

        //cout<<"Total de produtos2:    "<<produtos<<endl;

        int prateleirasParalelas = medidaUserC/1.5;
        produtos = calculoEspaco(medidaUserL)* calculoModulos(medidaUserH)* prateleirasParalelas ;
        return produtos;

}












//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int comparaCalculos(int medidaUserL,int medidaUserC,int medidaUserH){
        if( calculoProdutos(medidaUserL,medidaUserC,medidaUserH)>calculoProdutos2(medidaUserL,medidaUserC,medidaUserH)){
            int produtoFinal = calculoProdutos(medidaUserL,medidaUserC,medidaUserH);
            cout<<"Total de produtos que podem ser armazenados:    "<<produtoFinal<<endl;
            return produtoFinal;
        }
       else{
            int produtoFinal = calculoProdutos2(medidaUserL,medidaUserC,medidaUserH);
            cout<<"Total de produtos que podem ser armazenados:    "<<produtoFinal<<endl;
            return produtoFinal;
        }

}









//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int criandoNumeroRandomico(int medidaUserL,int medidaUserC,int medidaUserH){

    //CRIANDO NUMERO RANDOMICO
    int cabemXprodutos = comparaCalculos(medidaUserL,medidaUserC,medidaUserH);
    int dezPorcento = cabemXprodutos * 0.10;
    int quinhentosPorcento = cabemXprodutos * 5;
    int diferenca = quinhentosPorcento-dezPorcento;
    srand(time(NULL));
    int produtosChegando=0;
    for(int j=0;j<100;j++){
     produtosChegando = rand() % diferenca + dezPorcento;
    }

    if(produtosChegando>cabemXprodutos){
        cout<<"ALERTA!, nao ha espaco no armazem para a quantidade de produtos que esta chegando"<<endl;
    }else{
        cout<<produtosChegando<<endl;
    }

    produtosChegando = 300;
    cout<<"Estao chegando "<<produtosChegando<<" produtos no caminhao"<<endl;
    if(produtosChegando>cabemXprodutos){
        cout<<"ALERTA!, nao ha espaco no armazem para a quantidade de produtos que esta chegando"<<endl;

    }
    return produtosChegando;
}












//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int regulandoTempo(int contadorTempo,int empilhadeira,int contadorProdutos){
    int contadorTempoEmMinutos = contadorTempo;


    while(contadorTempoEmMinutos>=300){
        empilhadeira++;
        contadorTempoEmMinutos = contadorTempoEmMinutos/empilhadeira;
    }



    cout<<contadorTempoEmMinutos<<" Minutos  "<< "para empilhar os "<<contadorProdutos<<" produtos utilizando "<<empilhadeira<<" empilhadeiras"<<endl;

}





void print2(TlistaGenerica<TPilha<Produto>,2000> lista){

    for (int i = 0; i< lista.quantidade;i++){
        cout<<"Pilha Numero: "<<i<<endl;
        cout<< lista.elementos[i].dado<<endl;
    }



}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TlistaGenerica<TPilha<Produto>,2000>  descarregar( int medidaUserL, int medidaUserC,int medidaUserH){
    int produtosChegando =criandoNumeroRandomico(medidaUserL,medidaUserC,medidaUserH);

    const int quantidadeDeEspacos = produtosChegando/calculoModulos(medidaUserH);
    cout<<"Serao necessarias "<<quantidadeDeEspacos<<" colunas para armazenar esta quantidade de produtos"<<endl;
    TlistaGenerica<TPilha<Produto>,2000> lista;
    inicializa_lista_generica(lista);
    //criando uma fila de pilhas
    TPilha<Produto> pilha;
    Produto teste;
    int contadorProdutos=0;
    int descobreModulo=0;
    int contadorTempo=0;
    int empilhadeira=0;
    int contadorDePilhas=0;
    descobreModulo = calculoModulos(medidaUserH);
    int descobreModulo2= calculoModulos2(medidaUserH);
    for(int i=0;i<quantidadeDeEspacos;i++){

        for(int j=0;j<descobreModulo2;j++){
            startP(pilha);
            teste.pilha = contadorDePilhas;
            if(j==0){
                for(int k=0;k<5;k++){

                contadorProdutos++;
                teste.codigo=contadorProdutos;
                push(pilha,teste);
                contadorTempo=contadorTempo+11;
                }
            }
            if(j==1){
                for(int k=0;k<4;k++){

                contadorProdutos++;
                teste.codigo=contadorProdutos;
                push(pilha,teste);
                contadorTempo=contadorTempo+12;

                }
            }

            if(j==2){
                for(int k=0;k<3;k++){

                contadorProdutos++;
                teste.codigo=contadorProdutos;
                push(pilha,teste);
                contadorTempo=contadorTempo+13;
                }
            }
            contadorDePilhas++;
            inserir_fim_lista_generica(lista,pilha);

            }



            }

            regulandoTempo(contadorTempo,empilhadeira,contadorProdutos);
            print2(lista);




    return lista;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int funcaoDeRetirada(TlistaGenerica<TPilha<Produto>,2000> lista,int valorDoCodigo ){
    //RODANDO A LISTA DE PILHAS E CADA PILHA INDIVIDUALMENTE


    for(int i=0;i<lista.quantidade;i++){

        while(lista.elementos[i].dado.topo !=NULL){
            if(lista.elementos[i].dado.topo->dado.codigo==valorDoCodigo ){
                cout<<"O Elemento de codigo  '"<< lista.elementos[i].dado.topo->dado.codigo<<"'  se encontra na pilha "<<lista.elementos[i].dado.topo->dado.pilha<<endl;
                //RETORNANDO EM QUE PILHA DA LISTA ELE ENCONTROU O ELEMENTO
                return i;




            }
            lista.elementos[i].dado.topo= lista.elementos[i].dado.topo->proximo;
        }
    }

}

int checandoQtdeElementos(TlistaGenerica<TPilha<Produto>,2000> lista,int valorDoCodigo ){
    //RODANDO A LISTA DE PILHAS E CADA PILHA INDIVIDUALMENTE

    ///A IDEIA É CONTAR QUANTOS ELEMENTOS TEM NA PILHA E PASSAR PARA A FUNCAO CARREGAR, LÁ CHECAR IF==3,IF==4,IF==5
    for(int i=0;i<lista.quantidade;i++){
        int somadorTempo=0;
        while(lista.elementos[i].dado.topo !=NULL){
            if(lista.elementos[i].dado.topo->dado.codigo==valorDoCodigo ){
                
                somadorTempo++;


                //RETORNANDO EM QUE PILHA DA LISTA ELE ENCONTROU O ELEMENTO

            }
            somadorTempo++;
            lista.elementos[i].dado.topo= lista.elementos[i].dado.topo->proximo;
        }
    }

}



void carregar(TlistaGenerica<TPilha<Produto>,2000>& lista ,  int medidaUserL, int medidaUserC,int medidaUserH){
    //CRIANDO CLIENTE PARA TESTE
    TFila<Cliente> clientes;
    startF(clientes);
    int codigo = 30;
    int codigo2= 7;
    int codigo3 = 300;
    Cliente numero1;
    numero1.codigoProduto1=codigo;
    numero1.codigoProduto2=codigo2;
    numero1.codigoProduto3=codigo3;
    //CLIENTE COLOCADO NA FILA
    QueueFila(clientes,numero1);


    int resultadoDoSearch1 = funcaoDeRetirada(lista,codigo);
    int resultadoDoSearch2=  funcaoDeRetirada(lista,codigo2);
    int resultadoDoSearch3 = funcaoDeRetirada(lista,codigo3);
    int tempoCliente = checandoQtdeElementos(lista,codigo)+checandoQtdeElementos(lista,codigo2)+checandoQtdeElementos(lista,codigo3);
    cout<<checandoQtdeElementos(lista,codigo)<<endl;
    cout<<checandoQtdeElementos(lista,codigo2)<<endl;
    cout<<checandoQtdeElementos(lista,codigo3)<<endl;


    cout<<"O tempo para a entrega do produto ao cliente sera de:  "<<tempoCliente<<" minutos"<<endl;
    //POP
    if(lista.quantidade<2){
        cout<<"A Pilha nao pode ter menos de 2 elementos"<<endl;
    }
   //ANULANDO O ULTIMO DA PILHA(POP)
    lista.elementos[resultadoDoSearch1].dado.topo = lista.elementos[resultadoDoSearch1].dado.topo->proximo;
    lista.elementos[resultadoDoSearch2].dado.topo = lista.elementos[resultadoDoSearch2].dado.topo->proximo;
    lista.elementos[resultadoDoSearch3].dado.topo = lista.elementos[resultadoDoSearch3].dado.topo->proximo;
    DeQueue(clientes);

}

















#endif // FUNCOES_H
