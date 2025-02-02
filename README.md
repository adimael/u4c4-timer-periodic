# 🚦 Projeto Timer Periodic: Semáforo com temporização de 3 segundos

Este projeto implementa um **semáforo utilizando o microcontrolador Raspberry Pi Pico W**. O controle do semáforo é realizado por um **temporizador periódico**, que altera o estado do sinal a cada 3 segundos, seguindo a sequência tradicional:  

🔴 **Vermelho** (Pare) → 🟡 **Amarelo** (Atenção) → 🟢 **Verde** (Siga)  

Além disso, uma mensagem de status é exibida via **porta serial** a cada segundo.

---

## 📌 **Objetivos do Projeto**
✔️ Simular o funcionamento de um semáforo.  
✔️ Utilizar a **função `add_repeating_timer_ms()`** do Pico SDK para criar um temporizador periódico.  
✔️ Praticar o uso de **GPIOs** para controle de LEDs.  
✔️ Exibir mensagens na **porta serial** para monitoramento do sistema.  

---

## 🛠 **Materiais Necessários**
- 🖥️ **Microcontrolador:** Raspberry Pi Pico W  
- 🔴 **LED Vermelho** (Sinal "PARE")  
- 🟡 **LED Amarelo** (Sinal "ATENÇÃO")  
- 🟢 **LED Verde** (Sinal "SIGA")  
- 🔌 **Resistores de 330Ω** (1 para cada LED)  
- 🛠 **Jumpers e Protoboard** (Para conexões)  
- 💻 **Ambiente de Desenvolvimento:** SDK do Raspberry Pi Pico, compilador C/C++  

---

## ⚡ **Esquema de Ligação (GPIO)**
| Componente  | GPIO |
|-------------|------|
| LED Verde   | 11   |
| LED Amarelo | 12   |
| LED Vermelho| 13   |

**Observação:** No simulador **Wokwi**, o LED amarelo é realmente amarelo, mas na **BitDogLab**, ele é azul.

---

## 🚀 **Como Compilar e Executar**

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/adimael/u4c4-timer-periodic.git
   ````
2. **Entre na pasta do projeto**:
   ````
   cd u4c4-timer-periodic
   ````

### **1️⃣ Configurar o Ambiente de Desenvolvimento**
Certifique-se de ter instalado o **Raspberry Pi Pico SDK** e o **compilador C/C++**. Se ainda não configurou, siga as etapas abaixo:

### Passo 1: Baixar o Ninja
   1. Acesse a página oficial de releases do Ninja:  
   [Ninja Releases no GitHub](https://github.com/ninja-build/ninja/releases).
   2. Baixe o arquivo binário mais recente para Windows (geralmente um `.zip`).
   3. Extraia o conteúdo do arquivo `.zip` (haverá um arquivo `ninja.exe`).

   ---

   ### Passo 2: Adicionar o Ninja ao Path do sistema
   Para que o `ninja` seja reconhecido como um comando em qualquer terminal, siga estas etapas:

   1. Clique com o botão direito no botão **Iniciar** e selecione **Configurações**.
   2. Vá em **Sistema** → **Sobre** → **Configurações avançadas do sistema** (no lado direito).
   3. Na aba **Avançado**, clique em **Variáveis de Ambiente**.
   4. Na seção **Variáveis do Sistema**, localize a variável `Path` e clique em **Editar**.
   5. Clique em **Novo** e adicione o caminho completo para o diretório onde você extraiu o `ninja.exe`. Por exemplo:
      ````
      C:\Users\SeuUsuario\Downloads\ninja-win
      ````
   6. Clique em **OK** em todas as janelas.

   ---

   ### Passo 3: Verificar se o Ninja está funcionando
   1. Abra um terminal (PowerShell ou Prompt de Comando).
   2. Digite o comando abaixo para verificar a instalação:
      ```bash
      ninja --version
      ````

   ### Passo 4: Configurar e Compilar o Projeto

   1. Volte ao diretório do projeto e abra um terminal.
   2. Crie ou limpe a pasta `build`:
      ```bash
      rmdir /s /q build
      mkdir build
      cd build
      
   3. Configure o projeto com o CMake:
      ```bash
      cmake -G Ninja ..
      ````
   4. Compile o projeto:

      ```bash
         ninja
      ````

   5. Após isso, o arquivo main.elf será gerado na pasta build.