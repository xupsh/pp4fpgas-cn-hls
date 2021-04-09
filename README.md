# pp4fpgas-cn-hls
Examples codes and their HLS frameworks for pp4fpgas-cn running on PynqZ2 board.

Follow the steps in "Get Started" to get the verification via Jupyter Notebook. If you want to do the HLS by yourself, you can use the frameworks in the PYNQ projects folder and try different optimizations.

Jupyter Notebooks are in .boards/notebokes folder and c++ codes are in ./hw/ip folder.

Read examples: [https://xupsh.gitbook.io/pp4fpgas-cn/](https://xupsh.gitbook.io/pp4fpgas-cn/)

PYNQ projects: [https://pp4fpgas.readthedocs.io/en/latest/index.html](https://pp4fpgas.readthedocs.io/en/latest/index.html)

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
│   └── Pynq-Z2
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
├── PYNQ_projects
│   └── DFT/FFT/OFDM/cordic/fir/mono_fm/phase_detector
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
