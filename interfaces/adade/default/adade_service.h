#pragma once

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <android/binder_manager.h>

#include <aidl/devtitans/adade/BnAdade.h>            // Criado pelo AIDL automaticamente

#include "adade_lib.h"                                   // Classe Adade (biblioteca)

using namespace devtitans::adade;

namespace aidl::devtitans::adade {

class AdadeService : public BnAdade {
    public:
        ndk::ScopedAStatus connect(int32_t* _aidl_return) override;
        //ndk::ScopedAStatus getLed(int32_t* _aidl_return) override;
        //ndk::ScopedAStatus setLed(int32_t in_ledValue, bool* _aidl_return) override;
        ndk::ScopedAStatus getLuminosity(int32_t* _aidl_return) override;
        ndk::ScopedAStatus getTemperature(int32_t* _aidl_return) override;
        ndk::ScopedAStatus getHumidity(int32_t* _aidl_return) override;

    private:
        Adade adade;                                 // Biblioteca
};

}
