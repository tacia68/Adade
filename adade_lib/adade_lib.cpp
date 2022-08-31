#include "adade_lib.h"

using namespace std;                                   // Permite usar string, ifstream diretamente ao invés de std::string
using namespace android::base;                         // Permite usar GetBoolProperty ao invés de android::base::GetBoolProperty

namespace devtitans::adade {                       // Entra no pacote devtitans::adade

int Adade::connect() {
    char dirPath[] = "/sys/kernel/adade";
    struct stat dirStat;
    if (stat(dirPath, &dirStat) == 0)
        if (S_ISDIR(dirStat.st_mode))
            return 1;                                  // Se o diretório existir, retorna 1
        return 0;                                      // Dispositivo não encontrado
}

int Adade::readFileValue(string file) {
    int connected = this->connect();

    if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
        int value;
        string filename = string("/sys/kernel/adade/") + file;
        ifstream file(filename);                        // Abre o arquivo do módulo do kernel

        if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
            file >> value;                              // Lê um inteiro do arquivo
            file.close();
            return value;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return -1;
}

int Adade::getLuminosity() {
    return this->readFileValue("ldr");
}

int Adade::getTemperature() {
    return this->readFileValue("tem");
}

int Adade::getHumidity() {
    return this->readFileValue("hum");
}


} // namespace
