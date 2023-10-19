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
	char* escolha;
	char* opcao;
	
	// Define a mensagem de pular
	if ( pular == 1 ) {
		opcao = "\n\n\n\t\t\t\tPressione: \n"
			    "\t\t - 'Enter' para continuar a história \n"
			    "\t\t -   'P'   para pular a história \n"
			    "\t\t -   'Q'   para finalizar o jogo...\n";
			   
	// Define mensagem de continuar
	} else {
		opcao = "\n\n\n\t Pressione 'Enter' para continuar a história ou 'Q' para finalizar o jogo...\n";
	}

	// Verificar escolha
	while (1) {
		
		//Exibir Opção
		printf(opcao);
		
		// Captura o carater digitado
        escolha = getchar();
		
		if (escolha == '\n') {
			// Imprimir texto
			system("cls");
			espaco();
			imprimir(texto);
			return 1;
			break;
			
		} else if (escolha == 'p' || escolha == 'P') {
			// Imprimir contexto pulado
			system("cls");
			espaco();
			imprimir("\t\t\t Contexto pulado!");
	    	return 2;
	    	break;
		} else if (escolha == 'q' || escolha == 'Q') {
			// Finalizar jogo
			system("cls");
			espaco();
	        printf("\n Jogo finalizado.\n");
	        return 0;
	        break;
	    } else {
			// Opção inválida
			system("cls");
			printf("\n\n\t Escolha inválida. Tente novamente.");
		}	
	}
}

int decisao(char* texto, char* opcoes){
	// Limpa a tela
	system("cls");
	
	int escolha;

	// Verificar escolha
    while (1) {
    	
		// Imprime o texto
    	espaco();
		imprimir(texto);
		
    	// Imprime as opções
        printf("\n\n\t #Escolha uma opção: \n");
		imprimir(opcoes);
		printf("\n");
		
		// Armazena a opção
        scanf("%d", &escolha);

        if (escolha == 1 || escolha == 2 || escolha == 3) {
            // O usuário fez uma escolha válida
            // Sai do loop
			break; 
			 
        } else {
        	// Opção inválida
            system("cls");
			printf("\n\n\t Escolha inválida. Tente novamente.");
        }
    };

    // Retornar opção escolhida
    switch (escolha) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
    };
}

int fim(char* texto, char* texto_fim) {
	system("cls");
	
	espaco();
	imprimir(texto);
	sleep(4);
	
	system("cls");
	espaco();
	imprimir(texto_fim);
	sleep(4);
}

