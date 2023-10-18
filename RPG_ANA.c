# game-rpg
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void espaco() {
	printf("\n\n\n\n\n\n\n\n\n");
}

void imprimir(char* texto){
	int i;
			
	for(i=0; texto[i] !='\0'; i++) {
		putchar(texto[i]); 
		usleep(1000);
	};
}

int continuar(char* texto, int pular) {
	char escolha;
	
	// Exibe a mensagem de pular
	if ( pular == 1 ) {
		printf("\n\n\n\t\t\t\tPressione: \n"
			   "\t\t - 'Enter' para continuar a hist�ria \n"
			   "\t\t -   'P'   para pular a hist�ria \n"
			   "\t\t -   'Q'   para finalizar o jogo...\n");
	// Exibe mensagm de continuar
	} else if ( pular == 0) {
		printf("\n\n\nPressione 'Enter' para continuar a hist�ria ou 'Q' para finalizar o jogo...\n");
		
	// Exibe somente o texto
	} else {
		// Continua o jogo
        system("cls");
	
		// Coloca o espa�o e o texto
        espaco();
		imprimir(texto);
        
        return 1;
	}
	
	// Verificar escolha
	while (1) {
		// Captura o carater digitado
        escolha = getchar();
        
        if (escolha == '\n') {
            // Continua o jogo
            system("cls");
		
			// Coloca o espa�o e o texto
	        espaco();
			imprimir(texto);
            
            return 1;
            break;
        } else if (escolha == 'q' || escolha == 'Q') {
        	// Finaliza o Jogo
        	system("cls");
        	
			// Coloca o espa�o e finaliza
        	espaco();
            printf("\n Jogo finalizado.\n");
            
            break;
		} else if (escolha == 'p' || escolha == 'P') {
    		// Pula contexto
    		system("cls");
    	
    		char* pular_contexto = "\t\t\t Contexto pulado!";
    		
			// Coloca o espa�o e pula o contexto
    		espaco();
    		imprimir(pular_contexto);
    		
        	return 2;
        	break;
        } else {
        	// Op��o desconhecida
        	system("cls");
        	
        	// Coloca o espa�o e
        	espaco();
            printf("\nOp��o desconhecida. Tente novamente.\n");
            while (getchar() != '\n') continue;
        };
    };
}

int historia() {
	// Aguarda 2 segundos e limpa
	sleep(2);
	system("cls");
	
	
	printf("\n\n \t\t Iniciando a historia");
	
}

