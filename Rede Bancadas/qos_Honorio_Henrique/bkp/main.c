/* CALCULO QoS - REDES DE COMPUTADORES
   Aluno: Honório Henrique de Carvalho Lima
   Sistemas para Internet - II Periodo      
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	int AMOSTRA_BASE = 10; 	//Indica o tamanho da minha amostra base
	int REP_AMOSTRA = 2; 	// Indica quantas vezes irei repetir minha amostra base
	char c = 0, j=0;
	int result_perda = 0;
	float mil_sec[10], somar = 0, atraso = 0, jitter = 0;
	float calc_atraso = 0, aux_1 = 0, aux_2 = 0;
	int i = 0, perd_neg = 0;
	char lh[10];
	
	for(i = 0 ; i < REP_AMOSTRA ; i++)
	{
		system("ping -c 10 -i 0 8.8.8.8 > ping_host.txt");
		system("cat ping_host.txt | awk '{print $7}' | grep = | cut -c 6- > milisegundos.txt");
		
		fp = fopen("milisegundos.txt", "r");
		rewind(fp);
		if (fp == NULL)
		{
	      		printf ("Houve um erro ao abrir o arquivo.\n");
	      		break;
   		}
		else
		{
   			printf ("Arquivo README aberto com sucesso, copiando informações...\n");
			for(j=0;j<10;j++)
			{
				fgets(lh, 255, fp);
				mil_sec[j] = atof(lh);
				somar = somar+mil_sec[j];
				//printf("mil. %f.\n", mil_sec[j]);
				//printf("soma: %0.3f.\n",somar);			
			}
			atraso = atraso+((somar/2)/AMOSTRA_BASE);
			//printf("\nAtraso: %0.3f.\n", atraso);
			fclose(fp);
		}
	}
	
	for(i = 0; i < AMOSTRA_BASE; i++)
	{
		jitter = jitter +((mil_sec[i] - mil_sec[i-1])/2);
	}
   	jitter = jitter/AMOSTRA_BASE;
   	system("clear");

	printf("jitter: %f.\n", jitter);	
	printf("\n\nTOTAL - ETAPA 1\n");
	
	for(i=0;i<10;i++)
	{
		printf("Total Segundos %dº ping: %f.\n",i+1, mil_sec[i]);
	}
	printf("Soma Total: %0.3f.\n",somar);
	printf("\nGerando relatorio final...\n", atraso);
	sleep(4);
	system("clear");
	
    	printf("\nTESTE EXECUTADO COM SUCESSO !\n");
      
    	printf("\nAmostra Base: %d.", AMOSTRA_BASE);
    	printf("\nRepetições: %d.\n", REP_AMOSTRA);
	printf("\n\nRESULTADO:");
	printf("\nAtraso: %0.3f.\n", atraso);
	
	if(jitter < 0)
	{
			jitter=jitter*(-1);
			printf("Jitter: %f.\n", jitter);
	}
	else
	{
			printf("Jitter: %f.\n", jitter);
	}
	printf("\nTotal de Pacotes enviados:  \n");
	result_perda = system("cat ping_host.txt | grep packet | awk '{print $4}'");
	
	if(result_perda == AMOSTRA_BASE)
	{
		result_perda = result_perda - AMOSTRA_BASE;
		printf("Perda: %d.\n\n", result_perda);
	}
	else if(result_perda < AMOSTRA_BASE);
	{
		perd_neg = result_perda;
		printf("Houve perda de %d pacotes.\n\n", perd_neg);
	}
}
