#include <stdio.h>
#include <time.h>

#define TAM 250000

int contador;

int * insertionSortCrescente(int original[], int length){
    int j, atual;
    contador+=2;
    

    for(int i=1; i<length; i++){
        atual = original[i];
        contador++;
        j=i-1;
        contador+=2;
        contador+=2;
        while((j>=0) && (atual < original[j])){
            original[j+1]=original[j];
            j = j-1;
            contador+=3;
        }
        original[j+1] = atual;
        contador+=1;
    }
    return (int * ) original;
}


int main(){

// PARA O CASO MÉDIO -> vetor aleatório
int my_array[TAM];
   srand(0);
   int z;
   for(z=0; z<TAM; z++){
      my_array[z]=rand();
   }


// PARA O MELHOR CASO -> recebe um vetor já ordenado 
int vetor_ordenado[TAM];
for(int p=0; p<TAM; p++){
    vetor_ordenado[p]=p;
}

// PARA O pior CASO -> recebe um vetor invertido
int vetor_ordenado_traz_pra_frente[TAM];
int j=0;
for(int p=TAM; p>0; p--){
    vetor_ordenado_traz_pra_frente[j]=p;
    j++;
}

clock_t begin = clock();

insertionSortCrescente(vetor_ordenado_traz_pra_frente, TAM);

clock_t end = clock();

for(int f=0; f<TAM; f++){
   //printf("%d ", vetor_ordenado_traz_pra_frente[f]);
}

   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de execucao foi de: %lf", time_spent);
   printf("\nNumero de interacoes foi de %d", contador);

   return 0;
}

// Vetor aleatório (CASO MÉDIO)
// Para vetor de 10 mil elementos ->>> média = 0,061s
// Para vetor de 50 mil elementos ->>> média = 1.554s
// Para vetor de 100 mil elementos ->>> média = 6.203s
// Para vetor de 250 mil elementos ->>> média = 37s
// Para vetor de 500 mil elementos ->>> média = 149s

// Vetor ordenado (Melhor caso)
// Para vetor de 10 mil elementos ->>> média = 0,00s
// Para vetor de 50 mil elementos ->>> média = 0,00s
// Para vetor de 100 mil elementos ->>> média = 0,00s
// Para vetor de 250 mil elementos ->>> média = 0,001s
// Para vetor de 500 mil elementos ->>> média = 0,002s

// Vetor desordenado (Pior caso)
// Para vetor de 10 mil elementos ->>> média = 0,12s
// Para vetor de 50 mil elementos ->>> média = 3,13s
// Para vetor de 100 mil elementos ->>> média = 12,250s
// Para vetor de 250 mil elementos ->>> média = 78s
// Para vetor de 500 mil elementos ->>> média = 3151s


 /*
   int i, j, count, temp, number[25];

   printf("Digite o numero de elementos?: ");
   scanf("%d",&count);

   //printf("Digite os %d elementos fora de ordem: ", count);
   // salva no array desordenado conforme digita
   //for(i=0;i<count;i++)
   //   scanf("%d",&number[i]);

   int my_array[100];
   srand(0);
   int z;
   for(z=0;z<100;z++){
      my_array[z]=rand();
   }

   

   // InsertionSort
   for(i=1;i<count;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }

   printf("Vetor agora ordenado: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);


/*
int tam;
printf("Digite o tamanho do vetor: ");
scanf("%d", &tam);

int vetor[tam];
for(int pos=0; pos<=tam; pos++){
   vetor[pos];
}

insertionSortCrescente(vetor, tam);
*/