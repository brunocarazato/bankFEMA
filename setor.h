#include <iostream>
#include <cstring>
using namespace std;

class Setor{
    private:
        int codigo;
        string nome;
        int qtdMaxFun;
        int qtdFun;
    public:
        void setCodigo(int codigo);
        int getCodigo();

        void setNome(string nome);
        string getNome();

        void setQtdMaxFun(int qtd);
        int getQtdMaxFun();
        
        void incrementaFun();
        int getQtdFun();
        bool temVaga();
        Setor();
};

void Setor::setCodigo(int codigo){
    this->codigo = codigo;
}

int Setor::getCodigo(){
    return this->codigo;
}

void Setor::setNome(string nome){
    this->nome = nome;
}

string Setor::getNome(){
    return this->nome;
}

void Setor::setQtdMaxFun(int qtd){
    this->qtdMaxFun = qtd;
}

int Setor::getQtdMaxFun(){
    return this->qtdMaxFun;
}

void Setor::incrementaFun(){
    this->qtdFun = this->qtdFun+1;
}

int Setor::getQtdFun(){
    return this->qtdFun;
}

bool Setor::temVaga(){
    if(this->qtdFun < this->qtdMaxFun){
        return true;
    }
    return false;
}

Setor::Setor():qtdFun(0){}