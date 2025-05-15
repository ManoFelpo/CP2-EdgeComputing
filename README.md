# 🍷 Projeto Vinheria Agnello - Checkpoint 02

Este projeto foi desenvolvido como parte da disciplina de **Edge Computing & Computer Systems**, com o objetivo de aprimorar o monitoramento de condições ambientais de uma vinheria tradicional, agregando sensores e dispositivos eletrônicos para simular uma experiência de loja física no ambiente virtual.

## 🧠 Objetivo

A Vinheria Agnello deseja controlar as condições de armazenamento de seus vinhos com base em três fatores críticos:

- 🌡️ Temperatura
- 💧 Umidade
- 💡 Luminosidade

Além disso, o sistema deve alertar visualmente e sonoramente quando algum parâmetro estiver fora dos limites ideais.

---

## 🛠️ Tecnologias Utilizadas

- **Arduino UNO**
- **IDE do Arduino**
- **Linguagem C++ para Arduino**
- **Simulação no Wokwi**
- **Display LCD 16x2**
- **Sensores analógicos e digitais (LM35, LDR, etc.)**
- **Buzzer e LEDs (verde, amarelo, vermelho)**

---

## ⚙️ Componentes Utilizados

| Componente         | Função                                          |
|--------------------|-------------------------------------------------|
| TMP36              | Sensor de temperatura (em °C)                   |
| Potenciômetro      | Simula sensor de umidade (0% a 100%)            |
| LDR (sensor de luz)| Mede a intensidade de luminosidade (em lux)     |
| Display LCD 16x2   | Exibe mensagens e valores lidos                 |
| Buzzer             | Alerta sonoro para condições críticas           |
| LEDs (3 cores)     | Alertas visuais: verde (ok), amarelo e vermelho |

---

## 🔍 Funcionalidades

### ✅ Monitoramento Contínuo
O sistema lê continuamente os sensores de temperatura, umidade e luz a cada 5 segundos, com base na média de 5 leituras para maior precisão.

### ✅ Condições e Alertas

- **Luminosidade**
  - 💚 Escuro: LED verde aceso
  - 💛 Meia luz: LED amarelo + mensagem no display
  - ❤️ Muito claro: LED vermelho + mensagem + buzzer ligado

- **Temperatura**
  - 🔵 OK: entre 10 °C e 15 °C
  - 🔴 Abaixo de 10 °C: LED amarelo + mensagem + buzzer
  - 🔴 Acima de 15 °C: LED amarelo + mensagem + buzzer

- **Umidade**
  - 🔵 OK: entre 50% e 70%
  - 🔴 Abaixo de 50% ou acima de 70%: LED vermelho + mensagem + buzzer

---

## 🧪 Simulação

A simulação foi feita na plataforma **TinkerCAD**, tivemos que fazer a troca do sensor DHT11 pelo TMP36(temperatura) e Soil Moisture Sensor(umidade). Link do projeto:

🔗 [Clique aqui para acessar a simulação](https://www.tinkercad.com/things/3UrE1iMruEI-cp2-edgecomputing)

---

## 🎥 Vídeo Explicativo

O vídeo demonstra a proposta do projeto, funcionamento do sistema e dificuldades enfrentadas.

🔗 [Link para o vídeo](https://www.loom.com/share/810150d2194f4f108ad981390937e139?sid=5e68f9b3-59fe-4c19-9d65-edca4617d490)

---

## 👨‍💻 Equipe

- Felipe Santos Nunes - RM563919

---

## 📅 Data de Entrega

15/05/2025 – Hands-on presencial (1ESS)

---

## 📝 Observações

- O código utiliza a função `millis()` para evitar travamentos com `delay()`.
- A lógica de alerta segue rigorosamente os requisitos definidos no enunciado.
- As médias suavizam flutuações nas leituras dos sensores, proporcionando maior confiabilidade.

---

📄 *Este projeto foi desenvolvido para fins educacionais no curso de Engenharia de Software – FIAP.*
