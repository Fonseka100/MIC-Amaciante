# MIC-Amaciante
Controlador para saber quando colocar o amaciante, em máquinas de lavar antiga. Mais informações na Wiki
 
Alunos:  
Danilo Cardoso RA: 413437  
Tarcísio Fonseca Guidoni RA: 488941

# Introdução  

Este trabalho consiste em um sistema que informa o momento correto para colocar o amaciante em uma máquina de lavar antiga, tendo como principal objetivo a praticidade e evitar o possível esquecimento ou atraso dessa operação.

# Problema
Em máquinas de lavar roupas que são antigas, não há o dispenser para se colocar amaciante o que requer um constante monitoramento do tempo uma vez que este deve ser colocado durante o momento do enxágue. Se a pessoa perder este tempo suas roupas ficarão sem o amaciante pois a máquina já terá drenado toda a água para a centrifugação das mesmas.

# Solução

Este projeto desenvolvido no laboratório de Microcontroladores e Aplicações traz uma solução para o problema supracitado. Sua instalação requer:

* barreira móvel a ser acoplada no botão rotacional da máquina de lavar 
* um LED na posição do enxágue ou no momento cujo amaciante deva ser colocado
* um sensor de luz na posição oposta ao LED com espaço para a passagem da barreira entre eles   

Quando o botão passa pela posição do enxágue, a qual chamaremos de crítica, a barreira bloqueia a luz oriunda do LED e faz com que haja uma diferença significativa lida pelo sensor de luz. Essa diferença é então interpretada pelo Arduino de modo a pausar o funcionamento da máquina e sinalizar que o amaciante deva ser colocado. Através de um botão o usuário pode voltar o funcionamento da mesma após ter colocado o amaciante.

# Componentes Utilizados  
* Arduino Mega 2560  
* Fonte DC 5V
* Motor de Passo
* Microcontrolador uln2003
* Grove - LCD RGB Backlight
* Grove - Smart Relay
* Grove - LED
* Grove - Light Sensor  
* Grove - Base Shield  
* Grove - Buzzer  
* Grove - DIP LED Red-Red

# Esquemático
![Esquemático](https://github.com/Fonseka100/MIC-Amaciante/blob/master/Imagens/Esquematico.png)

[Clique aqui para abrir no schematics.com](http://www.schematics.com/project/mic-amaciante-24750/)

# Funcionamento do Projeto 
Inicialmente quando o circuito for ligado, o motor de passo começará a girar, de acordo com a velocidade desejada, para representar o botão rotacional de uma máquina de lavar antiga. Assim, quando o motor de passo girar a ponto da barreira acoplada adentrar na região crítica, será chamada a rotina _amaciante_ pois será bloqueada a passagem de luz para o sensor.  
A rotina _amaciante_ desligará o motor de passo através do relê, o LCD RGB BackLight irá apresentar uma mensagem indicando que é o momento de colocar o amaciante no cesto de roupas e uma buzina será acionada para alertar o usuário. Após o usuário colocar o amaciante, ele deverá apertar um botão para sinalizar que o procedimento foi feito, este por sua vez irá gerar uma interrupção que irá limpar a mensagem do LCD e o relê irá acionar novamente o motor.
Seguem imagens do circuito:

## Outros trabalhos desta disciplina

https://github.com/Power041/cancela

https://github.com/jblsouza/Lab-Mic-A

https://github.com/iksmada/TuringMachine

https://github.com/Fonseka100/MIC-Amaciante

https://github.com/matheusvervloet/girassolar

https://github.com/alex-dias/TrabalhoFinalMIC2015

https://github.com/gustavocesarlos/trabalhofinalMic

https://github.com/gabrielNT/LabMicApl_TrabalhoFinal

https://github.com/brunowilliamsap/microcontroladores

https://github.com/rodrigoa1990/Projeto-Microcontroladores

https://github.com/matheusDeAlmeida/trabalhoFinalMicrocontroladores
