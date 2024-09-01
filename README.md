# ADS Bank - Sistema de Gerenciamento Bancário

## Este projeto é um sistema de gerenciamento bancário simples desenvolvido em C. O sistema permite que gerentes de banco cadastrem clientes, alterem seus saldos, e que clientes consultem suas contas e realizem operações básicas.

## Funcionalidades

### Para Gerentes
- **Cadastro de Clientes:** Permite adicionar novos clientes ao sistema, incluindo nome, CPF, e saldo inicial.
- **Listagem de Clientes:** Exibe uma lista de todos os clientes cadastrados com seus respectivos saldos.
- **Alteração de Saldo:** Permite alterar o saldo de qualquer cliente identificado por seu CPF.
- **Autenticação:** Apenas gerentes autenticados podem acessar essas funcionalidades.

### Para Clientes
- **Consulta de Saldo:** Exibe o saldo disponível na conta do cliente.
- **Saque:** Permite ao cliente realizar saques, descontando o valor de seu saldo.
- **Depósito:** Permite ao cliente realizar depósitos, aumentando o saldo.
- **Transferência de Valores:** Permite a transferência de valores entre contas.
- **Autenticação:** Apenas clientes autenticados podem acessar essas funcionalidades.

## Requisitos

- Um compilador C (como GCC)
- Sistema operacional compatível com C (Windows, Linux, macOS)

## Como Compilar e Executar

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/seuusuario/ads-bank.git
   cd ads-bank
