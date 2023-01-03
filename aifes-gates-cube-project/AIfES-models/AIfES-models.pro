TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AIfES_for_Arduino/src/aifes_config.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_dense_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_elu_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_leaky_relu_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_relu_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_sigmoid_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_softmax_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_softsign_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_tanh_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/aimath/aimath_f32_avr_pgm.c \
        AIfES_for_Arduino/src/basic/avr_pgm/aimath/aimath_q7_avr_pgm.c \
        AIfES_for_Arduino/src/basic/base/aialgo/aialgo_sequential_inference.c \
        AIfES_for_Arduino/src/basic/base/aialgo/aialgo_sequential_training.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_dense.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_elu.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_input.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_leaky_relu.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_relu.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_sigmoid.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_softmax.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_softsign.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_tanh.c \
        AIfES_for_Arduino/src/basic/base/ailayer/ailayer_template.c \
        AIfES_for_Arduino/src/basic/base/ailoss/ailoss_crossentropy.c \
        AIfES_for_Arduino/src/basic/base/ailoss/ailoss_mse.c \
        AIfES_for_Arduino/src/basic/base/aimath/aimath_basic.c \
        AIfES_for_Arduino/src/basic/base/aimath/aimath_f32.c \
        AIfES_for_Arduino/src/basic/base/aimath/aimath_q31.c \
        AIfES_for_Arduino/src/basic/base/aimath/aimath_q7.c \
        AIfES_for_Arduino/src/basic/base/aimath/aimath_u8.c \
        AIfES_for_Arduino/src/basic/base/aiopti/aiopti_adam.c \
        AIfES_for_Arduino/src/basic/base/aiopti/aiopti_sgd.c \
        AIfES_for_Arduino/src/basic/cmsis/ailayer/ailayer_dense_cmsis.c \
        AIfES_for_Arduino/src/basic/cmsis/aimath/aimath_f32_cmsis.c \
        AIfES_for_Arduino/src/basic/cmsis/aimath/aimath_q31_cmsis.c \
        AIfES_for_Arduino/src/basic/cmsis/aimath/aimath_q7_cmsis.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_dense_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_elu_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_input_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_leaky_relu_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_relu_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_sigmoid_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_softmax_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_softsign_default.c \
        AIfES_for_Arduino/src/basic/default/ailayer/ailayer_tanh_default.c \
        AIfES_for_Arduino/src/basic/default/ailoss/ailoss_crossentropy_default.c \
        AIfES_for_Arduino/src/basic/default/ailoss/ailoss_mse_default.c \
        AIfES_for_Arduino/src/basic/default/aimath/aimath_f32_default.c \
        AIfES_for_Arduino/src/basic/default/aimath/aimath_q31_default.c \
        AIfES_for_Arduino/src/basic/default/aimath/aimath_q7_default.c \
        AIfES_for_Arduino/src/basic/default/aiopti/aiopti_adam_default.c \
        AIfES_for_Arduino/src/basic/default/aiopti/aiopti_sgd_default.c \
        AIfES_for_Arduino/src/basic/express/aifes_express_f32_fnn.c \
        AIfES_for_Arduino/src/basic/express/aifes_express_q7_fnn.c \
        main.c \
        test_gates.c


DISTFILES += \
    AIfES_for_Arduino/src/CMSIS/README.md \
    AIfES_for_Arduino/src/CMSIS/prepare_cmsis.py

