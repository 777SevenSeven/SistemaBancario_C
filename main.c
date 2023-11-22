#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maximo_clientes 100
#define maximo_investimento 30

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct telefone {
  int DDD;
  long int numero;
} Telefone;

typedef struct cliente {
  char nome[50];
  char CPF[15];
  Telefone fone;
  Data nascimento;
} Cliente;

typedef struct investimento {
  int tipoAplicacao;
  char emissor[50];
  float taxa;
  char ativo;
} Investimento;

typedef struct transacao {
  int idTransacao;
  int cliente;
  int investimento;
  Data dataAplicacao;
  float valorAplicacao;
  Data dataResgate;
  float valorResgate;
} Transacao;

// Verificar Data
int VerificarData (int dia, int mes, int ano) {
  if (dia >= 1 && dia <= 30) {
    if (mes >= 1 && mes <= 12) {
	    if (ano >= 1900 && ano <= 2023) {
	      return 1;
	    }
	  else {
	      printf ("Ano invalido. Digite um ano entre 1900 e 2023.\n");
	       }
	  }
      else {
	  printf ("Mes invalido. Digite um mes entre 1 e 12.\n");
	         }
  }
  else {
      printf ("Dia invalido. Digite um dia entre 1 e 30.\n");
       }

  return 0;
}

// Verificar Telefone
int VerificarTelefone (int DDD, long int numero) {
  char num[50];
  sprintf (num, "%ld", numero);
  if (DDD >= 11 && DDD <= 91) {
      if (strlen (num) == 8) {
	  return 1;
	  }
      if (strlen (num) == 9 && num[0] == '9') {
	  return 1;
	  }
  }
  return 0;
}

