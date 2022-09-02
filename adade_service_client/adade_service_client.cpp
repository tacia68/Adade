#include <android/binder_manager.h>
#include <aidl/devtitans/adade/IAdade.h>
#include <iostream>                             // std::cout e std::endl (end-line)

using namespace aidl::devtitans::adade;     // IAdade
using namespace std;                            // std::shared_ptr
using namespace ndk;                            // ndk::SpAIBinder

int main() {
    shared_ptr<IAdade> service;
    service = IAdade::fromBinder(SpAIBinder(AServiceManager_getService("devtitans.adade.IAdade/default")));

    if (!service) {
        cout << "Erro acessando o serviço!" << endl;
        return 1;
    }

    int32_t _aidl_return;
    ScopedAStatus status = service->getTemperature(&_aidl_return);
    int temperature = static_cast<int32_t>(_aidl_return);
    cout << "Temperatura: " << temperature << endl;

    return 0;
}
