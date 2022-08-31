#include "adade_cliente.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::adade {      // Entra no pacote devtitans::hello

void AdadeClient::start(int argc, char **argv) {
    cout << "Adade SmartLamp!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: get-luminosity, get-temperature, get-humidity" << endl;
        exit(1);
    }

    Adade adade;             // Classe da biblioteca Smartlamp

    // Comando get-luminosity
    if (!strcmp(argv[1], "get-luminosity")) {
        cout << "Luminosidade atual: " << adade.getLuminosity() << endl;
    }

    // Comandos get-threshold e set-threshold
    else if (!strcmp(argv[1], "get-temperature")) {
        cout << "Luminosidade atual: " << adade.getTemperature() << endl;
    }
    else if (!strcmp(argv[1], "get-humidity")) {
        cout << "Luminosidade atual: " << adade.getHumidity() << endl;
    }

    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace



// MAIN

using namespace devtitans::adade; // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main(int argc, char **argv) {
    AdadeClient client;               // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    client.start(argc, argv);             // Executa o método printHello
    return 0;
}
