#pragma once                           // Inclui esse cabeçalho apenas uma vez

#include <fstream>                     // Classe ifstream
#include <android-base/properties.h>   // Função GetBoolProperty
#include <sys/stat.h>                  // Função e struct stat
#include <random>                      // Geração de números aleatórios (valores simulados)

using namespace std;                   // Permite usar string diretamente ao invés de std::string

namespace devtitans::adade {       // Pacote Smartlamp

class Adade {
    public:
        /**
         * Verifica se o diretório /sys/kernel/adade existe. Se existir
         * o dispositivo SmartLamp está conectado via USB. Caso contrário,
         * Retorna:
         *      0: dispositivo não encontrado
         *      1: sucesso
         */
        int connect();

        /**
         * Acessa o nível de luminosidade atual conforme reportado
         * pelo sensor de luz -- LDR (light-dependent resistor).
         *
         * Retorna:
         *      0: completamente escuro
         *      1 a 99: nível de luminosidade
         *      100: completamente claro
         */
        int getLuminosity();

        /**
         * Acessa a temperatura multiplicada por 100

         *
         * Retorna:
         *     Um valor inteiro para temperatura multiplicada por 100
         */
        int getTemperature();

        /**
         * Acessa a umidade multiplicada por 100

         *
         * Retorna:
         *     Um valor inteiro para umidade multiplicada por 100
         */
        int getHumidity();
    private:
        int readFileValue(string file);
};

} // namespace