// Verificar CPF
int validarCPF (char *cpf) {
  int i, j;
  int digito1 = 0, digito2 = 0;
  int peso = 10;

  if (strlen (cpf) != 11) {
    return 0;
  }
  for (i = 0; i < 10; i++) {
      if (cpf[i] != cpf[i + 1])
	break;
    }
  if (i == 10) {
    return 0;
  }
  for (i = 0; i < 9; i++) {
      digito1 += (cpf[i] - '0') * peso;
      peso--;
    }
  digito1 = (digito1 * 10) % 11;
  if (digito1 == 10) {
    digito1 = 0;
  }
  peso = 11;
  for (i = 0; i < 10; i++) {
      digito2 += (cpf[i] - '0') * peso;
      peso--;
    }
  digito2 = (digito2 * 10) % 11;
  if (digito2 == 10) {
    digito2 = 0;

  if (digito1 == cpf[9] - '0' && digito2 == cpf[10] - '0') {
    return 1;
  }
  else {
    return 0;
        }
    }
}
void calcularImpostos (Investimento investimento, float valorAplicacao, float valorResgate, float *imposto, float *taxa, float *lucro, float *valorResgateFinal) {
  switch (investimento.tipoAplicacao) {
    case 1:
      *imposto = 0;
      *taxa = 0;
      *lucro = valorResgate - valorAplicacao;
      *valorResgateFinal = valorResgate;
      break;

    case 2:
      *imposto = (*lucro > 0) ? *lucro * 0.15 : 0;
      *taxa = 0;
      *lucro = valorResgate - valorAplicacao - *imposto;
      *valorResgateFinal = valorResgate - *imposto;
      break;

    case 3:
      *imposto = (*lucro > 0) ? *lucro * 0.15 : 0;
      *taxa = valorAplicacao * 0.01;
      *lucro = valorResgate - valorAplicacao - *taxa - *imposto;
      *valorResgateFinal = valorResgate - *taxa - *imposto;
      break;

    default:
      printf ("Tipo de aplicacao invalido.\n");
      *imposto = 0;
      *taxa = 0;
      *lucro = 0;
      *valorResgateFinal = 0;
      break;
    }
}
int main () {
  Cliente Clis[maximo_clientes];
  Investimento Invs[maximo_investimento];
  Transacao trans[maximo_clientes];
  int numeroClientes = 0;
  int numeroInvestimentos = 0;
  int numeroTransacao = 0;
  int menu;
  int opcao, NUclientes = 0, NUinvestimentos = 0;
  do {
      printf ("\nMENU\n");
      printf ("1: Cadastrar novo cliente\n");
      printf ("2: Cadastrar novo investimento\n");
      printf ("3: Fazer nova aplicacao\n");
      printf ("4: Impostos, taxas e lucro\n");
      printf ("5: Extrato atualizado\n");
      printf ("6: Montante aplicado\n");
      printf ("7: Lista de clientes por nome\n");
      printf ("X: Sair\n");
      printf ("Escolha uma opcao: ");
      scanf ("%d", &menu);

      switch (menu) {
	case 1:
	  {
	    // Codigo para cadastrar novo cliente
	    printf ("Cadastro\n");
	    if (NUclientes >= maximo_clientes) {
		printf ("Limite maximo de clientes atingido.\n");
		break;
	      }
	    Cliente cliente;
	    printf ("Nome: ");
	    scanf ("%s", cliente.nome);
	    printf ("CPF: ");
	    scanf ("%s", cliente.CPF);
	    if (!validarCPF (cliente.CPF)) {
		printf ("CPF invalido. Cadastro cancelado.\n");
		break;
	      }
	    printf ("Telefone (DDD): ");
	    scanf ("%d", &cliente.fone.DDD);
	    printf ("Telefone (numero): ");
	    scanf ("%ld", &cliente.fone.numero);
	    if (!VerificarTelefone (cliente.fone.DDD, cliente.fone.numero)) {
		printf
		  ("Numero de telefone invalido. Cadastro cancelado.\n");
		break;
	      }
	    printf ("Data de nascimento (dd mm aaaa): ");
	    scanf ("%d %d %d", &cliente.nascimento.dia,&cliente.nascimento.mes, &cliente.nascimento.ano);
        if (!VerificarData(cliente.nascimento.dia, cliente.nascimento.mes,cliente.nascimento.ano)) {
		    printf("Data de nascimento invalida. Cadastro cancelado.\n");
		    break;
	      }
	    Clis[NUclientes] = cliente;
	    NUclientes++;
	    printf ("Cadastro realizado com sucesso!\n");
	    break;
	  }
	case 2:
	  {
	    // Codigo para cadastrar novo investimento
	    printf ("Cadastro de Investimento\n");
	    if (NUinvestimentos >= maximo_investimento) {
		    printf ("Limite maximo de investimentos atingido.\n");
		    break;
	      }
	    Investimento investimento;
	    printf ("Tipo de aplicacao (1, 2 ou 3): ");
	    scanf ("%d", &investimento.tipoAplicacao);
	    if (investimento.tipoAplicacao < 1 || investimento.tipoAplicacao > 3) {
		    printf("Tipo de aplicacao invalido. Cadastro cancelado.\n");
		    break;
	      }
	    printf ("Emissor: ");
	    scanf ("%s", investimento.emissor);
	    printf ("Taxa: ");
	    scanf ("%f", &investimento.taxa);
	    printf ("Ativo (S/N): ");
	    scanf (" %c", &investimento.ativo);
	    Invs[NUinvestimentos] = investimento;
	    NUinvestimentos++;
	    printf ("Cadastro realizado com sucesso!\n");
	    break;
	  }
	case 3:
	  {
	    // Codigo para fazer nova aplicacao
	    printf ("Nova Aplicacao\n");
	    if (NUclientes == 0 || NUinvestimentos == 0) {
		    printf ("Cadastre clientes e investimentos antes de realizar uma aplicacao.\n");
		    break;
	      }
	    Transacao transacao;
	    printf ("ID da transacao: ");
	    scanf ("%d", &transacao.idTransacao);
	    printf ("ID do cliente (de 0 a %d): ", NUclientes - 1);
	    scanf ("%d", &transacao.cliente);
	    if (transacao.cliente < 0 || transacao.cliente >= NUclientes) {
		    printf ("ID do cliente invalido. Aplicacao cancelada.\n");
		    break;
	      }
	    printf ("ID do investimento (de 0 a %d): ", NUinvestimentos - 1);
	    scanf ("%d", &transacao.investimento);
	    if (transacao.investimento < 0 || transacao.investimento >= NUinvestimentos) {
		    printf("ID do investimento invalido. Aplicacao cancelada.\n");
		    break;
	      }
	    printf ("Data de aplicacaoo (dd mm aaaa): ");
	    scanf ("%d %d %d", &transacao.dataAplicacao.dia,&transacao.dataAplicacao.mes,&transacao.dataAplicacao.ano);
	    if (!VerificarData(transacao.dataAplicacao.dia, transacao.dataAplicacao.mes,transacao.dataAplicacao.ano)) {
		    printf("Data de aplicacao invalida. Aplicacao cancelada.\n");
		    break;
	      }
	    printf ("Valor de aplicacao: ");
	    scanf ("%f", &transacao.valorAplicacao);
	    break;
	  }
	case 4:
	  {
	    // Código para calcular impostos, taxas e lucro
	    printf ("Impostos, taxas e lucro\n");
	    if (NUclientes == 0 || NUinvestimentos == 0 || numeroTransacao == 0) {
		    printf ("Realize cadastros e transacoes antes de calcular impostos, taxas e lucro.\n");
		    break;
	      }
	    int idTransacao;
	    printf ("Digite o ID da transacaoo: ");
	    scanf ("%d", &idTransacao);

	    // Encontrar a transacao pelo ID
	    int indexTransacao = -1;
	    for (int i = 0; i < numeroTransacao; i++) {
		    if (trans[i].idTransacao == idTransacao) {
		      indexTransacao = i;
		      break;
		  }
	     }
	    if (indexTransacao == -1) {
		      printf ("Transacao nao encontrada.\n");
		      break;
	      }

	    // Calcular impostos, taxas e lucro
	    float imposto, taxa, lucro, valorResgateFinal;
	    calcularImpostos (Invs[trans[indexTransacao].investimento],
			      trans[indexTransacao].valorAplicacao,
			      trans[indexTransacao].valorResgate, &imposto,
			      &taxa, &lucro, &valorResgateFinal);

	    // Exibir resultados
	    printf ("Imposto: %.2f\n", imposto);
	    printf ("Taxa: %.2f\n", taxa);
	    printf ("Lucro: %.2f\n", lucro);
	    printf ("Valor Resgate Final: %.2f\n", valorResgateFinal);

	    break;
	  }
	case 5:
	  {
	    // Codigo para extrato atualizado
	    printf ("Extrato atualizado\n");
	    if (NUclientes == 0 || NUinvestimentos == 0 || numeroTransacao == 0) {
		    printf ("Realize cadastros e transacoes antes de gerar o extrato.\n");
		    break;
	      }
	    int idCliente;
	    printf ("Digite o ID do cliente (de 0 a %d): ", NUclientes - 1);
	    scanf ("%d", &idCliente);

	    // Verificar se o ID do cliente é válido
	    if (idCliente < 0 || idCliente >= NUclientes) {
		    printf ("ID do cliente invalido.\n");
		    break;
	      }

	    // Exibir extrato para o cliente selecionado
	    printf ("Extrato para o cliente %s:\n", Clis[idCliente].nome);
	    for (int i = 0; i < numeroTransacao; i++) {
		    if (trans[i].cliente == idCliente) {
		      printf ("Transacao ID: %d\n", trans[i].idTransacao);
		      printf ("Investimento: %s\n",
			  Invs[trans[i].investimento].emissor);
		      printf ("Data de Aplicacao: %02d/%02d/%04d\n",
			  trans[i].dataAplicacao.dia,
			  trans[i].dataAplicacao.mes,
			  trans[i].dataAplicacao.ano);
		      printf ("Valor de Aplicacao: %.2f\n",
			  trans[i].valorAplicacao);
		      printf ("Data de Resgate: %02d/%02d/%04d\n",
			  trans[i].dataResgate.dia,
			  trans[i].dataResgate.mes,
			  trans[i].dataResgate.ano);
		      printf ("Valor de Resgate: %.2f\n",
			  trans[i].valorResgate);
		      printf ("---------------\n");
		  }
	  }
	    break;
	 }
	case 6:
	  {
	    // Código para calcular o montante aplicado
	    printf ("Montante aplicado\n");
	    if (NUclientes == 0 || NUinvestimentos == 0 || numeroTransacao == 0) {
		    printf ("Realize cadastros e transacoes antes de calcular o montante aplicado.\n");
		    break;
	      }

	    int idCliente;
	    printf ("Digite o ID do cliente (de 0 a %d): ", NUclientes - 1);
	    scanf ("%d", &idCliente);

	    // Verificar se o ID do cliente é valido
	    if (idCliente < 0 || idCliente >= NUclientes) {
		      printf ("ID do cliente invalido.\n");
		      break;
	      }

	    // Calcular o montante aplicado para o cliente selecionado
	    float montanteAplicado = 0;
	    for (int i = 0; i < numeroTransacao; i++) {
		      if (trans[i].cliente == idCliente) {
		        montanteAplicado += trans[i].valorAplicacao;
		  }

	    // Exibir resultado
	    printf ("Montante aplicado para o cliente %s: %.2f\n",
		    Clis[idCliente].nome, montanteAplicado);
	    break;
	    }
	    default:
	    printf ("Opcao invalida. Tente novamente.\n");
	    break;
	    }
    }
}
    while (menu != 'X' && menu != 'x');
  return 0;
}
