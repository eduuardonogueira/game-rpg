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

int continuar(char* texto) {
	char escolha;
	
	char* opcao = "\n\n\n\t\t\t\t  Pressione: \n"
		    "\t\t -   'C'   para continuar a hist�ria \n"
		    "\t\t -   'P'   para pular a hist�ria \n"
		    "\t\t -   'Q'   para finalizar o jogo... \n\n"
		    "\t\t Sua Escolha: ";
	
	system("cls");  
	
    while (1) {
    	
    	// Imprimir texto e op��es

		espaco();
		imprimir(texto);
		printf(opcao);
    	
    	
        scanf(" %c", &escolha);

        if (escolha == 'C' || escolha == 'c') {
            // Continuar hist�ria
            return 1;
            break;
        } else if (escolha == 'P' || escolha == 'p') {
            // Pular para hist�ria
			historia();
			break;
        } else if (escolha == 'Q' || escolha == 'q') {
        	return 0;
            printf("Finalizando o jogo...\n");
            break; // Sai do loop
        } else {
        	system("cls");
            printf("\n\n\t\t\t Op��o inv�lida. Tente novamente.\n");
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
        printf("\n\n");
		printf(opcoes);
		printf("\n\n\t Sua escolha: ");
		
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

int fim(char* texto, char* texto_fim, int tipo) {
	system("cls");
	
	if (tipo == 1) {
		system("color 2F");
		
	} else if (tipo == 2) {
		system("color 6F");
		
	} else {
		system("color 4F");
	}
	
	// Pr� final
	espaco();
	printf("\n\n\n");
	imprimir(texto);
	sleep(4);
	
	// Mensagem final
	system("cls");
	espaco();
	printf("\n\n\n");
	imprimir(texto_fim);
	sleep(5);
	
	// FIM!
	system("cls");
	espaco();
	printf("\n\n\n");	
	imprimir("\t\t\t\t  Obrigado por jogar! :) ");
	sleep(2);
	
	// Jogar denovo?
	system("cls");
	
	char* opcao = "\t\t\t  Deseja jogar novamente? \n"
		    	  "\t\t -   'C'   jogar novamente \n"
		    	  "\t\t -   'Q'   para finalizar o jogo... \n\n"
		    	  "\t\t Sua Escolha: ";
		    
	char escolha;
			   
    while (1) {
    	
    	// Imprimir texto e op��es
		espaco();
		printf("\n\n\n");
		imprimir(opcao);
    	
        scanf(" %c", &escolha);

        if (escolha == 'C' || escolha == 'c') {
            // Continuar hist�ria
            main();
            break;
            
        } else if (escolha == 'Q' || escolha == 'q') {
        	return 0;
            printf("Finalizando o jogo...\n");
            break; // Sai do loop
            
        } else {
        	system("cls");
        	espaco();
            printf("\t\t\t Op��o inv�lida. Tente novamente.\n");
        }
    }
	
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
				 "\t enorme que controla toda a regi�o. Ent�o, ele decide procur�-la.";
				
	opcoes = "\t\t #O que Aphelios dever� fazer? \n"
			 "\t 1.	Aphelios deve procurar sozinho Liora. \n"
			 "\t 2.	Aphelios deve encontrar o ex�rcito de Liora e tentar se infiltrar para ajud�-la na guerra. \n"
			 "\t 3.	Aphelios deve procurar um antigo amigo seu, Jax, para ajud�-lo a achar Liora.";

	switch (decisao(texto_base, opcoes)) {

		// Deve procurar sozinho Liora
		case 1:
			texto_base = "\t Ap�s muita dificuldade, Aphelios encontra Liora e ela � uma \n"
						 "\t guerreira resistente e l�der de um ex�rcito contra o Reino.";
						
			opcoes = "\t #Como Aphelios deve agir? \n"
					 "\t 1.	Lutar ao lado de Liora como um soldado sem ela saber quem ele �. \n"
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

					fim(texto_base, texto_fim, 2);
				break;

				// Conversar com Liora e faze-la lembrar - FIM
				case 2:
					texto_base = "\t Liora, reafirmando sua paix�o inabal�vel por Aphelios, decide proteg�-lo ao prender o Ca�ador, \n"
								 "\t resultando em seu ex�rcito enfraquecido perante Veigar. Contudo, com a coragem de Jax, seu leal amigo, \n"
							     "\t o Ca�ador � libertado e triunfa sobre Veigar, desfazendo o feiti�o sombrio e restaurando a paz em I�nia, \n"
								 "\t embora o pre�o dessa vit�ria seja a perda irrepar�vel de seu ex�rcito, que era como uma fam�lia para Liora.";

					texto_fim = "\t Agora, juntos, eles enfrentam o desafio de reconstruir suas vidas com amor e determina��o, \n"
								"\t enquanto Liora relembra a intensidade de sua paix�o por Aphelios.";

					fim(texto_base, texto_fim, 1);
				break;
			}
		break;	
		// Deve encontrar o exercito e tentar se infiltrar		
		case 2:
			texto_base = "\t Aphelios se infiltra na guerra lutando contra v�rios\n"
						 "\t soldados de Veigar por v�rios dias at� encontrar Liora. ";

			opcoes = "\t #Qual atitude ele dever� adotar ao se aproximar de Liora? \n"
					 "\t 1. Se infiltrar na guerra e matar Veigar diretamente.\n"
					 "\t 2. Se infiltrar na guerra para conversar com Liora.";

			switch (decisao(texto_base, opcoes)) {
				// Infiltrar na guerra e matar Veigar diretamente - FIM
				case 1:
					texto_base = "\t Aphelios n�o consegue matar veigar sozinho, o ex�rcito do reino alterativo captura o ca�ador e o prende no calabou�o.";
					
					texto_fim = "\t Liora n�o consegue salvar Aphelios devido n�o ter conhecido ele.";

					fim(texto_base, texto_fim, 0);
				break;

				// Infiltrar na guerra para conversar com Liora - FIM
				case 2:
					texto_base = "\t Aphelios se infiltra no ex�rcito de Liora e tenta manter contato com a guerreira, por�m, \n"
								 "\t Veigar percebe que o Ca�ador est� tentando explicar algo para Liora e \n"
								 "\t manda rapidamente seu ex�rcito capturar o ca�ador e mat�-lo."; 
								
					texto_fim = "\t Aphelios n�o consegue se proteger, e falece.";

					fim(texto_base, texto_fim, 0);
				break;
			}
		break;

		// Deve procurar seu antigo amigo para ajud�-lo a achar Liora
		case 3:		
			texto_base = "\t Aphelios acha um orbe da amizade no meio do mundo alternativo, fazendo-o encontrar Jax, \n"
						 "\t um velho amigo de anos. Por�m, ele acaba indo parar um terceiro mundo alternativo em que \n"
						 "\t Liora foi enfeiti�ada por Veigar para ser sua amada esposa.";
			
			opcoes = "\t #Que decis�o ele deve tomar? \n"
					 "\t 1. Aphelios deve usar o orbe para conseguir fazer mais amizades e matar Veigar. \n"
					 "\t 2. Aphelios deve seguir sua vida e n�o fazer nada nesse mundo alternativo.";

			switch (decisao(texto_base, opcoes)) {
				
				// Usar orbe de amizade e matar Veigar - FIM
				case 1:
					
					texto_base = "\t Aphelios consegue montar um grupo com v�rios amigos de Jax em comum, com outros \n"
								 "\t poderes como assassinos, tanques e magos, Veigar � contestado e morto. ";
								 
					texto_fim = "\t Ap�s a morte de Veigar, Liora � desencantada e todas as suas vidas voltam ao mundo normal em I�nia, \n"
								"\t fazendo com que a concilia��o de Aphelios e sua amada Liora ocorra novamente.";
								
					fim(texto_base, texto_fim, 1);
				break;

				// Seguir sua vida e n�o fazer nada - FIM
				case 2:
					texto_base = "\t Com isso, Aphelios percebe que a sua nova vida � mais ca�tica sem Liora, \n"
								 "\t e esbarra com ela em algum bar se divertindo com seus amigos, \n "
								 "\t Aphelios tenta conversar com Liora, por�m, ela se assusta. \n"
								 "\t Liora h� muito tempo sentia um vazio e ao conhecer Aphelios novamente, \n"
								 "\t sente seu vazio preenchido."; 
								 
					texto_fim = "\t Juntos, ca�am e matam Veigar com suas espadas que quebram os feiti�os feitos \n"
								"\t pelo Mago maligno. Fazendo assim, ter paz no reino alternativo.";
								
					fim(texto_base, texto_fim, 1);
				break;
			};
		break;
	};
};

int historia() {
	// Aguarda 2 segundos e limpa
	system("cls");
	
	espaco();
	imprimir("\t\t Iniciando a historia...");
	
	sleep(1);

	char* texto_base;
	char* opcoes;
	char* texto_fim;
	
	texto_base = "\t Em uma certa manh� no Reino de I�nia... \n\n"
				 "\t Aphelios se encontra cansado da sua rotina exaustiva, e faz o seguinte desejo em voz alta \n"
				 "\t longe da sua casa 'Quero que tu voltes a ser como era antes, tenho sentido falta de como \n"
				 "\t tu eras no passado!' para si. Ap�s esse desabafo, Veigar, um destemido Mago que vagava por I�nia, \n"
				 "\t ouve Aphelios e diz para o Ca�ador: Ora, eu posso ajudar voc� com isso, meu jovem rapaz \n"
				 "\t oferecendo um acordo para sua vida voltar a ser vibrante como antes.";
                         
    opcoes = "\t #Aphelios ent�o deve:\n"
			 "\t 1. Aceitar o pacto \n"
			 "\t 2. Recusar o pacto";
                   
                   
    // Inicio
	switch (decisao(texto_base, opcoes)) {

		// Aceitar Pacto
		case 1:		
			aceitar_pacto();
		break;
		
		// Recusa Pacto
		case 2: 
			texto_base = "\t Ao recusar o Pacto, Aphelios se sente perdido e ent�o pensa no seu relacionamento com Liora.";
			
			opcoes = "\t #O que ele dever� fazer? \n"
					 "\t 1. Terminar com Liora. \n"
					 "\t 2. N�o terminar com Liora.";
					 
			switch (decisao(texto_base, opcoes)) {
				// Terminar com Liora
				case 1:
					texto_base = "\t Aphelios segue em frente com a sua vida...";

					opcoes = "\t #Qual passo Aphelios deve dar? \n"
							 "\t 1. Retomar a vida de ca�ador. \n"
							 "\t 2. Virar ajudante do Reino de I�nia.";
							 
					switch (decisao(texto_base, opcoes)) {
						// Retomar vida de ca�ador - FIM
						case 1:
							texto_base = "\t Aphelios se torna um dos maiores ca�adores novamente, voltando � estaca zero de sua vida, \n"
										 "\t a procura de novos lares e buscando vagar por outros reinos.";
										 
							texto_fim = "\t Veigar deixa Aphelios em paz, fazendo-o criar todo o amargo no cora��o por levar \n"
										"\t uma vida sozinho, onde esse �dio se transforma em poderes de ca�a para os reinos que explora.";
							
							fim(texto_base, texto_fim, 1);
						break;
							
						// Virar ajudante do Reino de I�nia - FIM
						case 2:
							texto_base = "\t Aphelios em seu passado sempre foi conhecido como um dos maiores ca�adores do Reino, \n"
										 "\t capaz de combater inimigos como em Targus, cidade que faz fronteira com a muralha do Reino.";
										 
							texto_fim = "\t Com a proposta da corte, Aphelios volta a ter apoio do Reino para \n"
										"\t ter a sua vida de Ca�ador de volta, ganhando mais poder e experi�ncia.";
							
							fim(texto_base, texto_fim, 1);
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
					
					char* opcao = "\n\n\t\t\t  Deseja Continuar? \n"
						    	  "\t\t -   'C'   para continuar \n"
						    	  "\t\t -   'Q'   para retornar ao in�cio... \n\n"
						    	  "\t\t Sua Escolha: ";
		    
					char escolha;
							   
				    while (1) {
				    	system("cls");
				    	// Imprimir texto e op��es
						espaco();
						imprimir(texto_base);
						imprimir(opcao);
				    	
				        scanf(" %c", &escolha);
				
				        if (escolha == 'c' || escolha == 'C') {
				            // Continuar hist�ria
				            aceitar_pacto();
				            break;
				            
				        } else if (escolha == 'q' || escolha == 'q') {
							iniciar();
				            break; // Sai do loop
				            
				        } else {
				        	espaco();
				            printf("\t\t\t Op��o inv�lida. Tente novamente.\n");
				        }
				    }
					
					
					
					if( continuar(texto_base) == 1) {
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
					  "\t antigos e poderes m�gicos.";
    
    // Descri��o
    if (continuar(descricao) == 1) {
    	char* personagens = "\t #Personagens: \n\n"
							"\t - Aphelios (Classe: Ca�ador): O her�i principal da narrativa, um ca�ador \n"
							"\t de habilidades not�veis que almeja uma vida tranquila com Liora. \n"
							"\t - Liora (Classe: Guerreira, camponesa, esposa de Aphelios): O interesse \n"
							"\t amoroso de Aphelios, uma bela donzela que desempenha um papel central em sua jornada. \n"
							"\t - Veigar (Classe: Mago): Um personagem misterioso cujos segredos det�m \n"
							"\t uma influ�ncia significativa no destino de I�nia e seu mundo alternativo. \n"
							"\t - Jax (Classe: Ca�ador, Amigo de Aphelios): Um leal amigo \n"
							"\t de longa data conhecido por suas habilidades em combate.";
							
 		// Personagens
    	if (continuar(personagens) == 1) {
    		char* cenario = "\t #Cen�rio: \n\n"
							"\t O jogo se desenrola em meio �s paisagens exuberantes do Reino de I�nia, \n"
							"\t bem como em um mundo alternativo dele repleto de mist�rios e magia.";
    		
    		// Cen�rio
    		if (continuar(cenario) == 1) {
    			char * sobre = "\t #Hist�ria: \n\n"
							   "\t Aphelios, um ca�ador aclamado que desfrutou de sucesso na cidade de Targus, \n"
							   "\t conheceu Liora e sua paix�o por ela cresceu ao longo de uma d�cada. \n"
							   "\t Durante esse tempo, ele renunciou a sua carreira em prol de uma vida campestre \n"
							   "\t tranquila ao lado dela no Reino de I�nia, afastando-se dos perigos do mundo exterior. \n"
							   "\t No entanto, conforme a hist�ria se desenrola, Aphelios, insatisfeito com a rotina \n"
							   "\t mon�tona, � arrastado para uma situa��o dram�tica com um mago chamado Veigar, \n"
							   "\t que mudar� o curso de sua vida e o destino de I�nia. Esta narrativa explora \n"
							   "\t o desenvolvimento da hist�ria de Aphelios em meio a um mundo alternativo, \n"
							   "\t que o far� redescobrir sua coragem em um mundo repleto de segredos, \n"
							   "\t desafios e for�as sombrias que amea�avam o Reino e seu eterno amor por Liora.";
    			
    			// Hist�ria
    			if (continuar(sobre) == 1) {
    				char* objetivos = "\t #Objetivos: \n\n"
									  "\t - Recuperar seu status de ca�ador, proteger I�nia e proteger Liora dos perigos que se aproximam. \n\n"
									  "\t - Descobrir a verdade sobre Veigar e seus planos sombrios. \n\n"
									  "\t - Unir for�as com Jax e outros aliados para enfrentar amea�as m�gicas.\n\n";
							
					// Objetivos		  
					if (continuar(objetivos) == 1) {
						char* escolhas = "\t #Escolhas \n\n"
										 "\t Cada escolha que Aphelios fizer moldar� a narrativa do jogo e determinar� o destino de I�nia.\n"
						 				 "\t Ser� um desafio equilibrar o amor por Liora e o dever de proteger o reino. \n"
										 "\t Sua jornada ir� misturar romance, mist�rio e a��o em um �pico de propor��es m�gicas.";
						
						// Escolhas
						if (continuar(escolhas) == 1) {
							char* prepare_se = "\t Prepare-se para viver uma emocionante saga em 'Destino I�nico: A Jornada de Aphelios' \n"
							 				   "\t e descubra se o amor, a amizade e a coragem podem superar as for�as do destino!";
							
							// Prepare - se
							if (continuar(prepare_se) == 1) {
								
								// Preparado?
								system("cls");
								sleep(3);
								
								char* preparado = "\n\n\n\n\n\n\n\n\n"
												  "\t Preparado?";
							
								imprimir(preparado);
								sleep(2);
								system("cls");
								
								// Come�o da hist�ria
								historia();
							}
						}		
					}
				}
			}
		}
	}
	
}

int iniciar() {
	setlocale(LC_ALL, "Portuguese");
	
	
	// Deixar a tela azul e texto branco
	system("color 1F");
	
	char* titulo =  "|-------------------------------------------------------------------------| \n"
					"|=>\t\t  Destino I�nico: A Jornada de Aphelios  \t\t<=| \n"
					"|-------------------------------------------------------------------------| \n\n"
					"\t\t\t Seja Bem-vindo ao Jogo!";
			

	if(continuar(titulo) == 1) {
		contexto();
	} 
}

int main() {
	
	iniciar();

    return 0;
}

