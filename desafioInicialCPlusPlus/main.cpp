#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;
vector<string> alunosMatriculados;

void adicionar_aluno(string aluno) {
    alunosMatriculados.push_back(aluno);

}

void listarAlunos() {
    for (int i = 0; i < alunosMatriculados.size(); i++) {
        cout << i + 1 << " - " << alunosMatriculados[i] << endl;

    }

}

void listarOpcoes() {
    cout << "1 - Adicionar Aluno: " << endl;
    cout << "2 - Remover Aluno: " << endl;
    cout << "3 - Adicionar nota: " << endl;
    cout << "4 - Visualizar alunos: " << endl;
    cout << "5 - sair: " << endl;
}

int main() {
    map<string, double> notaAlunos;


    cout << "Bem-vindo ao Sistema do Aluno!" << endl;
    int digitar_operacao = 0;
    while (digitar_operacao != 5) {
        cout << "Digite a operacao do aluno: " << endl;
        listarOpcoes();

        cin >> digitar_operacao;

        switch (digitar_operacao) {
            case 1: {
                string nomeAluno;
                cout << "Digite o nome do aluno: ";
                cin >> nomeAluno;
                adicionar_aluno(nomeAluno);
                cout << "Aluno adicionado" << endl;
                break;
            }
            case 2: {
                listarAlunos();
                int alunoDeletar;

                cout << "Digite o numero do aluno que deseja deletar: ";
                cin >> alunoDeletar;


                if (alunoDeletar >= 0 && alunoDeletar <= alunosMatriculados.size()) {
                    alunosMatriculados.erase(alunosMatriculados.begin() + alunoDeletar - 1);
                    cout << "Aluno deletado" << endl;
                }
                else {
                    cout << "Erro!" << endl;
                }

                break;
            }
            case 3: {
                listarAlunos();
                cout << "Digite o numero do aluno que deseja adicionar uma nota: " << endl;

                int alunoAdicionarNota;
                cin >> alunoAdicionarNota;

                cout << "Digite a nota do aluno: "<< alunosMatriculados[alunoAdicionarNota - 1] << endl;
                double notaAluno;
                cin >> notaAluno;

                notaAlunos[alunosMatriculados[alunoAdicionarNota - 1]] = notaAluno;

                cout << "Nota adicionada" << endl;
                break;
            }
            case 4: {
                listarAlunos();
                cout << "Deseja ver a nota de um aluno (s/n) " << endl;
                string verNota;
                cin >> verNota;
                if (verNota == "s") {
                    cout << "Digite o numero do aluno que deseja ver a nota: ";
                    int verNotaAluno;
                    cin >> verNotaAluno;
                    cout << "Nota do aluno: " << alunosMatriculados[verNotaAluno] << "-" << notaAlunos[alunosMatriculados[verNotaAluno - 1]] << endl;
                }
                break;
            }
                case 5:
                    cout << "Sair!" << endl;
                    break;
            default: {
                cout << "Opcao invalida!" << endl;
            }

        }




    }
    return 0;
}