void aceitar_pacto() {
	char* texto_base;
	char* opcoes;
	char* texto_fim;
	
	texto_base = "\t Ao aceitar o Pacto, Aphelios desesperadamente se arrepende de sua escolha. \n"
				 "\t Veigar, o mago, o joga Aphelios em uma realidade alternativa do Reino, \n"
				 "\t onde a esposa do Caçador não o conhece! Com isso, o agir de Aphelios \n"
			 	 "\t é saber rapidamente sobre Liora, onde ele descobre que nesse mundo, \n"
				 "\t ela é uma guerreira contra o reino de Veigar, dono de um exército \n"
				 "\t enorme que controla toda a região. Então, ele decide procurá-la. \n"
				 "\t O que Aphelios deverá fazer?";
				
	opcoes = "\t 1.	Aphelios deve procurar sozinho Liora.\n"
			 "\t 2.	Aphelios deve encontrar o exército de Liora e tentar se infiltrar para ajudá-la na guerra. \n"
			 "\t 3.	Aphelios deve procurar um antigo amigo seu, Jax, para ajudá-lo a achar Liora.";

	switch (decisao(texto_base, opcoes)) {

		// Deve procurar sozinho Liora
		case 1:
			texto_base = "\t Após muita dificuldade, Aphelios encontra Liora e ela é uma guerreira resistente \n"
						 "\t e líder de um exército contra o Reino. Como Aphelios deve agir?";
						
			opcoes = "\t 1.	Lutar ao lado de Liora como um soldado sem ela saber quem ele é. \n"
					 "\t 2.	Conversar com Liora e tentar fazê-la lembrar deles.";

			switch (decisao(texto_base, opcoes)) {

				// Lutar ao lado de Liora - FIM
				case 1:
					texto_base = "\t Liora aceita Aphelios no seu exército. Liora, uma jovem guerreira que não deixa \n"
								 "\t seus companheiros de guerra para trás, vê Aphelios em uma situação de perigo, \n" 
								 "\t onde o Caçador está na mira de Veigar, rapidamente Liora percebe e doa sua vida por Aphelios";

					texto_fim = "\t #FINAL: \n\n"
								"\t Sacrificando toda a sua alma pelo Caçador, onde Aphelios se revolta e mata Veigar, \n"
								"\t quebrando assim todo feitiço, fazendo Aphelios voltar à realidade em Iônia, porém, sem sua amada Liora.";

					fim(texto_base, texto_fim);
				break;

				// Conversar com Liora e fazÃª-la lembrar - FIM
				case 2:
					texto_base = "\t Liora, reafirmando sua paixão inabalável por Aphelios, decide protegê-lo ao prender o Caçador, \n"
								 "\t resultando em seu exército enfraquecido perante Veigar. Contudo, com a coragem de Jax, seu leal amigo, \n"
							     "\t o Caçador é libertado e triunfa sobre Veigar, desfazendo o feitiço sombrio e restaurando a paz em Iônia, \n"
								 "\t embora o preço dessa vitória seja a perda irreparável de seu exército, que era como uma família para Liora.";

					texto_fim = "\t Agora, juntos, eles enfrentam o desafio de reconstruir suas vidas com amor e determinação, \n"
								"\t enquanto Liora relembra a intensidade de sua paixão por Aphelios.";

					fim(texto_base, texto_fim);
				break;
			}
		break;	
		// Deve encontrar o exercito e tentar se infiltrar		
		case 2:
			texto_base = "\t Aphelios se infiltra na guerra lutando contra vários soldados de Veigar por vários dias \n"
						 "\t até encontrar Liora, qual atitude ele deverá adotar ao se aproximar de Liora?";

			opcoes = "\t 1. Se infiltrar na guerra e matar Veigar diretamente.\n"
					 "\t 2. Se infiltrar na guerra para conversar com Liora.";

			switch (decisao(texto_base, opcoes)) {
				// Infiltrar na guerra e matar Veigar diretamente - FIM
				case 1:
					texto_base = "\t Aphelios não consegue matar veigar sozinho, o exército do reino alterativo captura o caçador e o prende no calabouço.";
					
					texto_fim = "\t Liora não consegue salvar Aphelios devido não ter conhecido ele.";

					fim(texto_base, texto_fim);
				break;

				// Infiltrar na guerra para conversar com Liora - FIM
				case 2:
					texto_base = "\t Aphelios se infiltra no exército de Liora e tenta manter contato com a guerreira, porém, \n"
								 "\t Veigar percebe que o Caçador está¡ tentando explicar algo para Liora e \n"
								 "\t manda rapidamente seu exército capturar o caçador e matá-lo."; 
								
					texto_fim = "\t Aphelios nãoo consegue se proteger, e falece.";

					fim(texto_base, texto_fim);
				break;
			}
		break;

		// Deve procurar seu antigo amigo para ajudÃ¡-lo a achar Liora
		case 3:		
			texto_base = "\t Aphelios acha um orbe da amizade no meio do mundo alternativo, fazendo-o encontrar Jax, \n"
						 "\t um velho amigo de anos. Porém, ele acaba indo parar um terceiro mundo alternativo em que \n"
						 "\t Liora foi enfeitiçada por Veigar para ser sua amada esposa. Que decisão ele deve tomar?";
			
			opcoes = "\t 1. Aphelios deve usar o orbe para conseguir fazer mais amizades e matar Veigar. \n"
					 "\t 2. Aphelios deve seguir sua vida e não fazer nada nesse mundo alternativo.";

			switch (decisao(texto_base, opcoes)) {
				
				// Usar orbe de amizade e matar Veigar - FIM
				case 1:
					
					texto_base = "\t Aphelios consegue montar um grupo com vários amigos de Jax em comum, com outros \n"
								 "\t poderes como assassinos, tanques e magos, Veigar é contestado e morto. ";
								 
					texto_fim = "\t Após a morte de Veigar, Liora é desencantada e todas as suas vidas voltam ao mundo normal em Iônia, \n"
								"\t fazendo com que a conciliação de Aphelios e sua amada Liora ocorra novamente.";
								
					fim(texto_base, texto_fim);
				break;

				// Seguir sua vida e não fazer nada - FIM
				case 2:
					texto_base = "\t Com isso, Aphelios percebe que a sua nova vida é mais caótica sem Liora, e esbarra com ela \n"
								 "\t em algum bar se divertindo com seus amigos, Aphelios tenta conversar com Liora, porém,\n"
								 "\t ela se assusta. Liora há muito tempo sentia um vazio e ao conhecer Aphelios novamente, sente seu vazio preenchido."; 
								 
					texto_fim = "\t Juntos, caçam e matam Veigar com suas espadas que quebram os feitiços feitos \n"
								"\t pelo Mago maligno. Fazendo assim, ter paz no reino alternativo.";
								
					fim(texto_base, texto_fim);
				break;
			};
		break;
	};
};

