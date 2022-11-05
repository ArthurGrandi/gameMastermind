#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int menu, dificuldade = 2, tentativas, num_Certo, posicao_num_Certo, comparacao, resposta, n1, n2, n3, n4, n5;
    bool n_Venceu = true, sair = false;

    srand(time(NULL));

    do{

        cout <<"\t ________________________"<<endl;
        cout <<"\t|                        |"<<endl;
        cout <<"\t|       S E N H A        |"<<endl;
        cout <<"\t|                        |"<<endl;
        cout <<"\t| 1 - Jogar              |"<<endl;
        cout <<"\t|                        |"<<endl;
        cout <<"\t| 2 - Dificuldade        |"<<endl;
        cout <<"\t|                        |"<<endl;
        cout <<"\t| 3 - Creditos           |"<<endl;
        cout <<"\t|                        |"<<endl;
        cout <<"\t| 4 - Sair               |"<<endl;
        cout <<"\t|________________________|"<<endl;

        cin >> menu;
        system("cls");

        switch (menu) {
        case 1:

            switch (dificuldade)//Definição de n° de tentativas
            {
            case 1:
                tentativas = 8;
                break;
            case 2:
                tentativas = 10;
                break;
            case 3:
                tentativas = 12;
                break;
            }
            //Gerção dos números aleatórios e checagem de não repetição
            n1 = rand() % 6 + 1;
            n2 = rand() % 6 + 1;while (n2 == n1){ n2 = rand() % 6 + 1; }
            n3 = rand() % 6 + 1;while (n3 == n1 || n3 == n2){ n3 = rand() % 6 + 1; }
            n4 = rand() % 6 + 1;while (n4 == n1 || n4 == n2 || n4 == n3){ n4 = rand() % 6 + 1; }
            n5 = rand() % 6 + 1;while (n5 == n1 || n5 == n2 || n5 == n3 || n5 == n4){ n5 = rand() % 6 + 1; }


            n_Venceu = true; //O jogo começa definindo que o jogador ainda não ganhou
            while (tentativas > 0 && n_Venceu) {//Se repete até a vitoria do usuario, ou o fim das tentativas
                //zera as variaveis
                num_Certo = 0;
                posicao_num_Certo = 0;
                for (comparacao = 0; comparacao < dificuldade + 2; comparacao++)//Laço para acertar a dificuldade e escolher os numeros certo.
                {
                    system("cls");
                    // cout <<n1<<n2<<n3<<n4<<n5<<endl;// Apenas para teste
                    cout <<"\t ________________________________________________________________________"<<endl;
                    cout <<"\t|                                                                        |"<<endl;
                    cout <<"\t| Tentativas Restantes: " << tentativas << "                                                |"<<endl;
                    cout <<"\t| Numeros certos: " << num_Certo << "                                                      |"<<endl;
                    cout <<"\t| Numeros certos nas posicoes certas: " << posicao_num_Certo <<"                                  |"<<endl;
                    cout <<"\t|________________________________________________________________________|"<<endl;
                    if (comparacao < dificuldade + 2)//Lê a tentativa quando o numero da repeticao for menor que o numero de numeros do jogo
                    {
                        cout << "\n\tVoce esta na tentativa " << comparacao + 1 << "/" << dificuldade + 2 << ": ";
                        cin >> resposta;
                    }
                    if (resposta > 0 && resposta < 7) {//Garante um número válido
                        switch (comparacao)//Utilizado para verificar se tem numero certo e se esta na posicao certa
                        {
                        case 0://verifica o primeiro numero
                            if (resposta == n1)
                            {
                                num_Certo++;
                                posicao_num_Certo++;
                            }
                            else if (resposta == n2 || resposta == n3 || resposta == n4 || resposta == n5)
                            {
                                num_Certo++;
                            }
                            break;
                        case 1:
                            if (resposta == n2)
                            {
                                num_Certo++;
                                posicao_num_Certo++;
                            }
                            else if (resposta == n1 || resposta == n3 || resposta == n4 || resposta == n5)
                            {
                                num_Certo++;
                            }
                            break;
                        case 2:
                            if (resposta == n3)
                            {
                                num_Certo++;
                                posicao_num_Certo++;
                            }
                            else if (resposta == n1 || resposta == n2 || resposta == n4 || resposta == n5)
                            {
                                num_Certo++;
                            }
                            break;
                        case 3:
                            if (resposta == n4)
                            {
                                num_Certo++;
                                posicao_num_Certo++;
                            }
                            else if (resposta == n1 || resposta == n2 || resposta == n3 || resposta == n5)
                            {
                                num_Certo++;
                            }
                            break;
                        case 4:
                            if (resposta == n5)
                            {
                                num_Certo++;
                                posicao_num_Certo++;
                            }
                            else if (resposta == n1 || resposta == n2 || resposta == n3 || resposta == n4)
                            {
                                num_Certo++;
                            }
                            break;
                        }
                    }
                    else {//Caso insira um número invalido, Não conta a tentativa
                        comparacao--;
                    }

                    if (posicao_num_Certo == dificuldade + 2)//Verifica se a quantidade de acertos de posicao é igual ao número de digitos para adivinhar
                    {
                        n_Venceu = false;//Se a condição acima for verdadeira. O bool fica falso, sinalizando vitória.
                    }
                }
                tentativas--;//Diminui o numero de tentativas restantes
                system("pause");
            }

            system("cls");
            if (n_Venceu)// Leitura do bool, e resultado da partida.
            {
                cout <<"\t _______________________________"<<endl;
                cout <<"\t|                               |"<<endl;
                cout <<"\t| Voce perdeu! Tente novamente! |"<<endl;
                cout <<"\t|_______________________________|"<<endl;
            }
            else
            {
                cout <<"\t ___________________________________"<<endl;
                cout <<"\t|                                   |"<<endl;
                cout <<"\t| Parabens! Voce desvendou a senha! |"<<endl;
                cout <<"\t|___________________________________|"<<endl;
            }
            cout << "O numero era: " << n1 << n2 << n3;//escreve apenas os numeros de acordo com a dificuldade
            if (dificuldade == 2)
            {
                cout << n4 << endl;
            }
            else if (dificuldade == 3)
            {
                cout << n4 << n5 << endl;
            }
            cout << "\n";

            system("pause");
            system("cls");
            break;


            break;
        case 2:

            do{
                cout <<"\t ________________________________________"<<endl;
                cout <<"\t|                                        |"<<endl;
                cout <<"\t| Dificuldade: " << dificuldade <<"                         |  "<<endl;
                cout <<"\t|                                        |"<<endl;
                cout <<"\t| 1 - Facil: 3 numeros e 8 tentativas    |"<<endl;
                cout <<"\t|                                        |"<<endl;
                cout <<"\t| 2 - Medio: 4 numeros e 10 tentativas   |"<<endl;
                cout <<"\t|                                        |"<<endl;
                cout <<"\t| 3 - Dificil: 5 numeros e 12 tentativas |"<<endl;
                cout <<"\t|                                        |"<<endl;
                cout <<"\t|     Escolha um valor entre 1 e 3!      |"<<endl;
                cout <<"\t|________________________________________|"<<endl;
                cout <<" "<<endl;
                cin >> dificuldade;
            }while(dificuldade <= 0 || dificuldade >= 4 );
            cout <<"\t ________________________________________"<<endl;
            cout <<"\t|                                        |"<<endl;
            cout <<"\t| Dificuldade alterada com sucesso!      |"<<endl;
            cout <<"\t|________________________________________|"<<endl;
            system("pause");
            system("cls");

            break;
        case 3:

            cout <<"\t _______________________________________________________________________________________"<<endl;
            cout <<"\t|                                                                                       |"<<endl;
            cout <<"\t| Creditos:                                                                             |"<<endl;
            cout <<"\t|                                                                                       |"<<endl;
            cout <<"\t| Este programa foi desenvolvido por Arthur Annes Grandi e Rodrigo Berardi              |"<<endl;
            cout <<"\t| Para a disciplina de Algoritmos e Programacao I do professor Eduardo Alves da Silva.  |"<<endl;
            cout <<"\t|                                                                                       |"<<endl;
            cout <<"\t| O objetivo do programa e simular um jogo conhecido como  Senha onde o jogador         |"<<endl;
            cout <<"\t| Deve decifrar um codigo de cores. Nesta adaptacao o codigo sera formado por numeros.  |"<<endl;
            cout <<"\t|                                                                                       |"<<endl;
            cout <<"\t| Outubro de 2022.                                                                      |"<<endl;
            cout <<"\t|_______________________________________________________________________________________|"<<endl;
            cout <<" "<<endl;
            system("pause");
            system("cls");

            break;
        case 4:
            cout <<"\t _______________________"<<endl;
            cout <<"\t|                       |"<<endl;
            cout <<"\t| Obrigador por jogar!  |"<<endl;
            cout <<"\t|                       |"<<endl;
            cout <<"\t| Volte sempre!         |"<<endl;
            cout <<"\t|_______________________|"<<endl;
            cout <<" "<<endl;
            system("pause");

            sair = true;

            break;
        default:

            cout <<"\t ________________________________________________________________"<<endl;
            cout <<"\t|                                                                |"<<endl;
            cout <<"\t| Opcao invalida! Aperte qualquer tecla para voltar ao menu.     |"<<endl;
            cout <<"\t|________________________________________________________________|"<<endl;
            cout <<" "<<endl;
            system("pause");
            system("cls");

            break;
        }

    }while(sair != true);

    return 0;
}
