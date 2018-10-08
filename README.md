# pp4fpgas-cn-hls
HLS Project for pp4fpgas-cn

## Get Started
> Tested on PYNQ-Z1/Z2 v2.3

- Install using `pip`

```console
sudo pip3 install --upgrade git+https://github.com/xupsh/pp4fpgas-cn-hls.git
```

- Open your browser with `<pynq_ip>:9090` and type in xilinx as password.
- Get started using `00-Tutorial` notebook.

> tips: <pynq_ip> is the ip of your pynq.

## Repository Tree
```
.
├── boards
│   ├── Pynq-Z1
│   └── Pynq-Z2
├── hw
│   ├── build_ip.tcl
│   ├── cordic
│   ├── dft
│   ├── histogram
│   ├── ip
│   ├── matrixm
│   ├── sort
│   └── sum
├── LICENSE
├── pp4fpgas
│   ├── cordic_overlay.py
│   ├── dft_overlay.py
│   ├── fir_overlay.py
│   ├── histogram_overlay.py
│   ├── __init__.py
│   ├── matrixm_overlay.py
│   ├── sort_overlay.py
│   ├── spmv_overlay.py
│   ├── sum_overlay.py
│   └── vs_overlay.py
├── README.md
└── setup.py
```

## Hardware Design Rebuilt
> version required: vivado 2017.4

- Open your vivado gui and find `tcl console`
- `cd` the path you git clone
- `cd` hw directory
- `source build_ip.tcl`

![tcl console](./boards/Pynq-Z1/notebooks/data/tclconsole.png)

## Based on
- PYNQ : [https://github.com/Xilinx/PYNQ](https://github.com/Xilinx/PYNQ)
- PP4FPGAS-CN : [https://github.com/xupsh/pp4fpgas-cn](https://github.com/xupsh/pp4fpgas-cn)

