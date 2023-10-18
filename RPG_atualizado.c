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
			   "\t\t - 'Enter' para continuar a história \n"
			   "\t\t -   'P'   para pular a história \n"
			   "\t\t -   'Q'   para finalizar o jogo...\n");
	// Exibe mensagm de continuar
	} else if ( pular == 0) {
		printf("\n\n\nPressione 'Enter' para continuar a história ou 'Q' para finalizar o jogo...\n");
		
	// Exibe somente o texto
	} else {
		// Continua o jogo
        system("cls");
	
		// Coloca o espaço e o texto
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
		
			// Coloca o espaço e o texto
	        espaco();
			imprimir(texto);
            
            return 1;
            break;
        } else if (escolha == 'q' || escolha == 'Q') {
        	// Finaliza o Jogo
        	system("cls");
        	
			// Coloca o espaço e finaliza
        	espaco();
            printf("\n Jogo finalizado.\n");
            
            break;
		} else if (escolha == 'p' || escolha == 'P') {
    		// Pula contexto
    		system("cls");
    	
    		char* pular_contexto = "\t\t\t Contexto pulado!";
    		
			// Coloca o espaço e pula o contexto
    		espaco();
    		imprimir(pular_contexto);
    		
        	return 2;
        	break;
        } else {
        	// Opção desconhecida
        	system("cls");
        	
        	// Coloca o espaço e
        	espaco();
            printf("\nOpção desconhecida. Tente novamente.\n");
            while (getchar() != '\n') continue;
        };
    };
}

int decisao(char* texto, char* opcoes){
	char escolha;
	
	system("cls");
	
	// Coloca o espaço e o texto
    espaco();
	imprimir(texto);
	// Coloca o espaço e as opções
	espaco();
	imprimir(opcoes);
	
	// Verificar escolha
	while (1) {
		
		// Captura o carater digitado
        escolha = getchar();
        
        if (escolha == '1') {
            // Opção 1
            return 1;
            break;
        } else if (escolha == '2') {
			// Opção 2
			return 2;            
            break;
    	} else if (escolha == '3') {
    		// Opção 3
    		return 3;
    		break;
        } else {
        	// Opção desconhecida
        	system("cls");
        	
        	// Coloca o espaço e retorna para as opções
        	espaco();
            printf("\n Opção desconhecida. Tente novamente. \n");
            while (getchar() != '\n') continue;
        };
    };
}

int historia() {
	// Aguarda 2 segundos e limpa
	sleep(2);
	system("cls");
	
	
	printf("\n\n \t\t Iniciando a historia");
	
	sleep(1);
	
	
	char* texto_base = "\t Em uma certa manhã no Reino de Iônia… \n\n"
						 "\t Aphelios se encontra cansado da sua rotina exaustiva, e faz o seguinte desejo em voz alta longe da sua casa \n" 
                         "\t 'Quero que tu voltes a ser como era antes, tenho sentido falta de como tu eras no passado!' para si. Após esse desabafo, Veigar, \n" 
                         "\t um destemido Mago que vagava por Iônia, ouve Aphelios e diz para o Caçador: “Ora, eu posso ajudar você com isso, \n" 
                         "\t meu jovem rapaz oferecendo um acordo para sua vida voltar a ser vibrante como antes. Aphelios então deve:";
                         
    char* opcoes = "\t (01) Aceitar o pacto \n"
                   "\t (02) Recusar o pacto ";
                   
                   
    // Texto 1
    int caminho = decisao(texto_base, opcoes);
	if (caminho == 1) {
		// Aceita Pacto
		
		texto_base = "\t Ao aceitar o Pacto, Aphelios desesperadamente se arrepende de sua escolha. Veigar, o mago, o joga Aphelios \n"
					 "\t em uma realidade alternativa do Reino, onde a esposa do Caçador não o conhece! Com isso, o agir de Aphelios \n"
					 "\t é saber rapidamente sobre Liora, onde ele descobre que nesse mundo, ela é uma guerreira contra o reino de Veigar, \n"
					 "\t dono de um exército enorme que controla toda a região. Então, ele decide procurá-la. O que Aphelios deverá fazer?";
						 
		opcoes = "\t 1.	Aphelios deve procurar sozinho Liora.\n"
				 "\t 2.	Aphelios deve encontrar o exército de Liora e tentar se infiltrar para ajudá-la na guerra. \n"
                 "\t 3.	Aphelios deve procurar um antigo amigo seu, Jax, para ajudá-lo a achar Liora.";
                 
		caminho = decisao(texto_base, opcoes);
		if (caminho == 1) {
			// Deve procurar sozinho Liora
			
			texto_base = "\t Após muita dificuldade, Aphelios encontra Liora e ela é uma guerreira resistente \n"
						 "\t e líder de um exército contra o Reino. Como Aphelios deve agir?";
						 
			opcoes = "\t 1.	Lutar ao lado de Liora como um soldado sem ela saber quem ele é. \n"
					 "\t 2.	Conversar com Liora e tentar fazê-la lembrar deles.";
			
			caminho = decisao(texto_base, opcoes);
			if (caminho == 1) {
				// Lutar ao lado de Liora
				
			} else {
				// Conversar com Liora e fazê-la lembrar
				
			}
			
		} else if (caminho == 3) {
			// Deve encontra exercito e tentar se infiltrar
			
		
		} else if (caminho == 3) {
			// Deve procurar seu antigo amigo para ajudá-lo a achar Liora
			
			
		}
		
	} else {
		// Recusa Pacto
	}	
}

