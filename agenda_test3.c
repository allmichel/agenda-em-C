#include <stdio.h> lib padrao de entrada e saida
#include <stdlib.h> lib padrao de proposito geral de C. possui fun��es envolvendo aloca��o de mem�ria, controle de processos, convers�es e outras.
#include <string.h> lib responsavel por manipular strings

    struct pessoa {
    char nome[50];
    char ddd[50];
    char telefone[50];
    char data[50];
    };

    struct pessoa contato[100];

    int opcao,op;/// VARIAVEL NA ESCOLHA DO MENU
    int count=0;///VARIAVEL QUE CONTEM O VALOR DO indice DO VETOR
    char pesq[30],pesq2[30];///GUARDAR O NOME DA PESQUISA
    int cod;
    int d,m;
    //op 1 -> adiciona todos contatos
    void add_cont(){
        system("cls");//limpa a tela
        printf("=========================================\n");
        printf("            Adicionar um contato         \n");
        printf("=========================================\n");
        printf("\n Insira seu nome:");
        printf("\n (EX: Allan)\n");
        scanf("%s",contato[count].nome);
        printf("\n Insira o DDD:");
        printf("\n (EX: 88)\n");
        scanf("%s",&contato[count].ddd);
        printf("\n Insira o numero de telefone");
        printf("\n (EX: 98126-0072)\n");
        scanf("%s",&contato[count].telefone);
        printf("\n Insira a data de aniversario: ");
        printf("\n (EX: 28/10/2003)\n");
        scanf("%s", &contato[count].data);
        count++;
        fflush(stdin);
    }
    //op 2 -> pesquisa um contato
    void search_cont(){
        system("cls");
        printf("=========================================\n");
        printf("          Pesquisar um contato           \n");
        printf("=========================================\n");
        printf("\nPESQUISAR:");
        scanf("%s",pesq);
        for(int i=0; i<count; i++) {
        if(strcmp(pesq,contato[i].nome)==0){
            printf("\n CONTATO LOCALIZADO COM SUCESSO!!",i);
            printf("\n NOME:%s",contato[i].nome);
            printf("\n TELEFONE:(%s) %s",contato[i].ddd,contato[i].telefone);
            printf("\n ANIVERSARIO DD/MM/ANO : %s", contato[i].data);
            }
        }
        printf("\n");
        system("pause");

    }
    //op 3 -> exclui o contato que o usuario deseja
    void clean_cont(){
        char procura[30], *x;
	    int j;
        system("cls");
        printf("=========================================\n");
        printf("            Remover um contato           \n");
        printf("=========================================\n");
        printf("\nINFORME O NOME:");
        scanf("%s", &procura);
        for(int i = 0; i < count; i++){
		x = contato[i].nome;
		j = strcmp(x, procura);
		if(j == 0){
			contato[i].nome[0] = '\0';
			contato[i].ddd[0] = '\0';
			contato[i].telefone[0] = '\0';
			contato[i].data[0] = '\0';
			count--;
			printf("\nCONTATO DELETADO COM SUCESSO!\n\n");
			system("pause");
		}
	}

        if(j != 0){
            printf("\nNenhum resultado encontrado!\n\n");
            system("pause");
    	}
    }
    //op 4 -> lista todos contatos informados
    void list_cont(){
        system("cls");
        printf("=========================================\n");
        printf("         Listar todos os contatos        \n");
        printf("=========================================\n");
        for(int i=0; i<count; i++){
            printf("\n NOME:%s",contato[i].nome);
            printf("\n TEL:(%s) %s",contato[i].ddd,contato[i].telefone);
            printf("\n ANIVERSARIO: %s", contato[i].data);
            printf("\n=======================================\n");
        }
        system("pause");
    }
    //op 5 -> pesquisa os contatos por DDD
    void search_ddd(){
        system("cls");
        printf("=========================================\n");
        printf("  Pesquisar o estado brasileiro por DDD  \n");
        printf("=========================================\n");
        printf("\nPESQUISAR:");
        scanf("%s",pesq2);
        for(int i=0; i<count; i++){
            if(strcmp(pesq2,contato[i].ddd)==0){
            printf("\n CONTATO LOCALIZADO COM SUCESSO!!",i);
            printf("\n NOME:%s",contato[i].nome);
            printf("\n TELEFONE:%s %s",contato[i].ddd,contato[i].telefone);
            printf("\n ANIVERSARIO DD/MM/ANO : %s", contato[i].data);
            }
        }

        printf("\n");
        system("pause");
    }

    void clean_dup(){
        printf("\n ): \n");
        system("pause");
    }
    //op 7 -> excluir todos contatos
    void clean(){
        int cl;
        printf("Deseja realmente excluir todos os contatos? SIM(1)/NAO(2): ");
        scanf("%d",&cl);
        if (cl == 1)
        {
        for (int i = 0; i < count; i++)
        {
            contato[i].nome[0] = '/0';
            contato[i].ddd[0] = '/0';
            contato[i].telefone[0] = '/0';
            contato[i].data[0] = '/0';
        }
        count = 0;

        printf("Todos os contatos foram excluidos permanentemente! ");

        system("pause");
        }
        else if (cl==2)
        {
            system("pause");
        }
        else
        {
            printf("\n por favor, informe somente os numeros solicitados \n");
            system("pause");
        }
    }
    //op 8 -> sobre nós
    void about_us()
{
        system("cls");
        printf("       * UNIVERSIDADE FEDERAL DO CEARA *\n\n");
        printf("       CAMPUS JARDINS DE ANITA - ITAPAJE\n\n");
        printf("                      *  *\n\n");
        printf("CURSO TECNOLOGO EM ANALISE E DESENVOLVIMENTO DE SISTEMAS\n\n");
        printf("EQUIPE: Allan Michel, Guilherme Pinheiro, Jurandir Neto\n\n");
        printf("\n\n");
        printf("Esta agenda foi criada para a disciplina de Laboratorio de Programcao,\n\n");
        printf("Tendo como fito, estimular a capacidade do aluno de\n\n");
        printf("trabalhar em equipe para organizar, projetar e desenvolver solucoes\n\n");
        printf("para problemas formulados que envolvam o estudo e o conhecimento\n\n");
        printf("adquirido durante a disciplina;\n\n");
        printf("E aplicacao do conhecimento na pratica por meio do desenvolvimento\n\n");
        printf("de programas usando a linguagem de programacao C.\n");
        system("pause");
}

    //op 9 -> finaliza o programa
    void exit_diary(){
        system("exit");
    }

    int main(int argc, char const *argv[])
    {
        do
        {
            system("cls");
            printf("\n=======================================");
            printf("\n               AGENDA                 =");
            printf("\n=======================================\n");
            printf("   [1] Adicionar novo contato\n");
            printf("   [2] Pesquisar um contato\n");
            printf("   [3] Remover um contato\n");
            printf("   [4] Listar todos os contato\n");
            printf("   [5] Pesquisar o estado brasileiro pelo DDD\n");
            printf("   [6] Limpar duplicados\n");
            printf("   [7] Fazer a limpa\n");
            printf("   [8] Sobre nos\n");
            printf("   [9] sair do programa\n");
            printf("\n=======================================\n");
            printf("\n escolha a opcao: ");
            scanf("%d",&op);

            switch (op)
            {
                case 1: { add_cont(); break;}
                case 2: { search_cont(); break;}
                case 3: { clean_cont(); break;}
                case 4: { list_cont(); break;}
                case 5: { search_ddd(); break;}
                case 6: { clean_dup(); break;}
                case 7: { clean(); break;}
                case 8: { about_us(); break;}
                case 9: { exit_diary(); break;}
            }

        }while(op!=9);
        return 0;
    }