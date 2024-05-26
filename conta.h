#include <iostream>
#include <cstring>
using namespace std;


class Conta{
    private:
        int numero;
        float saldo;
        bool estado;
        void setSaldo(float saldo);
    public:
        int getNumero();
        void setNumero(int numero);
        float getSaldo();
        bool getEstado();
        void setEstado(bool novoEstado);
        Conta(int numeroConta);
        void obterExtrato(int numeroConta);
        void sacar(int numeroConta, float valor);
        void depositar(float valor);
};

void Conta::depositar(float valor){
    this->saldo = this->saldo + valor;
    cout << "Depósito realizado" << endl;
}

void Conta::obterExtrato(int numeroConta){
    if (this->numero == numeroConta){
        cout << "O saldo é de R$: " << this->saldo << endl;
    }else{
        cout << "Operação inválida" << endl;
    }
}
void Conta::sacar(int numeroConta, float valor){
    if (this->numero == numeroConta){
        if(this->saldo > 0 && this->saldo >= valor){
            if((int)valor % 15 == 0){
                this->saldo = this->saldo - valor;
                cout << "Operação realizada. " << endl;
                cout << "Novo saldo R$:  " << this->saldo <<endl;
            }else{
                cout << "Valor não é multiplo de 15" << endl;
            }
        }else{
            cout << "Operação não pode ser realizada. Saldo insuficiente."<<endl;
        }
    }else{
        cout << "Operação inválida";
    }
}

Conta::Conta(int numeroConta){
    this->numero = numeroConta;
    this->saldo = 0;
    this->setEstado(true);
}

int Conta::getNumero(){
    return this->numero;
}

void Conta::setNumero(int numero){
    this->numero = numero;
}

float Conta::getSaldo(){
    return this->saldo;
}

void Conta::setSaldo(float saldo){
    this->saldo = saldo;
}

bool Conta::getEstado(){
    return this->estado;
}

void Conta::setEstado(bool novoEstado){
    this->estado = novoEstado;
}