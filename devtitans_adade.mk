# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)


# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devtitans_adade
PRODUCT_DEVICE := adade
PRODUCT_BRAND := adadeBrand
PRODUCT_MODEL := adadeModel

PRODUCT_PACKAGES += \
	adade_client

BOARD_SEPOLICY_DIRS += device/devtitans/adade/sepolicy

# Adade AIDL Interface
PRODUCT_PACKAGES += devtitans.adade

# Adade Binder Service
PRODUCT_PACKAGES += devtitans.adade-service

# Device Framework Matrix (Declara que o nosso produto Kraken precisa do serviço adade)
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devtitans/adade/device_framework_matrix.xml

# Cliente de Linha de Comando para o Serviço Adade
PRODUCT_PACKAGES += adade_service_client
