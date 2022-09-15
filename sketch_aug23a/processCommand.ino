void processCommand(String command) {
    command.trim();
    command.toUpperCase();

    if (command == TAG_LDR){
      Serial.print(getluminosity());
    }

    else if (command == TAG_HUM){
      Serial.print(gethumidity());
    }
   
      
    
    else if (command == TAG_TEM){
      Serial.print(getTemperature());
    }
    
    else{
      Serial.print("ERR Unknown command.\n");
    }
      
}
