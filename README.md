
# Sistema de Gestão de Investimentos

## Visão Geral
Este sistema é uma aplicação de console desenvolvida em C para gerenciar investimentos e transações financeiras de clientes. Ele permite o cadastro de clientes, investimentos, e realização de transações, além de calcular impostos, taxas e lucros.

## Funcionalidades Principais
- Cadastro de Novo Cliente: Permite o cadastro de novos clientes, incluindo informações como nome, CPF, telefone e data de nascimento.
- Cadastro de Novo Investimento: Permite o cadastro de novos investimentos, incluindo informações como tipo de aplicação, emissor, taxa e estado de atividade.
- Nova Aplicação: Permite realizar uma nova aplicação financeira associada a um cliente e a um investimento específico.
- Cálculo de Impostos, Taxas e Lucro: Calcula os impostos, taxas e lucro associados a uma determinada transação financeira.
- Extrato Atualizado: Exibe o extrato atualizado de transações financeiras para um cliente específico.
- Montante Aplicado: Calcula o montante total aplicado por um cliente.

## Estruturas de Dados Utilizadas
O sistema utiliza as seguintes estruturas de dados:
- Cliente: Armazena informações sobre um cliente, incluindo nome, CPF, telefone e data de nascimento.
- Investimento: Armazena informações sobre um investimento, incluindo tipo de aplicação, emissor, taxa e estado de atividade.
- Transação: Armazena informações sobre uma transação financeira, incluindo ID, cliente, investimento, datas e valores.

## Como Compilar e Executar
Para compilar e executar o sistema, siga estas etapas:
1. Abra o terminal e navegue até o diretório onde o código fonte está localizado.
2. Compile o código fonte utilizando um compilador C compatível (por exemplo, GCC) com o seguinte comando:
   ```
   gcc main.c -o sistema
   ```
3. Execute o sistema com o seguinte comando:
   ```
   ./sistema
   ```

## Contribuição
Contribuições para este projeto são bem-vindas! Sinta-se à vontade para bifurcar este repositório, fazer suas alterações e enviar uma solicitação de pull. No entanto, por favor, não copie sem permissão.

## Autor
- Desenvolvedor: André Antônio da Silva Queiroz
  - [LinkedIn](https://www.linkedin.com/)
  - [GitHub](https://github.com/)

## Licença
Este projeto está licenciado sob a Licença [MIT](https://opensource.org/licenses/MIT).