int historia() {
	// Aguarda 2 segundos e limpa
	sleep(2);
	system("cls");
	
	espaco();
	imprimir("\t\t Iniciando a historia...");
	
	sleep(1);

	char* texto_base;
	char* opcoes;
	char* texto_fim;
	
	texto_base = "\t Em uma certa manhã no Reino de Iônia… \n\n"
				 "\t Aphelios se encontra cansado da sua rotina exaustiva, e faz o seguinte desejo em voz alta \n"
				 "\t longe da sua casa 'Quero que tu voltes a ser como era antes, tenho sentido falta de como \n"
				 "\t tu eras no passado!' para si. Após esse desabafo, Veigar, um destemido Mago que vagava \n"
				 "\t por Iônia, ouve Aphelios e diz para o Caçador: “Ora, eu posso ajudar você com isso, meu jovem \n"
				 "\t rapaz oferecendo um acordo para sua vida voltar a ser vibrante como antes. Aphelios então deve:";
                         
    opcoes = "\t 1. Aceitar o pacto \n"
			 "\t 2. Recusar o pacto";
                   
                   
    // Inicio
	switch (decisao(texto_base, opcoes)) {

		// Aceitar Pacto
		case 1:		
			aceitar_pacto();
		break;
		
		// Recusa Pacto
		case 2: 
			texto_base = "\t Ao recusar o Pacto, Aphelios se sente perdido e então… pensa no seu relacionamento com Liora. \n"
						 "\t O que ele deverá fazer? ";
			
			opcoes = "\t 1. Terminar com Liora. \n"
					 "\t 2. Não terminar com Liora.";
					 
			switch (decisao(texto_base, opcoes)) {
				// Terminar com Liora
				case 1:
					texto_base = "\t Aphelios segue em frente com a sua vida... \n"
					   			 "\t Qual passo Aphelios deve dar?";
					   			 
					opcoes = "\t 1. Retomar a vida de caçador. \n"
							 "\t 2. Virar ajudante do Reino de Iônia.";
							 
					switch (decisao(texto_base, opcoes)) {
						// Retomar vida de caçador - FIM
						case 1:
							texto_base = "\t Aphelios se torna um dos maiores caçadores novamente, voltando à estaca zero de sua vida, \n"
										 "\t a procura de novos lares e buscando vagar por outros reinos.";
										 
							texto_fim = "\t Veigar deixa Aphelios em paz, fazendo-o criar todo o amargo no coração por levar \n"
										"\t uma vida sozinho, onde esse ódio se transforma em poderes de caça para os reinos que explora.";
							
							fim(texto_base, texto_fim);
						break;
							
						// Virar ajudante do Reino de Iônia - FIM
						case 2:
							texto_base = "\t Aphelios em seu passado sempre foi conhecido como um dos maiores caçadores do Reino, \n"
										 "\t capaz de combater inimigos como em Targus, cidade que faz fronteira com a muralha do Reino.";
										 
							texto_fim = "\t Com a proposta da corte, Aphelios volta a ter apoio do Reino para \n"
										"\t ter a sua vida de Caçador de volta, ganhando mais poder e experiência.";
							
							fim(texto_base, texto_fim);
						break;
					}
				break;
					
				// Não terminar com Liora
				case 2:
					// Aceita o pacto
					
					texto_base = "\t Veigar se sente ameaçado por Aphelios porque o caçador não escolheu aceitar \n"
								 "\t o pacto, fazendo com que Liora corra perigo em Iônia, onde o mago joga um feitiço \n"
								 "\t na camponesa e acaba raptando-a. Com isso, dias após a procura de Aphelios pelo reino, \n"
								 "\t Veigar aparece fazendo novamente a proposta ao caçador, \n"
								 "\t e ele aceita sem pensar duas vezes, na chance de recuperar sua amada!";
					
					if( continuar(texto_base, 0) == 1) {
						aceitar_pacto();	
					}
					 
				break;
			}
		break;
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
					"|-------------------------------------------------------------------------| \n\n"
					"\t\t\tSeja Bem-vindo ao Jogo!";
			
	// Imprimir titulo
	espaco();
	imprimir(titulo);
			
	// Pular contexto?
	int pular = continuar("", 1);
	
	if(pular == 2){
		historia();
	} else if (pular == 1) {
		contexto();
	}
    
    return 0;
}

