#include "funcionario.h"
#include "setor.h"
#include "conta.h"
#include "cliente.h"

int numeroConta = 1;

void contratarFuncionarios(Setor setor[], Funcionario funcionario[]);
void promoverFuncionarios(Setor setor[], Funcionario funcionario[]);

int main(){

    //instanciando os objetos
    Setor set[2];
    Funcionario fun[3];
    
    //inicializando valores dos objetos de setores
    set[0].setCodigo(3321);
    set[0].setNome("Pessoa Física");
    set[0].setQtdMaxFun(1);

    set[1].setCodigo(4442);
    set[1].setNome("Pessoa Jurídica");
    set[1].setQtdMaxFun(2);

    //chamando as funções para contratar e promover
    contratarFuncionarios(set, fun);
    promoverFuncionarios(set, fun);

    //abertura das contas e cadastro dos clientes
    Conta conta1(numeroConta);
    numeroConta++;
    Conta conta2(numeroConta);
    numeroConta++;

    //cadastro dos clientes
    Cliente cliente1(conta1.getNumero());
    Cliente cliente2(conta2.getNumero());
    cliente1.cadastrar();
    cliente2.cadastrar();

    //depositando valores
    conta1.depositar(200.00);
    conta2.depositar(150.00);

    //sacando valores
    conta1.sacar(100.00, cliente1.getContaBancaria());
    conta2.sacar(100.00, cliente2.getContaBancaria());

    //solicitando extratos
    conta1.extratificar(cliente1.getContaBancaria());
    conta2.extratificar(cliente2.getContaBancaria());

    //tentando sacar valores invalidos
    conta1.sacar(120.00, cliente1.getContaBancaria());
    conta2.sacar(60.00, cliente2.getContaBancaria());
    
    return 0;
}

void contratarFuncionarios(Setor set[], Funcionario fun[]){
    //contratando com base na disponibilidade de vagas dos setores
    for(int i=0; i<3; i++){
        if(set[0].temVaga()){
            fun[i].contratar(set[0].getCodigo());
            cout << "\nContratado no setor " << set[0].getNome() << endl;
            set[0].incrementaFun();
        } else if(set[1].temVaga()){
            fun[i].contratar(set[1].getCodigo());
            cout << "\nContratado no setor " << set[1].getNome() << endl;
            set[1].incrementaFun();
        } else {
            cout << "Desculpe, não há vagas";
        }
    }
}

void promoverFuncionarios(Setor set[], Funcionario fun[]){
    //tentando promover os funcionários
    bool foiPromovido = false;
    for(int i=0; i<3; i++){
        cout << "\n--------Iniciando processo de promoção--------";
        foiPromovido = fun[i].promover();
        if(foiPromovido == true){
            cout << "\nSucesso! Agora o cargo do " << fun[i].getNome() << " é: " << fun[i].getCargo() << endl;
        }else{
            cout << "\nNão foi possível :(" << endl;
            cout << "O funcionário " << fun[i].getNome() << " não possui tempo de experiência suficiente" << endl;
        }
    }
}

