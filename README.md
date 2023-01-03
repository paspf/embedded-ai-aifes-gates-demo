# AI Gates using TensorFlow and AIfES
This project runs small neural networks in [AIfES](https://github.com/Fraunhofer-IMS/AIfES_for_Arduino). The networks are trained to predict logical gates (AND, OR, NOR, XOR, XNOR).

The networks were trained with Tensorflow 2.10 and brought to the microcontroller (STM32 L476RG) using CubeIDE. This git repo includes the associated Cube IDE project, a Qt Creator project for the execution without the microcontroller, the Jupyter Notebook required to train the neural networks, as well as a Jupyter Notebook to convert the neural networks for AIfES.

The demo application includes the following features:
- Predict functions for all gates (test_gates.c)
- Print model evaluation to command line interface (test_gates.c)
- Map a single gate to I/O ports (io_gate.c)
- Usage of the ES-PCB for Nucleo L476RG as periphery board
- QtCreator project to run the project without any hardware

## Setup
Clone git:
```
git clone git@github.com:paspf/embedded-ai-aifes-gates-demo.git --recursive
```
Replace the aifes configuration by copying:
```
aifes-gates-cube-project\AIfES-models\AIfES_for_Arduino\etc\aifes_configurations\pc\aifes_config.c
aifes-gates-cube-project\AIfES-models\AIfES_for_Arduino\etc\aifes_configurations\pc\aifes_config.h
```

to:
```
aifes-gates-cube-project\AIfES-models\AIfES_for_Arduino\src
```
and remove:
```
aifes-gates-cube-project\AIfES-models\AIfES_for_Arduino\src\aifes_config.cpp
```