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
			    "\t\t - 'Enter' para continuar a hist�ria \n"
			    "\t\t -   'P'   para pular a hist�ria \n"
			    "\t\t -   'Q'   para finalizar o jogo...\n";
			   
	// Define mensagem de continuar
	} else {
		opcao = "\n\n\n\t Pressione 'Enter' para continuar a hist�ria ou 'Q' para finalizar o jogo...\n";
	}

	// Verificar escolha
	while (1) {
		
		//Exibir Op��o
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
			// Op��o inv�lida
			system("cls");
			printf("\n\n\t Escolha inv�lida. Tente novamente.");
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
		
    	// Imprime as op��es
        printf("\n\n\t #Escolha uma op��o: \n");
		imprimir(opcoes);
		printf("\n");
		
		// Armazena a op��o
        scanf("%d", &escolha);

        if (escolha == 1 || escolha == 2 || escolha == 3) {
            // O usu�rio fez uma escolha v�lida
            // Sai do loop
			break; 
			 
        } else {
        	// Op��o inv�lida
            system("cls");
			printf("\n\n\t Escolha inv�lida. Tente novamente.");
        }
    };

    // Retornar op��o escolhida
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
				 "\t onde a esposa do Ca�ador n�o o conhece! Com isso, o agir de Aphelios \n"
			 	 "\t � saber rapidamente sobre Liora, onde ele descobre que nesse mundo, \n"
				 "\t ela � uma guerreira contra o reino de Veigar, dono de um ex�rcito \n"
				 "\t enorme que controla toda a regi�o. Ent�o, ele decide procur�-la. \n"
				 "\t O que Aphelios dever� fazer?";
				
	opcoes = "\t 1.	Aphelios deve procurar sozinho Liora.\n"
			 "\t 2.	Aphelios deve encontrar o ex�rcito de Liora e tentar se infiltrar para ajud�-la na guerra. \n"
			 "\t 3.	Aphelios deve procurar um antigo amigo seu, Jax, para ajud�-lo a achar Liora.";

	switch (decisao(texto_base, opcoes)) {

		// Deve procurar sozinho Liora
		case 1:
			texto_base = "\t Ap�s muita dificuldade, Aphelios encontra Liora e ela � uma guerreira resistente \n"
						 "\t e l�der de um ex�rcito contra o Reino. Como Aphelios deve agir?";
						
			opcoes = "\t 1.	Lutar ao lado de Liora como um soldado sem ela saber quem ele �. \n"
					 "\t 2.	Conversar com Liora e tentar faz�-la lembrar deles.";

			switch (decisao(texto_base, opcoes)) {

				// Lutar ao lado de Liora - FIM
				case 1:
					texto_base = "\t Liora aceita Aphelios no seu ex�rcito. Liora, uma jovem guerreira que n�o deixa \n"
								 "\t seus companheiros de guerra para tr�s, v� Aphelios em uma situa��o de perigo, \n" 
								 "\t onde o Ca�ador est� na mira de Veigar, rapidamente Liora percebe e doa sua vida por Aphelios";

					texto_fim = "\t #FINAL: \n\n"
								"\t Sacrificando toda a sua alma pelo Ca�ador, onde Aphelios se revolta e mata Veigar, \n"
								"\t quebrando assim todo feiti�o, fazendo Aphelios voltar � realidade em I�nia, por�m, sem sua amada Liora.";

					fim(texto_base, texto_fim);
				break;

				// Conversar com Liora e fazê-la lembrar - FIM
				case 2:
					texto_base = "\t Liora, reafirmando sua paix�o inabal�vel por Aphelios, decide proteg�-lo ao prender o Ca�ador, \n"
								 "\t resultando em seu ex�rcito enfraquecido perante Veigar. Contudo, com a coragem de Jax, seu leal amigo, \n"
							     "\t o Ca�ador � libertado e triunfa sobre Veigar, desfazendo o feiti�o sombrio e restaurando a paz em I�nia, \n"
								 "\t embora o pre�o dessa vit�ria seja a perda irrepar�vel de seu ex�rcito, que era como uma fam�lia para Liora.";

					texto_fim = "\t Agora, juntos, eles enfrentam o desafio de reconstruir suas vidas com amor e determina��o, \n"
								"\t enquanto Liora relembra a intensidade de sua paix�o por Aphelios.";

					fim(texto_base, texto_fim);
				break;
			}
		break;	
		// Deve encontrar o exercito e tentar se infiltrar		
		case 2:
			texto_base = "\t Aphelios se infiltra na guerra lutando contra v�rios soldados de Veigar por v�rios dias \n"
						 "\t at� encontrar Liora, qual atitude ele dever� adotar ao se aproximar de Liora?";

			opcoes = "\t 1. Se infiltrar na guerra e matar Veigar diretamente.\n"
					 "\t 2. Se infiltrar na guerra para conversar com Liora.";

			switch (decisao(texto_base, opcoes)) {
				// Infiltrar na guerra e matar Veigar diretamente - FIM
				case 1:
					texto_base = "\t Aphelios n�o consegue matar veigar sozinho, o ex�rcito do reino alterativo captura o ca�ador e o prende no calabou�o.";
					
					texto_fim = "\t Liora n�o consegue salvar Aphelios devido n�o ter conhecido ele.";

					fim(texto_base, texto_fim);
				break;

				// Infiltrar na guerra para conversar com Liora - FIM
				case 2:
					texto_base = "\t Aphelios se infiltra no ex�rcito de Liora e tenta manter contato com a guerreira, por�m, \n"
								 "\t Veigar percebe que o Ca�ador est� tentando explicar algo para Liora e \n"
								 "\t manda rapidamente seu ex�rcito capturar o ca�ador e mat�-lo."; 
								
					texto_fim = "\t Aphelios n�oo consegue se proteger, e falece.";

					fim(texto_base, texto_fim);
				break;
			}
		break;

		// Deve procurar seu antigo amigo para ajudá-lo a achar Liora
		case 3:		
			texto_base = "\t Aphelios acha um orbe da amizade no meio do mundo alternativo, fazendo-o encontrar Jax, \n"
						 "\t um velho amigo de anos. Por�m, ele acaba indo parar um terceiro mundo alternativo em que \n"
						 "\t Liora foi enfeiti�ada por Veigar para ser sua amada esposa. Que decis�o ele deve tomar?";
			
			opcoes = "\t 1. Aphelios deve usar o orbe para conseguir fazer mais amizades e matar Veigar. \n"
					 "\t 2. Aphelios deve seguir sua vida e n�o fazer nada nesse mundo alternativo.";

			switch (decisao(texto_base, opcoes)) {
				
				// Usar orbe de amizade e matar Veigar - FIM
				case 1:
					
					texto_base = "\t Aphelios consegue montar um grupo com v�rios amigos de Jax em comum, com outros \n"
								 "\t poderes como assassinos, tanques e magos, Veigar � contestado e morto. ";
								 
					texto_fim = "\t Ap�s a morte de Veigar, Liora � desencantada e todas as suas vidas voltam ao mundo normal em I�nia, \n"
								"\t fazendo com que a concilia��o de Aphelios e sua amada Liora ocorra novamente.";
								
					fim(texto_base, texto_fim);
				break;

				// Seguir sua vida e n�o fazer nada - FIM
				case 2:
					texto_base = "\t Com isso, Aphelios percebe que a sua nova vida � mais ca�tica sem Liora, e esbarra com ela \n"
								 "\t em algum bar se divertindo com seus amigos, Aphelios tenta conversar com Liora, por�m,\n"
								 "\t ela se assusta. Liora h� muito tempo sentia um vazio e ao conhecer Aphelios novamente, sente seu vazio preenchido."; 
								 
					texto_fim = "\t Juntos, ca�am e matam Veigar com suas espadas que quebram os feiti�os feitos \n"
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
	
	texto_base = "\t Em uma certa manh� no Reino de I�nia� \n\n"
				 "\t Aphelios se encontra cansado da sua rotina exaustiva, e faz o seguinte desejo em voz alta \n"
				 "\t longe da sua casa 'Quero que tu voltes a ser como era antes, tenho sentido falta de como \n"
				 "\t tu eras no passado!' para si. Ap�s esse desabafo, Veigar, um destemido Mago que vagava \n"
				 "\t por I�nia, ouve Aphelios e diz para o Ca�ador: �Ora, eu posso ajudar voc� com isso, meu jovem \n"
				 "\t rapaz oferecendo um acordo para sua vida voltar a ser vibrante como antes. Aphelios ent�o deve:";
                         
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
			texto_base = "\t Ao recusar o Pacto, Aphelios se sente perdido e ent�o� pensa no seu relacionamento com Liora. \n"
						 "\t O que ele dever� fazer? ";
			
			opcoes = "\t 1. Terminar com Liora. \n"
					 "\t 2. N�o terminar com Liora.";
					 
			switch (decisao(texto_base, opcoes)) {
				// Terminar com Liora
				case 1:
					texto_base = "\t Aphelios segue em frente com a sua vida... \n"
					   			 "\t Qual passo Aphelios deve dar?";
					   			 
					opcoes = "\t 1. Retomar a vida de ca�ador. \n"
							 "\t 2. Virar ajudante do Reino de I�nia.";
							 
					switch (decisao(texto_base, opcoes)) {
						// Retomar vida de ca�ador - FIM
						case 1:
							texto_base = "\t Aphelios se torna um dos maiores ca�adores novamente, voltando � estaca zero de sua vida, \n"
										 "\t a procura de novos lares e buscando vagar por outros reinos.";
										 
							texto_fim = "\t Veigar deixa Aphelios em paz, fazendo-o criar todo o amargo no cora��o por levar \n"
										"\t uma vida sozinho, onde esse �dio se transforma em poderes de ca�a para os reinos que explora.";
							
							fim(texto_base, texto_fim);
						break;
							
						// Virar ajudante do Reino de I�nia - FIM
						case 2:
							texto_base = "\t Aphelios em seu passado sempre foi conhecido como um dos maiores ca�adores do Reino, \n"
										 "\t capaz de combater inimigos como em Targus, cidade que faz fronteira com a muralha do Reino.";
										 
							texto_fim = "\t Com a proposta da corte, Aphelios volta a ter apoio do Reino para \n"
										"\t ter a sua vida de Ca�ador de volta, ganhando mais poder e experi�ncia.";
							
							fim(texto_base, texto_fim);
						break;
					}
				break;
					
				// N�o terminar com Liora
				case 2:
					// Aceita o pacto
					
					texto_base = "\t Veigar se sente amea�ado por Aphelios porque o ca�ador n�o escolheu aceitar \n"
								 "\t o pacto, fazendo com que Liora corra perigo em I�nia, onde o mago joga um feiti�o \n"
								 "\t na camponesa e acaba raptando-a. Com isso, dias ap�s a procura de Aphelios pelo reino, \n"
								 "\t Veigar aparece fazendo novamente a proposta ao ca�ador, \n"
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

