#include <iostream>
#include <cstring>

using namespace std;

class Funcionario{

    private:
        string nome;
        long int cpf;
        string cargo;
        int setor;
        float experiencia;
    public:
        string getNome();
        void setNome(string nome);

        long int getCpf();
        void setCpf(long int cpf);

        string getCargo();
        void setCargo(string cargo);

        int getSetor();
        void setSetor(int setor);

        float getExperiencia();
        void setExperiencia(float exp);

        Funcionario();
        void contratar(int setor);
        bool promover();

};

    string Funcionario::getNome(){
        return this->nome;
    }

    void Funcionario::setNome(string nome){
        this->nome = nome;
    }

    long int Funcionario::getCpf(){
        return this->cpf;
    }

    void Funcionario::setCpf(long int cpf){
        this->cpf = cpf;
    }

    string Funcionario::getCargo(){
        return this->cargo;
    }

    void Funcionario::setCargo(string cargo){
        this->cargo = cargo;
    }

    int Funcionario::getSetor(){
        return this->setor;
    }

    void Funcionario::setSetor(int setor){
        this->setor = setor;
    }

    float Funcionario::getExperiencia(){
        return this->experiencia;
    }

    void Funcionario::setExperiencia(float exp){
        this->experiencia = exp;
    }

    Funcionario::Funcionario(){
        this->cargo = "Operador de caixa";
    }
    
    void Funcionario::contratar(int setor){
        string nome;
        long int cpf;
        string cargo;
        float experiencia;
        cout << "\n ---------Iniciando o processo de contratação---------" <<endl;
        cout << "Informe o nome: ";
        cin >> nome;
        cout << "Informe o cpf: ";
        cin >> cpf;
        cout << "Informe a exp em anos (ex: 1.5): ";
        cin >> experiencia;

        this->setNome(nome);
        this->setCpf(cpf);
        this->setSetor(setor);
        this->setExperiencia(experiencia);
    }

    bool Funcionario::promover(){
        if(this->getExperiencia() < 2){ //ele não pode ser promovido pois não tem tempo de exp suficiente
            return false;
        }else if(this->getExperiencia() >= 2 && this->getExperiencia() < 10){
            this->setCargo("Gerente de conta");
            return true;
        }else{
            this->setCargo("Gerente de agência");
            return true;
        }
    }

