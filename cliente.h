#include <iostream>
#include <cstring>
using namespace std;


class Cliente{
    private:
        string nome;
        long int cpf;
        string profissao;
        int contaBancaria;
    public:
        void setNome(string nome);
        string getNome();
        void setCpf(long int cpf);
        long int getCpf();
        void setProfissao(string profissao);
        string getProfissao();
        void setContaBancaria(int contaBancaria);
        int getContaBancaria();
        Cliente(int conta);
        void cadastrar();
};
int Cliente::getContaBancaria(){
    return this->contaBancaria;
}


Cliente::Cliente(int conta){
    this->contaBancaria = conta;
}

void Cliente::cadastrar(){
    string nome;
    long int cpf;
    string profissao;
    cout << "\n ---------Iniciando o processo de cadastro de cliente ---------" <<endl;
    cout << "Informe o nome: ";
    cin >> nome;
    cout << "Informe o cpf: ";
    cin >> cpf;
    cout << "Informe a profissão: ";
    cin >> profissao;
    this->setNome(nome);
    this->setCpf(cpf);
    this->setProfissao(profissao);

}

void Cliente::setNome(string nome){
    this->nome = nome;
}

void Cliente::setCpf(long int cpf){
    this->cpf = cpf;
}

void Cliente::setProfissao(string profissao){
    this->profissao = profissao;
}


string Cliente::getNome(){
    return this->nome;
}

long int Cliente::getCpf(){
    return this->cpf;
}

string Cliente::getProfissao(){
    return this->profissao;
}

void Cliente::setContaBancaria(int contaBancaria){
    this->contaBancaria = contaBancaria;
}