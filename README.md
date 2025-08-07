
# Scheduling Policy to the Linux Kernel

## Descrição do Projeto

Este projeto faz parte da disciplina de **Sistemas Operacionais – DCC403** da **Universidade Federal de Roraima**, Departamento de Ciência da Computação. O objetivo principal é estudar o funcionamento do escalonador de processos do Linux e implementar uma nova política de escalonamento chamada `SCHED_BACKGROUND`.

O **escalonador de processos** é uma parte fundamental do sistema operacional, responsável por escolher qual processo será executado pela CPU a cada momento. Neste projeto, foi desenvolvida uma nova política de escalonamento que executa processos apenas quando o sistema está ocioso, ou seja, quando não há processos `SCHED_OTHER`, `SCHED_FIFO` ou `SCHED_RR` prontos para serem executados.

## Objetivos do Projeto

- Compreender o funcionamento do escalonador do Linux.
- Estudar e descrever as principais políticas de escalonamento do kernel:
  - `SCHED_OTHER`
  - `SCHED_FIFO`
  - `SCHED_RR`
  - `SCHED_IDLE`
- Implementar uma nova política chamada `SCHED_BACKGROUND`.
- Criar um tutorial detalhado com código-fonte explicando como criar e testar políticas de escalonamento no Linux.
- Avaliar o desempenho da nova política em comparação com as políticas existentes.

## Arquivos do Repositório

- `schedbckg.c`: Código-fonte da nova política `SCHED_BACKGROUND`.
- `cpu_benchmark.c`: Benchmark utilizado para testar o desempenho da política implementada.
- `Slide.pdf`: Apresentação do projeto com ilustrações, gráficos e conceitos-chave.
- `Relatório SO.pdf`: Relatório completo com fundamentação teórica, implementação, testes e resultados.

## Avaliação de Desempenho

Para comparar as políticas, foram executadas combinações de processos CPU-bound com diferentes políticas de escalonamento. As medições de desempenho foram feitas com:

- `gettimeofday()` para tempo de **wallclock**
- `getrusage()` para medir tempo de **usuário** e **sistema**

Os tempos são registrados em milissegundos e analisados para comparar justiça, responsividade e eficiência das políticas.

## Considerações Finais

A política `SCHED_BACKGROUND` demonstrou ser eficaz para executar tarefas não urgentes, como sincronizações e indexações, sem interferir em processos prioritários. Sua natureza passiva, porém, a torna suscetível à inanição (starvation), sendo recomendável no futuro incluir mecanismos para mitigar esse problema.

---

> Projeto desenvolvido para fins acadêmicos na Universidade Federal de Roraima.
