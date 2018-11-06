from pynq import Overlay


__author__ = "sonnyhcl"

class SumOverlay(Overlay):
	
    def __init__(self, bitfile="sum.bit", **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")