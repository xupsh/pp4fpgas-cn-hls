from pynq import Overlay


__author__ = "sonnyhcl"

class DftOverlay(Overlay):
	
    def __init__(self, bitfile="dft.bit", **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")