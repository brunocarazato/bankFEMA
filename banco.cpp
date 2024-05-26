#include "funcionario.h"
#include "setor.h"
#include "conta.h"
#include "cliente.h"

int numeroConta = 1;

void contratarFuncionarios(Setor setor[], Funcionario funcionario[]);
void promoverFuncionarios(Setor setor[], Funcionario funcionario[]);

int main(){

    //1º PARTE - SETOR E FUNCIONARIO

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



    ///2 PARTE - CONTA E CLIENTE

    
    Conta novaConta1(numeroConta);  //instanciando um objeto do tipo Conta
    numeroConta++;                  //incrementando a variável global para controlar os números de conta
    Conta novaConta2(numeroConta);  //instanciando outro objeto do tipo Conta
    numeroConta++;                  //incrementando nvoamente a variável global para controlar os números de conta

    Cliente cliente1(novaConta1.getNumero()); //instanciando um objeto do tipo Cliente já passando no construtor o número do objeto novaConta1 (utilizei o método público getNumero da conta para acessar o atributo privado numero)
    cliente1.cadastrar();                     //chamando a função que solicita as informações do cliente1
    Cliente cliente2(novaConta2.getNumero()); //instanciando um outro objeto do tipo Cliente já passando no construtor o número do objeto novaConta2 (utilizei o método público getNumero da conta para acessar o atributo privado numero)
    cliente2.cadastrar();                     //chamando a função que solicita as informações do cliente2


    /* Até aqui temos o seguinte cenário:
        Conta1 -> Cliente1
        Conta2 -> Cliente2

        Ou seja, um cliente não pode obter extrato nem sacar valores da conta de outro cliente. Pode apenas depositar.
        Além disso, existem algumas restrições para saque, como por exemplo:
        - Só posso sacar se eu tiver saldo em minha conta
        - Só posso sacar valores múltiplos de 15, Ex: 150.00
    */

    // Testando um cenário válido
    novaConta1.obterExtrato(cliente1.getContaBancaria()); //pedindo um extrato - a conta vai estar com saldo zerada
    novaConta1.depositar(150.00);                         //depositando 150.00
    novaConta1.obterExtrato(cliente1.getContaBancaria()); //pedindo um extrato - a conta vai estar com saldo 150.00
    novaConta1.sacar(cliente1.getContaBancaria(), 30.00); //pedindo um extrato - tentando sacar um valor valido
    novaConta1.sacar(cliente1.getContaBancaria(), 150.00); //pedindo um extrato - tentando sacar um valor invalido por saldo
    novaConta1.sacar(cliente1.getContaBancaria(), 16.00); //pedindo um extrato - tentando sacar um valor invalido por não ser multiplo

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

