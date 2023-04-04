# AI Gates using TensorFlow and AIfES

This project runs small neural networks in [AIfES](https://github.com/Fraunhofer-IMS/AIfES_for_Arduino). The networks are trained to predict logical gates (AND, OR, NOR, XOR, XNOR).

The networks were trained with Tensorflow `2.10` and brought to the microcontroller (STM32 L476RG) using CubeIDE `1.11.2`. This git repo includes the associated Cube IDE project, a Qt Creator project for the execution without the microcontroller, the Jupyter Notebook required to train the neural networks, as well as a Jupyter Notebook to convert the neural networks for AIfES.

The demo application includes the following features:
- Predict functions for all gates (test_gates.c)
- Print model evaluation to command line interface (test_gates.c)
- Map a single gate to I/O ports (io_gate.c)
- Usage of the [ES-PCB for Nucleo L476RG](https://github.com/paspf/ES-PCB-for-L476RG) as periphery board
- QtCreator project to run the project without any embedded hardware

## Setup

### Get Repository

```
git clone git@github.com:paspf/embedded-ai-aifes-gates-demo.git --recursive
```
Replace default the aifes configuration by copying:
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

### Open Project in Cube IDE

Open the repositories folder in Cube IDE as workspace, import the `aifes-gates-cube-project`.

### Open Project in Qt Creator

Open `aifes-gates-cube-project/AIfES-models/AIfES-models.pro` in Qt Creator.

## Program Output

When running the program, the command line output should look similar to this:
```
test_and_gate_f32
|[0.0, 0.0]|[0]| -> 0.000019 -> Pass
|[0.0, 1.0]|[0]| -> 0.017244 -> Pass
|[1.0, 0.0]|[0]| -> 0.018041 -> Pass
|[1.0, 1.0]|[1]| -> 0.965991 -> Pass
test_and_gate_q7
|[0.0, 0.0]|[0]| -> 0.003906 -> Pass
|[0.0, 1.0]|[0]| -> 0.035156 -> Pass
|[1.0, 0.0]|[0]| -> 0.035156 -> Pass
|[1.0, 1.0]|[1]| -> 0.937500 -> Pass
```
Where the outputs of the floating point model are indicated with f32 and the outputs of the quantized model with q7.