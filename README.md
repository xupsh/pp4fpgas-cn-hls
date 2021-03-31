# pp4fpgas-cn-hls
Examples codes and HLS Projects for pp4fpgas-cn running on PynqZ2 board

Read examples: [https://xupsh.gitbook.io/pp4fpgas-cn/](https://xupsh.gitbook.io/pp4fpgas-cn/)

Project requirements: [https://pp4fpgas.readthedocs.io/en/latest/index.html](https://pp4fpgas.readthedocs.io/en/latest/index.html)

## Get Started

- Install using `pip`
> pynq v2.6

```console
sudo pip3 install --upgrade git+https://github.com/xupsh/pp4fpgas-cn-hls.git
```

or copy all files to your pynq board and
```console
sudo pip3 install -e .
```

- Open your browser with `<pynq_ip>:9090` and type in xilinx as password.
- Get started using `pp4fpgas` notebook.

> tips: <pynq_ip> is the ip of your pynq. usually it's `192.168.2.99`

## Repository Tree
```
.
├── boards
│   └── Pynq-Z1/Pynq-Z2
│   	├── cordic/dft/fft/fir/histogram/huffman/matrixm/sort/spmv/sum/vs
│   	└── notebooks/
├── hw
│   ├── build_ip.tcl
│   └── cordic/dft/fft/fir/histogram/huffman/matrixm/sort/spmv/sum/vs
│   	├── *_wrapper.v
│   	└── build_*.tcl
├── pp4fpgas
│   ├── __init__.py
│   └── cordic/dft/fft/fir/histogram/huffman/matrixm/sort/spmv/sum/vs
│   	├── __init__.py
│   	└── *_overlay.py
├── projects
│   └── CORDIC/Discrete_Fourier_Transform/Fast_Fourier_Transform/FIR_Filter_Design/Phase_Detector/OFDM_Receiver/FM_Demodulator
├── LICENSE
├── README.md
└── setup.py
```

## Hardware Design Rebuilt
> suggested version: vivado 2020.2
> make sure you already have these board files in your vivado
> https://github.com/xupsh/pynq-supported-board-file

- Open your vivado gui and find `tcl console`
- `cd` the path you git clone
- `cd` hw directory
- `source build_ip.tcl`

## Based on
- PYNQ : [https://github.com/Xilinx/PYNQ](https://github.com/Xilinx/PYNQ)
- PP4FPGAS-CN : [https://github.com/xupsh/pp4fpgas-cn](https://github.com/xupsh/pp4fpgas-cn)
