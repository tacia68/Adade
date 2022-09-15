void serialRead(){
    String serialCommand; // Strign responsavel por armazenar o comando

    while (Serial.available() > 0) {          // Serial.available() > 0 verifica se existe dados na porta serial
        char serialChar = Serial.read();      // Realiza a leitura de um bit na porta serial
        //Serial.print("Passou no Serial avaliable");
        serialCommand += serialChar;          // Concatena os bits lidos

        if (serialChar == '\n') {             // Verifica a quebra de linha para identificar o fim do comando
          //Serial.print("Passou no Serial char");
            processCommand(serialCommand);    // Função que processa o comando necessário e responde a ação
            serialCommand = "";               // Apaga o comando após o seu processamento
        }
    }
}