int contexto() {
	char* descricao = "\t No Reino místico de Iônia, \n"
					  "\t embarque em uma emocionante aventura como Aphelios, \n"
					  "\t um caçador que deixou seu passado gloriosos para trás \n"
					  "\t em busca de uma vida simples ao lado de sua amada Liora. \n"
					  "\t No entanto, as reviravoltas do destino o levarão \n"
					  "\t por caminhos inesperados, enquanto ele confronta segredos \n"
					  "\t antigos e poderes mágicos nas terras de Iônia.";
    
    // Descrição
    if (continuar(descricao, 2) == 1) {
    	char* personagens = "\t #Personagens: \n\n"
							"\t - Aphelios (Classe: Caçador): Protagonista \n\n"
							"\t - Liora (Profissão: Camponesa, esposa de Aphelios) \n\n"
							"\t - Veigar (Classe: Mago) \n\n"
							"\t - Jax (Amigo de Aphelios) \n\n";
 		// Personagens
    	if (continuar(personagens, 0) == 1) {
    		char* cenario = "\t #Cenário: \n\n"
							"\t O jogo se passa no Reino de Ionia, uma terra \n"
							"\t repleta de cenários incríveis e templos antigos.";
    		
    		// Cenário
    		if (continuar(cenario, 0) == 1) {
    			char * historia = "\t #História: \n\n"
								  "\t   Aphelios, uma vez um renomado caçador na cidade de Targus,\n"
								  "\t conheceu Liora, e sua paixão por ela cresceu ao longo de uma década.\n"
								  "\t No entanto, ele trocou sua carreira de sucesso por uma vida campestre\n"
								  "\t pacífica ao lado de Liora, afastando-se da cidade e dos perigos do mundo.\n"
								  "\t   Conforme a história se desenrola, Aphelios, insatisfeito com a rotina monótona,\n"
								  "\t acaba sendo arrastado para uma situação dramática que mudará o curso de sua vida \n"
								  "\t e o destino de Iônia. Ele deve enfrentar desafios, desvendar segredos e, \n"
								  "\t com a ajuda de seus amigos, enfrentar as forças obscuras que \n"
								  "\t ameaçam a terra e o seu amor por Liora.";
    			
    			// História
    			if (continuar(historia, 0) == 1) {
    				char* objetivos = "\t #Objetivos: \n\n"
									  "\t - Recuperar seu status de caçador, proteger Ionia e proteger Liora dos perigos que se aproximam. \n\n"
									  "\t - Descobrir a verdade sobre Veigar e seus planos sombrios. \n\n"
									  "\t - Unir forças com Jax e outros aliados para enfrentar ameaças mágicas.\n\n";
							
					// Objetivos		  
					if (continuar(objetivos, 0) == 1) {
						char* escolhas = "\t #Escolhas \n\n"
										 "\t Cada escolha que Aphelios fizer moldará a narrativa do jogo e determinará o destino de Iônia.\n"
						 				 "\t Será um desafio equilibrar o amor por Liora e o dever de proteger o reino. \n"
										 "\t Sua jornada irá misturar romance, mistério e ação em um épico de proporções mágicas.";
						
						// Escolhas
						if (continuar(escolhas, 0) == 1) {
							char* prepare_se = "\t Prepare-se para viver uma emocionante saga em 'Destino Iônico: A Jornada de Aphelios' \n"
							 				   "\t e descubra se o amor, a amizade e a coragem podem superar as forças do destino!";
							
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
								
								// Começo da história
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
					"|=>\t\t  Destino Iônico: A Jornada de Aphelios  \t\t<=| \n"
					"|-------------------------------------------------------------------------| \n\n";
	
	// Apresentar Título
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
    
    return 0;
}


