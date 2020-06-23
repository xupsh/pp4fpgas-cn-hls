# pp4fpgas-cn-hls
HLS Project for pp4fpgas-cn running on Pynq-Z1/Z2 board

## Get Started

- Install using `pip`
> pynq >= v2.3

```console
sudo pip3 install --upgrade git+https://github.com/xupsh/pp4fpgas-cn-hls.git
```

or copy all files to your pynq board and
```console
sudo pip3 install -e .
```
> pynq <= v2.2

```console
sudo pip3.6 install --upgrade git+https://github.com/xupsh/pp4fpgas-cn-hls.git
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
│   │ ├── *_wrapper.v
│   │ └── build_*.tcl
│   └── ip
│     └── cordic/dft/fft/fir/histogram/huffman/matrixm/sort/spmv/sum/vs
│       └── *.cpp
│       └── *.h
│
├── pp4fpgas
│   ├── __init__.py
│   └── cordic/dft/fft/fir/histogram/huffman/matrixm/sort/spmv/sum/vs
│   	├── __init__.py
│   	└── *_overlay.py
├── LICENSE
├── README.md
└── setup.py
```

## Hardware Design Rebuilt
> version required: vivado 2018.3  
> make sure you already have these board files in your vivado  
> https://github.com/xupsh/pynq-supported-board-file  
> take CORDIC on Pynq-Z2 as an example design 

- Open your vivado gui and find `tcl console`
- `cd` the path you git clone
- `cd` hw directory
- `source build_ip.tcl`
- `cd <the path you git clone>/boards/Pynq-Z2/cordic/`  
- `source cordic.tcl`  

![tcl console](./boards/Pynq-Z1/notebooks/data/tclconsole.png)

## Based on
- PYNQ : [https://github.com/Xilinx/PYNQ](https://github.com/Xilinx/PYNQ)
- PP4FPGAS-CN : [https://github.com/xupsh/pp4fpgas-cn](https://github.com/xupsh/pp4fpgas-cn)