int contexto() {
	char* descricao = "\t No Reino m�stico de I�nia, \n"
					  "\t embarque em uma emocionante aventura como Aphelios, \n"
					  "\t um ca�ador que deixou seu passado gloriosos para tr�s \n"
					  "\t em busca de uma vida simples ao lado de sua amada Liora. \n"
					  "\t No entanto, as reviravoltas do destino o levar�o \n"
					  "\t por caminhos inesperados, enquanto ele confronta segredos \n"
					  "\t antigos e poderes m�gicos nas terras de I�nia.";
    
    // Descri��o
    if (continuar(descricao, 2) == 1) {
    	char* personagens = "\t #Personagens: \n\n"
							"\t - Aphelios (Classe: Ca�ador): Protagonista \n\n"
							"\t - Liora (Profiss�o: Camponesa, esposa de Aphelios) \n\n"
							"\t - Veigar (Classe: Mago) \n\n"
							"\t - Jax (Amigo de Aphelios) \n\n";
 		// Personagens
    	if (continuar(personagens, 0) == 1) {
    		char* cenario = "\t #Cen�rio: \n\n"
							"\t O jogo se passa no Reino de Ionia, uma terra \n"
							"\t repleta de cen�rios incr�veis e templos antigos.";
    		
    		// Cen�rio
    		if (continuar(cenario, 0) == 1) {
    			char * historia = "\t #Hist�ria: \n\n"
								  "\t   Aphelios, uma vez um renomado ca�ador na cidade de Targus,\n"
								  "\t conheceu Liora, e sua paix�o por ela cresceu ao longo de uma d�cada.\n"
								  "\t No entanto, ele trocou sua carreira de sucesso por uma vida campestre\n"
								  "\t pac�fica ao lado de Liora, afastando-se da cidade e dos perigos do mundo.\n"
								  "\t   Conforme a hist�ria se desenrola, Aphelios, insatisfeito com a rotina mon�tona,\n"
								  "\t acaba sendo arrastado para uma situa��o dram�tica que mudar� o curso de sua vida \n"
								  "\t e o destino de I�nia. Ele deve enfrentar desafios, desvendar segredos e, \n"
								  "\t com a ajuda de seus amigos, enfrentar as for�as obscuras que \n"
								  "\t amea�am a terra e o seu amor por Liora.";
    			
    			// Hist�ria
    			if (continuar(historia, 0) == 1) {
    				char* objetivos = "\t #Objetivos: \n\n"
									  "\t - Recuperar seu status de ca�ador, proteger Ionia e proteger Liora dos perigos que se aproximam. \n\n"
									  "\t - Descobrir a verdade sobre Veigar e seus planos sombrios. \n\n"
									  "\t - Unir for�as com Jax e outros aliados para enfrentar amea�as m�gicas.\n\n";
							
					// Objetivos		  
					if (continuar(objetivos, 0) == 1) {
						char* escolhas = "\t #Escolhas \n\n"
										 "\t Cada escolha que Aphelios fizer moldar� a narrativa do jogo e determinar� o destino de I�nia.\n"
						 				 "\t Ser� um desafio equilibrar o amor por Liora e o dever de proteger o reino. \n"
										 "\t Sua jornada ir� misturar romance, mist�rio e a��o em um �pico de propor��es m�gicas.";
						
						// Escolhas
						if (continuar(escolhas, 0) == 1) {
							char* prepare_se = "\t Prepare-se para viver uma emocionante saga em 'Destino I�nico: A Jornada de Aphelios' \n"
							 				   "\t e descubra se o amor, a amizade e a coragem podem superar as for�as do destino!";
							
							// Prepare - se
							if (continuar(prepare_se, 0) == 1) {
								
								// Preparado?
								sleep(3);
								system("cls");
								
								char* preparado = "\n\n\n\n\n\n\n\n\n"
												  "\t preparado?";
							
								imprimir(preparado);
								sleep(2);
								system("cls");
								
								// Come�o da hist�ria
								historia;
							}
						}		
					}
				}
			}
		}
	}
	
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	
	// Deixar a tela azul e texto branco
	system("color 1F");
	
	char* titulo =  "|-------------------------------------------------------------------------| \n"
					"|=>\t\t  Destino I�nico: A Jornada de Aphelios  \t\t<=| \n"
					"|-------------------------------------------------------------------------| \n\n";
	
	// Apresentar T�tulo
	espaco();
	imprimir(titulo); 
			
	// Dar Boas-vindas
	char* boasvindas = "\t\t\tSeja Bem-vindo ao Jogo!";
	imprimir(boasvindas);		
			
	// Pular contexto?
	int pular = continuar("", 1);
	
	if(pular == 2){
		historia();
	} else if (pular == 1) {
		contexto();
	}
    // Primeiro contexto do jogo 
    char* contextoUm = "\t Aphelios se encontra cansado da sua rotina exaustiva, e faz o seguinte desejo em voz alta longe da sua casa \n" 
                        "\tQuero que tu voltes a ser como era antes, tenho sentido falta de como tu eras no passado!” para si. Após esse desabafo, Veigar, \n" 
                        "\t um destemido Mago que vagava por Iônia, ouve Aphelios e diz para o Caçador: “Ora, eu posso ajudar você com isso, \n" 
                        "\t meu jovem rapaz oferecendo um acordo para sua vida voltar a ser vibrante como antes. Aphelios então deve: \n"
                        "\t (01) Aceitar o pacto \n"
                        "\t (02) Recusar o pacto \n";
            int contextoUm 
            if (contextoUm == 1)
            {
                char* contextoUm = "\t Ao aceitar o Pacto, Aphelios desesperadamente se arrepende de sua escolha. Veigar, o mago, o joga Aphelios em uma realidade alternativa do Reino, \n" 
                                "\t onde a esposa do Caçador não o conhece! Com isso, o agir de Aphelios é saber rapidamente sobre Liora, onde ele descobre que nesse mundo, \n"
                                "\t ela é uma guerreira contra o reino de Veigar, dono de um exército enorme que controla toda a região. Então, ele decide procurá-la.  \n"
                                "\t O que Aphelios deverá fazer? \n";
            }            
            else (contextoUm == 2) // aqui o segmento é de quando o usuário recusa o pacto
            {
                char* contextoUm = "\t Ao recusar o Pacto, Aphelios se sente perdido e então… pensa no seu relacionamento com Liora. \n"
                                    "\tO que ele deverá fazer?\n"

            }
            // segmento da opção 01 quando ele aceita o pacto 
                char* contextoDois = "\t (01)) Aphelios deve procurar sozinho Liora.\n"
                                    "\t (02) Aphelios deve encontrar o exército de Liora e tentar se infiltrar para ajudá-la na guerra.\n"
                                    "\t (03) Aphelios deve procurar um antigo amigo seu, Jax, para ajudá-lo a achar Liora.\n";
                                    int contextoDois
                                    // seo usuário escolher a primeira alternativa do contexto 2
                                    if (contextoDois == 1){
                                        char* contextoDois = "\tApós muita dificuldade, Aphelios encontra Liora e ela é uma guerreira resistente e líder de um exército contra o Reino.\n"
                                                             "\tComo Aphelios deve agir?\n"
                                    }                              
                                    

    return 0;
}