HEADERS += \
    AIfES-and-gate-float/aifes_e_f32_fnn.h \
    AIfES-and-gate-float/aifes_e_f32_weights.h \
    AIfES-and-gate-q7/aifes_e_q7_fnn.h \
    AIfES-and-gate-q7/aifes_e_q7_weights.h \
    AIfES-nor-gate-float/aifes_e_f32_fnn.h \
    AIfES-nor-gate-float/aifes_e_f32_weights.h \
    AIfES-nor-gate-q7/aifes_e_q7_fnn.h \
    AIfES-nor-gate-q7/aifes_e_q7_weights.h \
    AIfES-or-gate-float/aifes_e_f32_fnn.h \
    AIfES-or-gate-float/aifes_e_f32_weights.h \
    AIfES-or-gate-q7/aifes_e_q7_fnn.h \
    AIfES-or-gate-q7/aifes_e_q7_weights.h \
    AIfES-xnor-gate-float/aifes_e_f32_fnn.h \
    AIfES-xnor-gate-float/aifes_e_f32_weights.h \
    AIfES-xnor-gate-q7/aifes_e_q7_fnn.h \
    AIfES-xnor-gate-q7/aifes_e_q7_weights.h \
    AIfES-xor-gate-float/aifes_e_f32_fnn.h \
    AIfES-xor-gate-float/aifes_e_f32_weights.h \
    AIfES-xor-gate-q7/aifes_e_q7_fnn.h \
    AIfES-xor-gate-q7/aifes_e_q7_weights.h \
    AIfES_for_Arduino/src/aifes.h \
    AIfES_for_Arduino/src/aifes_avr_pgm.h \
    AIfES_for_Arduino/src/aifes_cmsis.h \
    AIfES_for_Arduino/src/aifes_config.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_dense_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_elu_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_leaky_relu_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_relu_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_sigmoid_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_softmax_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_softsign_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/ailayer/ailayer_tanh_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/aimath/aimath_f32_avr_pgm.h \
    AIfES_for_Arduino/src/basic/avr_pgm/aimath/aimath_q7_avr_pgm.h \
    AIfES_for_Arduino/src/basic/base/aialgo/aialgo_sequential_inference.h \
    AIfES_for_Arduino/src/basic/base/aialgo/aialgo_sequential_training.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_dense.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_elu.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_input.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_leaky_relu.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_relu.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_sigmoid.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_softmax.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_softsign.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_tanh.h \
    AIfES_for_Arduino/src/basic/base/ailayer/ailayer_template.h \
    AIfES_for_Arduino/src/basic/base/ailoss/ailoss_crossentropy.h \
    AIfES_for_Arduino/src/basic/base/ailoss/ailoss_mse.h \
    AIfES_for_Arduino/src/basic/base/aimath/aimath_basic.h \
    AIfES_for_Arduino/src/basic/base/aimath/aimath_f32.h \
    AIfES_for_Arduino/src/basic/base/aimath/aimath_q31.h \
    AIfES_for_Arduino/src/basic/base/aimath/aimath_q7.h \
    AIfES_for_Arduino/src/basic/base/aimath/aimath_u8.h \
    AIfES_for_Arduino/src/basic/base/aiopti/aiopti_adam.h \
    AIfES_for_Arduino/src/basic/base/aiopti/aiopti_sgd.h \
    AIfES_for_Arduino/src/basic/cmsis/ailayer/ailayer_dense_cmsis.h \
    AIfES_for_Arduino/src/basic/cmsis/aimath/aimath_f32_cmsis.h \
    AIfES_for_Arduino/src/basic/cmsis/aimath/aimath_q31_cmsis.h \
    AIfES_for_Arduino/src/basic/cmsis/aimath/aimath_q7_cmsis.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_dense_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_elu_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_input_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_leaky_relu_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_relu_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_sigmoid_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_softmax_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_softsign_default.h \
    AIfES_for_Arduino/src/basic/default/ailayer/ailayer_tanh_default.h \
    AIfES_for_Arduino/src/basic/default/ailoss/ailoss_crossentropy_default.h \
    AIfES_for_Arduino/src/basic/default/ailoss/ailoss_mse_default.h \
    AIfES_for_Arduino/src/basic/default/aimath/aimath_f32_default.h \
    AIfES_for_Arduino/src/basic/default/aimath/aimath_q31_default.h \
    AIfES_for_Arduino/src/basic/default/aimath/aimath_q7_default.h \
    AIfES_for_Arduino/src/basic/default/aiopti/aiopti_adam_default.h \
    AIfES_for_Arduino/src/basic/default/aiopti/aiopti_sgd_default.h \
    AIfES_for_Arduino/src/basic/express/aifes_express_f32_fnn.h \
    AIfES_for_Arduino/src/basic/express/aifes_express_q7_fnn.h \
    AIfES_for_Arduino/src/core/aifes_core.h \
    AIfES_for_Arduino/src/core/aifes_math.h \
    test_gates.h

INCLUDEPATH += AIfES_for_Arduino/src/
